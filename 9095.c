//1,2,3 ���ϱ�(�ǹ� 3, ���̳��� ���α׷���)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;
int number;

void ans(int total, int left_one, int left_two, int left_three) {
	if (total == number) { //�־��� ������ ��ġ�ϸ� ������ ����� ���� 1�� ������Ű�� ����
		count++;
		return;
	}

	else if (total > number) { //�־��� �������� Ŀ���� ������ ����� ���̹Ƿ� �ƹ��͵� ���� �ʰ� ����
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
		scanf("%d", &number); //���� �Է� �ް�
		left_one = number / 1; //�ش� ������ �ִ� ��� ������ 1�� ���� ����
		left_two = number / 2; //�ش� ������ �ִ� ��� ������ 2�� ���� ����
		left_three = number / 3; //�ش� ������ �ִ� ��� ������ 3�� ���� ����
		ans(0, left_one, left_two, left_three); //�˰������� count �� ���
		printf("%d\n", count); //���
		count = 0; //���� ������ ���� count�� 0���� �ʱ�ȭ
	}
}