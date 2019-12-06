#include <iostream>
#include <cstdio>
#include "ast.h"
#include "y.tab.h"

using namespace std;

void Node::searchNode(Node *n, int cnt){
	if(n->type == ADD){ 
		printBlank(cnt);
		cout << "Op(+)" << endl;
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->l->value << ")" << endl;
		}
		else if (n->l && n->l->type ==STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->l->svalue << ")" << endl;
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->r->value << ")" << endl;
		}
		else if (n->r && n->r->type == STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->r->svalue << ")" << endl;
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == SUB){ //SUB
		printBlank(cnt);
		cout << "Op(-)" << endl;
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->l->value << ")" << endl;
		}
		else if (n->l && n->l->type ==STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->l->svalue << ")" << endl;
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->r->value << ")" << endl;
		}
		else if (n->r && n->r->type == STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->r->svalue << ")" << endl;
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == MUL){ // MUL
		printBlank(cnt);
		cout << "Op(*)" << endl;
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->l->value << ")" << endl;
		}
		else if (n->l && n->l->type ==STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->l->svalue << ")" << endl;
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->r->value << ")" << endl;
		}
		else if (n->r && n->r->type == STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->r->svalue << ")" << endl;
		}
		
		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == DIV) { //div
		printBlank(cnt);
		cout << "Op(/)" << endl;
		
		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->l->value << ")" << endl;
		}
		else if (n->l && n->l->type ==STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->l->svalue << ")" << endl;
		}
		if (n->r && n->r->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->r->value << ")" << endl;
		}
		else if (n->r && n->r->type == STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->r->svalue << ")" << endl;
		}

		searchNode(n->l, cnt+1);
		searchNode(n->r, cnt+1);
	}
	else if(n->type == UOP){ //uop
		printBlank(cnt);
		cout << "Uop(-)" << endl;

		if(n->l && n->l->type == NUMBER){
			printBlank(cnt+1);
			cout << "Int(" << n->l->value << ")" << endl;
		}
		else if (n->l && n->l->type == STRING){
			printBlank(cnt+1);
			cout << "Id(" << n->l->svalue << ")" << endl;
		}
		searchNode(n->l, cnt+1);
	}


}

Node* createNode(int type, Node *l, Node *r){
	Node *n = new Node;

	n->type = type;
	n->l = l;

	if(type != 267)
		n->r = r;

	return n;
}

Node *createUopNode(Node *n){
	Node *u = new Node;

	n->type = 267;
	n->l = n;

	return u;
}

Node *createLeaf(int val){
	Node *n = new Node;
	
	n->type = 258;
	n->value = val;

	return n;
}

Node *createLeaf(char *val){
	Node *n = new Node;
	
	n->type = STRING;
	n->svalue = val;

	return n;
}


void printBlank(int cnt){
	for(int i = 0; i < cnt; i++)
		cout << "  ";
}


