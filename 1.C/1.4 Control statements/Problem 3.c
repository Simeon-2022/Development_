#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHARS_PER_LINE 36
#include <conio.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>


int hexToDec(const char symbol) {
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
		iInDec = symbol - '0';
		break;
	}

	return iInDec;
};

void inputType(char line, int *base, int *lowerLimit) {
		
	switch (line)
	{
	case 'b':
	case 'B':
		*base = 2;
		*lowerLimit = 2;
		printf("Base is: Binary\n");
		break;
	case 'x':
	case 'X':
		*base = 16;
		*lowerLimit = 2;
		printf("Base is: Hex\n");
		break;
	default:
		*base = 8;
		*lowerLimit = 1;
		printf("Base is: Oct\n");
		break;
	}
}

unsigned ParseUnsignedLiteral(const char* line)
{
	int sum = 0;
	int power = 0;
	int base = 0;		int* basePointer = &base;
	int lowerLimit = 0; int* baseLowerLimit = &lowerLimit;

	
	//scanf(" %d", &base);
	inputType(line[1], basePointer, baseLowerLimit);
	int iArrLength = strlen(line);

	for (int i = iArrLength - 2; i >= lowerLimit; i--) // i >= lower limit 
	{
		int temp = hexToDec(line[i]);

		sum += temp * pow(base, power);
		power++;

	}
	// print output
	fputs("> ", stdout);
	printf("%d", sum);
	return 0;
};


int main(void)
{
	int x = 0;

	int base = 0;
	char line[MAX_CHARS_PER_LINE];


	printf("Enter sequence: ");
	fgets(line, MAX_CHARS_PER_LINE, stdin); // != 0 && line[0] != '\n')

	ParseUnsignedLiteral(line);


	return 0;
}




