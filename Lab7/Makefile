all: lex.yy.c y.tab.c y.tab.h
	gcc lex.yy.c y.tab.c
lex.yy.c: a.l y.tab.c
	flex a.l
y.tab.c: a.y
	bison -dy a.y

