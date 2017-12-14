#include<stdio.h>
int result;
int W,H;
char map[20+2][20+2];
int blockType[4][2][2]={{{1,0},{0,1}},{{1,0},{1,1}},{{0,1},{1,1}},{{0,1},{-1,1}}};

void boardCover(int curX, int curY, int totalBoardCnt, int curBoardCnt);
int isCoverable(int x, int y, int type);
int main(){
	
	freopen("input.txt","r",stdin);
	int tc;
	int whiteBlock;
	scanf("%d",&tc);
	for(int t= 1;t<=tc;t++){
		whiteBlock =0 ;
		result = 0;
		scanf("%d %d",&H,&W);
		char temp;
		for(int y = 0 ; y <H;y++){
			for(int x = 0; x<W;x++){
				scanf(" %c",&temp);
				map[y][x] = 1;
				if(temp!='#'){
					map[y][x] = 0;
					whiteBlock++;
				}
			}
		}

		if(whiteBlock%3 ==0){
			boardCover(0,0,whiteBlock/3,0);
		}
		printf("%d\n",result);
	}


}


void boardCover(int curX, int curY, int totalBoardCnt, int curBoardCnt){
	if(totalBoardCnt == curBoardCnt){
		result ++;
		return;
	}
	if(curY>H){
		return;
	}
	
	if(map[curY][curX]==0){
		int i;
		for(i = 0 ;i<4;i++){
			if(isCoverable(curX,curY, i)){
				map[curY][curX] = curBoardCnt+1;
				for(int j = 0;j<2;j++){
					map[curY+blockType[i][j][1]][curX+blockType[i][j][0]] = curBoardCnt+1;	
				}

				boardCover((curX+1+blockType[i][0][0])%W,curY+(curX+1+blockType[i][0][0])/W,totalBoardCnt, curBoardCnt+1);
				map[curY][curX] = 0;
				for(int j = 0;j<2;j++){
					map[curY+blockType[i][j][1]][curX+blockType[i][j][0]] = 0;	
				}
			}

		}
	} else{
		boardCover((curX+1)%W,curY+(curX+1)/W,totalBoardCnt, curBoardCnt);
	}
}

int isCoverable(int x, int y, int type){
	for(int i = 0;i<2;i++){
		if(y+blockType[type][i][1]>=H||x+blockType[type][i][0]<0||x+blockType[type][i][0]>=W||map[y+blockType[type][i][1]][x+blockType[type][i][0]]!=0)
			return 0;
	}
	return 1;
}

