/*
 blocks.hpp
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

#ifndef __Compressor__blocks__
#define __Compressor__blocks__

#include <iostream>
#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"


class AInstDeclareFunc : public AObject
{
	protected:
		AInstructionVector *block;
		AInstructionVector *args;
		AObject *owner;
		
	public:
		AInstDeclareFunc( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block );
		bool constructor;
		void setOwner( AObject *owner );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &blockGen( Context *ctx );
};

class AInstDeclareMethod : public AInstDeclareFunc
{
	public:
		AInstDeclareMethod( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstDeclareGet : public AInstDeclareMethod
{
	public:
		AInstDeclareGet( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block );
		virtual void setXName( AObject *target );
};

class AInstDeclareSet : public AInstDeclareMethod
{
	public:
		AInstDeclareSet( AExpression *name, ATypage *typage, AInstructionVector *args, AInstructionVector *block );
		virtual void setXName( AObject *target );
};

class AInstDeclareProp : public AObject
{
	protected:
		AExpression *name;
		
	public:
		AInstDeclareProp( AExpression *name, ATypage *typage, AExpression *value );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstDeclareMultProp : public AObject
{
	protected:
		AObjectVector *list;
		
	public:
		AInstDeclareMultProp( AObjectVector *list );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

// EXTERNALS //
class AInstExternalMethod : public AInstDeclareFunc
{
	protected:
		AExpression *id;
	
	public:
		AInstExternalMethod( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstExternalGet : public AInstDeclareGet
{
	protected:
		AExpression *id;
		bool isVar;
		
	public:
		AInstExternalGet( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id, bool isVar );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstExternalSet : public AInstDeclareSet
{
	protected:
		AExpression *id;
		
	public:
		AInstExternalSet( AExpression *name, ATypage *typage, AInstructionVector *args, AExpression *id );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstExternalProp : public AInstDeclareProp
{
	protected:
		AExpression *id;
	
	public:
		AInstExternalProp( AExpression *name, ATypage *typage, AExpression *id );
		virtual void setXName( AObject *target );
		virtual const std::string &codeGen( Context *ctx );
};

#endif /* defined(__Compressor__blocks__) */
