#include <iostream>
using namespace std;
#define MAXLEN 200000
#define INF 123456789
/*var*/
char group[MAXLEN],fan[MAXLEN];
int gLen,fLen,stk[MAXLEN],top,fir;
/*func*/
int get_len(char* str){
	int len=0;
	while(str[len]!='\0')
		len++;
	return len;
}

void set_stk(){
	for(int i=0;i<gLen;i++){
		if(group[i]=='M'){
			fir=i;
			break;
		}
	}

	for(int i=fir;i<gLen;i++){
		if(group[i]=='M'){
			stk[top++] = i-fir;
		}
	}
}

void init(){
	gLen = get_len(group);
	fLen = get_len(fan);
	top = 0;
	fir = INF;
	set_stk();
}

bool match(int index){
	for(int i=0;i<top;i++){
		if(fan[stk[i]+index]!='F')
			return false;
	}
	return true;
}

int number_of_hug(){
	int ret=0;
	for(int i=fir;i<fLen;i++){
		if(fan[i]=='F'&&match(i)){
			ret++;
		}
	}
	if(fir == INF)
		return fLen-gLen+1;
	return ret;
}
/*main*/
int main(){
	int test=-1;
	cin>>test;
	for(int t=0;t<test;t++){
		cin>>group;
		cin>>fan;
		init();
		cout<<number_of_hug()<<endl;
	}
	return 0;
}
