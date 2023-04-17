#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int new_line_count(const char* arr_1) {
	int counter = 0;
	for (const char* ptr = arr_1; *ptr != '\0'; ptr++)
	{
		if (*ptr == '\n')
		{
			counter++;
		}
	}
	return counter;
};

int main(void)
{
	char arr_1[ARR_SIZE] = { '\0' };
	printf("\nType in your multiline string. Terminate input with ctrl+Z [^Z]:\n\n");

	get_string_EOF(arr_1);

	printf("\nNumber of new lines: %d", new_line_count(arr_1));


	return 0;
}
