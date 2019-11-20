#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "y.tab.h"

Node *createNode(int type, Node *l, Node *r){
	Node *n = malloc(sizeof(Node));
	
	n->type = type;
	n->l = l;
	
	if(type != UOP)
		n->r = r;
	return n;
}

Node *createUopNode(Node* n){
	Node *u = malloc(sizeof(Node));

	u->type = UOP;
	u->l = n;
	
	return u;
}

Node *createLeaf(int val){
	Node *n = malloc(sizeof(Node));
	
	n->type = NUMBER;
	n->value = val;

	return n;
}

void printBlank(int cnt){
	for(int i = 0; i < cnt; i++)
		printf("  ");
}

void searchNode(Node *n, int cnt){
	if(n->type == ADD){
		printBlank(cnt);
		printf("Op(+)\n");
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->l->value);
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->r->value);
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == SUB){
		printBlank(cnt);
		printf("Op(-)\n");
	
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->l->value);
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->r->value);
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == MUL){
		printBlank(cnt);
		printf("Op(*)\n");
	
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->l->value);
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->r->value);
		}
		
		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == DIV){
		printBlank(cnt);
		printf("Op(/)\n");
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->l->value);
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->r->value);
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == UOP){
		printBlank(cnt);
		printf("Uop(-)\n");

		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			printf("Int(%d)\n", n->l->value);
		}

		searchNode(n->l, cnt+1);
	}
}
