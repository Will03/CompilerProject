%{
#define Trace(t)        printf(t)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "SymbolTable.h"
extern int yyerror(char *s);
int yylex();
symTable myTable;
char errWord[256];
char *declareErr = "error: declare fall";
int is_push = 0;
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
%right '<' '>' LESS_EQUAL GREAT_EQUAL EQUAL NOT_EQUAL AND_DOUBLE OR_DOUBLE
%right ADD_DOUBLE SUB_DOUBLE ADD_EQUAL MUL_EQUAL SUB_EQUAL DIV_EQUAL
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
            variableNode v(VAL_INT,$5.val_int,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            Trace("LET MUT ID '=' FLOAT reducing to Variable_declared\n");
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$5.val_str,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$5.val_float,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$5.val_flag,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' standard_data reducing to Variable_declared\n");
    }|
    LET MUT ID ':' standard_data_type '=' standard_data        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        if($5.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$7.val_int,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$7.val_str,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$7.val_float,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$7.val_flag,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type '=' standard_data reducing to Variable_declared\n");
    }|
    LET MUT ID                        
    {
        variableNode v(VAL_INT,0,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID reducing to Variable_declared\n");
    }|

    

    LET MUT ID ':' standard_data_type  
    {
        if($5.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,0,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,0,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,0,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,TRUE,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type reducing to constant_declared\n");
    };


Array_declared:
    LET MUT ID '[' INT ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_INT,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' INT ',' INT ']' reducing to Array_declared\n");
    }|
    LET MUT ID '[' FLOAT ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_FLOAT,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' FLOAT ',' INT ']' reducing to Array_declared\n");
    }|
    LET MUT ID '[' STR ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_STR,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' STR ',' INT ']' reducing to Array_declared\n");
    }|
    LET MUT ID '[' BOOL ',' INT ']' 
    {
        if(!myTable.array_declare(VAL_BOOL,$7.val_int,$5.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' BOOL ',' INT ']' reducing to Array_declared\n");
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
        if(!is_push)
        {
            myTable.pushTable();printf("create new table\n");
            is_push = 1;
        }
        if($3.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,0,$1.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($3.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,0,$1.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($3.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,0,$1.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($3.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,TRUE,$1.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else{
            yyerror(declareErr);
        }
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

func_block:
    '{' '}'
    {
        Trace("'{' '}' reducing to block\n");
    }|
    '{' 
    
    {
        if(!is_push)
        {
            myTable.pushTable();printf("create new table\n");
            is_push = 1;
        }
    }
    statements '}' 
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
    };


func_declared:
    FN ID '(' formal_arguments ')' func_block
    {
        variableNode v(VAL_NULL,$2.name,false);
        is_push = 0;
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' reducing to func_declared\n");
    }|
    FN ID '(' ')' func_block
    {
        variableNode v(VAL_NULL,$2.name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' FN ID '(' ')' reducing to func_declared\n");
    } |
     FN ID '('formal_arguments ')' '-' '>'  standard_data_type   func_block
    {
        variableNode v($8.val_type,$2.name,false);
        is_push = 0;
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' formal_arguments ')' '-' '>' standard_data_type reducing to func_declared\n");
    } |
    FN ID '(' ')' '-' '>' standard_data_type func_block
    {
        variableNode v($7.val_type,$2.name,false);
        is_push = 0;
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("FN ID '(' ')' '-' '>' standard_data_type reducing to func_declared\n");
    };
    


simple_state:
    ID '=' bool_exp ';'
    {
        if($3.val_type == VAL_INT)
        {
            variableNode v($3.val_type,$3.val_int,$1.name,TRUE);
            myTable.assignVal(v);
        }
        else if($3.val_type == VAL_FLOAT)
        {
            variableNode v($3.val_type,$3.val_float,$1.name,TRUE);
            myTable.assignVal(v);
        }
        else if($3.val_type == VAL_STR)
        {
            variableNode v($3.val_type,$3.val_str,$1.name,TRUE);
            myTable.assignVal(v);
        }
        else if($3.val_type == VAL_BOOL)
        {
            variableNode v($3.val_type,$3.val_flag,$1.name,TRUE);
            myTable.assignVal(v);
        }
        Trace("ID '=' bool_exp ';' reducing to simple_state\n");
    }|
    ID '[' expression ']' '=' expression ';'
    {
        if($3.val_type != VAL_INT)
        {
            strcpy(errWord,"need integer type\n");
            yyerror(errWord);
        }
        Trace("ID '[' expression ']' '=' expression ';' reducing to simple_state\n");
    }|
    PRINT expression ';'
    {
        if($2.val_type == VAL_INT)
        {
            printf("%d\n",$2.val_int);
        }
        else if($2.val_type == VAL_FLOAT)
        {
            printf("%f\n",$2.val_float);
        }
        else if($2.val_type == VAL_BOOL)
        {
            printf("%d\n",$2.val_flag);
        }
        else if($2.val_type == VAL_STR)
        {
            printf("%s\n",$2.val_str);
        }
        else{
            strcpy(errWord,"print error\n");
            yyerror(errWord);
        }
        
        Trace("PRINT expression ';' reducing to simple_state\n");
    }|
    PRINTLN expression ';'
    {
        if($2.val_type == VAL_INT)
        {
            printf("%d\n",$2.val_int);
        }
        else if($2.val_type == VAL_FLOAT)
        {
            printf("%f\n",$2.val_float);
        }
        else if($2.val_type == VAL_BOOL)
        {
            printf("%d\n",$2.val_flag);
        }
        else if($2.val_type == VAL_STR)
        {
            printf("%s\n",$2.val_str);
        }
        else{
            strcpy(errWord,"print error\n");
            yyerror(errWord);
        }
        
        Trace("PRINTLN expression ';' reducing to simple_state\n");
    }|
    RETURN ';'
    {
        Trace("RETURN ';' reducing to simple_state\n");
    }|
    RETURN expression ';' 
    {
        Trace("RETURN expression ';'  reducing to simple_state\n");
    };



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
    '{' {myTable.pushTable();Trace("create new table\n");} statements '}' 
    {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
    };
    
object:ID 
{
    variableNode * v = myTable.lookupVar($1.name);
    strcpy(errWord,"assign wrong\0");
    if(v != NULL)
    {
        $$.name = $1.name;
        $$.val_type = v->val_Type;
        if(v->val_Type == VAL_INT)
            $$.val_int = v->data.val_int;
        
        else if(v->val_Type == VAL_FLOAT)
            $$.val_float = v->data.val_float;

        else if(v->val_Type == VAL_STR)
            $$.val_str = v->data.val_str;

        else if(v->val_Type == VAL_BOOL)
            $$.val_flag = v->data.val_flag;
        
        else 
            yyerror(errWord);
    }
    else{
        strcpy(errWord,"can not find variable"); 
        yyerror(errWord);
        
    }   
};

expression:
    func_invoke{$$ = $1;}|
    object {$$ = $1;}|
    standard_data{$$ = $1;}|
    '-' expression{$$ = $2;}|
    '(' expression ')'{$$ = $2;}|
    expression '*' expression
    {
        strcpy(errWord,"type error");
        if($1.val_type != $3.val_type)
            yyerror(errWord);
        if($1.val_type != VAL_INT && $1.val_type != VAL_FLOAT)
            yyerror(errWord);
        if($1.val_type == VAL_INT)
        {
            $$.val_type = $1.val_type;
            $$.val_int = $1.val_int * $3.val_int;
        }
        else if($1.val_type == VAL_FLOAT)
        {
            $$.val_type = $1.val_type;
            $$.val_float = $1.val_float * $3.val_float;
        }
        else 
            yyerror(errWord);
    }|
    expression '/' expression
    {
        strcpy(errWord,"type error");
        if($1.val_type != $3.val_type)
            yyerror(errWord);
        if($1.val_type != VAL_INT && $1.val_type != VAL_FLOAT)
            yyerror(errWord);
        if($1.val_type == VAL_INT)
        {
            if($3.val_int == 0)
            {
                strcpy(errWord,"divide 0");
                yyerror(errWord);
            }
            $$.val_type = $1.val_type;
            $$.val_int = $1.val_int / $3.val_int;
        }
        else if($1.val_type == VAL_FLOAT)
        {
            if($3.val_float == 0)
            {
                strcpy(errWord,"divide 0");
                yyerror(errWord);
            }
            $$.val_type = $1.val_type;
            $$.val_float = $1.val_float / $3.val_float;
        }
        else 
            yyerror(errWord);
    }|
    expression '+' expression
    {
        strcpy(errWord,"type error");
        if($1.val_type != $3.val_type)
            yyerror(errWord);
        if($1.val_type != VAL_INT && $1.val_type != VAL_FLOAT)
            yyerror(errWord);
        if($1.val_type == VAL_INT)
        {
            $$.val_type = $1.val_type;
            $$.val_int = $1.val_int + $3.val_int;
        }
        else if($1.val_type == VAL_FLOAT)
        {
            $$.val_type = $1.val_type;
            $$.val_float = $1.val_float + $3.val_float;
        }
        else 
            yyerror(errWord);
    }|
    expression '-' expression
    {
        strcpy(errWord,"type error");

        if($1.val_type != VAL_INT && $1.val_type != VAL_FLOAT)
            yyerror(errWord);
        if($1.val_type == VAL_INT)
        {
            $$.val_type = $1.val_type;
            $$.val_int = $1.val_int - $3.val_int;
        }
        else if($1.val_type == VAL_FLOAT)
        {
            $$.val_type = $1.val_type;
            $$.val_float = $1.val_float - $3.val_float;
        }
        else 
            yyerror(errWord);
    };


bool_exp:
    expression|
    '!' bool_exp {$$ = $2;}|
    bool_exp '<' bool_exp|
    bool_exp '>' bool_exp|
    bool_exp LESS_EQUAL bool_exp|
    bool_exp GREAT_EQUAL bool_exp|
    bool_exp EQUAL bool_exp|
    bool_exp NOT_EQUAL bool_exp|
    bool_exp AND_DOUBLE bool_exp|
    bool_exp OR_DOUBLE bool_exp;





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
    exit(0);
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
    if (yyparse() == 1) 
                    /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    printf("\n\nEND PROGRAM\n");
    myTable.dumpTable();
}
