#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
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

	//iterFunc(J);
	my_list* obj = NULL;
	my_list_push_back(A, &obj);
	my_list_push_back(B, &obj);
	my_list_push_back(C, &obj);
	my_list_push_back(D, &obj);
	my_list_push_back(E, &obj);
	my_list_push_back(F, &obj);
	my_list_push_back(G, &obj);

	my_list_iterate(&obj, iterFunc);

	printNode(obj);

	free(obj);
	return 0;
}