#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mymath.h"
const double g_Pi = 3.14;

float area_Circle(float r) {
	return (float)(pow(r, 2) * g_Pi);
}

void area_Circle_Area_qna(void) {
	printf("\nEnter radius: ");
	double r = 0;
	scanf("%lf", &r);

	printf("\nArea of circle is: %.3lf sq.cm\n", (double)area_Circle((float)r));
}

float area_Triangle(float side_A, float side_B) {
	return (side_A * side_B)/2;
}

float area_Rectangle(float side_A, float side_B) {
	return (area_Triangle(side_A, side_B) * 2);
}

int fceil(float a) {

	if ((a - (int)a) > 0)
	{
		return (int)(a + 1);
	}
	return (int)a;
}

int ffloor(float a) {
	return (int)a;
}

int fround(float a) {
	if ((a - (int)a) >= 0.5)
	{
		return fceil(a);
	}
	else
	{
		return ffloor(a);
	}
};

float fpow(float number, int power) {

	if (power != 0)
	{
		return fpow(number, --power) * number;
	}
	else
	{
		return 1;
	}
}

// HW_6:__________________________________________________________
int factoriel(int n) {
	if (n != 0)
	{
		return factoriel(n - 1) * n;
	}
	else
	{
		return 1;
	}
}

// HW_7:__________________________________________________________
unsigned long long factoriel_2(int n) {

	int n_1 = 49;
	int r_1 = 6;
	int lower_Limit = n_1 - r_1;

	if (n > lower_Limit)
	{
		return factoriel_2(n - 1) * n;
	}
	else
	{
		return 1;
	}
}

// HW_8:__________________________________________________________
int randPositive(int max) {

	return rand() % max;
}

int randRange(int min, int max) {

	return min + rand() % (max + 1 - min);
}