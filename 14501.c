//���(�ǹ�3, ���Ʈ����)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int time;
	int pay;
}job;

int max = 0;
int N;
job day[15];

void count(int today, int pay) {
	if (today == N) {
		if (max < pay) max = pay;
	}

	for (int i = today; i < N; i++) {
		//case1: �ش����� ����� �޴� ���(��������: �ҿ� ���� �� N���� �Ѿ�� �� ��
		if (i + day[i].time <= N) count(i + day[i].time, pay + day[i].pay); //���� �ȿ� �������� �� ������ �ҿ�� �� �ڷ� �Ѿ��

		//case2: �ش����� ����� ���� �ʴ� ���(���� ������ �ȵǵ�, �׳� �Ѿ��)
		else count(i + 1, pay); //��¥�� �Ϸ� ���ϰ� ������ ����
	}
}

int main() {	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &day[i].time, &day[i].pay); // ��¥�� �ҿ�Ǵ� �ð�, ������ �Է� �޴´�
	}
	count(0, 0); //1�Ϻ��� 0���� ���ͺ��� ����
	printf("%d", max);
}