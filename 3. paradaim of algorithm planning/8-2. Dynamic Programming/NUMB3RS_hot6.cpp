/*numb3rs*/
#include<iostream>
using namespace std;
/*var*/
#define MAXVILLAGE 50
#define MAXDAYS 100
int siz, days, prison,targetSiz;
int adj[MAXVILLAGE][MAXVILLAGE], target[MAXVILLAGE];
float prob[MAXVILLAGE][MAXDAYS], sumAdj[MAXVILLAGE];
/*func*/
void input() {
	cin >> siz >> days >> prison;
	for (int i = 0; i < siz; i++) {
		for (int j = 0; j < siz; j++)
			cin >> adj[i][j];
	}
	cin >> targetSiz;
	for (int i = 0; i < targetSiz; i++)
		cin >> target[i];
}
void init() {
	int sum = 0;
	for (int i = 0; i < siz; i++) {
		sum = 0;
		for (int j = 0; j < siz; j++) {
			if (adj[i][j] == 1)
				sum++;
			prob[i][j] = 0;
		}
		sumAdj[i] = sum;
	}
	prob[prison][0] = 1;
}
void run() {
	for (int c = 1; c <= days; c++) {
		for (int r = 0; r < siz; r++) {
			for(int i=0;i<siz;i++)//인접을 찾을때 리스트로 구현하면 ㅈㄴ빠를듯.
				if(adj[i][r]==1)
					prob[r][c] += prob[i][c-1] / sumAdj[i];
		}
	}
}
void output() {
	/*
	각 테스트 케이스마다 t 개의 실수로 각 마을에 두니발 박사가 숨어 있을 확률을 출력합니다. 
	10-7 이하의 절대/상대 오차가 있는 경우 정답으로 처리됩니다.
	*/
	cout.setf(ios::fixed);
	cout.precision(10);
	for (int i = 0; i < targetSiz; i++) {
		cout << prob[target[i]][days];
		if(i!=targetSiz-1)
			cout << " ";
	}
	cout << endl;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	while (test--) {
		input();
		init();
		run();
		output();
	}
	return 0;
}