#include<iostream>
using namespace std;
#define MAXSIZE 10000

int heap[MAXSIZE];
int heapSize=0;

int heapPush(int val){
	int p,cur=heapsize-1;

	if(heapSize >= MAXSIZE)
		return -1;

	heap[heapSize++]=val;
	
	while((cur-1)/2>=0){
		p = (cur-1)/2;
		if(heap[p]>heap[cur]){
			int temp = heap[p];
			heap[p] = heap[cur];
			heap[cur] = heap[p];
			cur = p;
		}
	}
}

int heapPop(int* obj){
	int cur = 0;
	if(heapSize==0)
		return -1;

	*obj = heap[0];
	heap[0] = heap[--heapSize];
	while(cur*2+2<=heapSize){
		if()
	}
}

int main(){

	return 0;
}

