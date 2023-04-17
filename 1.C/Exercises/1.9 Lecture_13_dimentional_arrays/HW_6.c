/*
Задача 6
Напишете функция, която умножава всеки елемент на 3x3 float матрица с float
число.

*/

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 3
#define ARR_COLS 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Functions_13.h"


int main(void) {

	float matrix[ARR_ROWS][ARR_COLS] = { {1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f} };

	float number = 0.0f;
	//int col_2 = 0;

	print_matrix(*matrix, ARR_ROWS, ARR_COLS);
	
	printf("\nEnter a multiplier -> ");
	scanf("%f", &number);
	
	matrix_multiplier_2(*matrix, ARR_ROWS, ARR_COLS, number);
	
	printf("\nNew matrix:\n");
	print_matrix(*matrix, ARR_ROWS, ARR_COLS);
	return 0;
}