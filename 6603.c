//로또(실버 2, 브루트포스, 재귀)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number[49];
int num;
int target[6];

void calculate(int count, int current) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) printf("%d ", target[i]);
		printf("\n");
	}

	else {
		for (int i = current; i < num; i++) {
			target[count] = number[i];
			calculate(count + 1, i + 1);
		}
	}
}

int main() {
	int temp;
	while (1) {
		scanf("%d", &num);
		if (num == 0) break;

		for (int i = 0; i < num; i++) {
			scanf("%d", &number[i]);
		}

		for (int i = 0; i < num - 1; i++) {
			for (int j = i + 1; j < num; j++) {
				if (number[i] > number[j]) {
					temp = number[i];
					number[i] = number[j];
					number[j] = temp;
				}
			}
		}

		calculate(0, 0);
		printf("\n");
	}
}