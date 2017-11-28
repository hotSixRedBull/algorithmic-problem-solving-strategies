#include <iostream>
using namespace std;

typedef struct node {
	int val;
	node* next;
}node;

class linkedlist {
public:
	node* head;
	node* tail;
	int size;
	linkedlist() {
		size = 0;
	}
	void insert(int val) {
		if (size == 0) {
			head = new node();
			head->val = val;
			head->next = NULL;
			tail = head;
		}
		else {
			if (head == tail) { //first mistake. case misconception
				node* n = new node(); //second mistake. giving a memory to local value like "node n"
				n->val = val;
				n->next = NULL;
				head->next = n;
				tail = n;
			}
			else {
				node* n = new node();
				n->val = val;
				n->next = NULL;
				tail->next = n;
				tail = n;
			}
		}
		size++;
	}
	node* get(int ind) {
		if (size == 0)
			return NULL;
		else {
			node* cur = head;
			for (int i = 0; i<ind; i++) {
				cur = cur->next;
			}
			return cur;
		}
	}
	void delByIndex(int ind) {
		if (size<ind)
			return ;
		else {
			size--;
			if (ind == 0) {
				head = head->next;
			}
			else {
				node* parent = head;
				for (int i = 1; i<ind; i++) {
					parent = parent->next;
				}
				parent->next = parent->next->next;
			}

		}
	}
	void delByVal(int val) {
		if (size == 0) {
			return;
		}
		else {
			if (val == head->val) {
				head = head->next;
			}
			else {
				node* parent = head;
				while (parent->next != tail) {
					if (parent->next->val == val) {
						parent->next = parent->next->next;
						size--;
						return ;
					}
					//third mistake. missing incremental sentence
					parent = parent->next;
				}
				return ;
			}

		}
	}
};

linkedlist list;
void test(int size);

int main() {
	test(10);
	return 0;
}

void test(int size) {
	//insert test
	for (int i = 0; i<size; i++) {
		int randVal = rand();
		list.insert(randVal);
		cout << "[" << i << "] : " << randVal << endl;
	}

	for (int i = 0; i<size; i++) {
		cout << "[" << i << "] : " << list.get(i)->val << endl;
	}

	//delete test1
	int fir = rand() % size, sec = rand() % (size - 1);
	cout << "delete by index : " << fir << endl;
	list.delByIndex(fir);

	for (int i = 0; i<list.size; i++) {
		cout << "[" << i << "] : " << list.get(i)->val << endl;
	}

	//delete test2
	cout << "delete by val : " << list.get(sec)->val << endl;
	list.delByVal(list.get(sec)->val);

	for (int i = 0; i<list.size; i++) {
		cout << "[" << i << "] : " << list.get(i)->val << endl;
	}
}