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
		.x = -6.1f,
		.y = 7.0f
	};

	struct Rect_2df rect =
	{
		.vertices[A] = {5.0f,5.0f},
		.vertices[B] = {10.0f,5.0f},
		.vertices[C] = {10.0f,10.0f},
		.vertices[D] = {5.0f,10.0f}
	};

	determine_coverage_rect(&rect, &rand_point);
	
	return 0;
}