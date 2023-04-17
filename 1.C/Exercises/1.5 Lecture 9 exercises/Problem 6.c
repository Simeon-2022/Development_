#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int month = 0;
	int days = 0;
	printf("Enter a number of a month [1 to 12]: ");
	scanf("%d", &month);

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 2:
		days = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	default:
		break;
	}

	printf("\nSelected month has %d days.\n", days);

	return 0;
}
