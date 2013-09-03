/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TEOF = 0,
     TEQ = 258,
     TNE = 259,
     TLT = 260,
     TLE = 261,
     TGT = 262,
     TGE = 263,
     TPLUS = 264,
     TMINUS = 265,
     TMULT = 266,
     TDIVIDE = 267,
     TMODULUS = 268,
     TINCREMENT = 269,
     TDECREMENT = 270,
     TNOT = 271,
     TEQA = 272,
     TNEA = 273,
     TRPAREN = 274,
     TLPAREN = 275,
     TRBRACKET = 276,
     TLBRACKET = 277,
     TRBRACE = 278,
     TLBRACE = 279,
     TIMPLEMENTS = 280,
     TINTERFACE = 281,
     TASSIGN = 282,
     TASSIGN_PLUS = 283,
     TASSIGN_MINUS = 284,
     TASSIGN_MULTIPLY = 285,
     TASSIGN_DIVIDE = 286,
     TASSIGN_BOR = 287,
     TSEMICOLON = 288,
     TCOMMA = 289,
     TDOT = 290,
     TCOLON = 291,
     TQUESTION = 292,
     TCONST = 293,
     TIMPORT = 294,
     TPACKAGE = 295,
     TOR = 296,
     TAND = 297,
     TBXOR = 298,
     TLSHIFT = 299,
     TRSHIFT = 300,
     TZFILL = 301,
     TBOR = 302,
     TBAND = 303,
     TBNOT = 304,
     TGET = 305,
     TSET = 306,
     TINSTANCEOF = 307,
     TTRUE = 308,
     TFALSE = 309,
     TVAR = 310,
     TCONTINUE = 311,
     TBREAK = 312,
     TCASE = 313,
     TDEFAULT = 314,
     TNULL = 315,
     TRETURN = 316,
     TNEW = 317,
     TSUPER = 318,
     TTHIS = 319,
     TNUMBER = 320,
     TSTRING = 321,
     TNAME = 322,
     TCOMPVAR = 323,
     TPUBLIC = 324,
     TPRIVATE = 325,
     TPROTECTED = 326,
     TSTATIC = 327,
     TDELETE = 328,
     TIF = 329,
     TELSE = 330,
     TWHILE = 331,
     TTRY = 332,
     TCATCH = 333,
     TDO = 334,
     TFOR = 335,
     TIN = 336,
     TSWITCH = 337,
     TFUNCTION = 338,
     TCLASS = 339,
     TEXTENDS = 340,
     TCOMPNAME = 341,
     TCOMPGET = 342,
     TCOMPSET = 343,
     TREGEX = 344,
     TEXTERNAL = 345,
     TCUSTOMIZE = 346,
     TEXPORT = 347,
     TVOID = 348
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 38 "parser.y"

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


/* Line 2053 of yacc.c  */
#line 170 "parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
