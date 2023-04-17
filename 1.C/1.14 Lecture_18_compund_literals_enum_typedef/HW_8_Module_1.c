
#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE_BRAND 50
#define ARR_SIZE_VIN 17
#define ARR_SIZE_DESCRIPTION 450
#define STRUCT_SIZE_CARS 11
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "HW_8_Module_1.h"


size_t	my_strlen_NULL(const char arrPtr[]) {

	size_t lengthArray = 0;

	if (arrPtr == NULL)
	{
		return (int)lengthArray;
	}
	while (*arrPtr != '\0')
	{
		lengthArray++;

		arrPtr++;
	}

	return (int)lengthArray;
};

int my_strcmp(const char* arr_1, const char* arr_2) {

	const char* ptr_1 = arr_1;
	const char* ptr_2 = arr_2;
	int idx = 0;

	if (my_strlen_NULL(ptr_1) > my_strlen_NULL(ptr_2))
	{
		idx = (int)my_strlen_NULL(ptr_1);
	}
	else
	{
		idx = (int)my_strlen_NULL(ptr_2);
	}

	for (int i = 0; i < idx; i++)
	{
		if (*(ptr_1 + i) > *(ptr_2 + i))
		{
			return 1;
		}
		else if (*(ptr_1 + i) < *(ptr_2 + i))
		{
			return -1;
		}
	}
	return 0;
};

void vehicle_details_menu(const struct Vehicle_company* vehicle_List, int list_size, char* user_selection) {

	printf("\n------------------------------------------------\n");
	printf(" Vehicle Details Menu:");
	printf("\n------------------------------------------------\n");

	int check = atoi(user_selection);
	for (const struct Vehicle_company* p_full_List = vehicle_List; p_full_List != vehicle_List + list_size; p_full_List++)
	{
		if (check == p_full_List->details.id)
		{
			printf("\n -> Description:\n    * %s %s\n    * Available: %d\n %s", p_full_List->details.type.brand, p_full_List->details.type.model, p_full_List->counts_left, p_full_List->details.description);
		}
	}

	putchar('\n');
	printf("\n > 'b' -> back to main menu\n > 'y' -> proceed to order");

	printf("\n\n > Your input: ");
	scanf(" %s", user_selection);
}

void choose_vehicle_menu(const struct Vehicle_company* vehicle_List, int list_size, char* user_selection) {

	printf("\n------------------------------------------------\n");
	printf(" Choose Vehicle Menu:");
	printf("\n------------------------------------------------\n");

	int check = atoi(user_selection);

	for (const struct Vehicle_company* p_full_List = vehicle_List; p_full_List != vehicle_List + list_size; p_full_List++)
	{
		if (p_full_List->counts_left > 0 && *user_selection == '\0')
		{
			printf("\n > id# %d -> %s %s, available: %d", p_full_List->details.id, p_full_List->details.type.brand, p_full_List->details.type.model, p_full_List->counts_left);
		}
		else if (p_full_List->counts_left > 0 && p_full_List->details.identificator == check)
		{
			printf("\n > id# %d -> %s %s, available: %d", p_full_List->details.id, p_full_List->details.type.brand, p_full_List->details.type.model, p_full_List->counts_left);
		}
	}
	putchar('\n');
	printf("\n > 'b' -> back to main menu\n");

	printf("\n > Your input: ");
	scanf(" %s", user_selection);
}

void choose_brand_menu(const char* brand_list[], const struct Vehicle_company* vehicle_List, int list_size, char* user_selection) {

	printf("\n------------------------------------------------\n");
	printf("  Choose Brand Menu:");
	printf("\n------------------------------------------------\n");

	for (const char** p_brand_List = brand_list; *p_brand_List != NULL; p_brand_List++) // address of the first element of the corresponding array
	{
		for (const struct Vehicle_company* p_full_List = vehicle_List; p_full_List != vehicle_List + list_size; p_full_List++)
		{
			if (!my_strcmp(p_full_List->details.type.brand, *p_brand_List))
			{
				printf("\n > %d -> %s", p_full_List->details.identificator, *p_brand_List);
				break;
			}
		}
	}
	putchar('\n');
	printf("\n > 'b' -> back to main menu\n");

	printf("\n > Your input: ");
	scanf(" %s", user_selection);
}

char** model_names(const char* brand_list[], const struct Vehicle_company* vehicle_List, int list_size) {

	int row = 0;
	int idx_1 = 0;

	//const char** p_brand_List = brand_list;
	for (const struct Vehicle_company* iter_main = vehicle_List; iter_main < vehicle_List + list_size; iter_main++, row++)
	{
		bool is_found = false;

		for (int idx_2 = 0; idx_2 <= idx_1; idx_2++) // check for duplicates
		{
			if (brand_list[idx_2] == NULL)
			{
				continue;
			}
			else if (!my_strcmp(iter_main->details.type.brand, brand_list[idx_2]))
			{
				is_found = true;
				break;
			}
		}
		if (!is_found && iter_main->counts_left > 0)
		{
			brand_list[idx_1++] = iter_main->details.type.brand;
		}
	}
	return (char**) brand_list;
}

void main_menu(char* user_selection) {

	printf("\n------------------------------------------------\n");
	printf(" Main Menu:");
	printf("\n------------------------------------------------\n");

	printf(
		"\n > Press '1' to choose a vehicle (list of all available vehicles)"
		"\n > Press '2' to choose vehicle by brand (will filter only by brand name)"
		"\n > Press 'q' to quit\n"
		"\n > Your selection: "
		  );

	scanf(" %s", user_selection);

	// TO DO error handling with function getchar
	while (*user_selection != 'q')
	{
		if (atoi(user_selection) == Press_1)
		{
			break;
		}
		else if (atoi(user_selection) == Press_2)
		{
			break;
		}
		else if (*user_selection != 'q')
		{
			printf("\n > Not a valid user_selection. Try again: ");
		}
		scanf(" %s", user_selection);
	}
}