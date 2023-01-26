//퇴사(실버3, 브루트포스)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int time;
	int pay;
}job;

int max = 0;
int N;
job day[15];

void count(int today, int pay) {
	if (today == N) {
		if (max < pay) max = pay;
	}

	for (int i = today; i < N; i++) {
		//case1: 해당일의 상담을 받는 경우(제한조건: 소요 일자 후 N일을 넘어가면 안 됨
		if (i + day[i].time <= N) count(i + day[i].time, pay + day[i].pay); //기한 안에 마무리할 수 있으면 소요된 날 뒤로 넘어가기

		//case2: 해당일의 상담을 받지 않는 경우(제한 조건이 안되든, 그냥 넘어가든)
		else count(i + 1, pay); //날짜만 하루 더하고 이익은 동일
	}
}

int main() {	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &day[i].time, &day[i].pay); // 날짜당 소요되는 시간, 이익을 입력 받는다
	}
	count(0, 0); //1일부터 0원의 이익부터 시작
	printf("%d", max);
}