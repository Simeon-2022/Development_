#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_17.h"

int main(void)
{
	struct Circle_2df circle_1 =
	{
		.center = {10.0f,9.0f}, 
		.r = 3.0f
	};

	struct Circle_2df circle_2 =
	{
		.center = {5.0f,9.0f},
		.r = 2.0f
	};

	determine_coverage_circle(&circle_1, &circle_2);

	return 0;
}