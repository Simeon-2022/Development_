#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "My_Functions.h"


int main()
{
	//srand((unsigned int)time(NULL));
	const int array_size = _ARR_SIZE;

	int arr_1[_ARR_SIZE] = {0};
	int arr_2[_ARR_SIZE] = {0};

	int* arr_1_Ptr = arr_1;
	int* arr_2_Ptr = arr_2;

	arr_Manual_filler(arr_1_Ptr, array_size);

	arr_copy(arr_1_Ptr, arr_2_Ptr, array_size);

	printf("Array arr_1[%d] = ", array_size);
	print_Array(arr_1_Ptr, array_size);

	printf("Array arr_2[%d] = ", array_size);
	print_Array(arr_2_Ptr, array_size);

}





