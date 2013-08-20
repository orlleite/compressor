/*
 instructions.hpp
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

#ifndef Compressor_instructions_hpp
#define Compressor_instructions_hpp

#include <iostream>
#include "types.hpp"


class AInstDeclareVar : public AObject
{
	protected:
		AExpression *name;
	
	public:
		AInstDeclareVar( AExpression *name, ATypage *typage, AExpression *value );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &sCodeGen( Context *ctx );
};

class AInstDeclareMultVar : public AObject
{
	protected:
		AObjectVector *list;
		
	public:
		AInstDeclareMultVar( AObjectVector *list );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstAssign : public AInstruction
{
	protected:
		AExpression *target;
		TokenInfo *token;
		
	public:
		AInstAssign( AExpression *target, TokenInfo *token, AExpression *value );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstBlock : public AInstruction
{
	protected:
		AInstructionVector *list;
	
	public:
		AInstBlock( AInstructionVector *list );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstIf : public AInstBlock
{
	public:
		AInstIf( AExpression *expr, AInstructionVector *list );
		AInstIf( AExpression *expr, AInstruction *inst );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstElseif : public AInstIf
{
	public:
		AInstElseif( AExpression *expr, AInstructionVector *list );
		AInstElseif( AExpression *expr, AInstruction *inst );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstElse : public AInstIf
{
	public:
		AInstElse( AInstructionVector *list );
		AInstElse( AInstruction *inst );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstDo : public AInstIf
{
	public:
		AInstDo( AExpression *expr, AInstructionVector *list );
		AInstDo( AExpression *expr, AInstruction *inst );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstTryCatch : public AInstIf
{
	protected:
		AInstBlock *catchBlock;
		AInstruction *catchArg;
	
	public:
		AInstTryCatch( AInstructionVector *tryList, AInstruction *arg, AInstructionVector *catchList );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstWhile : public AInstIf
{
	public:
		AInstWhile( AExpression *expr, AInstructionVector *list );
		AInstWhile( AExpression *expr, AInstruction *inst );
		virtual const std::string &codeGen(Context *ctx);
};

class AInstFor : public AInstBlock
{
	protected:
		AInstruction *init;
		AInstruction *cond;
		AInstruction *loop;
		
		AInstruction *var;
		AExpression *target;
	
	public:
		AInstFor( AInstruction *init, AInstruction *cond, AInstruction *loop, AInstruction *inst );
		AInstFor( AInstruction *init, AInstruction *cond, AInstruction *loop, AInstructionVector *list );
		
		AInstFor( AInstruction *var, AExpression *target, AInstruction *inst );
		AInstFor( AInstruction *var, AExpression *target, AInstructionVector *list );
		
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstBreak : public AInstruction
{
	public:
		AInstBreak();
		virtual const std::string &codeGen(Context *ctx);
};

class AInstContinue : public AInstruction
{
	public:
		AInstContinue();
		virtual const std::string &codeGen(Context *ctx);
};

class AInstCase : public AInstruction
{
	public:
		AInstCase( AExpression *value );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstDefault : public AInstruction
{
	public:
		AInstDefault();
		virtual const std::string &codeGen( Context *ctx );
};

class AInstSwitch : public AInstIf
{
	public:
		AInstSwitch( AExpression *expr, AInstructionVector *list );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstReturn : public AInstruction
{
	public:
		AInstReturn( AExpression *value );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstDelete : public AInstruction
{
	public:
		AInstDelete( AExpression *value );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstDeclareArg : public AInstDeclareVar
{
	public:
		AInstDeclareArg( AExpression *name, ATypage *typage, AExpression *value );
		virtual const std::string &defaultValue( Context *ctx );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstPack : public AObject
{
	private:
		AExpression *package;
		int type;
	
	public:
		AInstPack();
		AInstPack( AExpression *package );
		AInstPack( AExpression *package, bool importer );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstSuperCall : public AExpCallFunc, public AInstruction
{
	public:
		AInstSuperCall( TokenInfo *token, AExpressionVector *explist );
		virtual const std::string &codeGen( Context *ctx );
};

#endif
