
Digit   [0-9]
Letter  [a-zA-Z]
integer {Digit}
plain_real {Digit}"."{Digit}
expreal {Digit}"."{Digit}[Ee][+-]?{Digit}
real {plainreal}|{expreal}


%{

#include"MySymbolTable.h"
#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,atoi(i));}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}
int linenum = 0;
char buf[MAX_LINE_LENG];
SymDataNode* myFirstNode;
static void skipcomm(void);
static void skipDouQuo(void); 
%}

%%
"(" {token("(");}
")" {token(")");}
"[" {token("[");}
"]" {token("]");}
"{" {token("{");}
"}" {token("}");}
"," {token(",");}
":" {token(":");}
";" {token(";");}

"\"" {skipDouQuo();}
"+" {token("+");}
"-" {token("-");}
"*" {token("*");}
"/" {token("/");}
"%" {token("%");}
"<" {token("<");}
">" {token(">");}
"!" {token("!");}
"=" {token("=");}
"<=" {token("<=");}
">=" {token(">=");}
"==" {token("==");}
"!=" {token("!=");}
"&&" {token("&&");}
"||" {token("||");}
"++" {token("++");}
"--" {token("--");}
"+=" {token("+=");}
"-=" {token("-=");}
"*=" {token("*=");}
"/=" {token("/=");}

"if" {token("IF");}
"bool" {token("BOOL");}
"break" {token("BREAK");}
"char" {token("CHAR");}
"continue" {token("CONTINUE");}
"do" {token("DO");}
"else" {token("ELSE");}
"enum" {token("ENUM");}
"extern" {token("EXTERN");}
"false" {token("FALSE");}
"float" {token("FLOAT");}
"for" {token("FOR");}
"fn" {token("FN");}
"in" {token("IN");}
"int" {token("INT");}
"let" {token("LET");}
"loop" {token("LOOP");}
"match" {token("MATCH");}
"mut" {token("MUT");}
"print" {token("PRINT");}
"println" {token("PRINTLN");}
"pub" {token("PUB");}
"return" {token("RETURN");}
"self" {token("SELF");}
"static" {token("STATIC");}
"str" {token("STR");}
"struct" {token("STRUCT");}
"true" {token("TRUE");}
"use" {token("USE");}
"where" {token("WHERE");}
"while" {token("WHILE");}

[a-zA-Z][0-9a-zA-Z]* {tokenString("ID",yytext);InsertTable(myFirstNode,yytext);}
{integer}+ {tokenInteger("integer",yytext);}

"//".*  { /* consume //-comment */ }
"/*"    {skipcomm();} 
\n {
LIST;
printf("%d: %s", linenum, buf);
linenum++;
buf[0] = 0;
}

[ \t]* {LIST;}
. {
LIST;
printf("%d:%s\n", linenum, buf);
printf("bad character:’%s’\n",yytext);
exit(-1);
}
%%
static void skipcomm(void)
{
    char c;
    int mybuflen = strlen(buf);
    for(;(c = yyinput()) != '\0';)
    {
        if(c == '*')
        {
            if((c = yyinput())== '/')
                return;
            else if(c == '\n')
            {
                LIST;
            }
            else
            {
                unput(yytext[yyleng-1]);
                buf[mybuflen++] = c;
                buf[mybuflen] = '\0';
            }
        }
    }
} 
static void skipDouQuo(void)
{
    char c;
    char totalString[256] = {0};
    int totalSlen = 0;
    int mybuflen = strlen(buf);
    for(;(c = yyinput()) != '\0';)
    {
        if(c == '"')
        {
            tokenString("string",totalString);
            return;
        }
        totalString[totalSlen++] = c;
        totalString[totalSlen] = '\0';
        buf[mybuflen++] = c;
        buf[mybuflen] = '\0';
    }
}

main()
{
    myFirstNode = CreateTable();
    yylex();
    DumpTable(myFirstNode);
}