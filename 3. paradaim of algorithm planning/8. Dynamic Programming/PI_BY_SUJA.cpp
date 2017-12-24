#include <stdio.h>

/*
* Problem :: PI
*
* Summary
*	Input :: 8글자 이상 10000글자 이하의 숫자
*	Output :: 주어진 숫자를 3~5개의 간격으로 잘라서 만들 수 있는 수열의 난이도 합 중 최소
*
* Solving :: 
*	1. 입력 받은 숫자의 길이가 주어져 있지 않기 때문에 String형태로 입력 받아서 int 배열에 저장
*	2. 주어진 규칙을 보면 난이도를 결정하는 규칙이 전부 등차 수열임 (ex. 1의 난이도의 경우 등차의 값이 0, 2의 난이도의 경우는 등차의 절대값이 1.. 따라서 각 자리숫자별로 차이 값을 저장. 단, 4와 10의 난이도의 경우는 조금 특이함(예외처리)
*	3. Dynamic Programming은 2차원배열로 생성[몇개를 자를 것인지(3~5)][몇번째 숫자인지(8~10000)], DP Table의 값을 채우는데 이때 Table에 들어가는 값은 j번째 숫자를 기준으로 앞의 i번째까지 잘랐을 때 만들 수 있는 최소 난이도의 합
*	## DP[0][i] = DP[0][i-3],DP[1][i-3],DP[2][i-3]중 최소 값 + i, i-1, i-2의 수열의 난이도
*	## DP[1][i] = DP[0][i-4],DP[1][i-4],DP[2][i-4]중 최소 값 + i, i-1, i-2, i-3의 수열의 난이도
*	## DP[2][i] = DP[0][i-5],DP[1][i-5],DP[2][i-5]중 최소 값 + i, i-1, i-2, i-3, i-4의 수열의 난이도
*	4. 결국 최종 답은 DP Table의 마지막 행의 값들 중 최소 값에 해당됨.
*/


int dp[3][10001],num[10001],dist[10001];

void Init(){ for(int i=1;i<=10000;++i) dp[0][i] = dp[1][i] = dp[2][i] = 9999999; }

int Grade(int idx,int cut){ 
	bool chk=true;
	for(int i=1;i<cut-1;++i){
		if(dist[idx]!=dist[idx-i]){chk = false;break;}
	}
	if(chk){
		if(dist[idx]==0) return 1;
		if(dist[idx]==1||dist[idx]==-1) return 2;
		return 5;
	}else{
		chk = true;
		int prev = dist[idx];
		for(int i=1;i<cut-1;++i){
			if(dist[idx-i]!=-prev) {chk=false;break;}
			prev = dist[idx-i];
		}
		if(chk) return 4;
		return 10;
	}
}

int Min(int a, int b){return (a<b)?a:b;}

int main(){
	freopen("test.txt","r",stdin);
	int T,len;
	char str[10001];
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		Init();
		scanf("%s",&str);
		for(len=0;str[len]!='\0';++len) {
			num[len] = str[len]-'0';
			if(len!=0) dist[len] = num[len]-num[len-1];
		}
		for(int i=1;i<=len;++i){ 
			if(i-3>=0) dp[0][i] = Min(Min(dp[0][i-3],Min(dp[1][i-3],dp[2][i-3]))+Grade(i-1,3),9999999);
			if(i-4>=0) dp[1][i] = Min(Min(dp[0][i-4],Min(dp[1][i-4],dp[2][i-4]))+Grade(i-1,4),9999999);
			if(i-5>=0) dp[2][i] = Min(Min(dp[0][i-5],Min(dp[1][i-5],dp[2][i-5]))+Grade(i-1,5),9999999);
		}
		printf("%d\n",Min(dp[0][len],Min(dp[1][len],dp[2][len])));
	}
} 
