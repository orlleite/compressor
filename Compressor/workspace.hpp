/*
 workspace.hpp
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

#ifndef Compressor_workspace_h
#define Compressor_workspace_h

#include <iostream>
#include <stdio.h>
#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "blocks.hpp"


class Package;
class RootObject;
class FileBlock;
class AInstDeclareClass;
class AInstExternalVar;

typedef std::deque<FileBlock *> FileBlockDeque;

StringDeque *stringSplit( const std::string &str, char splitter );

std::string &stringJoin( StringDeque *list, const std::string &glue );

class NanoFile
{
	public:
		std::string path;
		StringVector *imports;
		//NanoFile *importerFile;// Who imported me, when the file is ended, we call back this. //
							   // Ok Orlando from the past, now we don't need this anymore, but I'll see if it's really true soon. //
		NanoFile();
};

class FileBlock
{
	public:
		AObjectVector *list;
		const std::string &codeGen( Context *ctx );
		void appendObject( AObject *obj );
		FileBlock();
};

class PackageManager
{
	private:
		static FileBlockDeque *toCodeGen;
		static std::string names;
		static std::string internames;/* interface names */
		static PackageMap *map;
		static NanoFile *cfile;
		static StringDeque *dirs;
		static AObjectMap *objects;
		static AObjectMap *extvars;
		static AExpressionDeque *toImport;
		static StringDeque *imported;
		static StringDeque *allImports;
		static bool searchingClass;
		static bool loadingBaseFile;
		static int processNextFile();
	
	public:
		static int currentLine;
		static std::string currentFile;
		static AExpression *currentPathObj;
		static const std::string &newname();
		static const std::string &interfaceNewName();
	
		static AExpressionDeque::iterator expit;
		/*
		 * Current Object Owner
		 * class, functions, methods.
		 * Used to get newname for vars, func and prop correctly.
		 */
		static AInstPack *endOfFile();

		static void startWithPath( const std::string &base, const std::string &path, StringVector defines );
		static AInstPack *setCurrentPath( AExpression *pathObj ); // imports will be reset //
		static AInstPack *addImportPath( AExpression *pathObj );
		static const std::string &appendClass( AInstDeclareClass *obj );
		static void appendExternalVar( AInstExternalVar *obj );
		static AObject *getObject( std::string &name );
		static AObject  *getExternalVar( std::string &name );
		
		static void appendBlockToCodeGen( FileBlock *block );
		static AObject *searchObjectInPackage( std::string &name );
		
		PackageManager();
};


// Package //
/*class Package : public AObject
{
	private:
		AObjectMap *map;
	
	public:
		void appendClass( AInstDeclareClass *obj );
		Package();
};*/

class AInstDeclareClass : public AObject
{
	protected:
		AObjectVector *implementsClasses;
		AObjectVector *block;
		bool inited;
		virtual void startClass();
		
	public:
		AObject *constructor;
		ATypage *extends;
		AExpressionVector *implements;
		AInstDeclareClass *extendsClass;
		
		AInstDeclareClass( AExpression *name, ATypage *extends, AExpressionVector *implements, AObjectVector *block );
		
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &name();
		
		virtual bool objectByNameExists( const std::string &name );
		virtual AObject *objectByName( const std::string &name );
		AObject *getterByName( const std::string &name );
		AObject *setterByName( const std::string &name );
	
		AObjectMap *getters;
		AObjectMap *setters;
		AInstDeclareClass *getExtends();
	
		std::string &names();
};

class AInstExternalClass : public AInstDeclareClass
{
	protected:
		AExpression *id;
	
	public:
		AInstExternalClass( AExpression *name, ATypage *extends, AExpressionVector *implements, AObjectVector *block, AExpression *id );
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &xname();
};

class AInstDeclareInterface : public AInstDeclareClass
{
	public:
		AInstDeclareInterface( AExpression *name, AObjectVector *block );
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &xname();
};

class AInstExternalVar : public AInstDeclareClass
{
	protected:
		AExpression *id;
	
	public:
		AInstExternalVar( AExpression *name, ATypage *typage, AExpression *id );
		virtual const std::string &codeGen( Context *ctx );
		virtual const std::string &xname();
};


const std::string &mainCodeGen( FileBlockDeque *block );

void saveToFile( const std::string &value );

#endif
