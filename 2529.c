//�ε�ȣ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int k;
char ineq[9]; //�ε�ȣ�� 2������ �ִ� 9������ ����
long long max = 0;
long long min = 9999999999;
int number[10]; //�� ���࿡�� ���Ǵ� ���ڴ� 10������ �� �� ����
int min_ans[10];
int max_ans[10];
int use[10]; //0���� 9���� ����ߴ����� ��Ÿ���� ����

void cal(int count) {
	long long total = 0;
	if (count == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			total += pow(10, k - i) * number[i];
		}
		if (total > max) {
			for (int j = 0; j < k + 1; j++) max_ans[j] = number[j];
			max = total;
		}
		if (total < min) {
			for (int j = 0; j < k + 1; j++) min_ans[j] = number[j];
			min = total;
		}
	}
	
	else if (count == 0) {
		for (int i = 0; i < 10; i++) {
			number[count] = i;
			use[i] = 1;
			cal(count + 1);
			use[i] = 0; //��Ͱ� ������ ������ �� �ش� ���࿡�� ������ ������ ���
		}
	} 
	
	else {
		for (int i = 0; i < 10; i++) { //0���� 9������ ���ڵ鿡�� ���� �Ѵ�
			
			if (use[i] == 0) {
				
				if (ineq[count - 1] == '<') {
					if (number[count - 1] < i) {
						number[count] = i;
						use[i] = 1;
						cal(count + 1);
						use[i] = 0;
					}
				}
				else { //'>'
					if (number[count - 1] > i) {
						number[count] = i;
						use[i] = 1;
						cal(count + 1);
						use[i] = 0;
					}
				}

			}
		}
	}
}


int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf(" %c", &ineq[i]);
	}
	for (int i = 0; i < 10; i++)use[i] = 0; //�ʱ�ȭ
	
	cal(0);
	for (int i = 0; i < k + 1; i++) printf("%d", max_ans[i]);
	printf("\n");
	for (int i = 0; i < k + 1; i++)printf("%d", min_ans[i]);
}