//색종이(2차원 배열)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int total[100][100] = { 0 };
	int i, j, k;
	int count = 0;
	int num, x, y;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &x, &y);
		for (j = x; j < x + 10; j++) {
			for (k = y; k< y + 10; k++) {
				total[j][k] = 1;
			}
		}
	}

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (total[i][j] == 1) count++;
		}
	}

	printf("%d", count);
}