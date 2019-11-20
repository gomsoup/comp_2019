all: lex.yy.c y.tab.c ast.o ast.h y.tab.h
	gcc -g  lex.yy.c y.tab.c ast.o
lex.yy.c: a.l y.tab.c
	flex a.l
y.tab.c: a.y
	bison -dy a.y
ast.o: ast.c
	gcc -c -g ast.c
clean:
	rm lex.yy.c y.tab.c ast.o y.tab.h a.out
