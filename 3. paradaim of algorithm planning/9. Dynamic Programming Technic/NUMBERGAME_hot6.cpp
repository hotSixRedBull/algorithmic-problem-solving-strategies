#include<iostream>
using namespace std;
/*var*/
#define MAXLEN 50
#define MINUS -99999999
int cache[MAXLEN][MAXLEN],inp[MAXLEN];
int siz;
/*func*/
void input() {
	cin >> siz;
	for (int i = 0; i < siz; i++) {
		cin >> inp[i];
		for (int j = 0; j < siz; j++) {
			cache[i][j] = MINUS;
		}
	}
}
int max2(int a, int b) {
	return a > b ? a : b;
}
int get_max(int i, int j) {
	if (i > j) return 0;
	int& ret = cache[i][j];
	if (ret != MINUS)
		return ret;
	ret = max2(inp[i] - get_max(i + 1, j), inp[j] - get_max(i, j - 1));
	if (j - i + 1 < 2)
		return ret;
	ret = max2(ret, -get_max(i + 2, j));
	ret = max2(ret, -get_max(i, j - 2));
	return ret;
}
void output() {
	cout << get_max(0, siz - 1) << endl;
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

/*
	기존 코드
	max4(왼쪽먹기,오른쪽먹기,왼쪽없애기,오른쪽없애기)
*/