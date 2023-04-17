#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	FILE* fpRead;
	//FILE* fpWrite;
	char ch;

	if (argc < 2)
	{
		printf("\nEnter input below:\n > ");
		while ((ch = fgetc(stdin)) != EOF)
		{
			fputc(ch, stdout);
		}
	}
	else
	{

		for (int i = 1; i < argc; i++) // pRead = fopen(argv[i], "r") != NULL does not work?? - ask
		{
			fpRead = fopen(argv[i], "r");
			if (fpRead == NULL)
			{
				printf("\n\"%s\" argument invalid\n", argv[i]);
			}
			else
			{
				putchar('\n');
				while ((ch = fgetc(fpRead)) != EOF)
				{
					fputc(ch, stdout);
				}

			}


		}
	}

	return 0;
}