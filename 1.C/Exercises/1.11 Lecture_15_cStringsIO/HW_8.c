#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 7
#define ROW_SIZE 100
#define COL_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"

int main(void)
{
	double d_input_1 = 0.0;
	double d_input_2 = 0.0;
	double d_result = 0.0;
	char operand = ' ';
	char* ptr = &operand;

	char input_arr[ARR_SIZE] = { '\0' };

	print_menu();
	putchar(' ');
	operand = getchar();
	validate_input(&operand);

	while (operand != 'q')
	{
		getchar();
		printf("Enter first number: ");
		scanf("%s", input_arr);

		while (!is_digit(input_arr))
		{
			printf("'%s' is not a proper number!\n", input_arr);
			printf("Please enter a valid number e.g 2.5, -1.78, 3 etc.: ");
			scanf("%s", input_arr);
		}

		d_input_1 = conversion_type(is_digit(input_arr), input_arr);

		printf("\nEnter second number: ");
		scanf("%s", input_arr);
		putchar('\n');

		while (!is_digit(input_arr) || is_digit(input_arr) == 3)
		{
			if (is_digit(input_arr) == 3 && operand == 'd')
			{
				printf("Division by '0' is not allowed!\n");
			}
			else if (is_digit(input_arr) == 3 && operand != 'd')
			{
				break;
			}
			else
			{
				printf("'%s' is not a proper number!\n", input_arr);
			}
			printf("Please enter a valid number e.g 2.5, -1.78, 3 etc.: ");
			scanf("%s", input_arr);
			putchar('\n');
		}

		d_input_2 = conversion_type(is_digit(input_arr), input_arr);

		operation(operand, d_result, d_input_1, d_input_2);

		print_menu();
		putchar(' ');

		getchar();
		operand = getchar();
		validate_input(&operand);

		d_input_1 = 0.0;
		d_input_2 = 0.0;
		d_result = 0.0;
	};


	return 0;
}

