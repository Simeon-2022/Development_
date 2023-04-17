#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	
	int i_Gender_Indicator = 0;
	int i_Age = 0;
	const int i_Female_Range_From = 25;
	const int i_Female_Range_To = 35;
	const int i_Male_Range_From = 30;
	const int i_Male_Range_To = 40;

	printf("Please enter your gender:\n\n> female = [1]\n> male   = [2]\n\nYour choice: ");
	scanf(" %d", &i_Gender_Indicator);
	printf("\nPlease enter your age: ");
	scanf(" %d", &i_Age);

	switch (i_Gender_Indicator)
	{
	case 1:
		(i_Age >= i_Female_Range_From) && (i_Age <= i_Female_Range_To) ? printf("\nYou are a good (female) match!\n") : printf("\nSorry, you are not a good (female) match!\n");
		break;

	case 2:

		(i_Age >= i_Male_Range_From) && (i_Age <= i_Male_Range_To) ? printf("\nYou are a good (male) match!\n") : printf("\nSorry, you are not a good (male) match!\n");
		break;

	default:
		printf("\nGender or age was not valid!\n");
		break;
	}

	return 0;
}