#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
char str[] = { "Hello" };
	char rstr[6];
	int y = 0;

	for  (int i = strlen(str); i >= 0; i--, y++)
	{
		if (str[i] != '\0')
		{
			rstr[y] = str[i];
		}
		else
		{
			y--;
		}
	}
	rstr[y] = '\0';

	for (int i = 0; i < strlen(rstr); i++)
	{
		printf("%c", rstr[i]);
	}

	return 0;
}
