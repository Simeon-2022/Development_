#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


{
	
	signed char c = CHAR_MIN; 
	printf("%d\n", c);

	unsigned char uc = UCHAR_MAX; 
	printf("%u\n", uc);

	unsigned short us = 63498;//USHRT_MAX;
	printf("%u\n", us);

	unsigned int ui = 4294967292;//UINT_MAX;

	signed long long ul = -9000000000000775845;
	printf("%lld", ul);

	return 0;
}
