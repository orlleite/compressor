/*
 expressions.hpp
 Compressor
 
 Created by Orlando Leite on 02/12/11.
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

#ifndef Compressor_expressions_h
#define Compressor_expressions_h

#include <iostream>
#include "types.hpp"

class AExpParent : public AExpression
{
	public:
		AExpParent( AExpression *a );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpFastOp : public AExpression
{
	protected:
		bool before;
	
	public:
		AExpFastOp( AExpression *a, TokenInfo *token, bool before );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpOperation : public AExpression
{
	public:
		AExpOperation( AExpression *a, TokenInfo *token, AExpression *b );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpAssign : public AExpOperation
{
	public:
		AExpAssign( AExpression *a, TokenInfo *token, AExpression *b );
		virtual const std::string &codeGen(Context *ctx);
};

class AExpGetPath : public AExpression
{
	protected:
		AExpGetPath *append;
	
	public:
		AExpGetPath( AExpression *a );
		void appendCall( AExpGetPath *append );
		
		virtual AExpGetPath *appended();
		virtual const std::string &name( Context *ctx );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpSuper : public AExpGetPath
{
	public:
		AExpSuper( TokenInfo *token );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpGetItem : public AExpGetPath
{
	protected:
		AExpression *c;
		
	public:
		AExpGetItem( AExpression *a, AExpression *c );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpSetPath : public AExpGetPath
{
	public:
		AExpSetPath( AExpression *a );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpSetItem : public AExpSetPath
{
	protected:
		AExpression *c;
		
	public:
		AExpSetItem( AExpression *a, AExpression *c );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpCallFunc : public AExpGetPath
{
	protected:
		AExpressionVector *explist;
	
	public:
		AExpCallFunc( AExpression *a, AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
		const std::string &argsGen( Context *ctx );
};

class AExpNewArray : public AExpGetPath
{
	protected:
		AExpressionVector *explist;
	
	public:
		AExpNewArray( AExpressionVector *explist, AExpression *type );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpObjectProp : public AExpression
{
	public:
		AExpObjectProp( AExpression *a, AExpression *b );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpNewObject : public AExpGetPath
{
	protected:
		AExpressionVector *explist;
		
	public:
		AExpNewObject( AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpNew : public AExpCallFunc
{
	public:
		AExpNew( AExpression *a, AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
};

class AExpIfast : public AExpression
{
	protected:
		AExpression *c;
	public:
		AExpIfast( AExpression *a, AExpression *b, AExpression *c );
		virtual const std::string &codeGen( Context *ctx );
};

class CompilerName : public AExpression
{
	protected:
		AExpressionVector *explist;
	
	public:
		CompilerName( AExpression *a );
		virtual const std::string &codeGen( Context *ctx );
};

class CompilerGet : public AExpCallFunc
{
	public:
		CompilerGet( AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
};

class CompilerSet : public AExpCallFunc
{
	public:
		CompilerSet( AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
};

#endif
