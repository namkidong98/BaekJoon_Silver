//�似Ǫ�� ���� 0(�ǹ� 5): ť ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, num, target;
	int* queue;
	int front, rear;
	front = rear = -1;
	scanf("%d %d", &num, &target);

	//�ʱ� �� ����
	queue = (int*)malloc(sizeof(int) * num * num);
	for (i = 0; i < num; i++) {
		queue[++rear] = i + 1;
	}

	printf("<");
	for (i = 0; i < num; i++) {
		for (j = 0; j < target - 1; j++) {
			queue[++rear] = queue[++front];//target�������� �տ����� �ڿ� �ѱ��
		}
		if (rear - front == 1) printf("%d", queue[++front]);
		else printf("%d, ", queue[++front]);
	}
	printf(">");
}