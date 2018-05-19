
Digit   [0-9]
Letter  [a-zA-Z]
AllLetter [a-zA-Z0-9]

integer {Digit}+
fraction 0|[0-9]*[1-9]
plain_real {Digit}*\.{Digit}
float [+-]?{integer}\.{integer}
oth \.{integer}
expreal [+-]?[1-9]{oth}*[eE][+-]{integer}
real {plainreal}|{expreal}

%x Comm2Slide
%x CommStarSlide
%x StringMode

%{

#include "y.tab.h"
#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)
//printf("<'%s'>\n",yytext);
#define token(t) {LIST; return (t);}
//printf("<%s:%d>\n",t,atoi(i));
#define tokenInteger(t,i) {LIST;yylval.Data.val_int = atoi(i); yylval.Data.val_type = VAL_INT;return(INT);}
//printf("<%s:%s>\n",t,s);
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s); yylval.Data.val_str = strdup(s); yylval.Data.val_type = VAL_STR; return(STR);}
enum Type_enum{VAL_INT = 1, VAL_BOOL, VAL_STR, VAL_FLOAT, VAL_REAL};
int linenum = 1;
char buf[MAX_LINE_LENG];
char strBuf[MAX_LINE_LENG];
%}

%%
"(" {token('(');}
")" {token(')');}
"[" {token('[');}
"]" {token(']');}
"{" {token('{');}
"}" {token('}');}
"," {token(',');}
":" {token(':');}
";" {token(';');}


"+" {token('+');}
"-" {token('-');}
"*" {token('*');}
"/" {token('/');}
"%" {token('%');}
"<" {token('<');}
">" {token('>');}
"!" {token('!');}
"=" {token('=');}
"<=" {token(LESS_EQUAL);}
">=" {token(GREAT_EQUAL);}
"==" {token(EQUAL);}
"!=" {token(NOT_EQUAL);}
"&&" {token(AND_DOUBLE);}
"||" {token(OR_DOUBLE);}
"++" {token(ADD_DOUBLE);}
"--" {token(SUB_DOUBLE);}
"+=" {token(ADD_EQUAL);}
"-=" {token(SUB_EQUAL);}
"*=" {token(MUL_EQUAL);}
"/=" {token(DIV_EQUAL);}

"if" {token(IF);}
"bool" {token(BOOL);}
"break" {token(BREAK);}
"char" {token(CHAR);}
"continue" {token(CONTINUE);}
"do" {token(DO);}
"else" {token(ELSE);}
"enum" {token(ENUM);}
"extern" {token(EXTERN);}
"false" {yylval.Data.val_flag = FALSE; yylval.Data.val_type = VAL_BOOL;token(BOOL);}
"float" {token(FLOAT);}
"for" {token(FOR);}
"fn" {token(FN);}
"in" {token(IN);}
"int" {token(INT);}
"let" {token(LET);}
"loop" {token(LOOP);}
"match" {token(MATCH);}
"mut" {token(MUT);}
"print" {token(PRINT);}
"println" {token(PRINTLN);}
"pub" {token(PUB);}
"return" {token(RETURN);}
"self" {token(SELF);}
"static" {token(STATIC);}
"str" {token(STR);}
"struct" {token(STRUCT);}
"true" {yylval.Data.val_flag = TRUE; yylval.Data.val_type = VAL_BOOL;token(BOOL);}
"use" {token(USE);}
"where" {token(WHERE);}
"while" {token(WHILE);}

{Letter}{AllLetter}* {
	yylval.Data.name = strdup(yytext);
	yylval.Data.val_type = VAL_STR;
	printf("<%s:%s>\n", "ID", yytext);
	token(ID);
}

{integer} {tokenInteger("integer",yytext);}

{expreal} {
    yylval.Data.val_str = strdup(yytext);
	yylval.Data.val_type = VAL_REAL;
	token(REAL_NUMBER);
    }

{float}   {
    yylval.Data.val_float = atof(yytext);
	yylval.Data.val_type = VAL_FLOAT;
	token(FLOAT);
    }

"//"  {BEGIN(Comm2Slide);LIST;}

<Comm2Slide>[^\n]*        LIST;
<Comm2Slide>\n             {BEGIN(INITIAL);LIST;
                            printf("%d: %s", linenum, buf);
                            linenum++;
                            buf[0] = 0;}


"/*"         {BEGIN(CommStarSlide);LIST;}

<CommStarSlide>[^*\n]*        LIST;
<CommStarSlide>"*"+[^/\n]*   LIST;
<CommStarSlide>\n             {LIST;printf("%d: %s", linenum, buf);linenum++;buf[0] = 0;}
<CommStarSlide>"*"+"/"        {BEGIN(INITIAL);LIST;}

"\"" {BEGIN(StringMode);LIST;}

<StringMode>[^"\n]*        {LIST;strcat(strBuf,yytext);}
<StringMode>"\"\""        {LIST;strcat(strBuf,yytext);}
<StringMode>\n             {LIST;strcat(strBuf,yytext);printf("%d: %s", linenum, buf);buf[0] = 0;++linenum;}
<StringMode>"\""       {BEGIN(INITIAL);tokenString("string",strBuf);strBuf[0] = 0;}


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

int yywrap(void)        
{
LIST;
printf("%d: %s\n", linenum, buf);
linenum++;
buf[0] = 0;
buf[1] = 0;          
}

//main()
//{
//   myFirstNode = CreateTable();
//    yylex();
//    DumpTable(myFirstNode);
//}