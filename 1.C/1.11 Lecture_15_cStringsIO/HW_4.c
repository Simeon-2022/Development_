#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
#define ROW_SIZE 100
#define COL_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"

int main()
{
	char arr_1[ARR_SIZE] = { '\0' };
	char matrix[ROW_SIZE][COL_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line.\n\n");

	get_string_EOF(arr_1); // BlAAA bLa b_l_A9/11a a10a10aAA  569  bla bla .

	print_matrix_char(select_capital_lower_numeric(*matrix, COL_SIZE, arr_1), ROW_SIZE, COL_SIZE);

	return 0;
}

