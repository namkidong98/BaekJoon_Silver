//섬의 개수(실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _pos {
	int row;
	int col;
}pos;

int row, col; //각각 문제의 height, width에 해당
int map[50][50]; //map의 정보를 저장
int visited[50][50]; //방문 기록
pos land[2500]; //처음 map을 읽을 때 1이 저장되어 있는 지점의 행열을 저장하는 변수
int land_count = 0; //처음 map을 읽을 때 1이 저장되어 있는 지점의 개수
int result = 0; //연결된 섬의 개수를 나타내는 변수
pos queue[2500]; //최대 50 * 50으로 2500개가 들어올 수 있다
int d_row[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //위쪽부터 시계방향으로
int d_col[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; //위쪽부터 시계방향으로

void bfs(int start_row, int start_col) {
	int front, rear, cur_row, cur_col, next_row, next_col, dir;
	front = rear = -1;

	queue[++rear].row = start_row; queue[rear].col = start_col; //초기 위치 queue에 넣기
	while (front != rear) {
		cur_row = queue[++front].row; cur_col = queue[front].col; //queue에서 위치 가져오기

		dir = 0; //8가지 방향을 나타내는 변수를 0부터 7까지 증가시키면서
		while (dir < 8) {
			next_row = cur_row + d_row[dir]; next_col = cur_col + d_col[dir]; //예상되는 다음 지점을 갱신하고
			if (next_row >= 0 && next_row < row && next_col >= 0 && next_col < col) { //다음 지점이 map의 범위 안에 있고
				if (visited[next_row][next_col] == 0 && map[next_row][next_col] == 1) { //아직 방문되지 않은 섬이면
					queue[++rear].row = next_row; //queue에 위치 넣고 방문기록 남기기
					queue[rear].col = next_col;
					visited[next_row][next_col] = 1;
				}
			}
			dir++; //다음 방향 조사
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &col, &row);

		if (row == 0 && col == 0) break; //종료조건

		land_count = 0; result = 0; //새로운 시행을 위한 초기화
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					land[land_count].row = i;
					land[land_count].col = j;
					land_count++;
				}
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < land_count; i++) { //각각의 land를 기준으로 bfs를 탐색
			if (visited[land[i].row][land[i].col] == 0) { //아직 방문되지 않은 섬에 한에서만
				bfs(land[i].row, land[i].col);
				result++; //연결된 섬 단위 1개 추가
			}
		}

		printf("%d\n", result);
	}
}