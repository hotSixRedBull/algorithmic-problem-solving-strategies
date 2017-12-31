#include <stdio.h>

int arr[2][101];
int main() {
	int N, T,res;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		arr[0][0] = arr[1][0] = 0;
		arr[0][1] = arr[1][1] = arr[1][3] = 1;
		arr[0][2] = arr[1][2] = 2;
		arr[0][3] = arr[1][4] = 3;
		arr[0][4] = 5;
		for (int i = 5; i <= N; ++i) {
			arr[0][i] = (arr[0][i - 1] + arr[0][i - 2]) % 1000000007;
			arr[1][i] = (arr[1][i - 2] + arr[1][i - 4]) % 1000000007;
		}
		res = arr[0][N] - arr[1][N];
		if (res < 0) res += 1000000007;
		printf("%d\n", res);
	}
}
