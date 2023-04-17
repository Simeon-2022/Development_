#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int main() {

	float iInput_Qty,
		iProduct_Price,
		dTotal_Sum = 0;
	int	iInput_Product,
		iInput_Qty_Items,
		iCurrentSpent;




	printf("List of available products:\n\n"
		"- Tomatoes__________4.50 / kg = [1]\n"
		"- Wheat flower______1.80 / kg = [2]\n"
		"- Youghurt__________0.50 / pc = [3]\n"
		"- Ice cream_________0.60 / pc = [4]\n"
		"- Candy_____________1.50 / kg = [5]\n"
		"- Lollipop__________0.15 / pc = [6]\n"
		"- EXIT                        = [0]\n\n"
		"Please make a choice: ");

	scanf(" %d", &iInput_Product);

	while (iInput_Product != 0)
	{

		switch (iInput_Product)
		{
		case 1:
			iProduct_Price = 4.50;
			break;
		case 2:
			iProduct_Price = 1.80;
			break;
		case 3:
			iProduct_Price = 0.50;
			iInput_Qty = (int)iInput_Qty;
			break;
		case 4:
			iProduct_Price = 0.60;
			iInput_Qty = (int)iInput_Qty;
			break;
		case 5:
			iProduct_Price = 1.50;
			break;
		case 6:
			iProduct_Price = 4.50;
			iInput_Qty = (int)iInput_Qty;
			break;
		default:
			while (iInput_Product > 6 || iInput_Product < 0)
			{
				printf("Input invalid! Try again.\n");
				printf("\nPlease make a choice: ");
				scanf(" %d", &iInput_Product);
			}
			continue;
			break;
		}
		
		printf("\nType in needed quantity (kg or pieces): ");
		scanf(" %f", &iInput_Qty);

		dTotal_Sum += (iInput_Qty * iProduct_Price);

		printf("\nCurrent Product cost: %.2f lv.\n", (iInput_Qty * iProduct_Price));

		printf("\nPlease make a choice: ");
		scanf(" %d", &iInput_Product);
	}
	printf("------------------------------------");
	printf("\nYour groceries add up to: %.2f lv\n", dTotal_Sum);
	printf("------------------------------------");
	return 0;
}
