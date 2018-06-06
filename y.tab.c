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
char errWord[256];
char *declareErr = "error: declare fall";
FILE *myJavaCode;

#line 82 "y.tab.c" /* yacc.c:339  */

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
#line 18 "FirstYacc.y" /* yacc.c:355  */

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

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

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
       0,   121,   121,   124,   125,   128,   129,   130,   131,   132,
     133,   138,   139,   142,   143,   144,   147,   186,   235,   279,
     325,   338,   384,   398,   403,   408,   413,   418,   425,   431,
     441,   447,   455,   501,   506,   513,   517,   526,   533,   533,
     573,   573,   591,   590,   618,   617,   631,   655,   685,   710,
     735,   739,   747,   751,   757,   761,   769,   773,   773,   781,
     812,   813,   814,   815,   816,   817,   837,   867,   887,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   925,
     926,   929
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
  "identifier_declared", "constant_declared", "Variable_declared",
  "Array_declared", "standard_data_type", "standard_data",
  "formal_argment", "formal_arguments", "func_block", "func_sign",
  "func_declared", "$@1", "$@2", "$@3", "$@4", "simple_state", "func_arg",
  "func_invoke", "block", "$@5", "object", "expression", "bool_exp",
  "condition", "loop", YY_NULLPTR
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

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      79,   -62,  -133,  -133,   -15,   108,   108,    44,   -55,  -133,
     -49,  -133,  -133,    93,   108,   -47,   108,    18,  -133,    79,
    -133,   -34,  -133,  -133,  -133,  -133,   -13,  -133,  -133,  -133,
    -133,  -133,   236,   206,  -133,  -133,    93,    -8,   -22,   -40,
     208,   215,  -133,   222,    93,    93,   108,     3,   206,   -33,
    -133,    79,   191,  -133,  -133,  -133,    -6,   108,   108,   108,
     108,    93,    93,    93,    93,    93,    93,    93,    93,   162,
     -17,   108,    85,  -133,  -133,  -133,   168,   174,    20,  -133,
      -1,   197,     2,  -133,   -38,   -33,   -33,  -133,  -133,   206,
     206,   206,   206,   206,   206,   206,   206,     4,   108,    85,
      85,   236,  -133,  -133,  -133,  -133,  -133,    21,     4,  -133,
      25,  -133,   108,  -133,    11,    26,    23,    28,    92,   236,
      34,    41,   108,  -133,   108,  -133,    85,    53,    42,    64,
      56,     4,    17,   108,   236,   229,  -133,    85,    12,  -133,
    -133,    61,    42,  -133,  -133,   116,  -133,  -133,  -133,    48,
      85,  -133,  -133,    42,  -133,  -133,  -133,    42,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    29,    37,     0,     0,     0,     0,     0,    30,
      59,    28,    31,     0,     0,    57,     0,     0,     2,     3,
       5,     0,    13,    14,    15,    62,     0,    11,     6,    60,
      10,    61,    69,     7,     8,     9,     0,     0,     0,    59,
       0,     0,    50,     0,     0,     0,     0,     0,    70,    63,
      56,     0,     0,     1,     4,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,    48,    49,    51,     0,     0,     0,    55,
       0,    53,     0,    64,     0,    67,    68,    65,    66,    73,
      74,    75,    76,    77,    78,    71,    72,     0,     0,     0,
       0,    16,    24,    25,    26,    23,    27,     0,     0,    46,
       0,    54,     0,    58,     0,    40,    34,     0,    80,    18,
      21,     0,     0,    81,     0,    52,     0,     0,     0,     0,
      38,     0,     0,     0,    17,     0,    32,     0,     0,    41,
      33,     0,     0,    79,    19,     0,    47,    44,    35,     0,
       0,    39,    22,     0,    36,    42,    45,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   -16,  -133,  -133,  -133,  -133,  -133,  -133,    43,
     -14,  -133,    -9,  -132,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,     9,  -133,   -93,  -133,  -133,    -5,   122,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,   107,
      25,   116,   117,   139,    26,    27,   142,   128,   157,   153,
      28,    80,    29,    30,    51,    31,    32,    33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    41,    43,    54,   118,    37,    36,   114,     2,    49,
     151,    52,    45,    44,    46,   123,     1,     2,    53,    47,
      50,   156,     2,    59,    60,   158,    55,     3,    47,     4,
      38,   115,    56,     5,     6,    82,     7,    70,   143,    71,
      72,    78,    81,     8,    98,    99,   100,     9,    39,     2,
      11,    12,    85,    86,    87,    88,     9,    10,    14,    11,
      12,     9,    84,    13,    11,    12,   101,    14,   111,   113,
      15,    16,    79,   126,    57,    58,    59,    60,    15,   148,
      16,   127,   122,     1,     2,   110,   124,   129,     9,    39,
     102,    11,    12,   119,     3,   132,     4,   130,     2,    14,
       5,     6,   131,     7,    42,   133,   137,    81,   138,   114,
       8,   141,    16,     2,   150,   154,     0,   134,   144,   135,
     140,   125,   149,     9,    10,     0,    11,    12,   145,   103,
      13,   104,   105,   106,    14,    48,     0,     9,    39,     0,
      11,    12,   120,   121,    13,    15,     0,    16,    14,     0,
       0,     0,     9,    39,     0,    11,    12,     0,    69,     0,
       0,    16,     0,    14,     0,     0,    76,    77,     0,   136,
      57,    58,    59,    60,     0,     0,    16,     0,     0,     0,
     147,   152,     0,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,   155,    61,    62,    63,    64,    65,    66,
      61,    62,    63,    64,    65,    66,    61,    62,    63,    64,
      65,    66,     0,     0,    67,    68,     0,     0,     0,     0,
      67,    68,     0,     0,     0,     0,    67,    68,     0,     0,
       0,    97,     0,     0,   109,     0,     0,   108,    61,    62,
      63,    64,    65,    66,     0,    57,    58,    59,    60,     0,
       0,    57,    58,    59,    60,     0,     0,     0,    67,    68,
      83,   112,    57,    58,    59,    60,     0,     0,    73,    57,
      58,    59,    60,     0,     0,    74,    57,    58,    59,    60,
       0,     0,    75,    57,    58,    59,    60,     0,     0,   146,
      57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
       5,     6,     7,    19,    97,    20,    68,    45,     5,    14,
     142,    16,    61,    68,    63,   108,     4,     5,     0,    68,
      67,   153,     5,    56,    57,   157,    60,    15,    68,    17,
      45,    69,    45,    21,    22,    51,    24,    45,   131,    61,
      62,    46,    47,    31,    61,    62,    63,    44,    45,     5,
      47,    48,    57,    58,    59,    60,    44,    45,    55,    47,
      48,    44,    68,    51,    47,    48,    71,    55,    69,    67,
      66,    68,    69,    62,    54,    55,    56,    57,    66,    67,
      68,    55,    61,     4,     5,    65,    61,    64,    44,    45,
       5,    47,    48,    98,    15,    61,    17,    69,     5,    55,
      21,    22,    10,    24,    60,    64,    53,   112,    66,    45,
      31,    55,    68,     5,    53,    67,    -1,   122,   132,   124,
     129,   112,   138,    44,    45,    -1,    47,    48,   133,    44,
      51,    46,    47,    48,    55,    13,    -1,    44,    45,    -1,
      47,    48,    99,   100,    51,    66,    -1,    68,    55,    -1,
      -1,    -1,    44,    45,    -1,    47,    48,    -1,    36,    -1,
      -1,    68,    -1,    55,    -1,    -1,    44,    45,    -1,   126,
      54,    55,    56,    57,    -1,    -1,    68,    -1,    -1,    -1,
     137,    65,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,   150,    32,    33,    34,    35,    36,    37,
      32,    33,    34,    35,    36,    37,    32,    33,    34,    35,
      36,    37,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    69,    -1,    -1,    60,    -1,    -1,    69,    32,    33,
      34,    35,    36,    37,    -1,    54,    55,    56,    57,    -1,
      -1,    54,    55,    56,    57,    -1,    -1,    -1,    52,    53,
      69,    64,    54,    55,    56,    57,    -1,    -1,    60,    54,
      55,    56,    57,    -1,    -1,    60,    54,    55,    56,    57,
      -1,    -1,    60,    54,    55,    56,    57,    -1,    -1,    60,
      54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    15,    17,    21,    22,    24,    31,    44,
      45,    47,    48,    51,    55,    66,    68,    71,    72,    73,
      74,    75,    76,    77,    78,    80,    84,    85,    90,    92,
      93,    95,    96,    97,    98,    99,    68,    20,    45,    45,
      96,    96,    60,    96,    68,    61,    63,    68,    97,    96,
      67,    94,    96,     0,    72,    60,    45,    54,    55,    56,
      57,    32,    33,    34,    35,    36,    37,    52,    53,    97,
      45,    61,    62,    60,    60,    60,    97,    97,    96,    69,
      91,    96,    72,    69,    68,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    69,    61,    62,
      63,    96,     5,    44,    46,    47,    48,    79,    69,    60,
      65,    69,    64,    67,    45,    69,    81,    82,    93,    96,
      79,    79,    61,    93,    61,    91,    62,    55,    87,    64,
      69,    10,    61,    64,    96,    96,    79,    53,    66,    83,
      82,    55,    86,    93,    80,    96,    60,    79,    67,    72,
      53,    83,    65,    89,    67,    79,    83,    88,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    78,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    81,    82,    82,    83,    83,    84,    86,    85,
      87,    85,    88,    85,    89,    85,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    92,    93,    94,    93,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     4,     6,     5,     7,
       3,     5,     8,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     2,     3,     1,     0,     7,
       0,     6,     0,    10,     0,     9,     4,     7,     3,     3,
       2,     3,     3,     1,     4,     3,     2,     0,     4,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     7,
       5,     5
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
#line 121 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statements reducing to program\n");}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 124 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement reducing to statements\n");}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement statements reducing to statements\n");}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 128 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("declared reducing to statement\n");}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("simple_state reducing to statement\n");}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("bool_exp reducing to statement\n");}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 131 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("condition reducing to statement\n");}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 132 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("loop reducing to statement\n");}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("block reducing to statement\n");}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("func_declared reducing to declared\n");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("identifier_declared ';' reducing to declared\n");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("constant_declared reducing to identifier_declared\n");}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 143 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Variable_declared reducing to identifier_declared\n");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Array_declared reducing to identifier_declared\n");}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-2].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-2].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-2].Data).name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[0].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-2].Data).name,true);
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
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 187 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
        {
            yyerror(declareErr);
        }
        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-4].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-4].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-4].Data).name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-4].Data).name,true);

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
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 236 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            Trace("LET MUT ID '=' FLOAT reducing to Variable_declared\n");
        }
        else if((yyvsp[0].Data).val_type == VAL_STR)
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
        else if((yyvsp[0].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' standard_data reducing to Variable_declared\n");
    }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 280 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-4].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_STR)
        {
            variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-4].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-4].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if((yyvsp[-2].Data).val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,(yyvsp[0].Data).val_flag,(yyvsp[-4].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type '=' standard_data reducing to Variable_declared\n");
    }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 326 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v(VAL_INT,0,(yyvsp[0].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID reducing to Variable_declared\n");
    }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 339 "FirstYacc.y" /* yacc.c:1646  */
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
            variableNode v(VAL_BOOL,true,(yyvsp[-2].Data).name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type reducing to constant_declared\n");
    }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 385 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 399 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;
        Trace("INT reducing to standard_data_type\n");
    }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 404 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;
        Trace("BOOL reducing to standard_data_type\n");
    }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 409 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;
        Trace("STR reducing to standard_data_type\n");
    }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 414 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_REAL;
        Trace("REAL_NUMBER reducing to standard_data_type\n");
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 419 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;
        Trace("FLOAT reducing to standard_data_type\n");
    }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 426 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;(yyval.Data).val_int = (yyvsp[0].Data).val_int; 
        Trace("INT reducing to standard_data\n");
        fprintf(myJavaCode, "\t\tsipush %d\n", (yyvsp[0].Data).val_int);
    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 432 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;(yyval.Data).val_flag = (yyvsp[0].Data).val_flag; 
        Trace("BOOL reducing to standard_data\n");

            if((yyval.Data).val_flag)    
                fprintf(myJavaCode, "\t\tsipush %d\n", 1);
            else        
                fprintf(myJavaCode, "\t\tsipush %d\n", 0);
    }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 442 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;(yyval.Data).val_str = (yyvsp[0].Data).val_str;
        Trace("STR reducing to standard_data\n");
        fprintf(myJavaCode, "\t\tsipush %s\n", (yyvsp[0].Data).val_str);
     }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 448 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;(yyval.Data).val_float = (yyvsp[0].Data).val_float; 
        Trace("FLOAT reducing to standard_data\n");
        fprintf(myJavaCode, "\t\tsipush %d\n", (yyvsp[0].Data).val_float);
    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 456 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 502 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argment ',' formal_arguments reducing to formal_arguments\n");
    }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 507 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argument reducing to formal_arguments\n");
    }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 513 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
        fprintf(myJavaCode,"\t}\n");
    }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 517 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
        fprintf(myJavaCode,"\t}\n");
    }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 526 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize = 0;
        myTable.pushTable();printf("create new table\n");
        
        }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 533 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        variableNode v(VAL_NULL,(yyvsp[-3].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        fprintf(myJavaCode,"\tmethod public static void %s (", (yyvsp[-3].Data).name);

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
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 573 "FirstYacc.y" /* yacc.c:1646  */
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
            fprintf(myJavaCode,"\tmethod public static void %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-2].Data).name);
        }
        Trace("FN ID '(' ')' reducing to func_declared\n");
    }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 591 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v((yyvsp[0].Data).val_type,(yyvsp[-6].Data).name,false);
        if (strcmp((yyvsp[-6].Data).name, "main") == 0){
            if((yyvsp[0].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if((yyvsp[0].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }    
        else{
            if((yyvsp[-6].Data).val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-6].Data).name);
            else if((yyvsp[-6].Data).val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-6].Data).name);
            else if((yyvsp[-6].Data).val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string %s()\n\tmax_stack 30\n\tmax_locals 30\n\t{\n", (yyvsp[-6].Data).name);
            }
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' func_sign standard_data_type reducing to func_declared\n");
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 618 "FirstYacc.y" /* yacc.c:1646  */
    {
        variableNode v((yyvsp[0].Data).val_type,(yyvsp[-5].Data).name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' ')' func_sign standard_data_type reducing to func_declared\n");
    }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 632 "FirstYacc.y" /* yacc.c:1646  */
    {
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
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 656 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 686 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 711 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 736 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("RETURN ';' reducing to simple_state\n");
    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 740 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("RETURN expression ';'  reducing to simple_state\n");
    }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 748 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("expression ',' func_arg  reducing to func_arg\n");
    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 752 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("expression reducing to func_arg\n");
    }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 758 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("ID  '(' func_arg ')' reducing to func_invoke\n");
    }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 762 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("ID '(' ')' reducing to func_invoke\n");
    }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 770 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
    }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 773 "FirstYacc.y" /* yacc.c:1646  */
    {myTable.pushTable();Trace("create new table\n");}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 774 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
    }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 782 "FirstYacc.y" /* yacc.c:1646  */
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
    }
    else{
        strcpy(errWord,"can not find variable"); 
        yyerror(errWord);
        
    }   
}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 812 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 813 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 814 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 815 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 816 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[-1].Data);}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 818 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"type error");
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type != VAL_INT && (yyvsp[-2].Data).val_type != VAL_FLOAT)
            yyerror(errWord);
        if((yyvsp[-2].Data).val_type == VAL_INT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_int = (yyvsp[-2].Data).val_int * (yyvsp[0].Data).val_int;
        }
        else if((yyvsp[-2].Data).val_type == VAL_FLOAT)
        {
            (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
            (yyval.Data).val_float = (yyvsp[-2].Data).val_float * (yyvsp[0].Data).val_float;
        }
        else 
            yyerror(errWord);
    }
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 838 "FirstYacc.y" /* yacc.c:1646  */
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
    }
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 868 "FirstYacc.y" /* yacc.c:1646  */
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
    }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 888 "FirstYacc.y" /* yacc.c:1646  */
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
    }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 910 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2487 "y.tab.c" /* yacc.c:1646  */
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
#line 931 "FirstYacc.y" /* yacc.c:1906  */


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
    fprintf(myJavaCode,"class proj3\n{\n");
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
