#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 300
//#define ROW_SIZE 100
//#define COL_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_16.h"


int main(void)
{
	size_t idx_from = 0;
	size_t idx_to = 0;

	char arr_1[ARR_SIZE] = "This is a test string!";
	char arr_2[ARR_SIZE] = { '\0' };

	printf("Enter copy range [from - to] separated by space and press 'Enter': ");
	scanf("%zd %zd", &idx_from, &idx_to);

	printf("\n'%s' starting at %p",arr_2, extract_substr(arr_1, idx_from, idx_to, arr_2));
	
	return 0;
}