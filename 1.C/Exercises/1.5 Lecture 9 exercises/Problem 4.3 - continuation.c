#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	
	int i_Gender_Indicator = 0;
	int i_Age = 0;
	const int i_Female_Range[4] = { 25,30,35,40 };
	const int i_Male_Range[4] = { 30,35,40,45 };
	
		printf("Please enter your gender:\n\n> female = [1]\n> male   = [2]\n\nYour choice: ");
		scanf(" %d", &i_Gender_Indicator);
		printf("\nPlease enter your age: ");
		scanf(" %d", &i_Age);

		switch (i_Gender_Indicator)
		{
		case 1:
			if (((i_Age >= i_Female_Range[0]) && (i_Age <= i_Female_Range[1])) || ((i_Age >= i_Female_Range[2]) && (i_Age <= i_Female_Range[3])))
			{
				printf("\nYou are a good (female) match!\n");
			}
			else
			{
				printf("\nSorry, you are not a good (female) match!\n");
			}
			break;

		case 2:

			if (((i_Age >= i_Male_Range[0]) && (i_Age <= i_Male_Range[1])) || ((i_Age >= i_Male_Range[2]) && (i_Age <= i_Male_Range[3])))
			{
				printf("\nYou are a good (male) match!\n");
			}
			else
			{
				printf("\nSorry, you are not a good (male) match!\n");
			}
			break;

		default:
			printf("\nGender or age was not valid!\n");
			break;
		}

	return 0;
}