#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
char str[] = { "HELLO" };
	char rstr[6];
	int y = 0;

	for  (int i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] + 32;
	}


	for (int i = 0; i < strlen(str); i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}
