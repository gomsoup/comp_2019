%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ast.h"
	struct Node *root;

	void yyerror(char *);
	
	//extern Node *createNode(int type, Node *l, Node *r);
	//Node *creteUopNode(int type, Node *n);
	//extern Node *createLeaf(int val);
%}
%union {
	int ival;
	struct Node *pval;
}
%start Prog

%token <ival> NUMBER

%left ADD SUB
%left MUL DIV 
%token ADD SUB LBR RBR EOL UOP

%type <pval> Exp
%type <pval> Term
%type <pval> Fact
%%
Prog	:	Exp EOL		{ root = $1; searchNode(root, 0); exit(0);}
	;

Exp	:	Term		{ $$ = $1; }
    	|	Exp ADD Exp	{ $$ = createNode(ADD, $1, $3); }
	|	Exp SUB	Exp	{ $$ = createNode(SUB, $1, $3); } 
	|	SUB Exp		{ $$ = createNode(UOP, $2, $2); }
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

