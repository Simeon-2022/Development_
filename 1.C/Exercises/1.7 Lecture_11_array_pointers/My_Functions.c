#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "My_Functions.h"

//#define _ARR_MAX_SIZE 10

// HW_1__________________________________________________________________
void arr_Manual_filler(int* begin, int array_size) {

	int dummyVar = 0;
	int count = 0;

	printf("Please enter an array sequence of %d integers: \n", array_size);

	for (int* ptr = begin; ptr < (begin + array_size); ptr++)
	{
		printf("%d --> ", ++count);
		scanf("%d", &dummyVar);
		*ptr = dummyVar;
	}
	printf("\n");
}

void arr_filler(int* begin, int array_size) {

	int count = 0;

	printf("Random array sequence of [%d] integers is being generated:", array_size);

	for (int* ptr = begin; ptr < (begin + array_size); ptr++)
	{
		int dummyVar = rand() % (100 + 1);

		count++;

		//check for repeating values

		if (isFound(begin, count, dummyVar))
		{
			ptr--;
			count--;
		}
		else
		{
			*ptr = dummyVar;
		}

		printf(".");
		Sleep(50); // just for fun, adds no functionality at all

	}

	printf("Done.\n\n");
	Sleep(50);
}

void print_Array(int* begin, int array_size) {

	printf("{ ");

	for (int* arr_Ptr = begin; arr_Ptr < (begin + array_size); arr_Ptr++)
	{
		Sleep(50);
		printf("%d", *arr_Ptr);
		if (arr_Ptr < (begin + array_size) - 1)
		{
			printf(", ");
		}
		else
		{
			printf(" }");
		}
	}
	putchar('\n');
}

void compare(int* begin, int number, int array_size) {

	int index = 0;
	bool check = false;
	for (int* arr_Ptr = begin; arr_Ptr < (begin + array_size); arr_Ptr++)
	{
		if (*arr_Ptr == number)
		{
			printf("\nYour number is found at index: [%d]", index);
			check = true;
			break;
		}
		index++;
	}

	if (!check)
	{
		printf("\nYour number is NOT part of the array!");
	}
	putchar('\n');
}

int isFound(int* begin, int count, int dummyVar) {
	for (int* ptr = begin; ptr < (begin + count); ptr++)
	{
		if (dummyVar == *ptr)
		{
			//isFound = true;

			return 1;
		}
	}
	return 0;
}

void arr_copy(int* begin_arr_1, int* begin_arr_2, int size) {

	for (int* ptr_2 = begin_arr_2, *ptr_1 = begin_arr_1; ptr_1 < (begin_arr_1 + size); ptr_1++, ptr_2++)
	{
		*ptr_2 = *ptr_1 * 2;
	}
}

// HW_3_____________________________________________________________
void biggest_Number(int* begin, int array_size) {

	int number = INT_MIN;
	int index = 0;

	for (int* arr_Ptr = begin, counter = 0; arr_Ptr < (begin + array_size); counter++, arr_Ptr++)
	{
		if (*arr_Ptr > number)
		{
			number = *arr_Ptr;
			index = counter;
		}
	}

	printf("\nThe biggest number is (%d), found at index: [%d]", number, index);

	putchar('\n');
}

// HW_4_____________________________________________________________
void print_Array_In_Reverse(int* begin, int array_size) {

	printf("{ ");

	for (int* arr_Ptr = (begin + array_size) - 1; arr_Ptr >= begin; arr_Ptr--)
	{
		Sleep(50);
		printf("%d", *arr_Ptr);
		if (arr_Ptr > begin)
		{
			printf(", ");
		}
		else
		{
			printf(" }");
		}
	}
	putchar('\n');
}

// HW_5_____________________________________________________________

void print_Array_To_Index(int* begin, int index) {

	if (index == 0)
	{
		printf("{ }");
	}
	else {
		printf("{ ");

		for (int* arr_Ptr = begin; arr_Ptr < (begin + index); arr_Ptr++)
		{
			Sleep(50);
			printf("%d", *arr_Ptr);
			if (arr_Ptr < (begin + index) - 1)
			{
				printf(", ");
			}
			else
			{
				printf(" }");
			}
		}
	}
	putchar('\n');
}

void find_Unique_Numbers(int* begin_arr_1, int* begin_arr_2, int* indexCount, int array_size) {


	int* ptr_end = (begin_arr_1 + array_size);
	int* subPtr = begin_arr_2;

	for (int* ptr = begin_arr_1; ptr < ptr_end; ptr++)
	{
		bool isDuplicate = false;

		if (is_Duplicate(begin_arr_1, array_size, *ptr) > 1)
		{
			continue;
		}
		else
		{
			*(subPtr++) = *ptr;
			(*indexCount)++;
		}
	}
}

int is_Duplicate(int* begin, int array_size, int current) {

	int count = 0;

	for (int* ptr = begin; ptr < (begin + array_size); ptr++)
	{
		if (current == *ptr)
		{
			count++;
		}
		if (count > 1)
		{
			break;
		}
	}
	return count;
}


// HW_6_____________________________________________________________

int  count_Unique_Numbers(int* begin_arr_1, int array_size, int number) {

	int occurrencesCount = 0;
	for (int* Ptr = begin_arr_1; Ptr < (begin_arr_1 + array_size); Ptr++)
	{
		if (*Ptr == number)
		{
			occurrencesCount++;
		}
	}
	return occurrencesCount;
}

void print_Unique_Numbers(int number,int timesFound) {

	if (timesFound > 0)
	{
		printf("\nYour number [%d] in arr_1 is found [%d] time(s)\n", number, timesFound);
	}
	else
	{
		printf("\nYour number [%d] in arr_1 does not exist!\n", number);
	}
}


// HW_7_____________________________________________________________
void smallest_Number(int* begin, int array_size) {

	int number = INT_MAX;
	int index = 0;

	for (int* arr_Ptr = begin, counter = 0; arr_Ptr < (begin + array_size); counter++, arr_Ptr++)
	{
		if (*arr_Ptr < number)
		{
			number = *arr_Ptr;
			index = counter;
		}
	}

	printf("\nThe smallest number is (%d), found at index: [%d]", number, index);

	putchar('\n');
}


// HW_8_____________________________________________________________

void find_odd_even_numbers(int* begin_arr_1, int* begin_arr_2, int* begin_arr_3, int* index_2_Count, int* index_3_Count, int array_size) {

	for (int* ptr_1 = begin_arr_1, *ptr_2 = begin_arr_2, *ptr_3 = begin_arr_3; ptr_1 < (begin_arr_1 + array_size); ptr_1++)
	{
		if (*ptr_1 % 2 == 0)
		{
			*(ptr_3++) = *ptr_1;
			(*index_3_Count)++;
		}
		else
		{
			*(ptr_2++) = *ptr_1;
			(*index_2_Count)++;
		}
	}
}

// HW_9_____________________________________________________________

void shift_array_elements(int* begin, int shift, int array_size) {


	for (int* ptr = begin, i = 0; i < shift; i++)
	{
		int temp = *begin;

		for (ptr = begin; ptr < (begin + array_size) - 1; ptr++)
		{
			*ptr = *(ptr + 1);
		}
		*ptr = temp;
		printf("shift-> %d: ", i + 1);
		print_Array(begin, array_size);
	}
}