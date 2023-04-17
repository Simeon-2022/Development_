#define _CRT_SECURE_NO_WARNINGS

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
	my_vector_push_back_v2_(A, &vec);

	printf("%c\n", *my_vector_front(&vec));
	printf("%c\n", *my_vector_back(&vec));
	printf("%c\n", *my_vector_at(&vec,10));

	return 0;
}