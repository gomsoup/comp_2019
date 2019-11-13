#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int LA=-1;
int num = 0, result = 0;

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
	return LA == '\n';
}


int F(){
	if(LA == '('){
		match('('); int d1 = E();  match(')');
		return d1;
	}
	else{
		while(true){
			if(LA == 32)
				match(32);
			else break;
		}
		

		int d1;
		if(LA == '('){
			match('('); d1 = E(); match(')');
		}
		else
			d1 = LA;

		LA = yylex();
		
		while(true){
			if (LA == 32) 
				match(32);
			else break;
		}
	
		if(isdigit(d1)) d1 -= '0';
		return d1;	
	}
}

int Td(){
	if(LA == 32) 
		match(32);

	if(LA == '*'){
		match('*'); 
		int d1, d2;
		d1 = F(); 
		d2 = Td();
		
		if(d2 == -1) return d1;
		else return d1 * d2;
	}
	else{
		return -1;
	}
}

int T(){
	int d1, d2;
	d1 = F(); 
	d2 = Td();
	if(d2 == -1) return d1;
	else return d1 * d2;
}

int Ed(){
	if(LA == 32) 
		match(32);

	if(LA=='+'){
		match('+'); 
		int d1 = T(); 
		int d2 = Ed();
	
		if(d2 == -1) return d1;
		return d1 + d2;
	}
	else{
		return -1;
	}
}
		
int E(){
	if(LA == '\n' - '0') return 0;

	int d1, d2;
	d1 = T();
	d2 = Ed();

	if(d2 == -1) return d1;
	else return d1 + d2;
}

int main() {
	LA = yylex();
	printf("%d\n", E());
	return 0;
}
