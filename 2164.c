//카드 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, num;
	int* queue;
	int front, rear;
	front = rear = -1;
	scanf("%d", &num);
	queue = (int*)malloc(sizeof(int) * num * 2); //뒤로 옮기는 과정을 담을 수 있도록 num보다 더 큰 범위의 queue가 필요
	
	//1부터 N까지 차례대로 add_queue
	for (i = 0; i < num; i++) {
		queue[++rear] = i + 1;
	}

	while (front != rear - 1) { //한장 남을때 까지
		//제일 위의 카드 버리기
		front++; //front가 위치한 곳은 없는 취급
		//그 다음 제일 위의 카드를 제일 아래로 옮긴다
		queue[++rear] = queue[++front];
	}
	printf("%d", queue[rear]);

	free(queue);
}