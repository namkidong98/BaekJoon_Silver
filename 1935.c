//후기 표기식 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num, i;
	char string[101]; //입력을 받는 변수, 길이는 100을 넘지 않는다
	int prefix[101]; //입력 받은 후위표기식의 알파벳을 숫자로 변환하여 만든 string, 0은 연산자, 나머지는 피연산자를 의미
	int alphabet[26]; //각각의 알파벳에 입력되는 숫자를 저장하는 변수

	//값 입력 받기
	scanf("%d", &num);
	scanf("%s", string);
	int len = strlen(string);
	for (i = 0; i < num; i++) {
		scanf("%d", &alphabet[i]);
	}

	//숫자와 연산자로 이루어진 string으로 변환
	for (i = 0; i < len; i++) {
		if (string[i] >= 65 && string[i] <= 90) { //A~Z의 영대문자이면
			prefix[i] = alphabet[string[i] - 65]; //피연산자를 상징
		}
		else prefix[i] = 0; //연산자를 상징
	}
	double stack[101];
	int top = -1;
	double operand1, operand2;

	for (i = 0; i < len; i++) {
		if (prefix[i] != 0) { //피연산자
			stack[++top] = (double)prefix[i];
		}
		else { //연산자(아스키코드 기준 37이상
			operand2 = stack[top--]; //pop
			operand1 = stack[top--]; //pop
			if (string[i] == '+') {
				stack[++top] = operand1 + operand2;
			}
			else if (string[i] == '-') {
				stack[++top] = operand1 - operand2;
			}
			else if (string[i] == '*') {
				stack[++top] = operand1 * operand2;
			}
			else if (string[i] == '/') {
				stack[++top] = operand1 / operand2;
			}
			//% 연산자는 없어도 문제 없음
		}
	}
	printf("%.2lf", stack[0]); //소수점 둘째자리까지 출력
}
//주의점: float이 아닌 double로 자료형을 선언해야 한다