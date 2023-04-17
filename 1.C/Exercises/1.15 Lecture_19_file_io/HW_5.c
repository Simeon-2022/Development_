#define _CRT_SECURE_NO_WARNINGS
#define LINE_LENGTH 30
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

enum redactor
{
	create_new = 1,
	append
}redactor_mode;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL)); //C:\Users\Simeon\source\repos\ConsoleApplication1\Meeting_19>HW_5 HW_04_Names.txt HW_04_Family_Names.txt HW_04_Random.txt
	FILE* fp_1;
	FILE* fp_2;
	FILE* fp_3;

	if (argc != 4)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp_1 = fopen(argv[1], "r")) == NULL)//"HW_04_Names.txt"
	{
		printf("File missing or corrupted %s", argv[1]); 
		exit (EXIT_FAILURE);
	}
	else if ((fp_2 = fopen(argv[2], "r")) == NULL)//"HW_04_Family_Names.txt"
	{
		printf("File missing or corrupted %s", argv[2]); 
		exit (EXIT_FAILURE);
	}
	

	char names[LINE_LENGTH];
	char family_Names[LINE_LENGTH];
	char random_Names[LINE_LENGTH];
	char* mode[2] = { "w","a+" };

	fp_1 = fopen(argv[1], "r");
	fp_2 = fopen(argv[2], "r");

	int number_names = 8;
	int random_name = 0;
	int random_family = 0;
	int generations = 0;
	char menu_Y_N = 'y';

	while (menu_Y_N != 'n')
	{
		printf("How many pairs would you like? > ");
		scanf("%d", &generations);

		printf("\n > Create new list = 1\n > Append = 2\n\n > Your choice >> ");
		scanf("%d", &redactor_mode);

		fp_3 = fopen(argv[3], mode[redactor_mode - 1]);

		for (int i = 0; i < generations; i++)
		{

			while (random_name == random_family)
			{
				random_name = (1 + rand() % (number_names));
				random_family = (1 + rand() % (number_names));
			}

			for (int i = 0; i < random_name; i++)
			{
				fscanf(fp_1, "%s", names);
			}

			for (int i = 0; i < random_family; i++)
			{
				fscanf(fp_2, "%s", family_Names);
			}

			fprintf(fp_3, "%s", names);
			fprintf(fp_3, " ");
			fprintf(fp_3, "%s", family_Names);
			fprintf(fp_3, "\n");

			rewind(fp_1);
			rewind(fp_2);

			random_name = (1 + rand() % (number_names + 1));
			random_family = (1 + rand() % (number_names + 1));
		}

		fclose(fp_3);
		fp_3 = fopen(argv[3], "r");

		putchar('\n');

		int count_list = 0;

		while (count_list++, fgets(random_Names, LINE_LENGTH, fp_3) != NULL)
		{
			printf(" %d. ", count_list);
			fputs(random_Names, stdout);
		}
		printf("\n > Continue y(es) or n(o) >> ");
		scanf(" %c", &menu_Y_N);
		putchar('\n');
		fclose(fp_3);
	}

	fclose(fp_1);
	fclose(fp_2);
	
	return EXIT_SUCCESS;
}