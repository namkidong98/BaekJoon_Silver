//N�� M 3(�ǹ�3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int target[8]; //����� ���ڸ� ������� �����ϴ� ����

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}

	else {
		for (int i = current; i < N; i++) {
			if (count < M) {
				target[count] = i + 1;
				sequence(count + 1, current); //����ϱ� ���� �ʿ��� count�� 1�� ���������� ���� ��ġ�� ���� ���ڵ� �ǹǷ� + 1���� �ʰ� �ִ´�
			}
		}
	}
}
 
int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}