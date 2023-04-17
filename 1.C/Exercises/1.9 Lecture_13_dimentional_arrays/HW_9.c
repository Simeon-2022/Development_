/*
Задача 5
Напишете функция, която разменя две колони на матрица, по подадени аргументи за
индекси на колоните, които да се разменят.

*/

#define _CRT_SECURE_NO_WARNINGS
#define ARR_ROWS 4
#define ARR_COLS 4
//#define ARR_SIZE 100

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

	int matrix_1[ARR_ROWS][ARR_COLS] = { 0 }; // { {0, 1, 1, 1}, { 1,1,0,1 }, { 1,0,1,1 }, { 1,1,1,1 } };

	fill_matrix_rand_int(*matrix_1, ARR_ROWS, ARR_COLS);

	print_matrix_no_decimal_int(*matrix_1, ARR_ROWS, ARR_COLS);

	printf("\nUnique columns: --> ");
	printf("%d\n", unique_columns(* matrix_1, ARR_ROWS, ARR_COLS));
	return 0;
}
