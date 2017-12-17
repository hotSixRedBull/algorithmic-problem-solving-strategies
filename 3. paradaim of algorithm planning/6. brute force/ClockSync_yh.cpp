#include<stdio.h>
int sw[10][5]={{0,1,2,},{3,7,9,11,},{4,10,14,15,},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15},{3,14,15,},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};
int swCnt[10] = {3,4,4,5,5,4,3,5,5,5};
int clock[16];
int min;
int curClock;
void getMinClockSync(int btn, int curPush);
int main(){
	int tc;
	freopen("input.txt","r",stdin);
	scanf("%d",&tc);
	for(int t = 1 ;t<=tc;t++){
		curClock = 0;
		min = 100000007;
		for(int i = 0 ; i<16;i++){
			scanf("%d",&clock[i]);
			clock[i]=clock[i]%12;
			curClock += clock[i];
		}
		getMinClockSync(0, 0);
		if(min==100000007){
			min=-1;
		}
		printf("%d\n",min);
	}

}

void getMinClockSync(int btn, int curPush){
	if(curClock == 0){
		min = curPush;

	}
	if(curPush>min||btn==10){
		return;
	}


	for(int i = 0;i<4;i++){
		for(int j = 0 ; j<swCnt[btn];j++){
			curClock -= clock[sw[btn][j]];
			clock[sw[btn][j]] = (clock[sw[btn][j]] + i*3)%12;
			curClock += clock[sw[btn][j]];
		}

		getMinClockSync(btn+1,curPush+i);

		for(int j = 0 ; j<swCnt[btn];j++){
			curClock -= clock[sw[btn][j]];
			clock[sw[btn][j]] = (clock[sw[btn][j]] + (4-i)*3)%12;
			curClock += clock[sw[btn][j]];
		}

	}
}