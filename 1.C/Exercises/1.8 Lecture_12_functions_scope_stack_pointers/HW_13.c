//Задача 13
//Напишете функция, която обръща стойностите на две променливи
//от тип int

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions_12.h"

int main(void) {

	int a = 0;
	int b = 0;

	printf("\nCharacter 'a' -> ");
	scanf("%d", &a);
	
	printf("\nCharacter 'b' -> ");
	scanf("%d", &b);

	printf("\nCharacters before change:\n a = %d\n b = %d",a,b);
	change_variables(&a, &b);

	printf("\n\nCharacters after change:\n a = %d\n b = %d\n", a, b);
	return 0;
}