#include <stdio.h>

int main()
{
int nResult = 13; 
	int nX = 4;
	printf("Result = %d\n", nResult);
	nResult *= nX;
	printf("Result *= %d -> %d\n", nX, nResult);
	nResult = 200;
	nResult %= nX;
	printf("Result %%= %d -> %d\n", nX, nResult);
	nResult = 5;
	nResult &= nX;
	printf("Result &= %d -> %d\n", nX, nResult);
	nResult = 10;
	nResult ^= nX;
	printf("Result ^= %d -> %d\n", nX, nResult);
	nResult = 15;
	nResult |= nX;
	printf("Result |= %d -> %d\n", nX, nResult);
	nX = 1;
	nResult = 7;
	nResult <<= nX;
	printf("Result <<= %d -> %d\n", nX, nResult);
	nResult = 7;
	nResult >>= nX;
	printf("Result >>= %d -> %d\n", nX, nResult);
  
  return 0;
}
