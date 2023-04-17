/*
Задача 11
Напишете функция, която претърсва за последователност от стойности (подадени
в едномерен масив) в редовете и колоните на двумерен масив. Функцията връща 1
ако е открила последователността, в някой ред или колона и 0 ако не е.

*/

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 5
#define ARR_COLS 7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include "Functions_13.h"


int main(void) {

	srand((unsigned int)time(NULL));

	int matrix_rows = ARR_ROWS;
	int matrix_cols = ARR_COLS;

	int matrix_1[ARR_ROWS][ARR_COLS]; //= { {1,1,1}, {1,0,1}, {1,0,1}, {1,0,1} };
	char arr_1[ARR_ROWS * ARR_COLS] = { '\0' };

	fill_matrix_rand_int(*matrix_1, ARR_COLS, ARR_ROWS);

	getCharArray(arr_1, ARR_ROWS, ARR_COLS);

	int arr_size = (int)strlen(arr_1);

	print_matrix_no_decimal_int(*matrix_1, ARR_ROWS, ARR_COLS);

	printf
	("\n=> %d",
		pattern_by_row(*matrix_1, matrix_rows, matrix_cols, arr_1, arr_size) > pattern_by_column(*matrix_1, matrix_rows, matrix_cols, arr_1, arr_size) ?
		pattern_by_row(*matrix_1, matrix_rows, matrix_cols, arr_1, arr_size) : pattern_by_column(*matrix_1, matrix_rows, matrix_cols, arr_1, arr_size)
	);

	return 0;
}

//arr_Manual_filler(arr_1, ARR_ROWS * ARR_COLS);