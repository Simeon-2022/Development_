#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "Functions_12.h"


// HW_1
unsigned long long range_factoriel_recursion(int min, int max) {


	if (min <= max)
	{
		return range_factoriel_recursion(min + 1, max) * min;
	}
	else
	{
		return 1;
	}
}

// HW_2

unsigned long long multiplication_Array_Range(const int* begin, const int array_size) {

	unsigned long long product = 1;

	for (int* arr_ptr = begin; arr_ptr < (begin + array_size); arr_ptr++)
	{
		product *= *arr_ptr;
	}

	return product;
}

void arr_Manual_filler(const int* begin, int array_size) {

	//int dummyVar = 0;
	int count = 0;

	printf("Please enter an array sequence of %d integers: \n", array_size);

	for (int* ptr = begin; ptr < (begin + array_size); ptr++)
	{
		printf("%d --> ", ++count);
		scanf("%d", &*ptr);//make it with pointer
		//*ptr = dummyVar;
	}
	printf("\n");
}

// HW_3

double arithmetic_Average(const int* begin, int array_size) {

	unsigned long long product = 0;

	for (int* arr_ptr = begin; arr_ptr < (begin + array_size); arr_ptr++)
	{
		product += *arr_ptr;
	}

	return (double)(product * 1.0 / array_size);
}

// HW_4

void print_Array_Brackets(const int* begin, int array_size) {

	for (int* arr_Ptr = begin; arr_Ptr < (begin + array_size); arr_Ptr++)
	{
		Sleep(25);
		printf("[");
		printf("%d", *arr_Ptr);
		printf("]");

	}
	putchar('\n');
}

// HW_5

int abs(int number) {
	return (number < 0) ? -number : number;
}

int isFound(const int* begin, int count, int dummyVar) {
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

void arr_range_filler_w_min_max(const int* begin, int minValue, int maxValue, int array_size) {

	int range = maxValue - minValue;
	/*if (range > array_size)
	{
		*limit = array_size;
	}
	else
	{
		*limit = range;
	}*/
	printf("\nRandom array sequence of [%d,%d] integers is being generated:", minValue, maxValue);

	for (int count = 0, *ptr = begin; ptr < (begin + array_size); ptr++, count++)
	{
		int dummyVar = minValue + rand() % (range + 1);
		/*
		//No check for repeating values --> if arr[1000] but range is 1-10, we must have repetition
		if (isFound(ptr, begin, count, dummyVar))
		{
			ptr--;
			count--;
		}
		else
		{
			*ptr = dummyVar;
		}*/
		* ptr = dummyVar;

		system("cls");
		printf("\nRandom array sequence of [%d,%d] integers is being generated. %.1f %% complete..\n\nWorking lease wait..", minValue, maxValue, (float)(count + 1) / array_size * 100);
		Sleep(55); // just for fun, adds no functionality at all
	}

	system("cls");

}

// HW_7

void null_Negative_Values(const int* begin, int array_size) {

	for (int* arr_ptr = begin; arr_ptr < (begin + array_size); arr_ptr++)
	{
		if (*arr_ptr < 0)
		{
			*arr_ptr = 0;
		}
	}
}

// HW_8

int range_check_w_min_max(int minValue, int maxValue, int array_element) {

	if (array_element < minValue)
	{
		printf("\nElement is below range! Make a new entry below:\n");
		return 0;
	}
	else if (array_element > maxValue)
	{
		printf("\nElement is above range! Make a new entry below:\n");
		return 0;
	}
	else
	{
		return 1;
	}


}

void arr_manual_range_filler(const int* begin, const int array_size, int minValue, int maxValue) {

	int dummyVar = 0;
	int count = 1;

	printf("\nPlease enter an array sequence of %d integers: \n", array_size);

	for (int* ptr = begin; ptr < (begin + array_size); ptr++)
	{
		printf("%d --> ", count);
		scanf("%d", &dummyVar);

		if (!range_check_w_min_max(minValue, maxValue, dummyVar))
		{
			ptr--;
			continue;
		}
		count++;
		*ptr = dummyVar;
	}
	printf("\n");
}

// HW_8
void arr_copy(const int* begin_arr_1, const int* begin_arr_2, int array_size) {

	for (int* ptr_2 = begin_arr_2, *ptr_1 = begin_arr_1; ptr_1 < (begin_arr_1 + array_size); ptr_1++, ptr_2++)
	{
		*ptr_2 = *ptr_1;
	}
}

// HW_10

void arr_rand_filler_preset_values(const int* begin, int array_size) {

	int count = 0;

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
	}
}


void array_exchange(const int* begin_arr_1, const  int* begin_arr_2, int array_size) {
	for (int* ptr_2 = begin_arr_2, *ptr_1 = begin_arr_1; ptr_1 < (begin_arr_1 + array_size); ptr_1++, ptr_2++)
	{
		int tempVar = *ptr_1;
		*ptr_1 = *ptr_2;
		*ptr_2 = tempVar;
	}
}

//HW_11

void printstr(const char* arr) {

	for (char* ptr = arr; *ptr != '\0'; ptr++)
	{
		Sleep(30);
		putchar(*ptr);
		putchar('\n');
	}
};

void getstr(char* arr) {
	char temp = ' ';
	int i = 0;
	do
	{
		temp = getchar();
		arr[i] = temp;
		i++;
	} while (temp != '\n');

	arr[i] = '\0';

}

void copystr(char* to, char* from) {

	char* ptr_2 = to;
	for (char* ptr_1 = from; *ptr_1 != '\0'; ptr_1++, ptr_2++)
	{
		*ptr_2 = *ptr_1;
	}
	*ptr_2 = '\0';
}

void change_variables(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void change_pointer_variables(int** a, int** b) {
	int* c = *a;
	*a = *b;
	*b = c;
}