//반전 요세푸스
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, temp;
	int N, K, M; //N명, K번째 사람, M명이 제거될 때마다 반대로
	int* queue;
	int front, rear, dir, end;
	front = rear = -1;
	dir = 0; //dir은 회전 방향을 나타내면 0일때는 시계방향, 1일때는 반시계방향
	end = 0; //1이 되면 종료하는 시그널

	scanf("%d %d %d", &N, &K, &M);
	queue = (int*)malloc(sizeof(int) * N * N);
	
	//초기 값 설정
	for (i = 0; i < N; i++) {
		queue[++rear] = i + 1;
	}
	
	while (1) {
		if (dir == 0) {
			for (j = 0; j < M; j++) {
				for (i = 0; i < K - 1; i++) {
					queue[++rear] = queue[++front];
				}
				printf("%d\n", queue[++front]);
				if (front == rear) { //종료 조건
					end = 1;
					break;
				}
			}
			if (end == 1) break;
			dir = 1; //M번째 이후에는 도는 방향을 바꿈
		}
		else { //dir이 1이어서 반시계로 도는 경우
			for (j = 0; j < M; j++) {
				for (i = 0; i < K - 1; i++) {
					queue[front--] = queue[rear--]; //rear과 front를 반대로 작동시키는 방식으로 구현
				}
				printf("%d\n", queue[rear--]);
				if (front == rear) { //종료 조건
					end = 1;
					break;
				}
			}
			if (end == 1) break;
			dir = 0; //M번째 이후에는 도는 방향을 바꿈
		}
	}
}