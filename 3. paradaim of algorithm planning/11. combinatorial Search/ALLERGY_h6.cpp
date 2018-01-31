/*sushi*/
#include<iostream>
using namespace std;
/*var*/
#define MAXSIZ 50
#define MAXLEN 10
int sizOfName,sizOfRel,best;
int canEat[MAXSIZ][MAXSIZ], eaters[MAXSIZ][MAXSIZ],edible[MAXSIZ];
char names[MAXSIZ][MAXLEN];
/*func*/
int sg_strlen(char* s) {
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}
bool sg_strcmp(char* s1, char* s2) {
	int l1 = sg_strlen(s1), l2 = sg_strlen(s2);
	if (l1 != l2)
		return false;
	for (int i = 0; i < l1; i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}
int get_index(char* str) {
	for (int i = 0; i < sizOfName; i++) {
		if (sg_strcmp(names[i], str))
			return i;
	}
}
void push(int i, char* str) {
	int ind = get_index(str);
	canEat[ind][i] = 1;
	eaters[i][ind] = 1;
}
void input() {
	int cnt;
	char name[MAXLEN];
	cin >> sizOfName >> sizOfRel;
	for (int n = 0; n < sizOfName; n++) {
			cin >> names[n];
	}
	for (int r = 0; r < sizOfRel; r++) {
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			cin >> name;
			push(r, name);
		}
	}
}
void init() {
	for (int r = 0; r < MAXSIZ; r++) {
		for (int c = 0; c < MAXSIZ; c++) {
			canEat[r][c] = 0;
			eaters[r][c] = 0;
		}
		edible[r] = 0;
	}
}
void search(int chosen) {
	if (chosen >= best)
		return;
	int first = 0;
	while (first < sizOfName && edible[first]>0) 
		++first;
	if (first == sizOfName) {
		if(best>chosen)
			best = chosen;
		return;
	}
	for (int i = 0; i < MAXSIZ; i++) {
		if (canEat[first][i] == 1) {
			for (int j = 0; j < MAXSIZ; j++) {
				if(eaters[i][j]==1)
					edible[j]++;
			}
			search(chosen + 1);
			for (int j = 0; j < MAXSIZ; j++) {
				if (eaters[i][j] == 1)
					edible[j]--;
			}
		}
	}
}
void output() {
	best = sizOfName;
	search(0);
	cout << best << endl;
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