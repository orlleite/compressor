/*
 blocks.cpp
 Compressor
 
 Created by Orlando Leite on 28/05/13.
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

#include "types.hpp"
#include "preprocessor.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "blocks.hpp"
#include "workspace.hpp"
#include "parser.hpp"

// AInstDeclareFunc //
AInstDeclareFunc::AInstDeclareFunc( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block )
: AObject::AObject()
{
	if( typage ) this->typage = typage;
	
	this->block = block;
	this->value = name;
	this->args = args;
	this->constructor = false;
	this->rname = name->codeGen( NULL );
	
	AInstructionVector::const_iterator it;
	AObject *temp;
	
	if( this->args )
	{
		for( it = this->args->begin(); it != this->args->end(); it++ )
		{
			temp = (AObject *)(*it);
			temp->setXName( this );
		}
	}
	
	AInstruction *temp2;
	for( it = this->block->begin(); it != this->block->end(); it++ )
	{
		temp2 = *it;
		temp2->setXName( this );
	}
};

void AInstDeclareFunc::setOwner( AObject *owner )
{
	this->owner = owner;
};

void AInstDeclareFunc::setXName( AObject *target )
{
	AObject *temp = target->objectByName( rname );
	
	if( temp )
	{
		overwrite = true;
		_xname = temp->xname();
	}
	else
	{
		if( target->rname == rname )
		{
			_xname = *new std::string( "_" );
		}
		else
			_xname = target->newname( rname );
	}
	
	if( target->rname == rname && typeid(*target) == typeid(AInstDeclareClass) )
	{
		this->constructor = true;
		((AInstDeclareClass *) target)->constructor = this;
	}
	else
		target->objects->insert( make_pair( rname, this ) );
}

const std::string &AInstDeclareFunc::blockGen( Context *ctx )
{
	std::string *temp = new std::string();
	
	AInstructionVector::const_iterator it;
	bool first = true;
	bool lcase = false;
	bool rbrace = false;
	int lastSize = 0;
	
	if( DEBUGGING ) ctx->tabs += "	";
	
	for( it = this->block->begin(); it != this->block->end(); it++ )
	{
		ctx->ctarget = this;
		ctx->cpath = NULL;
		
		if( lastSize != temp->size() )
			if( ( rbrace && typeid(**it) != typeid(AInstElse) && typeid(**it) != typeid(AInstElseif) ) ||
			   ( !first && !lcase && !rbrace ) ) *temp += ";";
		
		if( DEBUGGING ) *temp += LINE_BREAK + ctx->tabs;
		lastSize = temp->size();
		*temp += (**it).codeGen( ctx );
		
		if( (*temp)[temp->size()-1] == '}' ) rbrace = true;
		else rbrace = false;
		
		if( typeid(**it) == typeid(AInstCase) | typeid(**it) == typeid(AInstDefault) ) lcase = true;
		else lcase = false;
		
		first = false;
	}
	
	if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
	
	return *temp;
}

const std::string &AInstDeclareFunc::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstDeclareFunc" );
#endif
	std::string tname = this->xname() == "" ? this->rname : this->xname();
	std::string *temp = new std::string( ctx->tabs + "function " + tname + "(" );
	std::string *defs = new std::string(); // defaults
	ctx->cpath = NULL;
	
	if( DEBUGGING )
	{
		ctx->tabs += "	";
	}
	
	if( this->args )
	{
		*temp += SPACE;
		AInstructionVector::const_iterator it;
		bool first = true;
		bool dfirst = true;
		
		for( it = this->args->begin(); it != this->args->end(); it++ )
		{
			ctx->ctarget = this;
			if( !first ) *temp += "," + SPACE;
			*temp += (**it).codeGen( ctx );
			ctx->cpath = NULL;
			std::string t = ((AInstDeclareArg *)(*it))->defaultValue( ctx );
			ctx->cpath = NULL;
			
			if( t.size() )
			{
				if( !dfirst ) *defs += ";" + LINE_BREAK;
				*defs += ctx->tabs + t;
				
				dfirst = false;
			}
			
			first = false;
		}
		
		*temp += SPACE;
	}
	*temp += ")" + LINE_BREAK + "{" + LINE_BREAK;
	
	if( defs->size() ) *temp += LINE_BREAK + *defs + ";" + LINE_BREAK;
	
	*temp += blockGen( ctx ) + "}";
	
	if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
	
	return *temp;
};


// AInstDeclareMethod //
AInstDeclareMethod::AInstDeclareMethod( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block )
: AInstDeclareFunc::AInstDeclareFunc( name, typage, args, block )
{
	
};

const std::string &AInstDeclareMethod::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstDeclareMethod" );
#endif

	std::string *temp = new std::string();
	
	ctx->ctarget = this;
	
	if( isStatic ) ctx->cthis = NULL;
	
	if( !this->constructor )
	{
		if( _xname == "" ) _xname = this->value->codeGen( ctx );
		ctx->cpath = NULL;
		
		*temp += _xname + SPACE + "=" + SPACE;
	}
	
	if( DEBUGGING ) ctx->tabs += "	";
	
	*temp += "function(";
	
	std::string *defs = new std::string(); // defaults
	
	if( this->args )
	{
		*temp += SPACE;
		
		AInstructionVector::const_iterator it;
		bool first = true;
		bool dfirst = true;
		
		for( it = this->args->begin(); it != this->args->end(); it++ )
		{
			if( !first ) *temp += "," + SPACE;
			*temp += (**it).codeGen( ctx );
			ctx->cpath = NULL;
			std::string t = ((AInstDeclareArg *)(*it))->defaultValue(ctx);
			ctx->cpath = NULL;
			if( t.size() )
			{
				if( !dfirst ) *defs += ";";
				*defs += LINE_BREAK + ctx->tabs + t;
				
				dfirst = false;
			}
			
			first = false;
		}
		
		*temp += SPACE;
	}
	
	if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
	
	*temp += ")" + LINE_BREAK + ctx->tabs + "{";
	
	if( defs->size() ) *temp += *defs + ";";
	
	*temp += blockGen( ctx ) + LINE_BREAK + ctx->tabs + "}";
	
	return *temp;
};


// AInstDeclareGet //
AInstDeclareGet::AInstDeclareGet( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block )
: AInstDeclareMethod::AInstDeclareMethod( name, typage, args, block )
{
	
};

void AInstDeclareGet::setXName( AObject *target )
{
	AInstDeclareMethod::setXName( target );
	((AInstDeclareClass *)target)->getters->insert( make_pair( rname, this ) );
}


// AInstDeclareSet //
AInstDeclareSet::AInstDeclareSet( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block )
: AInstDeclareMethod::AInstDeclareMethod( name, typage, args, block )
{
	
};

void AInstDeclareSet::setXName( AObject *target )
{
	AInstDeclareGet *temp = (AInstDeclareGet *) ((AInstDeclareClass *) target)->getterByName( rname );
	if( temp )
	{
		_xname = *new std::string( "_" );
		if( DEBUGGING ) _xname += "_set_";
		_xname += temp->xname();
	}
	else
	{
		// SHOULD BE A ERROR; A property cannot be "write-only" //
		ERROR_LOG( errorList1[24], PackageManager::currentLine, PackageManager::currentFile.c_str() );
		_xname = target->newname( rname );
	}
	
	if( target->rname == rname )
	{
		// log( "ERROR: Property name is same as constructor;";
		ERROR_LOG( errorList1[23], PackageManager::currentLine, PackageManager::currentFile.c_str() );
	}
	
	((AInstDeclareClass *)target)->setters->insert( make_pair( rname, this ) );
};


// AInstDeclareProp //
AInstDeclareProp::AInstDeclareProp( AExpression *name, ATypage *typage, AExpression *value )
: AObject::AObject()
{
	this->name = name;
	this->value = value;
	this->typage = typage;
	this->rname = name->codeGen( NULL );
};

void AInstDeclareProp::setXName( AObject *target )
{
	_xname = target->newname( rname );
	if( target->rname == rname )
	{
		// log( "ERROR: Property name is same as constructor;";
		ERROR_LOG( errorList1[23], PackageManager::currentLine, PackageManager::currentFile.c_str() );
	}
	target->objects->insert( make_pair( rname, this ) );
}

const std::string &AInstDeclareProp::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstDeclareProp" );
#endif

	std::string *temp;
	
	if( _xname == "" ) _xname = this->name->codeGen( ctx );
	
	temp = new std::string( _xname );
	
	if( this->value ) *temp += SPACE + "=" + SPACE + this->value->codeGen( ctx );
	
	return *temp;
};


// AInstDeclareMultProp //
AInstDeclareMultProp::AInstDeclareMultProp( AObjectVector *list )
:AObject::AObject()
{
	this->list = list;
}

void AInstDeclareMultProp::setXName( AObject *target )
{
	AObjectVector::const_iterator it;
	for( it = this->list->begin(); it != this->list->end(); it++ )
	{
		(**it).setXName( target );
	}
}

const std::string &AInstDeclareMultProp::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstDeclareMultProp" );
#endif

	std::string *temp = new std::string();
	AObjectVector::const_iterator it;
	bool first = true;
	
	for( it = this->list->begin(); it != this->list->end(); it++ )
	{
		if( !first ) *temp += ";" + LINE_BREAK + ctx->tabs + "$." + ctx->cthis->xname() + "._.";
		*temp += (**it).codeGen( ctx );
		
		first = false;
	}
	
	return *temp;
}


// EXTERNALS //

// AInstExternalMethod //
AInstExternalMethod::AInstExternalMethod( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id )
: AInstDeclareFunc::AInstDeclareFunc( name, typage, args, new AInstructionVector() )
{
	this->id = id;
};

void AInstExternalMethod::setXName( AObject *target )
{
	if( target->rname == rname && typeid(*target) == typeid(AInstDeclareClass) )
	{
		this->constructor = true;
		((AInstDeclareClass *) target)->constructor = this;
	}
	else
		target->objects->insert( make_pair( rname, this ) );
	
	_xname = this->id->codeGen( NULL );
};

const std::string &AInstExternalMethod::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstExternalMethod" );
#endif

	return "";
};


// AInstExternalGet //
AInstExternalGet::AInstExternalGet( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id, bool isVar )
: AInstDeclareGet::AInstDeclareGet( name, typage, args, new AInstructionVector() )
{
	this->isVar = isVar;
	this->id = id;
};

void AInstExternalGet::setXName( AObject *target )
{
	_xname = this->id->codeGen(NULL);
	
	if( !this->isVar ) _xname += "()";
	
	target->objects->insert( make_pair( rname, this ) );
	((AInstDeclareClass *)target)->getters->insert( make_pair( rname, this ) );
}

const std::string &AInstExternalGet::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstExternalGet" );
#endif

	return "";
};


// AInstExternalSet //
AInstExternalSet::AInstExternalSet( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id )
: AInstDeclareSet::AInstDeclareSet( name, typage, args, new AInstructionVector() )
{
	this->id = id;
};

void AInstExternalSet::setXName( AObject *target )
{
	if( target->rname == rname && typeid(*target) == typeid(AInstDeclareClass) )
	{
		this->constructor = true;
		((AInstDeclareClass *) target)->constructor = this;
	}
	else
		target->objects->insert( make_pair( rname, this ) );
	
	((AInstDeclareClass *)target)->setters->insert( make_pair( rname, this ) );
}

const std::string &AInstExternalSet::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstExternalSet" );
#endif

	return "";
};


// AInstExternalProp //
AInstExternalProp::AInstExternalProp( AExpression *name, ATypage *typage, AExpression *id )
: AInstDeclareProp::AInstDeclareProp( name, typage, id )
{
	this->id = id;
};

void AInstExternalProp::setXName( AObject *target )
{
	_xname = this->id->codeGen(NULL);
	if( target->rname == rname )
	{
		// log( "ERROR: Property name is same as constructor;";
		ERROR_LOG( errorList1[23], PackageManager::currentLine, PackageManager::currentFile.c_str() );
	}
	target->objects->insert( make_pair( rname, this ) );
};

const std::string &AInstExternalProp::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_BLOCK )
	INTERNAL_LOG( "CodeGen AInstExternalProp" );
#endif

	return "";
};

