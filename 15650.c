//N�� M 2 (�ǹ�2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8] = { 0 }; //0�̸� ���X, 1�̸� ���

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < N; i++) { //1���� N���� 1���� ���� ������ ���������� ����
			if (number[i] == 1) printf("%d ", i + 1);
		}
		printf("\n");
	}

	else {
		for (int i = current; i < N; i++) {
			if (count < M) {
				number[i] = 1; //���
				sequence(count + 1, i + 1);
				number[i] = 0; //���X
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}