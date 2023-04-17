
#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
#include "Functions_12.h"

int main()
{
	const int array_size = _ARR_SIZE;

	int arr[_ARR_SIZE] = {0};

	arr_Manual_filler(arr, array_size);

	printf("\nArray elements: ");
	print_Array_Brackets(arr, array_size);

	return 0;
}

