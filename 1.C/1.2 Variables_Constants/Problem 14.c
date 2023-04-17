#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

int g_Global_Variable = 1;

void test(int* i) {
	(*i)++;
};

int main()
{
test(&g_Global_Variable);
	test(&g_Global_Variable);
	test(&g_Global_Variable);

	printf("%d\n", g_Global_Variable);
	return 0;
}
