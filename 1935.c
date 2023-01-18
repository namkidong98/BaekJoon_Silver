//�ı� ǥ��� 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num, i;
	char string[101]; //�Է��� �޴� ����, ���̴� 100�� ���� �ʴ´�
	int prefix[101]; //�Է� ���� ����ǥ����� ���ĺ��� ���ڷ� ��ȯ�Ͽ� ���� string, 0�� ������, �������� �ǿ����ڸ� �ǹ�
	int alphabet[26]; //������ ���ĺ��� �ԷµǴ� ���ڸ� �����ϴ� ����

	//�� �Է� �ޱ�
	scanf("%d", &num);
	scanf("%s", string);
	int len = strlen(string);
	for (i = 0; i < num; i++) {
		scanf("%d", &alphabet[i]);
	}

	//���ڿ� �����ڷ� �̷���� string���� ��ȯ
	for (i = 0; i < len; i++) {
		if (string[i] >= 65 && string[i] <= 90) { //A~Z�� ���빮���̸�
			prefix[i] = alphabet[string[i] - 65]; //�ǿ����ڸ� ��¡
		}
		else prefix[i] = 0; //�����ڸ� ��¡
	}
	double stack[101];
	int top = -1;
	double operand1, operand2;

	for (i = 0; i < len; i++) {
		if (prefix[i] != 0) { //�ǿ�����
			stack[++top] = (double)prefix[i];
		}
		else { //������(�ƽ�Ű�ڵ� ���� 37�̻�
			operand2 = stack[top--]; //pop
			operand1 = stack[top--]; //pop
			if (string[i] == '+') {
				stack[++top] = operand1 + operand2;
			}
			else if (string[i] == '-') {
				stack[++top] = operand1 - operand2;
			}
			else if (string[i] == '*') {
				stack[++top] = operand1 * operand2;
			}
			else if (string[i] == '/') {
				stack[++top] = operand1 / operand2;
			}
			//% �����ڴ� ��� ���� ����
		}
	}
	printf("%.2lf", stack[0]); //�Ҽ��� ��°�ڸ����� ���
}
//������: float�� �ƴ� double�� �ڷ����� �����ؾ� �Ѵ�