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
	int newLines = 0;
	int tab_char = 0;
	int space_char = 0;

	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter your text, and press 'Ctrl + z' on a new line.\n\n");

	get_string_EOF(arr_1); 

	for (int i = 0; arr_1[i] != '\0'; i++)
	{
		if (arr_1[i] == '\n')
		{
			newLines++;
		}
		else if (arr_1[i] == '\t')
		{
			tab_char++;
		}
		else if (arr_1[i] == ' ')
		{
			space_char++;
		}
	}

	printf("New lines count: %d;\nSpace count: %d;\nTabulations count: %d;\n", newLines, space_char, tab_char);
}

