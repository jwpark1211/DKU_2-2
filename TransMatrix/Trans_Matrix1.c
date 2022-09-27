#include <stdio.h>
#include "common.h"

TransMatrix(int** a, int m, int n) {
	int** trans_a;
	int i, j;

	trans_a = array(n, m);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			trans_a[j][i] = a[i][j];

	printArray(trans_a, m, n, "Trans_A");
	freeArray(trans_a, m, n);
}

int main(void) {
	int m, n;
	int r, c;
	int** a;

	printf("행렬의 행 값 입력:");
	scanf("%d", &m);
	printf("행렬의 열 값 입력:");
	scanf("%d", &n);

	a = array(m, n);

	for (r = 0; r < m; r++)
		for (c = 0; c < n; c++)
			a[r][c] = rand() % 10;

	printArray(a, m, n, "A");
	SparsMatrix(a, m, n);

	freeArray(a, m, n);
}