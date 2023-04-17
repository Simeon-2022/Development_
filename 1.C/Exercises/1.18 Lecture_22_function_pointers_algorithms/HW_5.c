#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_22.h"

/*Задача 5
Напишете функция за претърсване на сортиран масив от указатели към стринг литерали. Функцията
трябва да работи с предикат, подобно на bsort. Използвайте binary search алгоритъм.
Използвайте функцията за да откриете някоя от стринг литералите от масив от предходната задача.*/
int main(void) {

	char* arr_literals[] = { "bbbbb","AAAAA","zzzzzz","ccccccc","CCCCC","wwwww","aaaaaaa" };
	char* lookup[] = { "cccccccc" };
	int arr_size_ltr = sizeof(arr_literals) / sizeof(char*);

	// lookup string in unsorted array by pointer address value:
	char** result = bin_search_char_unsorted(arr_literals, arr_size_ltr, *lookup);
	
	if (result)
	{
		printf("\"%s\" found!", *result);
	}
	else
	{
		printf("\nString not found!");
	}
	qsort(arr_literals, arr_size_ltr, sizeof(char*), compare_ltr_);

	putchar('\n');
	for (int i = 0; i < arr_size_ltr; i++)
	{
		printf("%s ", arr_literals[i]);
	}

	// lookup string in sorted array perstring size:

	putchar('\n');

	result = bin_search_char_sorted(lookup, arr_literals, arr_size_ltr, compare_ltr_);

	if (result)
	{
		printf("\n\"%s\" found!", *result);
	}
	else
	{
		printf("\nString not found!");
	}
	
	return 0;
}