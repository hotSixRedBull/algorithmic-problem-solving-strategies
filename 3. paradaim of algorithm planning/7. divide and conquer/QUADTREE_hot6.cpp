#include<iostream>
using namespace std;
#define MAXLEN 1000
char str[MAXLEN];
int len,p;
class node {
public:
	char val;
	node* child[4];
	node(char v) {
		val = v;
	}
};

node* root;
void getLen() {
	len = 0;
	while (str[len] != '\0')
		len++;
}

void initialize() {
	p = 0;
	root = new node(str[0]);
	getLen();
}


void parse(int* pos,node* cur) {
	cur->val = str[*pos];
	(*pos)++;
	if (*pos < len) {
		for (int i = 0; i < 4; i++) {
			if (str[*pos] == 'x') {
				cur->child[i] = new node(str[*pos]);
				parse(pos, cur->child[i]);
				(*pos)--;
			}
			else {
				cur->child[i] = new node(str[*pos]);
			}
			(*pos)++;
		}
	}
	return;
}
void print(node* c) {
	node* cur = c;
	cout << cur->val;
	if (cur->val == 'x') {
		print(c->child[2]);
		print(c->child[3]);
		print(c->child[0]);
		print(c->child[1]);
	}
}
int main() {
	int test = 0;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> str;
		initialize();
		getLen();
		parse(&p,root);
		print(root);
		cout << endl;
	}
	return 0;
}