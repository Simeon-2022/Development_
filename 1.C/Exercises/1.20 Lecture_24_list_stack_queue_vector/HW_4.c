#define _CRT_SECURE_NO_WARNINGS
#define VECTOR_INIT_CAPACITY 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_24.h"



int main(void) {

	char* A = "A string literal.";
	char* B = "B string literal..";
	char* C = "C string literal...";
	char* D = "D string literal....";

	vector vec;
	my_vector_init(&vec);
	//my_vector_push_back_v2_(A, &vec);

	printf("%zd\n", my_vector_capacity(&vec));

	my_vector_reserve(&vec, 4);

	printf("%zd\n", my_vector_capacity(&vec));

	my_vector_reserve(&vec, 14);

	printf("%zd", my_vector_capacity(&vec));

	return 0;
}