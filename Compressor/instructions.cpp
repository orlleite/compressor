/*
 instructions.cpp
 Compressor
 
 Created by Orlando Leite on 05/12/11.
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
#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "blocks.hpp"
#include "workspace.hpp"
#include "parser.hpp"


// AInstDeclareVar //
AInstDeclareVar::AInstDeclareVar( AExpression *name, ATypage *typage )
: AObject::AObject()
{
	this->name = name;
	this->func = NULL;
	this->typage = typage;
	this->rname = name->codeGen( NULL );
};

AInstDeclareVar::AInstDeclareVar( AExpression *name, ATypage *typage, AExpression *value )
	: AObject::AObject()
{
	this->name = name;
	this->value = value;
	this->func = NULL;
	this->typage = typage;
	this->rname = name->codeGen( NULL );
};

AInstDeclareVar::AInstDeclareVar( AExpression *name, ATypage *typage, AObject *value )
{
	this->name = name;
	this->value = (AExpression *)value;
	this->typage = typage;
	this->func = value;
	this->rname = name->codeGen( NULL );
}

void AInstDeclareVar::setXName( AObject *target )
{
	this->loadTypage();
	
	_xname = target->newname( rname );
	if( this->func ) this->func->setXName( target );
	target->objects->insert( make_pair( rname, this ) );
}

const std::string &AInstDeclareVar::sCodeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "sCodeGen AInstDeclareVar" );
#endif
	
	if( _xname == "" ) _xname = this->name->codeGen( ctx );
	
	std::string *temp = new std::string( _xname );
	if( this->func )
	{
		*temp += SPACE + "=" + SPACE + this->func->codeGen( ctx );
	}
	else if( this->value )
		*temp += SPACE + "=" + SPACE + this->value->codeGen( ctx );
	
	ctx->cpath = NULL;
	
	return *temp;
};

const std::string &AInstDeclareVar::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDeclareVar" );
#endif
	
	return *new std::string( "var " + sCodeGen( ctx ) );
};


// AInstDeclareMultVar //
AInstDeclareMultVar::AInstDeclareMultVar( AObjectVector *list )
	:AObject::AObject()
{
	this->list = list;
}

void AInstDeclareMultVar::setXName( AObject *target )
{
	AObjectVector::const_iterator it;
	for( it = this->list->begin(); it != this->list->end(); it++ )
	{
		(**it).setXName( target );
	}
}

const std::string &AInstDeclareMultVar::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDeclareMultVar" );
#endif
	
	std::string *temp = new std::string("var ");
	AObjectVector::const_iterator it;
	bool first = true;
	
	for( it = this->list->begin(); it != this->list->end(); it++ )
	{
		if( !first ) *temp += "," + SPACE;
		AInstDeclareVar *target = (AInstDeclareVar *)*it;
		*temp += target->sCodeGen( ctx );
		
		first = false;
	}
	
	return *temp;
}


// AInstAssign //
AInstAssign::AInstAssign( AExpression *target, TokenInfo *token, AExpression *value )
	: AInstruction::AInstruction( value )
{
	this->token = token;
	this->target = target;
};

const std::string &AInstAssign::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstAssign" );
#endif
	
	std::string *temp = new std::string( this->target->codeGen( ctx ) );
	bool isSuper = ctx->isSuper;
	
	// if(ctx->cpath) log( ctx->cpath->rname << " -> " << typeid(ctx->cpath).name() << "\n";
	// std::string teste = target->codeGen( NULL );
	// log( teste << " -> " << typeid(*(ctx->cpath)).name() << "\n";
	if( !ctx->cpath || 
	    // typeid(*(ctx->cpath)) == typeid(AObject) || 
	    typeid(*(ctx->cpath)) == typeid(AInstDeclareVar) ||
	    typeid(*(ctx->cpath)) == typeid(AInstDeclareArg) ||
	    typeid(*(ctx->cpath)) == typeid(AInstDeclareProp) 
	  )
	{
		switch( this->token->type() )
		{
			case TASSIGN:
				*temp += SPACE + "=" + SPACE;
				break;
				
			case TASSIGN_DIVIDE:
				*temp += SPACE + "/=" + SPACE;
				break;
				
			case TASSIGN_MULTIPLY:
				*temp += SPACE + "*=" + SPACE;
				break;
				
			case TASSIGN_MINUS:
				*temp += SPACE + "-=" + SPACE;
				break;
				
			case TASSIGN_PLUS:
				*temp += SPACE + "+=" + SPACE;
				break;
		}
		
		ctx->cpath = NULL;
		*temp += this->value->codeGen( ctx );
		ctx->cpath = NULL;
	}
	else
	{
		//  if(ctx->cpath) log( ctx->cpath->rname << " -> " << typeid(ctx->cpath).name() << "\n";
		
		if( ctx->cpath->from && typeid(*(ctx->cpath->from)) == typeid(AInstDeclareClass) )
		{
			AInstruction *setter = ((AInstDeclareClass *)ctx->cpath->from)->setterByName( ctx->cpath->rname );
			
			// log( ctx->cpath->rname << std::endl;
			
			if( setter )
			{
				*temp = temp->substr( 0, temp->size() - ctx->cpath->xname().size() );
				
				if( isSuper ) 
					*temp += setter->xname() + ".apply(" + SPACE + "this," + SPACE + "[";
				else
					*temp += setter->xname() + "(" + SPACE;
			}
			else
			{
				ERROR_LOG( errorList1[21], PackageManager::currentLine, PackageManager::currentFile.c_str(), ctx->cpath->rname.c_str() );
				// log( "error var/pro" << std::endl;
				// ERROR: var/pro or setter not found //
			}
			
			switch( this->token->type() )
			{
				case TASSIGN_DIVIDE:
				case TASSIGN_MULTIPLY:
				case TASSIGN_MINUS:
				case TASSIGN_PLUS:
					// ERROR: set not support this kind of operation //
					break;
			}
			
			ctx->cpath = NULL;
			*temp += this->value->codeGen( ctx );
			ctx->cpath = NULL;
			
			if( isSuper ) *temp += "]";
			*temp += SPACE + ")";
		}
	}
	
	return *temp;
};


// AInstBlock //
AInstBlock::AInstBlock( AInstructionVector *list )
	: AInstruction::AInstruction( NULL )
{
	this->list = list;
};

void AInstBlock::setXName( AObject *target )
{
	AInstructionVector::const_iterator it;
	AInstruction *temp;
	
	if( this->list )
	{
		for( it = list->begin(); it != list->end(); it++ )
		{
			temp = *it;
			temp->setXName( target );
		}
	}
}

const std::string &AInstBlock::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstBlock" );
#endif
	
	std::string *temp = new std::string();
	
	AInstructionVector::const_iterator it;
	bool first = true;
	bool lcase = false;
	bool rbrace = false;
	int lastSize = 0;
	
	for( it = this->list->begin(); it != this->list->end(); it++ )
	{
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
		
		ctx->cpath = NULL;
	}
	
	return *temp;
};


// AInstIf //
AInstIf::AInstIf( AExpression *expr, AInstructionVector *list )
	: AInstBlock::AInstBlock( list )
{
	this->value = expr;
};

AInstIf::AInstIf( AExpression *expr, AInstruction *inst )
	: AInstBlock::AInstBlock( NULL )
{
	list = new AInstructionVector();
	
	list->push_back( inst );
	this->value = expr;
};

const std::string &AInstIf::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstIf" );
#endif
	
	std::string *temp = new std::string( "if(" + SPACE + this->value->codeGen( ctx ) + SPACE + ")" );
	ctx->cpath = NULL;
	
	if( this->list->size() == 1 && !DEBUGGING )
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstElseif //
AInstElseif::AInstElseif( AExpression *expr, AInstructionVector *list )
	: AInstIf::AInstIf( expr, list )
{
	
};

AInstElseif::AInstElseif( AExpression *expr, AInstruction *inst )
	: AInstIf::AInstIf( expr, inst )
{
	
};

const std::string &AInstElseif::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstElseif" );
#endif
	
	std::string *temp = new std::string( "else if(" + SPACE + this->value->codeGen( ctx ) + SPACE + ")" );
	ctx->cpath = NULL;
	
	if( this->list->size() == 1 && !DEBUGGING )
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstElse //
AInstElse::AInstElse( AInstructionVector *list )
	: AInstIf::AInstIf( NULL, list )
{
	
};

AInstElse::AInstElse( AInstruction *inst )
	: AInstIf::AInstIf( NULL, inst )
{
	
};

const std::string &AInstElse::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstElse" );
#endif
	
	std::string *temp = new std::string( "else" );
	if( this->list->size() == 1 && !DEBUGGING )
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstWhile //
AInstWhile::AInstWhile( AExpression *expr, AInstructionVector *list )
	: AInstIf::AInstIf( expr, list )
{
	
};

AInstWhile::AInstWhile( AExpression *expr, AInstruction *inst )
	: AInstIf::AInstIf( expr, inst )
{
	
};

const std::string &AInstWhile::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstWhile" );
#endif
	
	std::string *temp = new std::string( "while(" + SPACE + this->value->codeGen(ctx) + SPACE + ")" );
	ctx->cpath = NULL;
	
	if( this->list->size() == 1 && !DEBUGGING )
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstDo //
AInstDo::AInstDo( AExpression *expr, AInstructionVector *list )
	: AInstIf::AInstIf( expr, list )
{
	
};

AInstDo::AInstDo( AExpression *expr, AInstruction *inst )
	: AInstIf::AInstIf( expr, inst )
{
	
};

const std::string &AInstDo::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDo" );
#endif
	
	std::string *temp = new std::string( "do" );
	if( this->list->size() == 1 && !DEBUGGING )
	{
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
		ctx->cpath = NULL;
		*temp += "while(" + SPACE + this->value->codeGen( ctx ) + SPACE + ")";
	}
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}" + SPACE + "while(" + SPACE;
		
		ctx->cpath = NULL;
		*temp += this->value->codeGen( ctx ) + SPACE + ")";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstTryCatch //
AInstTryCatch::AInstTryCatch( AInstructionVector *tryList, AInstruction *arg, AInstructionVector *catchList )
	: AInstIf::AInstIf( NULL, tryList )
{
	this->catchBlock = new AInstBlock( catchList );
	this->catchArg = arg;
}

void AInstTryCatch::setXName( AObject *target )
{
	this->catchArg->setXName( target );
}

const std::string &AInstTryCatch::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstTryCatch" );
#endif
	
	std::string *temp = new std::string( "try" );
	
	if( this->list->size() == 1 && !DEBUGGING )
	{
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
		ctx->cpath = NULL;
		*temp += "catch(" + SPACE + this->catchArg->codeGen( ctx ) + SPACE + ")";
		ctx->cpath = NULL;
		*temp += LINE_BREAK + ctx->tabs + "{" + this->catchBlock->codeGen( ctx ) + "}";
	}
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
		ctx->cpath = NULL;
		*temp += LINE_BREAK + ctx->tabs + "catch(" + SPACE + this->catchArg->codeGen( ctx ) + SPACE + ")";
		ctx->cpath = NULL;
		*temp += LINE_BREAK + ctx->tabs + "{" + this->catchBlock->codeGen( ctx ) + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstFor //
AInstFor::AInstFor( AInstruction *init, AInstruction *cond, AInstruction *loop, AInstruction *inst )
	: AInstBlock::AInstBlock( NULL )
{
	this->init = init;
	this->cond = cond;
	this->loop = loop;
	
	this->list = new AInstructionVector();
	this->list->push_back( inst );
};

AInstFor::AInstFor( AInstruction *init, AInstruction *cond, AInstruction *loop, AInstructionVector *list )
	: AInstBlock::AInstBlock( NULL )
{
	this->init = init;
	this->cond = cond;
	this->loop = loop;
	
	this->list = list;
};

AInstFor::AInstFor( AInstruction *var, AExpression *target, AInstruction *inst )
	: AInstBlock::AInstBlock( NULL )
{
	this->var = var;
	this->target = target;
	
	this->list = new AInstructionVector();
	this->list->push_back( inst );
}

AInstFor::AInstFor( AInstruction *var, AExpression *target, AInstructionVector *list )
	: AInstBlock::AInstBlock( NULL )
{
	this->var = var;
	this->target = target;
	this->list = list;
}

void AInstFor::setXName( AObject *target )
{
	if( var )
	{
		this->var->setXName( target );
	}
	else
	{
		init->setXName( target );
		cond->setXName( target );
		loop->setXName( target );
	}
	
	AInstBlock::setXName( target );
}

const std::string &AInstFor::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstFor" );
#endif
	
	std::string *temp;
	
	if( var )
	{
		temp = new std::string( "for(" + SPACE + var->codeGen( ctx ) + " in " );
		ctx->cpath = NULL;
		*temp += target->codeGen( ctx ) + SPACE + ")";
		ctx->cpath = NULL;
	}
	else
	{
		temp = new std::string( "for(" + SPACE + init->codeGen( ctx ) + ";" );
		ctx->cpath = NULL;
		*temp += SPACE + cond->codeGen( ctx ) + ";";
		ctx->cpath = NULL;
		*temp += SPACE + loop->codeGen( ctx ) + SPACE + ")";
		ctx->cpath = NULL;
	}
	
	if( this->list->size() == 1 && !DEBUGGING )
		*temp += "{" + AInstBlock::codeGen( ctx ) + "}";
	else
	{
		*temp += LINE_BREAK + ctx->tabs + "{";
		
		if( DEBUGGING ) ctx->tabs += "	";
		*temp += AInstBlock::codeGen( ctx );
		if( DEBUGGING ) ctx->tabs.resize( ctx->tabs.size() - 1 );
		
		*temp += LINE_BREAK + ctx->tabs + "}";
	}
	
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstBreak //
AInstBreak::AInstBreak()
	: AInstruction::AInstruction( NULL )
{
	
};

const std::string &AInstBreak::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstBreak" );
#endif
	
	return *new std::string( "break" );
};


// AInstContinue //
AInstContinue::AInstContinue()
	: AInstruction::AInstruction( NULL )
{
	
};

const std::string &AInstContinue::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstContinue" );
#endif
	
	return *new std::string( "continue" );
};


// AInstCase //
AInstCase::AInstCase( AExpression *value )
	: AInstruction::AInstruction( value )
{
	
};

const std::string &AInstCase::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstCase" );
#endif
	
	std::string *temp = new std::string( "case " + value->codeGen( ctx ) + ":" );
	ctx->cpath = NULL;
	return *temp;
};


// AInstDefault //
AInstDefault::AInstDefault()
	: AInstruction::AInstruction( NULL )
{
	
};

const std::string &AInstDefault::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDefault" );
#endif
	
	return *new std::string( "default:" );
};


// AInstSwitch //
AInstSwitch::AInstSwitch( AExpression *expr, AInstructionVector *list )
	: AInstIf::AInstIf( expr, list )
{
	
}

const std::string &AInstSwitch::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstSwitch" );
#endif
	
	std::string *temp = new std::string( "switch(" + SPACE + this->value->codeGen( ctx ) + SPACE + ")" + LINE_BREAK + ctx->tabs + "{" );
	ctx->cpath = NULL;
	*temp += AInstBlock::codeGen( ctx ) + LINE_BREAK + ctx->tabs + "}";
	ctx->cpath = NULL;
	return *temp;
};


// AInstReturn //
AInstReturn::AInstReturn( AExpression *value )
	: AInstruction::AInstruction( value )
{
	
};

const std::string &AInstReturn::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstReturn" );
#endif
	
	std::string *temp = new std::string( "return" );
	
	if( value )
	{
		*temp += " " + this->value->codeGen( ctx );
		ctx->cpath = NULL;
	}
	
	return *temp;
};


// AInstDelete //
AInstDelete::AInstDelete( AExpression *value )
	: AInstruction::AInstruction( value )
{
	
};

const std::string &AInstDelete::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDelete" );
#endif
	
	std::string *temp = new std::string( "delete " + this->value->codeGen( ctx ) );
	ctx->cpath = NULL;
	
	return *temp;
};


// AInstDeclareArg //
AInstDeclareArg::AInstDeclareArg( AExpression *name, ATypage *typage, AExpression *value )
	: AInstDeclareVar::AInstDeclareVar( name, typage, value )
{
	/*if( name->codeGen(NULL) == "asdfasdf" )
		log( rname << " teste: " << value );*/
};

const std::string &AInstDeclareArg::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstDeclareArg" );
#endif
	
	// log( "_xname: " << _xname );
	/*if( _xname == "" )
	{
		_xname = this->value->codeGen( ctx );
	}*/
	ctx->cpath = NULL;
	
	return _xname;
};

const std::string &AInstDeclareArg::defaultValue( Context *ctx )
{
	if( _xname == "" ) _xname = this->value->codeGen( ctx );
	ctx->cpath = NULL;
	
	if( this->value )
	{
		std::string *temp = new std::string
		(
			"if(" + SPACE + "typeof " + _xname + SPACE +
			"==" + SPACE + "\"undefined\"" + SPACE + ")" + SPACE + _xname +
			SPACE + "=" + SPACE + this->value->codeGen( ctx )
		);
		ctx->cpath = NULL;
		
		return *temp;
	}	
	else
		return *new std::string();
};

AInstPack::AInstPack( AExpression *package )
	: AObject::AObject()
{
	this->package = package;
	this->type = 0;
};

AInstPack::AInstPack( AExpression *package, bool importer )
	: AObject::AObject()
{
	this->package = package;
	this->type = importer ? 1 : 0;
};

AInstPack::AInstPack()
	: AObject::AObject()
{
	this->type = 2;
};

const std::string &AInstPack::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstPack" );
#endif
	
	switch( type )
	{
		case 0:
			PackageManager::setCurrentPath( package );
			break;
			
		case 1:
			PackageManager::addImportPath( package );
			break;
			
		case 2:
			PackageManager::endOfFile();
			break;
	}
	
	return *new std::string();
}


// AInstSuperCall //
AInstSuperCall::AInstSuperCall( TokenInfo *token, AExpressionVector *explist )
	:AExpCallFunc::AExpCallFunc( NULL, explist ), AInstruction::AInstruction( NULL )
{
	this->token = token;
}

const std::string &AInstSuperCall::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_INSTRUCTION )
	INTERNAL_LOG( "CodeGen AInstSuperCall" );
#endif

	AInstDeclareClass *currentClass = (AInstDeclareClass *)ctx->cthis;
	
	std::string *temp = new std::string( "$." + currentClass->extendsClass->xname() + ".apply(" + SPACE + "this" );
	if( explist && explist->size() > 0 ) *temp += "," + SPACE + "[";
	
	ctx->cpath = NULL;
	
	*temp += this->argsGen( ctx );
	if( explist && explist->size() > 0 ) *temp += "]";
	*temp += SPACE + ")";
	
	return *temp;
}

