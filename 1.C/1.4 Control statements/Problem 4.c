#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
//#include <conio.h>
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

void reverseString(char str[]) {
	char temp;
	for (int i = 0,y = strlen(str) - 1; i < strlen(str)/2; i++, y--)
	{
		temp = str[i];
		str[i] = str[y];
		str[y] = temp;
	}
	//return str;
}

int main(void)
{


	char str[] = "Hello\n"; // "\nolleH"

	reverseString(str);

	printf("%s",str);
	return 0;
}