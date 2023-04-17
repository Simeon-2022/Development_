#pragma once
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include<stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Bits.h"

int get_bit_value_(int num, int pos) {

	if (pos < 1 || pos > CHAR_BIT * sizeof(int))
	{
		fprintf(stderr, "Error: Position out of scope %d\n", pos);
		return -1;
	}

	num >>= (pos - 1);

	return 1 & num;
}

u8bit u8_get_bit(u8 num, u8bitpos pos) {

	num >>= (pos - 1);

	return 1 & num;
}

u8 u8_set_bit_on(u8 num, u8bitpos pos) {

	u8 mask = 1;
	mask <<= (pos - 1);
	num |= mask;
	return num;
}

u8 u8_set_bit_off(u8 num, u8bitpos pos) {

	u8 mask = 1;
	mask <<= (pos - 1);
	num &= ~mask;
	return num;
}

u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val) {

	u8 mask = 1;
	mask <<= (pos - 1);

	if (val == 0)
	{
		return num &= ~mask;
	}
	return num |= mask;
}

u8 u8_toggle_bit(u8 num, u8bitpos pos) { // need to check the value of the bit

	u8 mask = 1;
	mask <<= (pos - 1); // pos = 2 => 0000 0010

	if ((num & mask) == mask) // if true => bit is 'on' 
	{
		return u8_set_bit_off(num, pos); // turning bit 'off' e.g ~mask = 1111 1101 => num &= ~mask;
	}
	// if false => bit is 'off':
	return u8_set_bit_on(num, pos);//turning bit 'on' e.g mask = 0000 0010 => num |= mask; 
}

u8 u8_toggle_bits(u8 num) { // need to check the value of the bit

	return ~num;
}

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

u8 u8_scan_bits(FILE* f) {

	// 1111 0000 <<

	u8 num = 0;
	char arr[LENGTH_CHARBIT] = { '\0' };

	for (int i = 0; i < LENGTH_CHARBIT; i++) //&& 
	{
		int ch = fgetc(f);
		if (ch == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		if (ch == '1' || ch == '0')
		{
			num <<= 1;
			if (ch == '1')
			{
				num |= 1;
			}
			arr[i] = ch;
		}
		else if (ch == 10)
		{
			i--;
		}
	}

	return num;
}

void u8_print_bits(FILE* f, u8 num) {

	char str[LENGTH_CHARBIT + 1];

	for (int i = LENGTH_CHARBIT - 1; i >= 0; i--, num >>= 1)
	{
		str[i] = ((num & 1) + '0');
	}

	str[LENGTH_CHARBIT] = '\0';

	fputs(str, f);
	fputs("\n", f);
	//fprintf(f, "0b%s", str);
	//fprintf(f, "\n");
}

char* char_bits_array(char* str, u8 num) {

	for (int i = LENGTH_CHARBIT - 1; i >= 0; i--, num >>= 1)
	{
		str[i] = ((num & 1) + '0');
	}

	str[LENGTH_CHARBIT] = '\0';

	return str;
}

void print_char_to_bits(char* str) {

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i % 4 == 0)
		{
			putchar(' ');
		}

		putchar(str[i]);
	}

}