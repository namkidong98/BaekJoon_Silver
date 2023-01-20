//유기농 배추(실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct position {
	int row;
	int col;
}position;

int t_row, t_col;
int** matrix;
int** visited;

void bfs(int row, int col) {
	position* queue = (position*)malloc(sizeof(position) * (t_row + 2) * (t_col + 2));
	int front = -1;
	int rear = -1;
	int cur_row, cur_col;
	queue[++rear].row = row; queue[rear].col = col;
	while (front != rear) { //queue가 빌 때까지
		cur_row = queue[++front].row; cur_col = queue[front].col; //현재 위치 가져오기

		if (matrix[cur_row - 1][cur_col] == 1 && visited[cur_row - 1][cur_col] == 0) {
			visited[cur_row - 1][cur_col] = 1;
			queue[++rear].row = cur_row - 1; queue[rear].col = cur_col;
		}
		if (matrix[cur_row + 1][cur_col] == 1 && visited[cur_row + 1][cur_col] == 0) {
			visited[cur_row + 1][cur_col] = 1;
			queue[++rear].row = cur_row + 1; queue[rear].col = cur_col;
		}
		if (matrix[cur_row][cur_col - 1] == 1 && visited[cur_row][cur_col - 1] == 0) {
			visited[cur_row][cur_col - 1] = 1;
			queue[++rear].row = cur_row; queue[rear].col = cur_col - 1;
		}
		if (matrix[cur_row][cur_col + 1] == 1 && visited[cur_row][cur_col + 1] == 0) {
			visited[cur_row][cur_col + 1] = 1;
			queue[++rear].row = cur_row; queue[rear].col = cur_col + 1;
		}
	}
}

int calculate(int width, int height, int terms) {
	int x, y, i, j;
	int count = 0; //필요한 배추 흰지렁이의 마리수 

	//매트릭스 만들기(가로는 col이 되고 세로는 row가 된다)
	t_row = height; t_col = width;
	matrix = (int**)malloc(sizeof(int*) * (t_row + 2)); //visited에서 상하좌우를 탐색할 때 벽쪽에 있어서 오류가 나오는 경우를 배제하기 위해
	for (i = 0; i < t_row + 2; i++) matrix[i] = (int*)malloc(sizeof(int) * (t_col + 2));
	visited = (int**)malloc(sizeof(int*) * (t_row + 2)); //visited에서 상하좌우를 탐색할 때 벽쪽에 있어서 오류가 나오는 경우를 배제하기 위해
	for (i = 0; i < t_row + 2; i++) visited[i] = (int*)malloc(sizeof(int) * (t_col + 2));

	for (i = 0; i < t_row + 2; i++) {
		for (j = 0; j < t_col + 2; j++) {
			matrix[i][j] = 0; //0으로 초기화(배추가 안 심어져 있다)
			visited[i][j] = 0;
		}
	}

	//terms들의 정보를 2차원 matrix에 저장
	for (i = 0; i < terms; i++) {
		scanf("%d %d", &x, &y); //배추의 x좌표, y좌표
		matrix[y + 1][x + 1] = 1; //1은 배추가 심어져 있다는 의미
	}

	//실질적인 matrix의 사이즈는 1부터 row-1, 1부터 col-1이다
	for (i = 1; i < t_row + 2; i++) {
		for (j = 1; j < t_col + 2; j++) {
			if (matrix[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				count++; //상하좌우 모두 방문된 흔적이 없는 곳(인접한 곳이 없는)은 지렁이가 필요
			}
		}
	}
	
	return count;
}

int main() {
	int i, testcase, width, height, terms, result;

	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++) {
		scanf("%d %d %d", &width, &height, &terms);
		result = calculate(width, height, terms);
		printf("%d\n", result);
	}
}