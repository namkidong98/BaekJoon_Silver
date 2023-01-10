//전위, 중위, 후위 순회
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node* node_pointer;
typedef struct _node {
	char alphabet;
	//node_pointer parent;
	node_pointer left;
	node_pointer right;
}node;

node_pointer* NODE;

void preorder(node_pointer ptr) {
	if (ptr) {
		printf("%c", ptr->alphabet);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(node_pointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%c", ptr->alphabet);
		inorder(ptr->right);
	}
}

void postorder(node_pointer ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%c", ptr->alphabet);
	}
}

int main() {
	int i, num;
	char a, b, c;
	node_pointer temp;

	scanf("%d", &num);
	NODE = (node_pointer*)malloc(sizeof(node_pointer) * num);
	for (i = 0; i < num; i++) {
		temp = (node_pointer)malloc(sizeof(node));
		temp->alphabet = 65 + i;
		temp->left = NULL;
		temp->right = NULL;
		NODE[i] = temp;
	}
	for (i = 0; i < num; i++) {
		scanf("%c", &a); //개행 문자 걷어내기
		scanf("%c %c %c", &a, &b, &c);
		if (b != '.') NODE[a - 65]->left = NODE[b - 65];
		if (c != '.') NODE[a - 65]->right = NODE[c - 65];
	}

	preorder(NODE[0]);
	printf("\n");
	inorder(NODE[0]);
	printf("\n");
	postorder(NODE[0]);
	printf("\n");
}