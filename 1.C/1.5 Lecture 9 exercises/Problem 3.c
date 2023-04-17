#include <stdio.h>

int main(){
	
	int iHeight = 0;
	const int iRange_1 = 146;
	const int iRange_2 = 181;
	const int iRange_3 = 206;

	printf("Enter height (cm): ");
	scanf("%d", &iHeight);

	if (iHeight < iRange_1)
	{
		printf("Short");
	}
	else if (iHeight < iRange_2)
	{
		printf("Middle");
	}
	else if (iHeight < iRange_3)
	{
		printf("Tall");
	}
	else
	{
		printf("You are exceptionally tall");
	}
	
	return 0;
}