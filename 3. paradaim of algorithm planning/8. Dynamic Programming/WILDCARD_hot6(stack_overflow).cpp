#include<iostream>
using namespace std;
/*vars*/
#define MAXLEN 100
#define MAXNUM 50
char patt[MAXLEN], sen[MAXNUM][MAXLEN];
int pattLen, senLen;

/*func*/
int s_len(char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
bool compare(char* str1, char* str2) {
	//str1이 사전순으로 빠르면 true
	int i = 0;
	for (; i < MAXLEN; i++) {
		if ((str1[i] == '\0') || (str2[i] == '\0'))
			break;
		if (str1[i] > str2[i])
			return false;
	}
	if ((str1[i] != '\0') && (str2[i] == '\0'))
		return false;
	return true;
}
void swap(char* str1, char* str2) {
	char temp[MAXLEN];
	//temp = str1
	for (int i = 0; i < MAXLEN; i++) temp[i] = str1[i];
	//str1 = str2
	for (int i = 0; i < MAXLEN; i++) str1[i] = str2[i];
	//str2 = temp
	for (int i = 0; i < MAXLEN; i++) str2[i] = temp[i];
}
void quick_sort(int l, int r) {
	int left = l, right = r,pivot = (l + r) / 2;
	while (left < right) {
		while (compare(sen[left], sen[pivot]))
			left++;
		while (compare(sen[pivot], sen[right]))
			right--;
		if (left <= right) {
			swap(sen[left], sen[right]);
			left++;
			right--;
		}
	}
	if (left < r)
		quick_sort(left, r);
	if (l < right)
		quick_sort(l, right);
}
bool check(char* str, int senPos, int pattPos) {
	if (pattPos > pattLen && senPos > senLen)
		return true;
	switch (patt[pattPos]) {
	case '?':
		return check(str, senPos + 1, pattPos + 1);
	case '*':
		for (int i = senPos; i < senLen; i++) {
			if (check(str, i, pattPos + 1))
				return true;
		}
		return false;
	default:
		if (patt[pattPos] == str[senPos])
			return check(str, senPos + 1, pattPos + 1);
		return false;
	}
	return false;
}
/*main*/
int main() {
	int test = -1, senSiz = -1;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> patt;
		cin >> senSiz;
		for (int i = 0; i < senSiz; i++) {
			cin >> sen[i];
		}
		quick_sort(0, senSiz-1);//답을 스택에 넣고 정렬하는게 빠름
		/*
		pattLen = s_len(patt);
		for (int i = 0; i < senSiz; i++) {
			senLen = s_len(sen[i]);
			if (check(sen[i], 0, 0))
				cout << sen[i] << endl;
		}
		*/
	}
	return 0;
}