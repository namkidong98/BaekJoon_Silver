//절대값 힙
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //abs함수로 절댓값 계산 가능

int* heap;
int n;

void push(int data) {
	int i = ++n;
	while ((i != 1) && abs(data) <= abs(heap[i / 2])) {
		if (abs(data) == abs(heap[i / 2])) {
			if (data < heap[i / 2]) {
				heap[i] = heap[i / 2];
				i /= 2;
			}
			else break;
		}
		else {
			heap[i] = heap[i / 2];
			i /= 2;
		}
	}
	heap[i] = data;
}

void pop() {
	int item = heap[1];
	int temp = heap[n--];
	int parent = 1;
	int child = 2;
	while (child <= n) {
		if (child < n) {
			if (abs(heap[child]) > abs(heap[child + 1])) child++;
			else if (abs(heap[child]) == abs(heap[child + 1])) {
				if (heap[child] > heap[child + 1]) child++;
			}
		}

		if (abs(temp) < abs(heap[child])) break;
		if (abs(temp) == abs(heap[child])) {
			if (temp < heap[child]) {
				break;
			}
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	printf("%d\n", item);
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
		if (data == 0) {
			if (n == 0) {
				printf("0\n");
			}
			else pop();
		}
		else {
			push(data);
		}
	}
}