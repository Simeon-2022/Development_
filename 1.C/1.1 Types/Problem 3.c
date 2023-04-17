#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void print_bin(unsigned n)
{
	unsigned i;
	for (i = 1 << 7; i > 0; i = i >> 1)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}
int main() {

	
	int c = UINT_MAX;
	print_bin(c + 1);

	return 0;
}
