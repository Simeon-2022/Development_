#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int main() {

	printf("Size of 'char'      is %d bytes or %d bits.\n", sizeof(char), sizeof(char) * CHAR_BIT);
	printf("Size of 'int'       is %d bytes or %d bits.\n", sizeof(int), sizeof(int) * CHAR_BIT);
	printf("Size of 'short'     is %d bytes or %d bits.\n", sizeof(short), sizeof(short) * CHAR_BIT);
	printf("Size of 'long'      is %d bytes or %d bits.\n", sizeof(long), sizeof(long) * CHAR_BIT);
	printf("Size of 'long long' is %d bytes or %d bits.\n", sizeof(long long), sizeof(long long) * CHAR_BIT);
	printf("Size of 'size_t'    is %d bytes or %d bits.\n", sizeof(size_t), sizeof(size_t) * CHAR_BIT);
	printf("Size of 'float'     is %d bytes or %d bits.\n", sizeof(float), sizeof(float) * CHAR_BIT);
	printf("Size of 'double'    is %d bytes or %d bits.\n", sizeof(double), sizeof(double) * CHAR_BIT);
	printf("Size of 'bool'      is %d bytes or %d bits.", sizeof(bool), sizeof(bool) * CHAR_BIT);

	return 0;
}
