#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
//#include <conio.h>
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

void arrayShifter(char arr[], int index, int size, char letter) {
	for (int y = index + 1; y < size; y++, index++)
	{
		arr[index] = arr[y];
	}

}

void squeeze(char str[], char a) {
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == a)
		{
			arrayShifter(str, i, size, a);
			i--;
		}
	}

}


int main(void) {

	char str[] = "Hello\n";
	squeeze(str, 'o'); // "Hell\n"
	printf("%s", str);
	return 0;

}