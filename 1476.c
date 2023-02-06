//날짜 계산(실버5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int E, S, M;
int count = 1;

int main() {
	int first, second, third;
	scanf("%d %d %d", &E, &S, &M);

	first = second = third = 1; //시작
	for (count = 1; ; count++) {
		if (first == E && second == S && third == M) break;

		first++;
		if (first == 16) first = 1;
		second++;
		if (second == 29) second = 1;
		third++;
		if (third == 20) third = 1;
	}
	printf("%d", count);
	
}