#include <stdio.h>

#define	MAX_COUNT	100
#define	MAX_WEIGHT	1000

char name[MAX_COUNT][21];
int weight[MAX_COUNT];
int value[MAX_COUNT];
int available[MAX_COUNT + 1];
int valid[MAX_WEIGHT + 1][MAX_COUNT];
int objectsize, weightsize;

void init()
{
	for (int i = 0; i < objectsize; i++) {
		for (int j = 0; j < objectsize; j++) {
			valid[i][j] = 0;
		}
		available[i] = 0;
	}
}
void getInput()
{
	scanf("%d %d", &objectsize, &weightsize);
	for(int i = 0; i < objectsize; i++)
		scanf(" %s %d %d", name[i], &weight[i], &value[i]);
}
void getAvailable()
{
	for (int i = 1; i <= weightsize; i++) {
		int max = 0, maxidx = 0;
		int tmp;
		for (int j = 0; j < objectsize; j++) {
			tmp = i - weight[j];
			if (i + weight[j] > weightsize || tmp < 0)
				continue;
			if (valid[tmp][j] == 0 && available[tmp] + weight[j] > max) {
				max = available[tmp] + value[j];
				maxidx = j;
			}
		}
		if (max == 0) {
			available[i] = available[i - 1];
			maxidx = -1;
			for (int j = 0; j < objectsize; j++)
				valid[i][j] = valid[i - 1][j];
		}
		else {
			available[i] = max;
			tmp = i > weight[maxidx] ? i - weight[maxidx] : 0;
			for (int j = 0; j < objectsize; j++)
					valid[i][j] = valid[tmp][j];
			valid[i][maxidx] = 1;
		}
	}
}
void printResult()
{
	int count = 0;
	for (int i = 0; i < weightsize; i++) {
		if (valid[weightsize][i] == 1)
			count++;
	}
	printf("%d %d\n", available[weightsize], count);

	for (int i = 0; i < weightsize; i++) {
		if (valid[weightsize][i] == 1)
			printf("%s\n", name[i]);
	}
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		init();
		getInput();
		getAvailable();
		printResult();
	}
	return 0;
}
