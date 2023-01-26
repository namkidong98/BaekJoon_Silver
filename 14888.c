//�����ڳ����ֱ�(���Ʈ ���� & ��Ʈ��ŷ)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long MAX = -1000000000;
long MIN = 1000000000;

int num;
int operand[11]; //2~11������ ���� �� ����
int operator[4];

void DFS(int plus, int minus, int multiple, int divide, int time, int sum) {
	if (time == num - 1) { //������ �� �Ҹ�
		if (sum > MAX) MAX = sum;
		if (sum < MIN) MIN = sum;
	}

	if (plus > 0) DFS(plus - 1, minus, multiple, divide, time + 1, sum + operand[time + 1]);
	if (minus > 0) DFS(plus, minus - 1, multiple, divide, time + 1, sum - operand[time + 1]);
	if (multiple > 0) DFS(plus, minus, multiple - 1, divide, time + 1, sum * operand[time + 1]);
	if (divide > 0) DFS(plus, minus, multiple, divide - 1, time + 1, sum / operand[time + 1]);
}
//������� plus�� 0���� Ŀ�� plus���� ������ DFS�� ��������� ����ǰ� �� ���࿡ ��� ������ ���� �ش� ���� ����ϰ� �Ʒ��ٷ� ������(plus���Ҿ���)
//�̷� ������� �����ڰ� ���̴� ����� ���� ���� ���������� counting�� �ʿ� ���� ����Ѵ�

int main() {
	scanf("%d", &num);
	for (int i = 0; i < num; i++) { //�ǿ����� �Է� �ޱ�
		scanf("%d", &operand[i]);
	}
	for (int i = 0; i < 4; i++) { //�� ������ ���� �Է� �ޱ�
		scanf("%d", &operator[i]);
	}

	DFS(operator[0], operator[1], operator[2], operator[3], 0, operand[0]);
	printf("%d\n%d", MAX, MIN);
}