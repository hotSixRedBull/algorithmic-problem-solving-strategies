#include <iostream>
using namespace std;
/*var*/
#define MAX 20002
int stk[MAX], top;
int inp[MAX], siz;
int ret;
/*func*/
void init() {
	for (int i = 0; i <= siz; i++)
		stk[i] = -1;
	top = -1;
	ret = -1;
}
void input() {
	cin >> siz;
	for (int i = 0; i<siz; i++)
		cin >> inp[i];
	init();
}
void output() {
	int comp;
	for (int cur = 0; cur<siz; cur++) {
		stk[++top] = cur;
		ret = ret < inp[stk[top]] ? inp[stk[top]] : ret;
		for (int j = 0; j <= top; j++) {
			if (j == top&&top>0) {
				comp = (stk[top] - stk[j - 1])*inp[stk[j]];
			}
			else {
				comp = (stk[top] - stk[j] + 1)*inp[stk[j]];
			}
			ret = ret < comp ? comp : ret;
		}
		while (top != -1 && inp[stk[top]]>inp[cur + 1])
			top--;
		if (top == -1)
			continue;
	}
	cout << ret << endl;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	while (test--) {
		input();
		output();
	}
	return 0;
}