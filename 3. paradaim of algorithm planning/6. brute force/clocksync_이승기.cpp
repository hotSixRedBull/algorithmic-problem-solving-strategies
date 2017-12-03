#include <iostream>
using namespace std;
#define INF 987654321
int clocks[16];
void push(int id, int num);
int pi_permu(int* q, int size, int dep, int cur, int currentClock);
int make_twelve(int currentClock);

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
};//btn[i번][i번째 시계] 연결되어있는지..
  //아래에서 올라오느냐, 위에서 내려가느냐..
  //12시가 아니라면 12시로 만들기 위한 모든 경우의 수 별로 파고들어간다.
void push(int id, int num) {
	for (int i = 0; i<16; i++) {
		if (btn[id][i] == 1)
			clocks[i] = (clocks[i]%12 + 3 * num); //두번째 실수
	}
}
int pi_permu(int* q, int size, int dep, int cur, int currentClock) {
	int ret = INF, comp = 0;
	if (dep == 0) {
		return make_twelve(currentClock + 1);
	}
	for (int i = cur; i<size; i++) {
		push(q[i], 1);
		comp = pi_permu(q, size, dep - 1, i,currentClock);
		ret = ret > comp ? comp : ret;
		push(q[i], -1);
	}
	return ret;//세번째 수정.
}

int make_twelve(int currentClock) {
	int q[10], size = 0;
	if (currentClock == 15){
		if (clocks[currentClock] == 12) 
			return 1;
		else
			return -1;
	}

	if (currentClock != 15 && clocks[currentClock] == 12)
		return make_twelve(currentClock + 1);

	for (int i = 0; i<10; i++) {
		bool frontchanging = false;//앞에 것이 바뀌는지. 1번째 실수.
		if (btn[i][currentClock] == 1) {
			for (int j = 0; j < currentClock; j++) {
				if (btn[i][j] == 1) {
					frontchanging = true;
					break;
				}
			}
			if (!frontchanging)
				q[size++] = i;
		}
	}

	//q를 가지고 경우의 수를 만들어야함	
	//만약 버튼이 5개고 3번만 눌러야 한다면
	//111,112,113,114,115,123,124,125,134,135...
	//size 만큼의 중복순열
	pi_permu(q, size,4-(clocks[currentClock]/3), 0, currentClock);

	return size;
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t<test; t++) {
		for (int c = 0; c<16; c++) {
			cin >> clocks[c];
		}
		if (clocks[14] != clocks[15])
			cout << -1 << endl;
		else {
			cout << make_twelve(0) << endl;
		}
	}

	return 0;
}