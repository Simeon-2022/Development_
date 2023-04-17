#pragma once
#ifndef FUNCTIONS_18_H
#define FUNCTIONS_18_H
#define ARR_SIZE 20
#define ANIMAL_ARR_SIZE 5

//HW_1_________________________________________________
typedef enum AnimalType
{
	Herbivore,
	Carnivore,
	Omnivore
}AnimalType;

typedef struct Animal
{
	char animalType_name[ARR_SIZE];
	AnimalType type;
	struct Animal* ptr_Animal;
}Animal;


void print_Animal(const struct Animal* arr);

//HW_2_________________________________________________


#endif // !FUNCTIONS_18_H
