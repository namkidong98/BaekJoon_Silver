//��ġ(�ǹ� 5), ���Ʈ ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num, i, j;
	int weight[50] = { 0 };
	int height[50] = { 0 };
	int rank[50] = { 0 };
	scanf("%d", &num);

	//���� �Է� �ޱ�(������, Ű)
	for (i = 0; i < num; i++) {
		scanf("%d %d", &weight[i], &height[i]);
	}

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (i == j) continue; //���� �ι��� ���� �н�
			if (weight[i] < weight[j] && height[i] < height[j]) rank[i]++;
		}
		rank[i]++; //��ġ ����� �ڽź��� ��ġ ū ����� k���� �� k+1�� �Ǳ� ����
	}

	for (i = 0; i < num; i++) {
		printf("%d ", rank[i]);
	}
}

//�����Գ� Ű�� ������ ��쿡 ���ؼ� ó������ �� ������ ���Դ�. ��ġ�� ũ�ٴ� ���ǿ� ���� ���ǰ� ����� �ʿ䰡 ���� �� ����
//if (weight[i] < weight[j] && height[i] <= height[j]) rank[i]++;
//else if (weight[i] == weight[j] && height[i] < height[j]) rank[i]++;