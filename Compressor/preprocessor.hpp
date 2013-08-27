/*
 preprocessor.hpp
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

#ifndef Compressor_preprocessor_h
#define Compressor_preprocessor_h

#include "types.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <map>

// #define DEBUG_PARSER true

class PreProcessor;
class PLine;

typedef std::deque<std::string> StringDeque;
typedef std::vector<PLine *> PLineVector;
typedef std::map<std::string, std::string> StringMap;

extern PreProcessor *pp;

class PLine
{
	protected:
		TokenInfo *token;
		
	public:
		PLine( TokenInfo *token );
		virtual const std::string &codeGen();
};

class PDefine : public PLine
{
	protected:
		TokenInfo *value;
		
	public:
		PDefine( TokenInfo *name, TokenInfo *value );
		virtual const std::string &codeGen();
};

class PExpression
{
	protected:
		TokenInfo *token;
		PExpression *a;
		PExpression *b;
		
	public:
		PExpression( TokenInfo *token );
		virtual bool result();
};

class PExpParent : public PExpression
{
	public:
		PExpParent( PExpression *a );
		virtual bool result();
};

class PExpOperation : public PExpression
{
	public:
		PExpOperation( PExpression *a, TokenInfo *token, PExpression *b );
		virtual bool result();
};

class PExpNot : public PExpression
{
	public:
		PExpNot( TokenInfo *a );
		virtual bool result();
};

class PIfDef : public PLine
{
	protected:
		PExpression *a;
	
	public:
		PIfDef( PExpression *a );
		virtual const std::string &codeGen();
};

class PElseIfDef : public PLine
{
	protected:
		PExpression *a;
	
	public:
		PElseIfDef( PExpression *a );
		virtual const std::string &codeGen();
};

class PElseDef : public PLine
{
	public:
		PElseDef();
		virtual const std::string &codeGen();
};

class PEndIfDef : public PLine
{
	public:
		PEndIfDef();
		virtual const std::string &codeGen();
};

class PreProcessor
{
	protected:
		std::string tempFolder;
		StringMap *defines;
		void saveToFile( const std::string &value );
		std::string names;
		std::string &newname();
	
	public:
		bool ifstate;
		bool ifgotone;
		bool ifcopen;
	
		PreProcessor( std::string path );
		bool processFile( std::string filePath );
		void addDef( std::string &name, std::string &value );
		bool isDef( std::string &name );
		void removeDef( std::string &name );
		void codeGenAndSave( PLineVector *block );
		void deleteTempFolder();
	
		const std::string &replaceDefinitions( const std::string &value );
};

#endif
