//DFS와 BFS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int vertex;
	node_pointer link;
}node;

node_pointer group[1001];
int visited[1001];

int stack[1001];
int top = -1;

int queue[1001];
int front, rear;

void dfs(int vertex) {
	node_pointer ptr;
	printf("%d ", vertex);
	visited[vertex] = 1;
	for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) {
		if (visited[ptr->vertex] == 0) { //방문하지 않은 노드이면
			dfs(ptr->vertex);
		}
	}
}

void bfs(int vertex) {
	node_pointer ptr;
	front = rear = -1;
	printf("%d ", vertex);
	visited[vertex] = 1;
	queue[++rear] = vertex; //add_queue
	while (front != rear) {
		ptr = group[queue[++front]]; //delete_queue
		for (; ptr != NULL; ptr = ptr->link) {
			if (visited[ptr->vertex] == 0) { //방문하지 않은 노드이면
				visited[ptr->vertex] = 1; // 방문한 것으로 표시
				printf("%d ", ptr->vertex); 
				queue[++rear] = ptr->vertex; //해당 노드를 큐에 add
			}
		}
	}

}

int main() {
	int i, num_of_node, num_of_edge, start, vertex1, vertex2;
	node_pointer ptr = NULL;
	node_pointer trail = NULL;
	
	scanf("%d %d %d", &num_of_node, &num_of_edge, &start);

	
	for (i = 0; i < 1001; i++) {
		group[i] = NULL;
		visited[i] = 0; //방문하지 않음
	}
	node_pointer temp;


	for (i = 0; i < num_of_edge; i++) {
		scanf("%d %d", &vertex1, &vertex2);

		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex2;
		trail = NULL;
		if (group[vertex1] != NULL) { //연결된 간선이 하나라도 있으면 (정점의 번호가 더 작은 쪽이 앞에 오도록 연결하기)
			for (ptr = group[vertex1]; ptr != NULL;) {
				if (temp->vertex < ptr->vertex) break;
				trail = ptr;
				ptr = ptr->link;
			}
			if (trail == NULL) { //제일 앞에 temp가 와야하는 상황
				temp->link = group[vertex1];
				group[vertex1] = temp;
			}
			else {
				trail->link = temp;
				temp->link = ptr;
			}
		}
		else { //연결된 간선이 없으면 (그냥 덧붙이면 됨)
			temp->link = group[vertex1];
			group[vertex1] = temp;
		}
		

		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex1;
		trail = NULL;
		if (group[vertex2] != NULL) { //연결된 간선이 하나라도 있으면 (정점의 번호가 더 작은 쪽이 앞에 오도록 연결하기)
			for (ptr = group[vertex2]; ptr != NULL;) {
				if (temp->vertex < ptr->vertex) break;
				trail = ptr;
				ptr = ptr->link;
			}
			if (trail == NULL) { //제일 앞에 temp가 와야하는 상황
				temp->link = group[vertex2];
				group[vertex2] = temp;
			}
			else {
				trail->link = temp;
				temp->link = ptr;
			}
			
		}
		else { //연결된 간선이 없으면 (그냥 덧붙이면 됨)
			temp->link = group[vertex2];
			group[vertex2] = temp;
		}
	}
	
	dfs(start);
	for (i = 0; i < 1001; i++) {
		visited[i] = 0;
	}
	printf("\n");
	bfs(start);
	
}