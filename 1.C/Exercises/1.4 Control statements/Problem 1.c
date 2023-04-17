#define MAX_CHARS_PER_LINE 16
#include <conio.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>


unsigned ParseUnsignedLiteral(const char* line, int base)
{
	int sum = 0;
	int power = 0;

	int num = atoi(line);
	scanf(" %d", &base);
	while (num != 0)
	{
		int temp = num % 10;
		sum += temp * pow(base, power);
		num /= 10;
		power++;
	}

	// print output
	fputs("> ", stdout);
	printf("%d", sum);
	return 0;
};


int main()
{
	int x = 0;

	int base = 0;
	int remainder;
	char line[MAX_CHARS_PER_LINE];
	
	fgets(line, MAX_CHARS_PER_LINE, stdin);

	ParseUnsignedLiteral(line, base);

return 0;

}