//ü���� �ٽ� ĥ�ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, row, col, p, q;
	char chess[51][51]; //ü������ �ִ� ũ��� 50 * 50
	int min = 65; //�ִ� ���� 8*8�� 64�̱� ����
	int flag; //Ȧ¦�� �����ϱ� ���� ����
	int count; //�� ���� �ٲپ�� �ϴ����� �����ϴ� ����

	scanf("%d %d", &row, &col);

	//���� �Է� �ޱ�
	for (i = 0; i < row; i++) {
		scanf("%s", chess[i]); //chess[i]�� �ش� �迭�� �ոӸ��� �� ��ü�� �ּҸ� �ǹ��ϱ⿡ &�� ������ �ʾƵ� �ȴ�
	}


	for (i = 0; i <= row - 8; i++) {
		for (j = 0; j <= col - 8; j++) {

			//���� ����� W�� �����Ѵٰ� �����ϰ� ���� ��
			flag = 0; count = 0;
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (flag == 0) {
						if (chess[p][q] != 'W') count++;
						flag = 1;
					}
					else { //flag == 1
						if (chess[p][q] != 'B') count++;
						flag = 0;
					}
				}
				if (flag == 0) flag = 1;
				else flag = 0;
			}
			//������ �ּڰ����� ������ ����
			if (min > count) min = count;

			//���� ����� B�� �����Ѵٰ� �����ϰ� ���� ��
			flag = 1; count = 0;
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (flag == 0) {
						if (chess[p][q] != 'W') count++;
						flag = 1;
					}
					else { //flag == 1
						if (chess[p][q] != 'B') count++;
						flag = 0;
					}
				}
				if (flag == 0) flag = 1;
				else flag = 0;
			}
			//������ �ּڰ����� ������ ����
			if (min > count) min = count;
		}
	}

	printf("%d", min);
}