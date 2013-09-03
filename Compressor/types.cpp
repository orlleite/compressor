/*
 preprocessor.hpp
 Compressor
 
 Created by Orlando Leite on 16/12/11.
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
#include <sstream>
#include <stdio.h>

#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "workspace.hpp"
#include "parser.hpp"

const char *currentFile = NULL;
const char *outputFile = NULL;
std::string LINE_BREAK;
std::string SPACE;

bool DEBUGGING;

std::string reservedWords [] = { "null", "true", "false", "break", "case",
								 "catch", "const", "default", "finally", "for",
								 "instanceof", "new", "var", "continue", "function",
								 "return", "void", "delete", "if", "this",
								 "do", "while", "else", "in", "switch",
								 "throw", "try", "typeof", "with", "debugger",
								 "class", "enum", "export", "extends", "import",
								 "super", "implements", "interface", "let", "package",
								 "private", "protected", "public", "static", "yield" };

char *errorList1 [] = {
	"",
	"ERROR 0001 | Language base file \"%s\" not found.",
	"ERROR 0002 | File \"%s\" not found.",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"ERROR 0010, LINE %d, FILE \"%s\" | Class \"%s\" not found.",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"ERROR 0020, LINE %d, FILE \"%s\" | Duplicated var %s in %s.",
	"ERROR 0021, LINE %d, FILE \"%s\" | Variable/property or setter %s not found.",
	"ERROR 0022, LINE %d, FILE \"%s\" | Setter do not support this kind of operation (yet).",
	"ERROR 0023, LINE %d, FILE \"%s\" | Property has the same name of class constructor.",
	"ERROR 0024, LINE %d, FILE \"%s\" | Properties cannot be \"write-only\".",
	"ERROR 0025, LINE %d, FILE \"%s\" | Object %s cannot be found.",
	"ERROR 0026, LINE %d, FILE \"%s\" | Class %s has no method %s needed for interface %s.",
	"ERROR 0027, LINE %d, FILE \"%s\" | Class %s has no getter %s needed for interface %s.",
	"ERROR 0028, LINE %d, FILE \"%s\" | Class %s has no setter %s needed for interface %s."
};

StringVector srcPaths;


// util //
std::string convertInt( int number )
{
	std::stringstream ss;// create a stringstream
	ss << number;// add number to the stream
	return ss.str();// return a string with the contents of the stream
}

bool reservedWord( std::string &name )
{
	int total = sizeof(reservedWords) / sizeof(reservedWords[0]);
	for( int i = 0; i < total; i++ )
	{
		if( reservedWords[i] == name )
			return true;
	}

	return false;
}


// TokenInfo //
TokenInfo::TokenInfo( int type, unsigned int line, const std::string &value, const std::string &filename )
{
	this->_type = type;
	this->line = line;
	this->filename = filename;
	this->value = value;
};

const std::string &TokenInfo::print()
{
	return *new std::string( "token: " + convertInt( this->_type ) +
							", line: " + convertInt( this->line ) + 
							", value: " + this->value );
}

int TokenInfo::type()
{
	PackageManager::currentLine = line;
	PackageManager::currentFile = filename;
	return this->_type;
}

void TokenInfo::setType( int value )
{
	this->_type = value;
}


// ATypage //
ATypage::ATypage()
{
	this->type = "";
	this->arrayType = "";
}

ATypage::ATypage( TokenInfo *token, bool isArray )
{
	// this->name = token->value;
	// this->isArray = isArray;
	this->type = isArray ? "Array" : token->value;
	this->arrayType = token->value;
}

ATypage::ATypage( std::string &name, bool isArray )
{
	this->arrayType = name;
	this->type = isArray ? "Array" : name;
}



// AExpression //
AExpression::AExpression( TokenInfo *token )
{
	this->token = token;
	this->a = NULL;
	this->b = NULL;
};

const std::string &AExpression::correctName( Context *ctx )
{
	std::string *xname = new std::string( this->token->value );
	
	// log( *xname << "\n";
	
	if( ctx )
	{
		std::string str = this->token->value;
		AObject *inst = NULL;
		ctx->isSuper = false;
		
		if( ctx->cpath )
		{
			// if( str == "MOUSE_DOWN" ) log( "cpath: " << typeid(ctx->cpath->typage).name() << " -> " << str << "\n";
			
			// log( "cpath: " << ctx->cpath->rname << " -> " << str << "\n";
			if( ctx->cpath->typage )
			{
				// log( ctx->cpath << std::endl;
				std::string obj = ctx->cpath->typage->type;
				AObject *target = PackageManager::getObject( obj );
				
				if( target )
				{
					inst = target->objectByName( str );
					
					if( inst )
					{
						ctx->cpath = inst;
						ctx->cpathClass = false;
						return inst->xname();
					}
				}
			}
			else
			{
				inst = ctx->cpath->objectByName( str );
				
				if( inst && ( inst->isStatic || ctx->ignoreStatic ) )
				{
					ctx->cpath = inst;
					ctx->cpathClass = false;
					return inst->xname();
				}
			}
			
			return *xname;
		}
		else
		{
			if( ctx->ctarget )
			{
				// log( "ctarget: " << ctx->ctarget->rname << " -> " << str << "\n";
				if( ctx->ctarget->rname != str )
					inst = ctx->ctarget->objectByName( str );
			}
			
			if( inst )
			{
				ctx->cpath = inst;
				ctx->cpathClass = false;
				return inst->xname();
			}
			else if( ctx->cthis )
			{
				// log( "cthis: " << ctx->cthis->rname << " -> " << str << "\n";
				if( ctx->cthis->rname != str )
					inst = ctx->cthis->objectByName( str );
			}
			
			if( inst )
			{
				ctx->cpath = inst;
				ctx->cpathClass = false;
				
				if( inst->isStatic ) // ERROR //
				{
					return *new std::string( ( inst->from->external ? "" : "$." ) + inst->from->xname() + "." + inst->xname() );
				}
				else
					return *new std::string( "this." + inst->xname() );
			}
			else
			{
				inst = PackageManager::getExternalVar( str );
				if( inst )
				{
					ctx->cpath = inst;
					ctx->cpathClass = false;
					
					return *new std::string( inst->xname() );
				}
				
				inst = PackageManager::getObject( str );
				
				if( inst )
				{
					ctx->cpath = inst;
					ctx->cpathClass = true;
					// log( "get one = " << str << " -> " << inst->xname() << "\n";
					return *new std::string( ( inst->external ? "" : "$." ) + inst->xname() );
				}
			}
		}
		// log( " - " << *xname << "\n";
		ctx->cpath = new AObject();
	}
	
	return *xname;
}

const std::string &AExpression::codeGen( Context *ctx )
{
	std::string temp;
	
	switch ( this->token->type() )
	{
		case TNAME:
			temp = this->correctName( ctx );
			break;
		
		case TNUMBER:
		case TSTRING:
		case TREGEX:
			temp = this->token->value;
			break;
		
		case TTHIS:
			if( ctx )
			{
				ctx->cpath = new AObject();
				ctx->cpath->typage = new ATypage( ctx->cthis->rname, false );
			}
			temp = "this";
			break;
			
		case TFALSE:
			temp = "false";
			break;
			
		case TTRUE:
			temp = "true";
			break;
			
		case TNULL:
			temp = "null";
			break;
			
		default:
			temp = "";
			break;
	}
	
	/*if( temp == "6000" )
	{
		log( "found 6000" << std::endl;
	}*/
	
	return *new std::string( temp );
};


// AInstruction //
AInstruction::AInstruction( AExpression *value )
{
	this->value = value;
	external = false;
	_xname = "";
	
	from = NULL;
};

void AInstruction::setXName( AObject *target )
{
	// _xname = target->newname();
}

const std::string &AInstruction::xname()
{
	return _xname;
}

const std::string &AInstruction::codeGen( Context *ctx )
{
	if( this->value )
		return this->value->codeGen( ctx );
	else
		return "";
};


// AObject //
AObject::AObject() : AInstruction::AInstruction( NULL )
{
	isStatic = false;
	isConst = false;
	access = TPRIVATE;
	
	typage = NULL;
	
	names = "a";
	objects = new AObjectMap();
};

const std::string &AObject::newname( const std::string &rname )
{
	if( objectByNameExists( rname ) )
	{
		std::string thisType;
		
		if( typeid(*this) == typeid(AInstDeclareClass) )
			thisType = "class";
		else if( typeid(*this) == typeid(AInstDeclareFunc) )
			thisType = "function";
		
		ERROR_LOG( errorList1[20], PackageManager::currentLine, PackageManager::currentFile.c_str(), rname.c_str(), this->rname.c_str() );
		// exitWithError( "Duplicated var " + rname + " in " + thisType + " " + this->rname, 1 );
	}
	
	if( DEBUGGING ) return rname;
	
	std::string *temp = new std::string( names );
	
	int length = names.size();
	int pos = length - 1;
	
	do {
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
				names[pos] = '_';
			else if( names[pos] == '_' )
				names[pos] = '$';
			else if( names[pos] == '$' )
				names += "a";
			else
				names[pos] += 1;
		}
	} while( reservedWord( *temp ) );
	
	return *temp;
}

const std::string &AObject::codeGen( Context *ctx )
{
	return "";
}

bool AObject::objectByNameExists( const std::string &name )
{
	AObjectMap::iterator p;
	p = objects->find( name );
	
	if( p != objects->end() )
		return true;
	else
		return false;
}

AObject *AObject::objectByName( const std::string &name )
{
	AObjectMap::iterator p; 
	p = objects->find( name );
	
	// log( name + "\n";
	
	if( p != objects->end() )
		return p->second;
	else
	{
		// log( "WARNING: " << name << " was not found in " << rname << std::endl;
		return NULL;
	}
}

Context::Context()
{
	cthis = NULL;
	cpath = NULL;
	ctarget = NULL;
	cpathClass = false;
	isSuper = false;
	ignoreStatic = false;
	tabs = "";
}


