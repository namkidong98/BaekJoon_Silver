//나이트의 이동
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
	int x;
	int y;
	int time;
}pos;

int bfs(int width, int height, int start_x, int start_y, int end_x, int end_y) {
	int i, j, front, rear, cur_x, cur_y, cur_time, next_x, next_y, dir;
	int found = 0; //1이 되면 종료 조건

	pos move[8]; //나이트가 움직일 수 있는 8가지 방향에 대한 좌표의 변화값
	move[0].x = 1; move[0].y = 2;
	move[1].x = 2; move[1].y = 1;
	move[2].x = 2; move[2].y = -1;
	move[3].x = 1; move[3].y = -2;
	move[4].x = -1; move[4].y = -2;
	move[5].x = -2; move[5].y = -1;
	move[6].x = -2; move[6].y = 1;
	move[7].x = -1; move[7].y = 2;

	pos* queue = (pos*)malloc(sizeof(pos) * width * height);
	front = rear = -1;
	int** visited = (int**)malloc(sizeof(int*) * width);
	for (i = 0; i < width; i++) visited[i] = (int*)malloc(sizeof(int) * height);
	
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			visited[i][j] = 0;
		}
	}
	
	visited[start_x][start_y] = 1;
	queue[++rear].x = start_x; queue[rear].y = start_y; queue[rear].time = 0;  //queue에 초기 위치 넣기
	while (front != rear) {
		cur_x = queue[++front].x; cur_y = queue[front].y; cur_time = queue[front].time; //queue에서 새로운 위치 가져오기

		if (cur_x == end_x && cur_y == end_y) break; //종료 조건

		//8가지 방향으로 이동 가능하다면 queue에 add하기
		dir = 0;
		while (dir < 8) {
			next_x = cur_x + move[dir].x; next_y = cur_y + move[dir].y;

			if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height) { //이동하려는 위치가 체스판 안에 위치할 때만
				if (visited[next_x][next_y] == 0) { //아직 방문하지 않은 곳이면
					visited[next_x][next_y] = 1;//
					queue[++rear].x = next_x; queue[rear].y = next_y; queue[rear].time = cur_time + 1;
				}
				
			}
			dir++;
		}
	}

	return cur_time;
}

int main() {
	int i, testcase, width, height, start_x, start_y, end_x, end_y;
	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++) {
		scanf("%d", &width);
		height = width;
		scanf("%d %d", &start_x, &start_y);
		scanf("%d %d", &end_x, &end_y);
		printf("%d\n", bfs(width, height, start_x, start_y, end_x, end_y));
	}
}