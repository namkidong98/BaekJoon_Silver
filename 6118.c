//���ٲ���(�ǹ� 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int vertex;
	node_pointer link;
}node;

node_pointer* group; //�ش� vertex�� ����� vertex���� ������ ����
int* visited; //�ش� vertex�� �湮�Ǿ������� ������ ����
int* depth; //�ش� vertex�� 1�κ��� �󸶳� ������ �ִ��� �Ÿ��� ������ ����
int N, M; //vertex�� ������ edge�� ����

void bfs() {
	node_pointer ptr;
	int* queue = (int*)malloc(sizeof(int) * N); //bfs�� �� ���̱� ������ �ִ�� ��� ������ŭ ���� �� �ִ� queue�� �����
	int front, rear, vertex, cur_depth;
	front = rear = -1;

	queue[++rear] = 1;  visited[1] = 1; //1�� ��带 ���������� ����
	while (front != rear) {
		vertex = queue[++front]; cur_depth = depth[vertex]; //queue���� ��ġ�� �������� ���� ���̵� cur_depth�� �����´�

		for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) { //�ش� vertex�� ����� ������ �ʺ� �켱 Ž��
			if (visited[ptr->vertex] == 0) { //���� �湮���� ���� vertex��
				queue[++rear] = ptr->vertex; //�ش� vertex�� queue�� add
				visited[ptr->vertex] = 1; //�湮 ��� �����
				depth[ptr->vertex] = cur_depth + 1; //�ش� vertex�� depth�� ����
			}
		}
	}

	int count = 0; //�ִ� depth�� ���� ������ �����ϴ� ����
	for (int i = 1; i <= N; i++) { //1������ N������ �ݺ��ؼ�
		if (depth[i] == cur_depth && count == 0) { //�� vertex�� depth�� �������� ����� cur_depth�� �����ϰ�(�ִ� depth) �ּ� vertex�� ��
			count++; //���� 1�� ����
			printf("%d %d ", i, cur_depth); //�ش� ������ ���, �ش� ������ depth�� ���
		}
		else if (depth[i] == cur_depth && count != 0) count++; //ù��°�� �ƴϰ� depth�� ���� ���� count�� ����
	}
	printf("%d", count); //���������� ���� depth�� ���� vertex�� ������ ���ϴ� count�� ���
}

int main() {
	int vertex1, vertex2;
	node_pointer temp;
	
	scanf("%d %d", &N, &M);
	group = (node_pointer*)malloc(sizeof(node_pointer) * (N + 1));
	visited = (int*)malloc(sizeof(int) * (N + 1));
	depth = (int*)malloc(sizeof(int) * (N + 1));
	
	for (int i = 0; i < N + 1; i++) { //����� �������� �ʱ�ȭ
		group[i] = NULL;
		visited[i] = 0;
		depth[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &vertex1, &vertex2);

		//vertex1�� ���忡�� vertex2�� ����
		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex2;
		temp->link = group[vertex1];
		group[vertex1] = temp;

		//vertex2�� ���忡�� vertex1�� ����
		temp = (node_pointer)malloc(sizeof(node));
		temp->vertex = vertex1;
		temp->link = group[vertex2];
		group[vertex2] = temp;
	}

	bfs();
}