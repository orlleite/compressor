/*
 preprocessor.cpp
 Compressor
 
 Created by Orlando Leite on 13/05/13.
 Copyright 2011. All rights reserved.
 
 This file is part of Compressor.
 
 Compressor is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Compressor is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Compressor.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

#include <dirent.h>

#include "preprocessor.hpp"
#include "pre_parser.hpp"

extern FILE* zzin;
extern void ppnewfile(FILE *file);
extern int zzparse();
extern int newfile( const char*, char const* );

bool isDirectory(char path[]) {
    struct stat s;
	if( stat(path,&s) == 0 )
	{
		if( s.st_mode & S_IFDIR )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool removeDirectory(std::string path)
{
	// log( path[path.length()-1] << std::endl;
	
    if (path[path.length()-1] != '/') path += "/";
    // first off, we need to create a pointer to a directory
    DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
    pdir = opendir (path.c_str());
    struct dirent *pent = NULL;
    if (pdir == NULL) { // if pdir wasn't initialised correctly
        return false; // return false to say "we couldn't do it"
    } // end if
    char file[256];
	
    int counter = 1; // use this to skip the first TWO which cause an infinite loop (and eventually, stack overflow)
    while (pent = readdir (pdir)) { // while there is still something in the directory to list
        if (counter > 2) {
            for (int i = 0; i < 256; i++) file[i] = '\0';
            strcat(file, path.c_str());
            if (pent == NULL) { // if pent has not been initialised correctly
                return false; // we couldn't do it
            } // otherwise, it was initialised correctly, so let's delete the file~
            strcat(file, pent->d_name); // concatenate the strings to get the complete path
			
            if (isDirectory(file) == true) {
                removeDirectory(file);
            } else { // it's a file, we can use remove
                remove(file);
            }
        } counter++;
    }
	
    // finally, let's clean up
    closedir (pdir); // close the directory
    if (!rmdir(path.c_str())) return false; // delete the directory
    return true;
}

PreProcessor *pp;

extern StringDeque *stringSplit( const std::string &str, char splitter );
extern std::string &stringJoin( StringDeque *list, const std::string &glue );

void replaceAll( std::string& str, const std::string& from, const std::string& to )
{
    if(from.empty()) return;
	
    size_t start_pos = 0;
    while( (start_pos = str.find(from, start_pos)) != std::string::npos )
	{
        str.replace( start_pos, from.length(), to );
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
};


// ALine //
ALine::ALine( TokenInfo *token )
{
	this->token = token;
};

const std::string &ALine::codeGen()
{
	return pp->replaceDefinitions( this->token->value );
};


// ADefine //
ADefine::ADefine( TokenInfo *name, TokenInfo *value ) : ALine::ALine( name )
{
	this->value = value;
	pp->addDef( token->value, value->value );
};

const std::string &ADefine::codeGen()
{
	return "\n";
};


// AIfDef //
AIfDef::AIfDef( TokenInfo *token ) : ALine::ALine( token )
{
	
};

const std::string &AIfDef::codeGen()
{
	pp->ifstate = true;
	
	if( pp->isDef( token->value ) )
	{
		pp->ifgotone = true;
		return "\n";
	}
	else
	{
		pp->ifcopen = true;
		return "/*\n";
	}
};


// AElseIfDef //
AElseIfDef::AElseIfDef( TokenInfo *token ) : ALine::ALine( token )
{
	
};

const std::string &AElseIfDef::codeGen()
{
	if( !pp->ifstate )
	{
		// ERROR_LOG( errorList1[10], currentLine, currentFile.c_str(), spath.c_str() );
		log( "ERROR: #elseif without #if" );
		exit( 1 );
	}
	
	if( !pp->ifgotone && pp->isDef( token->value ) )
	{
		pp->ifgotone = true;
		pp->ifcopen = false;
		return "*/\n";
	}
	else if( pp->ifcopen )
	{
		return "\n";
	}
	else
	{
		pp->ifcopen = true;
		return "/*\n";
	}
};


// AElseDef //
AElseDef::AElseDef() : ALine::ALine( NULL )
{
	
};

const std::string &AElseDef::codeGen()
{
	if( !pp->ifstate )
	{
		log( "ERROR: #else without #if" );
		exit( 1 );
	}
	
	if( !pp->ifgotone )
	{
		pp->ifgotone = true;
		pp->ifcopen = false;
		
		return "*/\n";
	}
	else if( pp->ifcopen )
	{
		return "\n";
	}
	else
	{
		pp->ifcopen = true;
		return "/*\n";
	}
};


// AEndIfDef //
AEndIfDef::AEndIfDef() : ALine::ALine( NULL )
{
	
};

const std::string &AEndIfDef::codeGen()
{
	if( !pp->ifstate )
	{
		log( "ERROR: #endif without #if" );
		exit( 1 );
	}
	
	pp->ifstate = false;
	pp->ifgotone = false;
	
	if( pp->ifcopen )
	{
		pp->ifcopen = false;
		return "*/\n";
	}
	else
		return "\n";
};


// PreProcessor //
PreProcessor::PreProcessor( std::string path )
{
	tempFolder = path;
	
	defines = new StringMap();
	ifstate = false;
	ifgotone = false;
	ifcopen = false;
	
	names = "a";
	
	removeDirectory( tempFolder );
	mkdir( tempFolder.c_str(), 0777 );
	
	tempFolder += "/";
};

void PreProcessor::addDef( std::string &name, std::string &value )
{
	defines->insert( make_pair( name, value ) );
};

void PreProcessor::removeDef( std::string &name )
{
	
};

bool PreProcessor::isDef( std::string &name )
{
	StringMap::iterator p;
	p = defines->find( name );
	
	if( p != defines->end() )
		return true;
	else
		return false;
}

void PreProcessor::codeGenAndSave( ALineVector *block )
{
	std::string *temp = new std::string();
	
	ALineVector::const_iterator it;
	
	for( it = block->begin(); it != block->end(); it++ )
	{
		*temp += (**it).codeGen();
	}
	
	saveToFile( *temp );
};

void PreProcessor::saveToFile( const std::string &value )
{
	std::ofstream compiled;
	compiled.open( (tempFolder + names).c_str(), std::ios::trunc );
	if( compiled.is_open() )
	{
		compiled << value;
		compiled.close();
	}
	else
	{
		log( "Unable to create/open file\n" );
	}
};

const std::string &PreProcessor::replaceDefinitions( const std::string &value )
{
	std::string *temp = new std::string( value );
	
	StringMap::iterator it;
	std::string strToReturn;// This is no longer on the heap
	
	for( it = defines->begin(); it != defines->end(); ++it)
	{
		replaceAll( *temp, "#"+it->first, it->second );
	}
	
	return *temp;
}

std::string &PreProcessor::newname()
{
	std::string *temp = new std::string( names );
	
	int length = names.size();
	int pos = length - 1;
	if( length == 1 )
	{
		if( names[pos] == 'z' )
			names[pos] = 'A';
		else if( names[pos] == 'Z' )
			names = "aa";
		else
			names[pos] += 1;
	}
	else
	{
		if( names[pos] == 'z' )
			names[pos] = 'A';
		else if( names[pos] == 'Z' )
			names[pos] = '0';
		else if( names[pos] == '9' )
			names += "a";
		else
			names[pos] += 1;
	}
	
	return *temp;
}

bool PreProcessor::processFile( std::string filePath )
{
	FILE *file = fopen( filePath.c_str(), "r" );
	
	if( file )
	{
		ppnewfile( file );
		zzparse();
		
		std::string name = this->newname();
		// log( name << std::endl;
		newfile( (tempFolder + name).c_str(), filePath.c_str() );
		
		return true;
	}
	else
	{
		return false;
	}
}

void PreProcessor::deleteTempFolder()
{
	removeDirectory( tempFolder );
}

