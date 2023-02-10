//���� ����(�ǹ�2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _pos {
	int row;
	int col;
}pos;

int row, col; //���� ������ height, width�� �ش�
int map[50][50]; //map�� ������ ����
int visited[50][50]; //�湮 ���
pos land[2500]; //ó�� map�� ���� �� 1�� ����Ǿ� �ִ� ������ �࿭�� �����ϴ� ����
int land_count = 0; //ó�� map�� ���� �� 1�� ����Ǿ� �ִ� ������ ����
int result = 0; //����� ���� ������ ��Ÿ���� ����
pos queue[2500]; //�ִ� 50 * 50���� 2500���� ���� �� �ִ�
int d_row[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; //���ʺ��� �ð��������
int d_col[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; //���ʺ��� �ð��������

void bfs(int start_row, int start_col) {
	int front, rear, cur_row, cur_col, next_row, next_col, dir;
	front = rear = -1;

	queue[++rear].row = start_row; queue[rear].col = start_col; //�ʱ� ��ġ queue�� �ֱ�
	while (front != rear) {
		cur_row = queue[++front].row; cur_col = queue[front].col; //queue���� ��ġ ��������

		dir = 0; //8���� ������ ��Ÿ���� ������ 0���� 7���� ������Ű�鼭
		while (dir < 8) {
			next_row = cur_row + d_row[dir]; next_col = cur_col + d_col[dir]; //����Ǵ� ���� ������ �����ϰ�
			if (next_row >= 0 && next_row < row && next_col >= 0 && next_col < col) { //���� ������ map�� ���� �ȿ� �ְ�
				if (visited[next_row][next_col] == 0 && map[next_row][next_col] == 1) { //���� �湮���� ���� ���̸�
					queue[++rear].row = next_row; //queue�� ��ġ �ְ� �湮��� �����
					queue[rear].col = next_col;
					visited[next_row][next_col] = 1;
				}
			}
			dir++; //���� ���� ����
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &col, &row);

		if (row == 0 && col == 0) break; //��������

		land_count = 0; result = 0; //���ο� ������ ���� �ʱ�ȭ
		
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

		for (int i = 0; i < land_count; i++) { //������ land�� �������� bfs�� Ž��
			if (visited[land[i].row][land[i].col] == 0) { //���� �湮���� ���� ���� �ѿ�����
				bfs(land[i].row, land[i].col);
				result++; //����� �� ���� 1�� �߰�
			}
		}

		printf("%d\n", result);
	}
}