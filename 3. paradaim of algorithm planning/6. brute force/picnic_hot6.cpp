#include <iostream>
using namespace std;
#define MAXRELATION 55
#define MAXSTUDENT 10
int friends[MAXRELATION][2];
int used[MAXSTUDENT];
int sunyul[MAXSTUDENT]; //array로 했다 에러남.
int dupl[MAXSTUDENT][MAXSTUDENT];

int check(int studentSize, int curDepth, int relationSize, int* arr, int* used) { //int* ans 추가
	int ret = 0;
	if (studentSize == curDepth) {
		return 1;
	}
	else {
		for (int i = 0; i<studentSize; i++) {
			if (used[i] == 0) {
				arr[curDepth] = i;
				used[i] = 1;
				for (int j = 0; j < relationSize; j++) {
					if (friends[j][0] == i) {
						if (used[friends[j][1]] == 0) {
							arr[curDepth + 1] = friends[j][1];
							used[friends[j][1]] = 1;
							ret += check(studentSize, curDepth + 2, relationSize, arr, used);
							used[friends[j][1]] = 0;
						}
					}
				}
				used[i] = 0;
			}
		}
		return ret;
	}
}

int main() {
	int test, n, m;
	cin >> test;
	for (int t = 0; t<test; t++) {
		cin >> n >> m;
		for (int i = 0; i<n; i++) {
			used[i] = 0;
			sunyul[i] = 0;
			for (int j = 0; j < n; j++) {
				dupl[i][j] = 0;
			}
		}
		for (int i = 0; i<m; i++) //적이 아니라 친구를 주는거였음..개소름.
			cin >> friends[i][0] >> friends[i][1];
		int div = 1;//중복제거
		for (int f = n / 2; f > 1; f--)
			div *= f;
		cout << check(n, 0, m, sunyul, used)/div << endl;
	}
	return 0;
}