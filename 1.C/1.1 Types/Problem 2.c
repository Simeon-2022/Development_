#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int main() {

	printf("'unsigned char overflow' before [%u] and after [%u].\n", (int) (unsigned char)UCHAR_MAX , (int)(unsigned char)(UCHAR_MAX + 1));
	printf("'unsigned char overflow' before [%d] and after [%d].", (int)(char)SCHAR_MAX , (int)(char)(SCHAR_MAX + 1));



	return 0;
}
