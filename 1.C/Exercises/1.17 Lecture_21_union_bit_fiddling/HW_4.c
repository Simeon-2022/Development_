/*������ 4. ����������� �������:
u8 u8_set_bit_off(u8 num, u8bitpos pos);
, ����� ������� ���������� �� ��� �� ����� num �� ������ ������� pos �� 0*/

#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "Bits.h"


int main(void) {

	int test;
	u8 num;
	u8bitpos pos;

	printf("Enter integer >> ");
	scanf("%d", &test);

	if (test > UCHAR_MAX || test < 0)
	{
		fprintf(stderr, "Number is not an unsigned char!");
		return -1;
	}
	num = test;

	printf("Enter bit position to set to 'on' >> ");
	scanf("%hhu", &pos);


	if (pos < 1 || pos > CHAR_BIT * sizeof(unsigned char))
	{
		fprintf(stderr, "Error: Position out of scope %d\n", pos);
		return -1;
	}

	u8 temp = num;

	num = u8_set_bit_off(num, pos);

	char char_bit_view[LENGTH_CHARBIT + 1];

	printf("Old value of bit position is: ");
	print_char_to_bits(char_bits_array(char_bit_view, temp)); putchar('\n');

	printf("New value of bit position is: ");
	print_char_to_bits(char_bits_array(char_bit_view, num));

	return 0;
}