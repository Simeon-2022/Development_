#define _CRT_SECURE_NO_WARNINGS
//#define MAX_CHARS_PER_LINE 36
#include <stdio.h>
#include <stdbool.h>
int main(){
	const double baseAmount = 1000000;
	const double withdrawal = 100000;
	const float interest = 0.08f;
	int yearsCount = 0;

	double iAvailable = baseAmount;

	while (iAvailable > 0)
	{

		iAvailable += (iAvailable * interest);
		iAvailable -= withdrawal;
		yearsCount++;
	}
	printf("Years needed %d years\n", yearsCount);

return 0;
}