all: lex.yy.c y.tab.c
	gcc -W lex.yy.c y.tab.c -o expr
lex.yy.c: expr.l y.tab.c
	flex expr.l
y.tab.c: expr.y
	bison -dy expr.y

clean:
	rm -rf *.c *.h expr
