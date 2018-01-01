#include <stdio.h>

#define	SIZE	100
#define	MOD		1000000007

int num;
long long dp[SIZE + 1];

void getDp()
{
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= SIZE; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1])%MOD;
	}
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	getDp();

	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d", &num);

		long long tmp = dp[num];
		tmp = (tmp - dp[num / 2] + MOD) % MOD;
		if (num % 2 == 0)
			tmp = (tmp - dp[(num / 2) - 1] + MOD) % MOD;

		printf("%d\n", tmp);
	}

	return 0;
}
