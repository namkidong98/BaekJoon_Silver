//부분수열의 합(실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S;
int number[20];
int count = 0;

void cal(int left, int total, int current) {
	if (left == 0) { //i개를 모두 골라서 left가 0이 되고
		if (total == S) { //골라진 부분 수열의 합이 S와 같으면
			count++; //경우의 수 1개 증가
		}
	}
	else { //left가 남아 더 골라야 하는 상황에선
		for (int i = current; i < N; i++) { //이전 위치를 받아와서
			cal(left - 1, total + number[i], i + 1); //left 1개 줄이고 해당 수열의 값을 total에 더하고 current는 1 증가시켜 다음 것을 탐색하도록
		}
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 1; i <= N; i++) {
		cal(i, 0, 0); //i개의 부분수열로 S가 되는지 만들어보게끔 시행
	}
	printf("%d", count);
}