//#pragma once

#ifndef HW_8_MODULE_1
#define HW_8_MODULE_1

struct Vehicle
{
	char brand[ARR_SIZE_BRAND];
	char model[ARR_SIZE_BRAND];

};

struct Vehicle_Data
{
	struct Vehicle type;
	char description[ARR_SIZE_DESCRIPTION];
	int id;
	int identificator;
};

struct Vehicle_company
{
	struct Vehicle_Data details;
	int counts_left;
	int price_per_day;
};

struct list_Cars_node_
{

	struct Vehicle_company node_cars;
	struct list_Cars_node_* p_Next_available_carBrand;
	struct list_Cars_node_* p_Next_available_carBrand_per_selection;

};

//char* brand[ARR_SIZE_BRAND] = { "Honda", "Toyota", "Alfa Romeo", "Fiat", "Moskvich"};

enum Main_Menu
{
	Press_1 = 1,
	Press_2,
}main_menu_option;

size_t	my_strlen_NULL			(const char arrPtr[]);
int		my_strcmp				(const char* arr_1, const char* arr_2);
void	choose_vehicle_menu		(const struct Vehicle_company* vehicle_List, int list_size, char* user_selection);
void	choose_brand_menu		(const char* brand_list[], const struct Vehicle_company* vehicle_List, int list_size, char* user_selection);
char**	model_names				(const char* brand_list[], const struct Vehicle_company* vehicle_List, int list_size);
void	vehicle_details_menu	(const struct Vehicle_company* vehicle_List, int list_size, char* user_selection);
void	main_menu				(char* user_selection);

#endif // !HW_8_MODULE_1
