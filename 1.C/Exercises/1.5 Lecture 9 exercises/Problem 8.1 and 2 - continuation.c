#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	
	for (int i = 1; i <= 9; i++)
	{
		if (i != 5 && i != 7)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}