#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
//#include <conio.h>
#include <stdio.h>
#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

/*void arrayShifter(char arr[], int index, int size) {
	for (int y = index + 1; y < size; y++, index++)
	{
		arr[index] = arr[y];
	}
}
*/

int findIndex(char str1[], char str2[]) {

	int size1 = strlen(str1);
	int size2 = strlen(str2);
	int index = INT_MAX;

	for (int i = 0; i < size2; i++)
	{
		for (int y = 0; y < size1; y++)
		{
			if (str2[i] == str1[y])
			{
				if (index > y)
				{
					index = y;
				}
			}
		}
	}

	if (index == INT_MAX)
	{
		index = -1;
	}

	return index;
}


int main(void) {

	//char str1[] = "Hello\n";
	
	printf("%d", findIndex("Hello", "oe"));// index = 1;
	return 0;

}