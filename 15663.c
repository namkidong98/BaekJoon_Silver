//N�� M 8 (�ǹ�2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, len;
int input[8]; //���� �Է� �ޱ� ���� ����
int number[8][2]; //�Է� ���� ���� ������������ �����ϰ� 0���� �ش� ���ڸ�, 1���� �ش� ���ڰ� ���� Ƚ���� ����
int target[8];

void sequence(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}

	else {
		for (int i = 0; i <= len; i++) {
			if (number[i][1] > 0) { //�ش� ���ڸ� ����� Ƚ���� �����ִٸ�
				target[count] = number[i][0];
				number[i][1]--; //��� ������ Ƚ�� �ϳ��� ���̰�
				sequence(count + 1);
				number[i][1]++; //��Ͱ� ������ ������ �� �̹� ���࿡�� ������ ��(Ƚ�� 1�� ���̱�)�� ����Ű�� �۾�
			}
		}
	}
}

int main() {
	int temp; len = 0;
	scanf("%d %d", &N, &M);

	//�ʱ�ȭ
	for (int i = 0; i < N; i++) {
		number[i][0] = 0;
		number[i][1] = 0;
	}

	//�� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	
	//������������ input���ٰ� ����
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (input[i] > input[j]) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

	//���ĵ� input�� ���� �ݺ��Ǿ� ���� ���ڸ� ���ְ� Ƚ���� �ľ��ϴ� number�� �����
	for (int i = 0; i < N; i++) {
		number[len][0] = input[i];
		number[len][1]++;
		if (i == N - 1) continue;
		if (input[i] == input[i + 1]) {
		}
		else len++;
	}
	
	//��� �Լ� ����
	sequence(0);
}