//크로아티아 알파벳
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char string[101];
	int i, j, len;
	scanf("%s", string);
	len = strlen(string);
	int result = len;
	for (i = 0; i < len; i++) {
		if (string[i] == 'c') {
			if (string[i + 1] == '=' || string[i + 1] == '-') result--;
		}
		else if (string[i] == 'd') {
			if (string[i + 1] == '-') result--;
			else if (string[i + 1] == 'z' && string[i + 2] == '=') {
				result -= 2;
				i += 2;
			}
		}
		else if (string[i] == 'l' && string[i + 1] == 'j') result--;
		else if (string[i] == 'n' && string[i + 1] == 'j') result--;
		else if (string[i] == 's' && string[i + 1] == '=') result--;
		else if (string[i] == 'z' && string[i + 1] == '=') result--;
	}

	printf("%d", result);
}