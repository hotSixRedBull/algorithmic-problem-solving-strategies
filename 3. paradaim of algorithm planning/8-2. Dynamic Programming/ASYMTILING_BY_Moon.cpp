#include<stdio.h>

int cache[101 + 3];
int mod = 1000000007;

int asymTiling(int len);
int tiling(int len);
int main() {
	int tc;
	int len = 0;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < len + 1; i++) {
			cache[i] = 0;
		}
		scanf("%d", &len);
		printf("%d\n", asymTiling(len));
	}

}
int asymTiling(int len) {
	if (len % 2 == 0) {
		return ((tiling(len) - tiling(len / 2) + mod) % mod - tiling(len / 2 - 1) + mod - (((len / 2 - 1) == 0) ? 1 : 0)) % mod;
	}
	else {
		return (tiling(len) - tiling(len / 2) + mod - (((len / 2) == 0) ? 1 : 0)) % mod;
	}


}

int tiling(int len) {

	if (cache[len] != 0) {
		return cache[len];
	}

	if (len <= 2) {
		return cache[len] = len;
	}

	return cache[len] = (tiling(len - 1) % mod + tiling(len - 2) % mod) % mod;

}

