//���� ����(�ǹ� 3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int target[10000];
int tmp[10000];

int main() {
	int count = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &target[i]);
	}
	
	int i;
	//�ڿ������� �о �ٷ� ���� index�� �� ���� ��츦 �߰��ϸ� ����� (count�� ������Ű�鼭 �дٰ�)
	for (i = N - 1; i >= 1; i--) {
		if (target[i] < target[i - 1]) count++;
		else break;
	}

	//count�� N-1�̸� �ڿ������� �� �����Ѵٴ� ������ ������ �������� ���ϰ� �̶��� -1�� ����ϰ� �����Ѵ�
	if (count == N - 1) {
		printf("-1");
		return 0;
	}

	//�� �������� ���� index�� �۾��� ���, �� index���� �ٷ� �������� ū ���� �ڿ������� �����鼭 ã�Ƴ� ��
	int next = target[i - 1];
	int index = i;
	int first = 1;
	for (int j = N - 1; j >= i; j--) {
		if (first == 1 && target[j] > next) {
			next = target[j];
			index = j;
			first = 0;
		}
		else if (first == 0 && target[j] < next && target[j] > target[i - 1]) {
			next = target[j];
			index = j;
		}
	}
	
	//�ش� index���� �ٷ� �������� ū ���� ã������ swap�Ѵ�
	int temp = target[i - 1];
	target[i - 1] = target[index];
	target[index] = temp;

	//���� �ش� index(i-1)���� ū�κ��� ����� tmp�� �����Ѵ�
	int k = 0;
	for (int j = N - 1; j >= i; j--) {
		tmp[k++] = target[j];
	}

	//�պκ��� ������ �ʾ����Ƿ� ���� �Է� �޾ƿԴ� target���� �ش� index�� i-1���� �״�� ����ϰ�
	for (int x = 0; x <= i - 1; x++) {
		printf("%d ", target[x]);
	}

	//�� �޺κ��� ����� �����ߴ� tmp�� ���������� ����ϸ� �Է¹��� target ������ �ٷ� ���� ������ �ȴ�
	for (int x = 0; x <= count; x++) {
		printf("%d ", tmp[x]);
	}
}

//��� �Լ��� ����Ͽ� �־��� ������ ã�� �� �ٷ� ���� ������ ����ϴ�, ���Ʈ ���� ������� ã�� ���� �ð��� ���� �ɷ��� �ð��ʰ��� �߻��Ѵ�.