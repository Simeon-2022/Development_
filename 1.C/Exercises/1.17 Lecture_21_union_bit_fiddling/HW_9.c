#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bits.h"


/*
Задача 9. Дефинирайте функция:
void u8_print_bits(FILE* f, u8 num);
, която принтира битовете на число num на подадения й файлов поток
*/



int main(void) {

	u8 num;
	int test;

	printf("Enter integer >> ");
	scanf("%d", &test);

	if (test > UCHAR_MAX || test < 0)
	{
		fprintf(stderr, "Number is not an unsigned char!");
		return -1;
	}
	num = test;
	FILE* f = NULL;
	f = fopen("Num_to_bits.txt", "a+");
	u8_print_bits(f, num);
	fclose(f);
	return 0;
}