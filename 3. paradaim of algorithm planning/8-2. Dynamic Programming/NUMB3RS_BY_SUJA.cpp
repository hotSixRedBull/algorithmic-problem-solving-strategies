#include <stdio.h>

int main(){
	freopen("test.txt","r",stdin);
	int T,N,d,s,arr[100][100],total[100],cnt,idx;
	double prob[2][100];
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d%d%d",&N,&d,&s);
		for(int i=0;i<N;++i){
			prob[0][i] = prob[1][i] = total[i] = 0;
			for(int j=0;j<N;++j) {
				scanf("%d",&arr[i][j]);
				if(arr[i][j]) total[i]++;
			}
		}
		for(int i=1;i<=d;++i){
			for(int j=0;j<N;++j) prob[i%2][j] = 0;
			for(int j=0;j<N;++j){
				if(i==1) {
					if(arr[s][j]) prob[i%2][j] = (double)1/total[s];
				}else{
					if(prob[(i+1)%2][j]!=0){
						for(int k=0;k<N;++k){
							if(arr[j][k]) prob[i%2][k] += prob[(i+1)%2][j]*((double)1/total[j]);
						}
					}
				}
			}
		}
		scanf("%d",&cnt);
		for(int i=0;i<cnt;++i){
			scanf("%d",&idx);
			printf("%.8lf ",prob[d%2][idx]);
		}
		printf("\n");
	}
}
