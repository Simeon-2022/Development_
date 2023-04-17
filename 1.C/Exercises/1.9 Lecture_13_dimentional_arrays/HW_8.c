/*
Задача 8
Напишете функция, която умножава две 3x3 float матрици

*/

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 3
#define ARR_COLS 3
//#define ARR_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>
#include "Functions_13.h"


int main(void) {

	int rows = ARR_ROWS;
	int cols = ARR_COLS;

	float matrix_1[ARR_ROWS][ARR_COLS] = { {3.0f,12.0f,4.0f},{5.0f,6.0f,8.0f},{1.0f,0.0f,2.0f} };
	float matrix_2[ARR_ROWS][ARR_COLS] = { {7.0f,3.0f,8.0f},{11.0f,9.0f,5.0f},{6.0f,8.0f,4.0f} };
	float matrix_3[ARR_ROWS][ARR_COLS] = { {0} };

	//fill_matrix_rand(*matrix_1, ARR_ROWS, ARR_COLS);
	//fill_matrix_rand(*matrix_2, ARR_ROWS, ARR_COLS);

	print_matrix(*matrix_1, ARR_ROWS, ARR_COLS);

	printf("\nMultiplier matrix:\n");
	print_matrix(*matrix_2, ARR_ROWS, ARR_COLS);

	matrix_multiplier(*matrix_1, *matrix_2, *matrix_3, rows, cols);

	printf("\nNew matrix:\n");
	print_matrix(*matrix_3, ARR_ROWS, ARR_COLS);

	return 0;
}
