#define _CRT_SECURE_NO_WARNINGS
#define ARR_COLS 3
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_22.h"

/*Задача 4
Напишете функция за сортиране на масив от указатели към стринг литерали, която работи с
предикатна функция, подобно на qsort (приемa като параметър указател към функция-предикат)
Напишете функции, които сортират масив:
● лексикографски, в обратен ред
● по брой символи в стринга
● по брой пунктуационни знаци в стринга
*/
int main(void) {

	char* arr_literals_v1[] = { "b","AA","zzz","cccccccc","CCCCC","wwwww","rrrrrrrrrr","aaaaaaaa" };
	char* arr_literals_v2[] = { "b,.,.","A!!!A","z.z!z","ccc?????cccc","CCCC.........C","wwwww.","rrrrrrrr","aaaaaaa" };

	int arr_size_ltr_v1 = sizeof(arr_literals_v1) / sizeof(char*);
	int arr_size_ltr_v2 = sizeof(arr_literals_v2) / sizeof(char*);

	//char* ptr = NULL;
	//for (int i = 0; i < arr_size_ltr; i++)
	//{
	//	for (int j = 0; j < arr_size_ltr - 1; j ++)
	//	{
	//		if (my_strcmp_rvsl(arr_literals[j], arr_literals[j + 1]) > 0)
	//		{
	//			ptr = arr_literals[j];
	//			arr_literals[j] = arr_literals[j + 1];
	//			arr_literals[j + 1] = ptr;
	//		}
	//	}
	//}

	my_qsort(arr_literals_v1, arr_size_ltr_v1, sizeof(char*), compare_ltr_rvsl);

	for (int i = 0; i < arr_size_ltr_v1; i++)
	{
		printf("%s ", arr_literals_v1[i]);
	}
	putchar('\n');

	my_qsort(arr_literals_v1, arr_size_ltr_v1, sizeof(char*), compare_char_count_);

	for (int i = 0; i < arr_size_ltr_v1; i++)
	{
		printf("%s ", arr_literals_v1[i]);
	}

	putchar('\n');

	my_qsort(arr_literals_v2, arr_size_ltr_v2, sizeof(char*), compare_char_punct_);

	for (int i = 0; i < arr_size_ltr_v2; i++)
	{
		printf("%s ", arr_literals_v2[i]);
	}

	return 0;

}