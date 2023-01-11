//������ ť(�ǹ�3, ť ����)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calculate(int num, int index, int* imp, int max) {
	int front, rear, i;
	int count = 0; //���° ������� ��Ÿ���� ��ǥ
	front = -1;
	rear = num - 1;
	while (1) { 
		if (imp[++front] < max) { //�߿䵵�� �� ������ ������
			imp[++rear] = imp[front]; //������� �ʰ� �ڷ� �ѱ��
			if (index == front) index = rear;
		}
		else { //�� ���� �߿䵵�� ������ --> ����ؾ� �Ѵ�
			count++;
			if (front == index) break;
			//�߿䵵�� �ִ� ����
			max = imp[front + 1];
			for (i = front + 1; i <= rear; i++) {
				if (imp[i] > max) max = imp[i];
			}
		}
	}
	return count;
}

int main() {
	int testcase, i, j; 
	int num, index; //������ ����, �ñ��� ������ queue������ ����(0����)
	int* imp; //������ �߿䵵(queue�� ����)
	int result;
	int max = 0;

	scanf("%d", &testcase); //�׽�Ʈ ���̽� ���� �Է�
	for (i = 0; i < testcase; i++) {
		//�׽�Ʈ ���̽��� �ʿ��� ���� �Է� �ޱ�(���� ����, �ñ��� ������ ����, ���������� �߿䵵)
		scanf("%d %d", &num, &index); 
		imp = (int*)malloc(sizeof(int) * num * num);
		for (j = 0; j < num; j++) {
			scanf("%d", &imp[j]); //0���� ���������� �߿䵵
			if (max < imp[j]) max = imp[j];
		}
		result = calculate(num, index, imp, max);
		printf("%d\n", result);
		max = 0; //���� ������ ���� �ʱ�ȭ
	}
}