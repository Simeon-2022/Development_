/*
«адача 10
Ќапишете програма, ко€то принтира сумата на всеки ред и на вс€ка колона
на една матрица.

*/

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 10
#define ARR_COLS 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include "Functions_13.h"

int main(void) {

	srand((unsigned int)time(NULL));

	int rows = ARR_ROWS;
	int cols = ARR_COLS;

	int matrix_1[ARR_ROWS][ARR_COLS] = { 0 };
	int arr_1[ARR_ROWS * ARR_COLS] = { 0 };

	fill_matrix_rand_int(*matrix_1, ARR_ROWS, ARR_COLS);

	printf("\nSum of [%d] rows and [%d] columns:\n\n", ARR_ROWS, ARR_COLS);

	sum_of_rows_and_columns(*matrix_1, ARR_ROWS, ARR_COLS);

	return 0;
}
