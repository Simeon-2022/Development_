#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
//#define ROW_SIZE 100
//#define COL_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_16.h"


int main(void)
{
	char arr_1[ARR_SIZE] = { '\0' };
	char* ptr_arr_1;

	printf("Enter array of symbols and press 'Enter':\n=====================================================\n");
	get_string(arr_1);

	printf("\nEnter the symbol to look for in '%s': ", arr_1);

	char look_up = getchar();
	printf("=====================================================\n");
	ptr_arr_1 = my_strrchr(arr_1, look_up);

	if (ptr_arr_1 != NULL)
	{
		printf("Last occurrence at %d \n", (int)(ptr_arr_1 - arr_1 + 1));
	}
	else
	{
		printf("Not found\n");
	}

	return 0;
}