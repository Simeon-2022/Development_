#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
#define ROW_SIZE 100
#define COL_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"

int main(void) {
	
	int matrix_row_size = 0;
	int current_row = 0;
	int col = 0;

	char arr_1[ARR_SIZE] = { '\0' };
	char matrix[ROW_SIZE][COL_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line:\n=====================================================\n");
	get_string_EOF(arr_1);

	fill_char_matrix_from_array_split_by_line(*matrix, &current_row, ROW_SIZE, COL_SIZE, arr_1);

	printf("\nPrint lines in reverse order:\n=====================================================");
	print_reversed_char_matrix_from_row_(*matrix, current_row, COL_SIZE);

	return 0;
}