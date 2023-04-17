#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_17.h"

int main(void)
{
	struct Point_2df rand_point =
	{
		.x = 6.1f,
		.y = 6.0f
	};

	struct Circle_2df circle =
	{
		.center = {5.1f,5.1f},
		.r = 3.0f
	};

	determine_coverage_point(&circle, &rand_point);
	return 0;
}