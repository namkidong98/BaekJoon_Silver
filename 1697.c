//숨바꼭질 (BFS)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100001

typedef struct pos {
	int pos;
	int time;
}pos;

int main() {
	int start, end, i, cur_pos, cur_time, front, rear;
	scanf("%d %d", &start, &end);
	pos queue[LIMIT * 2];
	int visited[LIMIT];
	front = rear = -1;
	for (i = 0; i < LIMIT; i++) visited[i] = 0; //방문하지 않음으로 초기화

	queue[++rear].pos = start; queue[rear].time = 0; visited[start] = 1;//시작지점 세팅
	while (front != rear) {
		cur_pos = queue[++front].pos; cur_time = queue[front].time;
		
		if (cur_pos == end) break; //도착지점에 이르면 loop out

		//case1: x + 1
		if (cur_pos < end && visited[cur_pos + 1] == 0) {
			queue[++rear].pos = cur_pos + 1; queue[rear].time = cur_time + 1; visited[cur_pos + 1] = 1;
		}
		//case2: x - 1
		if (visited[cur_pos - 1] == 0) {
			queue[++rear].pos = cur_pos - 1; queue[rear].time = cur_time + 1; visited[cur_pos - 1] = 1;
		}
		//case3: x * 2
		if (cur_pos < end && visited[cur_pos * 2] == 0) {
			queue[++rear].pos = cur_pos * 2; queue[rear].time = cur_time + 1; visited[cur_pos * 2] = 1;
		}
	}
	printf("%d", cur_time);
}