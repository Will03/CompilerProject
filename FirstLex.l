
Digit   [0-9]
Letter  [a-zA-Z]
AllLetter [a-zA-Z0-9]

integer {Digit}+
fraction 0|[0-9]*[1-9]
plain_real {Digit}*\.{Digit}
float [+-]?{integer}\.{fraction}
expreal [1-9]\.{integer}[eE][+-]{integer}
real {plainreal}|{expreal}

%x Comm2Slide
%x CommStarSlide
%x StringMode

%{

#include"MySymbolTable.h"
#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,atoi(i));}
#define tokenFloat(t,i) {LIST; printf("<%s:%f>\n",t,atof(i));}
#define tokenExponent(t,i) {LIST; printf("<%s:%g>\n",t,atof(i));}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}
int linenum = 1;
char buf[MAX_LINE_LENG];
char strBuf[MAX_LINE_LENG];
SymDataNode* myFirstNode; 
%}

%%
"(" {token("'('");}
")" {token("')'");}
"[" {token("'['");}
"]" {token("']'");}
"{" {token("'{'");}
"}" {token("'}'");}
"," {token("','");}
":" {token("':'");}
";" {token("';'");}


"+" {token("'+'");}
"-" {token("'-'");}
"*" {token("'*'");}
"/" {token("'/'");}
"%" {token("'%'");}
"<" {token("'<'");}
">" {token("'>'");}
"!" {token("'!'");}
"=" {token("'='");}
"<=" {token("'<='");}
">=" {token("'>='");}
"==" {token("'=='");}
"!=" {token("'!='");}
"&&" {token("'&&'");}
"||" {token("'||'");}
"++" {token("'++'");}
"--" {token("'--'");}
"+=" {token("'+='");}
"-=" {token("'-='");}
"*=" {token("'*='");}
"/=" {token("'/='");}

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

{Letter}{AllLetter}* {tokenString("id",yytext);InsertTable(myFirstNode,yytext);}
("+"|"-")?{integer} {tokenInteger("integer",yytext);}
{expreal} {tokenExponent("exponent",yytext);}
{float} {tokenFloat("float",yytext);}

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
<StringMode>"\""       {BEGIN(INITIAL);tokenString("string",strBuf);}


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

main()
{
    myFirstNode = CreateTable();
    yylex();
    DumpTable(myFirstNode);
}