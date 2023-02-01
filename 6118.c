//숨바꼭질(실버 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int vertex;
	node_pointer link;
}node;

node_pointer* group; //해당 vertex와 연결된 vertex들을 저장할 변수
int* visited; //해당 vertex가 방문되었는지를 저장할 변수
int* depth; //해당 vertex가 1로부터 얼마나 떨어져 있는지 거리를 저장할 변수
int N, M; //vertex의 개수와 edge의 개수

void bfs() {
	node_pointer ptr;
	int* queue = (int*)malloc(sizeof(int) * N); //bfs를 쓸 것이기 때문에 최대로 노드 갯수만큼 담을 수 있는 queue를 만들기
	int front, rear, vertex, cur_depth;
	front = rear = -1;

	queue[++rear] = 1;  visited[1] = 1; //1번 노드를 시작점으로 설정
	while (front != rear) {
		vertex = queue[++front]; cur_depth = depth[vertex]; //queue에서 위치를 가져오고 현재 깊이도 cur_depth로 가져온다

		for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) { //해당 vertex에 연결된 지점을 너비 우선 탐색
			if (visited[ptr->vertex] == 0) { //아직 방문되지 않은 vertex만
				queue[++rear] = ptr->vertex; //해당 vertex를 queue에 add
				visited[ptr->vertex] = 1; //방문 기록 남기고
				depth[ptr->vertex] = cur_depth + 1; //해당 vertex의 depth를 갱신
			}
		}
	}

	int count = 0; //최대 depth를 가진 개수를 저장하는 변수
	for (int i = 1; i <= N; i++) { //1번부터 N번까지 반복해서
		if (depth[i] == cur_depth && count == 0) { //각 vertex의 depth가 마지막에 저장된 cur_depth와 동일하고(최대 depth) 최소 vertex일 때
			count++; //개수 1개 증가
			printf("%d %d ", i, cur_depth); //해당 지점을 출력, 해당 지점의 depth도 출력
		}
		else if (depth[i] == cur_depth && count != 0) count++; //첫번째가 아니고 depth만 같은 경우는 count만 증가
	}
	printf("%d", count); //최종적으로 동일 depth를 가진 vertex의 개수를 뜻하는 count를 출력
}

int main() {
	int vertex1, vertex2;
	node_pointer temp;
	
	scanf("%d %d", &N, &M);
	group = (node_pointer*)malloc(sizeof(node_pointer) * (N + 1));
	visited = (int*)malloc(sizeof(int) * (N + 1));
	depth = (int*)malloc(sizeof(int) * (N + 1));
	
	for (int i = 0; i < N + 1; i++) { //사용할 변수들을 초기화
		group[i] = NULL;
		visited[i] = 0;
		depth[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &vertex1, &vertex2);

		//vertex1의 입장에서 vertex2를 연결
		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex2;
		temp->link = group[vertex1];
		group[vertex1] = temp;

		//vertex2의 입장에서 vertex1을 연결
		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex1;
		temp->link = group[vertex2];
		group[vertex2] = temp;
	}

	bfs();
}