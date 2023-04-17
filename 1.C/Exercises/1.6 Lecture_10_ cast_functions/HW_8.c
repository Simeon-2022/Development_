 #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mymath.h"


int main(void) {
	srand(time(NULL));
	int randomNumber = 0;
	int i_MaxNumber = 0;
	int i_MinNumber = 0;

	//printf("%d", RAND_MAX);

	printf("Enter max random value limit: ");
	scanf("%d", &i_MaxNumber);
	printf("\nResult with a max value limit of %d is --> %d\n",i_MaxNumber, randPositive(i_MaxNumber + 1));

	printf("\nEnter min random value limit: ");
	scanf("%d", &i_MinNumber);
	printf("\nEnter max random value limit: ");
	scanf("%d", &i_MaxNumber);

	printf("\nResult with a value range of [%d,%d] is --> %d\n",i_MinNumber, i_MaxNumber, randRange(i_MinNumber, i_MaxNumber));

	return 0;
}
