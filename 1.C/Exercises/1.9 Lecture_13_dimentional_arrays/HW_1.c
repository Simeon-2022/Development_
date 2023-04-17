// Meeting_13.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 4
#define ARR_COLS 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions_13.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	float matrix_1[ARR_ROWS * ARR_COLS] = { 0.0f };
	float matrix_2[ARR_ROWS * ARR_COLS] = { 0.0f };
	float matrix_3[ARR_ROWS * ARR_COLS] = { 0.0f };

	fill_matrix_rand(matrix_1, ARR_ROWS, ARR_COLS);
	fill_matrix_rand(matrix_2, ARR_ROWS, ARR_COLS);

	sum_matrix(matrix_1, matrix_2, matrix_3, ARR_ROWS, ARR_COLS);
	
	printf("\nMatrix 1:\n");
	print_matrix(matrix_1, ARR_ROWS, ARR_COLS);
	
	printf("\nMatrix 2:\n");
	print_matrix(matrix_2, ARR_ROWS, ARR_COLS);

	printf("\nMatrix 3:\n");
	print_matrix(matrix_3, ARR_ROWS, ARR_COLS);

	return 0;
}

