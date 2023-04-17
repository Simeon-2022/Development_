#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_CHARBIT (CHAR_BIT * sizeof(unsigned char))
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bits.h"

/*
������ 10. ����������� �������:
u8 u8_scan_bits(FILE* f);
, ����� ������ ����� �� ������� ������� �� ���������� ���� ������� � ��������� � ������ �����.
*/


int main(void) {

	FILE* f = NULL;

	f = fopen("Num_to_bits.txt", "r");

	u8 num = u8_scan_bits(f);

	while (true)
	{
		for (int i = LENGTH_CHARBIT - 1; i >= 0; i--)
		{
			printf("%d", ((num >> i) & 1));
		}
		num = u8_scan_bits(f);
		putchar('\n');
	}

	fclose(f);

	return 0;
}