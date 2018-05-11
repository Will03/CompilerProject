/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    FLOAT = 269,
    FOR = 270,
    FN = 271,
    IN = 272,
    INT = 273,
    LET = 274,
    LOOP = 275,
    MATCH = 276,
    MUT = 277,
    PRINT = 278,
    PRINTLN = 279,
    PUB = 280,
    RETURN = 281,
    SELF = 282,
    STATIC = 283,
    STRUCT = 284,
    TRUE = 285,
    USE = 286,
    WHERE = 287,
    WHILE = 288,
    LESS_EQUAL = 289,
    GREAT_EQUAL = 290,
    EQUAL = 291,
    NOT_EQUAL = 292,
    AND_DOUBLE = 293,
    OR_DOUBLE = 294,
    ADD_DOUBLE = 295,
    SUB_DOUBLE = 296,
    ADD_EQUAL = 297,
    SUB_EQUAL = 298,
    MUL_EQUAL = 299,
    DIV_EQUAL = 300,
    NUMBER = 301,
    STR = 302,
    ID = 303,
    REAL_NUMBER = 304
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
#define FLOAT 269
#define FOR 270
#define FN 271
#define IN 272
#define INT 273
#define LET 274
#define LOOP 275
#define MATCH 276
#define MUT 277
#define PRINT 278
#define PRINTLN 279
#define PUB 280
#define RETURN 281
#define SELF 282
#define STATIC 283
#define STRUCT 284
#define TRUE 285
#define USE 286
#define WHERE 287
#define WHILE 288
#define LESS_EQUAL 289
#define GREAT_EQUAL 290
#define EQUAL 291
#define NOT_EQUAL 292
#define AND_DOUBLE 293
#define OR_DOUBLE 294
#define ADD_DOUBLE 295
#define SUB_DOUBLE 296
#define ADD_EQUAL 297
#define SUB_EQUAL 298
#define MUL_EQUAL 299
#define DIV_EQUAL 300
#define NUMBER 301
#define STR 302
#define ID 303
#define REAL_NUMBER 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "FirstYacc.y" /* yacc.c:1909  */

    struct
    {
        // store yylval's value
        union{
            char *name;
            int  val;
            bool flag;
        };
        char* concat_name;
        // if it is an array element it should be store the index
        int arr_idx;
        // int => 0 = T_INT bool => 1 = T_BOOL string => 3 = T_STR real => 3 = T_REAL
        int val_type;
        //0 => id || 1 => primitive type for passing data by $$ to recognize
        int state; 
    }Data;

#line 171 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
