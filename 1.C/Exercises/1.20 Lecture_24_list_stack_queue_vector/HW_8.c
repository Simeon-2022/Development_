#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_24.h"

int main(void) {

	char* A = "ZZXPMNKJBCA";

	vector vec;

	my_vector_init(&vec);
	my_vector_push_back_v2_(A, &vec);

	my_vector_sort(&vec, (*compare_ltr_));

	printf("%s", vec.data);

	return 0;
}