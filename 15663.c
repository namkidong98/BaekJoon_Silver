//N과 M 8 (실버2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, len;
int input[8]; //값을 입력 받기 위한 변수
int number[8][2]; //입력 받은 값을 오름차순으로 정렬하고 0에는 해당 숫자를, 1에는 해당 숫자가 나온 횟수를 저장
int target[8];

void sequence(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", target[i]);
		}
		printf("\n");
	}

	else {
		for (int i = 0; i <= len; i++) {
			if (number[i][1] > 0) { //해당 숫자를 사용할 횟수가 남아있다면
				target[count] = number[i][0];
				number[i][1]--; //사용 가능한 횟수 하나를 줄이고
				sequence(count + 1);
				number[i][1]++; //재귀가 끝나고 나왔을 때 이번 시행에서 변경한 것(횟수 1개 줄이기)을 상쇄시키는 작업
			}
		}
	}
}

int main() {
	int temp; len = 0;
	scanf("%d %d", &N, &M);

	//초기화
	for (int i = 0; i < N; i++) {
		number[i][0] = 0;
		number[i][1] = 0;
	}

	//값 입력 받기
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	
	//오름차순으로 input에다가 정렬
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (input[i] > input[j]) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

	//정렬된 input을 보고 반복되어 나온 숫자를 없애고 횟수로 파악하는 number를 만들기
	for (int i = 0; i < N; i++) {
		number[len][0] = input[i];
		number[len][1]++;
		if (i == N - 1) continue;
		if (input[i] == input[i + 1]) {
		}
		else len++;
	}
	
	//재귀 함수 시작
	sequence(0);
}