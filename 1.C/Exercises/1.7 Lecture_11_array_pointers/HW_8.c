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
	//srand(time(NULL));

	int index_2 = 0; int* index_2_Count = &index_2;
	int index_3 = 0; int* index_3_Count = &index_3;
	
	const int array_size = _ARR_SIZE;

	int arr_1[_ARR_SIZE] = { 0 };
	int arr_odd[_ARR_SIZE] = { 0 };
	int arr_even[_ARR_SIZE] = { 0 };

	int* arr_1_Ptr = arr_1;
	int* arr_2_Ptr = arr_odd;
	int* arr_3_Ptr = arr_even;

	arr_Manual_filler(arr_1_Ptr, array_size);

	find_odd_even_numbers(arr_1_Ptr, arr_2_Ptr, arr_3_Ptr, &index_2, &index_3, array_size);
	
	printf("\nOriginal array: ");
	print_Array(arr_1_Ptr, array_size);

	printf("\nFound (%d) Odd numbers in array: ", index_2);
	print_Array_To_Index(arr_2_Ptr, index_2);

	printf("\nFound (%d) Even numbers in array: ", index_3);
	print_Array_To_Index(arr_3_Ptr, index_3);
}

