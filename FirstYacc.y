%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int yyerror(char *s);
int yylex();

enum Type_enum{VAL_INT = 0, VAL_BOOL = 1, VAL_STR, VAL_REAL};

%}

%union 
{
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
}



%type<Data> ID
%type<Data> STR
%type<Data> REAL_NUMBER
%type<Data> NUMBER
%type<Data> standard_data_type
//%type<Token> identifier_list
//%type<Token> argument_list
//%type<Token> bool_type
//%type<Token> primitive_type
//%type<Token> primitive
//%type<Token> expression
//%type<Token> bool_exp
// %type<Token> mix_exp
//%type<Token> array_element
//%type<Token> object
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
%token FLOAT
%token FOR
%token FN
%token IN
%token INT
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

%token NUMBER
%token STR
%token ID
%token REAL_NUMBER

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
    declared { Trace("declare id \n");}



declared:
    func_declared | 
    //identifier_declared ;


standard_data_type:
    INT {$$.val_type =  VAL_INT;} |
    BOOL {$$.val_type = VAL_BOOL;} |
    STR   {$$.val_type = VAL_STR;} |
    REAL_NUMBER {$$.val_type = VAL_REAL;} ;

formal_argment:
    ID ':' standard_data_type

formal_arguments:
    formal_argment ',' formal_arguments |
    formal_argment                      


func_declared:
    FN ID '(' formal_arguments ')' {}|
    FN ID '(' ')' {}
    


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
