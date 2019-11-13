#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int LA;
void error(char *msg) {
	printf("ERROR: %s\n", msg);
	exit(1);
}

int yylex() {
	return getchar();
}

int match(int t) {
	if (LA == t)
		LA = yylex();
	else
		error("lexical error");
}

bool eof() {
	return LA == EOF;
}

int E(), T(), F(), Ed(), Td();

int E(){
	if (eof()){
		puts("E -> EOF()");
		exit(0);
	}
	else{
		puts("E -> T E'");
		T(); Ed();

	}
}

int T(){
	puts("T -> F T'");
	F(); Td();
}

int Ed(){
	if(LA == "+"){
		puts("E' -> + T E'");
		int d1 = 0, d2 = 0;
		match('+'); d1 = T(); d2 = Ed();
		return d1 + d2;
	}
	else
		return 0;
}

int Td(){
	if(LA == '*'){
		puts("T' -> * F T'");
		int d1 = 0, d2 = 0;
		match('*'); d1 = F(); d2 = Td();
		return d1 * d2;
	}
	else
		return 0;
}

int F(){
	if(LA == '('){
		puts("F -> ( E )");
		int d1 = 0;
		match('('); E(); match(')');
	}
	else
		return LA;
}

int main() {
	LA = yylex();
	E();
	return 0;
}
