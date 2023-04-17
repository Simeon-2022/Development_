#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_22.h"
/*
Задача 3
Използвайте стандартната функция bsearch от stdlib.h за да откриете някоя от стринговите литерали от сортирания лексикографски
масив от указатели към литерали
*/

int main(void) {

	char* arr_literals[] = { "bbbbb","AAAAA","zzzzzz","ccccccc","CCCCC","wwwww","aaaaaaa" };

	int arr_size_ltr = sizeof(arr_literals) / sizeof(char*);

	qsort(arr_literals, arr_size_ltr, sizeof(char*), compare_ltr_);

	for (int i = 0; i < arr_size_ltr; i++)
	{
		printf("%s ", arr_literals[i]);
	}

	const char* str[] = { "zzzzzz" };

	const char** ptr = (const char**)bsearch(str, arr_literals, arr_size_ltr, sizeof(char*), compare_ltr_);

	if (ptr)
	{
		printf("\n\"%s\" is found!", *ptr);
	}
	else
	{
		printf("\nNot found!");
	}


	return 0;
}