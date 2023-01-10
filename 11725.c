#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int index;
	node_pointer link;
}node;

int* parent;
node_pointer* graph;

void dfs(int i) {
	node_pointer ptr;
	for (ptr = graph[i]; ptr != NULL; ptr = ptr->link) {
		if (parent[ptr->index] == 0) {
			parent[ptr->index] = i;
			dfs(ptr->index);
		}
	}
}

int main() {
	node_pointer temp;
	int i, j, num, a, b, flag;

	scanf("%d", &num);
	parent = (int*)malloc(sizeof(int) * (num + 1));
	graph = (node_pointer*)malloc(sizeof(node_pointer) * (num + 1));
	for (i = 0; i < num + 1; i++) {
		parent[i] = 0;
		graph[i] = NULL;
	}
	parent[0] = 1;
	parent[1] = 1;

	//값 입력 받기
	for (i = 0; i < num - 1; i++) {
		scanf("%d %d", &a, &b);
		//a에서 b로의 간선 저장
		temp = (node_pointer)malloc(sizeof(node));
		temp->index = b;
		temp->link = graph[a];
		graph[a] = temp;
		//b에서 a로의 간선 저장
		temp = (node_pointer)malloc(sizeof(node));
		temp->index = a;
		temp->link = graph[b];
		graph[b] = temp;
	}

	//graph를 1부터 시작으로 돌면서 parent를 설정하기
	dfs(1);

	for (i = 2; i < num + 1; i++) {
		printf("%d ", parent[i]);
	}
}