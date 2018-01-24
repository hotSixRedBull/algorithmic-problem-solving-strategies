#include<stdio.h>

int candAns[10000 + 3];
int box[10000 + 3];
int eatTime[10000 + 3];

void quickSortPair(int *list1, int *list2, int n);
void quickSort(int *list1, int n);
int main() {
	int tc;
	int n;
	freopen("input.txt", "r", stdin);


	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &box[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &eatTime[i]);
		}
		quickSortPair(eatTime, box, n);
		
		
		candAns[0] = box[0] + eatTime[0];
		int max = candAns[0];
		for (int i = 1; i < n; i++) {
			candAns[i] = candAns[i - 1] - eatTime[i - 1] + box[i] + eatTime[i];
			if(max<candAns[i]){
				max = candAns[i];
			}
		}

		printf("%d\n",max);
	}
}

void quickSortPair(int *list1, int *list2, int n)
{
	int i = 0, j = n;
	int temp;
	if (n < 2) return;
	while (1)
	{
		while (list1[++i] > list1[0])
			if (i >= n) break;

		while (list1[--j] < list1[0]);

		if (i >= j)
		{
			break;
		}
		temp = list1[i];
		list1[i] = list1[j];
		list1[j] = temp;
		temp = list2[i];
		list2[i] = list2[j];
		list2[j] = temp;
	}

	if (j == n - 1 && list1[0] == list1[j])
	{
		j--;
	}
	temp = list1[0];
	list1[0] = list1[j];
	list1[j] = temp;
	temp = list2[0];
	list2[0] = list2[j];
	list2[j] = temp;
	quickSortPair(list1, list2, j);
	quickSortPair(list1 + j + 1, list2 + j + 1, n - j - 1);
}

