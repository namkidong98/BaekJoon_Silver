//N과 M 7(실버3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8];
int target[8];

void sequence(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) printf("%d ", target[i]);
		printf("\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			target[count] = number[i];
			sequence(count + 1);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}

	//입력 받은 값들 오름차순으로 정렬
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (number[i] > number[j]) {
				int temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}

	sequence(0);
}