#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions_12.h"


int main()
{
	srand((unsigned int)time(NULL));

	int choice = 0;
	const int array_size = _ARR_SIZE;

	int arr[_ARR_SIZE] = { 0 };

	arr_Manual_filler(arr,array_size);

	printf("\nArray elements: ");
	print_Array_Brackets(arr, array_size);

	do
	{
		printf("\nPossible actions:\n"
			"\n -> Calculate the product(*) of all numbers in array [1]"
			"\n -> Calculate the average(+) of all numbers in array [2]"
			"\n -> Overwrite array with 'rand()' generator          [3]"
			"\n -> For exit enter                                   [0]\n");

		printf("\nWhat action do you want to perform: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			system("cls");
			printf("\nMultiplication result is: %llu\n", multiplication_Array_Range(arr, array_size));
			printf("\nArray elements: ");
			print_Array_Brackets(arr, array_size);
			break;
		case 2:
			system("cls");
			printf("\nArithmetic average of array elements = %.2lf;\n", arithmetic_Average(arr, array_size));
			printf("\nArray elements: ");
			print_Array_Brackets(arr, array_size);
			break;

		case 3:

		{int minValue = 0, maxValue = 0;

		printf("\nEnter lower value limit: ");
		scanf("%d", &minValue);

		printf("\nEnter upper value limit: ");
		scanf("%d", &maxValue);

		arr_range_filler_w_min_max(arr, minValue, maxValue,array_size);

		printf("\nNew array between range [%d,%d]: ", minValue, maxValue);

		print_Array_Brackets(arr, array_size);
		}
		break;

		default:

			break;
		}

	} while (choice != 0);
	return 0;
}
