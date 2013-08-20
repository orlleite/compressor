/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 23 "parser.y"

	#include <iostream>
	#include "types.hpp"
	#include "expressions.hpp"
	#include "instructions.hpp"
	#include "blocks.hpp"
	#include "workspace.hpp"

	extern int yylex( void );
	
	void yyerror(const char *s) { printf("ERROR: %s\n", s); };


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 311 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 324 "parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNRULES -- Number of states.  */
#define YYNSTATES  441

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    12,    15,    17,    20,
      22,    25,    33,    44,    55,    56,    59,    62,    64,    65,
      67,    70,    73,    74,    76,    79,    82,    83,    86,    87,
      90,    94,    97,   101,   105,   112,   119,   129,   140,   152,
     163,   169,   172,   176,   181,   188,   195,   198,   209,   221,
     233,   242,   244,   246,   248,   252,   258,   264,   272,   274,
     285,   292,   301,   304,   309,   315,   323,   333,   345,   353,
     363,   369,   377,   385,   394,   406,   413,   418,   421,   424,
     432,   434,   436,   438,   441,   445,   450,   456,   460,   468,
     474,   476,   479,   482,   484,   488,   491,   492,   494,   498,
     502,   508,   513,   520,   522,   524,   526,   528,   530,   532,
     534,   536,   540,   543,   546,   549,   552,   555,   558,   561,
     564,   568,   573,   579,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     615,   617,   619,   621,   623,   625,   627,   629,   631,   633,
     637,   639,   644,   646,   648,   652,   654,   658,   662,   666,
     668,   670,   676,   681,   686,   691,   696,   701,   702,   706,
     712,   713,   715,   719,   721,   725,   727,   729,   731,   733,
     735,   737,   739,   741
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      93,     0,    -1,    -1,    93,    94,     0,    -1,    -1,    94,
      95,    -1,    94,    32,    -1,    95,    -1,    39,   121,    -1,
      39,    -1,    38,   121,    -1,    83,   127,    99,   100,    24,
      97,    23,    -1,    89,    83,   127,    99,   100,    24,    98,
      23,    26,   127,    -1,    82,   127,    20,   111,    19,    35,
     126,    24,    96,    23,    -1,    -1,    96,   107,    -1,    96,
      32,    -1,   107,    -1,    -1,   103,    -1,    97,   103,    -1,
      97,    32,    -1,    -1,   101,    -1,    98,   101,    -1,    98,
      32,    -1,    -1,    84,   126,    -1,    -1,    25,   127,    -1,
     100,    33,   127,    -1,   105,   102,    -1,   105,    71,   102,
      -1,   105,    37,   102,    -1,    54,   127,    35,   126,    26,
     127,    -1,    37,   127,    35,   126,    26,   127,    -1,    82,
     127,    20,   111,    19,    35,   126,    26,   127,    -1,    49,
      82,   127,    20,   111,    19,    35,   126,    26,   127,    -1,
      49,    82,   127,    20,   111,    19,    35,   126,    26,    54,
     127,    -1,    50,    82,   127,    20,   111,    19,    35,   126,
      26,   127,    -1,    82,   127,    20,   111,    19,    -1,   105,
     104,    -1,   105,    71,   104,    -1,    54,   127,    35,   126,
      -1,    54,   127,    35,   126,    26,   116,    -1,    37,   127,
      35,   126,    26,   116,    -1,    54,   106,    -1,    82,   127,
      20,   111,    19,    35,   126,    24,    96,    23,    -1,    49,
      82,   127,    20,   111,    19,    35,   126,    24,    96,    23,
      -1,    50,    82,   127,    20,   111,    19,    35,   126,    24,
      96,    23,    -1,    82,   127,    20,   111,    19,    24,    96,
      23,    -1,    69,    -1,    68,    -1,    70,    -1,   127,    35,
     126,    -1,   127,    35,   126,    26,   116,    -1,   106,    33,
     127,    35,   126,    -1,   106,    33,   127,    35,   126,    26,
     116,    -1,   116,    -1,    82,   127,    20,   111,    19,    35,
     126,    24,    96,    23,    -1,    74,    73,    20,   116,    19,
     107,    -1,    74,    73,    20,   116,    19,    24,    96,    23,
      -1,    74,   107,    -1,    74,    24,    96,    23,    -1,    73,
      20,   116,    19,   107,    -1,    73,    20,   116,    19,    24,
      96,    23,    -1,    79,    20,   114,    32,   114,    32,   114,
      19,   107,    -1,    79,    20,   114,    32,   114,    32,   114,
      19,    24,    96,    23,    -1,    79,    20,   113,    80,   116,
      19,   107,    -1,    79,    20,   113,    80,   116,    19,    24,
      96,    23,    -1,    75,    20,   116,    19,   107,    -1,    75,
      20,   116,    19,    24,    96,    23,    -1,    78,   107,    32,
      75,    20,   116,    19,    -1,    78,    24,    96,    23,    75,
      20,   116,    19,    -1,    76,    24,    96,    23,    77,    20,
     112,    19,    24,    96,    23,    -1,    54,   127,    35,   126,
      26,   116,    -1,    54,   127,    35,   126,    -1,    54,   108,
      -1,    72,   122,    -1,    81,    20,   116,    19,    24,   109,
      23,    -1,    56,    -1,    55,    -1,    60,    -1,    60,   116,
      -1,   119,   115,   116,    -1,    62,    20,   125,    19,    -1,
     127,    35,   126,    26,   116,    -1,   127,    35,   126,    -1,
     108,    33,   127,    35,   126,    26,   116,    -1,   108,    33,
     127,    35,   126,    -1,   110,    -1,   109,    32,    -1,   109,
     110,    -1,   107,    -1,    57,   116,    35,    -1,    58,    35,
      -1,    -1,   112,    -1,   111,    33,   112,    -1,   127,    35,
     126,    -1,   127,    35,   126,    26,   116,    -1,    54,   127,
      35,   126,    -1,    54,   127,    35,   126,    26,   116,    -1,
     116,    -1,    26,    -1,    30,    -1,    28,    -1,    29,    -1,
      27,    -1,    31,    -1,   117,    -1,   116,   118,   116,    -1,
       9,   116,    -1,    10,   116,    -1,    48,   116,    -1,    16,
     116,    -1,   116,    14,    -1,    14,   116,    -1,   116,    15,
      -1,    15,   116,    -1,    20,   116,    19,    -1,    61,   127,
      22,    21,    -1,   116,    36,   116,    35,   116,    -1,   119,
     115,   116,    -1,   122,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,
      -1,    12,    -1,    11,    -1,    13,    -1,    40,    -1,    41,
      -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,    46,
      -1,    47,    -1,    48,    -1,    17,    -1,    18,    -1,    51,
      -1,   120,    -1,   122,    34,   120,    -1,   127,    -1,   127,
      22,   116,    21,    -1,   127,    -1,    62,    -1,   121,    34,
     121,    -1,   123,    -1,   122,    34,   123,    -1,    22,   125,
      21,    -1,    24,   124,    23,    -1,   127,    -1,    62,    -1,
      61,   123,    20,   125,    19,    -1,   123,    20,   125,    19,
      -1,    86,    20,   125,    19,    -1,    87,    20,   125,    19,
      -1,   123,    22,   116,    21,    -1,   127,    22,   116,    21,
      -1,    -1,   127,    35,   116,    -1,   124,    33,   127,    35,
     116,    -1,    -1,   116,    -1,   125,    33,   116,    -1,    66,
      -1,    66,    22,    21,    -1,    64,    -1,    66,    -1,    65,
      -1,    88,    -1,    53,    -1,    52,    -1,    59,    -1,    63,
      -1,    85,    20,   121,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    89,    93,    94,    95,    96,   100,   101,
     102,   103,   104,   105,   109,   110,   111,   112,   116,   117,
     118,   119,   123,   124,   125,   126,   130,   131,   135,   136,
     137,   141,   142,   143,   147,   148,   149,   150,   151,   152,
     153,   157,   158,   162,   163,   164,   165,   166,   167,   168,
     169,   173,   173,   173,   177,   178,   179,   180,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   216,   217,   218,   219,
     224,   225,   226,   230,   231,   232,   235,   236,   237,   241,
     242,   246,   250,   251,   255,   255,   255,   255,   255,   255,
     259,   260,   264,   265,   266,   267,   268,   269,   270,   271,
     273,   274,   275,   276,   277,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   286,   287,
     291,   292,   296,   297,   298,   302,   303,   304,   305,   309,
     310,   313,   314,   315,   316,   317,   318,   322,   323,   324,
     328,   329,   330,   334,   335,   339,   340,   341,   342,   343,
     344,   345,   346,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "TEQ", "TNE", "TLT", "TLE",
  "TGT", "TGE", "TPLUS", "TMINUS", "TMULT", "TDIVIDE", "TMODULUS",
  "TINCREMENT", "TDECREMENT", "TNOT", "TEQA", "TNEA", "TRPAREN", "TLPAREN",
  "TRBRACKET", "TLBRACKET", "TRBRACE", "TLBRACE", "TIMPLEMENTS", "TASSIGN",
  "TASSIGN_PLUS", "TASSIGN_MINUS", "TASSIGN_MULTIPLY", "TASSIGN_DIVIDE",
  "TASSIGN_BOR", "TSEMICOLON", "TCOMMA", "TDOT", "TCOLON", "TQUESTION",
  "TCONST", "TIMPORT", "TPACKAGE", "TOR", "TAND", "TBXOR", "TLSHIFT",
  "TRSHIFT", "TZFILL", "TBOR", "TBAND", "TBNOT", "TGET", "TSET",
  "TINSTANCEOF", "TTRUE", "TFALSE", "TVAR", "TCONTINUE", "TBREAK", "TCASE",
  "TDEFAULT", "TNULL", "TRETURN", "TNEW", "TSUPER", "TTHIS", "TNUMBER",
  "TSTRING", "TNAME", "TCOMPVAR", "TPUBLIC", "TPRIVATE", "TPROTECTED",
  "TSTATIC", "TDELETE", "TIF", "TELSE", "TWHILE", "TTRY", "TCATCH", "TDO",
  "TFOR", "TIN", "TSWITCH", "TFUNCTION", "TCLASS", "TEXTENDS", "TCOMPNAME",
  "TCOMPGET", "TCOMPSET", "TREGEX", "TEXTERNAL", "TCUSTOMIZE", "TEXPORT",
  "$accept", "input", "file_block", "object", "block", "class_block",
  "external_class_block", "extends", "implements", "external_property",
  "external_proper2", "property", "proper2", "access", "props_declaration",
  "instruction", "vars_declaration", "switch_block", "switch_inst",
  "declare_args", "declare_arg", "forin_var", "for_args", "assigning",
  "expression", "expr2", "comparing", "set_path", "set_obj",
  "package_path", "get_path", "get_obj", "object_props", "call_args",
  "typage", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   109,   110,   110,   110,   111,   111,   111,   112,
     112,   113,   114,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     1,     2,     1,
       2,     7,    10,    10,     0,     2,     2,     1,     0,     1,
       2,     2,     0,     1,     2,     2,     0,     2,     0,     2,
       3,     2,     3,     3,     6,     6,     9,    10,    11,    10,
       5,     2,     3,     4,     6,     6,     2,    10,    11,    11,
       8,     1,     1,     1,     3,     5,     5,     7,     1,    10,
       6,     8,     2,     4,     5,     7,     9,    11,     7,     9,
       5,     7,     7,     8,    11,     6,     4,     2,     2,     7,
       1,     1,     1,     2,     3,     4,     5,     3,     7,     5,
       1,     2,     2,     1,     3,     2,     0,     1,     3,     3,
       5,     4,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     1,     1,     3,     1,     3,     3,     3,     1,
       1,     5,     4,     4,     4,     4,     4,     0,     3,     5,
       0,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     0,     9,     0,     0,     0,     0,     7,
     180,   179,   181,   153,   182,   175,   177,   176,     0,   178,
      10,   152,     8,     0,    26,     0,     3,     6,     5,     0,
       0,    96,     0,    28,    26,     0,   154,     0,    97,     0,
     173,    27,     0,     0,    28,   183,     0,     0,     0,     0,
      29,    18,     0,     0,     0,    98,    99,   174,    52,    51,
      53,     0,    19,     0,    30,    22,     0,     0,    11,    21,
      20,     0,     0,     0,     0,     0,     0,    41,     0,    23,
       0,    14,     0,     0,     0,     0,     0,     0,   170,   167,
       0,     0,   160,     0,     0,   100,   110,     0,   148,   124,
     155,   159,     0,     0,     0,    46,     0,    42,     0,     0,
      25,    24,     0,     0,     0,     0,     0,     0,    31,     0,
      81,    80,    82,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    58,     0,   112,   113,   117,
     119,   115,     0,   171,     0,     0,     0,   114,     0,     0,
     159,   170,   170,   125,   126,   127,   128,   129,   130,   131,
     132,   134,   133,   135,   116,   118,   145,   146,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   147,     0,
     104,   108,   106,   107,   105,   109,     0,     0,   170,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,    33,
       0,     0,     0,     0,    32,     0,    77,     0,    83,   170,
      78,   159,     0,    14,     0,    62,     0,    14,    14,     0,
       0,     0,     0,    13,    16,    15,     0,   120,   157,     0,
     158,     0,     0,   170,     0,     0,     0,     0,   111,   123,
     149,   156,     0,     0,     0,     0,    96,    96,     0,    43,
       0,    12,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,    96,    84,   172,     0,   168,
       0,   121,     0,   163,   164,     0,   162,   165,   166,     0,
       0,     0,     0,     0,     0,     0,    96,    96,     0,     0,
       0,    76,    85,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   166,   122,    45,
       0,     0,    56,    44,    14,     0,     0,     0,     0,     0,
      40,     0,     0,    14,    64,     0,    14,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,    35,     0,     0,    34,     0,    89,    75,
       0,    14,    60,     0,     0,     0,     0,   101,     0,     0,
       0,     0,     0,    93,     0,    90,     0,     0,     0,    57,
      50,    14,     0,     0,     0,     0,    65,     0,    71,     0,
       0,    72,     0,    14,    68,     0,     0,     0,    95,    79,
      91,    92,     0,    14,    14,     0,     0,     0,     0,    88,
      61,     0,    73,   102,     0,     0,     0,    94,    14,     0,
       0,    47,     0,     0,    36,    14,    69,    14,    66,     0,
      48,    49,     0,    37,    39,     0,     0,    59,    38,    74,
      67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     9,   133,    61,    78,    33,    43,    79,
     118,    62,    77,    63,   105,   134,   206,   374,   375,    37,
      38,   271,   272,   186,   135,    96,   179,    97,    98,    20,
      99,   100,   145,   144,    41,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -306
static const yytype_int16 yypact[] =
{
    -306,    21,  -306,   236,   236,   498,   498,   -70,     8,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,    38,  -306,
      43,  -306,    43,    69,    11,   498,  -306,  -306,  -306,   236,
     236,   498,    45,    83,    11,    -2,    43,     1,  -306,    98,
     119,  -306,   498,    82,    83,  -306,   100,   498,    45,   128,
    -306,   109,   498,   107,    45,  -306,   126,  -306,  -306,  -306,
    -306,   -14,  -306,    68,  -306,   109,   133,  2907,  -306,  -306,
    -306,   498,    80,    90,   498,   -25,   498,  -306,    13,  -306,
      88,  2151,  2907,  2907,  2907,  2907,  2907,  2907,  2907,   498,
    2907,   427,  -306,   154,   162,  3465,  -306,   358,  -306,   150,
     138,   346,   148,   498,   498,   152,   151,  -306,   172,   170,
    -306,  -306,   167,   118,   120,   498,   192,   498,  -306,   498,
    -306,  -306,  2907,   177,   102,   183,  2231,   185,   182,  2311,
     187,   189,   498,   791,  -306,  3465,   358,   330,   330,  3465,
    3465,  3465,  2939,  3465,   -10,    51,   190,  3465,   427,   149,
     196,  2907,  2907,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  2907,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  2907,
    -306,  -306,  -306,  -306,  -306,  -306,  2907,   427,  2907,  2907,
    2907,    45,   202,   207,   498,    45,   498,   498,   498,  -306,
     199,   498,   498,   200,  -306,   216,   179,   204,  3465,  2907,
     203,   218,  2907,  2071,   230,  -306,  2907,  2151,  2071,   219,
     653,  2907,   238,  -306,  -306,  -306,  2907,  -306,  -306,  2907,
    -306,   498,  2907,  2907,  2791,    29,    31,  2993,  3465,  3465,
    -306,   138,    33,  3009,  3058,   233,   498,   498,   221,    97,
      34,  -306,    45,   241,   242,    45,   498,   498,    45,    42,
     427,  2907,  3078,   871,   249,  2907,  3127,   951,  1031,   188,
     498,   186,   237,  3465,  3147,   498,  3465,  3465,   235,  3465,
      59,  -306,  3196,  -306,  -306,  2907,  -306,  -306,   428,  2907,
      61,    66,    45,  2907,    52,   247,   498,   498,   256,    74,
     248,   110,  -306,  2391,  -306,  3216,  2471,   191,   210,   266,
     255,  2907,  2849,   268,    94,  2907,  -306,  -306,  3465,  3465,
     261,   271,   265,  3265,  2151,    45,   498,   113,   115,   498,
     272,    45,  2907,  2071,  -306,  2551,  2071,  -306,   283,   288,
    2907,    45,  3314,   498,   277,  1111,   276,  3465,    45,    45,
    2907,  1191,   292,  -306,   282,   284,  -306,    45,   286,  3331,
    1271,  2071,  -306,  1351,   498,  2907,  3380,   294,  2631,   290,
    2849,  2907,   293,  -306,   711,  -306,    45,   303,   305,  3465,
    -306,  2151,    45,    45,   308,  2907,  -306,  1431,  -306,   299,
    3400,  -306,  2907,  2071,  -306,    45,   312,  3449,  -306,  -306,
    -306,  -306,   311,  2151,  2151,  1511,   310,   320,   498,  3465,
    -306,   313,  -306,  3465,  1591,   294,  2711,  -306,  2151,  1671,
    1751,  -306,   443,   498,  -306,  2151,  -306,  2071,  -306,  1831,
    -306,  -306,   498,  -306,  -306,  1911,  1991,  -306,  -306,  -306,
    -306
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -306,  -306,  -306,   341,  -180,  -306,  -306,   318,   315,   278,
     -81,   296,   279,   -35,  -306,   267,  -306,  -306,   -19,  -177,
     -42,  -306,  -305,   224,   359,  -306,  -306,    47,   175,    12,
     239,   -85,  -306,  -137,   -44,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -168
static const yytype_int16 yytable[] =
{
      21,    21,    23,    24,    56,    55,   149,   344,    26,    68,
      66,   228,    71,    25,   235,   236,    22,    45,    69,   250,
      46,     2,    34,   229,    72,    73,    21,    21,    39,    74,
      80,   199,    30,   263,    47,   204,   109,   267,   268,    50,
      27,    35,    36,    80,    39,   110,     3,     4,   283,    64,
     284,   242,   286,   294,    58,    59,    60,    76,    29,     3,
       4,   302,   229,   149,   229,   396,   229,    47,   102,   290,
     291,   106,   259,   108,   230,   229,   324,    30,   316,   299,
     320,    58,    59,    60,   231,   321,   146,   325,   150,    31,
       5,     6,   229,   330,    47,    32,   280,     7,   314,    47,
     192,   193,   241,     5,     6,    71,    51,    47,    42,   200,
       7,    40,   203,   346,   205,    52,   207,    72,    73,   327,
     328,   211,    74,   293,    88,   112,    89,    47,   136,   222,
     -54,    65,   354,    48,   355,    54,   332,   113,   114,    75,
      52,    49,   115,   -87,   351,   211,    47,   245,    47,    57,
      76,   249,    67,   360,    10,    11,   363,    81,   188,   116,
     189,    12,   103,   148,    92,    14,    15,    16,    17,   233,
     117,   189,   104,   136,   151,   241,   136,    58,    59,    60,
     136,   387,   152,   191,   187,   194,   195,    18,    93,    94,
      19,   248,   196,    39,   251,   200,   197,   209,   253,   254,
     201,   405,   202,   212,   198,   216,   217,   220,   295,   221,
     264,   298,   257,   414,   301,   264,   113,   114,   234,    10,
      11,   115,   246,   419,   420,   232,    12,   247,   278,   198,
      14,    15,    16,    17,   252,   255,   256,   260,   429,   258,
     261,   113,   114,    39,    39,   435,   115,   436,   322,   117,
     265,   269,    18,    39,   300,    19,   292,   211,   275,   289,
     136,   296,   297,   309,   136,   136,   311,   310,   338,   312,
     315,   190,    39,   326,   117,  -150,  -150,  -150,  -150,  -150,
    -150,   352,   329,   331,   232,   339,   340,   358,    10,    11,
     341,   350,   345,    39,    39,    12,   348,   367,    13,    14,
      15,    16,    17,   364,   377,   378,   349,   357,   365,   370,
     136,   376,   385,   384,   136,   136,   381,   382,   411,   383,
     392,    18,   389,   353,    19,   395,   356,   403,   398,   404,
     264,   416,   402,   264,   408,   418,   422,   425,   406,   407,
     369,   161,   162,   163,   164,   165,   423,   166,   167,    28,
     136,   415,    44,   136,   107,   401,   111,    70,   264,    53,
     226,    39,   240,   210,     0,     0,   168,     0,   190,     0,
       0,   136,  -150,  -150,  -150,  -150,  -150,  -150,   177,     0,
     136,   178,   136,   136,   180,   181,   182,   183,   184,   185,
     264,     0,   136,   215,     0,     0,   219,     0,   136,     0,
     225,     0,     0,     0,     0,   424,     0,   136,   136,     0,
     136,     0,     0,     0,     0,   136,     0,     0,     0,   433,
     434,   136,     0,     0,   264,     0,    95,     0,   136,   438,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,     0,   147,
     136,   136,   136,     0,  -151,  -151,  -151,  -151,  -151,  -151,
       0,   136,     0,   136,     0,   136,   136,   136,     0,     0,
       0,     0,   136,     0,   136,     0,   136,     0,     0,    10,
      11,   208,   136,   136,     0,     0,    12,     0,   148,    92,
      14,    15,    16,    17,     0,    10,    11,   432,     0,     0,
       0,     0,    12,     0,     0,     0,    14,    15,    16,    17,
     143,   143,    18,    93,    94,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,    18,     0,
     225,    19,     0,     0,   225,   225,     0,     0,   238,     0,
       0,     0,     0,     0,     0,   239,     0,   143,   243,   244,
      10,    11,     0,     0,     0,     0,     0,    12,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,   143,     0,
     334,   262,     0,   337,     0,   266,     0,     0,     0,   273,
     274,     0,     0,    18,     0,   276,    19,     0,   277,     0,
       0,   279,   143,   282,     0,     0,     0,     0,     0,     0,
       0,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,   225,     0,
     282,     0,     0,     0,   305,     0,     0,   225,     0,     0,
     225,     0,     0,     0,     0,   394,     0,     0,     0,     0,
       0,   373,     0,     0,   318,     0,     0,     0,   319,     0,
       0,     0,   323,     0,   225,     0,     0,     0,     0,     0,
       0,     0,    82,    83,     0,     0,     0,    84,    85,    86,
     342,   273,   225,    87,   347,    88,     0,    89,     0,     0,
       0,   225,     0,   428,     0,     0,   225,   225,     0,     0,
       0,   359,     0,     0,     0,     0,   225,     0,     0,   366,
       0,    90,   225,   225,     0,    10,    11,   270,     0,   379,
       0,     0,    12,     0,    91,    92,    14,    15,    16,    17,
      82,    83,     0,     0,   390,    84,    85,    86,     0,   273,
     397,    87,     0,    88,   399,    89,     0,     0,    18,    93,
      94,    19,     0,   400,   409,     0,     0,     0,     0,     0,
       0,   413,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,   371,   372,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   223,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   304,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   307,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   308,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,   371,   372,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   380,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   386,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   388,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   410,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   421,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   426,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   430,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   431,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   437,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   439,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,   440,    89,     0,     0,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,  -167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   214,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   333,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,     0,    88,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,   119,   120,   121,     0,     0,
      12,   122,    91,   123,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,   129,
     130,     0,   131,   132,     0,     0,    18,    93,    94,    19,
      82,    83,     0,     0,     0,    84,    85,    86,     0,     0,
       0,    87,   281,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    10,    11,     0,     0,     0,     0,     0,
      12,     0,    91,    92,    14,    15,    16,    17,    82,    83,
       0,     0,     0,    84,    85,    86,     0,     0,     0,    87,
       0,    88,     0,    89,     0,     0,    18,    93,    94,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,    10,    11,   343,     0,     0,     0,     0,    12,     0,
      91,    92,    14,    15,    16,    17,    82,    83,     0,     0,
       0,    84,    85,    86,     0,     0,     0,    87,     0,    88,
       0,    89,     0,     0,    18,    93,    94,    19,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    90,   166,   167,   227,    10,
      11,     0,     0,     0,     0,     0,    12,     0,    91,    92,
      14,    15,    16,    17,     0,   168,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,     0,
     178,     0,    18,    93,    94,    19,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     166,   167,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,   166,   167,   285,   168,
     287,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,     0,   178,   168,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,     0,
     178,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   166,   167,     0,     0,   288,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   168,   166,   167,   303,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,     0,   178,
       0,     0,     0,     0,   168,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,     0,   178,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,   166,   167,   306,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   168,   166,   167,   313,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,   178,     0,
       0,     0,     0,   168,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,   178,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,   166,   167,     0,     0,   317,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   168,   166,   167,   335,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,   178,     0,     0,
       0,     0,   168,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,   178,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -55,     0,
       0,   168,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,     0,   178,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   166,   167,   368,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,   166,   167,
     168,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   -86,   178,     0,   168,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,     0,   178,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,   166,   167,   391,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   168,   166,   167,   412,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,   178,     0,     0,     0,     0,   168,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,   178,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,   166,   167,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,     0,   166,   167,   417,   168,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,     0,
     178,   168,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,     0,   178
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,    48,    47,    91,   312,     0,    23,
      54,    21,    37,    83,   151,   152,     4,    19,    32,   196,
      19,     0,    25,    33,    49,    50,    29,    30,    31,    54,
      65,   112,    34,   213,    33,   116,    23,   217,   218,    42,
      32,    29,    30,    78,    47,    32,    38,    39,    19,    52,
      19,   188,    19,    19,    68,    69,    70,    82,    20,    38,
      39,    19,    33,   148,    33,   370,    33,    33,    71,   246,
     247,    74,   209,    76,    23,    33,    24,    34,    19,   256,
      19,    68,    69,    70,    33,    19,    89,    35,    91,    20,
      82,    83,    33,    19,    33,    84,   233,    89,   275,    33,
     103,   104,   187,    82,    83,    37,    24,    33,    25,   112,
      89,    66,   115,    19,   117,    33,   119,    49,    50,   296,
     297,   124,    54,    26,    22,    37,    24,    33,    81,   132,
      33,    24,    19,    35,    19,    35,    26,    49,    50,    71,
      33,    22,    54,    33,   324,   148,    33,   191,    33,    21,
      82,   195,    26,   333,    52,    53,   336,    24,    20,    71,
      22,    59,    82,    61,    62,    63,    64,    65,    66,    20,
      82,    22,    82,   126,    20,   260,   129,    68,    69,    70,
     133,   361,    20,    35,    34,    33,    35,    85,    86,    87,
      88,   194,    20,   196,   197,   198,    26,    20,   201,   202,
      82,   381,    82,    20,    37,    20,    24,    20,   252,    20,
     213,   255,    33,   393,   258,   218,    49,    50,    22,    52,
      53,    54,    20,   403,   404,    35,    59,    20,   231,    37,
      63,    64,    65,    66,    35,    35,    20,    34,   418,    35,
      22,    49,    50,   246,   247,   425,    54,   427,   292,    82,
      20,    32,    85,   256,   257,    88,    35,   260,    20,    26,
     213,    20,    20,    75,   217,   218,    80,   270,    77,    32,
      35,    22,   275,    26,    82,    26,    27,    28,    29,    30,
      31,   325,    26,    35,    35,    75,    20,   331,    52,    53,
      35,    26,    24,   296,   297,    59,    35,   341,    62,    63,
      64,    65,    66,    20,   348,   349,    35,    35,    20,    32,
     263,    35,    26,   357,   267,   268,    24,    35,    19,    35,
      26,    85,   364,   326,    88,    35,   329,    24,    35,    24,
     333,    19,   376,   336,    26,    24,    26,    24,   382,   383,
     343,    11,    12,    13,    14,    15,    26,    17,    18,     8,
     303,   395,    34,   306,    75,   374,    78,    61,   361,    44,
     136,   364,   187,   124,    -1,    -1,    36,    -1,    22,    -1,
      -1,   324,    26,    27,    28,    29,    30,    31,    48,    -1,
     333,    51,   335,   336,    26,    27,    28,    29,    30,    31,
     393,    -1,   345,   126,    -1,    -1,   129,    -1,   351,    -1,
     133,    -1,    -1,    -1,    -1,   408,    -1,   360,   361,    -1,
     363,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,   422,
     423,   374,    -1,    -1,   427,    -1,    67,    -1,   381,   432,
      -1,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,
     393,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
     403,   404,   405,    -1,    26,    27,    28,    29,    30,    31,
      -1,   414,    -1,   416,    -1,   418,   419,   420,    -1,    -1,
      -1,    -1,   425,    -1,   427,    -1,   429,    -1,    -1,    52,
      53,   122,   435,   436,    -1,    -1,    59,    -1,    61,    62,
      63,    64,    65,    66,    -1,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
     151,   152,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    85,    -1,
     263,    88,    -1,    -1,   267,   268,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,   209,    -1,
     303,   212,    -1,   306,    -1,   216,    -1,    -1,    -1,   220,
     221,    -1,    -1,    85,    -1,   226,    88,    -1,   229,    -1,
      -1,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,   351,    -1,
     261,    -1,    -1,    -1,   265,    -1,    -1,   360,    -1,    -1,
     363,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,
      -1,   374,    -1,    -1,   285,    -1,    -1,    -1,   289,    -1,
      -1,    -1,   293,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    15,    16,
     311,   312,   405,    20,   315,    22,    -1,    24,    -1,    -1,
      -1,   414,    -1,   416,    -1,    -1,   419,   420,    -1,    -1,
      -1,   332,    -1,    -1,    -1,    -1,   429,    -1,    -1,   340,
      -1,    48,   435,   436,    -1,    52,    53,    54,    -1,   350,
      -1,    -1,    59,    -1,    61,    62,    63,    64,    65,    66,
       9,    10,    -1,    -1,   365,    14,    15,    16,    -1,   370,
     371,    20,    -1,    22,    23,    24,    -1,    -1,    85,    86,
      87,    88,    -1,    32,   385,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    81,    82,    -1,    -1,    85,    86,    87,    88,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    65,    66,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    65,    66,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    48,    17,    18,    19,    52,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    62,
      63,    64,    65,    66,    -1,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    -1,    85,    86,    87,    88,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    35,    36,
      21,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    51,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    -1,    21,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    36,    17,    18,    19,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    36,    17,    18,    19,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    -1,    21,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    36,    17,    18,    19,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    51,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    33,    51,    -1,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    51,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    36,    17,    18,    19,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,     0,    38,    39,    82,    83,    89,    94,    95,
      52,    53,    59,    62,    63,    64,    65,    66,    85,    88,
     121,   127,   121,   127,   127,    83,     0,    32,    95,    20,
      34,    20,    84,    99,   127,   121,   121,   111,   112,   127,
      66,   126,    25,   100,    99,    19,    19,    33,    35,    22,
     127,    24,    33,   100,    35,   112,   126,    21,    68,    69,
      70,    97,   103,   105,   127,    24,   126,    26,    23,    32,
     103,    37,    49,    50,    54,    71,    82,   104,    98,   101,
     105,    24,     9,    10,    14,    15,    16,    20,    22,    24,
      48,    61,    62,    86,    87,   116,   117,   119,   120,   122,
     123,   127,   127,    82,    82,   106,   127,   104,   127,    23,
      32,   101,    37,    49,    50,    54,    71,    82,   102,    54,
      55,    56,    60,    62,    72,    73,    74,    75,    76,    78,
      79,    81,    82,    96,   107,   116,   119,   116,   116,   116,
     116,   116,   116,   116,   125,   124,   127,   116,    61,   123,
     127,    20,    20,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    17,    18,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    51,   118,
      26,    27,    28,    29,    30,    31,   115,    34,    20,    22,
      22,    35,   127,   127,    33,    35,    20,    26,    37,   102,
     127,    82,    82,   127,   102,   127,   108,   127,   116,    20,
     122,   127,    20,    24,    73,   107,    20,    24,    24,   107,
      20,    20,   127,    23,    32,   107,   115,    19,    21,    33,
      23,    33,    35,    20,    22,   125,   125,   116,   116,   116,
     120,   123,   125,   116,   116,   126,    20,    20,   127,   126,
     111,   127,    35,   127,   127,    35,    20,    33,    35,   125,
      34,    22,   116,    96,   127,    20,   116,    96,    96,    32,
      54,   113,   114,   116,   116,    20,   116,   116,   127,   116,
     125,    21,   116,    19,    19,    35,    19,    21,    21,    26,
     111,   111,    35,    26,    19,   126,    20,    20,   126,   111,
     127,   126,    19,    19,    23,   116,    19,    23,    23,    75,
     127,    80,    32,    19,   111,    35,    19,    21,   116,   116,
      19,    19,   126,   116,    24,    35,    26,   111,   111,    26,
      19,    35,    26,    24,   107,    19,    24,   107,    77,    75,
      20,    35,   116,    54,   114,    24,    19,   116,    35,    35,
      26,    96,   126,   127,    19,    19,   127,    35,   126,   116,
      96,    24,   107,    96,    20,    20,   116,   126,    19,   127,
      32,    57,    58,   107,   109,   110,    35,   126,   126,   116,
      23,    24,    35,    35,   126,    26,    23,    96,    23,   112,
     116,    19,    26,    24,   107,    35,   114,   116,    35,    23,
      32,   110,   126,    24,    24,    96,   126,   126,    26,   116,
      23,    19,    19,   116,    96,   126,    19,    35,    24,    96,
      96,    23,    26,    26,   127,    24,    23,    24,   107,    96,
      23,    23,    54,   127,   127,    96,    96,    23,   127,    23,
      23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 89 "parser.y"
    { (yyvsp[(2) - (3)].file_block)->appendObject( PackageManager::endOfFile() ); PackageManager::appendBlockToCodeGen( (yyvsp[(2) - (3)].file_block) ); ;}
    break;

  case 4:
#line 93 "parser.y"
    { (yyval.file_block) = new FileBlock(); ;}
    break;

  case 5:
#line 94 "parser.y"
    { (yyval.file_block) = (yyvsp[(1) - (2)].file_block); if( (yyvsp[(2) - (2)].prop) ) (yyvsp[(1) - (2)].file_block)->appendObject( (yyvsp[(2) - (2)].prop) ); ;}
    break;

  case 6:
#line 95 "parser.y"
    { (yyval.file_block) = (yyvsp[(1) - (2)].file_block); ;}
    break;

  case 7:
#line 96 "parser.y"
    { (yyval.file_block) = new FileBlock(); if( (yyvsp[(1) - (1)].prop) ) (yyval.file_block)->appendObject( (yyvsp[(1) - (1)].prop) ); ;}
    break;

  case 8:
#line 100 "parser.y"
    { (yyval.prop) = PackageManager::setCurrentPath( (yyvsp[(2) - (2)].expr_path) ); ;}
    break;

  case 9:
#line 101 "parser.y"
    { (yyval.prop) = PackageManager::setCurrentPath( NULL ); ;}
    break;

  case 10:
#line 102 "parser.y"
    { (yyval.prop) = PackageManager::addImportPath( (yyvsp[(2) - (2)].expr_path) ); ;}
    break;

  case 11:
#line 103 "parser.y"
    { (yyval.prop) = new AInstDeclareClass( (yyvsp[(2) - (7)].expr), (yyvsp[(3) - (7)].exp_type), (yyvsp[(4) - (7)].expr_list), (yyvsp[(6) - (7)].prop_list) ); ;}
    break;

  case 12:
#line 104 "parser.y"
    { (yyval.prop) = new AInstExternalClass( (yyvsp[(3) - (10)].expr), (yyvsp[(4) - (10)].exp_type), (yyvsp[(5) - (10)].expr_list), (yyvsp[(7) - (10)].prop_list), (yyvsp[(10) - (10)].expr) ); ;}
    break;

  case 13:
#line 105 "parser.y"
    { (yyval.prop) = new AInstDeclareFunc( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); ;}
    break;

  case 14:
#line 109 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); ;}
    break;

  case 15:
#line 110 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); if( (yyvsp[(2) - (2)].inst) ) (yyvsp[(1) - (2)].inst_list)->push_back( (yyvsp[(2) - (2)].inst) ); ;}
    break;

  case 16:
#line 111 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); ;}
    break;

  case 17:
#line 112 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); if( (yyvsp[(1) - (1)].inst) ) (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); ;}
    break;

  case 18:
#line 116 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); ;}
    break;

  case 19:
#line 117 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( (yyvsp[(1) - (1)].prop) ); ;}
    break;

  case 20:
#line 118 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); (yyvsp[(1) - (2)].prop_list)->push_back( (yyvsp[(2) - (2)].prop) ); ;}
    break;

  case 21:
#line 119 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); ;}
    break;

  case 22:
#line 123 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); ;}
    break;

  case 23:
#line 124 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( (yyvsp[(1) - (1)].prop) ); ;}
    break;

  case 24:
#line 125 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); (yyvsp[(1) - (2)].prop_list)->push_back( (yyvsp[(2) - (2)].prop) ); ;}
    break;

  case 25:
#line 126 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); ;}
    break;

  case 26:
#line 130 "parser.y"
    { (yyval.exp_type) = NULL; ;}
    break;

  case 27:
#line 131 "parser.y"
    { (yyval.exp_type) = (yyvsp[(2) - (2)].exp_type); ;}
    break;

  case 28:
#line 135 "parser.y"
    { (yyval.expr_list) = NULL; ;}
    break;

  case 29:
#line 136 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 30:
#line 137 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (3)].expr_list); (yyvsp[(1) - (3)].expr_list)->push_back( (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 31:
#line 141 "parser.y"
    { (yyval.prop) = (yyvsp[(2) - (2)].prop); (yyvsp[(2) - (2)].prop)->access = (yyvsp[(1) - (2)].tinfo)->type(); ;}
    break;

  case 32:
#line 142 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isStatic = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); ;}
    break;

  case 33:
#line 143 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isConst = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); ;}
    break;

  case 34:
#line 147 "parser.y"
    { (yyval.prop) = new AInstExternalProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 35:
#line 148 "parser.y"
    { (yyval.prop) = new AInstExternalProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 36:
#line 149 "parser.y"
    { (yyval.prop) = new AInstExternalMethod( (yyvsp[(2) - (9)].expr), (yyvsp[(7) - (9)].exp_type), (yyvsp[(4) - (9)].inst_list), (yyvsp[(9) - (9)].expr) ); ;}
    break;

  case 37:
#line 150 "parser.y"
    { (yyval.prop) = new AInstExternalGet( (yyvsp[(3) - (10)].expr), (yyvsp[(8) - (10)].exp_type), (yyvsp[(5) - (10)].inst_list), (yyvsp[(10) - (10)].expr), false ); ;}
    break;

  case 38:
#line 151 "parser.y"
    { (yyval.prop) = new AInstExternalGet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(11) - (11)].expr), true ); ;}
    break;

  case 39:
#line 152 "parser.y"
    { (yyval.prop) = new AInstExternalSet( (yyvsp[(3) - (10)].expr), (yyvsp[(8) - (10)].exp_type), (yyvsp[(5) - (10)].inst_list), (yyvsp[(10) - (10)].expr) ); ;}
    break;

  case 40:
#line 153 "parser.y"
    { (yyval.prop) = new AInstExternalMethod( (yyvsp[(2) - (5)].expr), NULL, (yyvsp[(4) - (5)].inst_list), (yyvsp[(2) - (5)].expr) ); ;}
    break;

  case 41:
#line 157 "parser.y"
    { (yyval.prop) = (yyvsp[(2) - (2)].prop); (yyvsp[(2) - (2)].prop)->access = (yyvsp[(1) - (2)].tinfo)->type(); ;}
    break;

  case 42:
#line 158 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isStatic = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); ;}
    break;

  case 43:
#line 162 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type), NULL ); ;}
    break;

  case 44:
#line 163 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 45:
#line 164 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 46:
#line 165 "parser.y"
    {  (yyval.prop) = new AInstDeclareMultProp( (yyvsp[(2) - (2)].prop_list) ); ;}
    break;

  case 47:
#line 166 "parser.y"
    { (yyval.prop) = new AInstDeclareMethod( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); ;}
    break;

  case 48:
#line 167 "parser.y"
    { (yyval.prop) = new AInstDeclareGet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(10) - (11)].inst_list) ); ;}
    break;

  case 49:
#line 168 "parser.y"
    { (yyval.prop) = new AInstDeclareSet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(10) - (11)].inst_list) ); ;}
    break;

  case 50:
#line 169 "parser.y"
    { (yyval.prop) = new AInstDeclareMethod( (yyvsp[(2) - (8)].expr), NULL, (yyvsp[(4) - (8)].inst_list), (yyvsp[(7) - (8)].inst_list) ); ;}
    break;

  case 54:
#line 177 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type), NULL ) ); ;}
    break;

  case 55:
#line 178 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ) ); ;}
    break;

  case 56:
#line 179 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (5)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].exp_type), NULL ) ); ;}
    break;

  case 57:
#line 180 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (7)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].expr) ) ); ;}
    break;

  case 58:
#line 185 "parser.y"
    { (yyval.inst) = new AInstruction( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 59:
#line 186 "parser.y"
    { (yyval.inst) = new AInstDeclareFunc( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); ;}
    break;

  case 60:
#line 187 "parser.y"
    { (yyval.inst) = new AInstElseif( (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].inst) ); ;}
    break;

  case 61:
#line 188 "parser.y"
    { (yyval.inst) = new AInstElseif( (yyvsp[(4) - (8)].expr), (yyvsp[(7) - (8)].inst_list) ); ;}
    break;

  case 62:
#line 189 "parser.y"
    { (yyval.inst) = new AInstElse( (yyvsp[(2) - (2)].inst) ); ;}
    break;

  case 63:
#line 190 "parser.y"
    { (yyval.inst) = new AInstElse( (yyvsp[(3) - (4)].inst_list) ); ;}
    break;

  case 64:
#line 191 "parser.y"
    { (yyval.inst) = new AInstIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].inst) ); ;}
    break;

  case 65:
#line 192 "parser.y"
    { (yyval.inst) = new AInstIf( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); ;}
    break;

  case 66:
#line 193 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (9)].inst), (yyvsp[(5) - (9)].inst), (yyvsp[(7) - (9)].inst), (yyvsp[(9) - (9)].inst) ); ;}
    break;

  case 67:
#line 194 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (11)].inst), (yyvsp[(5) - (11)].inst), (yyvsp[(7) - (11)].inst), (yyvsp[(10) - (11)].inst_list) ); ;}
    break;

  case 68:
#line 195 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (7)].inst), (yyvsp[(5) - (7)].expr), (yyvsp[(7) - (7)].inst) ); ;}
    break;

  case 69:
#line 196 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (9)].inst), (yyvsp[(5) - (9)].expr), (yyvsp[(8) - (9)].inst_list) ); ;}
    break;

  case 70:
#line 197 "parser.y"
    { (yyval.inst) = new AInstWhile( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].inst) ); ;}
    break;

  case 71:
#line 198 "parser.y"
    { (yyval.inst) = new AInstWhile( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); ;}
    break;

  case 72:
#line 199 "parser.y"
    { (yyval.inst) = new AInstDo( (yyvsp[(6) - (7)].expr), (yyvsp[(2) - (7)].inst) ); ;}
    break;

  case 73:
#line 200 "parser.y"
    { (yyval.inst) = new AInstDo( (yyvsp[(7) - (8)].expr), (yyvsp[(3) - (8)].inst_list) ); ;}
    break;

  case 74:
#line 201 "parser.y"
    { (yyval.inst) = new AInstTryCatch( (yyvsp[(3) - (11)].inst_list), (yyvsp[(7) - (11)].inst), (yyvsp[(10) - (11)].inst_list) ); ;}
    break;

  case 75:
#line 202 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 76:
#line 203 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type), NULL ); ;}
    break;

  case 77:
#line 204 "parser.y"
    { (yyval.inst) = new AInstDeclareMultVar( (yyvsp[(2) - (2)].prop_list) ); ;}
    break;

  case 78:
#line 205 "parser.y"
    { (yyval.inst) = new AInstDelete( (yyvsp[(2) - (2)].expr_path) ); ;}
    break;

  case 79:
#line 206 "parser.y"
    { (yyval.inst) = new AInstSwitch( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); ;}
    break;

  case 80:
#line 207 "parser.y"
    { (yyval.inst) = new AInstBreak(); ;}
    break;

  case 81:
#line 208 "parser.y"
    { (yyval.inst) = new AInstContinue(); ;}
    break;

  case 82:
#line 209 "parser.y"
    { (yyval.inst) = new AInstReturn( NULL ); ;}
    break;

  case 83:
#line 210 "parser.y"
    { (yyval.inst) = new AInstReturn( (yyvsp[(2) - (2)].expr) ); ;}
    break;

  case 84:
#line 211 "parser.y"
    {  (yyval.inst) = new AInstAssign( (yyvsp[(1) - (3)].expr_path), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 85:
#line 212 "parser.y"
    { (yyval.inst) = new AInstSuperCall( (yyvsp[(1) - (4)].tinfo), (yyvsp[(3) - (4)].expr_list) ); ;}
    break;

  case 86:
#line 216 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ) ); ;}
    break;

  case 87:
#line 217 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type), NULL ) ); ;}
    break;

  case 88:
#line 218 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (7)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].expr) ) ); ;}
    break;

  case 89:
#line 219 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (5)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].exp_type), NULL ) ); ;}
    break;

  case 90:
#line 224 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); ;}
    break;

  case 91:
#line 225 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); ;}
    break;

  case 92:
#line 226 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); (yyvsp[(1) - (2)].inst_list)->push_back( (yyvsp[(2) - (2)].inst) ); ;}
    break;

  case 93:
#line 230 "parser.y"
    { (yyval.inst) = (yyvsp[(1) - (1)].inst); ;}
    break;

  case 94:
#line 231 "parser.y"
    { (yyval.inst) = new AInstCase( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 95:
#line 232 "parser.y"
    { (yyval.inst) = new AInstDefault(); ;}
    break;

  case 96:
#line 235 "parser.y"
    { (yyval.inst_list) = NULL; ;}
    break;

  case 97:
#line 236 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); ;}
    break;

  case 98:
#line 237 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (3)].inst_list); (yyvsp[(1) - (3)].inst_list)->push_back( (yyvsp[(3) - (3)].inst) ); ;}
    break;

  case 99:
#line 241 "parser.y"
    { (yyval.inst) = new AInstDeclareArg( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type), NULL ); ;}
    break;

  case 100:
#line 242 "parser.y"
    { (yyval.inst) = new AInstDeclareArg( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 101:
#line 246 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type), NULL ); ;}
    break;

  case 102:
#line 250 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); ;}
    break;

  case 103:
#line 251 "parser.y"
    { (yyval.inst) = new AInstruction( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 110:
#line 259 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 111:
#line 260 "parser.y"
    { (yyval.expr) = new AExpOperation( (yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 112:
#line 264 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); ;}
    break;

  case 113:
#line 265 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); ;}
    break;

  case 114:
#line 266 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); ;}
    break;

  case 115:
#line 267 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); ;}
    break;

  case 116:
#line 268 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].tinfo), false ); ;}
    break;

  case 117:
#line 269 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); ;}
    break;

  case 118:
#line 270 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].tinfo), false ); ;}
    break;

  case 119:
#line 271 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); ;}
    break;

  case 120:
#line 273 "parser.y"
    { (yyval.expr) = new AExpParent( (yyvsp[(2) - (3)].expr) ); ;}
    break;

  case 121:
#line 274 "parser.y"
    { (yyval.expr) = new AExpNewArray( NULL, (yyvsp[(2) - (4)].expr) ); ;}
    break;

  case 122:
#line 275 "parser.y"
    { (yyval.expr) = new AExpIfast( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); ;}
    break;

  case 123:
#line 276 "parser.y"
    {  (yyval.expr) = new AExpAssign( (yyvsp[(1) - (3)].expr_path), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 124:
#line 277 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr_path); ;}
    break;

  case 148:
#line 286 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (1)].expr_path); ;}
    break;

  case 149:
#line 287 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); ;}
    break;

  case 150:
#line 291 "parser.y"
    { (yyval.expr_path) = new AExpSetPath( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 151:
#line 292 "parser.y"
    { (yyval.expr_path) = new AExpSetItem( (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr) ); ;}
    break;

  case 152:
#line 296 "parser.y"
    { (yyval.expr_path) = new AExpGetPath( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 153:
#line 297 "parser.y"
    { (yyval.expr_path) = new AExpSuper( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 154:
#line 298 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); ;}
    break;

  case 155:
#line 302 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (1)].expr_path); ;}
    break;

  case 156:
#line 303 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); ;}
    break;

  case 157:
#line 304 "parser.y"
    { (yyval.expr_path) = new AExpNewArray( (yyvsp[(2) - (3)].expr_list), NULL ); ;}
    break;

  case 158:
#line 305 "parser.y"
    { (yyval.expr_path) = new AExpNewObject( (yyvsp[(2) - (3)].expr_list) ); ;}
    break;

  case 159:
#line 309 "parser.y"
    { (yyval.expr_path) = new AExpGetPath( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 160:
#line 310 "parser.y"
    { (yyval.expr_path) = new AExpSuper( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 161:
#line 313 "parser.y"
    { (yyval.expr_path) = new AExpNew( (yyvsp[(2) - (5)].expr_path), (yyvsp[(4) - (5)].expr_list) ); ;}
    break;

  case 162:
#line 314 "parser.y"
    { (yyval.expr_path) = new AExpCallFunc( (yyvsp[(1) - (4)].expr_path), (yyvsp[(3) - (4)].expr_list) ); ;}
    break;

  case 163:
#line 315 "parser.y"
    { (yyval.expr_path) = new CompilerGet( (yyvsp[(3) - (4)].expr_list) ); ;}
    break;

  case 164:
#line 316 "parser.y"
    { (yyval.expr_path) = new CompilerSet( (yyvsp[(3) - (4)].expr_list) ); ;}
    break;

  case 165:
#line 317 "parser.y"
    { (yyval.expr_path) = new AExpGetItem( (yyvsp[(1) - (4)].expr_path), (yyvsp[(3) - (4)].expr) ); ;}
    break;

  case 166:
#line 318 "parser.y"
    { (yyval.expr_path) = new AExpGetItem( (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr) ); ;}
    break;

  case 167:
#line 322 "parser.y"
    { (yyval.expr_list) = NULL; ;}
    break;

  case 168:
#line 323 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( new AExpObjectProp( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ) ); ;}
    break;

  case 169:
#line 324 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (5)].expr_list); (yyvsp[(1) - (5)].expr_list)->push_back( new AExpObjectProp( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ) ); ;}
    break;

  case 170:
#line 328 "parser.y"
    { (yyval.expr_list) = NULL; ;}
    break;

  case 171:
#line 329 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 172:
#line 330 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (3)].expr_list); (yyvsp[(1) - (3)].expr_list)->push_back( (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 173:
#line 334 "parser.y"
    { (yyval.exp_type) = new ATypage( (yyvsp[(1) - (1)].tinfo), false ); ;}
    break;

  case 174:
#line 335 "parser.y"
    { (yyval.exp_type) = new ATypage( (yyvsp[(1) - (3)].tinfo), true ); ;}
    break;

  case 175:
#line 339 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 176:
#line 340 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 177:
#line 341 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 178:
#line 342 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 179:
#line 343 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 180:
#line 344 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 181:
#line 345 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 182:
#line 346 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); ;}
    break;

  case 183:
#line 347 "parser.y"
    { (yyval.expr) = new CompilerName( (yyvsp[(3) - (4)].expr_path) ); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3272 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 350 "parser.y"


