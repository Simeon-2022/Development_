#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 20
#include <stdio.h>
#include <stdbool.h>
#include "My_Functions.h"



int main()
{
	int index = 0; int* indexCount = &index;
	int number = 0;

	const int array_size = _ARR_SIZE;

	int arr_1[_ARR_SIZE] = {0};
	
	int* arr_1_Ptr = arr_1;
	
	arr_Manual_filler(arr_1_Ptr, array_size);

	printf("Enter a number: ");
	scanf("%d", &number);

	print_Unique_Numbers(number, count_Unique_Numbers(arr_1_Ptr, array_size, number));

}






