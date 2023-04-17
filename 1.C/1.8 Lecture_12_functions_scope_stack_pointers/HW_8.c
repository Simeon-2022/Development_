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

	const int array_size = _ARR_SIZE;

	int arr[_ARR_SIZE] = { 0 };

	int minValue = 0;
	int maxValue = 0;

	printf("\nEnter lower value limit: ");
	scanf("%d", &minValue);

	printf("\nEnter upper value limit: ");
	scanf("%d", &maxValue);

	arr_manual_range_filler(arr, array_size, minValue, maxValue);

	printf("\nArray elements range [%d,%d]: ", minValue, maxValue);

	print_Array_Brackets(arr, array_size);

	return 0;
}

