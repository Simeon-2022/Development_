#define _CRT_SECURE_NO_WARNINGS
#include "Functions_23.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {

	char* A = "A string literal. ";
	char* B = "B string literal.. ";
	char* C = "C string literal... ";


	my_list* firstNode= NULL;
	my_list_init(&firstNode);
	firstNode->char_Arr = (char*)realloc(firstNode->char_Arr, sizeof(char) * strlen(A) + 1);
	strcpy(firstNode->char_Arr, A);


	my_list* secondNode = NULL;
	my_list_init(&secondNode);
	secondNode->char_Arr = (char*)realloc(secondNode->char_Arr, sizeof(char) * strlen(B) + 1);
	firstNode->next = secondNode;
	strcpy(secondNode->char_Arr, B);


	my_list* thirdNode = NULL;
	my_list_init(&thirdNode);
	thirdNode->char_Arr = (char*)realloc(thirdNode->char_Arr, sizeof(char) * strlen(C) + 1); 
	secondNode->next = thirdNode;
	strcpy(thirdNode->char_Arr, C);
	


	printNode(firstNode);

	my_list_clear(firstNode);
	//my_list_clear(secondNode); - memory already freed
	//my_list_clear(thirdNode); - memory already freed

	return 0;
}

/*
	firstNode = (my_list*)realloc(firstNode, sizeof(my_list) * 2); 
	my_list_init(&firstNode[1]); // indirection ** -> *
	firstNode[1].char_Arr = (char*)realloc(firstNode[1].char_Arr, sizeof(char) * strlen(B)); // not working
	firstNode->next = &firstNode[1];
	strcpy(firstNode[1].char_Arr, B);
*/