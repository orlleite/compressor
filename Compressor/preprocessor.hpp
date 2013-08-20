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
class ALine;

typedef std::deque<std::string> StringDeque;
typedef std::vector<ALine *> ALineVector;
typedef std::map<std::string, std::string> StringMap;

extern PreProcessor *pp;

class ALine
{
	protected:
		TokenInfo *token;
		
	public:
		ALine( TokenInfo *token );
		virtual const std::string &codeGen();
};

class ADefine : public ALine
{
	protected:
		TokenInfo *value;
		
	public:
		ADefine( TokenInfo *name, TokenInfo *value );
		virtual const std::string &codeGen();
};

class AIfDef : public ALine
{
	public:
		AIfDef( TokenInfo *token );
		virtual const std::string &codeGen();
};

class AElseIfDef : public ALine
{
	public:
		AElseIfDef( TokenInfo *token );
		virtual const std::string &codeGen();
};

class AElseDef : public ALine
{
	public:
		AElseDef();
		virtual const std::string &codeGen();
};

class AEndIfDef : public ALine
{
	public:
		AEndIfDef();
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
		void codeGenAndSave( ALineVector *block );
		void deleteTempFolder();
	
		const std::string &replaceDefinitions( const std::string &value );
};

#endif
