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
	size_t count = 0;

	printf("Enter destination string and press 'Enter': ");
	get_string(arr_1);

	printf("Enter source string and press 'Enter': ");
	get_string(arr_2);

	printf("Enter number of chars and press 'Enter': ");
	scanf("%zd", &count);

	printf("\nConcatenated string: ");

	print_char_Array(my_strncat(arr_1, arr_2,count));

	return 0;
}