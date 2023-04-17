// Meeting_13.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 3
#define ARR_COLS 3
#define ARR_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Functions_13.h"



int main(void)
{
	//srand((unsigned int)time(NULL));

	float matrix_1[ARR_SIZE] = { 0.0f };
	float matrix_2[ARR_SIZE] = { 0.0f };

	printf("\n %d elements for Matrix_1 [%d][%d] required:\n\n", ARR_COLS * ARR_ROWS, ARR_ROWS, ARR_COLS);
	fill_matrix_manual(matrix_1, ARR_ROWS, ARR_COLS);

	printf("\n %d elements for Matrix_2 [%d][%d] required:\n\n", ARR_COLS * ARR_ROWS, ARR_ROWS, ARR_COLS);
	fill_matrix_manual(matrix_2, ARR_ROWS, ARR_COLS);

	printf("\nMatrix 1:\n");
	print_matrix(matrix_1, ARR_ROWS, ARR_COLS);

	printf("\nMatrix 2:\n");
	print_matrix(matrix_2, ARR_ROWS, ARR_COLS);

	compare_elements(matrix_1, matrix_2, ARR_ROWS, ARR_COLS);


	return 0;
}

