#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
#include <stdio.h>


void replace(char str[], char a, char b) {
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == a)
		{
			str[i] = b;
		}
	}

}

int main(void) {

	char str[] = "Hello\n";
	replace(str, 'e', '3'); // "H3llo\n"
	printf("%s", str);
	return 0;

}