all: lex.yy.c y.tab.c
	gcc lex.yy.c y.tab.c -o a
lex.yy.c: a.l y.tab.c
	flex a.l
y.tab.c: a.y
	bison -dy a.y

clean:
	rm -rf *.c *.h a
