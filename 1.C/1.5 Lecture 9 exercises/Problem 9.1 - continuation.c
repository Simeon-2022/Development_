#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int iSum = 0;
	int iStart_Index = 0;
	int iNumbers_Count = 0;
	int iCount = 1;
	printf("NB: Natural numbers exclude negatives, floating point and fractions!\n");
	printf("\nEnter the starting point: " );
	scanf("%d", &iStart_Index);
	printf("\nEnter how many (natural) numbers you wish to sum up: ");
	scanf("%d", &iNumbers_Count);

	for (int i = iStart_Index; iCount <= iNumbers_Count; i++, iCount++)
	{
		iSum += i;
	};
	printf("\nTotal sum id: %d\n", iSum);
	return 0;
	
}
