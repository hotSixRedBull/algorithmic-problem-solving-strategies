/*sushi*/
#include<iostream>
using namespace std;
/*var*/
#define MAXSIZ 100
#define X 0
#define Y 1
float camp[MAXSIZ][2];
int par[MAXSIZ];
int campSiz;
/*func*/
void input() {
	cin >> campSiz;
	for (int i = 0; i < campSiz; i++) {
		cin >> camp[i][X] >> camp[i][Y];
	}
}
//최소스패닝트리 문제 같은 데...
//tree? heap? 
void init() {
	for (int r = 0; r < MAXSIZ; r++) {
		par[r] = r;
	}
}
float sg_square(float a) {
	return a*a;
}
int parentOf(int nodeNum) {
	int ret = nodeNum, compared=1000000;
	if(par[nodeNum] != nodeNum)
		compared = parentOf(par[nodeNum]);
	ret = ret < compared ? ret : compared;
	return ret;
}
bool decision(float radioDistance) {//아래가 존재하느냐
	if (radioDistance == 15.625)
	{
		cout << "test" << endl;
	}
	init();
	for (int i = 0; i < campSiz; i++) {
		for (int j = i+1; j < campSiz; j++) {
			if (sg_square(camp[i][X]-camp[j][X])+sg_square(camp[i][Y]-camp[j][Y])<sg_square(radioDistance)) {
				//i랑 j를 연결 해야함
				par[j] = parentOf(i);
				break;
			}
			else if(j==campSiz-1) {
				return false;
			}
		}
	}
	//모든 노드가 연결되었는 지 확인해야함.
	int root = parentOf(0);
	for (int i = 1; i < campSiz; i++) {
		if (parentOf(i) != root)
			return false;
	}
	return true;
}
float run() {
	float low = 0,high = 2000,mid=1000;
	for (int i = 0; i < 100; i++) {
		if (decision(mid)) {//low~mid 조사해야함
			high = mid;
		}
		else {//mid~high 조사해야함
			low = mid;
		}
		mid = (low + high) / 2;
	}
	return mid;
}
void output() {
	cout << run() << endl;
}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	while (test--) {
		init();
		input();
		output();
	}
	return 0;
}