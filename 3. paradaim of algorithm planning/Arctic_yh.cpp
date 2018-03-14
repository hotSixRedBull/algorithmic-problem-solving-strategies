#include <stdio.h>
#include<math.h>

void quickSort(int first, int last);
double findMST(int* parent, int N);
int checkCycle(int u, int* parent);

double dist[10000 + 3][3];

int main() {

	int tc, N;

	double pos[100 + 3][2];
	int parent[100 + 3];

	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		}

		for (int idx = 0; idx < N * (N - 1) / 2; idx++) {
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					dist[idx][0] = i;
					dist[idx][1] = j;
					dist[idx][2] = sqrt((pos[i][0] - pos[j][0])*(pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1])*(pos[i][1] - pos[j][1])); 
				}
			}
		}
		printf("%.2lf\n", findMST(parent, N));
	}

}

double findMST(int* parent, int N) {
	double result;
	int arrSize = N * (N - 1) / 2;
	int select = 0;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	quickSort(0, arrSize - 1);

	for (int i = 0; i < N*(N - 1) / 2; i++) {
		int represent[2];
		represent[0] = checkCycle((int)dist[i][0], parent);
		represent[1] = checkCycle((int)dist[i][1], parent);

		if (represent[0] != represent[1]) {
			select++;
			result = dist[i][2];
			parent[represent[1]] = dist[i][0];
			if (select >= N - 1) {
				break;
			}
		}
	}
	return result;
}
int checkCycle(int u, int* parent) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	double temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (dist[i][2] <= dist[pivot][2] && i < last)
			{
				i++;
			}
			while (dist[j][2] > dist[pivot][2])
			{
				j--;
			}
			if (i < j)
			{
				temp = dist[i][2];
				dist[i][2] = dist[j][2];
				dist[j][2] = temp;

				temp = dist[i][1];
				dist[i][1] = dist[j][1];
				dist[j][1] = temp;

				temp = dist[i][0];
				dist[i][0] = dist[j][0];
				dist[j][0] = temp;
			}
		}

		temp = dist[pivot][2];
		dist[pivot][2] = dist[j][2];
		dist[j][2] = temp;

		temp = dist[pivot][1];
		dist[pivot][1] = dist[j][1];
		dist[j][1] = temp;

		temp = dist[pivot][0];
		dist[pivot][0] = dist[j][0];
		dist[j][0] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}