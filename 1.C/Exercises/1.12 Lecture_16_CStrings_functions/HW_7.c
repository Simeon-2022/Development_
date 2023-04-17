#define _CRT_SECURE_NO_WARNINGS
#define SUB_ARR_ROW 5
#define SUB_ARR_COL 4
#define ROW_SIZE 4
#define COL_SIZE 7
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_16.h"


int main(void)
{
	int sub_array_cols = SUB_ARR_COL;
	int sub_array_rows = SUB_ARR_ROW;

	const char matrix_1[][COL_SIZE] = {
										"bathbah",
										"abitita",
										"botytat",
										"bitcatt"
	};

	const char arr_1[][SUB_ARR_COL] = { "cat", "bat", "hat", "bit", "bot" };

	//printf("Enter base string and press 'Enter': ");
	//get_string(arr_1);

	//printf("Enter substring and press 'Enter': ");
	//get_string(arr_2);

	printf("Base matrix:\n");
	print_matrix(*matrix_1, ROW_SIZE, COL_SIZE);

	printf("\nSearch string: \n");
	print_matrix_brackets(*arr_1, sub_array_rows, sub_array_cols);

	putchar('\n');

	const char* ptr_End = *(arr_1 + sub_array_rows);

	for (const char* ptr = *arr_1; ptr < ptr_End; ptr += sub_array_cols)
	{
		printf("\n%s found: %d times", ptr, find_str_pattern_by_row_char(*matrix_1, ROW_SIZE, COL_SIZE, ptr));
	}



	return 0;
}