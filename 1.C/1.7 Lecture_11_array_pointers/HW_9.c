#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "My_Functions.h"

int main()
{
	srand((unsigned int)time(NULL));

	int shift = 0;
		
	int arr_1[_ARR_SIZE] = {0};

	const int array_size = _ARR_SIZE;

	int* arr_1_Ptr = arr_1;
	//char arr7[] = { [8] = 'a' };
	arr_Manual_filler(arr_1_Ptr, array_size);

	printf("\nEnter number of shift cycles: ");
	scanf("%d", &shift);

	printf("\nOriginal array sequence: ");
	print_Array(arr_1_Ptr, array_size);

	printf("\n");

	shift_array_elements(arr_1_Ptr, shift, array_size);

	printf("\nShifted array with %d cycles: ", shift);
	print_Array(arr_1_Ptr, array_size);

	return 0;
}

