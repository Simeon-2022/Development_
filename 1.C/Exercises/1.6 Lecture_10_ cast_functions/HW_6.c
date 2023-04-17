#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

#include "mymath.h"

int main(void) {

	int a = 7;

	for (int i = a - 1; i > 0; i--)
	{
		a *= i;
	}

	printf("%d", a);
	printf("\n");
	a = 7;

	printf("%d", factoriel(a));
	
	return 0;
}
