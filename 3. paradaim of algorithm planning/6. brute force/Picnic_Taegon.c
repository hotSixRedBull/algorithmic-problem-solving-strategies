#include <stdio.h>

#define	MAX_SIZE	10

typedef enum _boolean { FALSE, TRUE }boolean;

boolean pair[10][10];
boolean valid[10];
int students, pairsize;
int result, cnt;

void init()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++)
			pair[i][j] = FALSE;
		valid[i] = TRUE;
	}
	students = pairsize = 0;
	result = cnt = 0;
}

void setPair(int a, int b, boolean value)
{
	pair[a][b] = pair[b][a] = value;
}
void setValid(int a, int b, boolean value)
{
	valid[a] = valid[b] = value;
}

void getInput()
{
	scanf(" %d %d", &students, &pairsize);

	for (int i = 0; i < pairsize; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);

		setPair(a, b, TRUE);
	}
}

int findNext()
{
	int i;
	for (i = 0; i < students; i++) {
		if (valid[i] == TRUE)
			return i;
	}
	
	return -1;
}

void countPair()
{
	int next = findNext();
	
	if (next == -1) {
		result++;
		return;
	}
	
	for (int i = 0; i < students; i++) {
		if (valid[i] == FALSE)
			continue;
		if (pair[next][i] == TRUE) {
			setPair(next, i, FALSE);
			setValid(next, i, FALSE);
			countPair();
			setPair(next, i, TRUE);
			setValid(next, i, TRUE);
		}
	}
}

int main(int argc, char** argv)
{
	int T, testcase;

	scanf(" %d", &T);

	for (testcase = 1; testcase <= T; testcase++) {
		
		init();
		getInput();

		countPair();

		printf("%d\n", result);
	}

	return 0;
}
