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

#ifndef Compressor_types_hpp
#define Compressor_types_hpp

#include <iostream>
#include <vector>
#include <deque>
#include <map>

/*
 This is used to debug the nano processor itself. The name represent the position in files
 */
#define INTERNAL_DEBUG true
// #define DEBUG_CREATE_EXPRESSION true
// #define DEBUG_CREATE_INSTRUCTION true
// #define DEBUG_CREATE_BLOCKS true
// #define DEBUG_CREATE_WORKSPACE true
//
// #define DEBUG_CODEGEN_EXPRESSION true
// #define DEBUG_CODEGEN_INSTRUCTION true
// #define DEBUG_CODEGEN_BLOCK true
// #define DEBUG_CODEGEN_WORKSPACE true
// #define DEBUG_PACKAGE true

#define ERROR_LOG( a, ... ) { printf( a, __VA_ARGS__ ); exit(0); }
#define INTERNAL_LOG( a ) { std::cout << "INTERNAL: " << a << std::endl; }

/* Related to files >classes, dir, packages not found */
extern char *errorList1 [];

#define log( a ) std::cout << a << std::endl;
#define BASE_CLASS "Object"

class Context;
class AObject;
class TokenInfo;
class AExpression;
class AInstruction;
class Package;

extern const char *currentFile;
extern const char *outputFile;
extern std::string LINE_BREAK;
extern std::string SPACE;
extern bool DEBUGGING;

typedef std::vector<std::string> StringVector;
typedef std::deque<std::string> StringDeque;
typedef std::vector<AExpression *> AExpressionVector;
typedef std::deque<AExpression *> AExpressionDeque;
typedef std::vector<AInstruction *> AInstructionVector;
typedef std::vector<AObject *> AObjectVector;
typedef std::deque<AObject *> AObjectDeque;

typedef std::map<std::string, AObject *> AObjectMap;
typedef std::map<std::string, Package *> PackageMap;

extern StringVector srcPaths;

class ATypage
{
	public:
		std::string type;
		std::string arrayType;
	
		int line;
		std::string filename;
		
		// ATypage();
		ATypage( TokenInfo *token, bool isArray );
		ATypage( std::string &name, bool isArray );
};


class AExpression
{
	protected:
		AExpression *a;
		AExpression *b;
		const std::string &correctName( Context *ctx );
		
	public:
		TokenInfo *token;
		AExpression( TokenInfo *token );
		virtual const std::string &codeGen( Context *ctx );
};

class AInstruction
{
	protected:
		std::string _xname;
		
	public:
		AExpression *value;
		virtual void setXName( AObject *target );
		virtual const std::string &xname();
		AObject *from;
		
		bool external;
		AInstruction( AExpression *value );
		virtual const std::string &codeGen( Context *ctx );
};

// AObject //
class AObject : public AInstruction
{
	protected:
		std::string names;
		
	public:
		bool overwrite;
		AObjectMap *objects;
		ATypage *typage;
	
		virtual const std::string &newname( const std::string &rname );
		std::string rname;
		bool isSetter;
		bool isStatic;
		bool isConst;
		int access;
		
		AObject();
		virtual const std::string &codeGen( Context *ctx );
		virtual AObject *objectByName( const std::string &name );
		virtual bool objectByNameExists( const std::string &name );
		bool isArray();
};


class Context
{
	public:
		AObject *cthis;
		AObject *cpath;
		AObject *ctarget;
		bool cpathClass;
		bool isSuper;
	
		bool ignoreStatic;
		std::string tabs;
	
		Context();
};

class TokenInfo
{
	private:
		int _type;
	
	public:
		std::string value;
	
		std::string filename;
		unsigned int line;
		
		TokenInfo( int type, unsigned int line, const std::string &value, const std::string &file );
		virtual const std::string &print();
	
		int type();
		void setType( int value );
};


#endif
