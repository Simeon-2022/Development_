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
	int count_chars = 0;
	int count_words = 0;
	int non_alpha_numeric = 0;
	float average_letter_count = 0;

	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line:\n=============================================\n");

	get_string_EOF(arr_1);

	printf("\n=============================================\n");

	for (const char* arr_ptr = arr_1; *arr_ptr != '\0'; arr_ptr++)
	{
		bool is_letter = false;

		if (is_alpha(*arr_ptr) || is_numeric(*arr_ptr)) //?ddd  ddd
		{
			is_letter = true;
			count_chars++;
			non_alpha_numeric = 0;
		}
		else
		{
			non_alpha_numeric++;
		}

		if (count_chars && !is_letter && (non_alpha_numeric == 1))
		{
			count_words++;
		}
	}

	average_letter_count = (float)(count_chars / (float)(count_words) );

	printf("Average letters per word: %d letters / %d words = %.2f\n", count_chars, count_words, average_letter_count);

	return 0;
}
/*
!@# we we w wwww. A ksdjdd
sdd, sddsd jk 32323 sddd
wewr err er 11 1 1 1ffff
^Z
*/
