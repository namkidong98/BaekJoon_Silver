//프린터 큐(실버3, 큐 응용)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int calculate(int num, int index, int* imp, int max) {
	int front, rear, i;
	int count = 0; //몇번째 출력인지 나타내는 지표
	front = -1;
	rear = num - 1;
	while (1) { 
		if (imp[++front] < max) { //중요도가 더 높은게 있으면
			imp[++rear] = imp[front]; //출력하지 않고 뒤로 넘긴다
			if (index == front) index = rear;
		}
		else { //더 높은 중요도가 없으면 --> 출력해야 한다
			count++;
			if (front == index) break;
			//중요도의 최댓값 갱신
			max = imp[front + 1];
			for (i = front + 1; i <= rear; i++) {
				if (imp[i] > max) max = imp[i];
			}
		}
	}
	return count;
}

int main() {
	int testcase, i, j; 
	int num, index; //문서의 개수, 궁금한 문서의 queue에서의 순서(0부터)
	int* imp; //문서의 중요도(queue의 역할)
	int result;
	int max = 0;

	scanf("%d", &testcase); //테스트 케이스 개수 입력
	for (i = 0; i < testcase; i++) {
		//테스트 케이스에 필요한 정보 입력 받기(문서 개수, 궁금한 문서의 순서, 문서마다의 중요도)
		scanf("%d %d", &num, &index); 
		imp = (int*)malloc(sizeof(int) * num * num);
		for (j = 0; j < num; j++) {
			scanf("%d", &imp[j]); //0부터 문서마다의 중요도
			if (max < imp[j]) max = imp[j];
		}
		result = calculate(num, index, imp, max);
		printf("%d\n", result);
		max = 0; //다음 시행을 위한 초기화
	}
}