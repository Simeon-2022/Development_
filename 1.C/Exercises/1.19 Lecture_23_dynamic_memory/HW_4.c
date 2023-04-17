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

	my_list* new_list = NULL;

	my_list_push_front(C, &new_list);
	my_list_push_front(B, &new_list);
	my_list_push_front(A, &new_list);

	my_list_insert(D, &new_list, 9);

	//my_list_push_back(A, &new_list);
	//my_list_push_back(C, &new_list);

	printNode(new_list);
	free(obj);
	return 0;
}