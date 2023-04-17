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
	int alpha_char = 0;
	int punct_char = 0;
	int special_char = 0;
	
	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line.\n\n");

	get_string_EOF(arr_1); // "Hello, how are you?" - #)(@ said he.

	for (int i = 0; arr_1[i] != '\0'; i++)
	{
		if (is_alpha(arr_1[i]))
		{
			alpha_char++;
		}
		else if (is_punctuation(arr_1[i]))
		{
			punct_char++;
		}
		else if (is_special_character(arr_1[i]))
		{
			special_char++;
		}
	}

	printf("Special symbols count: %d;\nLetters count: %d;\nPunctuals count: %d;\n", special_char, alpha_char, punct_char);
}

