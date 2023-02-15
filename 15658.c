//������ �����ֱ�2 (�ǹ�2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N; //�Է� ���� ������ ����
int number[11]; //�Է� ���� ���ڸ� �ִ� ����
int max = -1000000001; //������ -10����� 10���̹Ƿ� �ּڰ��� �־� �ʱ�ȭ
int min = 1000000001; //������ -10����� 10���̹Ƿ� �ִ��� �־� �ʱ�ȭ

void calculate(int count, int total, int plus, int minus, int multiple, int divide) {
	if (count == N - 1) { //N���� ���� N-1���� �����ڰ� ������ ���
		if (total > max) max = total; //������ ����� max���� ũ�� max ����
		if (total < min) min = total; //������ ����� min���� ������ min ����
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