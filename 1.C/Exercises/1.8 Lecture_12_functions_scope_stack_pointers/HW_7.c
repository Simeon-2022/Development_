#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 20
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions_12.h"



int main()
{
	srand((unsigned int)time(NULL));

	const int array_size = _ARR_SIZE;

	int arr[_ARR_SIZE] = { 0 };

	int minValue = 0;
	int maxValue = 0;
	
	printf("\nEnter negative(-) value limit: ");
	scanf("%d", &minValue);

	printf("\nEnter upper value limit: ");
	scanf("%d", &maxValue);

	arr_range_filler_w_min_max(arr, minValue, maxValue, array_size);

	printf("\nArray elements range: ");
	print_Array_Brackets(arr, array_size);

	null_Negative_Values(arr, array_size);

	printf("\nArray nullified elements: ");
	print_Array_Brackets(arr, array_size);



	return 0;
}

