//최소 힙 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* heap;
int n = 0; //heap에 들어있는 노드의 개수

void push(int data) {
	int i = ++n;
	while ((i != 1) && data < heap[i / 2]) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = data;
}

void pop() {
	int min = heap[1];
	int temp = heap[n--];
	int parent = 1;
	int child = 2;
	while (child <= n) {
		if ((child < n) && heap[child] > heap[child + 1]) child++;
		if (temp <= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;

	printf("%d\n", min);
}

int main() {
	int command, i, data;
	scanf("%d", &command);
	heap = (int*)malloc(sizeof(int) * (command + 1));
	for (i = 0; i < command + 1; i++) {
		heap[i] = 0;
	}
	for (i = 0; i < command; i++) {
		scanf("%d", &data);
		if (data == 0) { //pop
			if (n == 0) {
				printf("0\n");
			}
			else pop();
		}
		else { //push
			push(data);
		}
	}
}