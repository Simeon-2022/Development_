#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Functions_17.h"

float determine_distance_point(const struct Point_2df* point_1, const struct Point_2df* point_2) {

	float distance_x = my_abs_float(point_1->x - point_2->x);
	float distance_y = my_abs_float(point_1->y - point_2->y);

	return (float)sqrt(pow(distance_x, 2) + pow(distance_y, 2));
}
//-----------------------------------------------------------------------------------
void determine_coverage_circle(const struct Circle_2df* circle_1, const struct Circle_2df* circle_2) {

	float a_triangle_side = my_abs_float(circle_1->center.x - circle_2->center.x);
	float b_triangle_side = my_abs_float(circle_1->center.y - circle_2->center.y);
	float hypotenuse = (float)sqrt(pow(a_triangle_side, 2) + pow(b_triangle_side, 2));

	float radii = circle_1->r + circle_2->r;

	if (hypotenuse == radii)
	{
		printf("Cicles are at collision point");
	}
	else
	{
		printf("Cicles are not at collision point");
	}

	putchar('\n');
}
//-----------------------------------------------------------------------------------
void determine_coverage_point(const struct Circle_2df* circle, const struct Point_2df* point) {

	float a_triangle_side = my_abs_float(circle->center.x - point->x);
	float b_triangle_side = my_abs_float(circle->center.y - point->y);
	float hypotenuse = (float)sqrt(pow(a_triangle_side, 2) + pow(b_triangle_side, 2));

	if (hypotenuse <= circle->r)
	{
		printf("Point within circle");
	}
	else
	{
		printf("Point outside circle");
	}

	putchar('\n');
}
//-----------------------------------------------------------------------------------
float my_abs_float(float number) {
	if (number < 0)
	{
		return -number;
	}
	return number;
}
//-----------------------------------------------------------------------------------
void determine_coverage_rect(const struct Rect_2df* rect, const struct Point_2df* point) {

	bool check_side_x_axis = (point->x >= rect->vertices[A].x) && (point->x <= rect->vertices[B].x);

	bool check_side_y_axis = (point->y >= rect->vertices[A].y) && (point->y <= rect->vertices[D].y);

	if (check_side_x_axis && check_side_y_axis)
	{
		printf("Dot falls within rect boundaries");
	}
	else
	{
		printf("Dot falls ouside rect boundaries");
	}
	putchar('\n');
}
//-----------------------------------------------------------------------------------
void input_struct_Point_2df(struct Point_2df* coordinates) {

	printf("Enter point coordinates [x;y] split by space: ");
	scanf("%f %f", &coordinates->x, &coordinates->y);
}

void print_struct_Point_2df(const struct Point_2df* coordinates) {

	puts("\nPoint coordinates:");
	printf(" x-axis: %f\n y-axis: %f\n", coordinates->x, coordinates->y);
}
//-----------------------------------------------------------------------------------
void input_struct_Triang_2df(struct Triang_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C' };

	puts("Enter triangular coordinates split by space:");
	for (int i = 0; i < 3; i++)
	{
		printf("Vertice %c [x;y]: ", vertices_to_char[i]);
		scanf("%f %f", &coordinates->vertices[i].x, &coordinates->vertices[i].y);
	}
}

void print_struct_Triang_2df(const struct Triang_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C' };

	for (int i = 0; i < 3; i++)
	{
		printf("\nVertice %c coordinates:", vertices_to_char[i]);
		printf("\n x-axis: %f\n y-axis: %f\n", coordinates->vertices[i].x, coordinates->vertices[i].y);
	}
}

//----------------------------------------------------------------------------------

void input_struct_Circle_2df(struct Circle_2df* coordinates) {

	printf("Enter circle coordinates [x;y] split by space: ");
	scanf("%f %f", &coordinates->center.x, &coordinates->center.y);

	printf("Enter length radius: ");
	scanf("%f", &coordinates->r);
}

void print_struct_Circle_2df(const struct Circle_2df* coordinates) {

	puts("\nCenter coordinates:");
	printf(" x-axis: %f\n y-axis: %f\n", coordinates->center.x, coordinates->center.y);
	puts("\nRadius length: ");
	printf(" r: %f", coordinates->r);
	putchar('\n');
}

//---------------------------------------------------------------------------------

void input_struct_Rect_2df(struct Rect_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C','D' };

	printf("Enter rectangular coordinates split by space:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Vertice %c [x;y]: ", vertices_to_char[i]);
		scanf("%f %f", &coordinates->vertices[i].x, &coordinates->vertices[i].y);
	}
}

void print_struct_Rect_2df(const struct Rect_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C','D' };
	for (int i = 0; i < 4; i++)
	{
		printf("\nVertice %c coordinates:", vertices_to_char[i]);
		printf(" x-axis: %f\n y-axis: %f\n", coordinates->vertices[i].x, coordinates->vertices[i].y);
	}
}

//---------------------------------------------------------------------------------


void input_struct_Polygon_2df(struct Polygon_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C','D','E','F','G','J' };

	printf("Enter number of verices the polygone has? >> ");
	scanf(" %d", &coordinates->countOfVertices);
	putchar('\n');

	for (int i = 0; i < coordinates->countOfVertices; i++)
	{
		printf("Vertice %c [x;y]: ", vertices_to_char[i]);
		scanf("%f %f", &coordinates->vertices[i].x, &coordinates->vertices[i].y);
	}
}

void print_struct_Polygon_2df(const struct Polygon_2df* coordinates) {

	char vertices_to_char[] = { 'A','B','C','D','E','F','G','J' };

	for (int i = 0; i < coordinates->countOfVertices; i++)
	{
		printf("\nVertice %c coordinates:", vertices_to_char[i]);
		printf("\n x-axis: %f\n y-axis: %f\n", coordinates->vertices[i].x, coordinates->vertices[i].y);
	}

}