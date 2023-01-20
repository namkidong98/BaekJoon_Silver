//���̷���(�ǹ�3), �׷����� ��ȸ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	int index;
	node_pointer link;
}node;

node_pointer* group;
int* visited; //�ش� ������ �湮�ߴ��� ��Ÿ���� ����
int count = 0; //1�� �����ִ� ������ ����

void dfs(int vertex) {
	node_pointer ptr;
	visited[vertex] = 1;
	count++; //1�� �����ִ� ����� ������ ������Ų��

	for (ptr = group[vertex]; ptr != NULL; ptr = ptr->link) {
		if (visited[ptr->index] == 0) {
			dfs(ptr->index);
		}
	}
}

int main() {
	int num_vertex, num_edge, vertex1, vertex2, i;
	node_pointer temp, ptr;

	//���� ���� �Է� �޾Ƽ� group ���� �Ҵ��ϱ�
	scanf("%d", &num_vertex);
	group = (node_pointer*)malloc(sizeof(node_pointer) * (num_vertex + 1));
	visited = (int*)malloc(sizeof(int) * (num_vertex + 1));
	for (i = 0; i < num_vertex + 1; i++) {
		group[i] = NULL;
		visited[i] = 0; //�湮���� �ʾҴٴ� �ǹ�
	}

	//���� �Է� �޾Ƽ� ���� �����ϱ�
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

	dfs(1); //���� �켱 Ž������ 1�� ����� ��ǻ�͵��� ������ ����
	printf("%d", count - 1); //count���� 1�� ���ԵǴµ� ���ϴ� ������ 1�� ���� �����Ǵ� ��ǻ�� ���̴� 1���� ����
}