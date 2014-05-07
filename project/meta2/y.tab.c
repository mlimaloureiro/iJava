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
     NUMBER = 258,
     ENDOF = 259,
     OCURV = 260,
     CCURV = 261,
     OBRACE = 262,
     CBRACE = 263,
     OSQUARE = 264,
     CSQUARE = 265,
     BOOLLIT = 266,
     INT = 267,
     BOOL = 268,
     NEW = 269,
     PRINT = 270,
     PARSEINT = 271,
     CLASS = 272,
     PUBLIC = 273,
     STATIC = 274,
     VOID = 275,
     STRING = 276,
     DOTLENGTH = 277,
     RETURN = 278,
     IF = 279,
     ELSE = 280,
     WHILE = 281,
     RESERVED = 282,
     OP1 = 283,
     OP2 = 284,
     OP3 = 285,
     OP4 = 286,
     ASSIGN = 287,
     SEMIC = 288,
     COMMA = 289,
     ID = 290,
     INTLIT = 291,
     NOT = 292,
     OR = 293,
     AND = 294,
     EQUALS = 295
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ENDOF 259
#define OCURV 260
#define CCURV 261
#define OBRACE 262
#define CBRACE 263
#define OSQUARE 264
#define CSQUARE 265
#define BOOLLIT 266
#define INT 267
#define BOOL 268
#define NEW 269
#define PRINT 270
#define PARSEINT 271
#define CLASS 272
#define PUBLIC 273
#define STATIC 274
#define VOID 275
#define STRING 276
#define DOTLENGTH 277
#define RETURN 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define RESERVED 282
#define OP1 283
#define OP2 284
#define OP3 285
#define OP4 286
#define ASSIGN 287
#define SEMIC 288
#define COMMA 289
#define ID 290
#define INTLIT 291
#define NOT 292
#define OR 293
#define AND 294
#define EQUALS 295




/* Copy the first part of user declarations.  */
#line 1 "ijparser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "structures.h"
	#include "functions.h"
	#include "show.h"


    int yylex(void);
    int yyerror(char *s);
    int linha, coluna,error;
    struct is_root *tree = NULL;
    char* yytext;


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
#line 18 "ijparser.y"
{
    struct is_root*                         is_root_t;
    struct is_program*                      is_program_t;
    struct is_field_or_method*              field_or_method_t;
    struct is_method_declaration*           method_decl_t;
    struct is_field_declaration*            field_decl_t;
    struct field_declarator*                field_declarator_t;
    struct field_declarator_list*           field_declarator_list_t;
    struct is_type_specifier*               is_type_specifier_t;
    struct is_opt_array*                    is_opt_array_t;
    struct var_type*                        is_var_type_t;
    struct is_function_type*                is_function_type_t;
    
    struct is_opt_formal_params*            is_opt_formal_params_t;
    struct is_formal_params*                is_formal_params_t;
    struct is_formal_params_list*           is_formal_params_list_t;
    
    struct is_opt_var_decl*                 is_opt_var_decl_t;
    struct is_opt_statement*                is_opt_statement_t;
    struct is_statement*                    is_statement_t;
    
    struct is_opt_expr*                     is_opt_expr_t;
    struct is_opt_array_pos*                is_opt_array_pos_t;
    struct is_expression*                   is_expression_t;
    
    struct is_array_dim*                    is_array_dim_t;
    struct is_opt_args*                     is_opt_args_t;
    struct is_args*                         is_args_t;
    struct is_opt_args_list*                is_opt_args_list_t;

    /* structures */
    char *value;
    char *intlit;
    char *identifier;
}
/* Line 193 of yacc.c.  */
#line 229 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 242 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    11,    12,    15,    18,    21,    33,
      35,    37,    38,    40,    44,    49,    50,    55,    56,    59,
      60,    64,    69,    72,    74,    76,    77,    80,    81,    84,
      88,    94,   102,   108,   114,   120,   124,   125,   129,   130,
     132,   138,   142,   146,   150,   154,   157,   160,   162,   164,
     166,   168,   172,   175,   183,   188,   193,   197,   198,   200,
     203,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    17,    35,     7,    44,     8,
      -1,    -1,    45,    44,    -1,    46,    44,    -1,    19,    53,
      -1,    18,    19,    47,    35,     5,    48,     6,     7,    51,
      57,     8,    -1,    54,    -1,    20,    -1,    -1,    49,    -1,
      54,    35,    50,    -1,    21,     9,    10,    35,    -1,    -1,
      34,    54,    35,    50,    -1,    -1,    53,    51,    -1,    -1,
      34,    35,    52,    -1,    54,    35,    52,    33,    -1,    55,
      56,    -1,    12,    -1,    13,    -1,    -1,     9,    10,    -1,
      -1,    58,    57,    -1,     7,    57,     8,    -1,    24,     5,
      61,     6,    58,    -1,    24,     5,    61,     6,    58,    25,
      58,    -1,    26,     5,    61,     6,    58,    -1,    15,     5,
      61,     6,    33,    -1,    35,    59,    32,    61,    33,    -1,
      23,    60,    33,    -1,    -1,     9,    61,    10,    -1,    -1,
      61,    -1,    14,    55,     9,    61,    10,    -1,    61,    28,
      61,    -1,    61,    29,    61,    -1,    61,    30,    61,    -1,
      61,    31,    61,    -1,    30,    61,    -1,    37,    61,    -1,
      62,    -1,    35,    -1,    36,    -1,    11,    -1,     5,    61,
       6,    -1,    61,    22,    -1,    16,     5,    35,     9,    61,
      10,     6,    -1,    35,     5,    63,     6,    -1,    62,     9,
      61,    10,    -1,     9,    61,    10,    -1,    -1,    64,    -1,
      61,    65,    -1,    -1,    34,    61,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   137,   137,   139,   141,   142,   143,   146,   149,   152,
     153,   156,   157,   160,   161,   164,   165,   168,   169,   172,
     173,   176,   179,   182,   183,   186,   187,   190,   191,   194,
     195,   196,   197,   198,   199,   200,   204,   205,   208,   209,
     213,   214,   215,   216,   217,   218,   219,   220,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   234,   235,   238,
     241,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ENDOF", "OCURV", "CCURV",
  "OBRACE", "CBRACE", "OSQUARE", "CSQUARE", "BOOLLIT", "INT", "BOOL",
  "NEW", "PRINT", "PARSEINT", "CLASS", "PUBLIC", "STATIC", "VOID",
  "STRING", "DOTLENGTH", "RETURN", "IF", "ELSE", "WHILE", "RESERVED",
  "OP1", "OP2", "OP3", "OP4", "ASSIGN", "SEMIC", "COMMA", "ID", "INTLIT",
  "NOT", "OR", "AND", "EQUALS", "$accept", "Start", "Program",
  "field_or_method", "field_decl", "method_decl", "function_type",
  "opt_formal_params", "formal_params", "opt_param", "opt_var_decl",
  "opt_variable", "var_decl", "Type", "var_type", "opt_array",
  "opt_statement", "Statement", "opt_array_pos", "opt_expr", "Expr",
  "array_dim", "opt_args", "Args", "opt_arg", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    44,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     0,     2,     2,     2,    11,     1,
       1,     0,     1,     3,     4,     0,     4,     0,     2,     0,
       3,     4,     2,     1,     1,     0,     2,     0,     2,     3,
       5,     7,     5,     5,     5,     3,     0,     3,     0,     1,
       5,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     3,     2,     7,     4,     4,     3,     0,     1,     2,
       0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     4,     0,     0,     0,
       4,     4,     0,    23,    24,     7,     0,    25,     3,     5,
       6,    10,     0,     9,    19,     0,    22,     0,     0,     0,
      26,    11,    19,    21,     0,     0,    12,     0,    20,     0,
       0,    15,     0,    17,     0,    13,    14,    27,    17,     0,
      27,     0,    38,     0,     0,    36,     0,    27,    18,    15,
       0,     0,     0,     0,    50,     0,     0,     0,    48,    49,
       0,     0,    39,    47,     0,     0,     0,     0,     8,    28,
      16,    29,     0,     0,     0,     0,     0,    45,    57,    46,
      35,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    56,     0,     0,    60,     0,    58,    41,
      42,    43,    44,     0,     0,     0,    37,     0,    33,     0,
       0,     0,    59,    54,    55,    30,    32,    34,    40,     0,
      60,     0,     0,    61,    31,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    22,    35,    36,    45,
      47,    29,    48,    16,    17,    26,    56,    57,    77,    71,
      72,    73,   107,   108,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
       5,   -10,    30,  -112,    47,  -112,    22,    27,    -1,    43,
      22,    22,    45,  -112,  -112,  -112,    36,    68,  -112,  -112,
    -112,  -112,    46,  -112,    48,    73,  -112,    86,    54,    60,
    -112,    -5,    48,  -112,    96,    97,  -112,    72,  -112,   108,
     112,    92,    85,    -1,    -1,  -112,  -112,    29,    -1,    93,
      29,   122,    12,   125,   126,   123,   136,    29,  -112,    92,
     137,    12,    12,    12,  -112,    -1,   129,    12,   142,  -112,
      12,   113,   141,   139,    12,    12,    12,   124,  -112,  -112,
    -112,  -112,    39,    44,    80,   145,   130,     7,    12,   135,
    -112,  -112,    12,    12,    12,    12,    12,    56,    70,    84,
      12,   133,  -112,  -112,    12,   149,   121,   161,  -112,    66,
     -12,     7,   135,    94,    29,    29,  -112,   131,  -112,   107,
      12,    12,  -112,  -112,  -112,   143,  -112,  -112,  -112,   111,
     121,    29,   167,  -112,  -112,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,    69,  -112,  -112,  -112,  -112,  -112,   115,
     127,   144,   169,    -7,   114,  -112,     6,  -111,  -112,  -112,
     -61,  -112,  -112,  -112,    50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      82,    83,    84,   125,   126,    23,    87,    13,    14,    89,
      91,    13,    14,    97,    98,    99,    34,    62,    94,    95,
     134,    63,     1,    64,    37,     4,    65,   106,    66,    91,
       5,   109,   110,   111,   112,   113,    50,    49,    95,   117,
       7,     8,    67,   119,    51,   101,    12,    68,    69,    70,
     102,    18,    52,    53,     6,    54,    60,    13,    14,   129,
     130,    91,   114,    79,    55,    21,    91,    92,    93,    94,
      95,    24,    92,    93,    94,    95,   115,    25,    91,    19,
      20,    27,    28,    30,    92,    93,    94,    95,    91,    32,
     103,    31,    91,    33,   116,    93,    94,    95,    92,    93,
      94,    95,    91,    40,   124,    39,    91,    41,    92,    93,
      94,    95,    92,    93,    94,    95,    91,   128,    42,    43,
      46,   132,    92,    93,    94,    95,    44,    61,    59,    91,
      74,    75,    76,    91,    86,    92,    93,    94,    95,    92,
      93,    94,    95,    91,    78,    81,    90,    88,    96,    92,
      93,    94,    95,    91,   104,   121,   100,    91,   120,    92,
      93,    94,    95,    91,   127,   105,   118,   123,   131,    92,
      93,    94,    95,   135,    80,    58,    38,    15,     0,    85,
     133
};

static const yytype_int16 yycheck[] =
{
      61,    62,    63,   114,   115,    12,    67,    12,    13,    70,
      22,    12,    13,    74,    75,    76,    21,     5,    30,    31,
     131,     9,    17,    11,    31,    35,    14,    88,    16,    22,
       0,    92,    93,    94,    95,    96,     7,    44,    31,   100,
      18,    19,    30,   104,    15,     6,    19,    35,    36,    37,
       6,     8,    23,    24,     7,    26,    50,    12,    13,   120,
     121,    22,     6,    57,    35,    20,    22,    28,    29,    30,
      31,    35,    28,    29,    30,    31,     6,     9,    22,    10,
      11,    35,    34,    10,    28,    29,    30,    31,    22,    35,
      10,     5,    22,    33,    10,    29,    30,    31,    28,    29,
      30,    31,    22,     6,    10,     9,    22,    35,    28,    29,
      30,    31,    28,    29,    30,    31,    22,    10,    10,     7,
      35,    10,    28,    29,    30,    31,    34,     5,    35,    22,
       5,     5,     9,    22,     5,    28,    29,    30,    31,    28,
      29,    30,    31,    22,     8,     8,    33,     5,     9,    28,
      29,    30,    31,    22,     9,    34,    32,    22,     9,    28,
      29,    30,    31,    22,    33,    35,    33,     6,    25,    28,
      29,    30,    31,     6,    59,    48,    32,     8,    -1,    65,
     130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    42,    43,    35,     0,     7,    18,    19,    44,
      45,    46,    19,    12,    13,    53,    54,    55,     8,    44,
      44,    20,    47,    54,    35,     9,    56,    35,    34,    52,
      10,     5,    35,    33,    21,    48,    49,    54,    52,     9,
       6,    35,    10,     7,    34,    50,    35,    51,    53,    54,
       7,    15,    23,    24,    26,    35,    57,    58,    51,    35,
      57,     5,     5,     9,    11,    14,    16,    30,    35,    36,
      37,    60,    61,    62,     5,     5,     9,    59,     8,    57,
      50,     8,    61,    61,    61,    55,     5,    61,     5,    61,
      33,    22,    28,    29,    30,    31,     9,    61,    61,    61,
      32,     6,     6,    10,     9,    35,    61,    63,    64,    61,
      61,    61,    61,    61,     6,     6,    10,    61,    33,    61,
       9,    34,    65,     6,    10,    58,    58,    33,    10,    61,
      61,    25,    10,    65,    58,     6
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
        case 2:
#line 137 "ijparser.y"
    {(yyval.is_root_t) = insert_start_list((yyvsp[(1) - (1)].is_program_t));tree = (yyval.is_root_t); }
    break;

  case 3:
#line 139 "ijparser.y"
    {(yyval.is_program_t) = insert_program((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].field_or_method_t));}
    break;

  case 4:
#line 141 "ijparser.y"
    {(yyval.field_or_method_t) = insert_field_or_method(NULL, NULL, NULL);}
    break;

  case 5:
#line 142 "ijparser.y"
    { (yyval.field_or_method_t) = insert_field_or_method((yyvsp[(1) - (2)].field_decl_t), NULL, (yyvsp[(2) - (2)].field_or_method_t));}
    break;

  case 6:
#line 143 "ijparser.y"
    { (yyval.field_or_method_t) = insert_field_or_method(NULL, (yyvsp[(1) - (2)].method_decl_t), (yyvsp[(2) - (2)].field_or_method_t)); }
    break;

  case 7:
#line 146 "ijparser.y"
    { (yyval.field_decl_t) = insert_field_declaration((yyvsp[(2) - (2)].field_declarator_t));}
    break;

  case 8:
#line 149 "ijparser.y"
    { (yyval.method_decl_t) = insert_method_declaration((yyvsp[(3) - (11)].is_function_type_t), (yyvsp[(4) - (11)].identifier), (yyvsp[(6) - (11)].is_opt_formal_params_t), (yyvsp[(9) - (11)].is_opt_var_decl_t), (yyvsp[(10) - (11)].is_opt_statement_t)); }
    break;

  case 9:
#line 152 "ijparser.y"
    { (yyval.is_function_type_t) = insert_function_type((yyvsp[(1) - (1)].is_type_specifier_t)); }
    break;

  case 10:
#line 153 "ijparser.y"
    { (yyval.is_function_type_t) = insert_function_type(NULL); }
    break;

  case 11:
#line 156 "ijparser.y"
    {(yyval.is_opt_formal_params_t) = insert_opt_formal_params(NULL);}
    break;

  case 12:
#line 157 "ijparser.y"
    {(yyval.is_opt_formal_params_t) = insert_opt_formal_params((yyvsp[(1) - (1)].is_formal_params_t));}
    break;

  case 13:
#line 160 "ijparser.y"
    { (yyval.is_formal_params_t) = insert_formal_params((yyvsp[(1) - (3)].is_type_specifier_t), (yyvsp[(2) - (3)].identifier), (yyvsp[(3) - (3)].is_formal_params_list_t)); }
    break;

  case 14:
#line 161 "ijparser.y"
    { (yyval.is_formal_params_t) = insert_formal_params(NULL, (yyvsp[(4) - (4)].identifier), NULL); }
    break;

  case 15:
#line 164 "ijparser.y"
    { (yyval.is_formal_params_list_t) = insert_formal_params_list(NULL,NULL,NULL);}
    break;

  case 16:
#line 165 "ijparser.y"
    { (yyval.is_formal_params_list_t) = insert_formal_params_list((yyvsp[(2) - (4)].is_type_specifier_t), (yyvsp[(3) - (4)].identifier), (yyvsp[(4) - (4)].is_formal_params_list_t));}
    break;

  case 17:
#line 168 "ijparser.y"
    { (yyval.is_opt_var_decl_t) = insert_opt_var_decl(NULL,NULL); }
    break;

  case 18:
#line 169 "ijparser.y"
    { (yyval.is_opt_var_decl_t) = insert_opt_var_decl((yyvsp[(1) - (2)].field_declarator_t), (yyvsp[(2) - (2)].is_opt_var_decl_t)); }
    break;

  case 19:
#line 172 "ijparser.y"
    { (yyval.field_declarator_list_t) = insert_opt_vars(NULL,NULL); }
    break;

  case 20:
#line 173 "ijparser.y"
    { (yyval.field_declarator_list_t) = insert_opt_vars((yyvsp[(2) - (3)].identifier), (yyvsp[(3) - (3)].field_declarator_list_t)); }
    break;

  case 21:
#line 176 "ijparser.y"
    { (yyval.field_declarator_t) = insert_field_declarator((yyvsp[(1) - (4)].is_type_specifier_t), (yyvsp[(2) - (4)].identifier), (yyvsp[(3) - (4)].field_declarator_list_t)); }
    break;

  case 22:
#line 179 "ijparser.y"
    { (yyval.is_type_specifier_t) = insert_type_specifier((yyvsp[(1) - (2)].is_var_type_t), (yyvsp[(2) - (2)].is_opt_array_t)); }
    break;

  case 23:
#line 182 "ijparser.y"
    { (yyval.is_var_type_t) = insert_type(is_int); }
    break;

  case 24:
#line 183 "ijparser.y"
    { (yyval.is_var_type_t) = insert_type(is_bool); }
    break;

  case 25:
#line 186 "ijparser.y"
    { (yyval.is_opt_array_t) = insert_opt_array(not_array); }
    break;

  case 26:
#line 187 "ijparser.y"
    { (yyval.is_opt_array_t) = insert_opt_array(is_array); }
    break;

  case 27:
#line 190 "ijparser.y"
    { (yyval.is_opt_statement_t) = insert_opt_statement(NULL,NULL); }
    break;

  case 28:
#line 191 "ijparser.y"
    { (yyval.is_opt_statement_t) = insert_opt_statement((yyvsp[(1) - (2)].is_statement_t), (yyvsp[(2) - (2)].is_opt_statement_t)); }
    break;

  case 29:
#line 194 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement((yyvsp[(2) - (3)].is_opt_statement_t), compound_stm, NULL, NULL, NULL, NULL, NULL, NULL); }
    break;

  case 30:
#line 195 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, if_stm, (yyvsp[(5) - (5)].is_statement_t), NULL, NULL, NULL, (yyvsp[(3) - (5)].is_expression_t), NULL); }
    break;

  case 31:
#line 196 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, else_stm, (yyvsp[(5) - (7)].is_statement_t), (yyvsp[(7) - (7)].is_statement_t), NULL, NULL, (yyvsp[(3) - (7)].is_expression_t), NULL); }
    break;

  case 32:
#line 197 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, while_stm, (yyvsp[(5) - (5)].is_statement_t), NULL, NULL, NULL, (yyvsp[(3) - (5)].is_expression_t), NULL); }
    break;

  case 33:
#line 198 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, print_stm, NULL, NULL, NULL, NULL, (yyvsp[(3) - (5)].is_expression_t), NULL); }
    break;

  case 34:
#line 199 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, store_stm, NULL, NULL, (yyvsp[(1) - (5)].identifier), (yyvsp[(2) - (5)].is_opt_array_pos_t), (yyvsp[(4) - (5)].is_expression_t), NULL); }
    break;

  case 35:
#line 200 "ijparser.y"
    { (yyval.is_statement_t) = insert_statement(NULL, return_stm, NULL, NULL, NULL, NULL, NULL, (yyvsp[(2) - (3)].is_opt_expr_t)); }
    break;

  case 36:
#line 204 "ijparser.y"
    { (yyval.is_opt_array_pos_t) = insert_opt_array_pos(NULL); }
    break;

  case 37:
#line 205 "ijparser.y"
    { (yyval.is_opt_array_pos_t) = insert_opt_array_pos((yyvsp[(2) - (3)].is_expression_t)); }
    break;

  case 38:
#line 208 "ijparser.y"
    { (yyval.is_opt_expr_t) = insert_opt_expr(NULL); }
    break;

  case 39:
#line 209 "ijparser.y"
    { (yyval.is_opt_expr_t) = insert_opt_expr((yyvsp[(1) - (1)].is_expression_t)); }
    break;

  case 40:
#line 213 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(new_expr,NULL,(yyvsp[(4) - (5)].is_expression_t),NULL,(yyvsp[(2) - (5)].is_var_type_t),NULL); }
    break;

  case 41:
#line 214 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(op_expr,NULL,(yyvsp[(1) - (3)].is_expression_t),(yyvsp[(3) - (3)].is_expression_t),NULL,(yyvsp[(2) - (3)].value)); }
    break;

  case 42:
#line 215 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(op_expr,NULL,(yyvsp[(1) - (3)].is_expression_t),(yyvsp[(3) - (3)].is_expression_t),NULL,(yyvsp[(2) - (3)].value)); }
    break;

  case 43:
#line 216 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(op_expr,NULL,(yyvsp[(1) - (3)].is_expression_t),(yyvsp[(3) - (3)].is_expression_t),NULL,(yyvsp[(2) - (3)].value)); }
    break;

  case 44:
#line 217 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(op_expr,NULL,(yyvsp[(1) - (3)].is_expression_t),(yyvsp[(3) - (3)].is_expression_t),NULL,(yyvsp[(2) - (3)].value)); }
    break;

  case 45:
#line 218 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(op3_expr,NULL,(yyvsp[(2) - (2)].is_expression_t),NULL,NULL,(yyvsp[(1) - (2)].value)); }
    break;

  case 46:
#line 219 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(not_expr,NULL,(yyvsp[(2) - (2)].is_expression_t),NULL,NULL,(yyvsp[(1) - (2)].value)); }
    break;

  case 47:
#line 220 "ijparser.y"
    { (yyval.is_expression_t) = insert_expression(array_expr2,(yyvsp[(1) - (1)].is_array_dim_t),NULL,NULL,NULL,NULL); }
    break;

  case 48:
#line 223 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim((yyvsp[(1) - (1)].identifier), NULL, NULL, NULL, 3);}
    break;

  case 49:
#line 224 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim(NULL, NULL, NULL, (yyvsp[(1) - (1)].value), 1); }
    break;

  case 50:
#line 225 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim(NULL, NULL, NULL, (yyvsp[(1) - (1)].value), 2); }
    break;

  case 51:
#line 226 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim(NULL, (yyvsp[(2) - (3)].is_expression_t), NULL, NULL, 4); }
    break;

  case 52:
#line 227 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim(NULL, (yyvsp[(1) - (2)].is_expression_t), NULL, NULL, 5);  }
    break;

  case 53:
#line 228 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim((yyvsp[(3) - (7)].identifier),(yyvsp[(5) - (7)].is_expression_t),NULL,NULL, 6);}
    break;

  case 54:
#line 229 "ijparser.y"
    { (yyval.is_array_dim_t) = insert_array_dim((yyvsp[(1) - (4)].identifier),NULL,(yyvsp[(3) - (4)].is_opt_args_t), NULL, 7); }
    break;

  case 55:
#line 230 "ijparser.y"
    { }
    break;

  case 56:
#line 231 "ijparser.y"
    { }
    break;

  case 57:
#line 234 "ijparser.y"
    { (yyval.is_opt_args_t) = insert_opt_args(NULL); }
    break;

  case 58:
#line 235 "ijparser.y"
    { (yyval.is_opt_args_t) = insert_opt_args((yyvsp[(1) - (1)].is_args_t)); }
    break;

  case 59:
#line 238 "ijparser.y"
    { (yyval.is_args_t) = insert_args((yyvsp[(1) - (2)].is_expression_t), (yyvsp[(2) - (2)].is_opt_args_list_t)); }
    break;

  case 60:
#line 241 "ijparser.y"
    { (yyval.is_opt_args_list_t) = insert_opt_arg(NULL, NULL); }
    break;

  case 61:
#line 242 "ijparser.y"
    { (yyval.is_opt_args_list_t) = insert_opt_arg((yyvsp[(2) - (3)].is_expression_t), (yyvsp[(3) - (3)].is_opt_args_list_t)); }
    break;


/* Line 1267 of yacc.c.  */
#line 1861 "y.tab.c"
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


#line 247 "ijparser.y"


int main(int argc, char* argv[])
{
    coluna = 0;
    linha = 1;
    yyparse();

    if(error == 0) {
        show_program(tree);
    }

    return 0;
}

int yyerror(char *s)
{
    printf ("Line %d, col %zd: %s: %s\n", linha, coluna - strlen(yytext) + 1, s, yytext);
    error=1;
    return 0;
}










