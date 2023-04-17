#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"



int main(void)
{
	char arr_1[ARR_SIZE] = { '\0' }; // 100100200312355123
	char arr_2[ARR_SIZE] = { '\0' };

	char cont = ' ';
	
	while (cont != 'n')
	{

		printf("\nType in phraze #1: ");
		get_string(arr_1);

		printf("\nType in phraze #2: ");
		get_string(arr_2);

		int arr_size_1 = (int)my_strlen(arr_1);
		int arr_size_2 = (int)my_strlen(arr_2);
		printf("\nOccurrences at index: [%d]", h_lookup_string_index(arr_1, arr_size_1, arr_2, arr_size_2));

		cont = getchar();
	}

	return 0;
}
/*
c.coom.ccom....c.com
*/