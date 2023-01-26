//수 이어가기(싧버5, 브루트포스)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SEARCH 1
#define PRINT 2

int count(int first, int second, int command) {
	int third; int count = 2;
	third = first - second;
	if (command == PRINT) printf("%d %d ", first, second);

	while (third >= 0) {
		if (command == PRINT) printf("%d ", third);
		count++;
		first = second;
		second = third;
		third = first - second;
	}
	return count;
}

int main() {
	int first, result;
	int max = 2; int index = 0;
	scanf("%d", &first);
	for (int second = 1; second <= first; second++) {
		result = count(first, second, SEARCH);
		if (max <= result) {
			max = result;
			index = second;
		}
	}
	printf("%d\n", max);
	count(first, index, PRINT);
}