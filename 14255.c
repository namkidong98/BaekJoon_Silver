//�κм����� ��(�ǹ� 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int number[20];
int visited[2000001] = { 0, }; //N�� �� 20������ �ǰ� ������ 10�� �����̹Ƿ� �ִ�� ���ص� 200������ �۴�

void possible(int total, int current) {
	if (visited[total] == 0) visited[total] = 1; //total�� ���� ���� �湮 ����� �����
	for (int i = current; i < N; i++) {
		possible(total + number[i], i + 1); //���� ���� �����
	}
}

int main() {
	int temp, result;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}

	possible(0, 0);

	for (result = 1; result<= 2000000; result++) { //�ڿ������ʹϱ� 1���� �����ؼ�
		if (visited[result] == 0) break; //�湮 ǥ�ð� �� �Ǿ� �ִ� ������ ���缭
	}
	
	printf("%d", result); //�ش� ������ ���
}