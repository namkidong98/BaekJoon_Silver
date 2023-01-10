//제로: 장부관리에서 0을 쓰면 최근 수를 지우고 저장된 값의 합을 출력(첫 줄은 명령줄의 개수)
#include <stdio.h>

int main() {
    int stack[100000];
    int top = -1;
    int i, num, data;
    int result = 0;
    scanf("%d", &num);
    for(i=0; i<num; i++) {
        scanf("%d", &data);
        if(data == 0) { //pop
            top--;
        }
        else { //push
            stack[++top] = data;
        }
    }
    for(i=0;i<=top;i++) {
        result += stack[i];
    }
    printf("%d\n", result);
}