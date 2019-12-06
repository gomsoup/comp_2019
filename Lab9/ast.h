#include <string>
using namespace std;

class Node{
	public:
	int type;
	int value;
	string svalue;
	Node *l;
	Node *r;

	void searchNode(Node *n, int cnt);
};

Node *createNode(int type, Node *l, Node *r);
Node *creteUopNode(int type, Node *n);
Node *createLeaf(int val);
Node *createLeaf(char *val);
void printBlank(int cnt);
void searchNode();
