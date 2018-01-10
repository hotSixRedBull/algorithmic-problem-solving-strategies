#include<iostream>
using namespace std;
/*var*/
#define MAXLEN 30
#define MAXNUMBEROF 200
#define MAXCAP 5000
char name[MAXNUMBEROF][MAXLEN];
int cache[MAXNUMBEROF][MAXCAP],p[MAXNUMBEROF],w[MAXNUMBEROF];
int nextChoice[MAXNUMBEROF],nextChoiceVal[MAXNUMBEROF];
int siz, cap, ans;
/*func*/
void init() {
	for (int i = 0; i < siz; i++) {
		nextChoice[i] = -1;
		nextChoiceVal[i] = 0;
		cache[i][0] = p[i];
		for (int j = 1; j <= cap; j++) {
			cache[i][j] = -1;
		}
	}
	nextChoice[siz] = -1;
	nextChoiceVal[siz] = 0;
}
void input() {
	cin >> siz >> cap;
	for (int i = 0; i < siz; i++) {
		cin >> name[i] >> w[i] >> p[i];
	}
	init();
	ans = -1;
}

int run(int start, int remain) {
	if (start == 8 && remain == 2)
		cout << "catch" << endl;
	int* ret = &cache[start][remain],comp=-1;
	if (*ret != -1)
		return *ret;
	for (int i = start + 1; i < siz; i++) {
		if (remain - w[i] >= 0) {
			comp = run(i, remain - w[i]);
			if (*ret < comp) {
				*ret = comp;
				nextChoice[start] = i;
				nextChoiceVal[start] = comp;
			}
		}
	}
	*ret += p[start];
	return *ret;
}
int count(int start) {
	int ind = start, sum = 0, ret = 0;
	ans = 0;
	while (ind != -1 && sum + w[ind] <= cap) {
		sum += w[ind];
		ans += p[ind];
		ind = nextChoice[ind];
		ret++;
	}
	return ret;
}
void output() {
	int ind = 0,cnt=0,comp=0;
	for (int i = 0; i < siz; i++) {
		comp = run(i, cap-w[i]);
		if (comp > ans) {
			ind = i;
			ans = comp;
		}
	}
	init();
	run(ind, cap-w[ind]);
	cnt = count(ind);
	cout << ans <<" "<<cnt<< endl;
	for(int i=0;i<cnt;i++){
		cout << name[ind] << endl;
		ind = nextChoice[ind];
	}
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