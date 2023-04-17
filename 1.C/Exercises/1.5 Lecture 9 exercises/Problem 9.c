#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("NB: Natural numbers exclude negatives, floating point and fractions!\n");
	int sum = 0;
	for (int i = 1; i <= 15; i++)
	{
		if (i < 11)
		{
			sum += i;
		}
	}
	printf("%d",sum);

	return 0;
}
