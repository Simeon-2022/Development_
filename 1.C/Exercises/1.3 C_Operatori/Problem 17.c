#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int main()
{
	int cycle = 3;
	long long A = 1;
	while (cycle > 0)
	{
		int var;
		printf("Type in an integer value: ");
		scanf("%d", &var);

		//for (int i = 0; i < var; i++)
		//{ A << 1;
		if (cycle % 2 != 0)
		{
			A ^= A << var;
		}
		else
		{
			A ^= A >> var;
		}
		
		//}
		//A ^= var;
		printf("----> %lld", A);
		printf("\n"); 
		cycle--;
	}
}
