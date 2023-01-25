//연결 요소의 개수(너비 우선 탐색, 실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int index;
	node_pointer link;
}node;

node_pointer* group;
int* visited;

void dfs(int vertex) {
	node_pointer ptr;
	visited[vertex] = 1;
	//printf("%d ", vertex);
	for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) {
		if (visited[ptr->index] == 0) {
			dfs(ptr->index);
		}
	}
}

int bfs(int num_of_vertex) {
	int* queue = (int*)malloc(sizeof(int) * num_of_vertex);
	int front, rear, i;	node_pointer ptr;
	front = rear = -1; int count = 0;

	for (i = 1; i <= num_of_vertex; i++) {
		if (visited[i] == 0) {
			queue[++rear] = i; visited[i] = 1;
			while (front != rear) {
				ptr = group[queue[++front]]; 
				for (; ptr != NULL; ptr = ptr->link) {
					if (visited[ptr->index] == 0) {
						visited[ptr->index] = 1;
						queue[++rear] = ptr->index;
					}
				}
			}
			count++;
		}
	}
	return count;
}

int main() {
	int N, M, i, vertex1, vertex2; node_pointer temp;
	int count = 0;

	scanf("%d %d", &N, &M);
	group = (node_pointer*)malloc(sizeof(node_pointer) * (N + 1)); //vertex 개수에 맞춰 동적 할당
	visited = (int*)malloc(sizeof(int) * (N + 1));
	for (i = 0; i < N + 1; i++) {
		group[i] = NULL; //초기화
		visited[i] = 0; //방문하지 않음으로 초기화
	}
	
	for (i = 0; i < M; i++) {
		scanf("%d %d", &vertex1, &vertex2);
	
		temp = (node_pointer)malloc(sizeof(node));
		temp->index = vertex2;
		temp->link = group[vertex1];
		group[vertex1] = temp;

		temp = (node_pointer)malloc(sizeof(node));
		temp->index = vertex1;
		temp->link = group[vertex2];
		group[vertex2] = temp;
	}

	/*
	for (i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i);
			//printf("\n");
			count++;
		}
	}
	*/

	count = bfs(N);

	printf("%d", count);
}
//dfs로 했을 때는 256ms가 나왔고 bfs로 했을 때는 236ms가 나왔다