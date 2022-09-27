#include <stdio.h>
#include "common.h"

DivTwoArrays(int** res, int** a, int** b, int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (b[i][j] == 0)
				res[i][j] = 0;
			else
				res[i][j] = a[i][j] / b[i][j];
		}
	}
}

int main() {
	int m, n;
	int r, c;
	int** a, ** b, ** res;

	printf("행렬의 행 값을 입력:");
	scanf("%d", &m);
	printf("행렬의 열 값을 입력:");
	scanf("%d", &n);

	a = array(m, n);
	b = array(m, n);
	res = array(m, n);

	for (r = 0; r < m; r++) {
		for (c = 0; c < n; c++) {
			a[r][c] = rand() % 10;
		}
	}
	for (r = 0; r < m; r++) {
		for (c = 0; c < n; c++) {
			b[r][c] = rand() % 5;
		}
	}

	printArray(a, m, n, "A");
	printArray(b, m, n, "B");
	DivTwoArrays(res, a, b, m, n);
	printArray(res, m, n, "C");

	freeArray(a, m, n);
	freeArray(b, m, n);
	freeArray(res, m, n);
}