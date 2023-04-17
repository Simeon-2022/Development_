//#pragma once
#ifndef FUNCTIONS_17_H
#define FUNCTIONS_17_H

struct Point_2df
{
	float x;
	float y;
};
struct Triang_2df
{
	struct Point_2df vertices[3];

};
struct Circle_2df
{
	struct Point_2df center;
	float r;
	float area;
	float circumference;

};
struct Rect_2df
{
	struct Point_2df vertices[4];

};
struct Polygon_2df
{
	struct Point_2df vertices[8];
	int countOfVertices;
};

enum Vertices
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	J
};

float	my_abs_float				(float number);
float	determine_distance_point	(const struct Point_2df* point_1, const struct Point_2df* point_2);
void	determine_coverage_point	(const struct Circle_2df* circle, const struct Point_2df* point);
void	determine_coverage_rect		(const struct Rect_2df* rect, const struct Point_2df* point);
void	determine_coverage_circle	(const struct Circle_2df* circle_1, const struct Circle_2df* circle_2);
void	input_struct_Point_2df		(struct Point_2df* coordinates);
void	print_struct_Point_2df		(const struct Point_2df* coordinates);
void	input_struct_Triang_2df		(struct Triang_2df* coordinates);
void	print_struct_Triang_2df		(const struct Triang_2df* coordinates);
void	input_struct_Circle_2df		(struct Circle_2df* coordinates);
void	print_struct_Circle_2df		(const struct Circle_2df* coordinates);
void	input_struct_Rect_2df		(struct Rect_2df* coordinates);
void	print_struct_Rect_2df		(const struct Rect_2df* coordinates);
void	input_struct_Polygon_2df	(struct Polygon_2df* coordinates);
void	print_struct_Polygon_2df	(const struct Polygon_2df* coordinates);



#endif // !FUNCTIONS_17_H
