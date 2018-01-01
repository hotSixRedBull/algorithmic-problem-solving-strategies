#include<stdio.h>

int road[50 + 3][50 + 3];
int roadCnt[50 + 3];
double cache[50 + 3][100 + 3];

double getProbability(int remainDay, int curVillage, int totalVillage, int targetVillage);

int main() {
	int tc;
	int N, D, P, T, Q;
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d %d %d", &N, &D, &P);

		for (int i = 0; i < N; i++) {
			roadCnt[i] = 0;
			for (int j = 0; j < N; j++) {
				scanf("%d", &road[i][j]);
				cache[i][j] = -1;
				if (road[i][j] == 1) {
					roadCnt[i]++;
				}
			}
		}
		scanf("%d", &T);
		for (int i = 0; i < T; i++) {
			scanf("%d", &Q);
			getProbability(D, Q, N, P);
			printf("%.8lf ", cache[Q][D]);
		}printf("\n");
	}
}

double getProbability(int remainDay, int curVillage, int totalVillage, int jail) {
	if (remainDay == 0) {
		return cache[curVillage][remainDay] = (curVillage == jail ? 1.0 : 0.0);
	}
	if (cache[curVillage][remainDay] > -0.5) {
		return cache[curVillage][remainDay];
	}

	cache[curVillage][remainDay] = 0.0;
	for (int i = 0; i < totalVillage; i++) {
		if (road[curVillage][i]) {
			cache[curVillage][remainDay] += getProbability(remainDay - 1, i, totalVillage, jail) / (double)roadCnt[i];
		}
	}
	return cache[curVillage][remainDay];
}
