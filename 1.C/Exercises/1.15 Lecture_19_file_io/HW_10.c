#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

int	is_numeric(const char symbol) {

	const char* ptr = &symbol;

	if ((*ptr >= '0' && *ptr <= '9'))
	{
		return 1;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	FILE* fp_READ;
	FILE* fp_WRIGHT;

	char ch;
	char char_array[ARR_SIZE] = { '\0' };

	fp_READ = fopen("HW_10_input.txt", "r");
	fp_WRIGHT = fopen("HW_10_output.txt", "w");

	int idx = 0;
	while ((ch = fgetc(fp_READ)) != EOF)
	{
		if (is_numeric(ch))
		{
			char_array[idx] = ch;
			idx++;
		}
		else
		{
			if (char_array[0] != '\0')
			{
				int charToInt = atoi(char_array) * 2;
				sprintf(char_array, "%d", charToInt);

				for (int i = 0; char_array[i] != '\0'; i++)
				{
					fputc(char_array[i], fp_WRIGHT);
				}

				for (int i = 0; i < ARR_SIZE && char_array[i] != '\0'; i++)
				{
					char_array[i] = '\0';
				}
				idx = 0;
			}
			fputc(ch, fp_WRIGHT);
		}
	}
	fclose(fp_READ);
	fclose(fp_WRIGHT);

	return 0;
}