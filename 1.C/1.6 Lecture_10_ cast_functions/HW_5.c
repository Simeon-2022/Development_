//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//#include <math.h>

#include "mymath.h"





int main(void) {
	
	printf("%d", fceil(4.000001));
	printf("\n");
	printf("%d", ffloor(4.955001));
	printf("\n");
	printf("%d", fround(4.4500));
	printf("\n");
	printf("%.2f", fpow(2.2, 4));

	return 0;

}

