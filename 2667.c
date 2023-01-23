//���� ��ȣ ���̱�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
	int row;
	int col;
}pos;

int bfs(int** matrix, int** visited, int row, int col, int i, int j) {
	pos queue[625]; //���������� �޸� �Ҵ� ���� ���, �ִ� 25 x 25�̹Ƿ� ������ �Է��� �ִ�� 625��
	int front, rear, cur_row, cur_col;
	front = rear = -1;
	
	queue[++rear].row = i; queue[rear].col = j; //�����ϴ� ��ġ

	while (front != rear) { //queue�� �� ������ �ݺ�
		cur_row = queue[++front].row; cur_col = queue[front].col; //queue���� ���ο� ��ġ ��������

		//4 ���⿡�� �̵��� �� �ִ� ������ �ִ��� Ȯ���ϰ� �ִٸ� �ش� ��ġ�� queue�� add
		if (matrix[cur_row + 1][cur_col] == 1 && visited[cur_row + 1][cur_col] == 0) {
			visited[cur_row + 1][cur_col] = 1; //�湮�� ��� �����
			queue[++rear].row = cur_row + 1; queue[rear].col = cur_col; //�̵� ��ġ queue�� add
		}
		if (matrix[cur_row - 1][cur_col] == 1 && visited[cur_row - 1][cur_col] == 0) {
			visited[cur_row - 1][cur_col] = 1; //�湮�� ��� �����
			queue[++rear].row = cur_row - 1; queue[rear].col = cur_col; //�̵� ��ġ queue�� add
		}
		if (matrix[cur_row][cur_col + 1] == 1 && visited[cur_row][cur_col + 1] == 0) {
			visited[cur_row][cur_col + 1] = 1; //�湮�� ��� �����
			queue[++rear].row = cur_row; queue[rear].col = cur_col + 1; //�̵� ��ġ queue�� add
		}
		if (matrix[cur_row][cur_col - 1] == 1 && visited[cur_row][cur_col - 1] == 0) {
			visited[cur_row][cur_col - 1] = 1; //�湮�� ��� �����
			queue[++rear].row = cur_row; queue[rear].col = cur_col - 1; //�̵� ��ġ queue�� add
		}
	}

	return rear + 1; //rear�� �Էµ� ���� ������ �ǹ�
}

int main() {
	int i, j, row, col, min, index, tmp;
	scanf("%d", &row);
	col = row; //���� ���� ����
	char** temp = (char**)malloc(sizeof(char**) * row);
	for (i = 0; i < row; i++) {
		temp[i] = (char*)malloc(sizeof(char) * (col + 1));
		scanf("%s", temp[i]);
	}

	int* group = (int*)malloc(sizeof(int) * row * col); //�������� �ִ� row * col�� ��ŭ ���� �� �ִ�
	for (i = 0; i < row * col; i++) group[i] = 0; //0���� �ʱ�ȭ
	int count = 0; //������ �� ������ �����ϴ� ����
	
	row += 2; col += 2; //�����¿� Ž���� �� �� ���ϱ� ���� �־��� ������ 0���� �ѷ��� ����� ����� ���� row�� col�� ���� 2�� ���Ѵ�
	int** matrix = (int**)malloc(sizeof(int*) * row); //�������� ����(���� ��ġ)�� �����ϴ� ����
	int** visited = (int**)malloc(sizeof(int*) * row); //������ ���� �湮�� �ߴ��� ���θ� �����ϴ� ����
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * row);
		visited[i] = (int*)malloc(sizeof(int) * row);
	}
	//matrix�� visited�� 0���� �ʱ�ȭ
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	//�Է� ���� �������� 1�� ��ġ�� matrix�� �ݿ�
	for (i = 0; i < row - 2; i++) {
		for (j = 0; j < col - 2; j++) {
			if (temp[i][j] == '1') matrix[i + 1][j + 1] = 1;
		}
	}

	for (i = 1; i < row - 1; i++) {
		for (j = 1; j < col - 1; j++) {
			if (matrix[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				group[count++] = bfs(matrix, visited, row, col, i, j);
			}
		}
	}
	printf("%d\n", count); //������ �� ������ ���

	//�� ������ ���� ���� �������� ����
	for (i = 0; i < count - 1; i++) {
		min = group[i];
		index = i;

		for (j = i + 1; j < count; j++) {
			if (group[j] < min) {
				min = group[j];
				index = j;
			}
		}

		//SWAP
		if (i != index) {
			tmp = group[i];
			group[i] = group[index];
			group[index] = tmp;
		}
	}
	for (i = 0; i < count; i++) printf("%d\n", group[i]); //������������ ���ĵ� �� ������ ���� ���� ���

	//����� ���� �Ҵ�� �޸� �����ϱ�
	for (i = 0; i < row; i++) {
		free(matrix[i]);
		free(visited[i]);
		if (i >= row - 2) continue;
		free(temp[i]);
	}
	free(matrix);
	free(visited);
	free(temp);
	free(group);
}