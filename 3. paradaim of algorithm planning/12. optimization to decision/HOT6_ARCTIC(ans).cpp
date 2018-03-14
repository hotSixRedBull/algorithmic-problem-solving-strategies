#include <iostream>
using namespace std;
#define MAXSIZ 100
#define MAXQSIZ 1000
int n;
//두 기지 사이의 거리를 미리 계산해둔다.
double dist[101][101];
//거리 d 이하인 기지들만을 연결했을 때 모든 기지가 연결되는지 여부를 반환한다.
bool decision(double d){
	bool visited[MAXSIZ];
	int q[MAXQSIZ],front=0,rear=0;
	for(int i=0;i<MAXSIZ;i++)
		visited[i] = false;
	q[rear++] = 0;
	int seen = 0;
	while(front<rear){
		int here = q[front++];
		++seen;
		for(int there=0;there<MAXSIZ;there++){
			if(!visited[there]&&dist[here][there] <= d)
				visited[there] = true;
				q[rear++] = there;
		}
	}
	return seen == n;
}
double optimize(){
	double lo = 0, hi = 1416.00;
	for(int it=0;it<100;++it){
		double mid = (lo+hi)/2;
		if(decision(mid)){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	return hi;
}
int main(){
	return 0;
}