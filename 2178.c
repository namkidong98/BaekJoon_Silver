//미로 탐색
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

	//시작점인 1,1을 queue에 삽입(움직인 거리는 1)
	queue[++rear].row = 1;
	queue[rear].col = 1;
	queue[rear].distance = 1;

	while (front != rear) { //queue가 빌 때까지
		cur_row = queue[++front].row; cur_col = queue[front].col; cur_distance = queue[front].distance; //위치 가져오기
		
		//만약 가져온 위치가 exit이라면 break
		if (cur_row == exit_row && cur_col == exit_col) break;

		//4방향을 조사(해당 길이 열려있고 방문한 적이 없는 경우 --> 방문한 기록을 남기고, 해당 위치를 queue에 add하기)
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
		matrix[i] = (int*)malloc(sizeof(int) * col); //col의 개수만큼 받고 맨 뒤에 \0이 와서 문장의 끝을 의미하기 때문
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