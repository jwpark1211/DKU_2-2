#include <stdio.h>
#include "common.h"

MulTwoArrays(int** res, int** a, int** b, int m, int n,int q) {
	int r, c, k;
	int sum;

	for(r=0;r<m;r++)
		for (c = 0; c < q; c++)
		{
			sum = 0;
			for (k = 0; k < n; k++)
				sum += a[r][k] + b[k][c];
			res[r][c] = sum;
		}
}

int main() {
	int m, n,q;
	int r, c;
	int** a, ** b, ** res;

	printf("ù��° ����� �� ���� �Է�:");
	scanf("%d", &m);
	printf("ù��° ����� �� ������ �ι�° ����� ���� �Է�:");
	scanf("%d", &n);
	printf("�ι�° ����� �� ���� �Է�:");
	scanf("%d", &q);

	a = array(m, n);
	b = array(n, q);
	res = array(m, q);

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
	MulTwoArrays(res, a, b, m, n,q);
	printArray(res, m, n, "C");

	freeArray(a, m, n);
	freeArray(b, n, q);
	freeArray(res, m, q);
}