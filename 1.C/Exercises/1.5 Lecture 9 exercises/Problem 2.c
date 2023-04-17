#include <stdio.h>

int main(){
	
	const int iValue1 = 10;
	int iValue2;

	printf("Enter your guess: ");
	scanf("%d", &iValue2);

	if (iValue2 >= iValue1)
	{
		printf("You win!");
	}
	else
	{
		printf("Try again!");
	}
	
	return 0;
}