//��ȭ���� ��(�ǹ�5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, target, temp;
	int num = 666; //ù��°�� 666���ʹϱ� ���� 0���� �� �ʿ� ���� 666���� ����
	int count = 0; //���° ��ȭ������ ��Ÿ���� ����

	scanf("%d", &target);
	
	while (count != target) {
		temp = num;
		while (temp != 0) {
			if (temp % 1000 == 666) { //1000���� ������ ���� �������� 666�̸� 6�� ���� 3�� ������ ���
				count++;
				break;
			}
			else temp /= 10; //���� ���� �ڸ����� ���������� ���
		}
		num++;
	}
	printf("%d", num - 1); //�������� count == target�̵Ǿ while���� �������� ������ ���� num++�� 1�� �������� �����Ƿ� 1�� ���� �Ѵ�
}