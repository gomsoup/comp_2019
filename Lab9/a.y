%{
	#include <stdio.h>
	#include <iostream>
	#include "ast.h"
	
	int yyerror(const char *);
	int yylex();
	Node *root;
%}

%union {
	int ival;
	char *sval;
	class Node *pval;
}
%start Prog

%token <ival> NUMBER
%token <sval> STRING

%left ADD SUB
%left MUL DIV 
%token ADD SUB LBR RBR EOL UOP

%type <pval> Exp
%type <pval> Term
%type <pval> Fact
%%
Prog	:	Exp EOL		{ root = $1; root->searchNode(root, 0); exit(0);}
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
	|	STRING		{ $$ = createLeaf($1); }
	;
%%

int yyerror(const char *msg){
	std::cout << "ERROR : " << msg << std::endl;
	return -1;
	}

int main(){
	yyparse();
	return 0;
}

