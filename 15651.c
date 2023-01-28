//N과 M 3(실버3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int target[8]; //출력할 숫자를 순서대로 저장하는 변수

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}

	else {
		for (int i = current; i < N; i++) {
			if (count < M) {
				target[count] = i + 1;
				sequence(count + 1, current); //출력하기 위해 필요한 count는 1개 증가하지만 현재 위치는 동일 숫자도 되므로 + 1하지 않고 넣는다
			}
		}
	}
}
 
int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}