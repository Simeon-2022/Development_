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




int main(void)
{
	const int rows = STRUCT_SIZE_CARS;
	const int cols = ARR_SIZE_BRAND;

	char* modelNames[STRUCT_SIZE_CARS] = { '\0' }; //modelNames[0] = cars->details.type.brand;
	char user_selection[5] = { '\0' };

	struct Vehicle_company cars[STRUCT_SIZE_CARS] =
	{
		{
			.details.type.brand = "Honda",
			.details.type.model = "Civic",
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.counts_left = 1,
			.details.id = 1111,
			.details.identificator = 1
		},
		{
			.details.type.brand = "Honda",
			.details.type.model = "Accord",
			.counts_left = 0,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 2222,
			.details.identificator = 1
		},
		{

			.details.type.brand = "Honda",
			.details.type.model = "HR-V",
			.counts_left = 0,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 3333,
			.details.identificator = 1
		},
		{
			.details.type.brand = "Toyota",
			.details.type.model = "Prius",
			.counts_left = 3,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 4444,
			.details.identificator = 2
		},
		{
			.details.type.brand = "Toyota",
			.details.type.model = "Avensis",
			.counts_left = 4,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 5555,
			.details.identificator = 2
		},
		{
			.details.type.brand = "Alfa Romeo",
			.details.type.model = "147",
			.counts_left = 3,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 6666,
			.details.identificator = 3
		},
		{
			.details.type.brand = "Alfa Romeo",
			.details.type.model = "Brera",
			.counts_left = 5,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 7777,
			.details.identificator = 3
		},
		{
			.details.type.brand = "Alfa Romeo",
			.details.type.model = "156 Sports Wagon",
			.counts_left = 3,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 8888,
			.details.identificator = 3
		},
		{
			.details.type.brand = "Moskvich",
			.details.type.model = "Aleko",
			.counts_left = 1,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 9999,
			.details.identificator = 4
		},
		{
			.details.type.brand = "Fiat",
			.details.type.model = "Panda",
			.counts_left = 0,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 1222,
			.details.identificator = 5
		},
		{
			.details.type.brand = "Fiat",
			.details.type.model = "Punto",
			.counts_left = 0,
			.details.description = "\n -> Color: 'Sky blue'\n -> Fuel type: Diesel.\n -> Fuels economy :\n    * Urban - 10l/100km\n    * Extra-urban - 5l/100km\n    * Combined - 7l/100km\n\n -> Extras and conveniences:\n    * 5 seats\n    * hatch-back\n    * manual gearbox\n    * AC\n    * power windows\n    * roofhatch\n    * EPS\n    * ABS\n    * Anti-theft system\n    * navigation\n    * cruise control",
			.details.id = 1333,
			.details.identificator = 5
		}

	};

	/*TO DO:
	struct list_Cars_node_ arr_node_cars[STRUCT_SIZE_CARS];
	struct list_Cars_node_* p_node_cars = arr_node_cars;

	for (const struct Vehicle_company* p_Cars = cars; p_Cars != NULL; p_Cars++, p_node_cars++)
	{
		p_node_cars->node_cars = *p_Cars;

	}
	struct list_Cars_node_* p_Next_available_carBrand;
	*/

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
			choose_brand_menu(model_names(modelNames, cars, STRUCT_SIZE_CARS), cars, STRUCT_SIZE_CARS, user_selection); //accept node (identofocator and availability) instead of cars ?

			if (*user_selection != 'b')
			{
				choose_vehicle_menu(cars, STRUCT_SIZE_CARS, user_selection); //accept node instead of cars ?
				if (*user_selection != 'b')
				{
					vehicle_details_menu(cars, STRUCT_SIZE_CARS, user_selection);
				}
			}
		}
	}


	return 0;
}
