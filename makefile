all:lex.yy.c
	g++ lex.yy.c -ll
 lex.yy.c: FirstLex.l
	lex FirstLex.l