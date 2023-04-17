#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
#include <conio.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int hexToDec(char symbol) {
	int iInDec;
	switch (symbol)
	{
	case 'A':
	case 'a':
		iInDec = 10;
		break;
	case 'B':
	case 'b':
		iInDec = 11;
		break;
	case 'C':
	case 'c':
		iInDec = 12;
		break;
	case 'D':
	case 'd':
		iInDec = 13;
		break;
	case 'E':
	case 'e':
		iInDec = 14;
		break;
	case 'F':
	case 'f':
		iInDec = 15;
		break;

	default:
		iInDec = atoi(&symbol);
		break;
	}

	return iInDec;
};

int is_alpha(const char symbol) {

	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return 1;
	}
	return 0;
};

unsigned ParseUnsignedLiteral(const char line[])
{
	unsigned long sum = 0;
	int power = 0;
	int base = 0;
	int temp = 0;

	printf("Enter base: ");
	scanf(" %d", &base);
	int iArrLength = (int)strlen(line);
	for (int i = iArrLength - 2; i >= 0; i--)
	{
		if (base == 16)
		{
			temp = hexToDec(line[i]);
		}
		else if (is_alpha(line[i]))
		{
			temp = line[i];
		}
		else
		{
			char xx = line[i];
			temp = atoi(&xx);
		}

		sum += temp * (int)pow(base, power);
		power++;
	}
	// print output
	fputs("> ", stdout);
	printf("%lu", sum);
	return 0;
};


int main()
{
	int x = 0;

	int base = 0;
	char line[MAX_CHARS_PER_LINE];
	//int conversion[MAX_CHARS_PER_LINE];

	printf("Enter sequence: ");
	fgets(line, MAX_CHARS_PER_LINE, stdin); // != 0 && line[0] != '\n')

	ParseUnsignedLiteral(line);


	return 0;
}




