#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
#define ROW_SIZE 100
#define COL_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"

int main()
{
	int count_chars = 0;

	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line:\n=============================================\n");

	get_string_EOF(arr_1);

	printf("\n=============================================\n");
	
	for (const char* arr_ptr = arr_1; *arr_ptr != '\0'; arr_ptr++)
	{
		if (*arr_ptr != '\n')
		{
			count_chars++;
			continue;
		}

		if (count_chars > 3)
		{
			for (const char* sub_ptr = arr_ptr - count_chars; *sub_ptr != '\n'; sub_ptr++)
			{
				putchar(*sub_ptr);
			}
			putchar('\n');
			count_chars = 0;
		}
		else
		{
			count_chars = 0;
		}
	}
}

