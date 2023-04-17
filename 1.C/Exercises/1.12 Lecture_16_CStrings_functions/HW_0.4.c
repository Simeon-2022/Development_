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


void shorten_str(char * str, int length) {

	//char* ptr = str;
	*(str + length) = '\0';
}

int main(void)
{
	int index = 0;
	char arr_1[ARR_SIZE] = { '\0' };

	printf("Enter array of symbols and press 'Enter':\n=====================================================\n");
	get_string(arr_1);

	printf("\nEnter the index to truncate: ");

	scanf("%d",&index);
	shorten_str(arr_1, index);

	printf("=====================================================\n");
	
	for (int i = 0; arr_1[i] != '\0'; i++)
	{
		putchar(arr_1[i]);
	}
	return 0;
}