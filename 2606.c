//바이러스(실버3), 그래프와 순회
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int index;
	node_pointer link;
}node;

node_pointer* group;
int* visited; //해당 정점을 방문했는지 나타내는 변수
int count = 0; //1과 접해있는 정점의 개수

void dfs(int vertex) {
	node_pointer ptr;
	visited[vertex] = 1;
	count++; //1과 접해있는 노드의 개수를 증가시킨다

	for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) {
		if (visited[ptr->index] == 0) {
			dfs(ptr->index);
		}
	}
}

int main() {
	int num_vertex, num_edge, vertex1, vertex2, i;
	node_pointer temp, ptr;

	//정점 개수 입력 받아서 group 동적 할당하기
	scanf("%d", &num_vertex);
	group = (node_pointer*)malloc(sizeof(node_pointer) * (num_vertex + 1));
	visited = (int*)malloc(sizeof(int) * (num_vertex + 1));
	for (i = 0; i < num_vertex + 1; i++) {
		group[i] = NULL;
		visited[i] = 0; //방문하지 않았다는 의미
	}

	//간선 입력 받아서 정보 저장하기
	scanf("%d", &num_edge);
	for (i = 0; i < num_edge; i++) {
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

	dfs(1); //깊이 우선 탐색으로 1과 연결된 컴퓨터들의 개수를 센다
	printf("%d", count - 1); //count에는 1도 포함되는데 원하는 정답은 1을 통해 감염되는 컴퓨터 수이니 1개를 뺀다
}