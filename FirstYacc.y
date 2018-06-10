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
int labelNum = 0;
int labelStackTop = 0;
int labelStack[20];
int funcArgSize;
int constDeclar;
char errWord[256];
char *declareErr = "error: declare fall";
FILE *myJavaCode;
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
%type<Data> func_arg

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
    LET ID '='{constDeclar = 1;} expression  
    {
        if($5.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$5.val_int,$2.name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            constDeclar = 0;
        }
        else if($5.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$5.val_str,$2.name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($5.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$5.val_flag,$2.name,true);
            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            
        }
        else if($5.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$5.val_float,$2.name,true);
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
    LET ID ':' standard_data_type '='{constDeclar = 1;} expression         
    {
        constDeclar = 0;
        if($4.val_type != $7.val_type)
        {
            yyerror(declareErr);
        }
        if($4.val_type == VAL_INT)
        {
            variableNode v(VAL_INT,$7.val_int,$2.name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_BOOL)
        {
            variableNode v(VAL_BOOL,$7.val_flag,$2.name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_STR)
        {
            variableNode v(VAL_STR,$7.val_str,$2.name,true);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
        }
        else if($4.val_type == VAL_FLOAT)
        {
            variableNode v(VAL_FLOAT,$7.val_float,$2.name,true);

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

    LET MUT ID '=' INT
    {

        variableNode v(VAL_INT,$5.val_int,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '=' INT reducing to Variable_declared\n");
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s = %d\n", $3.name, $5.val_int);
        else
        {
            variableNode *w = myTable.lookupVar_for_index($3.name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            fprintf(myJavaCode, "\t\tsipush %d\n",$5.val_int);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }

    }|
    LET MUT ID '=' BOOL
    {

        variableNode v(VAL_BOOL,$5.val_flag,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal()){
            if($5.val_flag == false)
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", $3.name, 0);
            else
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", $3.name, 1);
        }
        else
        {
            
            variableNode *w = myTable.lookupVar_for_index($3.name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            if($5.val_flag == false)
                fprintf(myJavaCode, "\t\tsipush %d\n",0);
            else
                fprintf(myJavaCode, "\t\tsipush %d\n",1);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        
        }
        
    }|
    LET MUT ID '=' STR
    {
       
        if($5.val_type == VAL_STR)
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

        Trace("LET MUT ID '=' standard_data reducing to Variable_declared\n");
    }|
    LET MUT ID ':' standard_data_type '=' INT        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        variableNode v(VAL_INT,$7.val_int,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s = %d\n", $3.name, $7.val_int);
        else
        {
            variableNode *w = myTable.lookupVar_for_index($3.name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            fprintf(myJavaCode, "\t\tsipush %d\n",$7.val_int);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }
    }|

    LET MUT ID ':' standard_data_type '=' STR        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        variableNode v(VAL_STR,$7.val_str,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }|
    LET MUT ID ':' standard_data_type '=' FLOAT        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        variableNode v(VAL_FLOAT,$7.val_float,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
    }|
    LET MUT ID ':' standard_data_type '=' BOOL        
    {
        if($5.val_type != $7.val_type)
            yyerror(declareErr);

        variableNode v(VAL_BOOL,$7.val_flag,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        if(myTable.checkGlobal()){
            printf("%d\n\n\n",$7.val_flag);
            if($7.val_flag == false)
            {
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", $3.name, 0);
            }
            else{
                fprintf(myJavaCode, "\tfield static bool %s = %d\n", $3.name, 1);
            }
                
        }
        else
        {
            variableNode *w = myTable.lookupVar_for_index($3.name);
            if(w == NULL)
            {
                yyerror(declareErr);
            }
            if($7.val_flag == false)
                fprintf(myJavaCode, "\t\tsipush %d\n",0);
            else
                fprintf(myJavaCode, "\t\tsipush %d\n",1);
            fprintf(myJavaCode, "\t\tistore %d\n",w->index);
        }
    }|
    LET MUT ID                        
    {
        variableNode v(VAL_INT,0,$3.name,false);

        if(!myTable.var_declare(v))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID reducing to Variable_declared\n");
        if(myTable.checkGlobal())
            fprintf(myJavaCode, "\tfield static int %s\n", $3.name);
        
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
            if(myTable.checkGlobal())
                fprintf(myJavaCode, "\tfield static int %s\n", $3.name);
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
            variableNode v(VAL_BOOL,true,$3.name,false);

            if(!myTable.var_declare(v))
            {
                yyerror(declareErr);
            }
            if(myTable.checkGlobal()){
                if($5.val_flag == false)
                    fprintf(myJavaCode, "\tfield static bool %s \n", $3.name);
                else
                    fprintf(myJavaCode, "\tfield static bool %s \n", $3.name);
            }
        }

        else{
            yyerror(declareErr);
        }
        Trace("LET MUT ID ':' standard_data_type reducing to constant_declared\n");
    };


Array_declared:
    LET MUT ID '[' standard_data_type ',' expression ']' 
    {
        if($7.val_type!= VAL_INT)
        {
            yyerror(declareErr);
        }
        if(!myTable.array_declare($5.val_type,$7.val_int,$3.name))
        {
            yyerror(declareErr);
        }
        Trace("LET MUT ID '[' standard_data_type ',' expression ']' reducing to Array_declared\n");
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
        
        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tsipush %d\n", $1.val_int);
        
    } |
    BOOL 
    {
        $$.val_type = VAL_BOOL;$$.val_flag = $1.val_flag; 
        Trace("BOOL reducing to standard_data\n");
        
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            if($$.val_flag)    
                fprintf(myJavaCode, "\t\ticonst_1\n");
            else        
                fprintf(myJavaCode, "\t\ticonst_0\n");
        }    
    } |
    STR   
    {
        $$.val_type = VAL_STR;$$.val_str = $1.val_str;
        Trace("STR reducing to standard_data\n");

        if((!myTable.checkGlobal()) && constDeclar==0)
            fprintf(myJavaCode, "\t\tldc \"%s\" \n", $1.val_str);
     } |
    FLOAT 
    {
        $$.val_type = VAL_FLOAT;$$.val_float = $1.val_float; 
        if((!myTable.checkGlobal()) && constDeclar==0)
        {
            fprintf(myJavaCode, "\t\tsipush %f\n", $1.val_float);
        }

        Trace("FLOAT reducing to standard_data\n");
    };

formal_argment:
    ID ':' standard_data_type
    {

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
        funcArgSize+=1;
        Trace("formal_argment ',' formal_arguments reducing to formal_arguments\n");
    } |
    formal_argment
    {
        funcArgSize+=1;
        Trace("formal_argument reducing to formal_arguments\n");
    };                    

func_block:
    '{' '}' {
        Trace("'{' '}' reducing to block\n");
        myTable.popTable();
        Trace("delete table\n");
        //fprintf(myJavaCode,"\t}\n");
    }|
    '{' statements '}' {
        //myTable.dumpTable();
        myTable.popTable();
        Trace("delete table\n");
        Trace("ID '(' statements ')' reducing to block\n");
        //fprintf(myJavaCode,"\t}\n");
    };

func_sign:
    FN {
        funcArgSize = 0;
        myTable.pushTable();printf("create new table\n");
        
        };

func_declared: 
    func_sign ID '('formal_arguments ')'{
        
        variableNode v(VAL_NULL,$2.name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        fprintf(myJavaCode,"\tmethod public static void %s(", $2.name);

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

    } func_block{
        fprintf(myJavaCode,"\t\treturn\n\t}\n");
        }
    |
    
    func_sign ID '(' ')' {
        variableNode v(VAL_NULL,$2.name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }
        if (strcmp($2.name, "main") == 0){
            fprintf(myJavaCode,"\tmethod public static void main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        }
        else{
            fprintf(myJavaCode,"\tmethod public static void %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $2.name);
        }

        Trace("FN ID '(' ')' reducing to func_declared\n");
    } func_block{fprintf(myJavaCode,"\t\treturn\n\t}\n");}
     |
     
    func_sign ID '(' formal_arguments ')' '-' '>'  standard_data_type
    {
        variableNode v($8.val_type,$2.name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }

        if (strcmp($2.name, "main") == 0){
            if($8.val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if($8.val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if($8.val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            }    
        else{
            if($8.val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int %s(", $2.name);
            else if($8.val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean %s(", $2.name);
            else if($8.val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string %s(", $2.name);
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
    } func_block {fprintf(myJavaCode,"\n\t}\n");}
    |
    
    func_sign ID '(' ')'  '-' '>' standard_data_type
    {
        variableNode v($7.val_type,$2.name,false);
        if(!myTable.func_declare(v))
        {
            yyerror(declareErr);
        }

        if (strcmp($2.name, "main") == 0){
            if($7.val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if($7.val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
            else if($7.val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string main(java.lang.String[])\n\tmax_stack 15\n\tmax_locals 15\n\t{\n");
        }    
        else{
            if($7.val_type == VAL_INT)
                fprintf(myJavaCode,"\tmethod public static int %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $2.name);
            else if($7.val_type == VAL_BOOL)
                fprintf(myJavaCode,"\tmethod public static boolean %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $2.name);
            else if($7.val_type == VAL_STR)
                fprintf(myJavaCode,"\tmethod public static string %s()\n\tmax_stack 15\n\tmax_locals 15\n\t{\n", $2.name);
        }
        Trace("FN ID '(' ')' func_sign standard_data_type reducing to func_declared\n");
    } func_block {fprintf(myJavaCode,"\n\t}\n");}
    ;
    


simple_state:
    ID '=' bool_exp ';'
    {
        variableNode *v = myTable.lookupVar($1.name);
        if(v->isGlobal)
        {
            fprintf(myJavaCode,"\t\tputstatic int Project.%s\n", $1.name);
        }
        else{
            fprintf(myJavaCode, "\t\tistore %d\n", v->index);
        }
        if($3.val_type == VAL_INT)
        {
            variableNode v($3.val_type,$3.val_int,$1.name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if($3.val_type == VAL_FLOAT)
        {
            variableNode v($3.val_type,$3.val_float,$1.name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if($3.val_type == VAL_STR)
        {
            variableNode v($3.val_type,$3.val_str,$1.name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
        }
        else if($3.val_type == VAL_BOOL)
        {
            variableNode v($3.val_type,$3.val_flag,$1.name,true);
            if(!myTable.assignVal(v))
            {
                strcpy(errWord,"assign wrong\0");
                yyerror(errWord);
            }
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
        if($6.val_type == VAL_INT)
        {
            variableNode v($6.val_type,$6.val_int,$1.name,false);
            myTable.assignArr($3.val_int,v);
        }
        else if($6.val_type == VAL_FLOAT)
        {
            variableNode v($6.val_type,$6.val_float,$1.name,false);
            myTable.assignArr($3.val_int,v);
        }
        else if($6.val_type == VAL_STR)
        {
            variableNode v($6.val_type,strdup($6.val_str),$1.name,false);
            myTable.assignArr($3.val_int,v);
        }
        else if($6.val_type == VAL_BOOL)
        {
            variableNode v($6.val_type,$6.val_flag,$1.name,false);
            myTable.assignArr($3.val_int,v);
        }
        Trace("ID '[' expression ']' '=' expression ';' reducing to simple_state\n");
    }|
    PRINT{fprintf(myJavaCode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}  expression ';'
    {
        if($3.val_type == VAL_STR)
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
        else
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n"); 

        Trace("PRINT expression ';' reducing to simple_state\n");
    }|
    PRINTLN{fprintf(myJavaCode,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");}  expression ';'
    { 
        if($3.val_type == VAL_STR)
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
        else
            fprintf(myJavaCode,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n"); 
        
        Trace("PRINTLN expression ';' reducing to simple_state\n");
    }|
    RETURN ';'
    {
        fprintf(myJavaCode,"\t\tireturn\n");
        Trace("RETURN ';' reducing to simple_state\n");
    }|
    RETURN expression ';' 
    {
        fprintf(myJavaCode,"\t\tireturn\n");
        Trace("RETURN expression ';'  reducing to simple_state\n");
    };



func_arg:
    expression ',' func_arg
    {
        
        int len = strlen($3.arg_var_type)+3;
        
        $$.arg_var_type = (char*)malloc(len*sizeof(char)); 
        sprintf($$.arg_var_type, "%d", $1.val_type);
        strcat($$.arg_var_type, ",");
        strcat($$.arg_var_type, $3.arg_var_type);
        free( $3.arg_var_type);
        
        Trace("expression ',' func_arg  reducing to func_arg\n");

    }|
    expression
    {
        $$.arg_var_type = (char*)malloc(2*sizeof(char)); 
        sprintf($$.arg_var_type, "%d", $1.val_type);
        Trace("expression reducing to func_arg\n");
    };

func_invoke:
    ID  '(' func_arg ')' 
    {
        
        strcpy(errWord ,"arg error");
        variableNode *v =  myTable.lookupFunc($$.name);
        if(v == NULL)
            yyerror(errWord);


        if(!myTable.func_type_check($1.name, $3.arg_var_type))
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

    }|
    ID '(' ')'
    {
        strcpy(errWord ,"arg error");
        variableNode *v =  myTable.lookupFunc($$.name);
        if(v == NULL)
            yyerror(errWord);
        
        if(!myTable.func_type_check($1.name,strdup("")))
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
                    fprintf(myJavaCode,"\t\tgetstatic int Project.%s\n", $1.name);
                else if(v->val_Type == VAL_BOOL)            
                    fprintf(myJavaCode,"\t\tgetstatic bool Project.%s\n", $1.name);
                else if(v->val_Type == VAL_FLOAT)
                    fprintf(myJavaCode,"\t\tgetstatic float Project.%s\n", $1.name);
                else if(v->val_Type == VAL_STR)
                    fprintf(myJavaCode,"\t\tgetstatic str Project.%s\n", $1.name);
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
};

expression:
    func_invoke{$$ = $1;}|
    object {$$ = $1;}|
    standard_data{$$ = $1;}|
    '-' expression{$$ = $2;fprintf(myJavaCode, "\t\tineg\n");}|
    '(' expression ')'{$$ = $2;}|
    expression '*' expression
    {
        printf("%d %d",$1.val_type , $3.val_type);
        strcpy(errWord,"type error");
        if($1.val_type != $3.val_type){
            yyerror(errWord);
        }
        
        fprintf(myJavaCode, "\t\timul\n");
        $$.val_type = $1.val_type;
        $$.val_int = $1.val_int * $3.val_int;
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
        
        fprintf(myJavaCode, "\t\tidiv\n");
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

        
        fprintf(myJavaCode, "\t\tiadd\n");
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
        
        fprintf(myJavaCode, "\t\tisub\n");
    }|
    expression '%' expression
    {
        strcpy(errWord,"tyep error"); 
        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        fprintf(myJavaCode, "\t\tirem\n");
    };


bool_exp:
    expression|
    '!' bool_exp {$$ = $2;}|
    bool_exp AND_DOUBLE bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tiand\n");

    }| 
    bool_exp OR_DOUBLE bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tior\n");

    }| 
    bool_exp '!' bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tixor\n");
    }| 
    bool_exp '<' bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tiflt L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }|

    bool_exp '>' bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifgt L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }|
    bool_exp LESS_EQUAL bool_exp {
        strcpy(errWord,"tyep error"); 
        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifle L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }|
    bool_exp GREAT_EQUAL bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifge L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }|

    bool_exp EQUAL bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifeq L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }|
    bool_exp NOT_EQUAL bool_exp {
        strcpy(errWord,"tyep error"); 

        if($1.val_type != $3.val_type)
            yyerror(errWord);
        $$ = $1;
        $$.val_type = VAL_BOOL;
        fprintf(myJavaCode, "\t\tisub\n");
        fprintf(myJavaCode, "\t\tifne L%d\n", labelNum);
        fprintf(myJavaCode, "\t\ticonst_0\n");
        fprintf(myJavaCode, "\t\tgoto L%d\n",labelNum+1);
        fprintf(myJavaCode, "\tL%d:\n\t\ticonst_1\n",labelNum);
        fprintf(myJavaCode, "\tL%d:\n",labelNum+1);
        labelNum +=2;
    }
    ;



condition_else:
    block ELSE
    {
        fprintf(myJavaCode,"\t\tgoto L%d\n", labelStack[labelStackTop-1] + 1);
        //else lable
        fprintf(myJavaCode, "\tL%d:\n", labelStack[labelStackTop - 1]);
    } block
    {
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop] + 1);
    }|block
    {
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop]);
    };


condition:
    IF '(' bool_exp ')'
    {
        
        labelStack[labelStackTop++] = labelNum;
        fprintf(myJavaCode,"\t\tifeq L%d\n", labelNum);
        labelNum += 2;        
    } condition_else;

loop:
    WHILE
    {
        labelStack[labelStackTop++] = labelNum;
        fprintf(myJavaCode, "\tL%d:\n", labelNum);
        labelNum += 2; 
    } '(' bool_exp ')'
    {
            fprintf(myJavaCode,"\t\tifeq L%d\n", labelStack[labelStackTop-1]+1);
    } block
    {
        fprintf(myJavaCode,"\t\tgoto L%d\n", labelStack[labelStackTop-1]);
        fprintf(myJavaCode, "\tL%d:\n", labelStack[--labelStackTop] + 1);
    };

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
