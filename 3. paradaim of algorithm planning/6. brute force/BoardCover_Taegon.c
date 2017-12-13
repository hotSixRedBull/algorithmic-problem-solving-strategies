#include <stdio.h>

#define	MAX_SIZE	20

char map[MAX_SIZE][MAX_SIZE];
int H, W;
int result;
int cnt;

int dh1[4] = { 0, 0, 1, 1 };
int dw1[4] = { 1, 1, 0, 0 };
int dh2[4] = { 1, 1, 1, 1 };
int dw2[4] = { 1, 0, 1, -1 };

void init()
{
	int i, j;

	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			map[i][j] = 0;
		}
	}
	H = W = result = cnt = 0;
}
void getInput()
{
	scanf("%d %d", &H, &W);

	int i, j;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '#')
				cnt++;
		}
	}
}
int isValid(int h, int w)
{
	if (0 <= h && h < H && 0 <= w && w < W && map[h][w] == '.')
		return 1;
	else
		return 0;
}

void getCount(int h, int w)
{
	if (cnt == H * W) {
		result++;
		return;
	}

	int i = h,
		j = w;

	while (i < H) {
		int flag = 0;
		while (j < W) {
			if (isValid(i, j)) {
				flag = 1;
				break;
			}
			j++;
		}
		if (flag == 1)
			break;
		i++;
		j = 0;
	}

	int k;
	for (k = 0; k < 4; k++) {
		if (!isValid(i, j))
			continue;
		int tmph1 = i + dh1[k],
			tmpw1 = j + dw1[k],
			tmph2 = i + dh2[k],
			tmpw2 = j + dw2[k];

		if (isValid(tmph1, tmpw1) && isValid(tmph2, tmpw2)) {
			map[tmph1][tmpw1] = '*';
			map[tmph2][tmpw2] = '*';
			map[i][j] = '*';
			cnt += 3;

			if (j + 1 < W) getCount(i, j + 1);
			else if (i + 1 < H) getCount(i + 1, 0);

			cnt -= 3;
			map[tmph1][tmpw1] = '.';
			map[tmph2][tmpw2] = '.';
			map[i][j] = '.';
		}
	}
}

int main(int argc, char** argv)
{
	int testcase, T;
	scanf("%d", &T);

	for (testcase = 1; testcase <= T; testcase++) {
		init();
		getInput();
		if ((H*W - cnt) % 3 > 0) {
			printf("0\n");
			continue;
		}

		getCount(0, 0);

		printf("%d\n", result);
	}

	return 0;
}
