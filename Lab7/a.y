%{
	#include <stdio.h>
	#include "ast.h"
	struct Node *root;

	void yyerror(char *);
	
	extern Node *createNode(int type, Node *l, Node *r);
	//Node *creteUopNode(int type, Node *n);
	extern Node *createLeaf(int val);
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
%token ADD SUB LBR RBR EOL
%type <pval> Exp
%type <pval> Term
%type <pval> Fact

%%
Prog	:	Exp		{ puts("p -> e"); root = $1; }
     	;

Exp	:	Term		{ puts("e -> t"); $$ = $1; }
    	|	Exp ADD Exp	{ puts("e -> e + e"); $$ = createNode(ADD, $1, $3); }
	|	Exp SUB	Exp	{ puts("e -> e - s"); $$ = createNode(SUB, $1, $3); } 
	;
Term	:	Fact		{ puts("t -> f"); $$ = $1; }
     	|	Term MUL Term	{ puts("t -> t * t"); $$ = createNode(MUL, $1, $3); }
	|	Term DIV Term	{ puts("t -> t / t"); $$ = createNode(DIV, $1, $3); }
	;
Fact	:	LBR Exp RBR	{ puts("f -> ( e )"); $$ = $2; }
     	|	NUMBER		{ puts("f -> number"); $$ = createLeaf($1); }
	;

%%

void yyerror(char *msg){
	printf("ERROR: %s", msg);
}

int main(){
	yyparse();
	return 0;
}

