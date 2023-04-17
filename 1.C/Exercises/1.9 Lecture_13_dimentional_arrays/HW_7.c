/*
Задача 7
Напишете функция, която умножава 3-мерен float вектор(едномерен масив с три
float елемента) по 3x3 float матрицa
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
	float array[ARR_COLS] = { 2.0f,3.0f,5.0f };

	printf("\nOld matrix:\n");
	print_matrix(*matrix, ARR_ROWS, ARR_COLS);

	printf("\nMultiplier:\n");
	print_Array_Brackets(array, ARR_COLS);

	array_matrix_multiplier(* matrix, ARR_ROWS, ARR_COLS, array);

	printf("\nNew matrix:\n");
	print_matrix(*matrix, ARR_ROWS, ARR_COLS);

	printf("\nNew float array:\n");
	print_Array_Brackets(array, ARR_COLS);
	return 0;
}