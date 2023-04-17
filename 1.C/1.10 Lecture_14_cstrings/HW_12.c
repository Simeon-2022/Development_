#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 256
#define ROW_SIZE 100
#define COL_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int main(void)
{
	const int arr_size = ARR_SIZE;
	const int row_size = ROW_SIZE;
	const int col_size = COL_SIZE;
	int current_row = 0;
	int matrix_row_size = 0;

	char arr_1[ARR_SIZE] = { '\0' };// "How are you today, how were you yesterday?"
	char arr_2[ARR_SIZE] = { '\0' };
	int arr_occurrences[ARR_SIZE] = { 0 };

	char matrix[256][20] = { '\0' };

	int uncounted = 1;

	get_string(arr_1);

	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (is_capital(arr_1[i]))
		{
			arr_1[i] = toLower(arr_1[i]);
		}
	}

	current_row = longest_word_matrix_position(arr_1, arr_2, *matrix, row_size, col_size, arr_occurrences, (int)my_strlen(arr_1));

	matrix_row_size = (int)my_strlen(*(matrix + current_row));

	printf("\nThe address of '%s' is %p\n", *(matrix + current_row),h_lookup_string_pointer(arr_1, arr_size, *(matrix + current_row), matrix_row_size));

	return 0;
}
/*
How is Simo today, how was Simo00000000000000000 yesterday ?
*/