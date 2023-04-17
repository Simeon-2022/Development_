#define _CRT_SECURE_NO_WARNINGS
#define LINE_LENGTH 300
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Writing and readin to a file using "fscanf" and "fprintf" : The function is used to write/read set of characters into file. It sends formatted output to a stream.
int main(void)
{

	char buff[LINE_LENGTH];

	while (fscanf(stdin, "%s", buff) != EOF) {

		fprintf(stdout, "%s", buff);
	}


	FILE* fp;

	fp = fopen("HW_03_fscanf_and_fprintf.txt", "w");

	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open file!");
		exit(0);
	}
	else
	{
		printf("\nEnter input below:\n > ");
		while(fscanf(stdin,"%s", buff) == 1)
		{
			
			fprintf(fp, "%s", buff);
		}
		fclose(fp);
	}

	fp = fopen("HW_03_fscanf_and_fprintf.txt", "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Cannot read file!");
		exit(0);
	}
	else
	{
		printf("\nRead the extracted text below:\n > ");
		while (fscanf(fp,"%s", buff) == 1) {

			printf("%s", buff);
		}
		fclose(fp);
	}

	return 0;
}