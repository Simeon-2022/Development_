//#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
char symbol = '#', spacer = ' ';
	int height = 6;
	int lenght = height * 2;
	int count = 0;

	printf("Pattern (a):\n\n");

	for (int rows = 0; rows < height; rows++)
	{
		for (int y = 0; y < lenght - 1; y++)
		{
			if (y < count && rows != 0)
			{
				printf("%c", spacer);
			}
			else
			{
				printf("%c", symbol);
				printf("%c", spacer);
			}
		}
		if (rows != height - 1)
		{
			count += 2;

		}
		printf("\n");
	}

	printf("\n");

	printf("Pattern (b):\n\n");

	for (int rows = 0; rows < height; rows++)
	{
		for (int y = 0; y < lenght - 1; y++)
		{
			if (y < count && rows != height - 1)
			{
				printf("%c", spacer);
			}
			else
			{
				printf("%c", symbol);
				printf("%c", spacer);
			}
		}
		count -= 2;
		printf("\n");
	}

	printf("\n");

	printf("Pattern (c):\n\n");

	count = lenght - 2;

	for (int rows = 0; rows < height; rows++)
	{
		for (int y = 0; y < lenght - 1; y++)
		{
			if (y < count && rows != height - 1)
			{
				printf("%c", spacer);
			}
			else
			{
				printf("%c", symbol);
				printf("%c", spacer);
			}
		}
		if (rows != height - 1)
		{
			count -= 2;

		}
		printf("\n");
	}
	for (int rows = 1; rows < height; rows++)
	{
		count += 2;
		for (int y = 1; y < lenght; y++)
		{
			if (y <= count&& rows != 0)
			{
				printf("%c", spacer);
			}
			else
			{
				printf("%c", symbol);
				printf("%c", spacer);
			}
		}

		printf("\n");
	}
	return 0;
}
