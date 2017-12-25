#include<iostream>
using namespace std;
/*	variables  */
#define MAXSIZE 20000
int siz;
class bunch {
public:
	int height;
	int numberOfWood;
	int size() {
		return numberOfWood*height;
	}
};
bunch arr[MAXSIZE], merged[MAXSIZE];

/*	functions  */
bool to_be_merged(int a,int b) {
	if ((a == b) || ((a<0) || (b<0)) || ((b>siz) || (a>siz)))
		return false;
	if ((merged[a].height < merged[b].height) 
		&& (((merged[a].numberOfWood+merged[b].numberOfWood)*merged[a].height) > merged[b].size())) {
		return true;
	}
	if ((merged[b].height < merged[a].height)
		&& (((merged[b].numberOfWood + merged[a].numberOfWood)*merged[b].height) > merged[a].size())) {
		return true;
	}
	if (merged[a].height == merged[b].height)
		return true;
	return false;
	//mis6. 방향을 줬어야함. b를 무조건 합쳐지는 쪽으로
}

void merge(int a, int b) { //mistake 1. i declared this func under the split.(split calls this func)
	if ((a == b) || ((a<0) || (b<0)) || ((b>siz) || (a>siz)))
		return;
	if ((merged[a].height < merged[b].height)
		&& (((merged[a].numberOfWood + merged[b].numberOfWood)*merged[a].height) > merged[b].size())) {
		merged[b].height = merged[a].height;
		merged[b].numberOfWood += merged[a].numberOfWood;
		merged[a] = merged[b];
		return;
	}
	if ((merged[b].height < merged[a].height)
		&& (((merged[b].numberOfWood + merged[a].numberOfWood)*merged[b].height) > merged[a].size())) {
		merged[a].height = merged[b].height;
		merged[a].numberOfWood += merged[b].numberOfWood;
		merged[b] = merged[a];
		return;
	}
	if (merged[a].height == merged[b].height) {
		merged[a].numberOfWood += merged[b].numberOfWood;
		merged[b] = merged[a];
		return;
	}
	//mis6. 방향을 줬어야함. b를 무조건 합쳐지는 쪽으로
}

void split(int start, int end) {//start,end
	if (start > end || (start<0 || end<0) || (start>siz&&end>siz)) // mistake 3
		return;
	if (start == end) {
		merged[start].height = arr[start].height;
		merged[start].numberOfWood = arr[start].numberOfWood;
	}
	else {
		if ((end - start) % 2 == 0) {//odd. mis4
			int center = start + (end - start) / 2;
			//merged[center] = arr[center];//mis5
			merged[center].height = arr[center].height;
			merged[center].numberOfWood = arr[center].numberOfWood;
			split(start, center - 1);
			split(center + 1, end);
			bool left = to_be_merged(center, center -1), right = to_be_merged(center, center + 1);
			if (left&&right) {
				merge(center - 1, center + 1);
				merge(center, center - 1);
			}
			else if (left) {
				merge(center, center - 1);
			}
			else if (right) {
				merge(center, center + 1);
			}
		}
		else { //even
			int lcenter = (end - start - 1) / 2,rcenter = (end - start + 1) / 2;
			split(start, lcenter);
			split(rcenter, end);
			bool left = to_be_merged(lcenter-1, lcenter), right = to_be_merged(rcenter, rcenter+1);
			if (left&&right) {
				merge(lcenter, lcenter - 1);
				merge(rcenter, rcenter + 1);
				merge(lcenter, rcenter);
			}
			else if(left){
				merge(lcenter, lcenter - 1);
			}
			else if (right) {
				merge(rcenter, rcenter + 1);
			}
		}
	}
}

int get_max_fence() {
	int max = -1;
	split(0, siz-1);
	for (int i = 0; i < siz; i++) {
		max = max > merged[i].size() ? max : merged[i].size();//double calc
	}
	return max;//mistake 2 i didn't return any value;
}

/*	main func  */
int  main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> siz;
		for (int i = 0; i < siz; i++) {
			cin >> arr[i].height;
			arr[i].numberOfWood = 1;
		}
		cout <<get_max_fence()<< endl;
	}
	return 0;
}