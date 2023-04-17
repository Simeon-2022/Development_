#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i_Days_Rental = 0;
	const int i_Price_Standard_Room = 120;
	const int i_Price_Luxury_Room = 180;
	const double i_Tax = 6;
	int i_Type_Room = 0;
	double d_Total = 0;

	printf("Choose a room:\n\n> Standard = 120/day [1]\n> Luxury   = 180/day [2]\n\nYour choice is: ");
	scanf("%d", &i_Type_Room);
	printf("\nNumber of days you'd like to rent the room(s) for: ");
	scanf("%d", &i_Days_Rental);
	while (i_Days_Rental > 14)
	{
		printf("\nThe offer is valid for 14 days only! Please choose between 1 and 14 days -> ");
		scanf("%d", &i_Days_Rental);
	}
	switch (i_Type_Room)
	{
	case 1:

		d_Total = i_Price_Standard_Room * i_Days_Rental;
		break;

	case 2:

		d_Total = i_Price_Luxury_Room * i_Days_Rental;
		break;

	default:
		break;
	}

	printf("\nTotal sum w/o tax: %.2lf", d_Total);
	printf("\nTax percentage is: %.0lf%%", i_Tax);
	printf("\n                  ---------");
	printf("\nTotal sum w/ tax:  %.2lf\n", d_Total * (1 + i_Tax / 100));
	return 0;
}
