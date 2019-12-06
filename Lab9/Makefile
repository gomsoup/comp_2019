all: lex.yy.c y.tab.c y.tab.h ast.o ast.h
	g++ -std=c++11 -o ast lex.yy.cpp y.tab.cpp ast.o
lex.yy.c: a.l
	flex -o lex.yy.cpp a.l
y.tab.c: a.y
	bison -dy -o y.tab.cpp a.y
	mv y.tab.hpp y.tab.h
ast.o: ast.cpp
	gcc -c -g -o ast.o ast.cpp 
clean:
	rm y.tab.* lex.yy.* ast.o ast
