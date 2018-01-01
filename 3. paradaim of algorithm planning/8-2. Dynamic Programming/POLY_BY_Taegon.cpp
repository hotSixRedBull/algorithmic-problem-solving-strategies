#include <stdio.h>

#define SIZE	101
#define MOD	10000000

int num;
long long dp[SIZE][SIZE];	//dp[allSize][remainder]

void makeDP()
{
	for (int i = 1; i < SIZE; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			long long sum = 0;
			for (int k = 0; k < j; k++) {
				sum += dp[j][k] * (i - k - 1);
				sum = sum % MOD;
			}
			dp[i][j] = sum;
		}
	}
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	int testcase;
	scanf("%d", &testcase);

	makeDP();

	while (testcase--) {
		scanf("%d", &num);

		long long sum = 0;
		for (int i = 0; i < num; i++)
			sum = (sum + dp[num][i]) % MOD;
		printf("%lld\n", sum);
	}
	return 0;
}
