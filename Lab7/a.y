%{
	#include <stdio.h>
	#include "ast.h"
	struct Node *root;

	void yyerror(char *);
%}
%union {
	char *sval;
	int ival;
	struct Node *pval;
}
%start Prog
%token <ival> NUMBER
%token <sval> ID
%left ADD SUB 
%left MUL DIV 
%token LBR RBR EOL
%type <pval> Exp
%type <pval> Term
%type <pval> Fact

%%
Prog	:	Exp		{ root = $1; }
     	;
Exp	:	Term		{ $$ = $1; }
    	|	Exp ADD Exp	{ $$ = createNode(ADD, $1, $3); }
	|	Exp SUB	Exp	{ $$ = createNode(SUB, $1, $3); } 
	;
Term	:	Fact		{ $$ = $1; }
     	|	Term MUL Term	{ $$ = createNode(MUL, $1, $3); }
	|	Term DIV Term	{ $$ = createNode(DIV, $1, $3); }
	;
Fact	:	LBR Exp RBR	{ $$ = $2; }
     	|	NUMBER		{ $$ = createLeaf($1); }
	;
%%

void yyerror(char *msg){
	printf("ERROR: %s", msg);
}

int main(){
	yyparse();
	return 0;
}

