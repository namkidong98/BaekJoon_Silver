//���� ����Ʈ(�׷���, �ǹ�1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int distance;
}pos;

dr[6] = { -2, -2, 0, 0, 2, 2}; //row���� 6���� ���⿡ ���� ��ȭ��
dc[6] = { -1, 1, -2, 2, -1, 1}; //col���� 6���� ���⿡ ���� ��ȭ��

int bfs(int row, int col, pos start, pos end) {
	pos* queue = (pos*)malloc(sizeof(pos) * row * col); //��ǥ�� ���� �� �ִ� ť�� ���� �Ҵ�
	int** visited = (int**)malloc(sizeof(int*) * row); //�湮 ������ ���� �� �ִ� �޸𸮸� ���� �Ҵ�
	for (int i = 0; i < row; i++)visited[i] = (int*)malloc(sizeof(int) * col);
	int front, rear, dir; front = rear = -1; pos cur, next;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visited[i][j] = 0; //�湮 ���� ������ �ʱ�ȭ
		}
	}

	// �������� queue�� add
	queue[++rear].row = start.row; queue[rear].col = start.col; queue[rear].distance = 0; visited[start.row][start.col] = 1; 

	while (front != rear) {
		cur.row = queue[++front].row; cur.col = queue[front].col; cur.distance = queue[front].distance; //queue���� ���ο� ��ġ ��������

		if ((cur.row == end.row) && (cur.col == end.col)) break; //���� ����(������ ��ġ�� �������� ��ġ)

		dir = 0; //ó�� ������� ����
		while (dir < 6) { //�� ������ 6������ �����Ƿ�
			next.row = cur.row + dr[dir]; next.col = cur.col + dc[dir]; next.distance = cur.distance + 1; //���� ��ǥ�� ���غ���
			if (next.row >= 0 && next.row < row && next.col >=0 && next.col < col) { //ü���� ���� �ȿ� ������
				if (visited[next.row][next.col] == 0) { //�ش� ��ǥ�� �湮���� �ʾ����� --> �̹� �湮�� ���� �� ���ٴ� ���� distance�� ���鿡�� �̹� �ּ� ���� �ƴϴ�(�����ؾ� �Ѵ�)
					visited[next.row][next.col] = 1; //�湮 ��� �����
					queue[++rear].row = next.row; queue[rear].col = next.col; queue[rear].distance = cur.distance + 1; //�ش� ��ġ�� queue�� add
				}
			}
			dir++; //���� �������� �Ѿ�鼭
		}

	}

	if ((cur.row == end.row) && (cur.col == end.col)) return cur.distance; //���� ���ǿ� �¾� while loop�� ���� ���, �ּ� �̵� Ƚ�� ��ȯ
	else return -1; //�̵��� �� ���� ���, -1 ��ȯ
}

int main() {
	pos start, end; int row, col;
	scanf("%d", &row);
	col = row;
	scanf("%d %d %d %d", &start.row, &start.col, &end.row, &end.col);

	printf("%d", bfs(row, col, start, end));
}