//한수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int result(int number) { //주어진 number가 한수인지 판단하는 함수
	int a[4] = { 0 }; //각 자릿수를 의미 a[3]은 천의자리, a[2]는 백의 자리, a[1]은 십의자리, a[0]은 일의자리
	a[3] = number / 1000;
	number = number % 1000;
	a[2] = number / 100;
	number = number % 100;
	a[1] = number / 10;
	number = number % 10;
	a[0] = number;
	int d[3] = { 0 };
	d[0] = a[3] - a[2];
	d[1] = a[2] - a[1];
	d[2] = a[1] - a[0];
	if (a[3] == 0 && a[2] == 0 && a[1] == 0) return 1; //1의 자리
	else if(a[3] == 0 && a[2] == 0) { //10의 자리
		return 1;
	}
	else if (a[3] == 0) { //백의 자리
		if (d[1] == d[2]) return 1;
	}
	else {
		if (d[0] == d[1] && d[1] == d[2]) return 1;
	}
	return 0;
}

int main() {
	int num, i, j;
	int count = 0;

	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		if (result(i) == 1) count++; //한수인 경우 숫자 늘리기
	}
	printf("%d", count);
}