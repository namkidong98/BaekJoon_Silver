//단지 번호 붙이기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
	int row;
	int col;
}pos;

int bfs(int** matrix, int** visited, int row, int col, int i, int j) {
	pos queue[625]; //지역변수로 메모리 할당 없이 사용, 최대 25 x 25이므로 가능한 입력의 최대는 625개
	int front, rear, cur_row, cur_col;
	front = rear = -1;
	
	queue[++rear].row = i; queue[rear].col = j; //시작하는 위치

	while (front != rear) { //queue가 빌 때까지 반복
		cur_row = queue[++front].row; cur_col = queue[front].col; //queue에서 새로운 위치 가져오기

		//4 방향에서 이동할 수 있는 지점이 있는지 확인하고 있다면 해당 위치를 queue에 add
		if (matrix[cur_row + 1][cur_col] == 1 && visited[cur_row + 1][cur_col] == 0) {
			visited[cur_row + 1][cur_col] = 1; //방문한 기록 남기기
			queue[++rear].row = cur_row + 1; queue[rear].col = cur_col; //이동 위치 queue에 add
		}
		if (matrix[cur_row - 1][cur_col] == 1 && visited[cur_row - 1][cur_col] == 0) {
			visited[cur_row - 1][cur_col] = 1; //방문한 기록 남기기
			queue[++rear].row = cur_row - 1; queue[rear].col = cur_col; //이동 위치 queue에 add
		}
		if (matrix[cur_row][cur_col + 1] == 1 && visited[cur_row][cur_col + 1] == 0) {
			visited[cur_row][cur_col + 1] = 1; //방문한 기록 남기기
			queue[++rear].row = cur_row; queue[rear].col = cur_col + 1; //이동 위치 queue에 add
		}
		if (matrix[cur_row][cur_col - 1] == 1 && visited[cur_row][cur_col - 1] == 0) {
			visited[cur_row][cur_col - 1] = 1; //방문한 기록 남기기
			queue[++rear].row = cur_row; queue[rear].col = cur_col - 1; //이동 위치 queue에 add
		}
	}

	return rear + 1; //rear이 입력된 집의 개수를 의미
}

int main() {
	int i, j, row, col, min, index, tmp;
	scanf("%d", &row);
	col = row; //열과 행은 동일
	char** temp = (char**)malloc(sizeof(char**) * row);
	for (i = 0; i < row; i++) {
		temp[i] = (char*)malloc(sizeof(char) * (col + 1));
		scanf("%s", temp[i]);
	}

	int* group = (int*)malloc(sizeof(int) * row * col); //단지수는 최대 row * col개 만큼 있을 수 있다
	for (i = 0; i < row * col; i++) group[i] = 0; //0으로 초기화
	int count = 0; //단지의 총 개수를 저장하는 변수
	
	row += 2; col += 2; //상하좌우 탐색을 할 때 편리하기 위해 주어진 정보를 0으로 둘러싼 행렬을 만들기 위해 row와 col에 각각 2씩 더한다
	int** matrix = (int**)malloc(sizeof(int*) * row); //실질적인 정보(집의 위치)를 저장하는 변수
	int** visited = (int**)malloc(sizeof(int*) * row); //각각의 집에 방문을 했는지 여부를 저장하는 변수
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * row);
		visited[i] = (int*)malloc(sizeof(int) * row);
	}
	//matrix와 visited를 0으로 초기화
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			matrix[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	//입력 받은 정보에서 1인 위치를 matrix에 반영
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
	printf("%d\n", count); //단지의 총 개수를 출력

	//각 단지를 집의 수로 오름차순 정렬
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
	for (i = 0; i < count; i++) printf("%d\n", group[i]); //오름차순으로 정렬된 각 단지의 집의 수를 출력

	//사용한 동적 할당된 메모리 해제하기
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