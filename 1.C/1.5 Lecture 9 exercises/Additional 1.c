#define _CRT_SECURE_NO_WARNINGS
//#define MAX_CHARS_PER_LINE 36
#include <stdio.h>
#include <stdbool.h>

int main()
{

	const double simpleInterestBaseAmount = 100;
	const double simpleInterest = 0.10;
	double simpleInterestTotalSum = simpleInterestBaseAmount; // starting amount

	const double compoundInterestBaseAmount = 100;
	const double compoundInterest = 0.05;
	double compoundInterestTotalSum = compoundInterestBaseAmount; // starting amount
	int yearsCount = 0;

	while (simpleInterestTotalSum >= compoundInterestTotalSum)
	{
		simpleInterestTotalSum += simpleInterestBaseAmount * simpleInterest;
		compoundInterestTotalSum += compoundInterestTotalSum * compoundInterest;
		yearsCount++;
	}
	printf("Years needed:            %d years\n", yearsCount);
	printf("Simple Interest total:   %.2f$\n", simpleInterestTotalSum );
	printf("Compound Interest total: %.2f$", compoundInterestTotalSum );
return 0;
}