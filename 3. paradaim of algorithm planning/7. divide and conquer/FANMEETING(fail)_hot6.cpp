#include<iostream>
using namespace std;
/*  var  */
#define MAXLEN 200000
char group[MAXLEN], fan[MAXLEN];
int stk[MAXLEN];
int gLen, fLen, top;
int fir = 123456789;

/*  func  */
int get_len(char* str) {
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}
void set_stk() {
	for (int i = 0; i < gLen; i++) {
		if (group[i] == 'M') {
			fir = i;
			break;
		}
	}
	for (int i = 0; i < gLen - fir; i++) {
		if (group[fir + i] == 'M')
			stk[++top] = i;
	}
}
void init() {
	top = -1;
	fir = 0;
	gLen = get_len(group);
	fLen = get_len(fan);
	set_stk();
}
bool is_it_match(int index) {
	for (int i = 0; i <= top; i++) {
		if ((stk[i]+index > fLen)||(fan[stk[i] + index] != 'F'))
			return false;
	}
	return true;
}
int find_match() {
	int ret = 0,start = fir>fLen ? 0 : fir;
	if (top == -1)
		return fLen-gLen+1;
	for (int i = start; i < fLen; i++) {
		if (fan[i] == 'F' && is_it_match(i))
			ret++;
	}
	return ret;
}

/* main func */
int main() {
	int test = -1;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> group;
		cin >> fan;
		init();
		cout << find_match() << endl;
	}
	return 0;
}