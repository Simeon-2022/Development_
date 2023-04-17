#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
//#include <conio.h>
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

void reverseString(char str[]) {
	char temp;
	for (int i = 0, y = strlen(str) - 1; i < strlen(str) / 2; i++, y--)
	{
		temp = str[i];
		str[i] = str[y];
		str[y] = temp;
	}
}

int main(void)
{
	int n = 123;
	int count = 0;

	char arr[MAX_CHARS_PER_LINE];

	scanf("%d", &n);

	do
	{
		int temp = n % 10;

		arr[count] = temp + '0';

		n /= 10;
		
	} while (count++, n > 0);

	arr[count] = '\0';
	reverseString(arr);

	printf("%s", arr);

	return 0;
}