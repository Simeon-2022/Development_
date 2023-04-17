
#define _CRT_SECURE_NO_WARNINGS

#define NAME_ARRAY 20
#define USER_ARRAY_LENGTH 5
#define DRIVING_LICENCE_CATEGORIES 4
#define PIN_ARRAY 11
#define VIN_ARRAY 18

#define ARR_SIZE_BRAND 50
#define ARR_SIZE_VIN 17
#define ARR_SIZE_DESCRIPTION 450
#define STRUCT_SIZE_CARS 15
#define SIZE_EXTRAS_CARS 17

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "HW_8_Module_1.h"

FILE* fp_car_r(FILE* fp_) {

	fp_ = fopen("HW_Cars_data.txt", "r");

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

FILE* fp_car_w(FILE* fp_) {

	fp_ = fopen("HW_Cars_data.txt", "w");

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

FILE* fp_persons_r(FILE* fp_) {
	fp_ = fopen("HW_User_data.txt", "r");

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

FILE* fp_persons_w(FILE* fp_) {
	fp_ = fopen("HW_User_data.txt", "w");

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

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
	printf("\n > 'b' -> back to main menu\n > 'o' -> proceed to order");

	printf("\n\n > Your input: ");
	scanf(" %s", user_selection);
}

void choose_vehicle_menu(struct Vehicle_company* vehicle_List, int list_size, char* user_selection) {

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

char** model_names(const char* brand_list[], const Vehicle_company* vehicle_List, int list_size) {

	int idx_1 = 0;
	int idx_last_record_next = id_cars_last_record_next_(vehicle_List, list_size);


	for (int i = 0; brand_list[i] != NULL; i++)
	{
		brand_list[i] = NULL;
	}

	for (const struct Vehicle_company* iter_main = vehicle_List; iter_main < vehicle_List + idx_last_record_next; iter_main++)
	{
		bool is_found = false;

		for (int i = 0; brand_list[i] != NULL; i++)
		{
			if (!my_strcmp(iter_main->details.type.brand, brand_list[i]))
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

	//for (int idx_2 = 0; idx_2 <= idx_1; idx_2++) // check for duplicates
	//{
	//	if (brand_list[idx_2] == NULL)
	//	{
	//		continue;
	//	}
	//	else if (!my_strcmp(iter_main->details.type.brand, brand_list[idx_2]))
	//	{
	//		is_found = true;
	//		break;
	//	}
	//}
	//if (!is_found && iter_main->counts_left > 0)
	//{
	//	brand_list[idx_1++] = iter_main->details.type.brand;
	//}

	return (char**)brand_list;
}

void main_menu(char* user_selection) {

	printf("\n------------------------------------------------\n");
	printf(" Main Menu:");
	printf("\n------------------------------------------------\n");

	printf(
		"\n > Press [1] to see full list of vehicles"
		"\n > Press [2] to see vehicles filtered by brand"
		"\n > Press [3] to enter admin menu"
		"\n > Press [q] to quit\n"
		" >> "
	);

	scanf(" %s", user_selection);

	// TO DO error handling with function getchar
	while (*user_selection != 'q')
	{
		if (atoi(user_selection) == Press_1 || atoi(user_selection) == Press_2 || atoi(user_selection) == Press_3)
		{
			break;
		}
		else if (*user_selection != 'q')
		{
			printf("\n > Not a valid option. >> ");
		}
		scanf(" %s", user_selection);
	}
}

//===================================================-User_Data-========================================================================//

int my_strcmp_v2(const char* arr_1, const char* arr_2) {

	const char* ptr_1 = arr_1;
	const char* ptr_2 = arr_2;
	int iterator = 0;

	for (const char* ptr_1 = arr_1, *ptr_2 = arr_2; *ptr_1 != '\0' || *ptr_2 != '\0';) //to avoid incrementing post deter zero
	{
		if (*ptr_1 > *ptr_2)
		{
			return 1;
		}
		else if (*ptr_1 < *ptr_2)
		{
			return -1;
		}

		if (*ptr_1 != '\0')
		{
			ptr_1++;
		}
		if (*ptr_2 != '\0')
		{
			ptr_2++;
		}
	}
	return 0;
};

E_DrivingLicenseCategory driving_licence_category_from_char(char* ch) {


	for (int i = 0; i < driving_licence_count; i++)
	{
		if (!my_strcmp_v2(ch, licence_to_char[i]))
		{
			return i;
		}
	}
	return driving_licence_count;
}

void read_User_Data_from_file(UserData* persons, FILE* fp_FROM, const char* FORMAT_FROM) {


	for (int idx = 1; idx <= USER_ARRAY_LENGTH; idx++)
	{
		if (fscanf(fp_FROM, FORMAT_FROM, persons->names[0], persons->names[1], persons->names[2], &persons->PIN, &categorySymbol) == 5)
		{
			persons->driving_licence = driving_licence_category_from_char(categorySymbol);
			persons++;
		}
		else
		{
			printf("Warning: Loading file corrupt! Exiting.. \n");
			exit(EXIT_FAILURE);

		}
	}
}

void write_User_Data_to_file(UserData* persons, FILE* fp_TO, const char* FORMAT_TO, int userArrayLength) {

	UserData* end_ptr_persons = persons + userArrayLength;

	for (; persons < end_ptr_persons; persons++)
	{
		fprintf(fp_TO, FORMAT_TO, persons->names[0], persons->names[1], persons->names[2], persons->PIN, licence_to_char[persons->driving_licence]);
	}
}

void print_User_Data_on_screen_(UserData* persons, FILE* fp_TO, const char* FORMAT, int userArrayLength) {

	UserData* end_ptr_persons = persons + userArrayLength;

	for (int idx = 1; persons < end_ptr_persons; persons++, idx++)
	{
		fprintf(fp_TO, FORMAT, idx, persons->names[0], persons->names[1], persons->names[2], persons->PIN, licence_to_char[persons->driving_licence]);
	}
}

void Fill_User_Names(UserData* persons, int idx_persons)
{
	char* namesNames[3] = { "Personal", "Surname", "Fathers" };

	char nameInput[NAME_ARRAY];

	putchar('\n');

	while ((getchar()) != '\n');

	for (int i = 0; i < 3; i++)
	{
		printf("%s:\t[%s] >> ", namesNames[i], persons[idx_persons].names[i]);
		fgets(nameInput, NAME_ARRAY, stdin);

		nameInput[strlen(nameInput) - 1] = '\0';
		if (nameInput[0] != '\0')
		{
			strcpy(persons[idx_persons].names[i], nameInput);
		}
	}
}

void Fill_User_PIN(UserData* persons, int idx_persons)
{
	char pin[PIN_ARRAY] = { '\0' };
	while ((getchar()) != '\n');

	for (; strlen(pin) < 10;)
	{
		printf("PIN: [%s] >> ", persons[idx_persons].PIN);
		scanf("%10[0-9]", pin);

		if (strlen(pin) < 10)
		{
			puts("PIN incomplete!");
		}
		else
		{
			strcpy(persons[idx_persons].PIN, pin);
			break;
		}
		while ((getchar()) != '\n');
	}
}

void Fill_User_DrivingLicence(UserData* persons, int idx_persons)
{
	while ((getchar()) != '\n');
	char categorySymbol[3] = { '\0' };

	for (; strlen(categorySymbol) == 0 || driving_licence_category_from_char(categorySymbol) == driving_licence_count;) {

		printf("Drivng licence: [%s] >> ", licence_to_char[persons[idx_persons].driving_licence]);
		scanf("%2[A-D]", categorySymbol);

		if (strlen(categorySymbol) == 0 || driving_licence_category_from_char(categorySymbol) == driving_licence_count)
		{
			puts("Licence incorrect!");
			//TODO: list the possible options?
		}
		else
		{
			persons[idx_persons].driving_licence = driving_licence_category_from_char(categorySymbol);
			break;
		}
		while ((getchar()) != '\n');
	}


	persons[idx_persons].driving_licence = driving_licence_category_from_char(categorySymbol);
}

void Change_User_Data(UserData* persons, const char* FORMAT_PERSON_PRINTSCREEN) {

	int idx_persons = -1;
	int idx_field = -1;
	char choice;

	printf("\nChange user data? Y(es) / N(o) -> ");
	scanf(" %c", &choice);

	if (tolower(choice) == 'y')
	{
		do
		{
			putchar('\n');
			print_User_Data_on_screen_(persons, stdout, FORMAT_PERSON_PRINTSCREEN, USER_ARRAY_LENGTH);

			printf("\nType in the user line number to edit -> ");
			scanf("%d", &idx_persons);
			printf("\nType in which field:\n > Name \t\t-> 1\n > PIN \t\t\t-> 2\n > Driving licence \t-> 3\n >> ");
			scanf("%d", &idx_field);

			if (idx_field == Name)
			{
				Fill_User_Names(persons, idx_persons - 1);
			}
			else if (idx_field == PIN)
			{
				Fill_User_PIN(persons, idx_persons - 1);
			}
			else if (idx_field == Driving_licence)
			{
				Fill_User_DrivingLicence(persons, idx_persons - 1);
			}

			printf("\nNew user info: ");
			printf(FORMAT_PERSON_PRINTSCREEN, idx_persons, persons[idx_persons - 1].names[0], persons[idx_persons - 1].names[1], persons[idx_persons - 1].names[2], persons[idx_persons - 1].PIN, licence_to_char[persons[idx_persons - 1].driving_licence]);

			printf("\nReload user list? Y(es) / N(o) -> ");
			scanf(" %c", &choice);

		} while ((char)tolower(choice) != 'n');
	}
}

//===================================================-Car_Data-========================================================================//

void read_Car_Data_from_file(Vehicle_company* cars, FILE* fp_CARS, const char* FORMAT_CARS_FROM, int arrayLength) {



	for (int idx = 1; idx <= arrayLength; idx++, cars++)
	{
		fscanf(fp_CARS, FORMAT_CARS_FROM, &cars->details.type.brand, &cars->details.type.model, &cars->details.description, &cars->counts_left, &cars->details.id, &cars->details.identificator, &cars->price_per_day);
	}
}

void write_Cars_Data_to_file(Vehicle_company* cars, FILE* fp_CARS_to_FILE, const char* FORMAT_CARS_TO, int arrayLength) {

	Vehicle_company* end_ptr_CARS = cars + arrayLength;

	for (; (cars < end_ptr_CARS) && (cars->details.id >= 1111 && cars->details.id <= 9999); cars++)
	{
		fprintf(fp_CARS_to_FILE, FORMAT_CARS_TO, cars->details.type.brand, cars->details.type.model, cars->details.type.year, cars->details.type.required_licence, cars->details.type.VIN, cars->details.description, cars->counts_left, cars->details.id, cars->details.identificator, cars->price_per_day);
	}
}

void print_Cars_Data_on_screen_(Vehicle_company* cars, FILE* fp_CARS_from_FILE, const char* FORMAT_CARS_TO, int arrayLength) {

	Vehicle_company* end_ptr_CARS = cars + arrayLength;

	for (; cars < end_ptr_CARS; cars++)
	{
		fprintf(fp_CARS_from_FILE, FORMAT_CARS_TO, cars->details.type.brand, cars->details.type.model, cars->details.description, cars->counts_left, cars->details.id, cars->details.identificator, cars->price_per_day);
	}
}

void print_Cars_Data_on_screen_by_id_(Vehicle_company* cars, int arrayLength) {

	for (Vehicle_company* end_ptr_CARS = cars + arrayLength; cars < end_ptr_CARS; cars++)
	{
		if (cars->details.id >= 1111 && cars->details.id <= 9999)
		{
			printf("\n > id# %d -> %s %s", cars->details.id, cars->details.type.brand, cars->details.type.model);
		}
	}
}

void Fill_Car_Brand_Names(Vehicle_company* cars, int idx_cars)
{
	//while (getchar() != '\n');
	char brandInput[NAME_ARRAY];

	printf("New brand name: ");
	fgets(brandInput, NAME_ARRAY, stdin);

	if (brandInput[0] == '\n')
	{
		fgets(brandInput, NAME_ARRAY, stdin);
	}
	brandInput[strlen(brandInput) - 1] = '\0';
	strcpy(cars[idx_cars].details.type.brand, brandInput);
}

void Fill_Car_Model(Vehicle_company* cars, int idx_cars)
{
	//while ((getchar()) != '\n');
	char modelInput[NAME_ARRAY];

	printf("New model name: ");
	fgets(modelInput, NAME_ARRAY, stdin);

	if (modelInput[0] == '\n')
	{
		//return 
		cars[idx_cars].details.type.model;
	}
	modelInput[strlen(modelInput) - 1] = '\0';
	//return 
	strcpy(cars[idx_cars].details.type.model, modelInput);
}

void Fill_Car_Year(Vehicle_company* cars, int idx_cars)
{
	int countValue = -1;
	printf("Previous year of manufacturing: %d\n", cars[idx_cars].details.type.year);
	printf("New year of manufacturing: ");
	scanf(" %d", &countValue);

	cars[idx_cars].details.type.year = countValue;
}

void Fill_Car_DrivingLicence(Vehicle_company* cars, int idx_cars)
{
	while ((getchar()) != '\n');
	char categorySymbol[3] = { '\0' };

	for (; strlen(categorySymbol) == 0 || driving_licence_category_from_char(categorySymbol) == driving_licence_count;) {

		printf("Default DL code: [%s] >> ", licence_to_char[cars[idx_cars].details.type.required_licence]);
		scanf("%2[A-D]", categorySymbol);

		if (strlen(categorySymbol) == 0 || driving_licence_category_from_char(categorySymbol) == driving_licence_count)
		{
			puts("Licence incorrect!");
			//TODO: list the possible options?
		}
		else
		{
			cars[idx_cars].details.type.required_licence = driving_licence_category_from_char(categorySymbol);
			break;
		}
		while ((getchar()) != '\n');
	}


	cars[idx_cars].details.type.required_licence = driving_licence_category_from_char(categorySymbol);
}

void Fill_Car_VIN(Vehicle_company* cars, int idx_cars)
{
	char vin[VIN_ARRAY] = { '\0' };
	while ((getchar()) != '\n');

	for (; strlen(vin) < VIN_ARRAY;)
	{
		printf("VIN: [%s] >> ", cars[idx_cars].details.type.VIN);
		scanf("%17[A-Z0-9]", vin);

		if (strlen(vin) != 17)
		{
			puts("VIN incomplete!");
		}
		else
		{
			strcpy(cars[idx_cars].details.type.VIN, vin);
			break;
		}
		while ((getchar()) != '\n');
	}
}

void Fill_Car_Description(Vehicle_company* cars, int idx_cars)
{
	//while ((getchar()) != '\n');
	//char null_array[ARR_SIZE_DESCRIPTION] = { '\0' };
	char rollback_array[ARR_SIZE_DESCRIPTION] = { '\0' };

	strcpy(rollback_array, cars[idx_cars].details.description);

	for (int i = 0; i < ARR_SIZE_DESCRIPTION; i++)
	{
		cars[idx_cars].details.description[i] = '\0';
	}

	const char* extras[SIZE_EXTRAS_CARS] = { " -> Color: ", " -> Fuel type: ", " -> Fuel economy l/100km:", "    * Urban - ", "    * Extra-urban - ", "    * Combined - ", " -> Extras and conveniences:", "    * seats - ", "    * gearbox - ", "    * AC-", "    * power windows-", "    * roofhatch-", "    * EPS-", "    * ABS-", "    * Anti-theft system-", "    * navigation-", "    * cruise control-" };

	char ch = ' ';

	for (int i = 0; i < SIZE_EXTRAS_CARS; i++)
	{
		int idx_extras = (int)strlen(extras[i]) - 1;
		if (extras[i][idx_extras] == '-')
		{
			printf("%s", extras[i]);
			printf("> Y(es)/N(o)? >> ");

			if ((ch = tolower(getchar())) == 'y')
			{
				strncat(cars[idx_cars].details.description, extras[i], idx_extras);

				int lengthCars = (int)strlen(cars[idx_cars].details.description);
				if (i < SIZE_EXTRAS_CARS - 1)
				{
					cars[idx_cars].details.description[lengthCars] = '\n';
					cars[idx_cars].details.description[lengthCars + 1] = '\0';
				}
			}
			while ((getchar()) != '\n');
		}
		else if (extras[i][idx_extras] == ' ')
		{
			char input[15];
			printf("%s>> ", extras[i]);
			fgets(input, 15, stdin);
			if (input[0] == '\n')
			{
				fgets(input, 15, stdin);
			}

			strcat(cars[idx_cars].details.description, extras[i]);
			strcat(cars[idx_cars].details.description, input);
		}
		else if (extras[i][idx_extras] == ':')
		{
			printf("%s", extras[i]);
			strcat(cars[idx_cars].details.description, extras[i]);
			int lengthCars = (int)strlen(cars[idx_cars].details.description);
			cars[idx_cars].details.description[lengthCars] = '\n';
			cars[idx_cars].details.description[lengthCars + 1] = '\0';
			putchar('\n');
		}
	}

	if (unique_id_validator(cars, cars[idx_cars].details.id))
	{
		printf("\nApply changes Y(es)/N(o)? >> ");
		scanf(" %c", &ch);
	}

	if (tolower(ch) == 'n')
	{
		strcpy(cars[idx_cars].details.description, rollback_array);
	}
}

void Fill_Car_Counts_left(Vehicle_company* cars, int idx_cars)
{
	int countValue = -1;
	printf("Old count value: %d\n", cars[idx_cars].counts_left);
	printf("New count value: ");
	scanf(" %d", &countValue);

	cars[idx_cars].counts_left = countValue;
}

void Fill_Car_ID(Vehicle_company* cars, int idx_cars)
{
	int IdValue = -1;

	if (unique_id_validator(cars, IdValue))
	{
		puts("Old id# value: n/a");
	}
	else
	{
		printf("Old id# value: %d\n", cars[idx_cars].details.id);
	}

	int max = 9999;
	int min = 1111;

	IdValue = ((rand() % (int)(((max)+1) - (min))) + (min));

	while (!unique_id_validator(cars, IdValue))
	{
		IdValue = ((rand() % (int)(((max)+1) - (min))) + (min));
	}

	printf("New id# value: %d\n", IdValue);
	cars[idx_cars].details.id = IdValue;
}

void Fill_Car_Identificator(Vehicle_company* cars, int idx_cars)
{
	int identificatorValue = -1;
	bool is_found = false;
	int idx_end = id_cars_last_record_next_(cars, STRUCT_SIZE_CARS);

	for (int i = 0; i < idx_end; i++)
	{
		if ((i != idx_cars) && (!strcmp(cars[i].details.type.brand, cars[idx_cars].details.type.brand)))
		{
			cars[idx_cars].details.identificator = cars[i].details.identificator; // = current brand identificator
			printf("Brand identificator assigned: %d -> [%s] brand\n", cars[idx_cars].details.identificator, cars[idx_cars].details.type.brand);
			is_found = true;
			break;
		}
	}

	if (!is_found)
	{
		int temp_identificator = 0;
		// build a log file with available identificators in case a brand is deleted
		for (Vehicle_company* ptr_cars = cars; ptr_cars < cars + idx_end; ptr_cars++)
		{
			if ((ptr_cars->details.identificator >= temp_identificator))// && !unique_id_validator(cars, ptr_cars->details.id))
			{
				temp_identificator = ptr_cars->details.identificator + 1;
			}
		}
		cars[idx_cars].details.identificator = temp_identificator;
		printf("Brand identificator to be assigned: %d -> [%s] brand\n", cars[idx_cars].details.identificator, cars[idx_cars].details.type.brand);
	}
}

void Fill_Car_Price_per_day(Vehicle_company* cars, int idx_cars)
{
	float priceValue = 0.0f;
	printf("Old price per day: %.2f\n", cars[idx_cars].price_per_day);
	printf("New price per day: ");
	scanf(" %f", &priceValue);

	//return 
	cars[idx_cars].price_per_day = priceValue;
}

int index_Cars_Data(Vehicle_company* cars, int id, int arrayLength) {
	int idx = 0;
	for (Vehicle_company* end_ptr_CARS = cars + arrayLength; (cars < end_ptr_CARS) && (cars->details.id != id); cars++)
	{
		idx++;
	}
	return idx;
}

void Change_Cars_Data(Vehicle_company* cars, const char* FORMAT_CARS_PRINTSCREEN, int arrayLength) {

	int id_cars = -1;
	int idx_field = -1;
	char choice;

	printf("\nChange cars data? Y(es) / N(o) -> ");
	scanf(" %c", &choice);

	if (tolower(choice) == 'y')
	{
		do
		{
			print_Cars_Data_on_screen_by_id_(cars, arrayLength);

			printf("\n\nType in the car 'id#' to edit -> ");
			scanf("%d", &id_cars);
			printf("\nChoose field:\n * Brand Name \t\t-> 1\n * Model \t\t-> 2\n * Year \t\t-> 3\n * DL code \t\t-> 4\n * VIN \t\t\t-> 5\n * Description \t\t-> 6\n * Counts_left \t\t-> 7\n * ID \t\t\t-> 8\n * Identificator \t-> 9\n * Price per day \t-> 10\n * Modify all sections \t-> 11\n\nYour input -> "); //TODO replace the submenu options with array?
			scanf("%d", &idx_field);

			int idx_car = index_Cars_Data(cars, id_cars, arrayLength);

			if (idx_field == Brand_Name)
			{
				while (getchar() != '\n');
				char previousBrand[NAME_ARRAY];
				strcpy(previousBrand, cars[idx_car].details.type.brand);
				Fill_Car_Brand_Names(cars, idx_car);
				printf("\nChange to id# %d: [%s] >> [%s]\n", id_cars, previousBrand, cars[idx_car].details.type.brand);
				//check if previous brand was unique => keep id & identificator else assign new
			}
			else if (idx_field == Model)
			{
				while ((getchar()) != '\n');
				char previousModel[NAME_ARRAY];
				strcpy(previousModel, cars[idx_car].details.type.model);
				Fill_Car_Model(cars, idx_car);
				printf("\nChange to id# %d: [%s] >> [%s]\n", id_cars, previousModel, cars[idx_car].details.type.model);
			}
			else if (idx_field == Year)
			{
				while ((getchar()) != '\n');
				int previousYear = cars[idx_car].details.type.year;
				Fill_Car_Year(cars, idx_car);
				printf("\nChange to id# %d: [%d] >> [%d]\n", id_cars, previousYear, cars[idx_car].details.type.year);
			}
			else if (idx_field == DL_code)
			{
				//while ((getchar()) != '\n');
				char previousDL[NAME_ARRAY];
				strcpy(previousDL, licence_to_char[cars[idx_car].details.type.required_licence]);
				Fill_Car_DrivingLicence(cars, idx_car);
				printf("\nChange to id# %d: [%s] >> [%s]\n", id_cars, previousDL, licence_to_char[cars[idx_car].details.type.required_licence]);
			}
			else if (idx_field == VIN)
			{
				//while ((getchar()) != '\n');
				char previousVIN[NAME_ARRAY];
				strcpy(previousVIN, cars[idx_car].details.type.VIN);
				Fill_Car_VIN(cars, idx_car);
				printf("\nChange to id# %d: [%s] >> [%s]\n", id_cars, previousVIN, cars[idx_car].details.type.VIN);
			}

			else if (idx_field == Description)
			{
				while ((getchar()) != '\n');
				Fill_Car_Description(cars, idx_car); //TODO break-down to sub categories
				printf("\nChange to id# %d:\n\n%s\n", id_cars, cars[idx_car].details.description);

			}
			else if (idx_field == Counts_left)
			{
				int previousCount = cars[idx_car].counts_left;
				Fill_Car_Counts_left(cars, idx_car);
				printf("\nChange to id# %d: [%d] >> [%d]\n", id_cars, previousCount, cars[idx_car].counts_left);
			}
			else if (idx_field == ID)
			{
				int previousID = cars[idx_car].details.id;
				Fill_Car_ID(cars, idx_car);
				printf("\nChange to id# %d: [%d] >> [%d]\n", id_cars, previousID, cars[idx_car].details.id);
			}
			else if (idx_field == Identificator)
			{
				int previousIdentificator = cars[idx_car].details.identificator;
				Fill_Car_Identificator(cars, idx_car);
				printf("\nChange to id# %d: [%d] >> [%d]\n", id_cars, previousIdentificator, cars[idx_car].details.identificator);
			}
			else if (idx_field == Price_Per_Day)
			{
				float oldPrice = cars[idx_car].price_per_day;
				Fill_Car_Price_per_day(cars, idx_car);
				printf("\nChange to id# %d: [%.2f] >> [%.2f]\n", id_cars, oldPrice, cars[idx_car].price_per_day);
			}
			else if (idx_field == All_elements)
			{
				for (int i = 0; i < 10; i++)
				{
					(*fun_ptr_arr[i])(cars, idx_car);
				}
			}

			printf("\nReload vehicle list? Y(es) / N(o) -> ");
			scanf(" %c", &choice);

		} while ((char)tolower(choice) != 'n');
	}
}

int unique_id_validator(Vehicle_company* cars, int rand_id) {

	for (Vehicle_company* start_ptr_CARS = cars; start_ptr_CARS < cars + STRUCT_SIZE_CARS; start_ptr_CARS++)
	{
		if (start_ptr_CARS->details.id == rand_id)
		{
			return 0;
			break;
		}
	}
	return 1;
}

int id_cars_last_record_next_(const Vehicle_company* cars, int list_size) {

	int idx_last_record = 0;

	for (const Vehicle_company* start_ptr_CARS = cars, *end_ptr_CARS = cars + list_size; start_ptr_CARS < end_ptr_CARS; start_ptr_CARS++)
	{
		if (start_ptr_CARS->details.id >= 1111 && start_ptr_CARS->details.id <= 9999)
		{
			idx_last_record++;
		}
		else
		{
			break;
		}
	}
	return idx_last_record;
}

void add_new_vehicle(Vehicle_company* cars, const char* FORMAT_CARS_PRINTSCREEN, int arrayLength) {

	int idx_last_record_next = id_cars_last_record_next_(cars, arrayLength);

	if (idx_last_record_next < STRUCT_SIZE_CARS)
	{
		char choice;
		printf("\nCreate new vehicle data? Y(es) / N(o) -> ");
		scanf(" %c", &choice);

		if (tolower(choice) == 'y')
		{
			while (getchar() != '\n');
			for (int i = 0; i < 10; i++)
			{
				(*fun_ptr_arr[i])(cars, idx_last_record_next);
			}
			puts("\nNew vehicle data:\n");

			printf("Brand: %s \nModel: %s \n%s \nAvailable: %d \nid#: %d \nIdentificator: %d \nPrice per day: %.2f\n\n", cars[idx_last_record_next].details.type.brand, cars[idx_last_record_next].details.type.model, cars[idx_last_record_next].details.description, cars[idx_last_record_next].counts_left, cars[idx_last_record_next].details.id, cars[idx_last_record_next].details.identificator, cars[idx_last_record_next].price_per_day);
		}
	}
	else
	{
		printf("Warning: Storage memory is full. You need to delete a record.");
		putchar('\n');
		//puts("Press enter");

	}
}

void (*fun_ptr_arr[10])(Vehicle_company* cars, int idx_car) = { Fill_Car_Brand_Names ,Fill_Car_Model,Fill_Car_Year,Fill_Car_DrivingLicence,Fill_Car_VIN ,Fill_Car_Description ,Fill_Car_Counts_left ,Fill_Car_ID ,Fill_Car_Identificator ,Fill_Car_Price_per_day };


//===================================================-Admin_menu-========================================================================//

void adminMenu(Vehicle_company* cars, UserData* person, char* user_selection, FILE* fp_CARS_WRITE, FILE* fp_PERSONS_WRITE) {


	for (; user_selection[0] != 'b';)
	{
		printf("\n------------------------------------------------\n");
		printf(" Admin Menu:");
		printf("\n------------------------------------------------\n");
		printf
		(
			"\n > Press [1] to access vehicle list"
			"\n > Press [2] to access customer list"
			"\n > Press [b] to return to main menu\n"
			// add back button functionality
		);
		//while (getchar() != '\n');
		printf(" >> ");
		fgets(user_selection, 5, stdin);
		if (user_selection[0] == '\n')
		{
			fgets(user_selection, 5, stdin);
		}

		if (atoi(user_selection) == Press_1)
		{
			printf
			(
				"\n > Press [1] to add new vehicle"
				"\n > Press [2] to remove existing vehicle [under construction]"
				"\n > Press [3] to modify existing vehicle"
			);
			//while (getchar() != '\n');
			printf("\n >> ");
			fgets(user_selection, 5, stdin);

			if (atoi(user_selection) == Press_1)
			{
				add_new_vehicle(cars, FORMAT_PERSON_PRINTSCREEN, STRUCT_SIZE_CARS);
			}
			/*	else if (atoi(user_selection) == Press_2)
				{
					getchar();
					continue;
				}*/
			else if (atoi(user_selection) == Press_3)
			{
				Change_Cars_Data(cars, FORMAT_CARS_PRINTSCREEN, STRUCT_SIZE_CARS);
			}

			fp_CARS_WRITE = fp_car_w(fp_CARS_WRITE);

			write_Cars_Data_to_file(cars, fp_CARS_WRITE, FORMAT_CARS_TO, STRUCT_SIZE_CARS);
			fclose(fp_CARS_WRITE);
		}
		else if (atoi(user_selection) == Press_2)
		{
			Change_User_Data(person, FORMAT_PERSON_PRINTSCREEN);

			fp_PERSONS_WRITE = fopen("HW_User_data.txt", "w");

			write_User_Data_to_file(person, fp_PERSONS_WRITE, FORMAT_PERSON_TO, USER_ARRAY_LENGTH);
			fclose(fp_PERSONS_WRITE);
		}
		else if (user_selection[0] != 'b')
		{
			printf("Not a valid choice");
		}
	}
}






