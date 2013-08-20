/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TASSIGN = 281,
     TASSIGN_PLUS = 282,
     TASSIGN_MINUS = 283,
     TASSIGN_MULTIPLY = 284,
     TASSIGN_DIVIDE = 285,
     TASSIGN_BOR = 286,
     TSEMICOLON = 287,
     TCOMMA = 288,
     TDOT = 289,
     TCOLON = 290,
     TQUESTION = 291,
     TCONST = 292,
     TIMPORT = 293,
     TPACKAGE = 294,
     TOR = 295,
     TAND = 296,
     TBXOR = 297,
     TLSHIFT = 298,
     TRSHIFT = 299,
     TZFILL = 300,
     TBOR = 301,
     TBAND = 302,
     TBNOT = 303,
     TGET = 304,
     TSET = 305,
     TINSTANCEOF = 306,
     TTRUE = 307,
     TFALSE = 308,
     TVAR = 309,
     TCONTINUE = 310,
     TBREAK = 311,
     TCASE = 312,
     TDEFAULT = 313,
     TNULL = 314,
     TRETURN = 315,
     TNEW = 316,
     TSUPER = 317,
     TTHIS = 318,
     TNUMBER = 319,
     TSTRING = 320,
     TNAME = 321,
     TCOMPVAR = 322,
     TPUBLIC = 323,
     TPRIVATE = 324,
     TPROTECTED = 325,
     TSTATIC = 326,
     TDELETE = 327,
     TIF = 328,
     TELSE = 329,
     TWHILE = 330,
     TTRY = 331,
     TCATCH = 332,
     TDO = 333,
     TFOR = 334,
     TIN = 335,
     TSWITCH = 336,
     TFUNCTION = 337,
     TCLASS = 338,
     TEXTENDS = 339,
     TCOMPNAME = 340,
     TCOMPGET = 341,
     TCOMPSET = 342,
     TREGEX = 343,
     TEXTERNAL = 344,
     TCUSTOMIZE = 345,
     TEXPORT = 346
   };
#endif
/* Tokens.  */
#define TEOF 0
#define TEQ 258
#define TNE 259
#define TLT 260
#define TLE 261
#define TGT 262
#define TGE 263
#define TPLUS 264
#define TMINUS 265
#define TMULT 266
#define TDIVIDE 267
#define TMODULUS 268
#define TINCREMENT 269
#define TDECREMENT 270
#define TNOT 271
#define TEQA 272
#define TNEA 273
#define TRPAREN 274
#define TLPAREN 275
#define TRBRACKET 276
#define TLBRACKET 277
#define TRBRACE 278
#define TLBRACE 279
#define TIMPLEMENTS 280
#define TASSIGN 281
#define TASSIGN_PLUS 282
#define TASSIGN_MINUS 283
#define TASSIGN_MULTIPLY 284
#define TASSIGN_DIVIDE 285
#define TASSIGN_BOR 286
#define TSEMICOLON 287
#define TCOMMA 288
#define TDOT 289
#define TCOLON 290
#define TQUESTION 291
#define TCONST 292
#define TIMPORT 293
#define TPACKAGE 294
#define TOR 295
#define TAND 296
#define TBXOR 297
#define TLSHIFT 298
#define TRSHIFT 299
#define TZFILL 300
#define TBOR 301
#define TBAND 302
#define TBNOT 303
#define TGET 304
#define TSET 305
#define TINSTANCEOF 306
#define TTRUE 307
#define TFALSE 308
#define TVAR 309
#define TCONTINUE 310
#define TBREAK 311
#define TCASE 312
#define TDEFAULT 313
#define TNULL 314
#define TRETURN 315
#define TNEW 316
#define TSUPER 317
#define TTHIS 318
#define TNUMBER 319
#define TSTRING 320
#define TNAME 321
#define TCOMPVAR 322
#define TPUBLIC 323
#define TPRIVATE 324
#define TPROTECTED 325
#define TSTATIC 326
#define TDELETE 327
#define TIF 328
#define TELSE 329
#define TWHILE 330
#define TTRY 331
#define TCATCH 332
#define TDO 333
#define TFOR 334
#define TIN 335
#define TSWITCH 336
#define TFUNCTION 337
#define TCLASS 338
#define TEXTENDS 339
#define TCOMPNAME 340
#define TCOMPGET 341
#define TCOMPSET 342
#define TREGEX 343
#define TEXTERNAL 344
#define TCUSTOMIZE 345
#define TEXPORT 346




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "parser.y"
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
/* Line 1529 of yacc.c.  */
#line 251 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

