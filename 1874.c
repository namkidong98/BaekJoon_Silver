//스택 수열
#include <stdio.h>
#include <stdlib.h>

int main() {
    int stack[100000] = { 0 };
    int* sequence;
    char result[200000] = { 0 };
    int count = 0;
    int index = 0;
    int top = -1;
    int flag = 0;
    int i, j, num, data;
    scanf("%d", &num);

    //수열 작성
    sequence = (int*)malloc(sizeof(int) * num);
    //result = (int*)malloc(sizeof(int) * num * 2);
    for (i = 0; i < num; i++) {
        scanf("%d", &data);
        if (data > num || data <= 0) flag = 1;
        sequence[i] = data;
    }
    
    if (flag == 1) return 0;

    //오름차순으로 stack에 저장, push와 pop을 사용하여 수열 만들기
    j = 1; //num까지의 인덱스
    for(i=0;i<num*2;i++) {
        if (sequence[index] > stack[top]) { //push
            stack[++top] = j++;
            result[count++] = 1;
            //printf("+\n"); //push는 +기호로 표시
        }
        else if (sequence[index] == stack[top]) { //pop
            top--;
            result[count++] = -1;
            index++;
            //printf("-\n"); //pop은 -기호로 표시
            if (top == -1 && j > num) break; //종료 조건
        }
        else {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("NO\n");
    }
    else {
        i = 0;
        while (result[i] != 0) {
            if (result[i] == 1) printf("+\n");
            else if (result[i] == -1) printf("-\n");
            else break;
            i++;
        }
    }
}