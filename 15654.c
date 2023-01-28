//N과 M 5(실버3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8];
int visited[8] = { 0 };
int target[8];

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			if (count < M && visited[i] == 0) {
				target[count] = number[i]; visited[i] = 1;
				sequence(count + 1, current + 1);
				visited[i] = 0;
			}
		}
	}
}

int main() {
	int temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}

	//오름차순으로 입력받은 숫자 정렬
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