#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions_23.h"

int main(void) {


	char* A = "A string literal. ";
	char* B = "B string literal.. ";
	char* C = "C string literal... ";
	char* D = "D string literal.... ";


	my_list* obj = NULL;
	//my_list_pop_back(&obj);

	my_list_push_back(A, &obj);
	my_list_push_back(B, &obj);
	my_list_push_back(C, &obj);
	my_list_push_back(D, &obj);
	my_list_pop_front(&obj);
	my_list_pop_front(&obj);
	my_list_pop_front(&obj);
	my_list_pop_front(&obj);
	//my_list_pop_back(&obj);
	//my_list_pop_back(&obj);
	//my_list_pop_back_v2(&obj);
	my_list_erase(&obj, 1);
	my_list_erase(&obj, 2);
	my_list_erase(&obj, 3);

	printNode(obj);

	free(obj);
	return 0;
}