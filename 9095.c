//1,2,3 더하기(실버 3, 다이나믹 프로그래밍)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;
int number;

void ans(int total, int left_one, int left_two, int left_three) {
	if (total == number) { //주어진 정수와 일치하면 성공한 경우의 수로 1개 증가시키고 종료
		count++;
		return;
	}

	else if (total > number) { //주어진 정수보다 커지면 실패한 경우의 수이므로 아무것도 하지 않고 종료
		return;
	}

	else {
		if (left_one > 0) ans(total + 1, left_one - 1, left_two, left_three);
		if (left_two > 0) ans(total + 2, left_one, left_two - 1, left_three);
		if (left_three > 0) ans(total + 3, left_one, left_two, left_three - 1);
	}
}

int main() {
	int left_one, left_two, left_three;
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &number); //값을 입력 받고
		left_one = number / 1; //해당 값에서 최대 사용 가능한 1의 개수 갱신
		left_two = number / 2; //해당 값에서 최대 사용 가능한 2의 개수 갱신
		left_three = number / 3; //해당 값에서 최대 사용 가능한 3의 개수 갱신
		ans(0, left_one, left_two, left_three); //알고리즘으로 count 값 계산
		printf("%d\n", count); //출력
		count = 0; //다음 시행을 위해 count를 0으로 초기화
	}
}