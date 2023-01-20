//����� ����(�ǹ�2)
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
	while (front != rear) { //queue�� �� ������
		cur_row = queue[++front].row; cur_col = queue[front].col; //���� ��ġ ��������

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
	int count = 0; //�ʿ��� ���� ���������� ������ 

	//��Ʈ���� �����(���δ� col�� �ǰ� ���δ� row�� �ȴ�)
	t_row = height; t_col = width;
	matrix = (int**)malloc(sizeof(int*) * (t_row + 2)); //visited���� �����¿츦 Ž���� �� ���ʿ� �־ ������ ������ ��츦 �����ϱ� ����
	for (i = 0; i < t_row + 2; i++) matrix[i] = (int*)malloc(sizeof(int) * (t_col + 2));
	visited = (int**)malloc(sizeof(int*) * (t_row + 2)); //visited���� �����¿츦 Ž���� �� ���ʿ� �־ ������ ������ ��츦 �����ϱ� ����
	for (i = 0; i < t_row + 2; i++) visited[i] = (int*)malloc(sizeof(int) * (t_col + 2));

	for (i = 0; i < t_row + 2; i++) {
		for (j = 0; j < t_col + 2; j++) {
			matrix[i][j] = 0; //0���� �ʱ�ȭ(���߰� �� �ɾ��� �ִ�)
			visited[i][j] = 0;
		}
	}

	//terms���� ������ 2���� matrix�� ����
	for (i = 0; i < terms; i++) {
		scanf("%d %d", &x, &y); //������ x��ǥ, y��ǥ
		matrix[y + 1][x + 1] = 1; //1�� ���߰� �ɾ��� �ִٴ� �ǹ�
	}

	//�������� matrix�� ������� 1���� row-1, 1���� col-1�̴�
	for (i = 1; i < t_row + 2; i++) {
		for (j = 1; j < t_col + 2; j++) {
			if (matrix[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				count++; //�����¿� ��� �湮�� ������ ���� ��(������ ���� ����)�� �����̰� �ʿ�
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