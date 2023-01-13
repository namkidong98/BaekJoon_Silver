//요세푸스 문제 0(실버 5): 큐 제거
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, num, target;
	int* queue;
	int front, rear;
	front = rear = -1;
	scanf("%d %d", &num, &target);

	//초기 값 설정
	queue = (int*)malloc(sizeof(int) * num * num);
	for (i = 0; i < num; i++) {
		queue[++rear] = i + 1;
	}

	printf("<");
	for (i = 0; i < num; i++) {
		for (j = 0; j < target - 1; j++) {
			queue[++rear] = queue[++front];//target이전까지 앞에꺼를 뒤에 넘긴다
		}
		if (rear - front == 1) printf("%d", queue[++front]);
		else printf("%d, ", queue[++front]);
	}
	printf(">");
}
