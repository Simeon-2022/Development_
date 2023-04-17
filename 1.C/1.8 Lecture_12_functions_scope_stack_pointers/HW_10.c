/*Задача 10
Напишете функция, която приема два масива от цели числа с
еднакъв размер и разменя стойностите на елементите им
*/
#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 10
#include <stdio.h>
//#include <stdlib.h>
//include <time.h>
//#include <stdbool.h>
#include "Functions_12.h"

int main()
{
	//srand((unsigned int)time(NULL));
	const int array_size = _ARR_SIZE;

	int arr_1[_ARR_SIZE] = { 0 };
	int arr_2[_ARR_SIZE] = { 0 };

	int* arr_1_Ptr = arr_1;
	int* arr_2_Ptr = arr_2;

	arr_rand_filler_preset_values(arr_1, array_size);
	arr_rand_filler_preset_values(arr_2, array_size);


	printf("Original array arr_1[%d] = ", array_size);
	print_Array_Brackets(arr_1, array_size);

	printf("Original array arr_2[%d] = ", array_size);
	print_Array_Brackets(arr_2, array_size);
	
	array_exchange(arr_1_Ptr, arr_2_Ptr, array_size);

	printf("\nSwapped array arr_1[%d]  = ", array_size);
	print_Array_Brackets(arr_1, array_size);

	printf("Swapped array arr_2[%d]  = ", array_size);
	print_Array_Brackets(arr_2, array_size);
}
