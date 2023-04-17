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

int main()
{
	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line.\n\n");

	get_string_EOF(arr_1); //   bla bla b l a a a a      bla bla . => bla bla b l a a a a bla bla .

	print_string_no_blanks_(arr_1);

}

