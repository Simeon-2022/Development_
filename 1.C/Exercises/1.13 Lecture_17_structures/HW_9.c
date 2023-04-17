#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "Functions_17.h"
/*Задача 9
● Дефинирайте тип Person с име и възраст. -> ok
● Дефинирайте масив от Person и го инициализирайте. -> ok
● Дефинирайте тип PersonNode с 2 member-а: Person и PersonNode* - информация за Person и указател към PersonNode, който
може да сочи към друг обект от тип PersonNode.
● Дефинирайте масив от тип PersonNode. Обходете масива и копирайте информацията за всеки елемент от съответстващия му по
индекс елемент от първия масив (от тип Person). В същия цикъл пренасочете всеки member указател към PersonNode към
следващия елемент от масива, който обхождаме (към 0 за последния елемент)
● Принтирайте съдържанието на създадения от нас свързан списък, използвайки само PersonNode обекти и техните members (без
да използвате името на масивите). Дефинирайте отделна функция за тази цел.

● Обходете масива отново и пренасочете member указателите на всеки PersonNode, чиито Person обект е с възраст над 18 год,
така че да сочат към следващия обект от масива от тип PersonNode, чиито Person member е с възраст над 18 год. (ако обектите с
индекс 0 и 1 и 4 са над 18, обектите с индекс 2 и 3 са под 18, member указателят на обект с индекс 1 трябва да почне да сочи не
към обект с индекс 2, ами да “пропусне всички следващи елементи под 18” и да се пренасочи към обект с индекс 4)
● Принтирайте съдържанието на масива (всички хора) и на списъка (само над 18).*/

struct Person
{
	const char* name;
	int age;

};

struct list_Person_node_
{
	struct Person person;
	struct list_Person_node_* next_Person;

};

void print_list_Person_node_(const struct list_Person_node_* arr_Person_list) {

	printf("\n--------------------------------------\n");

	while (arr_Person_list != NULL)
	{
		printf("Name: %s -> age: %d\n", arr_Person_list->person.name, arr_Person_list->person.age);
		arr_Person_list = arr_Person_list->next_Person;
	}
}

//void print_list_Person_node_by_limit(const struct list_Person_node_* arr_Person_list, int array_size, int age_limit) {
//
//	printf("\n--------------------------------------\n");
//
//	bool is_Found = false;
//
//	const struct list_Person_node_* endPtr = arr_Person_list + array_size;
//
//	while (arr_Person_list != NULL)
//	{
//		if (arr_Person_list->person.age >= age_limit && !is_Found)
//		{
//			is_Found = true;
//			printf("Name: %s -> age: %d\n", arr_Person_list->person.name, arr_Person_list->person.age);
//			arr_Person_list = arr_Person_list->next_Person;
//		}
//		else if (is_Found) //&& arr_Person_list->next_Person != NULL)
//		{
//			printf("Name: %s -> age: %d\n", arr_Person_list->person.name, arr_Person_list->person.age);
//			arr_Person_list = arr_Person_list->next_Person;
//		}
//		else if (arr_Person_list < endPtr)
//		{
//			arr_Person_list++;
//		}
//		else
//		{
//			puts("No matches found");
//			break;
//		}
//	}
//}


int main(void)
{
	int age = 0;

	struct Person persons[ARR_SIZE] =
	{
		{
			.name = "A",
			.age = 0
		},
		{
			.name = "B",
			.age = 50
		},
		{
			.name = "C",
			.age = 40
		},
		{
			.name = "D",
			.age = 0
		},
		{
			.name = "E",
			.age = 50
		},
		{
			.name = "F",
			.age = 0
		},
		{
			.name = "J",
			.age = 50
		},
		{
			.name = "K",
			.age = 40
		},
		{
			.name = "L",
			.age = 0
		},
		{
			.name = "M",
			.age = 0
		}

	};

	struct list_Person_node_ arr_Person[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr_Person[i].person = persons[i];

		if (i + 1 < ARR_SIZE)
		{
			arr_Person[i].next_Person = &arr_Person[i + 1];
		}
		else
		{
			arr_Person[i].next_Person = NULL;
		}
	}

	print_list_Person_node_(arr_Person);

	printf("\nEnter age criteria (>=): ");
	scanf("%d", &age);

	for (int i = 0, idx = 0; i < ARR_SIZE; i++, idx++)
	{
		if (arr_Person[i].person.age >= age)
		{
			arr_Person[i - idx].next_Person = &arr_Person[i];
			arr_Person[i].next_Person = NULL;

			idx = 0;
		}
		else
		{
			arr_Person[i].next_Person = NULL;
		}
	}

	bool check = false;
	const struct list_Person_node_* begin_Ptr = arr_Person;

	for (; begin_Ptr < arr_Person + ARR_SIZE; begin_Ptr++)
	{
		if (begin_Ptr->person.age >= age)
		{
			check = true;
			break;
		}
	}

	if (!check)
	{
		puts("No matches found");
	}
	else
	{
		print_list_Person_node_(begin_Ptr);
	}
	return 0;
}