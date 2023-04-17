#define _CRT_SECURE_NO_WARNINGS
#define NAME_ARRAY 20
#define USER_ARRAY_LENGTH 5
#define DRIVING_LICENCE_CATEGORIES 4
#define PIN_ARRAY 11

#define ARR_SIZE_BRAND 50
#define ARR_SIZE_VIN 17
#define ARR_SIZE_DESCRIPTION 450
#define STRUCT_SIZE_CARS 15
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "HW_8_Module_1.h"
#include "Datetime.h"

const char* licence_to_char[] = { "A","B","C","D","AA","AB","BC","DD" };
char categorySymbol[3] = { '\0' };


/*TO DO:
	struct list_Cars_node_ arr_node_cars[STRUCT_SIZE_CARS];
	struct list_Cars_node_* p_node_cars = arr_node_cars;

	for (const struct Vehicle_company* p_Cars = cars; p_Cars != NULL; p_Cars++, p_node_cars++)
	{
		p_node_cars->node_cars = *p_Cars;

	}
	struct list_Cars_node_* p_Next_available_carBrand;
	*/

int main(void)
{
	srand((unsigned int)time(NULL));

	FILE* fp_CARS_READ = NULL;
	FILE* fp_CARS_WRITE = NULL;

	FILE* fp_PERSONS_READ = NULL;
	FILE* fp_PERSONS_WRITE = NULL;

	const int rows = STRUCT_SIZE_CARS;
	const int cols = ARR_SIZE_BRAND;

	char* modelNames[STRUCT_SIZE_CARS] = { '\0' }; //modelNames[0] = cars->details.type.brand;
	char user_selection[5] = { '\0' };

	Vehicle_company cars[STRUCT_SIZE_CARS] = { '\0' };

	fp_CARS_READ = fp_car_r(fp_CARS_READ);
	read_Car_Data_from_file(cars, fp_CARS_READ, FORMAT_CARS_FROM, STRUCT_SIZE_CARS);
	fclose(fp_CARS_READ);

	UserData person[USER_ARRAY_LENGTH] = { '\0' };
	fp_PERSONS_READ = fp_persons_r(fp_PERSONS_READ);
	read_User_Data_from_file(person, fp_PERSONS_READ, FORMAT_PERSON_FROM);
	fclose(fp_PERSONS_READ);

	for (; *user_selection != 'q';)
	{
		main_menu(user_selection); // pointer to functions ?
		if (atoi(user_selection) == Press_1)
		{
			*user_selection = '\0';
			choose_vehicle_menu(cars, STRUCT_SIZE_CARS, user_selection); //accept node instead of cars ?
			if (*user_selection != 'b')
			{
				vehicle_details_menu(cars, STRUCT_SIZE_CARS, user_selection);
			}
		}
		else if (atoi(user_selection) == Press_2)
		{
			*user_selection = '\0';
			choose_brand_menu(model_names(modelNames, cars, STRUCT_SIZE_CARS), cars, STRUCT_SIZE_CARS, user_selection); //accept node (identificator and availability) instead of cars ?

			if (*user_selection != 'b')
			{
				choose_vehicle_menu(cars, STRUCT_SIZE_CARS, user_selection); //accept node instead of cars ?
				if (*user_selection != 'b')
				{
					vehicle_details_menu(cars, STRUCT_SIZE_CARS, user_selection);
				}
			}
		}
		else if(atoi(user_selection) == Press_3)
		{
			*user_selection = '\0';
			adminMenu(cars, person, user_selection, fp_CARS_WRITE, fp_PERSONS_WRITE);
		}
	}

	//>------------------------------------------------Date---------------------------------------------------------<
	
	/*int days = 3;
	datetime startDate =
	{
		.day_of_month = 30,
		.month = December,
		.year = 2022
	};

	datetime final_date = date_variance(startDate, days);
	print_time(&final_date);

	datetime final_date2 = date_variance_v2(startDate, days);
	print_time(&final_date2);

	datetime date_begin =
	{
		.day_of_month = 20,
		.month = December,
		.year = 2022
	};

	datetime date_end =
	{
		.day_of_month = 20,
		.month = December,
		.year = 2023
	};

	printf("%0.lf", date_difference(date_begin, date_end));

	char buffer[50];

	puts("\n--------------------------------------------");

	my_strftime(&date_end, buffer);

	printf("%s", buffer);*/
	
	
	
	return 0;
}
