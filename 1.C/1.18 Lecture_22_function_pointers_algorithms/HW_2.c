#define _CRT_SECURE_NO_WARNINGS
#define ARR_COLS 3
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_22.h"

/*Задача 2
Използвайте стандартната функция qsort от stdlib.h за да сортирате:
● масив от int във възходящ ред
● масив от char във низходящ ред
● масив от масив от константни указатели към стринг литерали лексикографски
● масив от unsigned long във низходящ ред, като четните стойности са преди нечетните, пример:
4, 2, 6, 1, 7, 5, 3, 9, 8, 0 след сортиране: 8, 6, 4, 2, 0, 9, 7, 5, 3, 1
*/


int main() {
	int arr[] = { 9,8,4,33,23,1000,-23,4,666 };
	char arr_char[] = { 'z','a','r','t','q','\0' }; //{ 'a','b','c','d' };
	char* arr_literals[] = { "bbbbb","AAAAA","AAAAA","ccccccc","CCCCC","wwwww","aaaaaaa" };
	char* arr_p_litr[][ARR_COLS] = { {"wwwww","rrrrr","uuu"}, {"cccccc","bbbbbb","aaaaaa"}, {"zzzzzz","mmmmmm","nnnnnn"}, };
	unsigned long arr_long[] = { 4, 2, 6, 1, 7, 5, 3, 9, 8, 0 };

	int arr_size = sizeof(arr) / sizeof(int);
	int arr_size_char = sizeof(arr_char);
	int arr_size_ltr = sizeof(arr_literals) / sizeof(arr_literals[0]);
	int arr_size_p_ltr = sizeof(arr_p_litr) / sizeof(arr_p_litr[0][0]) / ARR_COLS;
	unsigned long arr_size_long = sizeof(arr_long) / sizeof(unsigned int);


	printf("%d\n", compare_ltr_(&arr_literals[0], &arr_literals[1]));


	qsort(arr, arr_size, sizeof(int), compare_int_);

	for (int i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}

	putchar('\n');

	qsort(arr_char, arr_size_char, sizeof(char), compare_char_);

	for (int i = 0; i < arr_size_char; i++)
	{
		printf("%c ", arr_char[i]);
	}

	putchar('\n');

	qsort(arr_literals, arr_size_ltr, sizeof(char*), compare_ltr_);

	for (int i = 0; i < arr_size_ltr; i++)
	{
		printf("%s ", arr_literals[i]);
	}

	putchar('\n');

	for (int i = 0; i < arr_size_p_ltr; i++)
	{
		qsort(arr_p_litr[i], arr_size_p_ltr, sizeof(char*), compare_ltr_);
	}

	for (int i = 0; i < arr_size_p_ltr; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%s ", arr_p_litr[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');

	qsort(arr_long, arr_size_long, sizeof(unsigned int), compare_int_long);

	for (unsigned int i = 0; i < arr_size_long; i++)
	{
		printf("%lu ", arr_long[i]);
	}

	return 0;
}