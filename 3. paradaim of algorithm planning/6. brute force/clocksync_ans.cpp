#include <iostream>
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
int clk[16];
const char linked[SWITCHES][CLOCKS+1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
int min(int a,int b){
	return a < b ? a : b;
}
bool areAligned(int* clock){
	for(int i=0;i<16;i++){
		if(clock[i]!=12)
			return false;
	}
	return true;
}

void push(int* clock,int swtch){
	for(int c=0;c<CLOCKS;++c){
		if(linked[swtch][c]=='x'){
			clock[c] += 3;
			if(clock[c]==15) clock[c] = 3;
		}
	}
}

int solve(int* clock, int swtch){
	if(swtch==SWITCHES) return areAligned(clock) ? 0 : INF;
	int ret = INF;
	for(int cnt=0;cnt<4;++cnt){
		ret = min(ret,cnt+solve(clock,swtch+1));
		push(clock,swtch);
	}
	return ret;
}

int main(){
	int test;
	cin>>test;
	for(int t=0;t<test;t++){
		for(int i=0;i<16;i++){
			cin>>clk[i];
		}
		cout<<solve(clk,0)<<endl;
	}
	return 0;
}