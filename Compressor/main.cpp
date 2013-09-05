/*
 main.cpp
 Compressor
 
 Created by Orlando Leite on 07/10/11.
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
#include <cstdio>
#include <vector>

#include <tclap/CmdLine.h>

#include "types.hpp"
#include "expressions.hpp"
#include "instructions.hpp"
#include "preprocessor.hpp"
#include "blocks.hpp"
#include "workspace.hpp"
#include "parser.hpp"

extern int yyparse();
extern "C" FILE *yyin;
extern "C" FILE *zzin;
extern void init();

extern PreProcessor *pp;

int main (int argc, char **argv)
{	
	try {
		TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
		
		TCLAP::ValueArg<std::string> inputArg("i","input","The target file to be compiled.", false, "./main.nn","string");
		cmd.add( inputArg );
		
		TCLAP::ValueArg<std::string> outputArg("o","output","The javascript output file to be saved.", false, "./main.js","string");
		cmd.add( outputArg );
		
		TCLAP::MultiArg<std::string> srcsArg("s", "source-path", "Source path. Where compressor will look for classes. It accept multiple paths by adding mutiples '-s'.", false, "string");
		cmd.add( srcsArg );
		
		TCLAP::MultiArg<std::string> definesArg("d", "define", "Define a preprocessor constant (p.ex: -d BROWSER_GROUP_0).", false, "string");
		cmd.add( definesArg );
		
		TCLAP::ValueArg<std::string> baseArg("b","base","Language base file, should have at least the 'Object' class.", false, "./base.nn","string");
		cmd.add( baseArg );
		
		TCLAP::SwitchArg debugArg("D","debug","Don't compress names and make a beautiful code to be debugged. It's the same as -n -b simultaneously.", false);
		cmd.add( debugArg );
		
		TCLAP::SwitchArg compressNamesArg("N","keep-names","Don't compress classes, methods, vars and functions names.", false);
		cmd.add( compressNamesArg );
		
		TCLAP::SwitchArg lineBreaksArg("B","line-breaks","Make lines break.", false);
		cmd.add( lineBreaksArg );
		
		// Parse the argv array.
		cmd.parse( argc, argv );
		
		// Get the value parsed by each arg.
		outputFile = outputArg.getValue().c_str();
		srcPaths = srcsArg.getValue();
		DEBUGGING = debugArg.getValue();
		bool cnArg = compressNamesArg.getValue();
		bool lbArg = lineBreaksArg.getValue();
		
		if( DEBUGGING || lbArg )
		{
			LINE_BREAK = "\n";
			SPACE = " ";
		}
		else
		{
			LINE_BREAK = "";
			SPACE = "";
		}
		
		
		
		// init preprocessor and get temp folder //
		/*std::string path = std::string(inputArg.getValue());
		StringList *strList = stringSplit( path, '/' );
		strList->erase( strList->end() - 1 );
		
		pp = new PreProcessor( stringJoin( strList, "/" ) + "/__temp__" );
		pp->processFile( inputArg.getValue() );
		// newfile(  );
		
		int t = yyparse();*/
		
		log( "Input: " << inputArg.getValue() );
		PackageManager::startWithPath( baseArg.getValue(), inputArg.getValue(), definesArg.getValue() );
		log( "Output: " << outputFile );
		log( "Build Successfully." );
		
		return 0;
		// return yyparse();
	}
	catch (TCLAP::ArgException &e)
	{
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}
	
	/*saveTo = argv[2];
	 newfile( argv[1] );
	 
	 return yyparse();*/
	
	
	
	/*
	 // insert code here...
	 printf("Hello, World!\n");
	 return 0;
	 */
}





