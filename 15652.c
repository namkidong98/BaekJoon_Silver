//N과 M 4(실버 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int target[8];

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}
	else {
		for (int i = current; i < N; i++) { //i를 current부터 시작하게 해서 앞으로 가지 않도록(비내림차순 방지)
			if (count < M) {
				target[count] = i + 1;
				sequence(count + 1, i); //그리고 도달한 i번째 index 그대로 다음 시행의 current로 넘기기(비내림차순 방지)
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}