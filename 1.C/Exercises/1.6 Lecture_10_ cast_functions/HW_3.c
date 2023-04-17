#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include "mymath.h"

//float area_Triangle(float side_A, float side_B);
//double area_Rectangle(float side_A, float side_B);

int main(void)
{
	printf("\nSurface area of rectangle is: %.3f sq.cm\n", area_Rectangle(2.2f, 3.6f));

	return 0;
}

//float area_Triangle(float side_A, float side_B) {
//	return (side_A * side_B);
//}
//double area_Rectangle(area_Triangle(float side_A, float side_B)) {
//	return (double)(area_Triangle(side_A, side_B) * 2);
//}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
