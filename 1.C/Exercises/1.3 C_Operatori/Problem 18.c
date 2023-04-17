#define _CRT_SECURE_NO_WARNINGS
#include<windows.h> 
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>


int main()
{
	int x;
	int iter;
	int bin;
	int remainder;
	int count = 0;
	int iLeadingZeroes = 0;
	int iMaxSize = 100;
	int intSequence[100];
	int arrBinary[100];
	int number = 0;
	unsigned int seconds = 10;

	printf("Start entering sequence and when done type in [-1]:\n");

	for (int i = 0; i < iMaxSize; i++)
	{
		scanf("%d", &number);
		if (number >= 0)
		{
			intSequence[i] = number;
			iter = i;
		}
		else
		{
			intSequence[i] = -1;
			break;
		}
	}
				system("cls");

	for (int z = 0; z <= iter; )
	{
		while (intSequence[z] >= 0)
		{
			x = intSequence[z];

			while (x != 0)
			{
				bin = (x / 2);
				remainder = x - bin * 2;
				x = bin;
				arrBinary[count] = remainder;
				count++;
			}
			if (count < 4) // check if leading zeroes are needed 
			{
				iLeadingZeroes = 4;
				switch (count)
				{
				case 1:
					iLeadingZeroes -= count;
					break;
				case 2:
					iLeadingZeroes -= count;
					break;
				case 3:
					iLeadingZeroes -= count;
					break;

				default:
					break;
				}
				//if (iLeadingZeroes != 4)
				//{
					for (int i = (4 - iLeadingZeroes); i < 4; i++) // check
					{
						arrBinary[i] = 0;
					}
				//}
			}

			for (int i = 0; i < count + iLeadingZeroes; i++)
			{

				if (arrBinary[i] == 1)
				{

					Sleep(200); 
					printf("%c", '*');
				}
				else
				{
					Sleep(200);
					printf("%c", '.');
				}

			}
			count = 0;
			iLeadingZeroes = 0;
			//printf("\r");
			//printf("\n");
			z++;
			//scanf("%d", &iter);
		}
	}
	return 0;
}