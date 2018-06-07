/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "FirstYacc.y" /* yacc.c:339  */

#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "SymbolTable.h"
extern int yyerror(char *s);
int yylex();
symTable myTable;
int funcArgSize;
int constDeclar;
char errWord[256];
char *declareErr = "error: declare fall";
FILE *myJavaCode;

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    IF = 259,
    BOOL = 260,
    BREAK = 261,
    CHAR = 262,
    CONTINUE = 263,
    DO = 264,
    ELSE = 265,
    ENUM = 266,
    EXTERN = 267,
    FALSE = 268,
    FOR = 269,
    FN = 270,
    IN = 271,
    LET = 272,
    LOOP = 273,
    MATCH = 274,
    MUT = 275,
    PRINT = 276,
    PRINTLN = 277,
    PUB = 278,
    RETURN = 279,
    SELF = 280,
    STATIC = 281,
    STRUCT = 282,
    TRUE = 283,
    USE = 284,
    WHERE = 285,
    WHILE = 286,
    LESS_EQUAL = 287,
    GREAT_EQUAL = 288,
    EQUAL = 289,
    NOT_EQUAL = 290,
    AND_DOUBLE = 291,
    OR_DOUBLE = 292,
    ADD_DOUBLE = 293,
    SUB_DOUBLE = 294,
    ADD_EQUAL = 295,
    SUB_EQUAL = 296,
    MUL_EQUAL = 297,
    DIV_EQUAL = 298,
    STR = 299,
    ID = 300,
    REAL_NUMBER = 301,
    INT = 302,
    FLOAT = 303
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define IF 259
#define BOOL 260
#define BREAK 261
#define CHAR 262
#define CONTINUE 263
#define DO 264
#define ELSE 265
#define ENUM 266
#define EXTERN 267
#define FALSE 268
#define FOR 269
#define FN 270
#define IN 271
#define LET 272
#define LOOP 273
#define MATCH 274
#define MUT 275
#define PRINT 276
#define PRINTLN 277
#define PUB 278
#define RETURN 279
#define SELF 280
#define STATIC 281
#define STRUCT 282
#define TRUE 283
#define USE 284
#define WHERE 285
#define WHILE 286
#define LESS_EQUAL 287
#define GREAT_EQUAL 288
#define EQUAL 289
#define NOT_EQUAL 290
#define AND_DOUBLE 291
#define OR_DOUBLE 292
#define ADD_DOUBLE 293
#define SUB_DOUBLE 294
#define ADD_EQUAL 295
#define SUB_EQUAL 296
#define MUL_EQUAL 297
#define DIV_EQUAL 298
#define STR 299
#define ID 300
#define REAL_NUMBER 301
#define INT 302
#define FLOAT 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "FirstYacc.y" /* yacc.c:355  */

    struct
    {

        char *name;
        
        union{
            char *val_str;
            int  val_int;
            bool val_flag;
            float val_float;
        };
        char* concat_name;
        // if it is an array element it should be store the index
        int arr_idx;
        // int => 0 = T_INT bool => 1 = T_BOOL string => 3 = T_STR real => 3 = T_REAL
        int val_type;
        //0 => id || 1 => primitive type for passing data by $$ to recognize
        int state; 
    }Data;

#line 241 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    58,    50,     2,
      68,    69,    56,    54,    64,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    60,
      52,    61,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    65,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    49,    67,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   125,   126,   129,   130,   131,   132,   133,
     134,   139,   140,   143,   144,   145,   148,   148,   189,   189,
     240,   264,   296,   321,   320,   357,   369,   405,   418,   473,
     487,   492,   497,   502,   507,   514,   523,   536,   544,   556,
     602,   607,   614,   618,   627,   634,   634,   674,   674,   692,
     691,   748,   747,   778,   810,   840,   865,   890,   894,   902,
     906,   912,   916,   924,   928,   928,   936,  1002,  1003,  1004,
    1005,  1006,  1007,  1018,  1050,  1073,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1113,  1114,  1117
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "IF", "BOOL", "BREAK",
  "CHAR", "CONTINUE", "DO", "ELSE", "ENUM", "EXTERN", "FALSE", "FOR", "FN",
  "IN", "LET", "LOOP", "MATCH", "MUT", "PRINT", "PRINTLN", "PUB", "RETURN",
  "SELF", "STATIC", "STRUCT", "TRUE", "USE", "WHERE", "WHILE",
  "LESS_EQUAL", "GREAT_EQUAL", "EQUAL", "NOT_EQUAL", "AND_DOUBLE",
  "OR_DOUBLE", "ADD_DOUBLE", "SUB_DOUBLE", "ADD_EQUAL", "SUB_EQUAL",
  "MUL_EQUAL", "DIV_EQUAL", "STR", "ID", "REAL_NUMBER", "INT", "FLOAT",
  "'|'", "'&'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "';'", "'='", "':'", "'['", "','", "']'", "'{'", "'}'", "'('",
  "')'", "$accept", "program", "statements", "statement", "declared",
  "identifier_declared", "constant_declared", "$@1", "$@2",
  "Variable_declared", "$@3", "Array_declared", "standard_data_type",
  "standard_data", "formal_argment", "formal_arguments", "func_block",
  "func_sign", "func_declared", "$@4", "$@5", "$@6", "$@7", "simple_state",
  "func_arg", "func_invoke", "block", "$@8", "object", "expression",
  "bool_exp", "condition", "loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   124,
      38,    33,    60,    62,    43,    45,    42,    47,    37,    94,
      59,    61,    58,    91,    44,    93,   123,   125,    40,    41
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   -58,  -117,  -117,    -7,   100,   100,    82,   -56,  -117,
      23,  -117,  -117,    68,   100,   -49,   100,    40,  -117,    73,
    -117,   -39,  -117,  -117,  -117,  -117,    30,  -117,  -117,  -117,
    -117,  -117,    54,   175,  -117,  -117,    68,    31,   -46,    11,
     176,   183,  -117,   190,    68,    68,   100,     3,   175,   -29,
    -117,    73,    45,  -117,  -117,  -117,    12,   100,   100,   100,
     100,    68,    68,    68,    68,    68,    68,    68,    68,   125,
      90,  -117,    21,  -117,  -117,  -117,   137,   163,   -32,  -117,
      16,   165,    22,  -117,   -38,   -29,   -29,  -117,  -117,   175,
     175,   175,   175,   175,   175,   175,   175,    26,    59,    21,
      21,   100,  -117,  -117,  -117,  -117,  -117,    32,    26,  -117,
      37,  -117,   100,  -117,    72,    80,    74,    71,   133,  -117,
    -117,  -117,    85,    99,    54,  -117,  -117,   100,  -117,    21,
      96,    88,   121,   112,    26,     9,   100,   100,   197,  -117,
      21,    15,  -117,  -117,   122,    88,  -117,  -117,  -117,  -117,
     148,    54,  -117,  -117,  -117,   109,    21,  -117,   162,  -117,
      88,  -117,  -117,   160,  -117,    88,   146,  -117,   130,    21,
     132,   157,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    36,    44,     0,     0,     0,     0,     0,    37,
      66,    35,    38,     0,     0,    64,     0,     0,     2,     3,
       5,     0,    13,    14,    15,    69,     0,    11,     6,    67,
      10,    68,    76,     7,     8,     9,     0,     0,     0,    66,
       0,     0,    57,     0,     0,     0,     0,     0,    77,    70,
      63,     0,     0,     1,     4,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    16,     0,    55,    56,    58,     0,     0,     0,    62,
       0,    60,     0,    71,     0,    74,    75,    72,    73,    80,
      81,    82,    83,    84,    85,    78,    79,     0,     0,     0,
       0,     0,    31,    32,    33,    30,    34,     0,     0,    53,
       0,    61,     0,    65,     0,    47,    41,     0,    87,    21,
      22,    20,    28,     0,    17,    18,    88,     0,    59,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,    39,
       0,     0,    48,    40,     0,     0,    86,    26,    23,    25,
       0,    19,    54,    51,    42,     0,     0,    46,     0,    29,
       0,    43,    49,     0,    52,     0,     0,    50,     0,     0,
       0,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,   -16,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,   -95,  -117,  -117,    86,  -116,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,   102,  -117,   -91,  -117,  -117,    -5,
     120,  -117,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,   101,   137,    23,
     158,    24,   107,    25,   116,   117,   142,    26,    27,   145,
     131,   165,   160,    28,    80,    29,    30,    51,    31,    32,
      33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    41,    43,    54,   122,   123,   118,   114,     2,    49,
      36,    52,    44,    37,   147,    71,    72,   126,    50,     1,
       2,    55,    57,    58,    59,    60,   102,    59,    60,   157,
       3,   115,     4,   110,   139,    82,     5,     6,    38,     7,
      53,    78,    81,   146,   164,   153,     8,     9,    39,   167,
      11,    12,    85,    86,    87,    88,   148,   149,    14,     9,
      10,   162,    11,    12,   119,   103,    13,   104,   105,   106,
      14,    16,    79,     2,   170,    56,    70,     1,     2,    47,
      84,    15,   154,    16,    45,   111,    46,     2,     3,   113,
       4,    47,    15,   125,     5,     6,   124,     7,   127,    57,
      58,    59,    60,   120,     8,     2,   121,    81,    57,    58,
      59,    60,     9,    39,    83,    11,    12,     9,    10,    13,
      11,    12,   138,    14,    13,   155,     9,    39,    14,    11,
      12,   150,   151,    48,   129,   130,    16,    14,   132,    15,
     133,    16,    42,   134,     9,    39,   135,    11,    12,   140,
      16,    98,    99,   100,   141,    14,    69,    61,    62,    63,
      64,    65,    66,   136,    76,    77,   114,   144,    16,    61,
      62,    63,    64,    65,    66,   156,   161,    67,    68,   163,
     166,    89,    90,    91,    92,    93,    94,    95,    96,    67,
      68,   168,   169,   171,    97,    61,    62,    63,    64,    65,
      66,   172,    57,    58,    59,    60,   108,    61,    62,    63,
      64,    65,    66,   159,   128,    67,    68,     0,   143,    57,
      58,    59,    60,   109,     0,     0,     0,    67,    68,   112,
      57,    58,    59,    60,     0,     0,    73,    57,    58,    59,
      60,     0,     0,    74,    57,    58,    59,    60,     0,     0,
      75,    57,    58,    59,    60,     0,     0,   152
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,    19,    99,   100,    97,    45,     5,    14,
      68,    16,    68,    20,     5,    61,    62,   108,    67,     4,
       5,    60,    54,    55,    56,    57,     5,    56,    57,   145,
      15,    69,    17,    65,   129,    51,    21,    22,    45,    24,
       0,    46,    47,   134,   160,   140,    31,    44,    45,   165,
      47,    48,    57,    58,    59,    60,    47,    48,    55,    44,
      45,   156,    47,    48,     5,    44,    51,    46,    47,    48,
      55,    68,    69,     5,   169,    45,    45,     4,     5,    68,
      68,    66,    67,    68,    61,    69,    63,     5,    15,    67,
      17,    68,    66,    61,    21,    22,   101,    24,    61,    54,
      55,    56,    57,    44,    31,     5,    47,   112,    54,    55,
      56,    57,    44,    45,    69,    47,    48,    44,    45,    51,
      47,    48,   127,    55,    51,   141,    44,    45,    55,    47,
      48,   136,   137,    13,    62,    55,    68,    55,    64,    66,
      69,    68,    60,    10,    44,    45,    61,    47,    48,    53,
      68,    61,    62,    63,    66,    55,    36,    32,    33,    34,
      35,    36,    37,    64,    44,    45,    45,    55,    68,    32,
      33,    34,    35,    36,    37,    53,    67,    52,    53,    17,
      20,    61,    62,    63,    64,    65,    66,    67,    68,    52,
      53,    45,    62,    61,    69,    32,    33,    34,    35,    36,
      37,    44,    54,    55,    56,    57,    69,    32,    33,    34,
      35,    36,    37,    65,   112,    52,    53,    -1,   132,    54,
      55,    56,    57,    60,    -1,    -1,    -1,    52,    53,    64,
      54,    55,    56,    57,    -1,    -1,    60,    54,    55,    56,
      57,    -1,    -1,    60,    54,    55,    56,    57,    -1,    -1,
      60,    54,    55,    56,    57,    -1,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    15,    17,    21,    22,    24,    31,    44,
      45,    47,    48,    51,    55,    66,    68,    71,    72,    73,
      74,    75,    76,    79,    81,    83,    87,    88,    93,    95,
      96,    98,    99,   100,   101,   102,    68,    20,    45,    45,
      99,    99,    60,    99,    68,    61,    63,    68,   100,    99,
      67,    97,    99,     0,    72,    60,    45,    54,    55,    56,
      57,    32,    33,    34,    35,    36,    37,    52,    53,   100,
      45,    61,    62,    60,    60,    60,   100,   100,    99,    69,
      94,    99,    72,    69,    68,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,    69,    61,    62,
      63,    77,     5,    44,    46,    47,    48,    82,    69,    60,
      65,    69,    64,    67,    45,    69,    84,    85,    96,     5,
      44,    47,    82,    82,    99,    61,    96,    61,    94,    62,
      55,    90,    64,    69,    10,    61,    64,    78,    99,    82,
      53,    66,    86,    85,    55,    89,    96,     5,    47,    48,
      99,    99,    60,    82,    67,    72,    53,    86,    80,    65,
      92,    67,    82,    17,    86,    91,    20,    86,    45,    62,
      82,    61,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    77,    76,    78,    76,
      79,    79,    79,    80,    79,    79,    79,    79,    79,    81,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    84,
      85,    85,    86,    86,    87,    89,    88,    90,    88,    91,
      88,    92,    88,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    96,    97,    96,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     0,     5,     0,     7,
       5,     5,     5,     0,    15,     7,     7,     3,     5,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     3,     1,     0,     7,     0,     6,     0,
      10,     0,     9,     4,     7,     3,     3,     2,     3,     3,
       1,     4,     3,     2,     0,     4,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     5,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 122 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statements reducing to program\n");}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement reducing to statements\n");}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement statements reducing to statements\n");}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 129 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("declared reducing to statement\n");}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 130 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("simple_state reducing to statement\n");}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 131 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("bool_exp reducing to statement\n");}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 132 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("condition reducing to statement\n");}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("loop reducing to statement\n");}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("block reducing to statement\n");}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("func_declared reducing to declared\n");}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("identifier_declared ';' reducing to declared\n");}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("constant_declared reducing to identifier_declared\n");}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 144 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Variable_declared reducing to identifier_declared\n");}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Array_declared reducing to identifier_declared\n");}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "FirstYacc.y" /* yacc.c:1646  */
    {constDeclar = 1;}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-3].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            constDeclar = 0;
        }
        else if((yyvsp[0].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-3].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-3].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            
        }
        else if((yyvsp[0].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-3].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET ID '=' standard_data_type reducing to constant_declared\n");
    }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "FirstYacc.y" /* yacc.c:1646  */
    {constDeclar = 1;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 190 "FirstYacc.y" /* yacc.c:1646  */
    {
        constDeclar = 0;
        if((yyvsp[-3].Data).val_type != (yyvsp[0].Data).val_type)
        {
            yyerror(declareErr);
        }
        if((yyvsp[-3].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-5].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-3].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-5].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-3].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-5].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-3].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-5].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET ID ':' standard_data_type '=' standard_data reducing to constant_declared\n");
    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 241 "FirstYacc.y" /* yacc.c:1646  */
    {

        variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-2].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' FLOAT reducing to Variable_declared\n");
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s = %d\n", (yyvsp[-2].Data).name, (yyvsp[0].Data).val_int);
        else
        {
            variableNode *w = myTable.lookupVar_for_index((yyvsp[-2].Data).name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            fprintf(myJavaCode, "\t\tsipush %d\n",(yyvsp[0].Data).val_int);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }

    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 265 "FirstYacc.y" /* yacc.c:1646  */
    {

        variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-2].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal()){
            if((yyvsp[0].Data).val_flag == false)
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", (yyvsp[-2].Data).name, 0);
            else
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", (yyvsp[-2].Data).name, 1);
        }
        else
        {
            
            variableNode *w = myTable.lookupVar_for_index((yyvsp[-2].Data).name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            if((yyvsp[0].Data).val_flag == false)
                fprintf(myJavaCode, "\t\tsipush %d\n",0);
            else
                fprintf(myJavaCode, "\t\tsipush %d\n",1);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        
        }
        
    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 297 "FirstYacc.y" /* yacc.c:1646  */
    {
       
        if((yyvsp[0].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }

        Trace("LET MUT ID '=' standard_data reducing to Variable_declared\n");
    }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 321 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-4].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s = %d\n", (yyvsp[-4].Data).name, (yyvsp[0].Data).val_int);
        else
        {
            variableNode *w = myTable.lookupVar_for_index((yyvsp[-4].Data).name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            fprintf(myJavaCode, "\t\tsipush %d\n",(yyvsp[0].Data).val_int);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }
    }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 346 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-10].Data).val_type != (yyvsp[-8].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_STR,(yyvsp[-8].Data).val_str,(yyvsp[-12].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 358 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-4].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 370 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-4].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal()){
            printf("%d\n\n\n",(yyvsp[0].Data).val_flag);
            if((yyvsp[0].Data).val_flag == false)
            {
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", (yyvsp[-4].Data).name, 0);
            }
            else{
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", (yyvsp[-4].Data).name, 1);
            }
                
        }
        else
        {
            variableNode *w = myTable.lookupVar_for_index((yyvsp[-4].Data).name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            if((yyvsp[0].Data).val_flag == false)
                fprintf(myJavaCode, "\t\tsipush %d\n",0);
            else
                fprintf(myJavaCode, "\t\tsipush %d\n",1);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }
    }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 406 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v(VAL_INT,0,(yyvsp[0].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID reducing to Variable_declared\n");
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s\n", (yyvsp[0].Data).name);
        
    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 419 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            if(myTable.checkGlobal())
                fprintf(myJavaCode, "\tfield static int %s\n", (yyvsp[-2].Data).name);
        }
        else if((yyvsp[0].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,true,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            if(myTable.checkGlobal()){
                if((yyvsp[0].Data).val_flag == false)
                    fprintf(myJavaCode, "\tfield static bool %s \n", (yyvsp[-2].Data).name);
                else
                    fprintf(myJavaCode, "\tfield static bool %s \n", (yyvsp[-2].Data).name);
            }
        }

        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type reducing to constant_declared\n");
    }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 474 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].Data).val_type!= VAL_INT)
        {
            yyerror(declareErr);
        }
        if(!myTable.array_declare((yyvsp[-3].Data).val_type,(yyvsp[-1].Data).val_int,(yyvsp[-5].Data).name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' standard_data_type ',' expression ']' reducing to Array_declared\n");
    }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 488 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;
        Trace("INT reducing to standard_data_type\n");
    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 493 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;
        Trace("BOOL reducing to standard_data_type\n");
    }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 498 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;
        Trace("STR reducing to standard_data_type\n");
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 503 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_REAL;
        Trace("REAL_NUMBER reducing to standard_data_type\n");
    }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 508 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;
        Trace("FLOAT reducing to standard_data_type\n");
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 515 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;(yyval.Data).val_int = (yyvsp[0].Data).val_int; 
        Trace("INT reducing to standard_data\n");
        
        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tsipush %d\n", (yyvsp[0].Data).val_int);
        
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 524 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;(yyval.Data).val_flag = (yyvsp[0].Data).val_flag; 
        Trace("BOOL reducing to standard_data\n");
        
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            if((yyval.Data).val_flag)    
                fprintf(myJavaCode, "\t\iconst_1 %d\n", 1);
            else        
                fprintf(myJavaCode, "\t\iconst_0 %d\n", 0);
        }    
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 537 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;(yyval.Data).val_str = (yyvsp[0].Data).val_str;
        Trace("STR reducing to standard_data\n");

        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tldc \"%s\" \n", (yyvsp[0].Data).val_str);
     }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 545 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;(yyval.Data).val_float = (yyvsp[0].Data).val_float; 
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            fprintf(myJavaCode, "\t\tsipush %d\n", (yyvsp[0].Data).val_float);
        }

        Trace("FLOAT reducing to standard_data\n");
    }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 557 "FirstYacc.y" /* yacc.c:1646  */
    {

        if((yyvsp[0].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,0,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,TRUE,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("ID ':' standard_data_type reducing to formal_argment\n");
    }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 603 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argment ',' formal_arguments reducing to formal_arguments\n");
    }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 608 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argument reducing to formal_arguments\n");
    }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 614 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
        fprintf(myJavaCode,"\t}\n");
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 618 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
        fprintf(myJavaCode,"\t}\n");
    }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 627 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize = 0;
        myTable.pushTable();printf("create new table\n");
        
        }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 634 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        variableNode v(VAL_NULL,(yyvsp[-3].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        fprintf(myJavaCode,"\tmethod public static void %s(", (yyvsp[-3].Data).name);

        for(int i = 0;i< funcArgSize;i++)
        {
            myTable.dumpTable();
            variableNode * target = myTable.pushTableVar(i);
            if(target!=NULL)
            {
                if(target->val_Type == VAL_INT)
                {
                    fprintf(myJavaCode,"int");
                }
                else if(target->val_Type == VAL_BOOL)
                {
                    fprintf(myJavaCode,"boolean");
                }
                else if(target->val_Type == VAL_STR)
                {
                    fprintf(myJavaCode,"srting");
                }
 
            }
            else
                break;

            if(i<funcArgSize-1)fprintf(myJavaCode,", ");
        }
        fprintf(myJavaCode,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        Trace("FN ID '(' formal_arguments ')' reducing to func_declared\n");

    }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 674 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v(VAL_NULL,(yyvsp[-2].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        if (strcmp((yyvsp[-2].Data).name, "main") == 0){
            fprintf(myJavaCode,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        }
        else{
            fprintf(myJavaCode,"\tmethod public static void %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", (yyvsp[-2].Data).name);
        }

        Trace("FN ID '(' ')' reducing to func_declared\n");
    }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 692 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v((yyvsp[0].Data).val_type,(yyvsp[-6].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }

        if (strcmp((yyvsp[-6].Data).name, "main") == 0){
            if((yyvsp[0].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }    
        else{
            if((yyvsp[0].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int %s(", (yyvsp[-6].Data).name);
            else if((yyvsp[0].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean %s(", (yyvsp[-6].Data).name);
            else if((yyvsp[0].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string %s(", (yyvsp[-6].Data).name);
            }

        for(int i = 0;i< funcArgSize;i++)
        {
            myTable.dumpTable();
            variableNode * target = myTable.pushTableVar(i);
            if(target!=NULL)
            {
                if(target->val_Type == VAL_INT)
                {
                    fprintf(myJavaCode,"int");
                }
                else if(target->val_Type == VAL_BOOL)
                {
                    fprintf(myJavaCode,"boolean");
                }
                else if(target->val_Type == VAL_STR)
                {
                    fprintf(myJavaCode,"srting");
                }
 
            }
            else
                break;

            if(i<funcArgSize-1)fprintf(myJavaCode,", ");
        }
        fprintf(myJavaCode,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
 
        Trace("FN ID '(' formal_arguments ')' func_sign standard_data_type reducing to func_declared\n");
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 748 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v((yyvsp[0].Data).val_type,(yyvsp[-5].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }

        if (strcmp((yyvsp[-5].Data).name, "main") == 0){
            if((yyvsp[0].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        }    
        else{
            if((yyvsp[0].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", (yyvsp[-5].Data).name);
            else if((yyvsp[0].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", (yyvsp[-5].Data).name);
            else if((yyvsp[0].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", (yyvsp[-5].Data).name);
        }
        Trace("FN ID '(' ')' func_sign standard_data_type reducing to func_declared\n");
    }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 779 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode *v = myTable.lookupVar((yyvsp[-3].Data).name);
        if(v->isGlobal)
        {
            fprintf(myJavaCode,"\t\tputstatic int Project.%s\n", (yyvsp[-3].Data).name);
        }
        else{
            fprintf(myJavaCode, "\t\tistore %d\n", v->index);
        }
        if((yyvsp[-1].Data).val_type == VAL_INT)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_int,(yyvsp[-3].Data).name,true);
            myTable.assignVal(v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_FLOAT)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_float,(yyvsp[-3].Data).name,true);
            myTable.assignVal(v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_STR)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_str,(yyvsp[-3].Data).name,true);
            myTable.assignVal(v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_BOOL)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_flag,(yyvsp[-3].Data).name,true);
            myTable.assignVal(v);
        }
        Trace("ID '=' bool_exp ';' reducing to simple_state\n");
    }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 811 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        if((yyvsp[-4].Data).val_type != VAL_INT)
        {
            strcpy(errWord,"need integer type\n");
            yyerror(errWord);
        }
        if((yyvsp[-1].Data).val_type == VAL_INT)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_int,(yyvsp[-6].Data).name,false);
            myTable.assignArr((yyvsp[-4].Data).val_int,v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_FLOAT)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_float,(yyvsp[-6].Data).name,false);
            myTable.assignArr((yyvsp[-4].Data).val_int,v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_STR)
        {
            variableNode v((yyvsp[-1].Data).val_type,strdup((yyvsp[-1].Data).val_str),(yyvsp[-6].Data).name,false);
            myTable.assignArr((yyvsp[-4].Data).val_int,v);
        }
        else if((yyvsp[-1].Data).val_type == VAL_BOOL)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_flag,(yyvsp[-6].Data).name,false);
            myTable.assignArr((yyvsp[-4].Data).val_int,v);
        }
        Trace("ID '[' expression ']' '=' expression ';' reducing to simple_state\n");
    }
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 841 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].Data).val_type == VAL_INT)
        {
            printf("%d\n",(yyvsp[-1].Data).val_int);
        }
        else if((yyvsp[-1].Data).val_type == VAL_FLOAT)
        {
            printf("%f\n",(yyvsp[-1].Data).val_float);
        }
        else if((yyvsp[-1].Data).val_type == VAL_BOOL)
        {
            printf("%d\n",(yyvsp[-1].Data).val_flag);
        }
        else if((yyvsp[-1].Data).val_type == VAL_STR)
        {
            printf("%s\n",(yyvsp[-1].Data).val_str);
        }
        else{
            strcpy(errWord,"print error\n");
            yyerror(errWord);
        }
        
        Trace("PRINT expression ';' reducing to simple_state\n");
    }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 866 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].Data).val_type == VAL_INT)
        {
            printf("%d\n",(yyvsp[-1].Data).val_int);
        }
        else if((yyvsp[-1].Data).val_type == VAL_FLOAT)
        {
            printf("%f\n",(yyvsp[-1].Data).val_float);
        }
        else if((yyvsp[-1].Data).val_type == VAL_BOOL)
        {
            printf("%d\n",(yyvsp[-1].Data).val_flag);
        }
        else if((yyvsp[-1].Data).val_type == VAL_STR)
        {
            printf("%s\n",(yyvsp[-1].Data).val_str);
        }
        else{
            strcpy(errWord,"print error\n");
            yyerror(errWord);
        }
        
        Trace("PRINTLN expression ';' reducing to simple_state\n");
    }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 891 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("RETURN ';' reducing to simple_state\n");
    }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 895 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("RETURN expression ';'  reducing to simple_state\n");
    }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 903 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("expression ',' func_arg  reducing to func_arg\n");
    }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 907 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("expression reducing to func_arg\n");
    }
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 913 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("ID  '(' func_arg ')' reducing to func_invoke\n");
    }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 917 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("ID '(' ')' reducing to func_invoke\n");
    }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 925 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
    }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 928 "FirstYacc.y" /* yacc.c:1646  */
    {myTable.pushTable();Trace("create new table\n");}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 929 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
    }
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 937 "FirstYacc.y" /* yacc.c:1646  */
    {
    variableNode * v = myTable.lookupVar((yyvsp[0].Data).name);
    strcpy(errWord,"assign wrong\0");
    if(v != NULL)
    {
        (yyval.Data).name = (yyvsp[0].Data).name;
        (yyval.Data).val_type = v->val_Type;
        if(v->val_Type == VAL_INT)
            (yyval.Data).val_int = v->data.val_int;
        
        else if(v->val_Type == VAL_FLOAT)
            (yyval.Data).val_float = v->data.val_float;

        else if(v->val_Type == VAL_STR)
            (yyval.Data).val_str = v->data.val_str;

        else if(v->val_Type == VAL_BOOL)
            (yyval.Data).val_flag = v->data.val_flag;
        
        else 
            yyerror(errWord);


        if(v->is_const)
        {
            if(v->val_Type == VAL_INT)
                fprintf(myJavaCode,"\t\tsipush %d\n", v->data.val_int); 
            else if(v->val_Type == VAL_BOOL){
                if(v->data.val_flag)
                    fprintf(myJavaCode,"\t\ticonst_1%s\n");
                else
                    fprintf(myJavaCode,"\t\ticonst_0%s\n");
            }   
            else if(v->val_Type == VAL_FLOAT)
                fprintf(myJavaCode,"\t\tsipush %d\n", v->data.val_int); 
            else if(v->val_Type == VAL_STR)
                fprintf(myJavaCode,"\t\tldc \"%s\"\n", v->data.val_str); 
        }
        else
        {
            if(v->isGlobal)
            {
                if(v->val_Type == VAL_INT)
                    fprintf(myJavaCode,"\t\tgetstatic int Project.%s\n", (yyvsp[0].Data).name);
                else if(v->val_Type == VAL_BOOL)            
                    fprintf(myJavaCode,"\t\tgetstatic bool Project.%s\n", (yyvsp[0].Data).name);
                else if(v->val_Type == VAL_FLOAT)
                    fprintf(myJavaCode,"\t\tgetstatic float Project.%s\n", (yyvsp[0].Data).name);
                else if(v->val_Type == VAL_STR)
                    fprintf(myJavaCode,"\t\tgetstatic str Project.%s\n", (yyvsp[0].Data).name);
            }
            else
            {
                fprintf(myJavaCode,"\t\tiload %d\n", v->index);
            }
        }
    }
    else{
        strcpy(errWord,"can not find variable"); 
        yyerror(errWord);
        
    }   
}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1002 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1003 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1004 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1005 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1006 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[-1].Data);}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1008 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"type error");
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type){
            yyerror(errWord);
        }
        else 
            yyerror(errWord);
        
        fprintf(myJavaCode, "\t\timul\n");
    }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1019 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"type error");
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type != VAL_INT && (yyvsp[-2].Data).val_type != VAL_FLOAT)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            if((yyvsp[0].Data).val_int == 0)
            {
                strcpy(errWord,"divide 0");
                yyerror(errWord);
            }
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_int = (yyvsp[-2].Data).val_int / (yyvsp[0].Data).val_int;
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            if((yyvsp[0].Data).val_float == 0)
            {
                strcpy(errWord,"divide 0");
                yyerror(errWord);
            }
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_float = (yyvsp[-2].Data).val_float / (yyvsp[0].Data).val_float;
        }
        else 
            yyerror(errWord);
        
        fprintf(myJavaCode, "\t\tidiv\n");
    }
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1051 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"type error");
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type != VAL_INT && (yyvsp[-2].Data).val_type != VAL_FLOAT)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_int = (yyvsp[-2].Data).val_int + (yyvsp[0].Data).val_int;
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_float = (yyvsp[-2].Data).val_float + (yyvsp[0].Data).val_float;
        }
        else 
            yyerror(errWord);

        
        fprintf(myJavaCode, "\t\tiadd\n");
    }
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1074 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"type error");

        if((yyvsp[-2].Data).val_type != VAL_INT && (yyvsp[-2].Data).val_type != VAL_FLOAT)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_int = (yyvsp[-2].Data).val_int - (yyvsp[0].Data).val_int;
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_float = (yyvsp[-2].Data).val_float - (yyvsp[0].Data).val_float;
        }
        else 
            yyerror(errWord);
        
        fprintf(myJavaCode, "\t\tisub\n");
    }
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1098 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2708 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1119 "FirstYacc.y" /* yacc.c:1906  */


int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("compiler error:  %s  \n", s);
    //compier error exit()
    exit(0);
}

int main(int argc, char const *argv[])
{
    /* open the source program file */
    //if (argc != 2) {
    //    printf ("Usage: sc filename\n");
    //    exit(1);
    //}
    myJavaCode = fopen("Will.jasm", "w");         /* open input file */
    fprintf(myJavaCode,"class Project\n{\n");
    /* perform parsing */
    if (yyparse() == 1) 
                    /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    printf("\n\nEND PROGRAM\n");
    myTable.dumpTable();

    fprintf(myJavaCode,"}");
    fclose(myJavaCode);
    return 0;
    
}
