#include <stdio.h>

#define MAX_DAY	101
#define	MAX_SIZE	50

int size;
int day;
int map[MAX_SIZE][MAX_SIZE];
int available[MAX_SIZE];
double probability[MAX_SIZE];
double tmp[MAX_SIZE];

void getInput()
{
	int start;
	scanf("%d %d %d", &size, &day, &start);
	for (int i = 0; i < size; i++) {
		int cnt = 0;
		for (int j = 0; j < size; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				cnt++;
		}
		available[i] = cnt;
	}
	for (int i = 0; i < size; i++)
		probability[i] = 0;
	probability[start] = 1;
}
void initTmp()
{
	for (int i = 0; i < size; i++)
		tmp[i] = 0;
}
void getProb()
{
	while (day--) {
		initTmp();
		for (int i = 0; i < size; i++) {
			if (available[i] > 0 && probability[i] > 0) {
				for (int j = 0; j < size; j++) {
					if(map[i][j] > 0)
						tmp[j] += probability[i] / available[i];
				}
			}
		}

		for (int i = 0; i < size; i++)
			probability[i] = tmp[i];
	}
}

void printResult()
{
	int printsize, num;
	scanf("%d", &printsize);
	for (int i = 0; i < printsize; i++) {
		scanf("%d", &num);
		printf("%.8f ", probability[num]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		getInput();
		getProb();
		printResult();
	}
	return 0;
}
