#define _CRT_SECURE_NO_WARNINGS
#define ARGV_COUNT 5
#define ARGV_ARRAY_LENGTH 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

char* arguments[ARGV_ARRAY_LENGTH] = { "-c", "-w", "-l" };
char* arguments_description[ARGV_ARRAY_LENGTH] = { "Char count", "Word count", "New lines count" };

int	is_numeric(const char symbol) {

	const char* ptr = &symbol;

	if ((*ptr >= '0' && *ptr <= '9'))
	{
		return 1;
	}
	return 0;
};

int	is_alpha(const char symbol) {

	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return 1;
	}
	return 0;
}

int my_strcmp_v2(const char* arr_1, const char* arr_2) {

	for (const char* ptr_1 = arr_1, *ptr_2 = arr_2; *ptr_1 != '\0' || *ptr_2 != '\0';) //to avoid incrementing post deter zero
	{
		if (*ptr_1 > *ptr_2)
		{
			return 1;
		}
		else if (*ptr_1 < *ptr_2)
		{
			return -1;
		}

		if (*ptr_1 != '\0')
		{
			ptr_1++;
		}
		if (*ptr_2 != '\0')
		{
			ptr_2++;
		}
	}
	return 0;
};

int main(int argc, char* argv[])
{
	FILE* fp;
	char ch;
	int wordCount = 0;
	int charCount = 0;
	int newLinesCount = 0;
	bool isFound = false;

	//HW_8 HW_8_Wordcount.txt -c -w -l

	if (argc < 2 || argc > ARGV_COUNT)
	{
		fprintf(stderr, "Too many or too few arguments passed!\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) //"HW_8_Wordcount.txt"
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if (is_alpha(ch) || is_numeric(ch))
		{
			isFound = true;
		}
		else if (isFound)
		{
			wordCount++;
			isFound = false;
		}
		if (ch == '\n')
		{
			newLinesCount++;
		}
		charCount++;
	}

	if (isFound)
	{
		wordCount++;
	}

	int argumentsData[ARGV_ARRAY_LENGTH] = { charCount, wordCount, newLinesCount };

	if (argv[2] == NULL)
	{
		printf("\nWord count: %d", wordCount);
	}
	else
	{
		for (int i = 2; i < argc; i++)
		{
			bool isValid = false;
			for (int j = 0; j < ARGV_ARRAY_LENGTH; j++)
			{
				if (!my_strcmp_v2(argv[i], arguments[j]))
				{
					printf("\n%s: %d", arguments_description[j], argumentsData[j]);
					isValid = true;
					break;
				}
			}
			if (!isValid)
			{
				printf("\n\"%s\" argument invalid", argv[i]);
			}
		}
	}
	return 0;
}