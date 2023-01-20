//영화감독 숌(실버5)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, target, temp;
	int num = 666; //첫번째가 666부터니깐 굳이 0부터 할 필요 없이 666부터 시작
	int count = 0; //몇번째 영화인지를 나타내는 변수

	scanf("%d", &target);
	
	while (count != target) {
		temp = num;
		while (temp != 0) {
			if (temp % 1000 == 666) { //1000으로 나눴을 때의 나머지가 666이면 6이 연속 3개 나오는 경우
				count++;
				break;
			}
			else temp /= 10; //제일 낮은 자릿수를 지워나가는 방법
		}
		num++;
	}
	printf("%d", num - 1); //마지막에 count == target이되어서 while문을 나오지만 나오기 전에 num++로 1이 더해져서 나오므로 1을 빼야 한다
}