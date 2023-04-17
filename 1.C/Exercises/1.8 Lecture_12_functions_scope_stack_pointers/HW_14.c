//Задача 14
//Напишете функция, която обръща стойностите на две променливи
//от тип int*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions_12.h"


int main(void) {

	int a = 0; int* a_ptr = &a;
	int b = 0; int* b_ptr = &b;

	printf("\nCharacter 'a' -> ");
	scanf("%d", &a);

	printf("\nCharacter 'b' -> ");
	scanf("%d", &b);

	printf("\nPointer characters before change:\n *a = %d\n *b = %d", *a_ptr, *b_ptr);
	change_pointer_variables(&a_ptr, &b_ptr);

	printf("\n\nPointer characters after change:\n *a = %d\n *b = %d\n", *a_ptr, *b_ptr);
	return 0;
}