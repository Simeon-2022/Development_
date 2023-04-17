#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
#define ROW_SIZE 100
#define COL_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"


int main(void) {

	char arr_1[ARR_SIZE] = { '\0' };

	get_string_EOF(arr_1);

	print_reversed_char_array(arr_1);

	return 0;
}