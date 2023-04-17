/*Задача 11
Напишете функция, която печата низ, като принтирате всеки символ
поотделно, използвайки библиотечната функция putchar(c).
void printstr(char *s);
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

	char arr[_ARR_SIZE];
	printf("\nType in a sample string of characters: ");
	getstr(arr);

	printf("\nPrinting out sample: \n");
	printstr(arr);

	return 0;
}