//�̷� Ž��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
	int row;
	int col;
	int distance;
}pos;

int maze(int** matrix, int** visited, int row, int col) {
	pos* queue = (pos*)malloc(sizeof(pos) * row * col);
	int front, rear, cur_row, cur_col, cur_distance; 
	front = rear = -1;
	int exit_row = row - 2; int exit_col = col - 2;

	//�������� 1,1�� queue�� ����(������ �Ÿ��� 1)
	queue[++rear].row = 1;
	queue[rear].col = 1;
	queue[rear].distance = 1;

	while (front != rear) { //queue�� �� ������
		cur_row = queue[++front].row; cur_col = queue[front].col; cur_distance = queue[front].distance; //��ġ ��������
		
		//���� ������ ��ġ�� exit�̶�� break
		if (cur_row == exit_row && cur_col == exit_col) break;

		//4������ ����(�ش� ���� �����ְ� �湮�� ���� ���� ��� --> �湮�� ����� �����, �ش� ��ġ�� queue�� add�ϱ�)
		if (matrix[cur_row + 1][cur_col] == 1 && visited[cur_row + 1][cur_col] == 0) {
			visited[cur_row + 1][cur_col] = 1;
			queue[++rear].row = cur_row + 1; queue[rear].col = cur_col; queue[rear].distance = cur_distance + 1;
		}
		if (matrix[cur_row - 1][cur_col] == 1 && visited[cur_row - 1][cur_col] == 0) {
			visited[cur_row - 1][cur_col] = 1;
			queue[++rear].row = cur_row - 1; queue[rear].col = cur_col; queue[rear].distance = cur_distance + 1;
		}
		if (matrix[cur_row][cur_col + 1] == 1 && visited[cur_row][cur_col + 1] == 0) {
			visited[cur_row][cur_col + 1] = 1;
			queue[++rear].row = cur_row; queue[rear].col = cur_col + 1; queue[rear].distance = cur_distance + 1;
		}
		if (matrix[cur_row][cur_col - 1] == 1 && visited[cur_row][cur_col - 1] == 0) {
			visited[cur_row][cur_col - 1] = 1;
			queue[++rear].row = cur_row; queue[rear].col = cur_col - 1; queue[rear].distance = cur_distance + 1;
		}
	}

	return cur_distance;
}

int main() {
	int row, col, i, j;
	scanf("%d %d", &row, &col);
	char** temp = (char**)malloc(sizeof(char*) * row);
	for (i = 0; i < row; i++) {
		temp[i] = (char*)malloc(sizeof(char) * (col + 1));
	}
	for (i = 0; i < row; i++) scanf("%s", temp[i]);

	row = row + 2;
	col = col + 2;
	int** matrix = (int**)malloc(sizeof(int*) * row);
	int** visited = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * col); //col�� ������ŭ �ް� �� �ڿ� \0�� �ͼ� ������ ���� �ǹ��ϱ� ����
		visited[i] = (int*)malloc(sizeof(int) * col);
	}
	
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			visited[i][j] = 0;
			matrix[i][j] = 0;
		}
	}
	for (i = 0; i < row - 2; i++) {
		for (j = 0; j < col - 2; j++) {
			if(temp[i][j] == '1') matrix[i + 1][j + 1] = 1;
		}
	}

	printf("%d", maze(matrix, visited, row, col));
}