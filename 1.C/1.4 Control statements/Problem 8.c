#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
//#include <conio.h>
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

void arrayShifter(char arr[], int index, int size) {
	for (int y = index + 1; y < size; y++, index++)
	{
		arr[index] = arr[y];
	}
}

void squeeze(char str1[], char str2[]) {
	int size1 = strlen(str1);
	int size2 = strlen(str2);

	for (int i = 0; i < size2; i++)
	{
		for (int y = 0; y < size1; y++)
		{
			if (str2[i] == str1[y])
			{
				arrayShifter(str1, y, size1);
				y--;
			}
		}
	}
}


int main(void) {

	char str1[] = "Hello\n";
	squeeze(str1, "Hl"); // "eo\n"
	printf("%s", str1);
	return 0;

}