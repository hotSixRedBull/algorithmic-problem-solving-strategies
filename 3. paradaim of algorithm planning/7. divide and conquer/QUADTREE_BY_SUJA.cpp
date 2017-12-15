#include <stdio.h>

/*
* Problem :: QUADTREE
*
* Summary
*	Input :: 쿼드 트리 방식을 이용해서 압축된 문자열
*	Output :: 쿼드 트리 방식을 이용해서 압축된 문자열을 기반으로 원본의 그림을 뒤집고 쿼드트리 방식을 취해서 압축을 했을 때의 문자열
*
* Solving :: Tree 자료구조 사용
*	쿼드 트리 방식은 해당 공간의 모든 픽셀이 검은색일 경우 - b, 흰색일 경우 - w, 섞여있는 경우 다시 2x2로 나누어서 앞의 방식을 취하고 x라는 문자열을 붙임
* 자식을 4개 가지는 Tree를 구성해서 해결 -> x문자열이 나오는 경우 x를 부모로 두고 다시 4명의 자식을 구성하는 형태로 Tree구성 후, Tree 탐색 방식을 통해서 해결
* 압축 결과가 x(왼쪽위)(오른쪽위)(왼쪽아래)(오른쪽아래)이므로 이 형태의 그림을 뒤집으면 x(원본의 왼쪽아래)(원본의 오른쪽아래)(원본의 왼쪽위)(원본의 오른쪽위)로 구성해주면됨
* 즉, Tree를 구성한 후 3 -> 4 -> 1 -> 2번째 순으로 자식 노드를 방문하면 됨
*/

char quad[1001],res[1001];
int len;

struct Tree {
	char val;
	int num;
	Tree *sub[4], *root;
};

int Create(int idx, Tree *root) {
	for (int i = 0; i < 4 && quad[idx] != '\0'; ++i, ++idx) {
		Tree *a = new Tree();
		a->val = quad[idx];
		a->root = root;
		root->sub[i] = a;
		root->num++;
		if (a->val == 'x') idx = Create(idx + 1, a);
	}
	return idx-1;
}

void Visit(Tree *root) {
	printf("%c", root->val);
	for (int i = 2; i < 6; ++i) {
		if(root->sub[i%4]!=0) Visit(root->sub[i % 4]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		len = 0;
		scanf("%s", &quad);
		Tree *root = new Tree();
		root->val = quad[0];
		root->num = 0;
		Create(1, root);
		Visit(root);
		printf("\n");
	}
	return 0;
}
