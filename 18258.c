//큐2
#include <stdio.h>
#include <string.h>

int main() {
    int queue[2000000] = {0};
    int front = 0;
    int rear = 0;

    int i, num, data;
    char command[10];
    scanf("%d", &num);
    for( i=0; i< num; i++) {
        scanf("%s", command);
        if(!strcmp(command, "push")) {
            scanf("%d", &data);
            queue[++rear] = data;
        }
        else if(!strcmp(command, "pop")) {
            if(front == rear) printf("-1\n");
            else printf("%d\n", queue[++front]);
        }
        else if(!strcmp(command, "size")) {
            printf("%d\n", rear - front);
        }
        else if(!strcmp(command, "empty")) {
            if(front == rear) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(command, "front")) {
            if(front == rear) printf("-1\n");
            else printf("%d\n", queue[front + 1]);
        }
        else if(!strcmp(command, "back")) {
            if(front == rear) printf("-1\n");
            else printf("%d\n", queue[rear]);
        }
    }
}