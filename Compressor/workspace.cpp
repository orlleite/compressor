/*
 workspace.cpp
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

#include <sstream>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <stdio.h>

#include "types.hpp"
#include "preprocessor.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "blocks.hpp"
#include "workspace.hpp"
#include "parser.hpp"

std::string DEFAULT_PACKAGE = "nano.lang";
// extern int newfile( const char* );
extern PreProcessor *pp;
extern int yyparse();

#define iteration_log( interator_type, target, printing ) \
do{\
	std::cout << "{" << std::endl;\
	interator_type it = target.begin();\
	while( it != target.end() )\
	{\
		std::cout << "	" << printing << std::endl;\
		it++;\
	}\
	std::cout << "}" << std::endl;\
}while(0);

StringDeque *stringSplit( const std::string &str, char splitter )
{
	std::stringstream oss(str);
	std::string word;
	
	StringDeque *result = new StringDeque();
	
	while( getline( oss, word, splitter ) )
	{
		result->push_back( word );
	}
	
	return result;
};

std::string &stringJoin( StringDeque *list, const std::string &glue )
{
	std::string result;
	
	StringDeque::const_iterator it;
	bool first = true;
	
	for( it = list->begin(); it != list->end(); it++ )
	{
		if( !first ) result += glue;
		result += *it;
		
		first = false;
	}
	
	return result;
};


// NanoFile //
NanoFile::NanoFile()
{
	imports = new StringVector();
};


// FileBlock //
FileBlock::FileBlock()
{
	list = new AObjectVector();
};

void FileBlock::appendObject( AObject *obj )
{
	list->push_back( obj );
};

const std::string &FileBlock::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "CodeGen FileBlock" );
#endif

	std::string *temp = new std::string();
	
	AObjectVector::const_iterator it;
	bool first = true;
	bool lcase = false;
	bool rbrace = false;
	unsigned int lastSize = 0;
	
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
		
		/*if( typeid(**it) == typeid(AInstCase) | typeid(**it) == typeid(AInstDefault) ) lcase = true;
		else lcase = false;*/
		
		first = false;
		
		ctx->cpath = NULL;
	}
	
	return *temp;
};


// PackageManager //
StringDeque *PackageManager::dirs = new StringDeque();
PackageMap *PackageManager::map = NULL;
NanoFile *PackageManager::cfile = NULL;
AObjectMap *PackageManager::objects = new AObjectMap();
AObjectMap *PackageManager::extvars = new AObjectMap();
std::string PackageManager::names = "a";
std::string PackageManager::internames = "a";
AExpressionDeque *PackageManager::toImport = new AExpressionDeque();
StringDeque *PackageManager::imported = new StringDeque();
StringDeque *PackageManager::allImports = new StringDeque();
FileBlockDeque *PackageManager::toCodeGen = new FileBlockDeque();
bool PackageManager::searchingClass = false;
bool PackageManager::loadingBaseFile = false;
int PackageManager::currentLine = 0;
std::string PackageManager::currentFile = "";
AExpression *PackageManager::currentPathObj = NULL;
AExpressionDeque::iterator PackageManager::expit;
int PackageManager::searchingObjectFromLine = 0;
std::string PackageManager::searchingObjectFromFile = "";
std::string PackageManager::searchingClassName = "";

PackageManager::PackageManager()
{
	
};

AInstPack *PackageManager::setCurrentPath( AExpression *pathObj )
{
	const std::string path = pathObj ? pathObj->codeGen( NULL ) : "";
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "SetCurrentPath: " << path );
#endif
	
	if( !dirs->size() && !loadingBaseFile )
	{
		// std::string file(currentFile);
		
		StringDeque *list = stringSplit( currentFile, '/' );
		if( list->size() ) list->pop_back();
		
		std::string res = stringJoin( list, "/" );
		delete list;
		
		res += "/";
		
		list = stringSplit( path, '.' );
		// AExpGetPath *temp = path;
		while( list && list->size() )
		{
			res += "../";
			list->pop_back();
		}
		delete list;
		// log( res );
		/*
		 Verify, here, if there is the correct package path
		 */
		
		// log( res << std::endl;
		// log( res );
		dirs->push_back( res );
	}
	
	if( !map ) map = new PackageMap();
	
	// const std::string spath = path->codeGen( NULL );
	PackageMap::iterator inter = map->find( path );
	NanoFile *nfile = new NanoFile();
	nfile->path = path;
	// nfile->importerFile = cfile;
	cfile = nfile;
	
	// log( "package " << spath << "\n";
	
	// log( "cfile->path: " << nfile->path << "\n";
	/*
	if( inter == map->end() )
	{
		(*map)[spath] = new Package();
		inter = map->find( spath );
	}
	
	current = inter->second;
	*/
	// log( map[path->codeGen( NULL )];
	return new AInstPack( pathObj );
};

AInstPack *PackageManager::endOfFile()
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "EndOfFile: " << cfile->path );
#endif
	
	NanoFile *parsedFile = cfile;
	cfile = NULL;
	// cfile = cfile->importerFile;
	// delete parsedFile;
	
	return new AInstPack();
	
	// log( "back to: " << cfile->path << " -> " << cfile->imports->size() << "\n";
};

int PackageManager::processNextFile()
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "ProcessNextFile" );
#endif
	
	std::string filepath = *(dirs->begin());
	
	AExpression *pathObj = *toImport->begin();
	currentPathObj = pathObj;
	
	const std::string spath = pathObj->codeGen( NULL );
	// log( "processfile " << spath );
	toImport->pop_front();
	imported->push_back( spath );
	expit = toImport->begin();
	
	StringDeque *temp = stringSplit( spath, '.' );
	std::string nfile = stringJoin( temp, "/" );
	filepath += nfile + ".nn";
	delete temp;
	
	bool found = false;
	/*if( spath == "nano.display.EventDispatcher" )
	{
		log("got");
	}*/
	if( pp->processFile( filepath ) )
	{
		found = true;
		// newfile( filepath.c_str() );
	}
	else if( srcPaths.size() > 0 )
	{
		StringVector::const_iterator it;
		for( it = srcPaths.begin(); it != srcPaths.end(); it++ )
		{
			filepath = *it;
			filepath += nfile + ".nn";
			
			std::ifstream ifile(filepath.c_str());
			
			if( ifile )
			{
				pp->processFile( filepath );
				found = true;
				break;
			}
		}
	}
	
	if( !found )
	{
		if( searchingClass )
		{
			//log( "not found" );
			return 0;
		}
		else
			ERROR_LOG( errorList1[10], currentLine, currentFile.c_str(), spath.c_str() );
	}
	
	return yyparse();
};

void PackageManager::startWithPath( const std::string &base, const std::string &path, StringVector defines )
{
	// const std::string path = pathObj->codeGen( NULL );
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "StartWithPath" );
#endif
	
	// init preprocessor and get temp folder //
	expit = toImport->begin();
	StringDeque *strList = stringSplit( path, '/' );
	strList->erase( strList->end() - 1 );
	pp = new PreProcessor( stringJoin( strList, "/" ) + "/__temp__" );
	
	for( StringVector::iterator it = defines.begin(); it != defines.end(); it++ )
	{
		std::string name = *it;
		std::string value = "";
		pp->addDef( name, value );
	}
	
	// Load language base file //
	expit = toImport->begin();
	currentFile = base;
	loadingBaseFile = true;
	if( !pp->processFile( base ) )
	{
		ERROR_LOG( errorList1[1], base.c_str() );
	}
	yyparse();
	// exit(0);
	
	// Load the first file //
	expit = toImport->begin();
	loadingBaseFile = false;
	if( !pp->processFile( path ) )
	{
		ERROR_LOG( errorList1[2], path.c_str() );
	}
	currentFile = path;
	yyparse();
	
	while( toImport->size() > 0 )
	{
		int t = PackageManager::processNextFile();
	}
	
	
	
	saveToFile( mainCodeGen( toCodeGen ) );
	
	pp->deleteTempFolder();
};

AInstPack *PackageManager::addImportPath( AExpression *pathObj )
{
	const std::string path = pathObj->codeGen( NULL );
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "AddImportPath: " << path );
#endif
	
	cfile->imports->push_back( path );
	
	// const std::string spath = path->codeGen( NULL );
	StringDeque::iterator inter = std::find( allImports->begin(), allImports->end(), path );
	
	if( inter == allImports->end() )
	{
		toImport->insert( toImport->begin(), pathObj );
		allImports->push_back( path );
		
		/*
		std::string filepath = *(dirs->begin());
		
		StringDeque *temp = stringSplit( spath, '.' );
		std::string nfile = stringJoin( temp, "/" );
		filepath += nfile + ".nn";
		delete temp;
		
		std::ifstream ifile(filepath.c_str());
		if( ifile )
		{
			pp->processFile( filepath );
			// newfile( filepath.c_str() );
		}
		else if( srcPaths.size() > 0 )
		{
			StringDeque::const_iterator it;
			
			for( it = srcPaths.begin(); it != srcPaths.end(); it++ )
			{
				filepath = *it;
				filepath += nfile + ".nn";
				
				std::ifstream ifile(filepath.c_str());
				
				if( ifile )
				{
					log( filepath );
					pp->processFile( filepath );
					// newfile( filepath.c_str() );
					break;
				}
			}
		}
		*/
	}
	
	return new AInstPack( pathObj, true );
	// log( filepath.c_str() );
};

const std::string &PackageManager::appendClass( AInstDeclareClass *obj )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "AppendClass: " << obj->rname );
#endif
	
	std::string fullname = cfile->path + "." + obj->rname;
	if( searchingClass && fullname != PackageManager::searchingClassName )
	{
		return obj->rname;
	}
	else
	{
		obj->cfile = cfile;
		std::string name = cfile->path + "." + obj->name();
		obj->package = cfile->path;
		// log( "append: " << name );
		(*objects)[name] = obj;
		
		// current->appendClass( obj );
		
		if( DEBUGGING )
			return obj->rname;
		else
			return PackageManager::newname();
	}
};

void PackageManager::appendExternalVar( AInstExternalVar *obj )
{
	if( !searchingClass )
	{
		std::string name = obj->name();
		(*extvars)[name] = obj;
	}
};

const std::string &PackageManager::newname()
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "NewName" );
#endif
	
	std::string *temp = new std::string( names );
	
	int length = names.size();
	int pos = length - 1;
	if( length == 1 )
	{
		if( names[pos] == 'z' )
			names[pos] = 'A';
		else if( names[pos] == 'Z' )
			names = "aa";
		else
			names[pos] += 1;
	}
	else
	{
		if( names[pos] == 'z' )
			names[pos] = 'A';
		else if( names[pos] == 'Z' )
			names[pos] = '0';
		else if( names[pos] == '9' )
			names += "a";
		else
			names[pos] += 1;
	}
	
	return *temp;
}

const std::string &PackageManager::interfaceNewName()
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "InterfaceNewName" );
#endif
	
	std::string *temp = new std::string( "__" + internames );
	
	int length = internames.size();
	int pos = length - 1;
	if( length == 1 )
	{
		if( internames[pos] == 'z' )
			internames[pos] = 'A';
		else if( internames[pos] == 'Z' )
			internames = "aa";
		else
			internames[pos] += 1;
	}
	else
	{
		if( internames[pos] == 'z' )
			internames[pos] = 'A';
		else if( internames[pos] == 'Z' )
			internames[pos] = '0';
		else if( internames[pos] == '9' )
			internames += "a";
		else
			internames[pos] += 1;
	}
	
	return *temp;

}
/*
AObject *PackageManager::getObject( std::string &name, std::string &package )
{
	
}
*/
AObject *PackageManager::getObject( std::string &name )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "getObject: " << name );
#endif
	
	if( name == "document" )
		log("getObject" << name );
	
	const std::string path = cfile->path + "." + name;
	AObjectMap::iterator inter = objects->find( path );
	/// PROCURAR POR 'document'.
	/// Você acha que o getExternalGlobalVar deveria ser chamado aqui ///
	
	if( inter == objects->end() )
	{
		// log( cfile->imports->size() );
		if( cfile->imports->size() > 0 )
		{
			StringVector::const_iterator it;
			for( it = cfile->imports->begin(); it != cfile->imports->end(); it++ )
			{
				std::string temp = *it;
				// log( temp );
				// log( temp << " -> " << name );
				
				// check if temp size is equal or longer then name
				if( temp.size() > name.size() )
				{
					std::string tname = "." + name;
					// get the last part of the import and check if is same as name
					std::string endname = temp.substr( temp.size() - tname.size(), tname.size() );
					if( tname == endname )
					{
						// if we get here, of course the path is inside of objects, but 
						// for defensive programming, we check if it's really inside.
						
						AObjectMap::iterator inter = objects->find( temp );
						// log( "getObj: " << temp << " - " << (inter == objects->end()) );
						if( inter == objects->end() )
						{
							return PackageManager::searchObjectInPackage( name );
						}
						else
							return inter->second;
					}
				}
				else if( temp.size() == name.size() && name == temp )
				{
					// log( temp << " -- " << name );
					// if we get here, of course the path is inside of objects, but
					// for "non-knowing" reasons, we check if it's really inside.
					AObjectMap::iterator inter = objects->find( temp );
					if( inter == objects->end() )
					{
						return PackageManager::searchObjectInPackage( name );
					}
					else
						return inter->second;
				}
			}
			
			return PackageManager::searchObjectInPackage( name );
		}
		else
		{
			// Package verify
			return PackageManager::searchObjectInPackage( name );
		}
			
	}
	else
		return inter->second;
};

AObject *PackageManager::getExternalVar( std::string &name )
{
	// const std::string path = cfile->path + "." + name;
	AObjectMap::iterator inter = extvars->find( name );
	
	if( inter != extvars->end() )
		return inter->second;
	else
		return NULL;
}

void PackageManager::appendBlockToCodeGen( FileBlock *block )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "AppendBlockToCodeGen" );
#endif
	
	toCodeGen->push_back( block );
}

AObject *PackageManager::searchObjectInPackage( std::string &name )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_PACKAGE )
	INTERNAL_LOG( "SearchObjectInPackage: " << name );
#endif
	
	searchingClass = true;
	//	log( name );
	std::string path = cfile->path + "." + name;
	PackageManager::searchingClassName = path;
	// log( path );
	
	// log( "firsttry: " << path );
	AObjectMap::iterator inter = objects->find( path );
	// log( "inter == end" << ( inter == objects->end() ) );
	NanoFile *current = cfile;
	// log( "new test path -> " << path << " -> " << ( std::find( allImports->begin(), allImports->end(), path ) == allImports->end() ) );
	if( inter == objects->end() && ( std::find( allImports->begin(), allImports->end(), path ) == allImports->end() ) )
	{
		AExpression *pathObj = new AExpression( new TokenInfo( TNAME, currentLine, path, cfile->path ) );
		PackageManager::addImportPath( pathObj );
		// log( "search: " << pathObj->codeGen(NULL) );
		int result = PackageManager::processNextFile();
	}
	
	cfile = current;
	searchingClass = false;
	
	inter = objects->find( path );
	if( inter == objects->end() )
	{
		AObjectMap::iterator it;
		// log( "objects.size: " << objects->size() );
		
		AObjectMap::iterator inter = objects->find( DEFAULT_PACKAGE + "." + name );
		if( inter != objects->end() )
		{
			return inter->second;
		}
		else
		{
			iteration_log( AObjectMap::iterator, (*objects), it->first );
			
			// Objeto não encontrado, ERRO!
			ERROR_LOG( errorList1[25], PackageManager::searchingObjectFromLine, PackageManager::searchingObjectFromFile.c_str(), name.c_str() );
			return NULL;
		}
	}
	else
		return inter->second;
}

// Package //
/*Package::Package() : AObject::AObject()
{
	this->map = new AObjectMap();
};

void Package::appendClass( AInstDeclareClass *obj )
{
	std::string name = obj->name();
	(*this->map)[name] = obj;
};*/

// AInstDeclareClass //
AInstDeclareClass::AInstDeclareClass( AExpression *name, ATypage *extends, AExpressionVector *implements, AObjectVector *block )
	: AObject::AObject()
{
	this->cfile = NULL;
	this->inited = false;
	this->extends = extends;
	this->implements = implements;
	this->extendsClass = NULL;
	
	this->block = block;
	this->value = name;
	this->rname = name->codeGen( NULL );
	this->getters = new AObjectMap();
	this->setters = new AObjectMap();
	
	this->_xname = PackageManager::appendClass( this );
};

void AInstDeclareClass::startClass()
{
	inited = true;
	// log( "startClass: " << rname );
	
	// log( this->cfile->imports );
	NanoFile *oldFile = PackageManager::cfile;
	PackageManager::cfile = this->cfile;
	
	std::string oname = extends ? extends->type : std::string(BASE_CLASS);
	AInstDeclareClass *parent;
	if( oname == rname )
	{
		parent = NULL;
	}
	else
	{
		PackageManager::searchingObjectFromLine = this->value->token->line;
		PackageManager::searchingObjectFromFile = this->value->token->filename;
		parent = (AInstDeclareClass *) PackageManager::getObject( oname );
	}
	this->extendsClass = parent;
	if( parent )
	{
		AObject::names = parent->names();
	}
	
	if( implements )
	{
		this->implementsClasses = new AObjectVector();
		
		AExpressionVector::const_iterator it;
		AObject *temp;
		
		for( it = implements->begin(); it != implements->end(); it++ )
		{
			std::string iname = (*it)->codeGen(NULL);
			
			PackageManager::searchingObjectFromLine = (*it)->token->line;
			PackageManager::searchingObjectFromFile = (*it)->token->filename;
			temp = (AInstDeclareClass *) PackageManager::getObject( iname );
			this->implementsClasses->push_back( temp );
		}
	}
	
	AObjectVector::const_iterator it;
	AObject *temp;
	if( this->block )
	{
		AObjectVector *sets = new AObjectVector();
		for( it = this->block->begin(); it != this->block->end(); it++ )
		{
			temp = (AObject *)(*it);
			
			temp->from = this;
			if( typeid(*temp) == typeid(AInstDeclareSet) )
				sets->push_back( temp );
			else
				temp->setXName( this );
		}
		
		for( it = sets->begin(); it != sets->end(); it++ )
		{
			temp = (AObject *)(*it);
			
			temp->from = this;
			temp->setXName( this );
			log( temp->rname );
		}
	}
	
	PackageManager::cfile = oldFile;
};

const std::string &AInstDeclareClass::name()
{
	std::string *xname = new std::string( this->value->codeGen( NULL ) );
	
	return *xname;
}

std::string &AInstDeclareClass::names()
{
	return AObject::names;
}

bool AInstDeclareClass::objectByNameExists( const std::string &name )
{
	if( !inited ) startClass();
	
	return AObject::objectByNameExists( name );
}

AObject *AInstDeclareClass::objectByName( const std::string &name )
{
	if( !inited ) startClass();
	
	AObject *temp = AObject::objectByName( name );
	
	if( temp )
		return temp;
	else if( extendsClass )
		return extendsClass->objectByName( name );
	
	// else all possibilities //
	return NULL;
}

AObject *AInstDeclareClass::getterByName( const std::string &name )
{
	if( !inited ) startClass();
	
	AObjectMap::iterator p; 
	p = getters->find( name );
	
	// log( name + "\n";
	
	if( p != getters->end() )
		return p->second;
	else if( extendsClass )
	{
		return extendsClass->getterByName( name );
	}
	
	return NULL;
}

AObject *AInstDeclareClass::setterByName( const std::string &name )
{
	if( !inited ) startClass();
	
	AObjectMap::iterator p; 
	p = setters->find( name );
	
	// log( name + "\n";
	
	if( p != setters->end() )
		return p->second;
	else if( extendsClass )
	{
		return extendsClass->setterByName( name );
	}
		
	return NULL;
}

const std::string &AInstDeclareClass::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "CodeGen AInstDeclareClass" );
#endif
	
	if( !inited ) startClass();
	
	Context *cctx = new Context();
	cctx->cthis = this;
	
	Context *scctx = new Context();
	scctx->cthis = this; // cctx for static members
	
	//std::string name = this->value->codeGen(ctx);
	
	std::string *temp = new std::string( ctx->tabs + "$." + this->xname() + SPACE + "=" + SPACE );
	if( this->constructor )
		*temp += this->constructor->codeGen( cctx ) + ";";
	else
		*temp += "function(){};";
	
	if( this->extendsClass && extendsClass->xname() != "Object" )
	{
		// AObject *obj = PackageManager::getObject( this->extends->codeGen( NULL ) );
		*temp += LINE_BREAK + "$." + this->rname + ".prototype" + SPACE + "=" + SPACE + "$._($." + extendsClass->xname() + ".prototype);";
	}
	else
	{
		// *temp += LINE_BREAK + this->rname + ".prototype" + SPACE + "=" + SPACE + "new Object();";
	}
	
	*temp += LINE_BREAK + "$." + this->rname + "._" + SPACE + "=" + SPACE + "$." + this->rname + ".prototype;";
	
	if( DEBUGGING ) cctx->tabs += "";
	// if( extends ) *temp += "var __={};__._=this._;";
	std::string *statics = new std::string("");
	
	*temp += LINE_BREAK;
	
	AObjectVector::const_iterator it;
	bool first = true;
	bool sfirst = true; // statics //
	
	for( it = this->block->begin(); it != this->block->end(); it++ )
	{
		if( *it != this->constructor )
		{
			if( (*it)->isStatic )
			{
				if( !sfirst ) *statics += ";" + LINE_BREAK;
				*statics += ctx->tabs + "$." + this->xname() + "." + (**it).codeGen( scctx );
				
				sfirst = false;
			}
			else
			{
				if( !first ) *temp += ";" + LINE_BREAK;
				// log( "get here" << std::endl;
				// if( (**it).overwrite ) *temp += "__." + (**it).xname() + "=this." + (**it).xname() + ";";
				
				
				*temp += cctx->tabs + "$." + this->rname + "._." + (**it).codeGen( cctx );
				
				first = false;
			}
		}
	}
	
	if( this->implementsClasses )
	{
		for( it = this->implementsClasses->begin(); it != this->implementsClasses->end(); it++ )
		{
			*temp += (*it)->codeGen( cctx );
		}
	}
	
	// *temp += LINE_BREAK + "}";
	
	if( statics->size() > 0 ) *temp += ";" + LINE_BREAK + *statics;
	
	return *temp;
};

AInstExternalClass::AInstExternalClass( AExpression *name, ATypage *extends, AExpressionVector *implements, AObjectVector *block, AExpression *id )
	: AInstDeclareClass::AInstDeclareClass( name, extends, implements, block )
{
	this->id = id;
	this->external = true;
}

const std::string &AInstExternalClass::xname()
{
	return this->id->codeGen(NULL);
}

const std::string &AInstExternalClass::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "CodeGen AInstExternalClass" );
#endif
	
	return "";
}

AInstDeclareInterface::AInstDeclareInterface( AExpression *name, AObjectVector *block )
	: AInstDeclareClass::AInstDeclareClass( name, NULL, NULL, block )
{
	
}

const std::string &AInstDeclareInterface::xname()
{
	return "";
}

const std::string &AInstDeclareInterface::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "CodeGen AInstDeclareInterface" );
#endif
	
	std::string *temp = new std::string( "" );
	
	AObjectVector::const_iterator it;
	bool first = true;
	
	std::string name = ctx->cthis->xname();
	
	for( it = this->block->begin(); it != this->block->end(); it++ )
	{
		if( !first ) *temp += ";" + LINE_BREAK;
		
		*temp += ctx->tabs + name + "._." + (**it).codeGen( ctx );
		
		first = false;
	}
	
	return *temp;
}

AInstExternalVar::AInstExternalVar( AExpression *name, ATypage *typage, AExpression *id )
	: AInstDeclareClass::AInstDeclareClass( name, NULL, NULL, NULL )
{
	//log( "created externalvar" );
	this->id = id;
	this->external = true;
	
	PackageManager::appendExternalVar( this );
}

const std::string &AInstExternalVar::xname()
{
	return this->id->codeGen(NULL);
}

const std::string &AInstExternalVar::codeGen( Context *ctx )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "CodeGen AInstExternalVar" );
#endif
	
	return "";
}


const std::string &mainCodeGen( FileBlockDeque *block )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "MainCodeGen" );
#endif
	
	std::string *temp = new std::string( "/*\
 * Created with Compressor\
 * http://github.com/orlleite/compressor\
 */\
\
" );
	
	*temp += "$" + SPACE + "=" + SPACE + "{" + LINE_BREAK;
	
	std::string tab = "";
	
	if( DEBUGGING ) tab = "	";
	
	// object constructer //
	*temp += tab + "_:Object.create";
	
	// GET AND SET //
	// This is the first model. The next should know 
	// if target support get and set by default, and
	// use it.
	
	// get property //
	*temp += "," +
	LINE_BREAK + tab + "_0:function(" + SPACE + "a," + SPACE + "b" + SPACE + ")" + LINE_BREAK +
	LINE_BREAK + tab + "{" +
	LINE_BREAK + tab + tab + "return typeof a[b]" + SPACE + "==" + SPACE + "\"function\"" + SPACE + "?" + SPACE + "a[b]()" + SPACE + ":" + SPACE + "a[b]" +
	LINE_BREAK + tab + "}";
	
	// set property //
	*temp += "," +
	LINE_BREAK + tab + "_1:function(" + SPACE + "a," + SPACE + "b," + SPACE + "c" + SPACE + ")" +
	LINE_BREAK + tab + "{" +
	LINE_BREAK + tab + tab + "if(" + SPACE + "typeof a[b]" + SPACE + "==" + SPACE + "\"function\"" + SPACE + ")" +
	LINE_BREAK + tab + tab + tab + "a[\"_" +  ( DEBUGGING ? "_set_" : "" ) + "\"+b](" + SPACE + "c" + SPACE + ");" +
	LINE_BREAK + tab + tab + "else a[b]" + SPACE + "=" + SPACE + "c" +
	LINE_BREAK + tab + "}";
	
	// end //
	*temp += LINE_BREAK + "};";
	
	FileBlockDeque::reverse_iterator it;
	for( it = block->rbegin(); it != block->rend(); it++ )
	{
		*temp += (**it).codeGen( new Context() );
	}
	
	// *temp += block->codeGen( new Context() );
	
	return *temp;
}

void saveToFile( const std::string &value )
{
#if defined( INTERNAL_DEBUG ) && defined( DEBUG_CODEGEN_WORKSPACE )
	INTERNAL_LOG( "SaveToFile: " << outputFile );
#endif
	
	std::ofstream compiled;
	compiled.open( outputFile, std::ios::trunc );
	if( compiled.is_open() )
	{
		compiled << value;
		compiled.close();
	}
	else
	{
		log( "Unable to create/open file\n" );
	}
}

