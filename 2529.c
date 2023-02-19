//부등호
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int k;
char ineq[9]; //부등호는 2개에서 최대 9개까지 가능
long long max = 0;
long long min = 9999999999;
int number[10]; //각 시행에서 사용되는 숫자는 10개까지 들어갈 수 있음
int min_ans[10];
int max_ans[10];
int use[10]; //0부터 9까지 사용했는지를 나타내는 변수

void cal(int count) {
	long long total = 0;
	if (count == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			total += pow(10, k - i) * number[i];
		}
		if (total > max) {
			for (int j = 0; j < k + 1; j++) max_ans[j] = number[j];
			max = total;
		}
		if (total < min) {
			for (int j = 0; j < k + 1; j++) min_ans[j] = number[j];
			min = total;
		}
	}
	
	else if (count == 0) {
		for (int i = 0; i < 10; i++) {
			number[count] = i;
			use[i] = 1;
			cal(count + 1);
			use[i] = 0; //재귀가 끝나고 나왔을 때 해당 시행에서 변경한 사항을 상쇄
		}
	} 
	
	else {
		for (int i = 0; i < 10; i++) { //0부터 9까지의 숫자들에서 골라야 한다
			
			if (use[i] == 0) {
				
				if (ineq[count - 1] == '<') {
					if (number[count - 1] < i) {
						number[count] = i;
						use[i] = 1;
						cal(count + 1);
						use[i] = 0;
					}
				}
				else { //'>'
					if (number[count - 1] > i) {
						number[count] = i;
						use[i] = 1;
						cal(count + 1);
						use[i] = 0;
					}
				}

			}
		}
	}
}


int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf(" %c", &ineq[i]);
	}
	for (int i = 0; i < 10; i++)use[i] = 0; //초기화
	
	cal(0);
	for (int i = 0; i < k + 1; i++) printf("%d", max_ans[i]);
	printf("\n");
	for (int i = 0; i < k + 1; i++)printf("%d", min_ans[i]);
}