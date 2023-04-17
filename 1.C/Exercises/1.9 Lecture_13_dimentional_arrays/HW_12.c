/*
Задача 12
Напишете функция, която търси за под-матрица в матрица (подобно на миналата
задача, но търсим за двумерен масив)
*/
#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS_1 6
#define ARR_COLS_1 5
#define ARR_ROWS_2 4
#define ARR_COLS_2 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include "Functions_13.h"

int main(void) {

	srand((unsigned int)time(NULL));

	int matrix_1_rows = ARR_ROWS_1;
	int matrix_1_cols = ARR_COLS_1;

	int sub_matrix_rows = ARR_ROWS_2;
	int sub_matrix_cols = ARR_COLS_2;

	int matrix_1[ARR_ROWS_1][ARR_COLS_1] = { {0,1,0,1,1}, {1,1,1,1,0}, {1,1,0,1,0}, {1,1,1,1,0},{1,1,1,1,1},{0,1,0,1,0} };
	int sub_matrix[ARR_ROWS_2][ARR_COLS_2] = { {1,1,1,1}, {1,1,0,1}, {1,1,1,1}, {1,1,1,1} };

	//fill_matrix_rand_int(*matrix_1, ARR_COLS_1, ARR_ROWS_1);
	//fill_matrix_rand_int(*sub_matrix, ARR_COLS_2, ARR_ROWS_2);

	printf("\nMain matrix:\n");
	print_matrix_no_decimal_int(*matrix_1, ARR_ROWS_1, ARR_COLS_1);
	printf("\nSub matrix:\n");
	print_matrix_no_decimal_int(*sub_matrix, ARR_ROWS_2, ARR_COLS_2);

	printf("\n=> %d\n", pattern_by_row_col(*matrix_1, matrix_1_rows, matrix_1_cols, *sub_matrix, sub_matrix_rows, sub_matrix_cols));

	return 0;
}

