//최대 힙
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void deletion(int* heap, int* count) { //위에서 아래로 내려오는 과정
	int item = heap[1]; //제거할 제일 상단의 노드
	int temp = heap[(*count)--]; //마지막 번째의 노드
	int parent = 1;
	int child = 2;

	while (child <= *count) {
		if ((child < *count) && heap[child] < heap[child + 1]) child++; //좌측보다 우측이 크면 우측으로 변경
		if (temp > heap[child]) break; //
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	printf("%d\n", item);
}

void insertion(int* heap, int data, int* count) { //아래에서 위로 올라오는 과정
	int parent, child;
	int i = ++(*count);
	while ((i != 1) && data > heap[i / 2]) { //parent보다 값이 크면
		heap[i] = heap[i / 2]; //기존 자리에 parent를 내리고
		i /= 2; //원래 parent 자리로 올리간다
	}
	heap[i] = data;
}

int main() {
	int num, i, data;
	int* heap;
	int count = 0;
	scanf("%d", &num);

	//힙 초기화
	heap = (int*)malloc(sizeof(int) * (num + 1));
	for (i = 0; i <= num; i++) {
		heap[i] = 0;
	}

	for (i = 0; i < num; i++) {
		scanf("%d", &data);
		if (data == 0) { //delete(pop)
			if (count == 0) { //힙에 값이 없는 경우
				printf("0\n");
			}
			else { //힙에 값이 있는 경우 --> 최대 값을 출력(heap[0])
				deletion(heap, &count);
			}
		}
		else { //insert
			insertion(heap, data, &count);
		}
	}
}