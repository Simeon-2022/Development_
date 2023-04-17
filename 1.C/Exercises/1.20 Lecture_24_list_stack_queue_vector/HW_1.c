#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_24.h"


int main()
{
   	vector new_vec;
	vector* new_vec_ptr = NULL;

	my_vector_init(&new_vec);
	my_vector_init_ptr(&new_vec_ptr);

	my_vector_clear(&new_vec);
	my_vector_clear_ptr(&new_vec_ptr);

	return 0;
}


