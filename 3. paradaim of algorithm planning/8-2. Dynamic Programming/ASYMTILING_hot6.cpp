#include<iostream>
using namespace std;   
/*var*/
#define MAX 101
#define MOD 1000000007
int siz;
unsigned long long cache[MAX][2];
/*func*/
unsigned long long tiling(int size) {
	unsigned long long& ret = cache[size][1];
	if (ret != 7)return ret;
	ret = tiling(size - 1) + tiling(size - 2);
	cache[size][0] = cache[size - 1][0] + cache[size - 2][0] + ret/MOD;
	return ret %= MOD;
}
int asym() {
	unsigned long long a = tiling(siz), b = tiling(siz/2),
		c = siz%2==1?0:tiling(siz/2-1),d=(siz==2);
	if ((siz % 2 == 1) && cache[siz][0] - cache[siz / 2][0] > 0 && (a < b)) {
		a += MOD - b;
		b = 0;
	}
	if ((siz % 2 == 0) && cache[siz][0] - cache[siz / 2][0] - cache[siz / 2 - 1][0] > 0 &&(a < (b+c))) {
		if (cache[siz][0] - cache[siz / 2][0] - cache[siz / 2 - 1][0] == 1) {
			a += MOD - b - c;
		}
		else {
			a += MOD * 2 - b - c;
		}
		b = 0;
		c = 0;
	}
	return (a -b -c -d)%MOD;
}
void init() {
	cache[0][1] = 0;
	cache[1][1] = 1;
	cache[2][1] = 2;
	for (int i = 3; i < MAX; i++) {
		cache[i][1] = 7;
	}
	for (int i = 0; i < MAX; i++)
		cache[i][0] = 0;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	init();
	for (int t = 0; t < test; t++) {
		cin >> siz;
		cout << asym()<<endl;
	}
	return 0;
}