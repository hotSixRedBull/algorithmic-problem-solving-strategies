#include<iostream>
using namespace std;
#define MAXSIZE 10000

int heap[MAXSIZE];
int heapSize=0;

int heapPush(int val){
	if(heapSize >= MAXSIZE)
		return -1;

	heap[heapSize++]=val;
	int p,cur=heapsize-1;
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
	if(heapSize==0)
		return -1;

	*obj = heap[0];
	heap[0] = heap[--heapSize];

}

int main(){

	return 0;
}

