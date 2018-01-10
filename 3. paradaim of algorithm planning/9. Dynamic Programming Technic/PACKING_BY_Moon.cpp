#include<stdio.h>
int cache[1000+3][100+3];

int N, W;
int volume[100 + 3], value[100 + 3];
int max, maxCnt;
int result[100 + 3];
char item[100 + 3][21 + 3];


int packing(int idxItem, int remainAmount);
void reconstruct(int remainAmount, int idxItem);
int main() {
	int tc;
	freopen("input.txt", "r", stdin);

	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &N, &W);
		max = -1;
		maxCnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s %d %d", item[i], &volume[i], &value[i]);
		}
		reconstruct(W, 0);
		printf("%d %d\n", packing(0, W), maxCnt);
		for (int i = 0; i < maxCnt; i++) {
			printf("%s\n", item[result[i]]);
		}
		for (int i = 0; i <= W; i++) {
			for (int j = 0; j <= N; j++) {
				cache[i][j] = 0; 
			}
		}
	}

}

int packing(int idxItem, int remainAmount) {
	if (idxItem >= N) {
		return 0;
	}
	if (cache[remainAmount][idxItem] != 0) {
		return cache[remainAmount][idxItem];
	}

	cache[remainAmount][idxItem] = packing(idxItem + 1, remainAmount);

	if (remainAmount - volume[idxItem] >= 0) {
		cache[remainAmount][idxItem] = cache[remainAmount][idxItem] > (value[idxItem] + packing(idxItem+1, remainAmount - volume[idxItem])) ? cache[remainAmount][idxItem] : (value[idxItem] + packing(idxItem+1, remainAmount - volume[idxItem]));
	}

	return cache[remainAmount][idxItem];
}

void reconstruct(int remainAmount, int idxItem) {
	if (idxItem >= N) {
		return;
	}
	if (packing(idxItem, remainAmount) == packing(idxItem + 1, remainAmount)) {
		reconstruct(remainAmount, idxItem + 1);
	} else {
		result[maxCnt++] = idxItem;
		reconstruct(remainAmount - volume[idxItem], idxItem + 1);
	}
}
