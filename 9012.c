//괄호(스택): 괄호가 맞게 쓰이면 YES, 아니면 NO를 출력
#include <stdio.h>
#include <string.h>

int main() {
    //int stack[50];
    char string[50];
    int top = -1;
    int i, j, num, len;
    int flag = 0; //YES, NO 판단
    scanf("%d", &num);
    for(i=0;i<num;i++) {
        scanf("%s", string);
        len = strlen(string);
        for(j=0; j<len; j++) {
            if(string[j] == '(') { //push
                top++;
            }
            else { //')'인 경우 --> pop
                if(top == -1) {
                    flag = 1;
                    break;
                }
                else top--;
            }
        }

        //해당 입력에 대한 결과 출력
        if(flag == 1) {
            printf("NO\n");
        }
        else if (top == -1){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }

        //다음 시행을 위한 초기화
        flag = 0; 
        top = -1;
    }
}