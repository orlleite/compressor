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


// PLine //
PLine::PLine( TokenInfo *token )
{
	this->token = token;
};

const std::string &PLine::codeGen()
{
	return pp->replaceDefinitions( this->token->value );
};


// PDefine //
PDefine::PDefine( TokenInfo *name, TokenInfo *value ) : PLine::PLine( name )
{
	this->value = value;
};

const std::string &PDefine::codeGen()
{
	if( this->value )
		pp->addDef( token->value, value->value );
	else
	{
		std::string value = "";
		pp->addDef( token->value, value );
	}
	
	return "\n";
};


// PIfDef //
PIfDef::PIfDef( PExpression *a ) : PLine::PLine( NULL )
{
	this->a = a;
};

const std::string &PIfDef::codeGen()
{
	pp->ifstate = true;
	
	if( a->result() )
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


// PElseIfDef //
PElseIfDef::PElseIfDef( PExpression *a ) : PLine::PLine( NULL )
{
	this->a = a;
};

const std::string &PElseIfDef::codeGen()
{
	if( !pp->ifstate )
	{
		// ERROR_LOG( errorList1[10], currentLine, currentFile.c_str(), spath.c_str() );
		log( "ERROR: #elseif without #if" );
		exit( 1 );
	}
	
	if( !pp->ifgotone && a->result() )
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


// PElseDef //
PElseDef::PElseDef() : PLine::PLine( NULL )
{
	
};

const std::string &PElseDef::codeGen()
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


// PEndIfDef //
PEndIfDef::PEndIfDef() : PLine::PLine( NULL )
{
	
};

const std::string &PEndIfDef::codeGen()
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


// PExpression //
PExpression::PExpression( TokenInfo *token )
{
	this->token = token;
	this->a = NULL;
	this->b = NULL;
};

bool PExpression::result()
{
	// std::cout << token->value;
	return pp->isDef( token->value );
};

// AExprParent //
PExpParent::PExpParent( PExpression *a ) : PExpression::PExpression( NULL )
{
	this->a = a;
};

bool PExpParent::result()
{
	return this->a->result();
}

PExpNot::PExpNot( TokenInfo *token ) : PExpression::PExpression( token )
{
	
}

bool PExpNot::result()
{
	return !PExpression::result();
}


// AExpOperation //
PExpOperation::PExpOperation( PExpression *a, TokenInfo *token, PExpression *b )
: PExpression::PExpression( token )
{
	this->a = a;
	this->b = b;
};

bool PExpOperation::result()
{
	bool result;
	
	switch( this->token->type() )
	{
		case TOR:
			result = this->a->result() || this->b->result();
			break;
            
		case TAND:
			result = this->a->result() && this->b->result();
			break;
	}
	
	return result;
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

void PreProcessor::codeGenAndSave( PLineVector *block )
{
	std::string *temp = new std::string();
	
	PLineVector::const_iterator it;
	
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
	
	if( pp->ifcopen )
		replaceAll( *temp, "*/", "* /" );
	
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

