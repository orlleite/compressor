/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 23 "parser.y"

	#include <iostream>
	#include "types.hpp"
	#include "expressions.hpp"
	#include "instructions.hpp"
	#include "blocks.hpp"
	#include "workspace.hpp"

	extern int yylex( void );
	
	void yyerror(const char *s) { printf("ERROR: %s\n", s); };

/* Line 371 of yacc.c  */
#line 81 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 237 "parser.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 265 "parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3732

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNRULES -- Number of states.  */
#define YYNSTATES  492

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    12,    15,    17,    20,
      22,    25,    33,    39,    50,    61,    69,    70,    73,    76,
      78,    79,    81,    84,    87,    88,    90,    93,    96,    97,
      99,   102,   105,   106,   109,   110,   113,   117,   120,   124,
     129,   136,   143,   146,   157,   169,   181,   190,   193,   197,
     201,   208,   215,   225,   236,   248,   259,   265,   274,   284,
     294,   296,   298,   300,   304,   310,   316,   324,   326,   337,
     344,   353,   356,   361,   367,   375,   385,   397,   405,   415,
     421,   429,   437,   446,   458,   465,   472,   477,   480,   483,
     491,   493,   495,   497,   500,   504,   509,   515,   519,   527,
     535,   541,   551,   553,   556,   559,   561,   565,   568,   569,
     571,   575,   579,   585,   590,   597,   599,   601,   603,   605,
     607,   609,   611,   613,   617,   620,   623,   626,   629,   632,
     635,   638,   641,   645,   650,   656,   660,   662,   664,   666,
     668,   670,   672,   674,   676,   678,   680,   682,   684,   686,
     688,   690,   692,   694,   696,   698,   700,   702,   704,   706,
     708,   710,   714,   716,   721,   723,   725,   729,   731,   735,
     739,   743,   745,   747,   753,   758,   763,   768,   773,   778,
     779,   783,   789,   790,   792,   796,   798,   802,   804,   806,
     808,   810,   812,   814,   816,   818,   820
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      95,     0,    -1,    -1,    95,    96,     0,    -1,    -1,    96,
      97,    -1,    96,    33,    -1,    97,    -1,    40,   126,    -1,
      40,    -1,    39,   126,    -1,    84,   132,   102,   103,    24,
      99,    23,    -1,    26,   132,    24,   101,    23,    -1,    90,
      84,   132,   102,   103,    24,   100,    23,    27,   132,    -1,
      83,   132,    20,   116,    19,    36,   131,    24,    98,    23,
      -1,    90,    55,   132,    36,   131,    27,   121,    -1,    -1,
      98,   111,    -1,    98,    33,    -1,   111,    -1,    -1,   104,
      -1,    99,   104,    -1,    99,    33,    -1,    -1,   106,    -1,
     100,   106,    -1,   100,    33,    -1,    -1,   108,    -1,    99,
     108,    -1,    99,    33,    -1,    -1,    85,   131,    -1,    -1,
      25,   132,    -1,   103,    34,   132,    -1,   109,   105,    -1,
     109,    72,   105,    -1,    55,   132,    36,   131,    -1,    55,
     132,    36,   131,    27,   121,    -1,    38,   132,    36,   131,
      27,   121,    -1,    55,   110,    -1,    83,   132,    20,   116,
      19,    36,   131,    24,    98,    23,    -1,    50,    83,   132,
      20,   116,    19,    36,   131,    24,    98,    23,    -1,    51,
      83,   132,    20,   116,    19,    36,   131,    24,    98,    23,
      -1,    83,   132,    20,   116,    19,    24,    98,    23,    -1,
     109,   107,    -1,   109,    72,   107,    -1,   109,    38,   107,
      -1,    55,   132,    36,   131,    27,   132,    -1,    38,   132,
      36,   131,    27,   132,    -1,    83,   132,    20,   116,    19,
      36,   131,    27,   132,    -1,    50,    83,   132,    20,   116,
      19,    36,   131,    27,   132,    -1,    50,    83,   132,    20,
     116,    19,    36,   131,    27,    55,   132,    -1,    51,    83,
     132,    20,   116,    19,    36,   131,    27,   132,    -1,    83,
     132,    20,   116,    19,    -1,    69,    83,   132,    20,   116,
      19,    36,   131,    -1,    69,    50,    83,   132,    20,   116,
      19,    36,   131,    -1,    69,    51,    83,   132,    20,   116,
      19,    36,   131,    -1,    70,    -1,    69,    -1,    71,    -1,
     132,    36,   131,    -1,   132,    36,   131,    27,   121,    -1,
     110,    34,   132,    36,   131,    -1,   110,    34,   132,    36,
     131,    27,   121,    -1,   121,    -1,    83,   132,    20,   116,
      19,    36,   131,    24,    98,    23,    -1,    75,    74,    20,
     121,    19,   111,    -1,    75,    74,    20,   121,    19,    24,
      98,    23,    -1,    75,   111,    -1,    75,    24,    98,    23,
      -1,    74,    20,   121,    19,   111,    -1,    74,    20,   121,
      19,    24,    98,    23,    -1,    80,    20,   119,    33,   119,
      33,   119,    19,   111,    -1,    80,    20,   119,    33,   119,
      33,   119,    19,    24,    98,    23,    -1,    80,    20,   118,
      81,   121,    19,   111,    -1,    80,    20,   118,    81,   121,
      19,    24,    98,    23,    -1,    76,    20,   121,    19,   111,
      -1,    76,    20,   121,    19,    24,    98,    23,    -1,    79,
     111,    33,    76,    20,   121,    19,    -1,    79,    24,    98,
      23,    76,    20,   121,    19,    -1,    77,    24,    98,    23,
      78,    20,   117,    19,    24,    98,    23,    -1,    55,   132,
      36,   131,    27,   121,    -1,    55,   132,    36,   131,    27,
     113,    -1,    55,   132,    36,   131,    -1,    55,   112,    -1,
      73,   127,    -1,    82,    20,   121,    19,    24,   114,    23,
      -1,    57,    -1,    56,    -1,    61,    -1,    61,   121,    -1,
     124,   120,   121,    -1,    63,    20,   130,    19,    -1,   132,
      36,   131,    27,   121,    -1,   132,    36,   131,    -1,   112,
      34,   132,    36,   131,    27,   121,    -1,   112,    34,   132,
      36,   131,    27,   113,    -1,   112,    34,   132,    36,   131,
      -1,    83,    20,   116,    19,    36,   131,    24,    98,    23,
      -1,   115,    -1,   114,    33,    -1,   114,   115,    -1,   111,
      -1,    58,   121,    36,    -1,    59,    36,    -1,    -1,   117,
      -1,   116,    34,   117,    -1,   132,    36,   131,    -1,   132,
      36,   131,    27,   121,    -1,    55,   132,    36,   131,    -1,
      55,   132,    36,   131,    27,   121,    -1,   121,    -1,    27,
      -1,    31,    -1,    29,    -1,    30,    -1,    28,    -1,    32,
      -1,   122,    -1,   121,   123,   121,    -1,     9,   121,    -1,
      10,   121,    -1,    49,   121,    -1,    16,   121,    -1,   121,
      14,    -1,    14,   121,    -1,   121,    15,    -1,    15,   121,
      -1,    20,   121,    19,    -1,    62,   132,    22,    21,    -1,
     121,    37,   121,    36,   121,    -1,   124,   120,   121,    -1,
     127,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    12,    -1,
      11,    -1,    13,    -1,    41,    -1,    42,    -1,    43,    -1,
      44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      49,    -1,    17,    -1,    18,    -1,    52,    -1,   125,    -1,
     127,    35,   125,    -1,   132,    -1,   132,    22,   121,    21,
      -1,   132,    -1,    63,    -1,   126,    35,   126,    -1,   128,
      -1,   127,    35,   128,    -1,    22,   130,    21,    -1,    24,
     129,    23,    -1,   132,    -1,    63,    -1,    62,   128,    20,
     130,    19,    -1,   128,    20,   130,    19,    -1,    87,    20,
     130,    19,    -1,    88,    20,   130,    19,    -1,   128,    22,
     121,    21,    -1,   132,    22,   121,    21,    -1,    -1,   132,
      36,   121,    -1,   129,    34,   132,    36,   121,    -1,    -1,
     121,    -1,   130,    34,   121,    -1,    67,    -1,    67,    22,
      21,    -1,    93,    -1,    65,    -1,    67,    -1,    66,    -1,
      89,    -1,    54,    -1,    53,    -1,    60,    -1,    64,    -1,
      86,    20,   126,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    89,    93,    94,    95,    96,   100,   101,
     102,   103,   104,   105,   106,   107,   111,   112,   113,   114,
     118,   119,   120,   121,   125,   126,   127,   128,   132,   133,
     134,   135,   139,   140,   144,   145,   146,   150,   151,   155,
     156,   157,   158,   159,   160,   161,   162,   166,   167,   168,
     172,   173,   174,   175,   176,   177,   178,   182,   183,   184,
     188,   188,   188,   192,   193,   194,   195,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   232,   233,   234,   235,
     236,   240,   244,   245,   246,   250,   251,   252,   255,   256,
     257,   261,   262,   266,   270,   271,   275,   275,   275,   275,
     275,   275,   279,   280,   284,   285,   286,   287,   288,   289,
     290,   291,   293,   294,   295,   296,   297,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     306,   307,   311,   312,   316,   317,   318,   322,   323,   324,
     325,   329,   330,   333,   334,   335,   336,   337,   338,   342,
     343,   344,   348,   349,   350,   354,   355,   356,   360,   361,
     362,   363,   364,   365,   366,   367,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "TEQ", "TNE", "TLT", "TLE",
  "TGT", "TGE", "TPLUS", "TMINUS", "TMULT", "TDIVIDE", "TMODULUS",
  "TINCREMENT", "TDECREMENT", "TNOT", "TEQA", "TNEA", "TRPAREN", "TLPAREN",
  "TRBRACKET", "TLBRACKET", "TRBRACE", "TLBRACE", "TIMPLEMENTS",
  "TINTERFACE", "TASSIGN", "TASSIGN_PLUS", "TASSIGN_MINUS",
  "TASSIGN_MULTIPLY", "TASSIGN_DIVIDE", "TASSIGN_BOR", "TSEMICOLON",
  "TCOMMA", "TDOT", "TCOLON", "TQUESTION", "TCONST", "TIMPORT", "TPACKAGE",
  "TOR", "TAND", "TBXOR", "TLSHIFT", "TRSHIFT", "TZFILL", "TBOR", "TBAND",
  "TBNOT", "TGET", "TSET", "TINSTANCEOF", "TTRUE", "TFALSE", "TVAR",
  "TCONTINUE", "TBREAK", "TCASE", "TDEFAULT", "TNULL", "TRETURN", "TNEW",
  "TSUPER", "TTHIS", "TNUMBER", "TSTRING", "TNAME", "TCOMPVAR", "TPUBLIC",
  "TPRIVATE", "TPROTECTED", "TSTATIC", "TDELETE", "TIF", "TELSE", "TWHILE",
  "TTRY", "TCATCH", "TDO", "TFOR", "TIN", "TSWITCH", "TFUNCTION", "TCLASS",
  "TEXTENDS", "TCOMPNAME", "TCOMPGET", "TCOMPSET", "TREGEX", "TEXTERNAL",
  "TCUSTOMIZE", "TEXPORT", "TVOID", "$accept", "input", "file_block",
  "object", "block", "class_block", "external_class_block",
  "interface_block", "extends", "implements", "property", "proper2",
  "external_property", "external_proper2", "interface_property", "access",
  "props_declaration", "instruction", "vars_declaration",
  "anonymous_function", "switch_block", "switch_inst", "declare_args",
  "declare_arg", "forin_var", "for_args", "assigning", "expression",
  "expr2", "comparing", "set_path", "set_obj", "package_path", "get_path",
  "get_obj", "object_props", "call_args", "typage", "identifier", YY_NULL
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
     345,   346,   347,   348
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   101,   102,   102,   103,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     109,   109,   109,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     112,   113,   114,   114,   114,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   130,   130,   130,   131,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     1,     2,     1,
       2,     7,     5,    10,    10,     7,     0,     2,     2,     1,
       0,     1,     2,     2,     0,     1,     2,     2,     0,     1,
       2,     2,     0,     2,     0,     2,     3,     2,     3,     4,
       6,     6,     2,    10,    11,    11,     8,     2,     3,     3,
       6,     6,     9,    10,    11,    10,     5,     8,     9,     9,
       1,     1,     1,     3,     5,     5,     7,     1,    10,     6,
       8,     2,     4,     5,     7,     9,    11,     7,     9,     5,
       7,     7,     8,    11,     6,     6,     4,     2,     2,     7,
       1,     1,     1,     2,     3,     4,     5,     3,     7,     7,
       5,     9,     1,     2,     2,     1,     3,     2,     0,     1,
       3,     3,     5,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     4,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     3,     1,     3,     3,
       3,     1,     1,     5,     4,     4,     4,     4,     4,     0,
       3,     5,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     1,     0,     0,     9,     0,     0,     0,     0,
       7,   193,   192,   194,   195,   188,   190,   189,     0,   191,
       0,   165,    10,   164,     8,     0,    32,     0,     0,     3,
       6,     5,     0,    20,     0,   108,     0,    34,     0,    32,
       0,    61,    60,    62,     0,     0,    21,    29,     0,   166,
       0,   109,     0,   185,   187,    33,     0,     0,     0,    34,
     196,     0,     0,     0,    23,    22,    30,    12,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,    35,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    38,     0,     0,   110,   111,   186,    61,     0,
      36,     0,    24,     0,     0,   108,     0,     0,     0,     0,
       0,   108,     0,     0,    11,    23,     0,     0,     0,     0,
       0,     0,   182,   179,     0,     0,   172,     0,     0,    15,
     122,     0,   160,   136,   167,   171,     0,    25,     0,   108,
     108,     0,     0,   108,   108,     0,    39,     0,    16,   112,
     124,   125,   129,   131,   127,     0,   183,     0,     0,     0,
     126,     0,     0,   171,   182,   182,   137,   138,   139,   140,
     141,   142,   143,   144,   146,   145,   147,   128,   130,   157,
     158,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   159,     0,   116,   120,   118,   119,   117,   121,     0,
       0,   182,     0,     0,     0,    27,    26,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    90,    92,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    67,
       0,   132,   169,     0,   170,     0,     0,   171,   182,     0,
       0,     0,     0,   123,   135,   161,   168,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    48,     0,     0,
       0,     0,    41,     0,     0,    65,    40,    16,     0,    87,
       0,    93,   182,    88,     0,    16,     0,    71,     0,    16,
      16,     0,     0,     0,     0,    14,    18,    17,     0,   184,
       0,   180,     0,     0,   133,     0,   175,   176,     0,   174,
     177,   178,    13,     0,     0,     0,     0,   108,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,   108,    94,     0,   173,   178,   134,     0,
     108,   108,     0,     0,    58,    59,     0,     0,    66,    46,
      16,     0,    86,    95,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,    56,    16,    16,     0,     0,     0,    16,    73,     0,
      16,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    50,     0,     0,     0,    43,   100,
       0,    85,    84,     0,    16,    69,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,   105,     0,   102,     0,
       0,     0,     0,    44,    45,     0,   108,    74,     0,    80,
       0,     0,    81,     0,    16,    77,     0,     0,     0,   107,
      89,   103,   104,     0,     0,     0,     0,    99,    98,     0,
      70,     0,    82,   114,     0,     0,     0,   106,    16,     0,
       0,    52,     0,    16,    78,    16,    75,     0,     0,    53,
      55,     0,     0,     0,    68,    54,     0,    83,    76,    16,
       0,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     9,    10,   237,    44,   136,    45,    37,    57,
      46,    74,   137,   213,    47,    48,    90,   238,   279,   411,
     427,   428,    50,    51,   339,   340,   199,   239,   130,   192,
     131,   132,    22,   133,   134,   158,   157,    55,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -361
static const yytype_int16 yypact[] =
{
    -361,    71,  -361,  2861,   353,   353,  2861,  2861,   -29,    10,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,     3,  -361,
      34,  -361,   -18,  -361,   -18,    17,    22,  2861,  2861,  -361,
    -361,  -361,   353,    82,   353,  2861,   -46,   104,    98,    22,
      -5,   -31,  -361,  -361,   166,   115,  -361,  -361,   -16,   -18,
      -1,  -361,   103,   143,  -361,  -361,  2861,    30,   -46,   104,
    -361,    77,   101,  2861,   164,  -361,  -361,  -361,  2861,   111,
     120,  2861,   118,  2861,  -361,   169,  2861,   -46,   195,  -361,
     177,  2861,   207,    67,  2861,  2861,   211,   203,  2861,  2861,
     209,   205,  -361,   224,   -46,  -361,   229,  -361,  -361,    43,
    -361,  3067,   177,   240,   243,  2861,   -46,   245,   246,  2861,
     -46,  2861,   247,  3067,  -361,  -361,  3067,  3067,  3067,  3067,
    3067,  3067,  3067,  2861,  3067,   255,  -361,   248,   254,  3680,
    -361,   323,  -361,   241,    55,   361,    46,  -361,    94,  2861,
    2861,    40,   252,  2861,  2861,   249,   136,    53,  2241,  3680,
     496,   496,  3680,  3680,  3680,  3154,  3680,    62,    -7,   250,
    3680,   255,   142,   258,  3067,  3067,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  3067,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  3067,  -361,  -361,  -361,  -361,  -361,  -361,  3067,
     255,  3067,  3067,  3067,   256,  -361,  -361,  3059,   198,   201,
    2861,   147,  2861,  -361,    61,    65,   253,  3067,    69,    85,
     -46,  3067,   204,  2861,  -361,  -361,  3067,   271,   126,   272,
    2322,   275,   273,  2403,   276,   279,  2861,   783,  -361,  3680,
     323,  -361,  -361,  3067,  -361,  2861,  3067,   278,  3067,   548,
      90,    99,  3171,  3680,  3680,  -361,    55,   109,  3221,  3271,
    2861,  2861,  -361,   269,  2861,  2861,   270,  -361,   287,   274,
     277,   -46,  3680,   280,   288,   284,  3292,  2241,   -46,   291,
     292,  3680,  3067,   294,  3067,  2160,   307,  -361,  3067,  2241,
    2160,   298,  2889,  3067,   312,  -361,  -361,  -361,  3067,  3680,
     297,  3680,  3067,   138,  -361,  3342,  -361,  -361,  3067,  -361,
    -361,   488,  -361,   -46,   314,   319,   -46,  2861,   -46,   -46,
    -361,   -46,   -46,  3067,   864,   334,  2861,   -46,   140,   255,
    3363,   945,   223,  3067,  3413,  1026,  1107,   236,  2861,   286,
     326,  3680,  3430,  2861,  3680,  3067,  -361,  -361,  3680,   342,
    2861,  2861,   343,   148,  -361,  -361,   347,   348,  3680,  -361,
    2241,   339,   149,  -361,  2484,  -361,  3480,  2565,   300,   303,
     356,   349,  3067,  2948,   362,   162,  3680,  2861,   187,   189,
    2861,   363,  2241,  2241,  1188,   -46,  3007,  2160,  -361,  2646,
    2160,  -361,   378,   381,  3067,   -46,  3497,  2861,   369,  1269,
     368,  -361,   374,   379,  -361,   -46,  1350,  1431,  -361,   394,
     385,  -361,  3547,  1512,  2160,  -361,  1593,  2861,  3067,  3597,
     395,  2727,   388,  2948,  3067,   390,  -361,   702,  -361,   -46,
     -46,   -46,   401,  -361,  -361,  3007,  2861,  -361,  1674,  -361,
     410,  3614,  -361,  3067,  2160,  -361,   -46,   411,  3664,  -361,
    -361,  -361,  -361,   407,   408,   413,  2861,  -361,  3680,   192,
    -361,   414,  -361,  3680,  1755,   395,  2808,  -361,  2241,   520,
    2861,  -361,   398,  2241,  -361,  2160,  -361,  1836,  2861,  -361,
    -361,   -46,  1917,  1998,  -361,  -361,   420,  -361,  -361,  2241,
    2079,  -361
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -361,  -361,  -361,   428,    13,   370,  -361,  -361,   409,   392,
     -37,   377,   316,   -86,   412,   -90,  -361,  -189,  -361,    19,
    -361,    28,   -13,   -68,  -361,  -360,   218,   244,  -361,  -361,
     264,   259,     6,   232,  -110,  -361,  -159,   -49,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -180
static const yytype_int16 yytable[] =
{
      20,    23,    23,    25,    26,   250,   251,    65,    95,    82,
      29,    24,   138,   398,    60,   162,   244,    34,    75,    61,
      62,    53,    68,    32,    38,    39,    27,   245,    96,    23,
      34,    23,    52,    76,    69,    70,     3,    35,    40,    71,
      49,   287,   257,    30,   291,   112,   138,    54,   297,     4,
       5,   162,    63,    79,    80,    28,    72,   142,    33,   216,
      86,   146,    65,   447,    81,    87,   114,    73,    91,   204,
      93,     2,   222,    52,    76,   201,   115,   202,   100,   205,
     269,   103,   104,   242,   270,   107,   108,    76,   273,   303,
     256,   102,   141,     6,     7,    76,   243,     3,   147,    76,
       8,    81,    52,    76,   274,   -28,   145,    36,    52,   306,
       4,     5,    98,    42,    43,    98,    42,    43,   307,    76,
     159,   262,   163,   328,   243,   267,   214,   215,   309,    56,
     218,   219,   207,   243,    58,   297,    52,    52,    67,    77,
      52,    52,   297,   243,   208,   209,   297,   297,   122,   210,
     123,    41,    42,    43,     6,     7,    68,   346,   247,   363,
      84,     8,   248,   221,   202,    78,   211,   381,    69,    70,
     -63,   275,   243,    71,   243,   388,   386,   212,   391,    11,
      12,   400,    76,   -97,    85,   261,    13,   -31,   161,   126,
      14,    15,    16,    17,    88,   297,    76,   208,   209,    64,
     415,    73,   210,    89,   263,    94,   402,   266,   403,   268,
     426,   472,    18,   127,   128,    19,    97,   297,   297,   256,
     280,    76,   320,    76,   297,   247,    76,   297,   277,   325,
     212,   105,   445,   294,   101,    41,    42,    43,   426,   106,
     278,   110,   300,   109,   111,   203,    98,    42,    43,   297,
    -162,  -162,  -162,  -162,  -162,  -162,   113,   312,   263,   246,
     139,   314,   315,   140,   349,   143,   144,   352,   164,   354,
     355,   148,   356,   357,   165,   297,   200,   476,   362,   217,
     249,   264,   332,   260,   265,   220,   246,   332,   297,   271,
     324,   282,   284,   297,   297,   288,   292,   289,   331,   293,
     302,   297,   335,   336,   353,   313,   316,   317,    11,    12,
     318,   323,   370,   319,    52,    13,   321,   161,   126,    14,
      15,    16,    17,   361,   322,   326,   247,   333,   327,   329,
     375,   337,   343,   345,   350,   371,   409,   378,   379,   351,
      52,    18,   127,   128,    19,   129,   420,    52,    52,   440,
     193,   194,   195,   196,   197,   198,   432,   149,   360,   373,
     150,   151,   152,   153,   154,   155,   156,   372,   160,   377,
     380,   382,   383,   384,   401,   385,   394,   404,   392,   393,
     453,   454,   455,   203,   332,   395,   399,   332,  -162,  -162,
    -162,  -162,  -162,  -162,   422,   406,   407,   465,   417,   405,
     413,   418,   423,   416,   429,   436,    11,    12,   156,   156,
     430,   332,   240,    13,    52,   431,    21,    14,    15,    16,
      17,   435,   443,   459,   446,   252,   449,   438,   456,   461,
     466,   468,   486,    52,   481,   469,   253,    31,   473,    18,
     470,   332,    19,   254,   489,   156,   258,   259,    59,    92,
      99,    83,   206,   471,   457,   452,    66,   464,   298,   255,
     283,   272,     0,     0,     0,   276,   479,   480,     0,     0,
     281,     0,   332,     0,     0,   485,     0,     0,     0,     0,
       0,   477,     0,     0,     0,     0,   482,   299,   483,     0,
     301,     0,   156,   305,   240,     0,     0,   240,     0,     0,
       0,   240,   490,     0,     0,     0,     0,   174,   175,   176,
     177,   178,     0,   179,   180,  -163,  -163,  -163,  -163,  -163,
    -163,     0,     0,     0,     0,     0,   156,     0,   330,     0,
       0,     0,   334,   181,     0,     0,   341,   342,     0,     0,
       0,   240,   344,     0,     0,   190,   305,     0,   191,   240,
       0,     0,   348,   240,   240,     0,     0,   116,   117,     0,
       0,     0,   118,   119,   120,     0,     0,   358,   121,   304,
     122,     0,   123,    11,    12,   478,     0,   366,     0,     0,
      13,     0,     0,     0,    14,    15,    16,    17,   240,   376,
       0,     0,     0,     0,     0,   240,     0,   124,     0,   240,
     240,    11,    12,     0,     0,     0,    18,     0,    13,    19,
     125,   126,    14,    15,    16,    17,   396,   341,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     0,   240,     0,
     412,   240,     0,     0,    18,   127,   128,    19,   419,     0,
       0,     0,     0,     0,     0,     0,   240,   240,   240,     0,
       0,   240,     0,   240,   240,     0,     0,     0,     0,     0,
       0,     0,   441,   240,     0,     0,     0,   341,   448,     0,
     240,   240,     0,     0,     0,     0,     0,   240,   240,   458,
     240,     0,     0,     0,     0,   240,     0,   463,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,     0,     0,     0,     0,   240,     0,
       0,   116,   117,     0,     0,     0,   118,   119,   120,     0,
       0,     0,   121,     0,   122,   450,   123,     0,   240,     0,
     240,     0,   240,     0,     0,   451,     0,   240,     0,   240,
       0,   240,     0,     0,     0,     0,   240,   240,     0,     0,
       0,   124,     0,   240,   240,    11,    12,   223,   224,   225,
     424,   425,    13,   226,   125,   227,    14,    15,    16,    17,
       0,     0,     0,     0,     0,   228,   229,   230,   231,   232,
       0,   233,   234,     0,   235,   236,     0,     0,    18,   127,
     128,    19,   116,   117,     0,     0,     0,   118,   119,   120,
       0,     0,     0,   121,     0,   122,   295,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,    11,    12,   223,   224,
     225,     0,     0,    13,   226,   125,   227,    14,    15,    16,
      17,     0,     0,     0,     0,     0,   228,   229,   230,   231,
     232,     0,   233,   234,     0,   235,   236,     0,     0,    18,
     127,   128,    19,   116,   117,     0,     0,     0,   118,   119,
     120,     0,     0,     0,   121,     0,   122,   359,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,    11,    12,   223,
     224,   225,     0,     0,    13,   226,   125,   227,    14,    15,
      16,    17,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,     0,   233,   234,     0,   235,   236,     0,     0,
      18,   127,   128,    19,   116,   117,     0,     0,     0,   118,
     119,   120,     0,     0,     0,   121,     0,   122,   365,   123,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,    11,    12,
     223,   224,   225,     0,     0,    13,   226,   125,   227,    14,
      15,    16,    17,     0,     0,     0,     0,     0,   228,   229,
     230,   231,   232,     0,   233,   234,     0,   235,   236,     0,
       0,    18,   127,   128,    19,   116,   117,     0,     0,     0,
     118,   119,   120,     0,     0,     0,   121,     0,   122,   368,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,    11,
      12,   223,   224,   225,     0,     0,    13,   226,   125,   227,
      14,    15,    16,    17,     0,     0,     0,     0,     0,   228,
     229,   230,   231,   232,     0,   233,   234,     0,   235,   236,
       0,     0,    18,   127,   128,    19,   116,   117,     0,     0,
       0,   118,   119,   120,     0,     0,     0,   121,     0,   122,
     369,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
      11,    12,   223,   224,   225,     0,     0,    13,   226,   125,
     227,    14,    15,    16,    17,     0,     0,     0,     0,     0,
     228,   229,   230,   231,   232,     0,   233,   234,     0,   235,
     236,     0,     0,    18,   127,   128,    19,   116,   117,     0,
       0,     0,   118,   119,   120,     0,     0,     0,   121,     0,
     122,   408,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,    11,    12,   223,   224,   225,     0,     0,    13,   226,
     125,   227,    14,    15,    16,    17,     0,     0,     0,     0,
       0,   228,   229,   230,   231,   232,     0,   233,   234,     0,
     235,   236,     0,     0,    18,   127,   128,    19,   116,   117,
       0,     0,     0,   118,   119,   120,     0,     0,     0,   121,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,    11,    12,   223,   224,   225,   424,   425,    13,
     226,   125,   227,    14,    15,    16,    17,     0,     0,     0,
       0,     0,   228,   229,   230,   231,   232,     0,   233,   234,
       0,   235,   236,     0,     0,    18,   127,   128,    19,   116,
     117,     0,     0,     0,   118,   119,   120,     0,     0,     0,
     121,     0,   122,   433,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,     0,    11,    12,   223,   224,   225,     0,     0,
      13,   226,   125,   227,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   228,   229,   230,   231,   232,     0,   233,
     234,     0,   235,   236,     0,     0,    18,   127,   128,    19,
     116,   117,     0,     0,     0,   118,   119,   120,     0,     0,
       0,   121,     0,   122,   434,   123,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,    11,    12,   223,   224,   225,     0,
       0,    13,   226,   125,   227,    14,    15,    16,    17,     0,
       0,     0,     0,     0,   228,   229,   230,   231,   232,     0,
     233,   234,     0,   235,   236,     0,     0,    18,   127,   128,
      19,   116,   117,     0,     0,     0,   118,   119,   120,     0,
       0,     0,   121,     0,   122,   437,   123,     0,     0,     0,
       0,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,    11,    12,   223,   224,   225,
       0,     0,    13,   226,   125,   227,    14,    15,    16,    17,
       0,     0,     0,     0,     0,   228,   229,   230,   231,   232,
       0,   233,   234,     0,   235,   236,     0,     0,    18,   127,
     128,    19,   116,   117,     0,     0,     0,   118,   119,   120,
       0,     0,     0,   121,     0,   122,   439,   123,     0,     0,
       0,     0,     0,     0,     0,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,    11,    12,   223,   224,
     225,     0,     0,    13,   226,   125,   227,    14,    15,    16,
      17,     0,     0,     0,     0,     0,   228,   229,   230,   231,
     232,     0,   233,   234,     0,   235,   236,     0,     0,    18,
     127,   128,    19,   116,   117,     0,     0,     0,   118,   119,
     120,     0,     0,     0,   121,     0,   122,   460,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,    11,    12,   223,
     224,   225,     0,     0,    13,   226,   125,   227,    14,    15,
      16,    17,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,     0,   233,   234,     0,   235,   236,     0,     0,
      18,   127,   128,    19,   116,   117,     0,     0,     0,   118,
     119,   120,     0,     0,     0,   121,     0,   122,   474,   123,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,    11,    12,
     223,   224,   225,     0,     0,    13,   226,   125,   227,    14,
      15,    16,    17,     0,     0,     0,     0,     0,   228,   229,
     230,   231,   232,     0,   233,   234,     0,   235,   236,     0,
       0,    18,   127,   128,    19,   116,   117,     0,     0,     0,
     118,   119,   120,     0,     0,     0,   121,     0,   122,   484,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,    11,
      12,   223,   224,   225,     0,     0,    13,   226,   125,   227,
      14,    15,    16,    17,     0,     0,     0,     0,     0,   228,
     229,   230,   231,   232,     0,   233,   234,     0,   235,   236,
       0,     0,    18,   127,   128,    19,   116,   117,     0,     0,
       0,   118,   119,   120,     0,     0,     0,   121,     0,   122,
     487,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
      11,    12,   223,   224,   225,     0,     0,    13,   226,   125,
     227,    14,    15,    16,    17,     0,     0,     0,     0,     0,
     228,   229,   230,   231,   232,     0,   233,   234,     0,   235,
     236,     0,     0,    18,   127,   128,    19,   116,   117,     0,
       0,     0,   118,   119,   120,     0,     0,     0,   121,     0,
     122,   488,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,    11,    12,   223,   224,   225,     0,     0,    13,   226,
     125,   227,    14,    15,    16,    17,     0,     0,     0,     0,
       0,   228,   229,   230,   231,   232,     0,   233,   234,     0,
     235,   236,     0,     0,    18,   127,   128,    19,   116,   117,
       0,     0,     0,   118,   119,   120,     0,     0,     0,   121,
       0,   122,   491,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,    11,    12,   223,   224,   225,     0,     0,    13,
     226,   125,   227,    14,    15,    16,    17,     0,     0,     0,
       0,     0,   228,   229,   230,   231,   232,     0,   233,   234,
       0,   235,   236,     0,     0,    18,   127,   128,    19,   116,
     117,     0,     0,     0,   118,   119,   120,     0,     0,     0,
     121,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,     0,    11,    12,   223,   224,   225,     0,     0,
      13,   226,   125,   227,    14,    15,    16,    17,     0,     0,
       0,     0,     0,   228,   229,   230,   231,   232,     0,   233,
     234,     0,   235,   236,     0,     0,    18,   127,   128,    19,
     116,   117,     0,     0,     0,   118,   119,   120,     0,     0,
       0,   121,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,    11,    12,   223,   224,   225,     0,
       0,    13,   226,   125,   227,    14,    15,    16,    17,     0,
       0,     0,     0,     0,   228,   229,   230,   231,   232,     0,
     233,   234,     0,   235,   236,     0,     0,    18,   127,   128,
      19,   116,   117,     0,     0,     0,   118,   119,   120,     0,
       0,     0,   121,     0,   122,     0,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,    11,    12,   223,   224,   225,
       0,     0,    13,   226,   125,   227,    14,    15,    16,    17,
       0,     0,     0,     0,     0,   228,   286,   230,   231,   232,
       0,   233,   234,     0,   235,   236,     0,     0,    18,   127,
     128,    19,   116,   117,     0,     0,     0,   118,   119,   120,
       0,     0,     0,   121,     0,   122,     0,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,    11,    12,   223,   224,
     225,     0,     0,    13,   226,   125,   227,    14,    15,    16,
      17,     0,     0,     0,     0,     0,   228,   229,   230,   231,
     232,     0,   233,   234,     0,   235,   236,     0,     0,    18,
     127,   128,    19,   116,   117,     0,     0,     0,   118,   119,
     120,     0,     0,     0,   121,     0,   122,     0,   387,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,    11,    12,   223,
     224,   225,     0,     0,    13,   226,   125,   227,    14,    15,
      16,    17,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,     0,   233,   234,     0,   235,   236,     0,     0,
      18,   127,   128,    19,   116,   117,     0,     0,     0,   118,
     119,   120,     0,     0,     0,   121,     0,   122,     0,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,    11,    12,
     223,   224,   225,     0,     0,    13,   226,   125,   227,    14,
      15,    16,    17,     0,     0,     0,     0,     0,   228,   229,
     230,   231,   232,     0,   233,   234,     0,   235,   236,     0,
       0,    18,   127,   128,    19,   116,   117,     0,     0,     0,
     118,   119,   120,     0,     0,     0,   121,     0,   122,     0,
     414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,    11,
      12,   223,   224,   225,     0,     0,    13,   226,   125,   227,
      14,    15,    16,    17,     0,     0,     0,     0,     0,   228,
     229,   230,   231,   232,     0,   233,   234,     0,   235,   236,
       0,     0,    18,   127,   128,    19,   116,   117,     0,     0,
       0,   118,   119,   120,     0,     0,     0,   121,     0,   122,
       0,   444,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
      11,    12,   223,   224,   225,     0,     0,    13,   226,   125,
     227,    14,    15,    16,    17,     0,     0,     0,     0,     0,
     228,   229,   230,   231,   232,     0,   233,   234,     0,   235,
     236,     0,     0,    18,   127,   128,    19,   116,   117,     0,
       0,     0,   118,   119,   120,     0,     0,     0,   121,     0,
     122,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,    11,    12,   223,   224,   225,     0,     0,    13,   226,
     125,   227,    14,    15,    16,    17,     0,     0,     0,     0,
       0,   228,   229,   230,   231,   232,     0,   233,   234,     0,
     235,   236,     0,     0,    18,   127,   128,    19,   116,   117,
       0,     0,     0,   118,   119,   120,     0,     0,     0,   121,
       0,   122,     0,   123,    11,    12,     0,     0,     0,     0,
       0,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,    11,    12,   338,     0,     0,    18,     0,    13,
      19,   125,   126,    14,    15,    16,    17,   116,   117,     0,
       0,     0,   118,   119,   120,     0,     0,     0,   121,     0,
     122,     0,   123,     0,     0,    18,   127,   128,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,    11,    12,   397,     0,     0,     0,     0,    13,     0,
     125,   126,    14,    15,    16,    17,   116,   117,     0,     0,
       0,   118,   119,   120,     0,     0,     0,   121,     0,   122,
       0,   123,     0,     0,    18,   127,   128,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
      11,    12,     0,     0,     0,     0,     0,    13,     0,   125,
     126,    14,    15,    16,    17,     0,   116,   117,     0,     0,
       0,   118,   119,   120,     0,     0,     0,   121,     0,   122,
     410,   123,     0,    18,   127,   128,    19,   261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
     209,     0,    11,    12,   210,     0,   124,     0,     0,    13,
      11,    12,     0,    14,    15,    16,    17,    13,     0,   125,
     126,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,   212,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,    18,   127,   128,    19,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,   179,   180,   241,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,   180,
       0,   181,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,   191,   308,   181,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,     0,   191,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,   180,
       0,     0,   310,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,     0,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,     0,   191,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,     0,   179,   180,
       0,     0,   311,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   181,   179,
     180,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,     0,   191,     0,     0,   -64,     0,     0,   181,
       0,     0,     0,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,     0,   191,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,   179,
     180,     0,     0,   347,     0,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   181,
     179,   180,   364,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,     0,   191,     0,     0,     0,     0,     0,
     181,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,     0,   191,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,     0,
     179,   180,   367,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,   179,   180,   374,
     181,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,     0,   191,     0,   181,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,     0,   191,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,   179,   180,   389,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,   179,   180,   421,   181,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,     0,   191,     0,   181,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,     0,   191,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,   179,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -96,     0,     0,   181,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,     0,   191,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,   179,   180,   442,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,   179,   180,   462,   181,     0,     0,     0,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,     0,   191,
       0,   181,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,   191,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,   179,   180,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,   179,   180,     0,
     467,   181,     0,     0,     0,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,     0,   191,   181,     0,     0,
       0,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,     0,   191
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-361)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,   164,   165,    44,    76,    58,
       0,     5,   102,   373,    19,   125,    23,    35,    19,    50,
      51,    67,    38,    20,    27,    28,    55,    34,    77,    32,
      35,    34,    35,    34,    50,    51,    26,    20,    32,    55,
      34,   230,   201,    33,   233,    94,   136,    93,   237,    39,
      40,   161,    83,    56,    24,    84,    72,   106,    24,    19,
      63,   110,    99,   423,    34,    68,    23,    83,    71,    23,
      73,     0,    19,    76,    34,    20,    33,    22,    81,    33,
      19,    84,    85,    21,    19,    88,    89,    34,    19,   248,
     200,    24,   105,    83,    84,    34,    34,    26,   111,    34,
      90,    34,   105,    34,    19,    23,   109,    85,   111,    19,
      39,    40,    69,    70,    71,    69,    70,    71,    19,    34,
     123,   207,   125,   282,    34,   211,   139,   140,    19,    25,
     143,   144,    38,    34,    36,   324,   139,   140,    23,    36,
     143,   144,   331,    34,    50,    51,   335,   336,    22,    55,
      24,    69,    70,    71,    83,    84,    38,    19,   161,    19,
      83,    90,    20,    27,    22,    22,    72,    19,    50,    51,
      34,   220,    34,    55,    34,   364,    27,    83,   367,    53,
      54,    19,    34,    34,    83,    38,    60,    23,    62,    63,
      64,    65,    66,    67,    83,   384,    34,    50,    51,    33,
     389,    83,    55,    83,   207,    36,    19,   210,    19,   212,
     399,    19,    86,    87,    88,    89,    21,   406,   407,   329,
     223,    34,   271,    34,   413,   228,    34,   416,    24,   278,
      83,    20,   421,   236,    27,    69,    70,    71,   427,    36,
      36,    36,   245,    34,    20,    22,    69,    70,    71,   438,
      27,    28,    29,    30,    31,    32,    27,   260,   261,    36,
      20,   264,   265,    20,   313,    20,    20,   316,    20,   318,
     319,    24,   321,   322,    20,   464,    35,   466,   327,    27,
      22,    83,   285,    27,    83,    36,    36,   290,   477,    36,
     277,    20,    20,   482,   483,    20,    20,    24,   285,    20,
      22,   490,   289,   290,   317,    36,    36,    20,    53,    54,
      36,    27,    76,    36,   317,    60,    36,    62,    63,    64,
      65,    66,    67,   326,    36,    34,   329,    20,    36,    35,
     343,    33,    20,    36,    20,   338,   385,   350,   351,    20,
     343,    86,    87,    88,    89,   101,   395,   350,   351,   417,
      27,    28,    29,    30,    31,    32,   405,   113,    24,    33,
     116,   117,   118,   119,   120,   121,   122,    81,   124,    27,
      27,    24,    24,   360,   377,    36,    20,   380,    78,    76,
     429,   430,   431,    22,   387,    36,    24,   390,    27,    28,
      29,    30,    31,    32,   397,   382,   383,   446,    20,    36,
     387,    20,    33,   390,    36,    20,    53,    54,   164,   165,
      36,   414,   148,    60,   417,    36,    63,    64,    65,    66,
      67,    27,    27,   436,    36,   181,    36,   414,    27,    19,
      19,    24,   481,   436,    36,    27,   192,     9,    24,    86,
      27,   444,    89,   199,    24,   201,   202,   203,    39,    72,
      80,    59,   136,   456,   435,   427,    44,   444,   240,   200,
     228,   217,    -1,    -1,    -1,   221,   469,   470,    -1,    -1,
     226,    -1,   475,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,   473,   243,   475,    -1,
     246,    -1,   248,   249,   230,    -1,    -1,   233,    -1,    -1,
      -1,   237,   489,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    -1,    17,    18,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,   282,    -1,   284,    -1,
      -1,    -1,   288,    37,    -1,    -1,   292,   293,    -1,    -1,
      -1,   277,   298,    -1,    -1,    49,   302,    -1,    52,   285,
      -1,    -1,   308,   289,   290,    -1,    -1,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,   323,    20,    21,
      22,    -1,    24,    53,    54,    55,    -1,   333,    -1,    -1,
      60,    -1,    -1,    -1,    64,    65,    66,    67,   324,   345,
      -1,    -1,    -1,    -1,    -1,   331,    -1,    49,    -1,   335,
     336,    53,    54,    -1,    -1,    -1,    86,    -1,    60,    89,
      62,    63,    64,    65,    66,    67,   372,   373,    -1,    -1,
      -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,   364,    -1,
     386,   367,    -1,    -1,    86,    87,    88,    89,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   382,   383,   384,    -1,
      -1,   387,    -1,   389,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   399,    -1,    -1,    -1,   423,   424,    -1,
     406,   407,    -1,    -1,    -1,    -1,    -1,   413,   414,   435,
     416,    -1,    -1,    -1,    -1,   421,    -1,   443,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,     9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,   464,    -1,
     466,    -1,   468,    -1,    -1,    33,    -1,   473,    -1,   475,
      -1,   477,    -1,    -1,    -1,    -1,   482,   483,    -1,    -1,
      -1,    49,    -1,   489,   490,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    89,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    89,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    89,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    80,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    89,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    80,    -1,    82,    83,
      -1,    -1,    86,    87,    88,    89,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    89,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    80,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    80,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,     9,
      10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      80,    -1,    82,    83,    -1,    -1,    86,    87,    88,    89,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    80,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      89,     9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    89,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    89,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    89,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    80,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    89,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    80,    -1,    82,    83,
      -1,    -1,    86,    87,    88,    89,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    89,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    80,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    79,    80,
      -1,    82,    83,    -1,    -1,    86,    87,    88,    89,     9,
      10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    79,
      80,    -1,    82,    83,    -1,    -1,    86,    87,    88,    89,
       9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      79,    80,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      89,     9,    10,    -1,    -1,    -1,    14,    15,    16,    -1,
      -1,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    89,     9,    10,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    89,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    -1,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    79,    80,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    89,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    79,    80,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    89,     9,    10,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    79,    80,    -1,    82,    83,
      -1,    -1,    86,    87,    88,    89,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    89,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    79,    80,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    89,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    22,    -1,    24,    53,    54,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    54,    55,    -1,    -1,    86,    -1,    60,
      89,    62,    63,    64,    65,    66,    67,     9,    10,    -1,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      22,    -1,    24,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    64,    65,    66,    67,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    22,
      83,    24,    -1,    86,    87,    88,    89,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    53,    54,    55,    -1,    49,    -1,    -1,    60,
      53,    54,    -1,    64,    65,    66,    67,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    36,    37,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      -1,    -1,    21,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    37,    17,
      18,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    -1,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    -1,    21,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    37,
      17,    18,    19,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,    -1,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    -1,
      36,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,     0,    26,    39,    40,    83,    84,    90,    96,
      97,    53,    54,    60,    64,    65,    66,    67,    86,    89,
     132,    63,   126,   132,   126,   132,   132,    55,    84,     0,
      33,    97,    20,    24,    35,    20,    85,   102,   132,   132,
     126,    69,    70,    71,    99,   101,   104,   108,   109,   126,
     116,   117,   132,    67,    93,   131,    25,   103,    36,   102,
      19,    50,    51,    83,    33,   104,   108,    23,    38,    50,
      51,    55,    72,    83,   105,    19,    34,    36,    22,   132,
      24,    34,   131,   103,    83,    83,   132,   132,    83,    83,
     110,   132,   105,   132,    36,   117,   131,    21,    69,    99,
     132,    27,    24,   132,   132,    20,    36,   132,   132,    34,
      36,    20,   131,    27,    23,    33,     9,    10,    14,    15,
      16,    20,    22,    24,    49,    62,    63,    87,    88,   121,
     122,   124,   125,   127,   128,   132,   100,   106,   109,    20,
      20,   116,   131,    20,    20,   132,   131,   116,    24,   121,
     121,   121,   121,   121,   121,   121,   121,   130,   129,   132,
     121,    62,   128,   132,    20,    20,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    17,
      18,    37,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    52,   123,    27,    28,    29,    30,    31,    32,   120,
      35,    20,    22,    22,    23,    33,   106,    38,    50,    51,
      55,    72,    83,   107,   116,   116,    19,    27,   116,   116,
      36,    27,    19,    55,    56,    57,    61,    63,    73,    74,
      75,    76,    77,    79,    80,    82,    83,    98,   111,   121,
     124,    19,    21,    34,    23,    34,    36,   132,    20,    22,
     130,   130,   121,   121,   121,   125,   128,   130,   121,   121,
      27,    38,   107,   132,    83,    83,   132,   107,   132,    19,
      19,    36,   121,    19,    19,   131,   121,    24,    36,   112,
     132,   121,    20,   127,    20,    24,    74,   111,    20,    24,
      24,   111,    20,    20,   132,    23,    33,   111,   120,   121,
     132,   121,    22,   130,    21,   121,    19,    19,    36,    19,
      21,    21,   132,    36,   132,   132,    36,    20,    36,    36,
     131,    36,    36,    27,    98,   131,    34,    36,   130,    35,
     121,    98,   132,    20,   121,    98,    98,    33,    55,   118,
     119,   121,   121,    20,   121,    36,    19,    21,   121,   131,
      20,    20,   131,   116,   131,   131,   131,   131,   121,    23,
      24,   132,   131,    19,    19,    23,   121,    19,    23,    23,
      76,   132,    81,    33,    19,   116,   121,    27,   116,   116,
      27,    19,    24,    24,    98,    36,    27,    24,   111,    19,
      24,   111,    78,    76,    20,    36,   121,    55,   119,    24,
      19,   132,    19,    19,   132,    36,    98,    98,    23,   131,
      83,   113,   121,    98,    24,   111,    98,    20,    20,   121,
     131,    19,   132,    33,    58,    59,   111,   114,   115,    36,
      36,    36,   131,    23,    23,    27,    20,    23,    98,    23,
     117,   121,    19,    27,    24,   111,    36,   119,   121,    36,
      23,    33,   115,   131,   131,   131,    27,   113,   121,   116,
      23,    19,    19,   121,    98,   131,    19,    36,    24,    27,
      27,   132,    19,    24,    23,    24,   111,    98,    55,   132,
     132,    36,    98,    98,    23,   132,   131,    23,    23,    24,
      98,    23
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1787 of yacc.c  */
#line 89 "parser.y"
    { (yyvsp[(2) - (3)].file_block)->appendObject( PackageManager::endOfFile() ); PackageManager::appendBlockToCodeGen( (yyvsp[(2) - (3)].file_block) ); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 93 "parser.y"
    { (yyval.file_block) = new FileBlock(); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 94 "parser.y"
    { (yyval.file_block) = (yyvsp[(1) - (2)].file_block); if( (yyvsp[(2) - (2)].prop) ) (yyvsp[(1) - (2)].file_block)->appendObject( (yyvsp[(2) - (2)].prop) ); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    { (yyval.file_block) = (yyvsp[(1) - (2)].file_block); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 96 "parser.y"
    { (yyval.file_block) = new FileBlock(); if( (yyvsp[(1) - (1)].prop) ) (yyval.file_block)->appendObject( (yyvsp[(1) - (1)].prop) ); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 100 "parser.y"
    { (yyval.prop) = PackageManager::setCurrentPath( (yyvsp[(2) - (2)].expr_path) ); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 101 "parser.y"
    { (yyval.prop) = PackageManager::setCurrentPath( NULL ); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 102 "parser.y"
    { (yyval.prop) = PackageManager::addImportPath( (yyvsp[(2) - (2)].expr_path) ); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 103 "parser.y"
    { (yyval.prop) = new AInstDeclareClass( (yyvsp[(2) - (7)].expr), (yyvsp[(3) - (7)].exp_type), (yyvsp[(4) - (7)].expr_list), (yyvsp[(6) - (7)].prop_list) ); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 104 "parser.y"
    { (yyval.prop) = new AInstDeclareInterface( (yyvsp[(2) - (5)].expr), (yyvsp[(4) - (5)].prop_list) ); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 105 "parser.y"
    { (yyval.prop) = new AInstExternalClass( (yyvsp[(3) - (10)].expr), (yyvsp[(4) - (10)].exp_type), (yyvsp[(5) - (10)].expr_list), (yyvsp[(7) - (10)].prop_list), (yyvsp[(10) - (10)].expr) ); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { (yyval.prop) = new AInstDeclareFunc( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    { (yyval.prop) = new AInstExternalVar( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].expr) ); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 111 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 112 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); if( (yyvsp[(2) - (2)].inst) ) (yyvsp[(1) - (2)].inst_list)->push_back( (yyvsp[(2) - (2)].inst) ); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 113 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); if( (yyvsp[(1) - (1)].inst) ) (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 118 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 119 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( (yyvsp[(1) - (1)].prop) ); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); (yyvsp[(1) - (2)].prop_list)->push_back( (yyvsp[(2) - (2)].prop) ); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 121 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 125 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 126 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( (yyvsp[(1) - (1)].prop) ); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 127 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); (yyvsp[(1) - (2)].prop_list)->push_back( (yyvsp[(2) - (2)].prop) ); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 128 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 132 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 133 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( (yyvsp[(1) - (1)].prop) ); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 134 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); (yyvsp[(1) - (2)].prop_list)->push_back( (yyvsp[(2) - (2)].prop) ); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 135 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (2)].prop_list); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 139 "parser.y"
    { (yyval.exp_type) = NULL; }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    { (yyval.exp_type) = (yyvsp[(2) - (2)].exp_type); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 144 "parser.y"
    { (yyval.expr_list) = NULL; }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 145 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( (yyvsp[(2) - (2)].expr) ); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 146 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (3)].expr_list); (yyvsp[(1) - (3)].expr_list)->push_back( (yyvsp[(3) - (3)].expr) ); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 150 "parser.y"
    { (yyval.prop) = (yyvsp[(2) - (2)].prop); (yyvsp[(2) - (2)].prop)->access = (yyvsp[(1) - (2)].tinfo)->type(); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 151 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isStatic = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 155 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type), NULL ); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 156 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 157 "parser.y"
    { (yyval.prop) = new AInstDeclareProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 158 "parser.y"
    {  (yyval.prop) = new AInstDeclareMultProp( (yyvsp[(2) - (2)].prop_list) ); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 159 "parser.y"
    { (yyval.prop) = new AInstDeclareMethod( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    { (yyval.prop) = new AInstDeclareGet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(10) - (11)].inst_list) ); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    { (yyval.prop) = new AInstDeclareSet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(10) - (11)].inst_list) ); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 162 "parser.y"
    { (yyval.prop) = new AInstDeclareMethod( (yyvsp[(2) - (8)].expr), NULL, (yyvsp[(4) - (8)].inst_list), (yyvsp[(7) - (8)].inst_list) ); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 166 "parser.y"
    { (yyval.prop) = (yyvsp[(2) - (2)].prop); (yyvsp[(2) - (2)].prop)->access = (yyvsp[(1) - (2)].tinfo)->type(); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 167 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isStatic = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 168 "parser.y"
    { (yyval.prop) = (yyvsp[(3) - (3)].prop); (yyvsp[(3) - (3)].prop)->isConst = true; (yyvsp[(3) - (3)].prop)->access = (yyvsp[(1) - (3)].tinfo)->type(); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 172 "parser.y"
    { (yyval.prop) = new AInstExternalProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 173 "parser.y"
    { (yyval.prop) = new AInstExternalProp( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 174 "parser.y"
    { (yyval.prop) = new AInstExternalMethod( (yyvsp[(2) - (9)].expr), (yyvsp[(7) - (9)].exp_type), (yyvsp[(4) - (9)].inst_list), (yyvsp[(9) - (9)].expr) ); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 175 "parser.y"
    { (yyval.prop) = new AInstExternalGet( (yyvsp[(3) - (10)].expr), (yyvsp[(8) - (10)].exp_type), (yyvsp[(5) - (10)].inst_list), (yyvsp[(10) - (10)].expr), false ); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    { (yyval.prop) = new AInstExternalGet( (yyvsp[(3) - (11)].expr), (yyvsp[(8) - (11)].exp_type), (yyvsp[(5) - (11)].inst_list), (yyvsp[(11) - (11)].expr), true ); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    { (yyval.prop) = new AInstExternalSet( (yyvsp[(3) - (10)].expr), (yyvsp[(8) - (10)].exp_type), (yyvsp[(5) - (10)].inst_list), (yyvsp[(10) - (10)].expr) ); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 178 "parser.y"
    { (yyval.prop) = new AInstExternalMethod( (yyvsp[(2) - (5)].expr), NULL, (yyvsp[(4) - (5)].inst_list), (yyvsp[(2) - (5)].expr) ); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    { (yyval.prop) = new AInstInterfaceMethod( (yyvsp[(3) - (8)].expr), (yyvsp[(8) - (8)].exp_type), (yyvsp[(5) - (8)].inst_list) ); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    { (yyval.prop) = new AInstInterfaceGet( (yyvsp[(4) - (9)].expr), (yyvsp[(9) - (9)].exp_type), (yyvsp[(6) - (9)].inst_list) ); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    { (yyval.prop) = new AInstInterfaceSet( (yyvsp[(4) - (9)].expr), (yyvsp[(9) - (9)].exp_type), (yyvsp[(6) - (9)].inst_list) ); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type), NULL ) ); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 193 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ) ); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 194 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (5)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].exp_type), NULL ) ); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (7)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareProp( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].expr) ) ); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 200 "parser.y"
    { (yyval.inst) = new AInstruction( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 201 "parser.y"
    { (yyval.inst) = new AInstDeclareFunc( (yyvsp[(2) - (10)].expr), (yyvsp[(7) - (10)].exp_type), (yyvsp[(4) - (10)].inst_list), (yyvsp[(9) - (10)].inst_list) ); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 202 "parser.y"
    { (yyval.inst) = new AInstElseif( (yyvsp[(4) - (6)].expr), (yyvsp[(6) - (6)].inst) ); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 203 "parser.y"
    { (yyval.inst) = new AInstElseif( (yyvsp[(4) - (8)].expr), (yyvsp[(7) - (8)].inst_list) ); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 204 "parser.y"
    { (yyval.inst) = new AInstElse( (yyvsp[(2) - (2)].inst) ); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 205 "parser.y"
    { (yyval.inst) = new AInstElse( (yyvsp[(3) - (4)].inst_list) ); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 206 "parser.y"
    { (yyval.inst) = new AInstIf( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].inst) ); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 207 "parser.y"
    { (yyval.inst) = new AInstIf( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 208 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (9)].inst), (yyvsp[(5) - (9)].inst), (yyvsp[(7) - (9)].inst), (yyvsp[(9) - (9)].inst) ); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 209 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (11)].inst), (yyvsp[(5) - (11)].inst), (yyvsp[(7) - (11)].inst), (yyvsp[(10) - (11)].inst_list) ); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 210 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (7)].inst), (yyvsp[(5) - (7)].expr), (yyvsp[(7) - (7)].inst) ); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 211 "parser.y"
    { (yyval.inst) = new AInstFor( (yyvsp[(3) - (9)].inst), (yyvsp[(5) - (9)].expr), (yyvsp[(8) - (9)].inst_list) ); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyval.inst) = new AInstWhile( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].inst) ); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 213 "parser.y"
    { (yyval.inst) = new AInstWhile( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    { (yyval.inst) = new AInstDo( (yyvsp[(6) - (7)].expr), (yyvsp[(2) - (7)].inst) ); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    { (yyval.inst) = new AInstDo( (yyvsp[(7) - (8)].expr), (yyvsp[(3) - (8)].inst_list) ); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    { (yyval.inst) = new AInstTryCatch( (yyvsp[(3) - (11)].inst_list), (yyvsp[(7) - (11)].inst), (yyvsp[(10) - (11)].inst_list) ); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 217 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 218 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].prop) ); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type) ); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { (yyval.inst) = new AInstDeclareMultVar( (yyvsp[(2) - (2)].prop_list) ); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    { (yyval.inst) = new AInstDelete( (yyvsp[(2) - (2)].expr_path) ); }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 222 "parser.y"
    { (yyval.inst) = new AInstSwitch( (yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].inst_list) ); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 223 "parser.y"
    { (yyval.inst) = new AInstBreak(); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    { (yyval.inst) = new AInstContinue(); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 225 "parser.y"
    { (yyval.inst) = new AInstReturn( NULL ); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 226 "parser.y"
    { (yyval.inst) = new AInstReturn( (yyvsp[(2) - (2)].expr) ); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {  (yyval.inst) = new AInstAssign( (yyvsp[(1) - (3)].expr_path), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 228 "parser.y"
    { (yyval.inst) = new AInstSuperCall( (yyvsp[(1) - (4)].tinfo), (yyvsp[(3) - (4)].expr_list) ); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ) ); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 233 "parser.y"
    { (yyval.prop_list) = new AObjectVector(); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type) ) ); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 234 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (7)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].expr) ) ); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 235 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (7)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].exp_type), (yyvsp[(7) - (7)].prop) ) ); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    { (yyval.prop_list) = (yyvsp[(1) - (5)].prop_list); (yyval.prop_list)->push_back( new AInstDeclareVar( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].exp_type) ) ); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 240 "parser.y"
    { (yyval.prop) = new AInstDeclareAnoFunc( (yyvsp[(1) - (9)].tinfo), (yyvsp[(6) - (9)].exp_type), (yyvsp[(3) - (9)].inst_list), (yyvsp[(8) - (9)].inst_list) ); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 244 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 245 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 246 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (2)].inst_list); (yyvsp[(1) - (2)].inst_list)->push_back( (yyvsp[(2) - (2)].inst) ); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 250 "parser.y"
    { (yyval.inst) = (yyvsp[(1) - (1)].inst); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 251 "parser.y"
    { (yyval.inst) = new AInstCase( (yyvsp[(2) - (3)].expr) ); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 252 "parser.y"
    { (yyval.inst) = new AInstDefault(); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 255 "parser.y"
    { (yyval.inst_list) = NULL; }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 256 "parser.y"
    { (yyval.inst_list) = new AInstructionVector(); (yyval.inst_list)->push_back( (yyvsp[(1) - (1)].inst) ); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 257 "parser.y"
    { (yyval.inst_list) = (yyvsp[(1) - (3)].inst_list); (yyvsp[(1) - (3)].inst_list)->push_back( (yyvsp[(3) - (3)].inst) ); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 261 "parser.y"
    { (yyval.inst) = new AInstDeclareArg( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].exp_type), NULL ); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    { (yyval.inst) = new AInstDeclareArg( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].exp_type), (yyvsp[(5) - (5)].expr) ); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].exp_type) ); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 270 "parser.y"
    { (yyval.inst) = new AInstDeclareVar( (yyvsp[(2) - (6)].expr), (yyvsp[(4) - (6)].exp_type), (yyvsp[(6) - (6)].expr) ); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 271 "parser.y"
    { (yyval.inst) = new AInstruction( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 280 "parser.y"
    { (yyval.expr) = new AExpOperation( (yyvsp[(1) - (3)].expr), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 284 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 285 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 286 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 287 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 288 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].tinfo), false ); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 289 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].tinfo), false ); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    { (yyval.expr) = new AExpFastOp( (yyvsp[(2) - (2)].expr), (yyvsp[(1) - (2)].tinfo), true ); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 293 "parser.y"
    { (yyval.expr) = new AExpParent( (yyvsp[(2) - (3)].expr) ); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 294 "parser.y"
    { (yyval.expr) = new AExpNewArray( NULL, (yyvsp[(2) - (4)].expr) ); }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 295 "parser.y"
    { (yyval.expr) = new AExpIfast( (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 296 "parser.y"
    {  (yyval.expr) = new AExpAssign( (yyvsp[(1) - (3)].expr_path), (yyvsp[(2) - (3)].tinfo), (yyvsp[(3) - (3)].expr) ); }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 297 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr_path); }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 306 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (1)].expr_path); }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 307 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    { (yyval.expr_path) = new AExpSetPath( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 312 "parser.y"
    { (yyval.expr_path) = new AExpSetItem( (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr) ); }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 316 "parser.y"
    { (yyval.expr_path) = new AExpGetPath( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 317 "parser.y"
    { (yyval.expr_path) = new AExpSuper( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 318 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 322 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (1)].expr_path); }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 323 "parser.y"
    { (yyval.expr_path) = (yyvsp[(1) - (3)].expr_path); (yyval.expr_path)->appendCall( (yyvsp[(3) - (3)].expr_path) ); }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 324 "parser.y"
    { (yyval.expr_path) = new AExpNewArray( (yyvsp[(2) - (3)].expr_list), NULL ); }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 325 "parser.y"
    { (yyval.expr_path) = new AExpNewObject( (yyvsp[(2) - (3)].expr_list) ); }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    { (yyval.expr_path) = new AExpGetPath( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 330 "parser.y"
    { (yyval.expr_path) = new AExpSuper( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 333 "parser.y"
    { (yyval.expr_path) = new AExpNew( (yyvsp[(2) - (5)].expr_path), (yyvsp[(4) - (5)].expr_list) ); }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 334 "parser.y"
    { (yyval.expr_path) = new AExpCallFunc( (yyvsp[(1) - (4)].expr_path), (yyvsp[(3) - (4)].expr_list) ); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 335 "parser.y"
    { (yyval.expr_path) = new CompilerGet( (yyvsp[(3) - (4)].expr_list) ); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 336 "parser.y"
    { (yyval.expr_path) = new CompilerSet( (yyvsp[(3) - (4)].expr_list) ); }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 337 "parser.y"
    { (yyval.expr_path) = new AExpGetItem( (yyvsp[(1) - (4)].expr_path), (yyvsp[(3) - (4)].expr) ); }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 338 "parser.y"
    { (yyval.expr_path) = new AExpGetItem( (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr) ); }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 342 "parser.y"
    { (yyval.expr_list) = NULL; }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 343 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( new AExpObjectProp( (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr) ) ); }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (5)].expr_list); (yyvsp[(1) - (5)].expr_list)->push_back( new AExpObjectProp( (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr) ) ); }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 348 "parser.y"
    { (yyval.expr_list) = NULL; }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 349 "parser.y"
    { (yyval.expr_list) = new AExpressionVector(); (yyval.expr_list)->push_back( (yyvsp[(1) - (1)].expr) ); }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 350 "parser.y"
    { (yyval.expr_list) = (yyvsp[(1) - (3)].expr_list); (yyvsp[(1) - (3)].expr_list)->push_back( (yyvsp[(3) - (3)].expr) ); }
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 354 "parser.y"
    { (yyval.exp_type) = new ATypage( (yyvsp[(1) - (1)].tinfo), false ); }
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 355 "parser.y"
    { (yyval.exp_type) = new ATypage( (yyvsp[(1) - (3)].tinfo), true ); }
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 356 "parser.y"
    { (yyval.exp_type) = new ATypage(); }
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 360 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 361 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 362 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 363 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 364 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 365 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 366 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 367 "parser.y"
    { (yyval.expr) = new AExpression( (yyvsp[(1) - (1)].tinfo) ); }
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 368 "parser.y"
    { (yyval.expr) = new CompilerName( (yyvsp[(3) - (4)].expr_path) ); }
    break;


/* Line 1787 of yacc.c  */
#line 3508 "parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2050 of yacc.c  */
#line 371 "parser.y"

