#include <stdio.h>
#include "common.h"

SparsMatrix(int** a, int m, int n) {
	int size = 0, K = 0;
	int i, j;
	int** Spars_a;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0)
				size++;
		}
	}

	Spars_a = array(size, 3);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0)
			{
				Spars_a[K][0] = i;
				Spars_a[K][1] = j;
				Spars_a[K][2] = a[i][j];
				K++;
			}
		}
	}
	printArray(Spars_a, size, 3, "SparsM");
	freeArray(Spars_a, m, n);
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