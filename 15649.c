//N과 M 1(실버3)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int number[8] = { 0 }; //0이면 사용X, 1이상이면 우선순위로 사용한다는 의미

void sequence(int count, int current) { //count는 M개까지 남은 갯수, current는 현재 위치
	if (count == 0) {
		for (int j = M; j > 0; j--) { //총 M개를 골라야 하니 M번 반복하면서 우선순위 높은 것부터 출력하도록 설정
			for (int i = 0; i < N; i++) {
				if (number[i] == j) printf("%d ", i + 1);
			}
		}
		printf("\n");
	}

	else {
		for (int i = 0; i < N; i++) {
			if (count > 0 && number[i] == 0) { //아직 수열 길이가 남았으며 해당 숫자가 사용되지 않았다면
				number[i] = count;  //우선순위 부여해서
				sequence(count - 1, i + 1); //다음꺼 고르는 것으로 넘기기
				number[i] = 0; //끝나고 나오면 해당 위치 사용 안한 것으로 초기화(상쇄)
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	sequence(M, 0);
}