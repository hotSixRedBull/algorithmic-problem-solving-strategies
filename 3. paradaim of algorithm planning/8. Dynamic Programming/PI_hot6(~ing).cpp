#include<iostream>
using namespace std;
/*
모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
그 외의 경우 난이도: 10

아.. 망할.. 3자리에서 5자리까지 끊어 읽고 싶습니다.
*/
/*var*/
#define MAXLEN 10000
#define SAME 1
#define ONECHANGE 2
#define ZIGZAG 4
#define SAMEDISTANCE 5
#define OTHER 10
#define INF 987654321
char numbers[MAXLEN];
int numLen, flag[5] = {SAME,ONECHANGE,ZIGZAG,SAMEDISTANCE,OTHER};
/*func*/
void init() {
	numLen = 0;
	while (numbers[numLen] != '\0')
		numLen++;
}
int get_next_number(int flag, int cur,int next) {
	switch (flag) {
	case SAME:
		while (numbers[cur] != numbers[next])
			cur++;
		return cur;
		break;
	case ONECHANGE:
		int diff = numbers[next] - numbers[cur];
		if ((diff==1) || (diff==-1)) {
			while ((diff == 1) || (diff == -1)) {
				next++;
				cur++;
			}
			return next;
		}
		return INF;
		break;
	case ZIGZAG:
		int far1 = cur+2,far2 = next+2;
		if ((numbers[far1] != numbers[cur]) || (numbers[next] != numbers[far2]))
			return INF;
		else {
			while ((numbers[far1] != numbers[cur]) || (numbers[next] != numbers[far2])) {
				cur += 2;
				next += 2;
				far1 += 2;
				far2 += 2;
			}
			if (numbers[far1] == numbers[cur])
				return next;
			if (numbers[far2] == numbers[next])
				return cur;
		}
		break;
	case SAMEDISTANCE:
		int diff = numbers[next] - numbers[cur];
		if (numbers[next + 1] - numbers[next] != diff)
			return INF;
		while (numbers[next+1] - numbers[next] == diff) {
			next++;
			cur++;
			diff = numbers[next] - numbers[cur];
		}
		return next;
		break;
	case OTHER:
		return numLen;
		break;
	}
	return INF;
}
int min_level(int cur) {
	int ret = INF,comp = INF;
	if (cur == -1)
		return INF;
	if (cur+1 == numLen)
		return 0;
	for (int i = 0; i < 5; i++) {
		comp = min_level(get_next_number(flag[i], cur, cur + 1));
		ret = ret > comp ? comp : ret;
	}
	return ret;
}
/*main*/
int main() {
	int test = -1;
	for (int t = 0; t < test; t++) {
		cin >> numbers;
		init();
		cout << min_level(0)<<endl;
	}
	return 0;
}