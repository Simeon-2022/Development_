#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions_23.h"


int main(void) {

	char* A = "A string literal. ";
	char* B = "B stri...";
	char* C = "C stri...";
	char* D = "D stri...";
	char* E = "E string literal. ";
	char* F = "F stri...";
	char* G = "G string literal. ";
	char* J = "J string literal. ";

	my_list* obj = NULL;

	my_list_push_back(A, &obj);
	my_list_push_back(B, &obj);
	my_list_push_back(C, &obj);
	my_list_push_back(D, &obj);
	my_list_push_back(E, &obj);
	my_list_push_back(F, &obj);
	my_list_push_back(G, &obj);
	//my_list_push_back(J, &obj);

	//my_list_resize_init(&obj, 3, A);
	//my_list_resize_init(&obj, 1, B);
	//my_list_resize(&obj, 0);
	//my_list_resize_init(&obj, 2, C);
	//my_list_resize(&obj, 3);
	//my_list_resize(&obj, 2);
	//my_list_resize_init(&obj, 4, G);
	//my_list_resize_init(&obj, 4, D);

	//my_list_erase_if(&obj, *predicateFunc);

	printf("Deleted nodes >> %d\n", (int)my_list_erase_if(&obj, *predicateFunc));
	printNode(obj);

	free(obj);

	return 0;
}