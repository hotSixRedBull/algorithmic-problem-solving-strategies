#include<iostream>
using namespace std;
/*var*/
#define MAXLEN 101
#define MOD 1000000007
#define MINUS 7
int target;
unsigned long long cache[MAXLEN];
/*func*/
unsigned long long tiling(int s) {
	if (s < 0) return 0;
	unsigned long long& ret = cache[s];
	if (ret != MINUS) return ret;
	return ret = tiling(s - 1) + tiling(s - 2);
}
int asymtiling(int t) {
	if(t%2==1)
		return (tiling(t) - tiling(t / 2))%MOD;
	return (tiling(t) -tiling(t/2) - tiling(t/2 -1) - (t==2))%MOD;
}
void init() {
	for (int i = 0; i < MAXLEN; i++)
		cache[i] = MINUS;
	cache[0] = 0; cache[1] = 1; cache[2] = 2;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	init();
	while (test--) {//민수르님 방식
		cin >> target;
		cout << asymtiling(target) << endl;
	}
	return 0;
}
