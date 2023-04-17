#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 20
#define ANIMAL_ARR_SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_18.h"

enum arrSize
{
	arr_size = 8
};

typedef int arr8_i[arr_size];			//● масив с 8 int елемента: arr8_i
typedef arr8_i* arr8_i_ptr;				//● указател към arr8_i: arr8_i_ptr
typedef arr8_i arr2d8_i[arr_size];		//● масив с 8 елемента от тип arr8_i: arr2d8_i
typedef arr2d8_i* arr2d8_i_ptr;			//● указател към arr2d8_i: arr2d8_i_ptr

// Дефинирайте функции за принтиране на arr8_i и на arr2d8_i.

void print_array(const arr8_i* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", *(*arr + i));
	}
}

void print_2d_array(const arr2d8_i* arr, int arrSize) {
	for (int row = 0; row < arrSize; row++)
	{
		for (int col = 0; col < arrSize; col++)
		{
			printf("%d ",*(*(*arr + row) + col));// ***arr + (row * arrSize + col)
		}
		putchar('\n');
	}
}

int main(void) {

	arr8_i arr_1 = { 100, 1, 2, 3, 4, 5, 6, 7 };

	arr8_i_ptr arr8_ptr = &(int[arr_size]){ 0, 10, 2, 300, 4, 50, 6, 7 };//&arr8_i

	arr2d8_i arr8_matrix = {
							{100, 1, 2, 3, 4, 5, 6, 7},
							{8, 9, 10, 11, 12, 13, 14, 15},
							{16, 17, 18, 19, 20, 21, 22, 23},
							{24, 25, 26, 27, 28, 29, 30, 31},
							{32, 33, 34, 35, 36, 37, 38, 39},
							{40, 41, 42, 43, 44, 45, 46, 47},
							{48, 49, 50, 510, 5200, 53, 54, 55},
							{56, 57, 58, 59, 60, 61, 62, 63}
	};

	arr2d8_i_ptr arr2d_ptr = &(int[][arr_size]){

							{0, 1, 2, 3, 4, 5, 6, 7},
							{8, 9, 10, 11, 12, 13, 14, 15},
							{16, 17, 18, 19, 20, 21, 22, 23},
							{24, 25, 26, 27, 28, 29, 30, 31},
							{32, 33, 34, 35, 36, 37, 38, 39},
							{40, 41, 42, 43, 44, 45, 46, 47},
							{48, 49, 50, 51, 52, 53, 54, 55},
							{56, 57, 58, 59, 60, 61, 62, 63}
	};


	print_array(&arr_1, arr_size);

	puts("\n------------------------------------------");

	print_2d_array(&arr8_matrix, arr_size);

	return 0;
}