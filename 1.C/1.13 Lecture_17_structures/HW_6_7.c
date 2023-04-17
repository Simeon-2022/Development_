#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_17.h"


int main(void)
{
	struct Point_2df point;
	input_struct_Point_2df(&point);
	print_struct_Point_2df(&point);

	printf("-------------------------------------------------\n");

	struct Triang_2df triang;
	input_struct_Triang_2df(&triang);
	print_struct_Triang_2df(&triang);

	printf("-------------------------------------------------\n");

	struct Circle_2df circle;
	input_struct_Circle_2df(&circle);
	print_struct_Circle_2df(&circle);

	printf("-------------------------------------------------\n");

	struct Rect_2df rect;
	
	input_struct_Rect_2df(&rect);
	print_struct_Rect_2df(&rect);

	printf("-------------------------------------------------\n");

	struct Polygon_2df pol;
	
	input_struct_Polygon_2df(&pol);
	print_struct_Polygon_2df(&pol);

	return 0;
}