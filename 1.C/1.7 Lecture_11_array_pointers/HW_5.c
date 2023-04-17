#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "My_Functions.h"




int main()
{
	int index = 0; int* indexCount = &index;

	int array_size = _ARR_SIZE;
	
	int arr_1[_ARR_SIZE] = {0};
	int arr_2[_ARR_SIZE] = {0};

	int* arr_1_Ptr = arr_1;
	int* arr_2_Ptr = arr_2;

	arr_Manual_filler(arr_1_Ptr, array_size);

	find_Unique_Numbers(arr_1_Ptr, arr_2_Ptr, &index, array_size);

	printf("--> %d unique numbers found in arr_1[%d] = ",index, array_size);
	print_Array_To_Index(arr_2_Ptr, index);
}






