#include<iostream>
using namespace std;
#define ARRSIZE 1000

int testarr[ARRSIZE];
void initialize(){
	for(int i=0;i<ARRSIZE;i++){
		testarr[i] = rand();
	}
}
void print(){
	for(int i=0;i<ARRSIZE;i++){
		cout<<testarr[i]<<" ";
		if(i%10==0)
			cout<<endl;
	}
}
void quicksort(int* arr,int l,int r);

int main(){
	initialize();
	quicksort(testarr,0,ARRSIZE-1);
	print();
	return 0;
}

void quicksort(int* arr,int l,int r){
	int i=l,j=r;
	int pivot = arr[(l+r)/2];

	while(i<=j){
		while(arr[i]<pivot)
			i++;
		while(pivot<arr[j])
			j--;

		if(i<=j){
			int temp=arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	
	}
	if(i<r)
		quicksort(arr,i,r);
	if(l<j)
		quicksort(arr,l,j);
}
