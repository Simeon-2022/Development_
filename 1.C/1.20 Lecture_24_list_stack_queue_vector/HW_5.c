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
	my_vector_push_back_v2_(A, &vec);

	my_vector_resize(&vec, 30);
	printf("%s\n", vec.data);

	my_vector_resize(&vec, 10); //if -1 ->behaviour is undefined
	printf("%s\n", vec.data);

	my_vector_resize_init(&vec, 3, "7");
	printf("%s", vec.data);

	return 0;
}