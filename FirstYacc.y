%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "SymbolTable.h"
int yyerror(char *s);
int yylex();
symTable myTable;

char *declareErr = "error: declare fall";

%}

%union 
{
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
%type<Data> bool_exp
%type<Data> func_invoke


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
    statements {Trace("statements reducing to program\n");};

statements: 
    statement {Trace("statement reducing to statements\n");} |
    statement statements {Trace("statement statements reducing to statements\n");};

statement:
    declared     {Trace("declared reducing to statement\n");}|
    simple_state {Trace("simple_state reducing to statement\n");}|
    bool_exp     {Trace("bool_exp reducing to statement\n");}|
    condition    {Trace("condition reducing to statement\n");}|
    loop         {Trace("loop reducing to statement\n");}|
    block        {Trace("block reducing to statement\n");};



declared:
    func_declared           {Trace("func_declared reducing to declared\n");}| 
    identifier_declared ';' {Trace("identifier_declared ';' reducing to declared\n");};

identifier_declared:
    constant_declared     {Trace("constant_declared reducing to identifier_declared\n");}|
    Variable_declared     {Trace("Variable_declared reducing to identifier_declared\n");}|
    Array_declared        {Trace("Array_declared reducing to identifier_declared\n");};

constant_declared:
    LET ID '=' standard_data  
    {
        if($4.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$4.val_int,$2.name,TRUE);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$4.val_str,$2.name,TRUE);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$4.val_flag,$2.name,TRUE);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$4.val_float,$2.name,TRUE);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET ID '=' standard_data_type reducing to constant_declared\n");
    }|
    LET ID ':' standard_data_type '=' standard_data         
    {
        if($4.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$6.val_int,$2.name,TRUE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$6.val_flag,$2.name,TRUE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$6.val_str,$2.name,TRUE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$6.val_float,$2.name,TRUE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET ID ':' standard_data_type '=' standard_data reducing to constant_declared\n");
    };

Variable_declared:
    LET MUT ID '=' standard_data
    {
        if($5.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$5.val_int,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            Trace("LET MUT ID '=' FLOAT reducing to constant_declared\n");
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$5.val_str,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$5.val_float,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$5.val_flag,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' standard_data reducing to constant_declared\n");
    }|
    LET MUT ID ':' standard_data_type '=' standard_data        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        if($5.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$7.val_int,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$7.val_str,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$7.val_float,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$7.val_flag,$3.name,FALSE);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type '=' standard_data reducing to constant_declared\n");
    }|
    LET MUT ID                        
    {
        variableNode v(VAL_INT,0,$3.name,FALSE);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID reducing to constant_declared\n");
    }|

    

    LET MUT ID ':' standard_data_type  
    {
        Trace("LET MUT ID ':' standard_data_type reducing to constant_declared\n");
    };


Array_declared:
    LET MUT ID '[' INT ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_INT,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' INT ',' INT ']' reducing to constant_declared\n");
    }|
    LET MUT ID '[' FLOAT ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_FLOAT,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' FLOAT ',' INT ']' reducing to constant_declared\n");
    }|
    LET MUT ID '[' STR ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_STR,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' STR ',' INT ']' reducing to constant_declared\n");
    }|
    LET MUT ID '[' BOOL ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_BOOL,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' BOOL ',' INT ']' reducing to constant_declared\n");
    };

standard_data_type:
    INT 
    {
        $$.val_type =  VAL_INT;
        Trace("INT reducing to standard_data_type\n");
    } |
    BOOL 
    {
        $$.val_type = VAL_BOOL;
        Trace("BOOL reducing to standard_data_type\n");
    } |
    STR   
    {
        $$.val_type = VAL_STR;
        Trace("STR reducing to standard_data_type\n");
    } |
    REAL_NUMBER 
    {
        $$.val_type = VAL_REAL;
        Trace("REAL_NUMBER reducing to standard_data_type\n");
    } |
    FLOAT 
    {
        $$.val_type = VAL_FLOAT;
        Trace("FLOAT reducing to standard_data_type\n");
    };

standard_data:
    INT 
    {
        $$.val_type =  VAL_INT;$$.val_int = $1.val_int; 
        Trace("INT reducing to standard_data\n");
    } |
    BOOL 
    {
        $$.val_type = VAL_BOOL;$$.val_flag = $1.val_flag; 
        Trace("BOOL reducing to standard_data\n");
    } |
    STR   
    {
        $$.val_type = VAL_STR;$$.val_str = $1.val_str;
        Trace("STR reducing to standard_data\n");
     } |
    FLOAT 
    {
        $$.val_type = VAL_FLOAT;$$.val_float = $1.val_float; 
        Trace("FLOAT reducing to standard_data\n");
    };

formal_argment:
    ID ':' standard_data_type
    {
        Trace("ID ':' standard_data_type reducing to formal_argment\n");
    };

formal_arguments:
    formal_argment ',' formal_arguments
    {
        Trace("formal_argment ',' formal_arguments reducing to formal_arguments\n");
    } |
    formal_argment
    {
        Trace("formal_argument reducing to formal_arguments\n");
    };                    

func_declared:
    FN ID '(' formal_arguments ')'
    {
        variableNode v(VAL_NULL,$2.name,FALSE);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' reducing to func_declared\n");
    }|
    FN ID '(' formal_arguments ')' '-' '>' INT 
    {
        variableNode v(VAL_INT,$8.val_int,$2.name,FALSE);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' '-' '>' INT reducing to func_declared\n");
    } |
     FN ID '(' formal_arguments ')' '-' '>' BOOL 
    {
        variableNode v(VAL_BOOL,$8.val_flag,$2.name,FALSE);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' '-' '>' INT reducing to func_declared\n");
    } |
     FN ID '(' formal_arguments ')' '-' '>' STR 
    {
        variableNode v(VAL_STR,$8.val_str,$2.name,FALSE);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' '-' '>' INT reducing to func_declared\n");
    } |
     FN ID '(' formal_arguments ')' '-' '>' FLOAT 
    {
        variableNode v(VAL_FLOAT,$8.val_float,$2.name,FALSE);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' '-' '>' INT reducing to func_declared\n");
    } |
    FN ID '(' ')'
    {
        Trace("FN ID '(' FN ID '(' ')' reducing to func_declared\n");
    } |
    FN ID '(' ')' '-' '>' standard_data_type
    {
        Trace("FN ID '(' ')' '-' '>' standard_data_type reducing to func_declared\n");
    };
    


simple_state:
    ID '=' bool_exp ';'
    {
        Trace("ID '=' bool_exp ';' reducing to simple_state\n");
    }|
    ID '[' expression ']' '=' expression ';'
    {
        Trace("ID '[' expression ']' '=' expression ';' reducing to simple_state\n");
    }|
    PRINT expression ';'
    {
        Trace("PRINT expression ';' reducing to simple_state\n");
    }|
    PRINTLN expression ';'
    {
        Trace("PRINTLN expression ';' reducing to simple_state\n");
    }|
 //   READ ID|
    RETURN ';'
    {
        Trace("RETURN ';' reducing to simple_state\n");
    }|
    RETURN expression ';' 
    {
        Trace("RETURN expression ';'  reducing to simple_state\n");
    };

object:ID;

func_arg:
    expression ',' func_arg
    {
        Trace("expression ',' func_arg  reducing to func_arg\n");
    }|
    expression
    {
        Trace("expression reducing to func_arg\n");
    };

func_invoke:
    ID  '(' func_arg ')' 
    {
        Trace("ID  '(' func_arg ')' reducing to func_invoke\n");
    }|
    ID '(' ')'
    {
        Trace("ID '(' ')' reducing to func_invoke\n");
    };



block:
    '{' '}'
    {
        Trace("'{' '}' reducing to block\n");
    }|
    '{' {myTable.pushTable();} statements '}'
    {
        myTable.popTable();
        Trace("ID '(' ')' reducing to block\n");
    };

expression:
    func_invoke{$$ = $1;}|
    object {$$ = $1;}|
    standard_data|
    '-' expression|
    '(' expression ')'|
    expression '*' expression|
    expression '/' expression|
    expression '+' expression|
    expression '-' expression;
    
bool_exp:
    expression|
    '!' bool_exp|
    bool_exp '<' bool_exp|
    bool_exp '>' bool_exp|
    bool_exp LESS_EQUAL bool_exp|
    bool_exp GREAT_EQUAL bool_exp|
    bool_exp EQUAL bool_exp|
    bool_exp NOT_EQUAL bool_exp|
    bool_exp AND_DOUBLE bool_exp|
    bool_exp OR_DOUBLE bool_exp|





condition:
    IF '(' bool_exp ')' block ELSE block|
    IF '(' bool_exp ')' block;

loop:
    WHILE '(' bool_exp ')' block;

%%

int yyerror(char *s)
{
    
    // printf("%d:  %s:  \n", linenum, s);
    printf("compiler error:  %s  \n", s);
    //compier error exit()
    abort();
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
