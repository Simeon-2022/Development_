#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bits.h"

/*
Задача 8. Дефинирайте функция:
u8 u8_reverse_bits(u8 num);
, която обръща стойностите на битовете на число num в обратен ред
*/
// 0110 1111 => 1111 0110

u8 u8_reverse_bits(u8 num) {
	
	u8 mask = 1;
	u8 temp = num;
	
	for (int i = LENGTH_CHARBIT; i > 0; i--, temp >>= 1)
	{
		num = u8_set_bit(num, i, (temp & 1));
		/*if (temp & 1)
		{
			num |= (mask << (i - 1)); 
		}
		else
		{
			num &= ~(mask << (i - 1));
		}*/
	}
	return num;
}
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

	num = u8_reverse_bits(num);

	char char_bit_view[LENGTH_CHARBIT + 1];

	printf("Old value of bit position is: ");
	print_char_to_bits(char_bits_array(char_bit_view, temp)); putchar('\n');

	printf("New value of bit position is: ", num);
	print_char_to_bits(char_bits_array(char_bit_view, num));

}