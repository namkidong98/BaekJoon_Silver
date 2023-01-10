//스택: 스택의 5가지 기능을 구현(push, pop, size, empty, top)
#include <stdio.h>
#include <string.h>

int main() {
    int i, num, data;
    int top = -1;
    int stack[10000] = {0}; //총 1만개까지 명령을 받을 수 있는데 모두 push일 수 있다
    char command[10];
    scanf("%d", &num);
    for(i=0;i<num;i++) {
        scanf("%s", command);
        if(strcmp(command, "push") == 0) {
            scanf("%d", &data);
            stack[++top] = data;
        }
        else if (strcmp(command, "pop") == 0) {
            if(top == -1) {
                printf("-1\n");
            }
            else {
                printf("%d\n", stack[top--]);
            }
        }
        else if (strcmp(command, "top") == 0) {
            if(top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", top + 1);
        }
        else if(strcmp(command, "empty") == 0) {
            if(top == -1) printf("1\n");
            else printf("0\n");
        }
        
    }
}