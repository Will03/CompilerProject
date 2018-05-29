a.exe: y.tab.c lex.yy.c y.tab.h SymbolTable.h SymbolTable.cpp
	g++ -std=c++11 lex.yy.c y.tab.c SymbolTable.cpp SymbolTable.h -ll -ly

lex.yy.c: FirstLex.l
	flex FirstLex.l

y.tab.c: FirstYacc.y
	yacc -d FirstYacc.y
	
clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h a.out
	

