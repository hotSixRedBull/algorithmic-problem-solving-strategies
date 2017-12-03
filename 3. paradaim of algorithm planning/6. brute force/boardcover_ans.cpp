#include <iostream>
using namespace std;
int height,width;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
bool set(char** map,int y,int x,int type,int delta){
	bool ok = true;
	for(int i=0;i<3;i++){
		const int ny = y+coverType[type][i][0];
		const int nx = x+coverType[type][i][1];
		if(ny<0||ny>=width||nx<0||nx>=height){
			ok = false;
		}else if((map[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}
int cover(char** map){
	int y=-1,x=-1;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(map[i][j]==0){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1)
			break;
	}

	if(y==-1) return 1;
	int ret = 0;
	for(int type=0;type<4;++type){
		if(set(map,y,x,type,1))
			ret+=cover(map);
		set(map,y,x,type,-1);
	}
	return ret;
}

int main(){
	int test;
	char map[20][20];
	cin>>test;
	for(int t=0;t<test;t++){
		cin>>height>>width;
		for(int i=0;i<width;i++)
			cin>>map[i];
		cout<<cover(map)<<endl;
	}
	return 0;
}