#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_17.h"
/*Задача 5
Дефинирайте функция за пресмятането на разстоянието между две точки в равнината.
*/

int main(void)
{
	struct Point_2df point_1 =
	{
		.x = 15.0f,
		.y = 9.0f
	};

	struct Point_2df point_2 =
	{
		.x = 5.0f,
		.y = 12.50f
	};

	printf("Distance 'p_1' -> 'p_2' = %.2f\n",determine_distance_point(&point_1, &point_2));

	return 0;
}