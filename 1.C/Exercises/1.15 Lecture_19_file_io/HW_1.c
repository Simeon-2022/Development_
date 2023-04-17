#define _CRT_SECURE_NO_WARNINGS
#define LINE_LENGTH 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
//#include "Functions_19.h"

int main(void)
{
	// The fputs() and fgets() in C programming are used to write and read string from stream.
	// Writing and reading to stadard console using "fgets" and "fputs"
	
	char line[LINE_LENGTH];

	while (fgets(line, LINE_LENGTH, stdin) != NULL)
	{
		fputs(line, stdout);
	}

	// Writing and reading to a file using "fgets" and "fputs"
	
	FILE* fp_1;

	fp_1 = fopen("HW_01_fgets_and_fputs.txt", "w");

	if (fp_1 == NULL)
	{
		printf("File could not be opened.");
		exit(1);
	}
	else
	{
		printf("\nEnter input below:\n > ");
		while (fgets(line,LINE_LENGTH,stdin) != NULL)
		{
			fputs(line,fp_1);
		}
		fclose(fp_1);
	}

	fp_1 = fopen("HW_01_fgets_and_fputs.txt", "r");

	if (fp_1 == NULL)
	{
		printf("File could not be opened.");
		exit(1);
	}
	else
	{
		printf("\nRead the extracted text below:\n > ");
		while (fgets(line, LINE_LENGTH,fp_1) != NULL)
		{
			fputs(line, stdout);
		}
		fclose(fp_1);
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
