#include<stdio.h>
int H, W;
int R, C;

char map[10 + 2][10 + 2];
int blockType[4][10][10];
int relativeBlock[4][100][2];
int blockSize;
int maxBlock;
int totalType;

void getRotatedBlock();
void boardCover(int curX, int curY, int totalBoardCnt, int curBoardCnt);
int isCoverable(int x, int y, int type);
int main() {

	freopen("input.txt", "r", stdin);
	int tc;
	int whiteBlock;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		totalType = 4;
		whiteBlock = 0;
		scanf("%d %d %d %d", &H, &W, &R, &C);
		char temp;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				scanf(" %c", &temp);
				map[y][x] = 1;
				if (temp != '#') {
					map[y][x] = 0;
					whiteBlock++;
				}
			}
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				scanf(" %c", &temp);
				blockType[0][y][x] = 1;
				if (temp != '#') {
					blockType[0][y][x] = 0;
				}
			}
		}
		getRotatedBlock();


		maxBlock = -1;
		boardCover(0, 0, whiteBlock, 0);
		printf("%d\n", maxBlock);
	}


}

void getRotatedBlock() {
	int xSize = C, ySize = R;
	int stdX, stdY;
	int cnt;
	int temp;
	for (int i = 0; i < 4; i++) {
		cnt = 0;
		stdX = -1, stdY = -1;
		for (int y = 0; y < ySize; y++) {
			for (int x = 0; x < xSize; x++) {
				if (blockType[i][y][x] == 1) {
					if (stdX == -1) {
						stdX = x;
						stdY = y;
					}
					relativeBlock[i][cnt][0] = x - stdX;
					relativeBlock[i][cnt][1] = y - stdY;

					cnt++;
				}
				blockType[(i + 1) % 4][x][ySize - y - 1] = blockType[i][y][x];
			}
			blockSize = cnt;
		}

		temp = xSize;
		xSize = ySize;
		ySize = temp;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < blockSize; j++) {
			for (int k = j; k < blockSize; k++) {
				if (relativeBlock[i][j][0] > relativeBlock[i][k][0]) {
					temp = relativeBlock[i][j][0];
					relativeBlock[i][j][0] = relativeBlock[i][k][0];
					relativeBlock[i][k][0] = temp;
					temp = relativeBlock[i][j][1];
					relativeBlock[i][j][1] = relativeBlock[i][k][1];
					relativeBlock[i][k][1] = temp;
				}
			}
		}
	}
	int check[2] = { 0,0 };
	for (int j = 0; j < blockSize; j++) {
		if (relativeBlock[0][j][0] == relativeBlock[1][j][0]) {
			check[0]++;
		}
		if (relativeBlock[0][j][0] == relativeBlock[2][j][0]) {
			check[1]++;
		}
	}
	if (check[0] == blockSize) {
		totalType = 1;
	}
	else if (check[1] == blockSize) {
		totalType = 2;
	}
}


void boardCover(int curX, int curY, int whiteBlock, int curBoardCnt) {
	if (maxBlock < curBoardCnt) {
		printf("____________________________________________\n");
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				printf("%4d", map[y][x]);
			}printf("\n");
		}
		maxBlock = curBoardCnt;
	}
	if (blockSize != 0 && ((whiteBlock / blockSize) + curBoardCnt <= (maxBlock))) {
		return;
	}
	if (curY> H) {

		return;
	}

	if (map[curY][curX] == 0) {
		for (int i = 0; i < totalType; i++) {
			if (isCoverable(curX, curY, i)) {
				for (int j = 0; j < blockSize; j++) {
					map[curY + relativeBlock[i][j][1]][curX + relativeBlock[i][j][0]] = curBoardCnt + 1;
				}

				boardCover((curX + 1) % W, curY + (curX + 1) / W, whiteBlock - blockSize, curBoardCnt + 1);
				for (int j = 0; j < blockSize; j++) {
					map[curY + relativeBlock[i][j][1]][curX + relativeBlock[i][j][0]] = 0;
				}
			}
		}
	}
	boardCover((curX + 1) % W, curY + (curX + 1) / W, map[curY][curX] == 0 ? whiteBlock - 1 : whiteBlock, curBoardCnt);

	return;
}

int isCoverable(int x, int y, int type) {
	for (int i = 0; i < blockSize; i++) {
		if (y + relativeBlock[type][i][1] >= H || x + relativeBlock[type][i][0] < 0 || x + relativeBlock[type][i][0] >= W || map[y + relativeBlock[type][i][1]][x + relativeBlock[type][i][0]] != 0)
			return 0;
	}
	return 1;
}
