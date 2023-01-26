//연산자끼워넣기(브루트 포스 & 백트래킹)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long MAX = -1000000000;
long MIN = 1000000000;

int num;
int operand[11]; //2~11개까지 들어올 수 있음
int operator[4];

void DFS(int plus, int minus, int multiple, int divide, int time, int sum) {
	if (time == num - 1) { //연산자 다 소모
		if (sum > MAX) MAX = sum;
		if (sum < MIN) MIN = sum;
	}

	if (plus > 0) DFS(plus - 1, minus, multiple, divide, time + 1, sum + operand[time + 1]);
	if (minus > 0) DFS(plus, minus - 1, multiple, divide, time + 1, sum - operand[time + 1]);
	if (multiple > 0) DFS(plus, minus, multiple - 1, divide, time + 1, sum * operand[time + 1]);
	if (divide > 0) DFS(plus, minus, multiple, divide - 1, time + 1, sum / operand[time + 1]);
}
//순서대로 plus가 0보다 커서 plus부터 시작한 DFS가 재귀적으로 시행되고 그 시행에 모두 끝나고 나면 해당 줄을 통과하고 아랫줄로 내려감(plus감소없이)
//이런 방식으로 연산자가 놓이는 경우의 수를 굳이 실질적으로 counting할 필요 없이 계산한다

int main() {
	scanf("%d", &num);
	for (int i = 0; i < num; i++) { //피연산자 입력 받기
		scanf("%d", &operand[i]);
	}
	for (int i = 0; i < 4; i++) { //각 연산자 개수 입력 받기
		scanf("%d", &operator[i]);
	}

	DFS(operator[0], operator[1], operator[2], operator[3], 0, operand[0]);
	printf("%d\n%d", MAX, MIN);
}