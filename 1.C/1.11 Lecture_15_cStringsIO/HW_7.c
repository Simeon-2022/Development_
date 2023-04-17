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

int main(void)
{
	int count_chars = 0;
	int count_words = 0;
	int non_alpha_numeric = 0;
	float average_letter_count = 0;

	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line:\n=============================================\n");

	get_string_EOF(arr_1);

	printf("Remove whitespace characters(space, newline, tab)\n=============================================\n");

	for (int i = 0; arr_1[i] != '\0'; i++)
	{
		if ((arr_1[i] != '\n') && (arr_1[i] != '\t') && (arr_1[i] != ' '))
		{
			putchar(arr_1[i]);
		}
	}
	putchar('\n');

	return 0;
}
/*
!@# we we w wwww. A ksdjdd
sdd, sddsd jk 32323 sddd
wewr err er 11 1 1 1ffff
^Z
*/
