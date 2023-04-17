#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 20
#define ANIMAL_ARR_SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_18.h"

int main(void) {

	Animal arr[ANIMAL_ARR_SIZE] =
	{
		{
			.animalType_name = "lion",
			.type = Carnivore
		},
		{
			.animalType_name = "goat",
			.type = Herbivore
		},
		{
			.animalType_name = "rat",
			.type = Omnivore
		},
		{
			.animalType_name = "pigeon",
			.type = Herbivore
		},
		{
			.animalType_name = "vulture",
			.type = Carnivore
		}
	};

	Animal* begin_arr = arr;
	
	for (int i = 0; (i + 1) < ANIMAL_ARR_SIZE; i++)
	{
		
		if (i + 1 == ANIMAL_ARR_SIZE)
		{
			arr[i + 1].ptr_Animal = NULL;
		}
		else
		{
			arr[i].ptr_Animal = &begin_arr[i + 1];
		}
	}

	print_Animal(arr);


	return 0;
}