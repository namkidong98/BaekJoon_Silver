//�κм����� ��(�ǹ�2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, S;
int number[20];
int count = 0;

void cal(int left, int total, int current) {
	if (left == 0) { //i���� ��� ��� left�� 0�� �ǰ�
		if (total == S) { //����� �κ� ������ ���� S�� ������
			count++; //����� �� 1�� ����
		}
	}
	else { //left�� ���� �� ���� �ϴ� ��Ȳ����
		for (int i = current; i < N; i++) { //���� ��ġ�� �޾ƿͼ�
			cal(left - 1, total + number[i], i + 1); //left 1�� ���̰� �ش� ������ ���� total�� ���ϰ� current�� 1 �������� ���� ���� Ž���ϵ���
		}
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 1; i <= N; i++) {
		cal(i, 0, 0); //i���� �κм����� S�� �Ǵ��� �����Բ� ����
	}
	printf("%d", count);
}