
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "Bits.h"
//char* itobs(int, char*);
//void show_bstr(const char*);


/*Задача 2. Дефинирайте функция:
u8bit u8_get_bit(u8 num, u8bitpos pos);
, която връща стойността на бит от число num на дадена позиция pos*/
int main(void)
{
	//char bin_str[CHAR_BIT * sizeof(int) + 1];
	//int number;
	//puts("Enter integers and see them in binary.");
	//puts("Non-numeric input terminates program.");
	//while (scanf("%d", &number) == 1)
	//{
	//	itobs(number, bin_str);
	//	printf("%d is ", number);
	//	show_bstr(bin_str);
	//	putchar('\n');
	//}
	//puts("Bye!");

	u8 num;
	u8bitpos pos;

	printf("Enter integer >> ");
	scanf("%hhu", &num);
	printf("Enter bit position >> ");
	scanf("%hhu", &pos);

	if (pos < 1 || pos > CHAR_BIT * sizeof(char))
	{
		fprintf(stderr, "Error: Position out of range!\n");
		return -1;
	}
	
	u8bit result = u8_get_bit(num, pos);

	printf("Value of bit position %hhu is %d", pos, result);
	return 0;
}
//char* itobs(int n, char* ps)
//{
//	int i;
//	const static int size = CHAR_BIT * sizeof(int);
//	for (i = size - 1; i >= 0; i--, n >>= 1)
//		ps[i] = (01 & n) + '0'; // assume ASCII or similar
//	ps[size] = '\0';
//	return ps;
//}
///* show binary string in blocks of 4 */
//void show_bstr(const char* str)
//{
//	int i = 0;
//	while (str[i]) /* not the null character */
//	{
//		putchar(str[i]);
//		if (++i % 4 == 0 && str[i])
//			putchar(' ');
//	}
//}