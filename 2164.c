//ī�� 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, num;
	int* queue;
	int front, rear;
	front = rear = -1;
	scanf("%d", &num);
	queue = (int*)malloc(sizeof(int) * num * 2); //�ڷ� �ű�� ������ ���� �� �ֵ��� num���� �� ū ������ queue�� �ʿ�
	
	//1���� N���� ���ʴ�� add_queue
	for (i = 0; i < num; i++) {
		queue[++rear] = i + 1;
	}

	while (front != rear - 1) { //���� ������ ����
		//���� ���� ī�� ������
		front++; //front�� ��ġ�� ���� ���� ���
		//�� ���� ���� ���� ī�带 ���� �Ʒ��� �ű��
		queue[++rear] = queue[++front];
	}
	printf("%d", queue[rear]);

	free(queue);
}