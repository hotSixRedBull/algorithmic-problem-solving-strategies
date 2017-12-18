#include <iostream>
using namespace std;
#define MAXSIZE 20
int test, h, w, ret;
char map[MAXSIZE][MAXSIZE];
//좌 상단부터 차곡차곡 채워나갈 경우, L의 경우의 수는 4개다.
int l_sec_x[4] = { 1,0,0,1 }, l_sec_y[4] = { 0,1,1,0 };
int l_tir_x[4] = { 1,1,1,1 }, l_tir_y[4] = { -1,0,1,1 };
/*
	ㅂㅁ  ㅂ      ㅂ  ㅂㅁ  
	ㅁ    ㅁㅁ  ㅁㅁ    ㅁ
*/
//모양찾기는 늘 어렵군...
bool can_place(int id, int x, int y) {
	if (((x>=0)&&(x<h)&&(y>=0)&&(y<w))
		&& ((x + l_sec_x[id] >= 0) && (x + l_sec_x[id]<h) && (y + l_sec_y[id] >= 0) && (y + l_sec_y[id]<w))
		&& ((x + l_tir_x[id] >= 0) && (x + l_tir_x[id]<h) && (y + l_tir_y[id] >= 0) && (y + l_tir_y[id]<w))
		&& (map[x + l_sec_x[id]][y + l_sec_y[id]] == '.')
		&& (map[x + l_tir_x[id]][y + l_tir_y[id]] == '.')
		&& (map[x][y]=='.')) {
		return true;
	}
	return false;
}
void draw(int id, char c, int x, int y) {
	map[x][y] = c;
	map[x+l_sec_x[id]][y+l_sec_y[id]] = c;
	map[x+l_tir_x[id]][y+l_tir_y[id]] = c;
}
void initialize() {
	ret = 0;
}

int check() {
	bool full = true, fitBlockExist = false;
	for (int r=0; r<h; r++) {
		for (int c=0; c<w; c++) {
			if (map[r][c] == '.' && !fitBlockExist) {
				full = false;
				for (int i = 0; i<4; i++) {
					if (can_place(i, r, c) == true) {
						fitBlockExist = true;
						draw(i, 'x', r, c);
						check();
						draw(i, '.', r, c);
					}
				}
			}
		}
	}
	if (full) {
		ret++;
		return ret;
	}
	else if (!full && !fitBlockExist)
		return 0;
	else
		return ret;
}

int main() {
	cin >> test;
	for (int t = 0; t<test; t++) {
		cin >> h >> w;
		initialize();
		for (int i = 0; i<h; i++) {
			cin >> map[i];
		}
		cout << check() << endl;
	}
	return 0;
}