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

#ifndef YY_ZZ_PRE_PARSER_HPP_INCLUDED
# define YY_ZZ_PRE_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef ZZDEBUG
# if defined YYDEBUG
#  if YYDEBUG
#   define ZZDEBUG 1
#  else
#   define ZZDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ZZDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ZZDEBUG */
#if ZZDEBUG
extern int zzdebug;
#endif

/* Tokens.  */
#ifndef ZZTOKENTYPE
# define ZZTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum zztokentype {
     TLINE = 258,
     TEOF = 259,
     TDEFINE = 260,
     TDEFNAME = 261,
     TDEFVALUE = 262,
     TIFDEF = 263,
     TELSEIFDEF = 264,
     TELSEDEF = 265,
     TENDIFDEF = 266
   };
#endif


#if ! defined ZZSTYPE && ! defined ZZSTYPE_IS_DECLARED
typedef union ZZSTYPE
{
/* Line 2053 of yacc.c  */
#line 36 "pre_parser.y"

	ALineVector *line_list;
	ALine *line;

	TokenInfo *tinfo;
	int token;


/* Line 2053 of yacc.c  */
#line 85 "pre_parser.hpp"
} ZZSTYPE;
# define ZZSTYPE_IS_TRIVIAL 1
# define zzstype ZZSTYPE /* obsolescent; will be withdrawn */
# define ZZSTYPE_IS_DECLARED 1
#endif

extern ZZSTYPE zzlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int zzparse (void *YYPARSE_PARAM);
#else
int zzparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int zzparse (void);
#else
int zzparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_ZZ_PRE_PARSER_HPP_INCLUDED  */
