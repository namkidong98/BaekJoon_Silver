//�ִ� ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void deletion(int* heap, int* count) { //������ �Ʒ��� �������� ����
	int item = heap[1]; //������ ���� ����� ���
	int temp = heap[(*count)--]; //������ ��°�� ���
	int parent = 1;
	int child = 2;

	while (child <= *count) {
		if ((child < *count) && heap[child] < heap[child + 1]) child++; //�������� ������ ũ�� �������� ����
		if (temp > heap[child]) break; //
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	printf("%d\n", item);
}

void insertion(int* heap, int data, int* count) { //�Ʒ����� ���� �ö���� ����
	int parent, child;
	int i = ++(*count);
	while ((i != 1) && data > heap[i / 2]) { //parent���� ���� ũ��
		heap[i] = heap[i / 2]; //���� �ڸ��� parent�� ������
		i /= 2; //���� parent �ڸ��� �ø�����
	}
	heap[i] = data;
}

int main() {
	int num, i, data;
	int* heap;
	int count = 0;
	scanf("%d", &num);

	//�� �ʱ�ȭ
	heap = (int*)malloc(sizeof(int) * (num + 1));
	for (i = 0; i <= num; i++) {
		heap[i] = 0;
	}

	for (i = 0; i < num; i++) {
		scanf("%d", &data);
		if (data == 0) { //delete(pop)
			if (count == 0) { //���� ���� ���� ���
				printf("0\n");
			}
			else { //���� ���� �ִ� ��� --> �ִ� ���� ���(heap[0])
				deletion(heap, &count);
			}
		}
		else { //insert
			insertion(heap, data, &count);
		}
	}
}