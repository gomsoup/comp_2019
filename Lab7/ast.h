typedef struct _Node{
	int type;
	int value;
	struct _Node *l;
	struct _Node *r;
} Node;

Node *createNode(int type, Node *l, Node *r);
Node *creteUopNode(int type, Node *n);
Node *createLeaf(int val);
