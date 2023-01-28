//N�� M 4(�ǹ� 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int target[8];

void sequence(int count, int current) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}
	else {
		for (int i = current; i < N; i++) { //i�� current���� �����ϰ� �ؼ� ������ ���� �ʵ���(�񳻸����� ����)
			if (count < M) {
				target[count] = i + 1;
				sequence(count + 1, i); //�׸��� ������ i��° index �״�� ���� ������ current�� �ѱ��(�񳻸����� ����)
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(0, 0);
}