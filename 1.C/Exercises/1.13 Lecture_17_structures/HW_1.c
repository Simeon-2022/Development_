#define _CRT_SECURE_NO_WARNINGS
#define _VERTICES_TRIANGULAR 3
#define _VERTICES_RECTANGULAR 4
#define _VERTICES_POLYGON 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_17.h"


struct Point_2df
{
	float x;
	float y;
};
struct Triang_2df
{
	struct Point_2df vertices[_VERTICES_RECTANGULAR];
	float height;
	float width;
};
struct Circle_2df
{
	struct Point_2df center;
	float r;
};
struct Rect_2df
{
	struct Point_2df vertices[_VERTICES_RECTANGULAR];
};
struct Polygon_2df
{
	struct Point_2df vertices[_VERTICES_POLYGON];
	int countOfVertices;
};
int main(void)
{


	return 0;
}