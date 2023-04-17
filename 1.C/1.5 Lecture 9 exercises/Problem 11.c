#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	const int i_LuckyNumber = 10;
	int i_RandomNumber = 100;
	int i = 5;
	bool isFound = false;

	while (i != 0)
	{
		printf("Enter a guess number from 0 to 20. You have %d attempts left. --> ", i--);
		scanf(" %d", &i_RandomNumber);

		if (i_RandomNumber < 0 || i_RandomNumber > 20)
		{
			printf("\nThe number is outside the specified scope! Try again!\n\n");
			continue;
		}
		else if (i_RandomNumber < i_LuckyNumber)
		{
			printf("\nYour number is lower that the secret number. Try again!\n\n");

		}
		else if (i_RandomNumber > i_LuckyNumber)
		{
			printf("\nYour number is bigger that the secret number. Try again!\n\n");
		}
		else
		{
			printf("\nCongrats! You guessed it!\n");
			isFound = true;
			break;
		}
	}

	if (!isFound)
	{
		printf("Sorry! You lost!\n");
	}
	return 0;
}
