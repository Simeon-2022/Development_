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
	char arr_2[ARR_SIZE] = { '\0' };
	char* ptr_arr_1 = NULL;

	printf("Enter array of symbols to be copied and press 'Enter':\n=====================================================\n");
	get_string(arr_1);

	strcpy(arr_2, arr_1);

	printf("\nCopied array: \n=====================================================\n");
	print_char_Array(arr_2);

	return 0;
}
