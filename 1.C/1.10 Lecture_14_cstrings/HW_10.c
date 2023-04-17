#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"



int main(void)
{
	char arr_1[ARR_SIZE] = { '\0' };
	char arr_2[ARR_SIZE] = { '\0' };

	printf("\nType in your comparison string #1:\n");
	get_string(arr_1);

	printf("\nType in your comparison string #2:\n");
	get_string(arr_2);

	printf("\nResult %d", my_strcmp(arr_1, arr_2));

	return 0;
}
