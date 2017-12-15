#include <stdio.h>

/*
* Problem :: FENCE
*
* Summary
*	Input :: N개의 Fence의 높이
*	Output :: 주어진 Fence를 적절히 잘라서 만들 수 있는 최대 크기의 직사각형의 넓이
*
* Solving :: Sweeping Algorithm
*	i번째 fence를 이용해서 만들 수 있는 최대 직사각형의 넓이 = [(i번째 fence보다 낮은 fence가 나오기 직전의 오른쪽 끝 위치) - (i번째 fence보다 낮은 fence가 나오기 직전의 왼쪽 끝 위치) - 1] * fence[i]
* stack top에 쌓인 fence의 높이보다 새로 들어오는 fence의 높이가 크면 push, 작은 경우 현재 stack의 top에 있는 fence의 높이로 만들 수 있는 직사각형의 오른쪽 끝 위치를 나타냄
* 이 stack의 top을 pop한 위치 값 = 직사각형의 오른쪽 끝, pop을 한 후 stack의 top이 가르키는 위치 = 직사각형의 왼쪽의 끝
* for문을 다돌았음에도 stack이 비지 않는 경우가 발생하기 때문에 이때, 추가적으로 위의 계산을 한번 더 해줌
*/

int fence[20001];

int Max(int a, int b){return a>b?a:b;}

int solve(int N){
	int top = 0,stack[20005],res =0, i=0;
	stack[top] = -1;
	for(i=0;i<N;++i){
		while(top>=0&&fence[i]<fence[stack[top]]){
			int tmp = stack[top];top--;
			if(top>=0) res = Max(res, fence[tmp]*(i-stack[top]-1));
		}
		stack[++top] = i;
	}
	while(top>=0){
		int tmp = stack[top];top--;
		if(top>=0) res = Max(res, fence[tmp]*(i-stack[top]-1));
	}
	return res;
}

int main(){
	freopen("test.txt","r",stdin);
	int T,N;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d",&N);
		for(int i=0;i<N;++i) scanf("%d",&fence[i]);
		printf("%d\n",solve(N));
	}
}
