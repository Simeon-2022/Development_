#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bits.h"

/*
Задача 7. Дефинирайте функция:
u8 u8_toggle_bits(u8 num);
, която променя всичките битове от число num на обратните, така че да са равни на обратните им стойности.
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
	u8 temp = num;

	num = u8_toggle_bits(num);

	char char_bit_view[LENGTH_CHARBIT + 1];

	printf("Old value of bit position is: ");
	print_char_to_bits(char_bits_array(char_bit_view, temp)); putchar('\n');

	printf("New value of bit position is: ");
	print_char_to_bits(char_bits_array(char_bit_view, num));

	return 0;

}