#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int endOfCycle(char cIndex, int arr_Caravan[], int arr_Camper[], int iPrice_Per_Caravan_Per_Day, int iPrice_Per_Camper_Per_Day, int iSum_Caravan, int iSum_Camper) {
	if (cIndex == 'y')
	{
		cIndex = 'y';

		printf("\nPurchases:\n");
		for (int i = 0; i < 3; i++)
		{
			if (arr_Caravan[i] > 0 && arr_Caravan[i] <= 3)
			{
				printf("  -Caravan No. %d rented for %d days = %d lv\n", (i + 1), arr_Caravan[i], (arr_Caravan[i] * iPrice_Per_Caravan_Per_Day));
			}
		}

		printf("\n");

		for (int y = 0; y < 3; y++)
		{
			if (arr_Camper[y] > 0 && arr_Camper[y] <= 3)
			{
				printf("  -Camper No. %d  rented for %d days = %d lv\n", (y + 1), arr_Camper[y], (arr_Camper[y] * iPrice_Per_Camper_Per_Day));
			}
		}

		printf("                                   ---------");
		printf("\nTotal bill including all purchases = %d lv.\n\n", iSum_Caravan + iSum_Camper);

		printf("Your order is being processed. Thank you!\n\n");

	}
	else
	{
		printf("\n");
	}


};

int main()
{

	int iCaravan_Count = 3,
		iCamper_Count = 3,
		iPrice_Per_Caravan_Per_Day = 90,
		iPrice_Per_Camper_Per_Day = 100,
		iVehicle_Of_Choice,
		iDays_Rent,
		iArr_Index_Caravan = 0,
		iArr_Index_Camper = 0,
		iDays_Rent_Caravan = 0,
		iDays_Rent_Camper = 0,
		iSum_Caravan = 0,
		iSum_Camper = 0;

	char cIndex = ' ';
	int arr_Caravan[3];
	int arr_Camper[3];
	do
	{
		if (iCaravan_Count >= 0 && iCamper_Count >= 0)
		{
			if (iCaravan_Count == 0 && iCamper_Count == 0)
			{
				printf("\nNo more vehilces left for rent! Proceed to check out? [Yes = 'y'] [Abort = 'a'] : ");
				scanf(" %c", &cIndex);
				if (cIndex == 'a')
				{
					printf("\nCanceling all orders..\n");
					return 0;
				}
				else
				{
					endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
					return 0;
				}

			}
			else
			{
				printf("\nAvailable count of vehicles: \n\n-Caravan x %d\n-Camper  x %d\n", iCaravan_Count, iCamper_Count);

			}
		}

		if (iCaravan_Count == 0)
		{
			do
			{
				printf("\nVehilcles available for rent [Camper = 2] : "); //1
				scanf(" %d", &iVehicle_Of_Choice);
				if (iVehicle_Of_Choice == 1)
				{
					//points to caravan;
					printf("\nNo more Caravans left for rent! Proceed to check out? [Yes = 'y'] [No = 'n'] [Abort = 'a'] : ");
					scanf(" %c", &cIndex);

					if (cIndex == 'a')
					{
						printf("\Canceling all orders..\n");
						return 0;
					}
					else if (cIndex == 'y')
					{
						endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
						return 0;
					}
				}
				else
				{
					break; // added last
				}

			} while (cIndex == 'n' );
		}
		else if (iCamper_Count == 0)
		{
			do
			{
				printf("\nVehilcles available for rent [Caravan = 1] : ");
				scanf(" %d", &iVehicle_Of_Choice);

				if (iVehicle_Of_Choice == 2)
				{
					//points to camper;
					printf("\nNo more Campers left for rent! Proceed to check out? [Yes = 'y'] [No = 'n'] [Abort = 'a'] : ");
					scanf(" %c", &cIndex);

					if (cIndex == 'a')
					{
						printf("\nCanceling all orders..\n");
						return 0;
					}
					else if(cIndex == 'y')
					{
						endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
						return 0;
					}
				}
				else
				{
					break;
				}

			} while (cIndex == 'n' );
		}
		else
		{

			printf("\nWhat would you like to rent, a [Caravan = 1] or a [Camper = 2] ? : ");
			scanf(" %d", &iVehicle_Of_Choice);

		}


		while (iVehicle_Of_Choice != 1 && iVehicle_Of_Choice != 2)
		{
			printf("\nInvalid input. Enter a valid choice! --> ");
			scanf(" %d", &iVehicle_Of_Choice);
		}

		if (iVehicle_Of_Choice == 1)
		{
			//caravan:
			if (iCaravan_Count == 0)
			{
				printf("\nNo more Caravans left for rent! Proceed to check out? [Yes = 'y'] [No = 'n'] [Abort = 'a'] : ");
				scanf(" %c", &cIndex);

				if (cIndex == 'a')
				{
					printf("\nCanceling all orders..\n");
					return 0;
				}
				else if (cIndex == 'y')
				{
					endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
					return 0;
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			//camper:
			if (iCamper_Count == 0)
			{
				printf("\nNo more Campers left for rent! Proceed to check out? [Yes = 'y'] [No = 'n'] [Abort = 'a'] : ");
				scanf(" %c", &cIndex);

				if (cIndex == 'a')
				{
					printf("\nCanceling all orders..\n");
					return 0;
				}
				else if (cIndex == 'y')
				{
					endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
					return 0;
				}
				else
				{
					continue;
				}
			}
		}

		printf("\n");

		if (iVehicle_Of_Choice == 1)
			printf("- Chosen vehicle :: [Caravan]\n");
		else
			printf("- Chosen vehicle :: [Camper]\n");


		printf("\nHow many days would you like to rent the vehicle for? : ");
		scanf(" %d", &iDays_Rent);

		switch (iVehicle_Of_Choice)
		{
		case 1:
			iCaravan_Count--;
			iSum_Caravan += (iDays_Rent * iPrice_Per_Caravan_Per_Day);
			arr_Caravan[iArr_Index_Caravan++] = iDays_Rent;
			break;
		case 2:
			iCamper_Count--;
			iSum_Camper += (iDays_Rent * iPrice_Per_Camper_Per_Day);
			arr_Camper[iArr_Index_Camper++] = iDays_Rent;
			break;
		default:
			break;
		}

		printf("\nProceed to check out? [Yes = 'y'] [No = 'n'] [Abort = 'a'] : ");
		scanf(" %c", &cIndex);

		//end_of_cycle:
		if (cIndex == 'a')
		{
			printf("\nCanceling all orders..\n");
			return 0;
		}
		else if (cIndex == 'y')
		{
			endOfCycle(cIndex, arr_Caravan, arr_Camper, iPrice_Per_Caravan_Per_Day, iPrice_Per_Camper_Per_Day, iSum_Caravan, iSum_Camper);
			return 0;
		}



	} while (cIndex == 'n');
	return 0;
}

