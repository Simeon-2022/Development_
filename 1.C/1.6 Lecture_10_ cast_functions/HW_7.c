#define _CRT_SECURE_NO_WARNINGS
#include "mymath.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>




int main(void) {

	int n = 49;	// 3628800
	int r = 6;	// 720
				//factoriel(n) = (1*2*3*4...*43)...*49 / factoriel(n - r) = (1*2*3*4...*43)

	printf("Odds of winning are 1 : %llu", (factoriel_2(n) / factoriel_2(r)));

	return 0;
}

