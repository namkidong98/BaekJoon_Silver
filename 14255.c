//부분수열의 합(실버 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int number[20];
int visited[2000001] = { 0, }; //N이 총 20개까지 되고 각각은 10만 이하이므로 최대로 더해도 200만보다 작다

void possible(int total, int current) {
	if (visited[total] == 0) visited[total] = 1; //total에 들어온 값에 방문 기록을 남기고
	for (int i = current; i < N; i++) {
		possible(total + number[i], i + 1); //다음 조합 만들기
	}
}

int main() {
	int temp, result;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}

	possible(0, 0);

	for (result = 1; result<= 2000000; result++) { //자연수부터니깐 1부터 시작해서
		if (visited[result] == 0) break; //방문 표시가 안 되어 있는 곳에서 멈춰서
	}
	
	printf("%d", result); //해당 지점을 출력
}