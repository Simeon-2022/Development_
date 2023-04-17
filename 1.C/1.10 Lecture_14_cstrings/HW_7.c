#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int main(void)
{

	while (true)
	{
		char arr_1[ARR_SIZE] = { '\0' }; // 00000000000000111111110   
		char arr_2[ARR_SIZE] = { '\0' }; // 000001111

		printf("\nType in phraze #1: ");
		get_string(arr_1);

		printf("\nType in phraze #2: ");		get_string(arr_2);

		int arr_size_1 = (int)my_strlen(arr_1);
		int arr_size_2 = (int)my_strlen(arr_2);

		printf("\nOccurrences: [%d]\n", h_lookup_string_occurrences(arr_1, arr_size_1, arr_2, arr_size_2));

	}

	return 0;
}
