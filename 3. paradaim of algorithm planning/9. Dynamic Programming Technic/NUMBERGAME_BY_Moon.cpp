#define max(A,B) (A)>(B)?(A):(B);
#include<stdio.h>

int number[50 + 3];
int cache[50 + 3][50 + 3];


int numberGame(int left, int right);


int main() {
	int tc;
	int n = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				cache[i][j] = 0;
			}
		}

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &number[i]);
		}
		printf("%d\n", numberGame(0, n - 1));

	}

}
int numberGame(int left, int right) {
	if (left > right) {
		return 0;
	}

	if (cache[left][right] != 0) {
		return cache[left][right];
	}
	cache[left][right] = max(number[left] - numberGame(left + 1, right), number[right] - numberGame(left, right - 1));

	if (right - left + 1 >= 2) {
		cache[left][right] = max(cache[left][right], -numberGame(left + 2, right));
		cache[left][right] = max(cache[left][right], -numberGame(left, right - 2));
	}

	return cache[left][right];
}

