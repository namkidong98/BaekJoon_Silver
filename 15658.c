//연산자 끼워넣기2 (실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N; //입력 받을 숫자의 개수
int number[11]; //입력 받은 숫자를 넣는 변수
int max = -1000000001; //범위가 -10억부터 10억이므로 최솟값을 넣어 초기화
int min = 1000000001; //범위가 -10억부터 10억이므로 최댓값을 넣어 초기화

void calculate(int count, int total, int plus, int minus, int multiple, int divide) {
	if (count == N - 1) { //N개의 수에 N-1개의 연산자가 정해진 경우
		if (total > max) max = total; //연산의 결과가 max보다 크면 max 갱신
		if (total < min) min = total; //연산의 결과가 min보다 작으면 min 갱신
	}
	else {
		if (plus > 0) calculate(count + 1, total + number[count + 1], plus - 1, minus, multiple, divide);
		if (minus > 0) calculate(count + 1, total - number[count + 1], plus, minus - 1, multiple, divide);
		if (multiple > 0) calculate(count + 1, total * number[count + 1], plus, minus, multiple - 1, divide);
		if (divide > 0) calculate(count + 1, total / number[count + 1], plus, minus, multiple, divide - 1);
	}
}

int main() {
	int plus, minus, multiple, divide;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &number[i]);
	scanf("%d %d %d %d", &plus, &minus, &multiple, &divide);

	calculate(0, number[0], plus, minus, multiple, divide);
	printf("%d\n%d", max, min);
}