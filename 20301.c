//���� �似Ǫ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, temp;
	int N, K, M; //N��, K��° ���, M���� ���ŵ� ������ �ݴ��
	int* queue;
	int front, rear, dir, end;
	front = rear = -1;
	dir = 0; //dir�� ȸ�� ������ ��Ÿ���� 0�϶��� �ð����, 1�϶��� �ݽð����
	end = 0; //1�� �Ǹ� �����ϴ� �ñ׳�

	scanf("%d %d %d", &N, &K, &M);
	queue = (int*)malloc(sizeof(int) * N * N);
	
	//�ʱ� �� ����
	for (i = 0; i < N; i++) {
		queue[++rear] = i + 1;
	}
	
	while (1) {
		if (dir == 0) {
			for (j = 0; j < M; j++) {
				for (i = 0; i < K - 1; i++) {
					queue[++rear] = queue[++front];
				}
				printf("%d\n", queue[++front]);
				if (front == rear) { //���� ����
					end = 1;
					break;
				}
			}
			if (end == 1) break;
			dir = 1; //M��° ���Ŀ��� ���� ������ �ٲ�
		}
		else { //dir�� 1�̾ �ݽð�� ���� ���
			for (j = 0; j < M; j++) {
				for (i = 0; i < K - 1; i++) {
					queue[front--] = queue[rear--]; //rear�� front�� �ݴ�� �۵���Ű�� ������� ����
				}
				printf("%d\n", queue[rear--]);
				if (front == rear) { //���� ����
					end = 1;
					break;
				}
			}
			if (end == 1) break;
			dir = 0; //M��° ���Ŀ��� ���� ������ �ٲ�
		}
	}
}