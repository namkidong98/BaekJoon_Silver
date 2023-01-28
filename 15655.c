//N과 M 6(실버 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8];
int target[8];

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) printf("%d ", target[i]);
		printf("\n");
	}

	else {
		for (int i = current; i < N; i++) {
			target[count] = number[i];
			sequence(count + 1, i + 1);
		}
	}
}

int main() {
	int temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}

	//입력 받은 숫자 오름차순으로 정렬
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (number[i] > number[j]) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}

	sequence(0, 0);
}