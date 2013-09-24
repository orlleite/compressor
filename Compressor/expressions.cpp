/*
 expressions.cpp
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
#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "blocks.hpp"
#include "workspace.hpp"
#include "parser.hpp"


// AExprParent //
AExpParent::AExpParent( AExpression *a )
	: AExpression::AExpression( NULL )
{
	this->a = a;
};

const std::string &AExpParent::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpParent" );
#endif
	return *new std::string( "(" + SPACE + this->a->codeGen( ctx ) + SPACE + ")" );
}


// AExpFastOp //
AExpFastOp::AExpFastOp( AExpression *a, TokenInfo *token, bool before )
	: AExpression::AExpression( token )
{
	this->a = a;
	this->before = before;
};

const std::string &AExpFastOp::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpFastOp" );
#endif
	
	std::string temp;
	
	switch ( this->token->type() )
	{
		case TINCREMENT:
			temp = "++";
			break;
			
		case TDECREMENT:
			temp = "--";
			break;
			
		case TMINUS:
			temp = "-";
			break;
			
		case TBNOT:
			temp = "~";
			break;
		
		case TNOT:
			temp = "!";
			break;
	}
	
	return *new std::string( this->before ? temp + this->a->codeGen( ctx ) : this->a->codeGen( ctx ) + temp );
};


// AExpOperation //
AExpOperation::AExpOperation( AExpression *a, TokenInfo *token, AExpression *b )
	: AExpression::AExpression( token )
{
	this->a = a;
	this->b = b;
};

const std::string &AExpOperation::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpOperation" );
#endif
	
	std::string *temp = new std::string();
	
	*temp += this->a->codeGen( ctx );
	ctx->cpath = NULL;
	
	switch( this->token->type() )
	{
		case TPLUS:
			*temp += SPACE + "+" + SPACE;
			break;
		
		case TMINUS:
			*temp += SPACE + "-" + SPACE;
			break;
		
		case TMULT:
			*temp += SPACE + "*" + SPACE;
			break;
			
		case TDIVIDE:
			*temp += SPACE + "/" + SPACE;
			break;
			
		case TMODULUS:
			*temp += SPACE + "%" + SPACE;
			break;
			
		case TEQ:
			*temp += SPACE + "==" + SPACE;
			break;
			
		case TEQA:
			*temp += SPACE + "===" + SPACE;
			break;
			
		case TNE:
			*temp += SPACE + "!=" + SPACE;
			break;
		
		case TNEA:
			*temp += SPACE + "!==" + SPACE;
			break;
			
		case TLT:
			*temp += SPACE + "<" + SPACE;
			break;
			
		case TLE:
			*temp += SPACE + "<=" + SPACE;
			break;
			
		case TGT:
			*temp += SPACE + ">" + SPACE;
			break;
			
		case TGE:
			*temp += SPACE + ">=" + SPACE;
			break;
			
		case TOR:
			*temp += SPACE + "||" + SPACE;
			break;
			
		case TAND:
			*temp += SPACE + "&&" + SPACE;
			break;
			
		case TBAND:
			*temp += SPACE + "&" + SPACE;
			break;
			
		case TBOR:
			*temp += SPACE + "|" + SPACE;
			break;
			
		case TBXOR:
			*temp += SPACE + "^" + SPACE;
			break;
			
		case TLSHIFT:
			*temp += SPACE + "<<" + SPACE;
			break;
			
		case TRSHIFT:
			*temp += SPACE + ">>" + SPACE;
			break;
			
		case TZFILL:
			*temp += SPACE + ">>>" + SPACE;
			break;
			
		case TINSTANCEOF:
			*temp += " instanceof ";
			break;
	}
	// *temp += ":";
	*temp += this->b->codeGen( ctx );
	
	return *temp;
};


// AExpAssign //
AExpAssign::AExpAssign( AExpression *a, TokenInfo *token, AExpression *b )
	: AExpOperation::AExpOperation( a, token, b )
{
	
}

const std::string &AExpAssign::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpAssign" );
#endif
	
	std::string *temp = new std::string( this->a->codeGen( ctx ) );
	
	// if(ctx->cpath) log( ctx->cpath->rname << " -> " << typeid(ctx->cpath).name() << "\n";
	
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
			
			case TASSIGN_BOR:
				*temp += SPACE + "|=" + SPACE;
				break;
		}
		
		ctx->cpath = NULL;
		*temp += this->b->codeGen( ctx );
		ctx->cpath = NULL;
	}
	else
	{
		//  if(ctx->cpath) log( ctx->cpath->rname << " -> " << typeid(ctx->cpath).name() << "\n";
		
		if( ctx->cpath->from && typeid(*(ctx->cpath->from)) == typeid(AInstDeclareClass) )
		{
			AInstruction *setter = ((AInstDeclareClass *)ctx->cpath->from)->setterByName( ctx->cpath->rname );
			
			if( setter )
			{
				// log( "setter call" << std::endl;
				*temp = temp->substr( 0, temp->size() - ctx->cpath->xname().size() );
				*temp += setter->xname() + "(" + SPACE;
			}
			else
			{
				ERROR_LOG( errorList1[21], PackageManager::currentLine, PackageManager::currentFile.c_str(), ctx->cpath->rname.c_str() );
				// log( "ERROR: var/pro or setter not found." << std::endl;
			}
			
			switch( this->token->type() )
			{
				case TASSIGN_DIVIDE:
				case TASSIGN_MULTIPLY:
				case TASSIGN_MINUS:
				case TASSIGN_PLUS:
					ERROR_LOG( errorList1[22], PackageManager::currentLine, PackageManager::currentFile.c_str() );
					// ERROR: set not support this kind of operation //
					break;
			}
			
			ctx->cpath = NULL;
			*temp += this->b->codeGen( ctx );
			ctx->cpath = NULL;
			
			*temp += SPACE + ")";
		}
	}
	
	return *temp;
};


// AExpGetPath //
AExpGetPath::AExpGetPath( AExpression *a )
	: AExpression::AExpression( NULL )
{
	this->a = a;
	this->append = NULL;
};

void AExpGetPath::appendCall( AExpGetPath *append )
{
	if( this->append )
		this->append->appendCall( append );
	else 
		this->append = append;
};

AExpGetPath *AExpGetPath::appended()
{
	return append;
}

const std::string &AExpGetPath::name( Context *ctx )
{
	std::string *xname = new std::string( this->a->codeGen( ctx ) );
	
	return *xname;
}

const std::string &AExpGetPath::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpGetPath" );
#endif
	
	bool isSuper = ctx && ctx->isSuper ? true : false;
	std::string *temp = new std::string( a ? a->codeGen( ctx ) : "" );
	
	if( ctx && ctx->cpath && typeid(*(ctx->cpath)) == typeid(AInstDeclareGet) )
	{
		if( isSuper )
			*temp += ".apply(" + SPACE + "this" + SPACE + ")";
		else
			*temp += "()";
	}
	
	if( this->append )
		*temp += ( this->append != NULL ? "." + this->append->codeGen( ctx ) : "" );
	
	return *temp;
};


// AExpSuper //
AExpSuper::AExpSuper( TokenInfo *token )
: AExpGetPath::AExpGetPath( NULL )
{
	this->token = token;
}

const std::string &AExpSuper::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpSuper" );
#endif
	
	AInstDeclareClass *currentClass = (AInstDeclareClass *)ctx->cthis;
	AObject *tsuper = new AObject();
	ctx->cpath = tsuper;
	if( ctx && ctx->cthis ) tsuper->typage = new ATypage( (currentClass)->extendsClass->rname, false );
	ctx->isSuper = true;
	
	std::string *temp = new std::string( ( currentClass->extendsClass->external ? "" : "$." ) +
											currentClass->extendsClass->xname() + ".prototype" );
	
	if( this->append )
		*temp += ( this->append != NULL ? "." + this->append->codeGen( ctx ) : "" );
	
	return *temp;
}


// AExpGetItem //
AExpGetItem::AExpGetItem( AExpression *a, AExpression *c )
	: AExpGetPath::AExpGetPath( a )
{
	this->c = c;
}

const std::string &AExpGetItem::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpGetItem" );
#endif
	
	std::string *temp = new std::string( this->a->codeGen( ctx ) + "[" );
	AObject *tempPath = ctx->cpath;
	// log( tempPath->typage->codeGen(NULL) << "\n";
	ctx->cpath = NULL;
	
	*temp += this->c->codeGen(ctx) + "]";
	
	std::string obj = tempPath->typage->arrayType;
	
	PackageManager::searchingObjectFromLine = tempPath->typage->line;
	PackageManager::searchingObjectFromFile = tempPath->typage->filename;
	
	AObject *target = PackageManager::getObject( obj );
	
	// log( target << std::endl;
	
	if( target )
	{
		ctx->ctarget = target;
		ctx->cpathClass = false;
	}
	
	// ctx->cpath = tempPath;
	log( typeid(this->append).name() );
	
	if( this->append ) *temp += "." + this->append->codeGen(ctx);
	
	return *temp;
};


// AExpSetPath //
AExpSetPath::AExpSetPath( AExpression *a )
	: AExpGetPath::AExpGetPath( a )
{
	
};

const std::string &AExpSetPath::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpSetPath" );
#endif
	
	bool isSuper = ctx ? ctx->isSuper : false;
	const std::string *temp = &(this->a->codeGen(ctx));
	if( ctx ) ctx->isSuper = isSuper;
	
	return *temp;
};


// AExpSetItem //
AExpSetItem::AExpSetItem( AExpression *a, AExpression *c )
	: AExpSetPath::AExpSetPath( a )
{
	this->c = c;
}

const std::string &AExpSetItem::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpSetItem" );
#endif
	
	std::string *xname = new std::string( this->a->codeGen( ctx ) + "[" );
	if( ctx ) ctx->cpath = NULL;
	
	AObject *tempPath = ctx->cpath;
	// log( tempPath->typage->codeGen(NULL) << "\n";
	ctx->cpath = NULL;
	*xname += this->c->codeGen( ctx ) + "]";
	ctx->cpath = tempPath;
	
	return *xname;
};


// AExpCallFunc //
AExpCallFunc::AExpCallFunc( AExpression *a, AExpressionVector *explist )
	: AExpGetPath::AExpGetPath( a )
{
	this->explist = explist;
}

const std::string &AExpCallFunc::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpCallFunc" );
#endif
	
	std::string *temp = new std::string();
	bool isSuper = ctx->isSuper;
	if( isSuper )
	{
		*temp += this->a->codeGen( ctx ) + ".apply(" + SPACE + "this";
		if( explist && explist->size() > 0 ) *temp += "," + SPACE + "[";
	}
	else
	{
		*temp += this->a->codeGen( ctx ) + "(";
	}
	
	AObject *tempPath = ctx->cpath;
	ctx->cpath = NULL;
	
	*temp += this->argsGen( ctx );
	if( isSuper && explist && explist->size() > 0 ) *temp += "]" + SPACE;
	*temp += ")";
	
	ctx->cpath = tempPath;
	if( ctx->cpath && typeid(*ctx->cpath) != typeid(AInstDeclareClass) && ctx->cpath->typage )
	{
		// log( ctx->cpath->rname << "\n";
		std::string typage = ctx->cpath->typage->type;
		if( typage != "" )
		{
			PackageManager::searchingObjectFromLine = ctx->cpath->typage->line;
			PackageManager::searchingObjectFromFile = ctx->cpath->typage->filename;
			
			AObject *inst = PackageManager::getObject( typage );
			if( inst )
			{
				ctx->cpath = new AObject();
				ctx->cpath->typage = new ATypage( typage, false );
				ctx->cpathClass = false;
			}
			else
			{
				ctx->cpath = NULL;
				ctx->cpathClass = false;
			}
		}
		else
		{
			ctx->cpath = NULL;
			ctx->cpathClass = false;
		}
	}
	
	if( this->append ) *temp += "." + this->append->codeGen( ctx );
	
	return *temp;
};

const std::string &AExpCallFunc::argsGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "ArgsGen AExpCallFunc" );
#endif
	std::string *temp = new std::string();
	
	if( this->explist )
	{
		*temp += SPACE;
		
		AExpressionVector::const_iterator it;
		bool first = true;
		
		for( it = explist->begin(); it != explist->end(); it++ )
		{
			ctx->cpath = NULL;
			if( !first ) *temp += "," + SPACE;
			*temp += (**it).codeGen( ctx );
			
			first = false;
		}
		
		*temp += SPACE;
	}
	
	return *temp;
};


// AExpNewArray //
AExpNewArray::AExpNewArray( AExpressionVector *explist, AExpression *a )
	: AExpGetPath::AExpGetPath( a )
{
	this->explist = explist;
}

const std::string &AExpNewArray::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpNewArray" );
#endif
	
	std::string *temp = new std::string( "[" );
	
	if( this->explist )
	{
		AExpressionVector::const_iterator it;
		bool first = true;
		
		for( it = explist->begin(); it != explist->end(); it++ )
		{
			ctx->cpath = NULL;
			if( !first ) *temp += "," + SPACE;
			*temp += (**it).codeGen(ctx);
			
			first = false;
		}
		
		*temp += "]";
	}
	else
	{
		*temp += "]";
	}
	
	// shoud implement something like: ctx->cpath = Array //
	if( this->append ) *temp += "." + this->append->codeGen( ctx );
	
	return *temp;
};


//  AExpObjectProp //
AExpObjectProp::AExpObjectProp( AExpression *a, AExpression *b )
	: AExpression::AExpression( NULL )
{
	this->a = a;
	this->b = b;
};

const std::string &AExpObjectProp::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpObjectProp" );
#endif
	
	std::string *xname = new std::string( this->a->codeGen( NULL ) );
	*xname += ":" + this->b->codeGen( ctx );
	
	return *xname; 
};


// AExpNewObject //
AExpNewObject::AExpNewObject( AExpressionVector *explist )
	: AExpGetPath::AExpGetPath( a )
{
	this->explist = explist;
};

const std::string &AExpNewObject::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpNewObject" );
#endif
	std::string *temp = new std::string( "{" + SPACE );
	
	if( this->explist )
	{
		AExpressionVector::const_iterator it;
		bool first = true;
		
		for( it = explist->begin(); it != explist->end(); it++ )
		{
			ctx->cpath = NULL;
			if( !first ) *temp += "," + SPACE;
			*temp += (**it).codeGen( ctx );
			
			first = false;
		}
	}
	
	*temp += SPACE + "}";
	
	// shoud implement something like: ctx->cpath = Object //
	if( this->append ) *temp += "." + this->append->codeGen(ctx);
	
	return *temp;
};


// AExpNew //
AExpNew::AExpNew( AExpression *a, AExpressionVector *explist )
	: AExpCallFunc::AExpCallFunc( a, explist )
{
	
};

const std::string &AExpNew::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpNew" );
#endif
	
	std::string *temp = new std::string( "new " + this->a->codeGen( ctx ) );
	
	AObject *tempPath = ctx->cpath;
	ctx->cpath = NULL;
	*temp += "(" + SPACE + this->argsGen( ctx ) + SPACE + ")";
	
	ctx->cpath = tempPath;
	if( ctx->cpath )
	{
		PackageManager::searchingObjectFromLine = 0;
		PackageManager::searchingObjectFromFile = "undefined";
		
		AObject *inst = PackageManager::getObject( ctx->cpath->rname );
		if( inst )
		{
			ctx->cpath = inst;
			ctx->cpathClass = false;
		}
		else
		{
			ctx->cpath = NULL;
			ctx->cpathClass = false;
		}
	}
	
	if( this->append ) *temp += "." + this->append->codeGen( ctx );
	
	return *temp;
};


// AExpIfast //
AExpIfast::AExpIfast( AExpression *a, AExpression *b, AExpression *c )
	: AExpression::AExpression( NULL )
{
	this->a = a;
	this->b = b;
	this->c = c;
};

const std::string &AExpIfast::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen AExpIfast" );
#endif
	
	std::string *xname = new std::string( this->a->codeGen( ctx ) + SPACE + "?" + SPACE );
	
	ctx->cpath = NULL;
	*xname += this->b->codeGen( ctx ) + SPACE + ":" + SPACE;
	
	ctx->cpath = NULL;
	*xname += this->c->codeGen( ctx );
	
	return *xname;
};


// CompilerName //
CompilerName::CompilerName( AExpression *a ) 
	: AExpression::AExpression( NULL )
{
	this->a = a;
};

const std::string &CompilerName::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen CompilerName" );
#endif
	
	Context *cctx = new Context();
	cctx->ignoreStatic = true;
	this->a->codeGen( cctx );
	
	if( cctx->cpath )
		return cctx->cpath->xname();
	else
		return this->a->codeGen( NULL );
};


// CompilerGet //
CompilerGet::CompilerGet( AExpressionVector *explist )
	: AExpCallFunc::AExpCallFunc( NULL, explist )
{
	
};

const std::string &CompilerGet::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen CompilerGet" );
#endif
	
	std::string *temp = new std::string( "$._0(" + SPACE );
	*temp += this->argsGen( ctx );
	*temp += SPACE + ")";
	
	return *temp;
}

// CompilerSet //
CompilerSet::CompilerSet( AExpressionVector *explist )
	: AExpCallFunc::AExpCallFunc( NULL, explist )
{
	
};

const std::string &CompilerSet::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_EXPRESSION )
	INTERNAL_LOG( "CodeGen CompilerSet" );
#endif
	
	std::string *temp = new std::string( "$._1(" + SPACE );
	*temp += this->argsGen( ctx );
	*temp += SPACE + ")";
	
	return *temp;
}





