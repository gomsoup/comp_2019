%{
	#include <stdio.h>
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
Line	: Exp { printf("= %d \n", $1); }
	;

Exp	: Exp '+' Term	{ $$ = $1 + $3; }
    	| Exp '-' Term	{ $$ = $1 - $3; }
	| Term		{ $$ = $1; } 
	;

Term	: Term '*' Fact	{ $$ = $1 * $3; }
     	| Term '/' Fact { $$ = $1 / $3; }
	| Fact		{ $$ = $1; }
	;

Fact	: '-' Exp	{ $$ = -$2; }
     	| '(' Exp ')'	{ $$ = $2; }
	| NUMBER	{ $$ = $1; }
	;
%%

int main() { yyparse(); return 0;}
void yyerror(const char *msg) { fputs(msg, stderr); }
