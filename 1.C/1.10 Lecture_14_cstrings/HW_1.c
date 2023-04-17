#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int main(void)
{
	//srand((unsigned int)time(NULL));
	//case #1
	//const char* str[] = { "This is a pointer array to const string literal." };
	
	
//	printf("%s\n", str[0]);

//	print_reversed_const_string(str);

//	putchar('\n');

	//case #2
	char arr[ARR_SIZE] = { '\0' };

	get_string(arr);

	print_reversed_char_array(arr);

	return 0;
}