//Å¥(½Ç¹ö4)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int queue[10000];
int front, rear; 

int main() {
	int number;
	char string[10]; int data;
	front = rear = -1;

	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%s", string);
		if (strcmp(string, "push") == 0) {
			scanf("%d", &data);
			queue[++rear] = data;
		}
		else if (strcmp(string, "pop") == 0) {
			if (rear == front) {
				printf("-1\n");
			}
			else {
				printf("%d\n", queue[++front]);
			}
		}
		else if (strcmp(string, "size") == 0) {
			printf("%d\n", rear - front);
		}
		else if (strcmp(string, "empty") == 0) {
			if (rear == front) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(string, "front") == 0) {
			if (front != rear) printf("%d\n", queue[front + 1]);
			else printf("-1\n");
		}
		else if (strcmp(string, "back") == 0) {
			if (front != rear) printf("%d\n", queue[rear]);
			else printf("-1\n");
		}
	}
}