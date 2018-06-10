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
int labelNum = 0;
int labelStackTop = 0;
int labelStack[20];
int funcArgSize;
int constDeclar;
char errWord[256];
char *declareErr = "error: declare fall";
FILE *myJavaCode;

#line 86 "y.tab.c" /* yacc.c:339  */

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
#line 22 "FirstYacc.y" /* yacc.c:355  */

    struct
    {

        char *name;
        
        union{
            char *val_str;
            int  val_int;
            bool val_flag;
            float val_float;
            char *arg_var_type;
        };
        char* concat_name;
        // if it is an array element it should be store the index
        int arr_idx;
        // int => 0 = T_INT bool => 1 = VAL_BOOL string => 3 = T_STR real => 3 = T_REAL
        int val_type;
        //0 => id || 1 => primitive type for passing data by $$ to recognize
        int state; 
    }Data;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

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
       0,   126,   126,   129,   130,   133,   134,   135,   136,   137,
     138,   143,   144,   147,   148,   149,   152,   152,   193,   193,
     244,   268,   300,   324,   349,   361,   373,   409,   422,   477,
     491,   496,   501,   506,   511,   518,   527,   540,   548,   560,
     606,   611,   618,   624,   633,   640,   640,   683,   683,   701,
     700,   758,   757,   788,   836,   866,   866,   875,   875,   884,
     889,   898,   912,   920,   949,   973,   977,   977,   985,  1051,
    1052,  1053,  1054,  1055,  1056,  1068,  1100,  1123,  1144,  1155,
    1156,  1157,  1167,  1177,  1186,  1202,  1217,  1231,  1247,  1262,
    1283,  1282,  1290,  1298,  1297,  1307,  1312,  1306
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
  "Variable_declared", "Array_declared", "standard_data_type",
  "standard_data", "formal_argment", "formal_arguments", "func_block",
  "func_sign", "func_declared", "$@3", "$@4", "$@5", "$@6", "simple_state",
  "$@7", "$@8", "func_arg", "func_invoke", "block", "$@9", "object",
  "expression", "bool_exp", "condition_else", "$@10", "condition", "$@11",
  "loop", "$@12", "$@13", YY_NULLPTR
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

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,   -63,  -151,  -151,   -16,  -151,  -151,    31,  -151,  -151,
     -53,  -151,  -151,   126,   154,   -56,   154,    21,  -151,   145,
    -151,   -37,  -151,  -151,  -151,  -151,   -21,  -151,  -151,  -151,
    -151,  -151,   255,   204,  -151,  -151,   126,   -19,   -48,   154,
     154,   -31,  -151,   227,   -30,   126,   154,    26,   204,    -9,
    -151,   145,    99,  -151,  -151,  -151,   -26,   154,   154,   154,
     154,   154,   126,   126,   126,   126,   126,   126,   126,   126,
     126,    71,   -44,  -151,    36,   234,   241,  -151,   126,   192,
     205,  -151,   -13,   222,   -24,  -151,   -39,    -9,    -9,  -151,
    -151,  -151,   151,   151,   151,   151,   151,   151,   204,   151,
     151,  -151,    11,    36,    36,   154,  -151,  -151,  -151,  -151,
    -151,    -4,  -151,  -151,   182,  -151,    32,  -151,   154,  -151,
      -2,    37,    23,    27,    34,  -151,  -151,  -151,    48,    33,
     255,  -151,  -151,   154,  -151,    36,    57,    47,    70,    61,
     107,  -151,    41,   154,   154,    34,   248,  -151,    36,    97,
    -151,  -151,    67,    47,  -151,  -151,  -151,  -151,  -151,   210,
     255,  -151,  -151,  -151,  -151,    58,    36,  -151,    34,  -151,
      47,  -151,  -151,  -151,  -151,    47,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    36,    44,     0,    55,    57,     0,    95,    37,
      68,    35,    38,     0,     0,    66,     0,     0,     2,     3,
       5,     0,    13,    14,    15,    71,     0,    11,     6,    69,
      10,    70,    79,     7,     8,     9,     0,     0,     0,     0,
       0,    68,    59,     0,     0,     0,     0,     0,    80,    72,
      65,     0,     0,     1,     4,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    16,     0,     0,     0,    60,     0,     0,
       0,    64,     0,    62,     0,    73,     0,    76,    77,    74,
      75,    78,    86,    87,    88,    89,    81,    82,    83,    84,
      85,    93,     0,     0,     0,     0,    31,    32,    33,    30,
      34,     0,    56,    58,     0,    53,     0,    63,     0,    67,
       0,    47,    41,     0,     0,    21,    22,    20,    28,     0,
      17,    18,    96,     0,    61,     0,     0,     0,     0,    45,
      92,    94,     0,     0,     0,     0,     0,    39,     0,     0,
      48,    40,     0,     0,    90,    26,    24,    23,    25,     0,
      19,    97,    54,    51,    42,     0,     0,    46,     0,    29,
       0,    43,    49,    91,    52,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,   -17,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,   -76,  -151,  -151,   -11,  -150,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,    12,  -151,  -123,  -151,  -151,
      -7,    -1,  -151,  -151,  -151,  -151,  -151,  -151,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,   105,   144,    23,
      24,   111,    25,   122,   123,   150,    26,    27,   153,   137,
     175,   170,    28,    39,    40,    82,    29,    30,    51,    31,
      32,    33,   141,   168,    34,   124,    35,    44,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,   140,    54,   167,    37,    36,   120,    49,    45,    52,
      46,    50,    48,    73,    74,    47,   125,   102,   103,   104,
     174,    53,   161,    55,    56,   176,    72,   128,   129,    38,
     121,     2,    75,    76,    84,    71,     2,    47,    78,    80,
      83,   106,    86,   119,    79,   173,   155,    59,    60,    61,
      87,    88,    89,    90,    91,   126,   117,   131,   127,   147,
     135,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       9,    41,   163,    11,    12,     9,    41,   114,    11,    12,
     107,    14,   108,   109,   110,   156,    14,   138,   157,   158,
     172,    42,   136,   133,    16,    81,   139,   143,   130,    16,
      15,     1,     2,    62,    63,    64,    65,    66,    67,   142,
     148,    83,     3,   149,     4,   120,   152,   154,     5,     6,
     166,     7,    68,    69,    70,   171,   146,   151,     8,     0,
     134,     2,   165,     0,     0,     0,   159,   160,     0,     0,
     101,     9,    10,     0,    11,    12,     0,     0,    13,     1,
       2,     0,    14,    57,    58,    59,    60,    61,     0,     2,
       3,     0,     4,    15,   164,    16,     5,     6,    85,     7,
       9,    41,     0,    11,    12,     0,     8,    13,     0,     0,
       0,    14,     0,    62,    63,    64,    65,    66,    67,     9,
      10,     0,    11,    12,    16,     0,    13,     0,     9,    41,
      14,    11,    12,    69,    70,     0,     0,     0,     0,    14,
       0,    15,     0,    16,    62,    63,    64,    65,    66,    67,
       0,     0,    16,     0,    62,    63,    64,    65,    66,    67,
       0,     0,     0,    68,    69,    70,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,     0,     0,     0,     0,
       0,   132,   115,     0,     0,    68,    69,    70,     0,    57,
      58,    59,    60,    61,    57,    58,    59,    60,    61,     0,
     116,     0,     0,     0,     0,   169,    57,    58,    59,    60,
      61,    57,    58,    59,    60,    61,   118,    77,    57,    58,
      59,    60,    61,     0,   112,    57,    58,    59,    60,    61,
       0,   113,    57,    58,    59,    60,    61,     0,   162,    57,
      58,    59,    60,    61
};

static const yytype_int16 yycheck[] =
{
       7,   124,    19,   153,    20,    68,    45,    14,    61,    16,
      63,    67,    13,    61,    62,    68,     5,    61,    62,    63,
     170,     0,   145,    60,    45,   175,    45,   103,   104,    45,
      69,     5,    39,    40,    51,    36,     5,    68,    68,    46,
      47,     5,    68,    67,    45,   168,     5,    56,    57,    58,
      57,    58,    59,    60,    61,    44,    69,    61,    47,   135,
      62,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      44,    45,   148,    47,    48,    44,    45,    78,    47,    48,
      44,    55,    46,    47,    48,    44,    55,    64,    47,    48,
     166,    60,    55,    61,    68,    69,    69,    64,   105,    68,
      66,     4,     5,    32,    33,    34,    35,    36,    37,    61,
      53,   118,    15,    66,    17,    45,    55,    10,    21,    22,
      53,    24,    51,    52,    53,    67,   133,   138,    31,    -1,
     118,     5,   149,    -1,    -1,    -1,   143,   144,    -1,    -1,
      69,    44,    45,    -1,    47,    48,    -1,    -1,    51,     4,
       5,    -1,    55,    54,    55,    56,    57,    58,    -1,     5,
      15,    -1,    17,    66,    67,    68,    21,    22,    69,    24,
      44,    45,    -1,    47,    48,    -1,    31,    51,    -1,    -1,
      -1,    55,    -1,    32,    33,    34,    35,    36,    37,    44,
      45,    -1,    47,    48,    68,    -1,    51,    -1,    44,    45,
      55,    47,    48,    52,    53,    -1,    -1,    -1,    -1,    55,
      -1,    66,    -1,    68,    32,    33,    34,    35,    36,    37,
      -1,    -1,    68,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    51,    52,    53,    32,    33,    34,    35,
      36,    37,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    69,    60,    -1,    -1,    51,    52,    53,    -1,    54,
      55,    56,    57,    58,    54,    55,    56,    57,    58,    -1,
      65,    -1,    -1,    -1,    -1,    65,    54,    55,    56,    57,
      58,    54,    55,    56,    57,    58,    64,    60,    54,    55,
      56,    57,    58,    -1,    60,    54,    55,    56,    57,    58,
      -1,    60,    54,    55,    56,    57,    58,    -1,    60,    54,
      55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    15,    17,    21,    22,    24,    31,    44,
      45,    47,    48,    51,    55,    66,    68,    71,    72,    73,
      74,    75,    76,    79,    80,    82,    86,    87,    92,    96,
      97,    99,   100,   101,   104,   106,    68,    20,    45,    93,
      94,    45,    60,   100,   107,    61,    63,    68,   101,   100,
      67,    98,   100,     0,    72,    60,    45,    54,    55,    56,
      57,    58,    32,    33,    34,    35,    36,    37,    51,    52,
      53,   101,    45,    61,    62,   100,   100,    60,    68,   101,
     100,    69,    95,   100,    72,    69,    68,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,    69,    61,    62,    63,    77,     5,    44,    46,    47,
      48,    81,    60,    60,   101,    60,    65,    69,    64,    67,
      45,    69,    83,    84,   105,     5,    44,    47,    81,    81,
     100,    61,    69,    61,    95,    62,    55,    89,    64,    69,
      97,   102,    61,    64,    78,   108,   100,    81,    53,    66,
      85,    84,    55,    88,    10,     5,    44,    47,    48,   100,
     100,    97,    60,    81,    67,    72,    53,    85,   103,    65,
      91,    67,    81,    97,    85,    90,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    77,    76,    78,    76,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      84,    84,    85,    85,    86,    88,    87,    89,    87,    90,
      87,    91,    87,    92,    92,    93,    92,    94,    92,    92,
      92,    95,    95,    96,    96,    97,    98,    97,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     103,   102,   102,   105,   104,   107,   108,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     0,     5,     0,     7,
       5,     5,     5,     7,     7,     7,     7,     3,     5,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     3,     1,     0,     7,     0,     6,     0,
      10,     0,     9,     4,     7,     0,     4,     0,     4,     2,
       3,     3,     1,     4,     3,     2,     0,     4,     1,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     4,     1,     0,     6,     0,     0,     7
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
#line 126 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statements reducing to program\n");}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement reducing to statements\n");}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 130 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("statement statements reducing to statements\n");}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("declared reducing to statement\n");}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("simple_state reducing to statement\n");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("bool_exp reducing to statement\n");}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("condition reducing to statement\n");}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("loop reducing to statement\n");}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("block reducing to statement\n");}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("func_declared reducing to declared\n");}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 144 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("identifier_declared ';' reducing to declared\n");}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("constant_declared reducing to identifier_declared\n");}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 148 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Variable_declared reducing to identifier_declared\n");}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 149 "FirstYacc.y" /* yacc.c:1646  */
    {Trace("Array_declared reducing to identifier_declared\n");}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "FirstYacc.y" /* yacc.c:1646  */
    {constDeclar = 1;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 193 "FirstYacc.y" /* yacc.c:1646  */
    {constDeclar = 1;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 194 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 245 "FirstYacc.y" /* yacc.c:1646  */
    {

        variableNode v(VAL_INT,(yyvsp[0].Data).val_int,(yyvsp[-2].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' INT reducing to Variable_declared\n");
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
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 301 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 325 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 350 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_STR,(yyvsp[0].Data).val_str,(yyvsp[-4].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 362 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(declareErr);

        variableNode v(VAL_FLOAT,(yyvsp[0].Data).val_float,(yyvsp[-4].Data).name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 374 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 410 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 423 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 478 "FirstYacc.y" /* yacc.c:1646  */
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
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 492 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;
        Trace("INT reducing to standard_data_type\n");
    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 497 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;
        Trace("BOOL reducing to standard_data_type\n");
    }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 502 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;
        Trace("STR reducing to standard_data_type\n");
    }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 507 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_REAL;
        Trace("REAL_NUMBER reducing to standard_data_type\n");
    }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 512 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;
        Trace("FLOAT reducing to standard_data_type\n");
    }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 519 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type =  VAL_INT;(yyval.Data).val_int = (yyvsp[0].Data).val_int; 
        Trace("INT reducing to standard_data\n");
        
        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tsipush %d\n", (yyvsp[0].Data).val_int);
        
    }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 528 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_BOOL;(yyval.Data).val_flag = (yyvsp[0].Data).val_flag; 
        Trace("BOOL reducing to standard_data\n");
        
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            if((yyval.Data).val_flag)    
                fprintf(myJavaCode, "\t\ticonst_1\n");
            else        
                fprintf(myJavaCode, "\t\ticonst_0\n");
        }    
    }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 541 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_STR;(yyval.Data).val_str = (yyvsp[0].Data).val_str;
        Trace("STR reducing to standard_data\n");

        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tldc \"%s\" \n", (yyvsp[0].Data).val_str);
     }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 549 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).val_type = VAL_FLOAT;(yyval.Data).val_float = (yyvsp[0].Data).val_float; 
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            fprintf(myJavaCode, "\t\tsipush %f\n", (yyvsp[0].Data).val_float);
        }

        Trace("FLOAT reducing to standard_data\n");
    }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 561 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 607 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argment ',' formal_arguments reducing to formal_arguments\n");
    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 612 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize+=1;
        Trace("formal_argument reducing to formal_arguments\n");
    }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 618 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
        myTable.popTable();
        Trace("delete table\n");
        //fprintf(myJavaCode,"\t}\n");
    }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 624 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
        //fprintf(myJavaCode,"\t}\n");
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 633 "FirstYacc.y" /* yacc.c:1646  */
    {
        funcArgSize = 0;
        myTable.pushTable();printf("create new table\n");
        
        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 640 "FirstYacc.y" /* yacc.c:1646  */
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
 
                myTable.func_var_store(target->name,target->val_Type);
            }
            else
                break;

            if(i<funcArgSize-1)fprintf(myJavaCode,", ");
        }
        fprintf(myJavaCode,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        Trace("FN ID '(' formal_arguments ')' reducing to func_declared\n");

    }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 678 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode,"\t\treturn\n\t}\n");
        }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 683 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 697 "FirstYacc.y" /* yacc.c:1646  */
    {fprintf(myJavaCode,"\t\treturn\n\t}\n");}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 701 "FirstYacc.y" /* yacc.c:1646  */
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
 
                myTable.func_var_store(target->name,target->val_Type);
            }
            else
                break;

            if(i<funcArgSize-1)fprintf(myJavaCode,", ");
        }
        fprintf(myJavaCode,")\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
 
        Trace("FN ID '(' formal_arguments ')' func_sign standard_data_type reducing to func_declared\n");
    }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 754 "FirstYacc.y" /* yacc.c:1646  */
    {fprintf(myJavaCode,"\n\t}\n");}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 758 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 782 "FirstYacc.y" /* yacc.c:1646  */
    {fprintf(myJavaCode,"\n\t}\n");}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 789 "FirstYacc.y" /* yacc.c:1646  */
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
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if((yyvsp[-1].Data).val_type == VAL_FLOAT)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_float,(yyvsp[-3].Data).name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if((yyvsp[-1].Data).val_type == VAL_STR)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_str,(yyvsp[-3].Data).name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if((yyvsp[-1].Data).val_type == VAL_BOOL)
        {
            variableNode v((yyvsp[-1].Data).val_type,(yyvsp[-1].Data).val_flag,(yyvsp[-3].Data).name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        Trace("ID '=' bool_exp ';' reducing to simple_state\n");
    }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 837 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 866 "FirstYacc.y" /* yacc.c:1646  */
    {fprintf(myJavaCode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 867 "FirstYacc.y" /* yacc.c:1646  */
    {
        if((yyvsp[-1].Data).val_type == VAL_STR)
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
        else
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n"); 

        Trace("PRINT expression ';' reducing to simple_state\n");
    }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 875 "FirstYacc.y" /* yacc.c:1646  */
    {fprintf(myJavaCode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 876 "FirstYacc.y" /* yacc.c:1646  */
    { 
        if((yyvsp[-1].Data).val_type == VAL_STR)
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
        else
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n"); 
        
        Trace("PRINTLN expression ';' reducing to simple_state\n");
    }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 885 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode,"\t\tireturn\n");
        Trace("RETURN ';' reducing to simple_state\n");
    }
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 890 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode,"\t\tireturn\n");
        Trace("RETURN expression ';'  reducing to simple_state\n");
    }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 899 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        int len = strlen((yyvsp[0].Data).arg_var_type)+3;
        
        (yyval.Data).arg_var_type = (char*)malloc(len*sizeof(char)); 
        sprintf((yyval.Data).arg_var_type, "%d", (yyvsp[-2].Data).val_type);
        strcat((yyval.Data).arg_var_type, ",");
        strcat((yyval.Data).arg_var_type, (yyvsp[0].Data).arg_var_type);
        free( (yyvsp[0].Data).arg_var_type);
        
        Trace("expression ',' func_arg  reducing to func_arg\n");

    }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 913 "FirstYacc.y" /* yacc.c:1646  */
    {
        (yyval.Data).arg_var_type = (char*)malloc(2*sizeof(char)); 
        sprintf((yyval.Data).arg_var_type, "%d", (yyvsp[0].Data).val_type);
        Trace("expression reducing to func_arg\n");
    }
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 921 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        strcpy(errWord ,"arg error");
        variableNode *v =  myTable.lookupFunc((yyval.Data).name);
        if(v == NULL)
            yyerror(errWord);


        if(!myTable.func_type_check((yyvsp[-3].Data).name, (yyvsp[-1].Data).arg_var_type))
            yyerror(errWord);
        printf("sssssssssssssssss");
        char *ty;
        
        if(v->val_Type == VAL_INT)
            ty = strdup("int");
        else if(v->val_Type == VAL_BOOL)
            ty = strdup("bool");
        else if(v->val_Type == VAL_STR)
            ty = strdup("str");
        else if(v->val_Type == VAL_NULL)
            ty = strdup("void");

        char *combine = myTable.func_type_combine(v);
        fprintf(myJavaCode,"\t\tinvokestatic %s Project.%s(%s)\n", ty,v->name,combine);
        free(combine);
        Trace("ID  '(' func_arg ')' reducing to func_invoke\n");

    }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 950 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord ,"arg error");
        variableNode *v =  myTable.lookupFunc((yyval.Data).name);
        if(v == NULL)
            yyerror(errWord);
        
        if(!myTable.func_type_check((yyvsp[-2].Data).name,strdup("")))
            yyerror(errWord);
        char *ty;
        if(v->val_Type == VAL_INT)
            ty = strdup("int");
        else if(v->val_Type == VAL_BOOL)
            ty = strdup("bool");
        else if(v->val_Type == VAL_STR)
            ty = strdup("str");

        fprintf(myJavaCode,"\t\tinvokestatic %s Project.%s()\n", ty,v->name);
        Trace("ID '(' ')' reducing to func_invoke\n");
    }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 974 "FirstYacc.y" /* yacc.c:1646  */
    {
        Trace("'{' '}' reducing to block\n");
    }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 977 "FirstYacc.y" /* yacc.c:1646  */
    {myTable.pushTable();Trace("create new table\n");}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 978 "FirstYacc.y" /* yacc.c:1646  */
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
    }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 986 "FirstYacc.y" /* yacc.c:1646  */
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
                    fprintf(myJavaCode,"\t\ticonst_1\n");
                else
                    fprintf(myJavaCode,"\t\ticonst_0\n");
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
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1051 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1052 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1053 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1054 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);fprintf(myJavaCode, "\t\tineg\n");}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1055 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[-1].Data);}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1057 "FirstYacc.y" /* yacc.c:1646  */
    {
        printf("%d %d",(yyvsp[-2].Data).val_type , (yyvsp[0].Data).val_type);
        strcpy(errWord,"type error");
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type){
            yyerror(errWord);
        }
        
        fprintf(myJavaCode, "\t\timul\n");
        (yyval.Data).val_type = (yyvsp[-2].Data).val_type;
        (yyval.Data).val_int = (yyvsp[-2].Data).val_int * (yyvsp[0].Data).val_int;
    }
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1069 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1101 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1124 "FirstYacc.y" /* yacc.c:1646  */
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
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1145 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        fprintf(myJavaCode, "\t\tirem\n");
    }
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1156 "FirstYacc.y" /* yacc.c:1646  */
    {(yyval.Data) = (yyvsp[0].Data);}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1157 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tiand\n");

    }
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1167 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tior\n");

    }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1177 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tixor\n");
    }
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1186 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tiflt L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1202 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifgt L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1217 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 
        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifle L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1231 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifge L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1247 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifeq L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1262 "FirstYacc.y" /* yacc.c:1646  */
    {
        strcpy(errWord,"tyep error"); 

        if((yyvsp[-2].Data).val_type != (yyvsp[0].Data).val_type)
            yyerror(errWord);
        (yyval.Data) = (yyvsp[-2].Data);
        (yyval.Data).val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifne L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1283 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode,"\t\tgoto L%d\n", labelStack[labelStackTop-1] + 1);
        //else lable
        fprintf(myJavaCode, "\tL%d:\n", labelStack[labelStackTop - 1]);
    }
#line 2991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1288 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop] + 1);
    }
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1291 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop]);
    }
#line 3007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1298 "FirstYacc.y" /* yacc.c:1646  */
    {
        
        labelStack[labelStackTop++] = labelNum;
        fprintf(myJavaCode,"\t\tifeq L%d\n", labelNum);
        labelNum += 2;        
    }
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1307 "FirstYacc.y" /* yacc.c:1646  */
    {
        labelStack[labelStackTop++] = labelNum;
        fprintf(myJavaCode, "\tL%d:\n", labelNum);
        labelNum += 2; 
    }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1312 "FirstYacc.y" /* yacc.c:1646  */
    {
            fprintf(myJavaCode,"\t\tifeq L%d\n", labelStack[labelStackTop-1]+1);
    }
#line 3036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1315 "FirstYacc.y" /* yacc.c:1646  */
    {
        fprintf(myJavaCode,"\t\tgoto L%d\n", labelStack[labelStackTop-1]);
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop] + 1);
    }
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3049 "y.tab.c" /* yacc.c:1646  */
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
#line 1320 "FirstYacc.y" /* yacc.c:1906  */


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
