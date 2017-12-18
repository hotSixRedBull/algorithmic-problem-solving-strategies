#include <iostream>
using namespace std;
#define INF 987654321
int clocks[16];
const int btn[10][16] = {
	{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 },
	{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 },
	{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 },
};

/*
	안누르거나, 한번~3번 누르거나
	재귀로.
*/
void push(int btnid, int num) {
	for (int i = 0; i<16; i++) {
		if (btn[btnid][i] == 1) {
			clocks[i] += num * 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
			if (clocks[i] == 0)
				clocks[i] = 12;
		}
	}
}
int minimum_push(int btnid,int dep,int cnt) {
	int ret = INF,comp;
	if (btnid == dep) {
		for(int i=0;i<16;i++)
			if (clocks[i] != 12) {
				return INF;
			}
		return cnt;
	}
	for (int i = 0; i < 4; i++) {//push
		for (int j = 0; j < i; j++)
			push(btnid, 1);
		comp = minimum_push(btnid + 1, dep, cnt + i);
		ret = ret < comp ? ret : comp;
		for (int j = 0; j < i; j++)
			push(btnid, -1);
	}
	return ret;
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t<test; t++) {
		for (int c = 0; c<16; c++) {
			cin >> clocks[c];
		}
		int ret = minimum_push(0, 10, 0);
		if (ret == INF)
			ret = -1;
		cout << ret << endl;
	}

	return 0;
}