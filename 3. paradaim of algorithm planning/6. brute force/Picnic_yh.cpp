#include <stdio.h>

int pair[90+2][2];
int visited[10];
int result; 
void makepair(int m, int currentPair,  int totalPairCnt, int currentPairCnt);
int main(){

	int tc;
	int n = 0,m = 0;

	freopen("input.txt","r",stdin);

	scanf("%d",&tc);

	for(int t = 1; t <= tc; t++){
		for(int i = 0 ; i<n;i++){
			visited[i]=0;
		}
		result = 0;
		scanf("%d %d",&n,&m);
		
		for(int i = 0 ; i<m;i++){
			scanf("%d %d",&pair[i][0], &pair[i][1]);
		}

		makepair(m,0,n/2,0);
		printf("%d\n",result);
		

	}

}


void makepair(int m, int currentPair,  int totalPairCnt, int currentPairCnt){
	if(currentPairCnt == totalPairCnt){
		result ++;
		return;
	}
	if(currentPair == m){
		return;
	}


	if(visited[pair[currentPair][0]]!=1 && visited[pair[currentPair][1]]!=1){
		visited[pair[currentPair][0]]=1;
		visited[pair[currentPair][1]]=1;
		makepair(m,currentPair+1,totalPairCnt,currentPairCnt+1);
		visited[pair[currentPair][0]]=0;
		visited[pair[currentPair][1]]=0;
	} 
		
	makepair(m,currentPair+1,totalPairCnt,currentPairCnt);
	

}