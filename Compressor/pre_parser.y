/*
 pre_parser.y
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
%define api.prefix zz

%{
	#include <iostream>
	#include "preprocessor.hpp"

	extern int zzlex( void );
	
	void zzerror(const char *s) { printf("ERROR: %s\n", s); };
%}

/* Represents the many different ways we can access our data */
%union
{
	ALineVector *line_list;
	ALine *line;

	TokenInfo *tinfo;
	int token;
}

%token <tinfo> TLINE TEOF TDEFINE TDEFNAME TDEFVALUE TIFDEF TELSEIFDEF TELSEDEF TENDIFDEF

%type <line_list> block
%type <line> line

%%

input:
	| input block { pp->codeGenAndSave( $2 ); }
	;

block:
	{ $$ = new ALineVector(); }
	| block line { $$ = $1; if( $2 ) $1->push_back( $2 ); }
	| line { $$ = new ALineVector(); if( $1 ) $$->push_back( $1 ); }
	;

line:
	  TLINE { $$ = new ALine( $1 ); }
	| TDEFINE TDEFNAME TDEFVALUE { $$ = new ADefine( $2, $3 ); }
	| TIFDEF TDEFNAME { $$ = new AIfDef( $2 ); }
	| TELSEIFDEF TDEFNAME { $$ = new AElseIfDef( $2 ); }
	| TELSEDEF { $$ = new AElseDef(); }
	| TENDIFDEF { $$ = new AEndIfDef(); }
	;

aif:
	 TIFDEF block aif

%%
