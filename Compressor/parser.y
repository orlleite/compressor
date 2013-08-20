/*
 parser.y
 Compressor
 
 Created by Orlando Leite on 10/10/12.
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
%{
	#include <iostream>
	#include "types.hpp"
	#include "expressions.hpp"
	#include "instructions.hpp"
	#include "blocks.hpp"
	#include "workspace.hpp"

	extern int yylex( void );
	
	void yyerror(const char *s) { printf("ERROR: %s\n", s); };
%}

/* Represents the many different ways we can access our data */
%union
{
	AExpressionVector *expr_list;
	AExpGetPath *expr_path;
	AExpression *expr;
	ATypage *exp_type;
	
	AInstructionVector *inst_list;
	AInstruction *inst;
	
	AObjectVector *prop_list;
	AObject *prop;
	
	FileBlock *file_block;
	
	TokenInfo *tinfo;
	int token;
}

%token TEOF 0 "end of file"
%token <tinfo> TEQ TNE TLT TLE TGT TGE TPLUS TMINUS TMULT TDIVIDE TMODULUS TINCREMENT TDECREMENT TNOT TEQA TNEA
%token <tinfo> TRPAREN TLPAREN TRBRACKET TLBRACKET TRBRACE TLBRACE TIMPLEMENTS
%token <tinfo> TASSIGN TASSIGN_PLUS TASSIGN_MINUS TASSIGN_MULTIPLY TASSIGN_DIVIDE TASSIGN_BOR
%token <tinfo> TSEMICOLON TCOMMA TDOT TCOLON TQUESTION TCONST TIMPORT TPACKAGE
%token <tinfo> TOR TAND TBXOR TLSHIFT TRSHIFT TZFILL TBOR TBAND TBNOT TGET TSET TINSTANCEOF
%token <tinfo> TTRUE TFALSE TVAR TCONTINUE TBREAK TCASE TDEFAULT TNULL TRETURN TNEW TSUPER TTHIS
%token <tinfo> TNUMBER TSTRING TNAME TCOMPVAR TPUBLIC TPRIVATE TPROTECTED TSTATIC TDELETE
%token <tinfo> TIF TELSE TWHILE TTRY TCATCH TDO TFOR TIN TSWITCH TFUNCTION TCLASS TEXTENDS
%token <tinfo> TCOMPNAME TCOMPGET TCOMPSET TREGEX TEXTERNAL TCUSTOMIZE TEXPORT

%type <expr> expression expr2 identifier
%type <exp_type> typage extends
%type <expr_path> get_path get_obj set_path set_obj package_path
%type <expr_list> call_args object_props implements

%type <inst> instruction for_args switch_inst declare_arg forin_var 
%type <inst_list> block switch_block declare_args 

%type <prop_list> external_class_block class_block props_declaration vars_declaration
%type <prop> property proper2 external_property external_proper2 object
%type <file_block> file_block

%type <tinfo> assigning comparing access

%left TEQ TNE TLT TLE TGT TGE
%left TOR TAND TBXOR TLSHIFT TRSHIFT TZFILL TBOR TBAND
%left TPLUS TMINUS
%left TDIVIDE TMULT TMODULUS

%%

input:
	| input file_block TEOF { $2->appendObject( PackageManager::endOfFile() ); PackageManager::appendBlockToCodeGen( $2 ); }
	;
	
file_block:
	  { $$ = new FileBlock(); }
	| file_block object { $$ = $1; if( $2 ) $1->appendObject( $2 ); }
	| file_block TSEMICOLON { $$ = $1; }
	| object { $$ = new FileBlock(); if( $1 ) $$->appendObject( $1 ); }
	  ;
	  
object:
	  TPACKAGE package_path { $$ = PackageManager::setCurrentPath( $2 ); }
	| TPACKAGE { $$ = PackageManager::setCurrentPath( NULL ); }
	| TIMPORT package_path { $$ = PackageManager::addImportPath( $2 ); }
	| TCLASS identifier extends implements TLBRACE class_block TRBRACE { $$ = new AInstDeclareClass( $2, $3, $4, $6 ); }
	| TEXTERNAL TCLASS identifier extends implements TLBRACE external_class_block TRBRACE TASSIGN identifier { $$ = new AInstExternalClass( $3, $4, $5, $7, $10 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TLBRACE block TRBRACE { $$ = new AInstDeclareFunc( $2, $7, $4, $9 ); }
	  ;

block:
	  { $$ = new AInstructionVector(); }
	| block instruction { $$ = $1; if( $2 ) $1->push_back( $2 ); }
	| block TSEMICOLON { $$ = $1; }
	| instruction { $$ = new AInstructionVector(); if( $1 ) $$->push_back( $1 ); }
	  ;

class_block:
	  { $$ = new AObjectVector(); }
	| property { $$ = new AObjectVector(); $$->push_back( $1 ); }
	| class_block property { $$ = $1; $1->push_back( $2 ); }
	| class_block TSEMICOLON { $$ = $1; }
	;

external_class_block:
	  { $$ = new AObjectVector(); }
	| external_property { $$ = new AObjectVector(); $$->push_back( $1 ); }
	| external_class_block external_property { $$ = $1; $1->push_back( $2 ); }
	| external_class_block TSEMICOLON { $$ = $1; }
	;

extends:
	  { $$ = NULL; }
	| TEXTENDS typage { $$ = $2; }
	;

implements:
	  { $$ = NULL; }
	| TIMPLEMENTS identifier { $$ = new AExpressionVector(); $$->push_back( $2 ); }
	| implements TCOMMA identifier { $$ = $1; $1->push_back( $3 ); }
	;

external_property:
	  access external_proper2 { $$ = $2; $2->access = $1->type(); }
	| access TSTATIC external_proper2 { $$ = $3; $3->isStatic = true; $3->access = $1->type(); }
	| access TCONST external_proper2 { $$ = $3; $3->isConst = true; $3->access = $1->type(); }
	;

external_proper2:
	  TVAR identifier TCOLON typage TASSIGN identifier { $$ = new AInstExternalProp( $2, $4, $6 ); }
	| TCONST identifier TCOLON typage TASSIGN identifier { $$ = new AInstExternalProp( $2, $4, $6 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TASSIGN identifier { $$ = new AInstExternalMethod( $2, $7, $4, $9 ); }
	| TGET TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TASSIGN identifier { $$ = new AInstExternalGet( $3, $8, $5, $10, false ); }
	| TGET TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TASSIGN TVAR identifier { $$ = new AInstExternalGet( $3, $8, $5, $11, true ); }
	| TSET TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TASSIGN identifier { $$ = new AInstExternalSet( $3, $8, $5, $10 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN { $$ = new AInstExternalMethod( $2, NULL, $4, $2 ); }
	;

property:
	  access proper2 { $$ = $2; $2->access = $1->type(); }
	| access TSTATIC proper2 { $$ = $3; $3->isStatic = true; $3->access = $1->type(); }
	;

proper2:
	  TVAR identifier TCOLON typage { $$ = new AInstDeclareProp( $2, $4, NULL ); }
	| TVAR identifier TCOLON typage TASSIGN expression { $$ = new AInstDeclareProp( $2, $4, $6 ); }
	| TCONST identifier TCOLON typage TASSIGN expression { $$ = new AInstDeclareProp( $2, $4, $6 ); }
	| TVAR props_declaration {  $$ = new AInstDeclareMultProp( $2 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TLBRACE block TRBRACE { $$ = new AInstDeclareMethod( $2, $7, $4, $9 ); }
	| TGET TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TLBRACE block TRBRACE { $$ = new AInstDeclareGet( $3, $8, $5, $10 ); }
	| TSET TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TLBRACE block TRBRACE { $$ = new AInstDeclareSet( $3, $8, $5, $10 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN TLBRACE block TRBRACE { $$ = new AInstDeclareMethod( $2, NULL, $4, $7 ); }
	;

access:
	TPRIVATE | TPUBLIC | TPROTECTED
	;

props_declaration:
	  identifier TCOLON typage	 { $$ = new AObjectVector(); $$->push_back( new AInstDeclareProp( $1, $3, NULL ) ); }
	| identifier TCOLON typage TASSIGN expression { $$ = new AObjectVector(); $$->push_back( new AInstDeclareProp( $1, $3, $5 ) ); }
	| props_declaration TCOMMA identifier TCOLON typage	 { $$ = $1; $$->push_back( new AInstDeclareProp( $3, $5, NULL ) ); }
	| props_declaration TCOMMA identifier TCOLON typage TASSIGN expression { $$ = $1; $$->push_back( new AInstDeclareProp( $3, $5, $7 ) ); }
	;


instruction:
	  expression { $$ = new AInstruction( $1 ); }
	| TFUNCTION identifier TLPAREN declare_args TRPAREN TCOLON typage TLBRACE block TRBRACE { $$ = new AInstDeclareFunc( $2, $7, $4, $9 ); }
	| TELSE TIF TLPAREN expression TRPAREN instruction { $$ = new AInstElseif( $4, $6 ); }
	| TELSE TIF TLPAREN expression TRPAREN TLBRACE block TRBRACE { $$ = new AInstElseif( $4, $7 ); }
	| TELSE instruction { $$ = new AInstElse( $2 ); }
	| TELSE TLBRACE block TRBRACE { $$ = new AInstElse( $3 ); }
	| TIF TLPAREN expression TRPAREN instruction { $$ = new AInstIf( $3, $5 ); }
	| TIF TLPAREN expression TRPAREN TLBRACE block TRBRACE { $$ = new AInstIf( $3, $6 ); }
	| TFOR TLPAREN for_args TSEMICOLON for_args TSEMICOLON for_args TRPAREN instruction { $$ = new AInstFor( $3, $5, $7, $9 ); }
	| TFOR TLPAREN for_args TSEMICOLON for_args TSEMICOLON for_args TRPAREN TLBRACE block TRBRACE { $$ = new AInstFor( $3, $5, $7, $10 ); }
	| TFOR TLPAREN forin_var TIN expression TRPAREN instruction { $$ = new AInstFor( $3, $5, $7 ); }
	| TFOR TLPAREN forin_var TIN expression TRPAREN TLBRACE block TRBRACE { $$ = new AInstFor( $3, $5, $8 ); }
	| TWHILE TLPAREN expression TRPAREN instruction { $$ = new AInstWhile( $3, $5 ); }
	| TWHILE TLPAREN expression TRPAREN TLBRACE block TRBRACE { $$ = new AInstWhile( $3, $6 ); }
	| TDO instruction TSEMICOLON TWHILE TLPAREN expression TRPAREN { $$ = new AInstDo( $6, $2 ); }
	| TDO TLBRACE block TRBRACE TWHILE TLPAREN expression TRPAREN { $$ = new AInstDo( $7, $3 ); }
	| TTRY TLBRACE block TRBRACE TCATCH TLPAREN declare_arg TRPAREN TLBRACE block TRBRACE { $$ = new AInstTryCatch( $3, $7, $10 ); }
	| TVAR identifier TCOLON typage TASSIGN expression { $$ = new AInstDeclareVar( $2, $4, $6 ); }
	| TVAR identifier TCOLON typage { $$ = new AInstDeclareVar( $2, $4, NULL ); }
	| TVAR vars_declaration { $$ = new AInstDeclareMultVar( $2 ); }
	| TDELETE get_path { $$ = new AInstDelete( $2 ); }
	| TSWITCH TLPAREN expression TRPAREN TLBRACE switch_block TRBRACE { $$ = new AInstSwitch( $3, $6 ); }
	| TBREAK { $$ = new AInstBreak(); }
	| TCONTINUE { $$ = new AInstContinue(); }
	| TRETURN { $$ = new AInstReturn( NULL ); }
	| TRETURN expression { $$ = new AInstReturn( $2 ); }
	| set_path assigning expression {  $$ = new AInstAssign( $1, $2, $3 ); }
	| TSUPER TLPAREN call_args TRPAREN { $$ = new AInstSuperCall( $1, $3 ); }
	;

vars_declaration:
	  identifier TCOLON typage TASSIGN expression { $$ = new AObjectVector(); $$->push_back( new AInstDeclareVar( $1, $3, $5 ) ); }
	| identifier TCOLON typage { $$ = new AObjectVector(); $$->push_back( new AInstDeclareVar( $1, $3, NULL ) ); }
	| vars_declaration TCOMMA identifier TCOLON typage TASSIGN expression { $$ = $1; $$->push_back( new AInstDeclareVar( $3, $5, $7 ) ); }
	| vars_declaration TCOMMA identifier TCOLON typage { $$ = $1; $$->push_back( new AInstDeclareVar( $3, $5, NULL ) ); }
	;


switch_block:
	  switch_inst { $$ = new AInstructionVector(); $$->push_back( $1 ); }
	| switch_block TSEMICOLON { $$ = $1; }
	| switch_block switch_inst { $$ = $1; $1->push_back( $2 ); }
	;

switch_inst:
	  instruction { $$ = $1; }
	| TCASE expression TCOLON { $$ = new AInstCase( $2 ); }
	| TDEFAULT TCOLON { $$ = new AInstDefault(); }
	;

declare_args: /*blank*/  { $$ = NULL; }
	| declare_arg { $$ = new AInstructionVector(); $$->push_back( $1 ); }
	| declare_args TCOMMA declare_arg { $$ = $1; $1->push_back( $3 ); }
	;

declare_arg:
	  identifier TCOLON typage { $$ = new AInstDeclareArg( $1, $3, NULL ); }
	| identifier TCOLON typage TASSIGN expression { $$ = new AInstDeclareArg( $1, $3, $5 ); }
	;

forin_var:
	  TVAR identifier TCOLON typage { $$ = new AInstDeclareVar( $2, $4, NULL ); }
	;

for_args:
	  TVAR identifier TCOLON typage TASSIGN expression { $$ = new AInstDeclareVar( $2, $4, $6 ); }
	| expression { $$ = new AInstruction( $1 ); }
	;

assigning: 
	  TASSIGN | TASSIGN_DIVIDE | TASSIGN_MINUS | TASSIGN_MULTIPLY | TASSIGN_PLUS | TASSIGN_BOR
	;

expression:
	  expr2 { $$ = $1; }
	| expression comparing expression { $$ = new AExpOperation( $1, $2, $3 ); }
	;

expr2:
	  TPLUS expression { $$ = $2; }
	| TMINUS expression { $$ = new AExpFastOp( $2, $1, true ); }
	| TBNOT expression { $$ = new AExpFastOp( $2, $1, true ); }
	| TNOT expression { $$ = new AExpFastOp( $2, $1, true ); }
	| expression TINCREMENT { $$ = new AExpFastOp( $1, $2, false ); }
	| TINCREMENT expression { $$ = new AExpFastOp( $2, $1, true ); }
	| expression TDECREMENT { $$ = new AExpFastOp( $1, $2, false ); }
	| TDECREMENT expression { $$ = new AExpFastOp( $2, $1, true ); }
	// there is a double in get_obj, this miss leading should be solved soon //
	| TLPAREN expression TRPAREN { $$ = new AExpParent( $2 ); }
	| TNEW identifier TLBRACKET TRBRACKET { $$ = new AExpNewArray( NULL, $2 ); }
	| expression TQUESTION expression TCOLON expression { $$ = new AExpIfast( $1, $3, $5 ); }
	| set_path assigning expression {  $$ = new AExpAssign( $1, $2, $3 ); }
	| get_path { $$ = $1; }
	;

comparing:
	  TEQ | TNE | TLT | TLE | TGT | TGE | TPLUS | TMINUS | TDIVIDE | TMULT | TMODULUS | TOR | TAND
	| TBXOR | TLSHIFT | TRSHIFT | TZFILL | TBOR | TBAND | TBNOT | TEQA | TNEA | TINSTANCEOF
	;

set_path:
	  set_obj { $$ = $1; }
	| get_path TDOT set_obj { $$ = $1; $$->appendCall( $3 ); }


set_obj:
	  identifier { $$ = new AExpSetPath( $1 ); }
	| identifier TLBRACKET expression TRBRACKET { $$ = new AExpSetItem( $1, $3 ); }
	;

package_path:
	  identifier { $$ = new AExpGetPath( $1 ); }
	| TSUPER { $$ = new AExpSuper( $1 ); }
	| package_path TDOT package_path { $$ = $1; $$->appendCall( $3 ); }
	;

get_path:
	  get_obj { $$ = $1; }
	| get_path TDOT get_obj { $$ = $1; $$->appendCall( $3 ); }
	| TLBRACKET call_args TRBRACKET  { $$ = new AExpNewArray( $2, NULL ); } // create array //
	| TLBRACE object_props TRBRACE  { $$ = new AExpNewObject( $2 ); } // create array //
	;

get_obj:
	  identifier { $$ = new AExpGetPath( $1 ); }
	| TSUPER { $$ = new AExpSuper( $1 ); }
	// there is a double in expr2, this miss leading should be solved soon //
	// | TLPAREN expression TRPAREN { $$ = new AExpGetPath( new AExpParent( $2 ) ); } // there is no trouble anymore. Fuck! :S
	| TNEW get_obj TLPAREN call_args TRPAREN { $$ = new AExpNew( $2, $4 ); }
	| get_obj TLPAREN call_args TRPAREN { $$ = new AExpCallFunc( $1, $3 ); }
	| TCOMPGET TLPAREN call_args TRPAREN { $$ = new CompilerGet( $3 ); }
	| TCOMPSET TLPAREN call_args TRPAREN { $$ = new CompilerSet( $3 ); }
	| get_obj TLBRACKET expression TRBRACKET { $$ = new AExpGetItem( $1, $3 ); }
	| identifier TLBRACKET expression TRBRACKET { $$ = new AExpGetItem( $1, $3 ); }
	;

object_props:
	  { $$ = NULL; }/*blank*/
	| identifier TCOLON expression { $$ = new AExpressionVector(); $$->push_back( new AExpObjectProp( $1, $3 ) ); }
	| object_props TCOMMA identifier TCOLON expression { $$ = $1; $1->push_back( new AExpObjectProp( $3, $5 ) ); }
	;

call_args:
	  { $$ = NULL; }
	| expression { $$ = new AExpressionVector(); $$->push_back( $1 ); }
	| call_args TCOMMA expression { $$ = $1; $1->push_back( $3 ); }
	;

typage:
	  TNAME { $$ = new ATypage( $1, false ); }
	| TNAME TLBRACKET TRBRACKET { $$ = new ATypage( $1, true ); }
	;

identifier:
	  TNUMBER { $$ = new AExpression( $1 ); }
	| TNAME { $$ = new AExpression( $1 ); }
	| TSTRING { $$ = new AExpression( $1 ); }
	| TREGEX { $$ = new AExpression( $1 ); }
	| TFALSE { $$ = new AExpression( $1 ); }
	| TTRUE { $$ = new AExpression( $1 ); }
	| TNULL { $$ = new AExpression( $1 ); }
	| TTHIS	{ $$ = new AExpression( $1 ); }
	| TCOMPNAME TLPAREN package_path TRPAREN { $$ = new CompilerName( $3 ); }
	;

%%
