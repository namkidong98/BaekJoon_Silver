//그룹단어 체킹
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int num, i, j, k, index, len;
	int flag = 0;
	int result = 0;
	char string[101];
	
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%s", string);
		len = strlen(string);

		for (j = 0; j < len - 1; j++) {
			index = j;
			for (k = j + 1; k < len; k++) {
				if (string[k] == string[j]) {
					if (k - index == 1) index = k;
					else {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) result++;
		flag = 0; //다음 시행을 위한 초기화

	}
	printf("%d", result);
}