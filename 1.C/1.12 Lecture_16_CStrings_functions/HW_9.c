#define _CRT_SECURE_NO_WARNINGS
#define ARR_PTR_SIZE 4
#define ROW_SIZE 4
#define COL_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_16.h"

int main(void)
{

	int arr_ptr_size = ARR_PTR_SIZE;

	const char* arr_1[ARR_PTR_SIZE] = {	"Acdc aaaaa",
										"acdb bbbb",
										"Bcbb bbbbb",
										"Dddd ddddd"
									  };

	// Warning	C4090	'function': different 'const' qualifiers

	/*const char matrix[ROW_SIZE][COL_SIZE] = { {"aaaa aaaaa"},
											  {"abbb bbbbb"},
											  {"Bbcb bbbbb"},
											  {"Dddd ddddd"}
											 };*/

	if (is_lexicographical(arr_1, ARR_PTR_SIZE))
	{
		printf("\nStrings are in a lexicographical order\n");
	}
	else
	{
		printf("\nStrings are not in a lexicographical order\n");
	}


	return 0;
}