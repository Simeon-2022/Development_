#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>


static int g_StaticGlobalVariable = 0;

void test(int* i) {
	(*i)++;
};

int main(){

  test(&g_StaticGlobalVariable);
	test(&g_StaticGlobalVariable);
	test(&g_StaticGlobalVariable);

	printf("%d\n", g_StaticGlobalVariable);
	return 0;
  }
