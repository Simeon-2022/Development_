/*
Напишете функция:
void copystr(char *to, char *from),
която копира една последователност от символи в друга.
*/
#define _CRT_SECURE_NO_WARNINGS
#define _ARR_SIZE 100
#include <stdio.h>
//#include <stdlib.h>
//include <time.h>
//#include <stdbool.h>
#include <Windows.h>
#include "Functions_12.h"



int main(void) {

	char arr_1[_ARR_SIZE];
	char arr_2[_ARR_SIZE];

	printf("\nType in a sample string of characters: ");
	getstr(arr_1);

	copystr(arr_2, arr_1);

	printf("\nPrinting out copied sample: \n");
	printstr(arr_2);

	return 0;
}

