//N�� M 1(�ǹ�3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8] = { 0 }; //0�̸� ���X, 1�̻��̸� �켱������ ����Ѵٴ� �ǹ�

void sequence(int count, int current) { //count�� M������ ���� ����, current�� ���� ��ġ
	if (count == 0) {
		for (int j = M; j > 0; j--) { //�� M���� ���� �ϴ� M�� �ݺ��ϸ鼭 �켱���� ���� �ͺ��� ����ϵ��� ����
			for (int i = 0; i < N; i++) {
				if (number[i] == j) printf("%d ", i + 1);
			}
		}
		printf("\n");
	}

	else {
		for (int i = 0; i < N; i++) {
			if (count > 0 && number[i] == 0) { //���� ���� ���̰� �������� �ش� ���ڰ� ������ �ʾҴٸ�
				number[i] = count;  //�켱���� �ο��ؼ�
				sequence(count - 1, i + 1); //������ ���� ������ �ѱ��
				number[i] = 0; //������ ������ �ش� ��ġ ��� ���� ������ �ʱ�ȭ(���)
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(M, 0);
}