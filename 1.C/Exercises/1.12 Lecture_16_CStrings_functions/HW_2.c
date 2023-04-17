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
	int char_range = 0;
	
	printf("Enter string and press 'Enter':\n=====================================================\n");
	get_string(arr_1);

	printf("Enter number of chars and press 'Enter': ");
	scanf("%d", &char_range);

	printf("\nCopied string range: \n=====================================================\n");


	print_char_Array_to_index(my_strncpy(arr_2, arr_1, char_range), char_range);

	return 0;
}