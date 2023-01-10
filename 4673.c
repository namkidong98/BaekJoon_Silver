//셀프 넘버
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LIMIT 10000


int main() {
	int number[LIMIT + 1] = { 0 }; //1부터 10000까지의 수에 0을 대입 --> 셀프넘버는 0으로 남고 아닌건 1로 변함

	int n, d_n, i; //n은 생성자, d_n은 n과 n의 각 자리수를 더한 값
	for(i = 1; i <= LIMIT; i++) { //1부터 10000까지 조사
		n = i;
		d_n = n;
		do {
			d_n += n % 10;
			n = (n - (n % 10)) / 10;
		} while (n != 0);
		if(d_n <= LIMIT) number[d_n] = 1;
	}
	for (i = 1; i <= LIMIT; i++) {
		if (number[i] == 0) printf("%d\n", i);
	}
}