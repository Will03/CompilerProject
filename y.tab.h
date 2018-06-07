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
#line 19 "FirstYacc.y" /* yacc.c:1909  */

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

#line 172 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
