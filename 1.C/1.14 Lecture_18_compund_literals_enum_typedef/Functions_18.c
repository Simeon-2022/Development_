#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 20
#define ANIMAL_ARR_SIZE 5
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Functions_18.h"

char* animalType_to_char[3] = { "Herbivore", "Carnivore", "Omnivore" };

void print_Animal(const struct Animal* arr) {

	for (int i = 1; arr != NULL; i++)
	{
		printf("%d. Animal name: %s      \t=> Animal type: %s\n", i, arr->animalType_name, animalType_to_char[arr->type]);
		arr = arr->ptr_Animal;
	}
}