#define _CRT_SECURE_NO_WARNINGS
#define LINE_LENGTH 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Writing and readin to a file using "fgetc" and "fputc" : The fputc() function is used to write/read a single character into file. It outputs a character to a stream.

int main(void)
{
	FILE* fp_2;
	fp_2 = fopen("HW_02_getc_and_putc.txt", "w");
	
	if (fp_2 == NULL)
	{
		printf("File could not be opened.");
		exit(1);
	}
	else
	{
		printf("\nEnter input below:\n > ");
		char ch;
		while ((ch = getchar()) != EOF)
		{
			fputc(ch, fp_2);
		}
		fclose(fp_2);
	}

	fp_2 = fopen("HW_02_getc_and_putc.txt", "r");

	if (fp_2 == NULL)
	{
		printf("File could not be opened.");
		exit(1);
	}
	else
	{
		printf("\nRead the extracted text below:\n > ");
		char ch;
		while ((ch = fgetc(fp_2)) != EOF)
		{
			putchar(ch);
		}

		fclose(fp_2);
	}

	return 0;
}