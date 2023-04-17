#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int n;
	printf("Enter array size >> ");
	scanf("%d", &n);

	int* intPtrArr = (int*)calloc(n, sizeof(int));
	if (intPtrArr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		int number;
		printf("Enter array element [%d] >> ", i + 1);
		scanf("%d", &number);

		intPtrArr[i] = number;
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += intPtrArr[i];
	}

	printf("Sum of array is: %d", sum);

	return 0;
}