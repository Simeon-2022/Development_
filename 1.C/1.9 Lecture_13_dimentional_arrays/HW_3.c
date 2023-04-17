#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 5
#define ARR_COLS 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Functions_13.h"



int main(void)
{
	int matrix_size = ARR_ROWS * ARR_COLS;
	int zeroes_count = 0;

	int matrix_rows = ARR_ROWS;
	int matrix_cols = ARR_COLS;

	float matrix_1[ARR_ROWS][ARR_COLS] = { { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f},
											{0.0f, 1.0f, 0.0f, 1.0f, 0.0f},
											{0.0f, 0.0f, 1.0f, 0.0f, 0.0f},
											{0.0f, 1.0f, 0.0f, 1.0f, 0.0f},
											{1.0f, 0.0f, 0.0f, 0.0f, 1.0f}
	};

	if (check_diagonals(*matrix_1, matrix_rows, matrix_cols) && check_non_diagonals(*matrix_1, matrix_rows, matrix_cols))
	{

		printf("\nThis is an identity matrix!");
		printf("\nDiagonals are = 1's.\nThe other elements are = 0's\n");
		print_matrix(*matrix_1, ARR_ROWS, ARR_COLS);
	}
	else
	{
		printf("\nThis is NOT an identity matrix!\n");
		print_matrix(*matrix_1, ARR_ROWS, ARR_COLS);
	}
	return 0;
}

/*

{1.0 0.0 0.0 0.0 1.0},
{0.0 1.0 0.0 1.0 0.0},
{0.0 0.0 1.0 0.0 0.0},
{0.0 1.0 0.0 1.0 0.0},
{1.0 0.0 0.0 0.0 1.0}



*/