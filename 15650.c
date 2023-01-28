//N과 M 2 (실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8] = { 0 }; //0이면 사용X, 1이면 사용

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < N; i++) { //1부터 N까지 1번만 돌기 때문에 오름차순만 가능
			if (number[i] == 1) printf("%d ", i + 1);
		}
		printf("\n");
	}

	else {
		for (int i = current; i < N; i++) {
			if (count < M) {
				number[i] = 1; //사용
				sequence(count + 1, i + 1);
				number[i] = 0; //사용X
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}