#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"



int main(void)
{
	char arr_1[ARR_SIZE] = { '\0' };

	printf("\nType in phraze: ");
	get_string(arr_1);

	printf("\nType in lookup char: ");
	char ch = getchar();

		
	printf("\nOccurrences: %d", lookup_char_value(arr_1, ch));

	return 0;
}