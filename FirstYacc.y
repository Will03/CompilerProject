%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int yyerror(char *s);
int yylex();

enum Type_enum{VAL_INT = 0, VAL_BOOL = 1, VAL_STR, VAL_FLOAT, VAL_REAL};

%}

%union 
{
    struct
    {
        // store yylval's value
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
}



%type<Data> ID
%type<Data> STR
%type<Data> REAL_NUMBER
%type<Data> FLOAT
%type<Data> INT
%type<Data> BOOL
%type<Data> standard_data_type
%type<Data> standard_data
%type<Data> expression
%type<Data> object
%type<Data> statement
//%type<Token> identifier_list
//%type<Token> argument_list
//%type<Token> bool_type
//%type<Token> primitive_type
//%type<Token> primitive
//%type<Token> expression
//%type<Token> bool_exp
// %type<Token> mix_exp
//%type<Token> array_element
//%type<Token> func_invoke

/* tokens */
%token SEMICOLON
%token IF
%token BOOL
%token BREAK
%token CHAR
%token CONTINUE
%token DO
%token ELSE
%token ENUM
%token EXTERN
%token FALSE
%token FOR
%token FN
%token IN

%token LET
%token LOOP
%token MATCH
%token MUT
%token PRINT
%token PRINTLN
%token PUB
%token RETURN
%token SELF
%token STATIC
%token STRUCT
%token TRUE
%token USE
%token WHERE
%token WHILE

%token LESS_EQUAL
%token GREAT_EQUAL
%token EQUAL
%token NOT_EQUAL
%token AND_DOUBLE
%token OR_DOUBLE
%token ADD_DOUBLE
%token SUB_DOUBLE
%token ADD_EQUAL
%token SUB_EQUAL
%token MUL_EQUAL
%token DIV_EQUAL

%token STR
%token ID
%token REAL_NUMBER
%token INT
%token FLOAT


%start program
%right '|'
%right '&'
%right '!' 
// %right '<' '>' LESS_EQUAL GREAT_EQUAL EQUAL NOT_EQUAL
%left '+' '-' 
%left '*'  '/' '%' 
%right '^'

%%
program:    
    statements {Trace("Reducing to program\n");};

statements: 
    statement | statement statements;

statement:
    declared ';' { Trace("declare id \n");}|
    simple_state ';';



declared:
    func_declared | 
    identifier_declared ;

identifier_declared:
    constant_declared|
    Variable_declared|
    Array_declared ;

constant_declared:
    LET ID '=' standard_data_type|
    LET ID ':' INT '=' INT       |
    LET ID ':' BOOL '=' BOOL    |
    LET ID ':' STR '=' STR      |
    LET ID ':' FLOAT '=' FLOAT  |
    LET ID ':' REAL_NUMBER '=' REAL_NUMBER;

Variable_declared:
    LET MUT ID '=' standard_data_type|
    LET MUT ID ':' INT '=' INT       |
    LET MUT ID ':' BOOL '=' BOOL     |
    LET MUT ID ':' STR '=' STR       |
    LET MUT ID ':' FLOAT '=' FLOAT   |
    LET MUT ID ':' REAL_NUMBER '=' REAL_NUMBER;

Array_declared:
    LET MUT ID '[' standard_data_type ',' INT ']';

standard_data_type:
    INT {$$.val_type =  VAL_INT;} |
    BOOL {$$.val_type = VAL_BOOL;} |
    STR   {$$.val_type = VAL_STR;} |
    REAL_NUMBER {$$.val_type = VAL_REAL;} |
    FLOAT {$$.val_type = VAL_FLOAT;};

standard_data:
    INT {$$.val_type =  VAL_INT;$$.val_float = $1.val_float; } |
    BOOL {$$.val_type = VAL_BOOL;$$.val_float = $1.val_float; } |
    STR   {$$.val_type = VAL_STR;$$.val_str = $1.val_str; } |
    REAL_NUMBER {$$.val_type = VAL_REAL;$$.val_str = $1.val_str; } |
    FLOAT {$$.val_type = VAL_FLOAT;$$.val_float = $1.val_float; };

formal_argment:
    ID ':' standard_data_type;

formal_arguments:
    formal_argment ',' formal_arguments |
    formal_argment;                    

func_declared:
    FN ID '(' formal_arguments ')'|
    FN ID '(' formal_arguments ')' '-' '>' standard_data_type |
    FN ID '(' ')' |
    FN ID '(' ')' '-' '>' standard_data_type;
    
compound:
    '{' '}'|
    '{' statements '}';

simple_state:
    ID '=' expression|
    ID '[' expression ']' '=' expression|
    PRINT expression|
    PRINTLN expression;
 //   READ ID|
 //   return|
 //   return expression;

object:ID;

expression:
 //   func_invoke{$$ = $1;}|
    object {$$ = $1;}|
    standard_data|
    '-' expression|
    expression '*' expression
    {
        if($1.val_type != $3.val_type)
            yyerror("type_match_err");
        $$.val_int = $1.val_int * $3.val_int;
    }|
    expression '/' expression
    {
        if($1.val_type != $3.val_type)
            yyerror("type_match_err");
        $$.val_int = $1.val_int / $3.val_int;
    }|
    expression '+' expression
    {
        if($1.val_type != $3.val_type)
            yyerror("type_match_err");
        $$.val_int = $1.val_int + $3.val_int;
    }|
    expression '-' expression
    {
        if($1.val_type != $3.val_type)
            yyerror("type_match_err");
        $$.val_int = $1.val_int - $3.val_int;
    };
    
bool_exp:

%%

//yyerror(msg)
//char *msg;
//{
//    fprintf(stderr, "%s\n", msg);
//}

int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("compiler error:  %s  \n", s);
    // compier error exit()
    //abort();
    return 0;
}

int main(int argc, char const *argv[])
{
    /* open the source program file */
    //if (argc != 2) {
    //    printf ("Usage: sc filename\n");
    //    exit(1);
    //}
    //yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}
