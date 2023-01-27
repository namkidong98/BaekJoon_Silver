//데스 나이트(그래프, 실버1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int row;
	int col;
	int distance;
}pos;

dr[6] = { -2, -2, 0, 0, 2, 2}; //row에서 6가지 방향에 따른 변화값
dc[6] = { -1, 1, -2, 2, -1, 1}; //col에서 6가지 방향에 따른 변화값

int bfs(int row, int col, pos start, pos end) {
	pos* queue = (pos*)malloc(sizeof(pos) * row * col); //좌표를 담을 수 있는 큐를 동적 할당
	int** visited = (int**)malloc(sizeof(int*) * row); //방문 정보를 담을 수 있는 메모리를 동적 할당
	for (int i = 0; i < row; i++)visited[i] = (int*)malloc(sizeof(int) * col);
	int front, rear, dir; front = rear = -1; pos cur, next;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			visited[i][j] = 0; //방문 안한 것으로 초기화
		}
	}

	// 시작점을 queue에 add
	queue[++rear].row = start.row; queue[rear].col = start.col; queue[rear].distance = 0; visited[start.row][start.col] = 1; 

	while (front != rear) {
		cur.row = queue[++front].row; cur.col = queue[front].col; cur.distance = queue[front].distance; //queue에서 새로운 위치 가져오기

		if ((cur.row == end.row) && (cur.col == end.col)) break; //종료 조건(가져온 위치가 도착점과 일치)

		dir = 0; //처음 방향부터 시작
		while (dir < 6) { //총 방향은 6개까지 있으므로
			next.row = cur.row + dr[dir]; next.col = cur.col + dc[dir]; next.distance = cur.distance + 1; //다음 좌표를 구해보고
			if (next.row >= 0 && next.row < row && next.col >=0 && next.col < col) { //체스판 범위 안에 있으면
				if (visited[next.row][next.col] == 0) { //해당 좌표가 방문되지 않았으면 --> 이미 방문된 곳을 또 갔다는 것은 distance의 측면에서 이미 최소 값이 아니다(배제해야 한다)
					visited[next.row][next.col] = 1; //방문 기록 남기고
					queue[++rear].row = next.row; queue[rear].col = next.col; queue[rear].distance = cur.distance + 1; //해당 위치를 queue에 add
				}
			}
			dir++; //다음 방향으로 넘어가면서
		}

	}

	if ((cur.row == end.row) && (cur.col == end.col)) return cur.distance; //종료 조건에 맞아 while loop을 나온 경우, 최소 이동 횟수 반환
	else return -1; //이동할 수 없는 경우, -1 반환
}

int main() {
	pos start, end; int row, col;
	scanf("%d", &row);
	col = row;
	scanf("%d %d %d %d", &start.row, &start.col, &end.row, &end.col);

	printf("%d", bfs(row, col, start, end));
}