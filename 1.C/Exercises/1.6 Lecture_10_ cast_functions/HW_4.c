//#define _CRT_SECURE_NO_WARNINGS
#include "mymath.h"
#include <stdio.h>
#include <math.h>


int main(void)
{
	printf("\nArea of circle is: %.3lf sq.cm\n", area_Circle(5.5));
	area_Circle_Area_qna();
	printf("\nSurface area of rectangle is: %.3lf sq.cm\n", area_Rectangle(2.2, 3.6));

	return 0;
}

