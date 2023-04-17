#define _CRT_SECURE_NO_WARNINGS
//#define MAX_CHARS_PER_LINE 36
#include <stdio.h>


void toLowerCase(char str[]) {

	int size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')

			str[i] += 32;
	}
}



int main(void) {

	char str[] = "HElLO, 123\n";
	toLowerCase(str);
	printf("%s", str);// "hello, 123\n";

	return 0;

}