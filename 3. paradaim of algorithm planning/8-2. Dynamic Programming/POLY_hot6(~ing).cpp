/*poly*/
#include<iostream>
using namespace std;
/*var*/
#define MAX 100
int map[MAX*2+1][MAX*2+1],siz;
int minW, maxW, minH, maxH;
struct coor {
	int r; int c;
}coor;
/*func*/
bool check() {
	int chk = 0, cross = 0;
	for (int i = minH; i <= maxH; i++) {
		cross = 0;
		for (int j = minW; j <= maxW; j++) {
			if (map[i][j] ^ chk == 1) {
				chk ^= 1;
				cross++;
			}
		}
		if (cross >= 3)
			return false;
	}
	return true;
}
int make_poly(int remain){
	if (remain == 0) {
		print();
		if(check())
			return 1;
		return 0;
	}
	//min,max를 잡아줘야 하고 하나씩 더해줘야 함.
}
void print() {
	for (int i = 0; i < MAX * 2 + 1; i++) {
		for (int j = 0; j < MAX * 2 + 1; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
int get_number_of_poly() {
	minW = minH = MAX * 2 + 1;
	maxW = maxH = 0;

}
/*main*/
int main() {
	int test = -1;
	cin >> test;
	while (test--) {
		cin >> siz;
		//cout<<get_number_of_poly()<<endl;
	}
	return 0;
}
/*
	poly는 다음과 같은 방법으로 구한다.
	맵의 정중앙에 점을 찍는다.
	시계방향으로 위부터 하나를 붙이고, 재귀
	네개 다붙이고 재귀까지.

	그러고 출력해보자.
*/