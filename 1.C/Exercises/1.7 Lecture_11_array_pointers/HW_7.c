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
	int arr_1[_ARR_SIZE] = {0};

	const int array_size = _ARR_SIZE;

	int* arr_1_Ptr = arr_1;

	arr_Manual_filler(arr_1_Ptr, array_size);
	
	printf("\nArray arr_1[20] = ");
	print_Array(arr_1_Ptr, array_size);

	biggest_Number(arr_1_Ptr, array_size);
	smallest_Number(arr_1_Ptr, array_size);

}


