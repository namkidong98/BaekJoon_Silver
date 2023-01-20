//덩치(실버 5), 브루트 포스
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num, i, j;
	int weight[50] = { 0 };
	int height[50] = { 0 };
	int rank[50] = { 0 };
	scanf("%d", &num);

	//정보 입력 받기(몸무게, 키)
	for (i = 0; i < num; i++) {
		scanf("%d %d", &weight[i], &height[i]);
	}

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (i == j) continue; //동일 인물인 경우는 패스
			if (weight[i] < weight[j] && height[i] < height[j]) rank[i]++;
		}
		rank[i]++; //덩치 등수는 자신보다 덩치 큰 사람이 k명일 때 k+1이 되기 때문
	}

	for (i = 0; i < num; i++) {
		printf("%d ", rank[i]);
	}
}

//몸무게나 키가 동일한 경우에 대해서 처리했을 때 오류가 나왔다. 덩치가 크다는 조건에 대한 정의가 명료할 필요가 있을 것 같다
//if (weight[i] < weight[j] && height[i] <= height[j]) rank[i]++;
//else if (weight[i] == weight[j] && height[i] < height[j]) rank[i]++;