#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "y.tab.h"

Node *createNode(int type, Node *l, Node *r){
	Node *n = malloc(sizeof(Node));
	
	n->type = type;
	n->l = l;
	n->r = r;
	return n;
}

Node *createUopNode(int type, Node* n){
	Node *u = malloc(sizeof(Node));

	u->type = type;
	u->l = n;
	
	return u;
}

Node *createLeaf(int val){
	Node *n = malloc(sizeof(Node));
	
	n->type = NUMBER;
	n->value = val;

	return n;
}
