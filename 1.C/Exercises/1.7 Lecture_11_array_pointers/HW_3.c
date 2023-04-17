#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "My_Functions.h"


int main()
{
	srand((unsigned int)time(NULL));

	int number = 0;
	
	int array_size = _ARR_SIZE;

	int arr_1[_ARR_SIZE] = {0};

	int* arr_1_Ptr = arr_1;

	arr_filler(arr_1_Ptr,array_size);

	printf("\nRandom array arr_1[%d] = ",array_size);
	print_Array(arr_1_Ptr, array_size);

	biggest_Number(arr_1_Ptr, array_size);
}




