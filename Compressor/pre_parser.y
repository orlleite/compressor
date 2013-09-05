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
	
	void zzerror(const char *s) { printf("PRE_ERROR: %s\n", s); };
%}

/* Represents the many different ways we can access our data */
%union
{
	PLineVector *line_list;
	PLine *line;

	PExpression *expr;
	TokenInfo *tinfo;
	int token;
}

%token <tinfo> TEOF TDEFINE TIFDEF TELSEIFDEF TELSEDEF TENDIFDEF TOR TAND TLPAREN TRPAREN TNOT
%token <tinfo> TDEFNAME TDEFVALUE TLINE

%type <tinfo> comparing
%type <line_list> block
%type <line> line
%type <expr> expression expr2

%%

input:
	| input block { pp->codeGenAndSave( $2 ); }
	;

block:
	{ $$ = new PLineVector(); }
	| block line { $$ = $1; if( $2 ) $1->push_back( $2 ); }
	| line { $$ = new PLineVector(); if( $1 ) $$->push_back( $1 ); }
	;

line:
	  TLINE { $$ = new PLine( $1 ); }
	| TDEFINE TDEFNAME { $$ = new PDefine( $2, NULL ); }
	| TDEFINE TDEFNAME TDEFVALUE { $$ = new PDefine( $2, $3 ); }
	| TIFDEF expression { $$ = new PIfDef( $2 ); }
	| TELSEIFDEF expression { $$ = new PElseIfDef( $2 ); }
	| TELSEDEF { $$ = new PElseDef(); }
	| TENDIFDEF { $$ = new PEndIfDef(); }
	;

expression:
      expr2 { $$ = $1; }
    | expression comparing expression { $$ = new PExpOperation( $1, $2, $3 ); }
    ;

expr2:
      TLPAREN expression TRPAREN { $$ = new PExpParent( $2 ); }
    | TDEFNAME {  $$ = new PExpression( $1 ); }
    | TNOT TDEFNAME {  $$ = new PExpNot( $1 ); }
    ;

comparing:
      TOR | TAND;

aif:
	 TIFDEF block aif

%%
