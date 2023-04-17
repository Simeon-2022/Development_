#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int iSum = 0;
	int i = 0;

	while (i++,i <= 10)
	{
		iSum += i;
	}
	printf("\nTotal sum is: %d\n", iSum);
	return 0;
}
