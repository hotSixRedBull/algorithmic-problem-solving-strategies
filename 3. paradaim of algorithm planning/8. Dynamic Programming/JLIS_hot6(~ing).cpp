#include<iostream>
using namespace std;
/*var*/
#define MAXLEN 100
int fir[MAXLEN], sec[MAXLEN];
int firLen, secLen;
/*func*/
int get_max_len(int firPos, int secPos) {
	//fir과 sec가 각각의 위치에서부터 만들 수 있는 최고의 LIS
	int max = -1;

	return max;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> firLen >> secLen;
		for (int i = 0; i < firLen; i++)
			cin >> fir[i];
		for (int i = 0; i < secLen; i++)
			cin >> sec[i];
		int max = -1;
		for (int i = 0; i < firLen; i++) {
			for (int j = 0; j < secLen; j++) {
				int comp = get_max_len(i, j);
				max = max > comp ? max : comp;
			}
		}
		cout << max <<endl;
	}
	return 0;
}