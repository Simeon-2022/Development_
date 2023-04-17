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
	char arr_reversed[ARR_SIZE] = { '\0' };

	printf("\nType in phraze: ");

	get_string_no_blanks_lowercase(arr_1);

	copy_array_in_reverse(arr_1, arr_reversed);


	if (compare(arr_1, arr_reversed))
	{
		printf("\nPhraze is a palindrom");
	}
	else
	{
		printf("\nPhraze is not a palindrom");
	}
	

	return 0;
}