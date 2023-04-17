/*
Задача 4
Напишете функция, която размерня два реда на матрица, по подадени аргументи за
индекси на редовете, които да се разменят.
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

	float matrix_1[ARR_ROWS][ARR_COLS] = { {1.0f,2.0f,3.0f},{4.0f,5.0f,6.0f},{7.0f,8.0f,9.0f} };
	
	int row_swap_1 = 0;
	int row_swap_2 = 0;
	int columns = 0;

	print_matrix(*matrix_1, ARR_ROWS, ARR_COLS);
	
	printf("\nSelect 1st row from[0] to [%d]", ARR_ROWS);
	scanf("%d", &row_swap_1);

	printf("\nSelect 2nd row from[0] to [%d]", ARR_ROWS);
	scanf("%d", &row_swap_2);

	swap_rows(*matrix_1, ARR_COLS, &row_swap_1, &row_swap_2);

	print_matrix(*matrix_1, ARR_ROWS, ARR_COLS);
	return 0;
}