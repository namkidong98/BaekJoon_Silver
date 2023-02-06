//수 이어쓰기1(실버4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int N;

int main() {
	int digit = 0; 	int total = 0; int times, first;

	scanf("%d", &N);
	int temp = N;
	while (temp != 0) {
		temp /= 10;
		digit++;
	}
	temp = N;
	first = digit;
	while (digit != 0) {
		digit--;
		if (first - 1 == digit) times = temp - (int)pow(10, digit) + 1;
		else times = (int)pow(10, digit) * 9;

		total += times * (digit + 1);

		temp = temp - times; //남은 숫자 갱신
	}
	printf("%d", total);
}