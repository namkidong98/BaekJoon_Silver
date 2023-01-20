//체스판 다시 칠하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, row, col, p, q;
	char chess[51][51]; //체스판의 최대 크기는 50 * 50
	int min = 65; //최대 값이 8*8인 64이기 때문
	int flag; //홀짝을 구분하기 위한 변수
	int count; //몇 개를 바꾸어야 하는지를 저장하는 변수

	scanf("%d %d", &row, &col);

	//정보 입력 받기
	for (i = 0; i < row; i++) {
		scanf("%s", chess[i]); //chess[i]는 해당 배열의 앞머리로 그 자체가 주소를 의미하기에 &을 붙이지 않아도 된다
	}


	for (i = 0; i <= row - 8; i++) {
		for (j = 0; j <= col - 8; j++) {

			//좌측 상단을 W로 시작한다고 가정하고 구할 때
			flag = 0; count = 0;
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (flag == 0) {
						if (chess[p][q] != 'W') count++;
						flag = 1;
					}
					else { //flag == 1
						if (chess[p][q] != 'B') count++;
						flag = 0;
					}
				}
				if (flag == 0) flag = 1;
				else flag = 0;
			}
			//현재의 최솟값보다 작으면 갱신
			if (min > count) min = count;

			//좌측 상단을 B로 시작한다고 가정하고 구할 때
			flag = 1; count = 0;
			for (p = i; p < i + 8; p++) {
				for (q = j; q < j + 8; q++) {
					if (flag == 0) {
						if (chess[p][q] != 'W') count++;
						flag = 1;
					}
					else { //flag == 1
						if (chess[p][q] != 'B') count++;
						flag = 0;
					}
				}
				if (flag == 0) flag = 1;
				else flag = 0;
			}
			//현재의 최솟값보다 작으면 갱신
			if (min > count) min = count;
		}
	}

	printf("%d", min);
}