//#pragma once

#ifndef HW_8_MODULE_1
#define HW_8_MODULE_1
#define LINE_LENGTH 50
#define NAME_ARRAY 20
#define PIN_ARRAY 11
#define VIN_ARRAY 18

extern const char* licence_to_char[]; // = { "A","B","C","D","AA","AB","BC","DD" };
extern char categorySymbol[3];// = { '\0' };

static const char* FORMAT_CARS_FROM = "%[^\n] %[^\n] %[^;];\n%d\n%d\n%d\n%f\n";
//static const char* FORMAT_CARS_TO = "%s\n%s\n %s;\n%d\n%d\n%d\n%f\n\n";
static const char* FORMAT_CARS_TO = "%s\n%s\n%d\n%d\n%s\n%s;\n%d\n%d\n%d\n%f\n\n";
static const char* FORMAT_CARS_PRINTSCREEN = "Brand: %s\nModel: %s\nYear manufactured: %d\nDL code: %s\nVIN: %s\n%s\n -> Available: %d \n -> id#: %d \n -> Identificator: %d \n -> Price per day: %.2f\n\n";

static const char* FORMAT_PERSON_FROM = "%s %s %[^,], %[^,], %s\n";
static const char* FORMAT_PERSON_TO = "%s %s %s, %s, %s\n";
static const char* FORMAT_PERSON_PRINTSCREEN = "%d. Name: [%s %s %s], PIN: [%s], Licence: [%s]\n";

typedef enum E_DrivingLicenseCategory
{
	A,
	B,
	C,
	D,
	AA,
	AB,
	BC,
	DD,

	driving_licence_count
}E_DrivingLicenseCategory;

struct Vehicle
{
	char brand[ARR_SIZE_BRAND];
	char model[ARR_SIZE_BRAND];
	int year;	 
	char VIN[VIN_ARRAY]; //JH4KA3256JC800624
	E_DrivingLicenseCategory required_licence;
};

struct Vehicle_Data
{
	struct Vehicle type;
	char description[ARR_SIZE_DESCRIPTION];
	int id;
	int identificator;
};

typedef struct Vehicle_company
{
	struct Vehicle_Data details;
	int counts_left;
	float price_per_day;
}Vehicle_company;

struct list_Cars_node_
{
	struct Vehicle_company node_cars;
	struct list_Cars_node_* p_Next_available_carBrand;
	struct list_Cars_node_* p_Next_available_carBrand_per_selection;
};


typedef struct UserData
{
	char names[3][NAME_ARRAY];
	char PIN[PIN_ARRAY];
	E_DrivingLicenseCategory driving_licence;
}UserData;

//char* brand[ARR_SIZE_BRAND] = { "Honda", "Toyota", "Alfa Romeo", "Fiat", "Moskvich"};

typedef enum Main_Menu
{
	Press_1 = 1,
	Press_2,
	Press_3
}main_menu_option;

typedef enum UserFieldCategory
{
	Name = 1,
	PIN,
	Driving_licence,

}UserFieldCategory;

typedef enum CarFieldCategory
{
	Brand_Name = 1,
	Model,
	Year,
	DL_code,
	VIN,
	Description,
	Counts_left,
	ID,
	Identificator,
	Price_Per_Day,
	
	All_elements

}UserFieldCategory;

size_t	my_strlen_NULL			(const char arrPtr[]);
int		my_strcmp				(const char* arr_1, const char* arr_2);
void	choose_vehicle_menu		(struct Vehicle_company* vehicle_List, int list_size, char* user_selection);
void	choose_brand_menu		(const char* brand_list[], const struct Vehicle_company* vehicle_List, int list_size, char* user_selection);
char**	model_names				(const char* brand_list[], const Vehicle_company* vehicle_List, int list_size);
void	vehicle_details_menu	(const struct Vehicle_company* vehicle_List, int list_size, char* user_selection);

//===================================================-User_Data-========================================================================//
FILE*	fp_persons_r					(FILE* fp_);
FILE*	fp_persons_w					(FILE* fp_);
E_DrivingLicenseCategory driving_licence_category_from_char(char* ch);
int		my_strcmp_v2				(const char* arr_1, const char* arr_2);
void	read_User_Data_from_file	(UserData* persons, FILE* fp_FROM, const char* FORMAT_FROM);
void	write_User_Data_to_file		(UserData* persons, FILE* fp_TO, const char* FORMAT_TO, int userArrayLength);
void	print_User_Data_on_screen_	(UserData* persons, FILE* fp_TO, const char* FORMAT, int userArrayLength);
void	Fill_User_Names				(UserData* persons, int idx_persons);
void	Fill_User_PIN				(UserData* persons, int idx_persons);
void	Fill_User_DrivingLicence	(UserData* persons, int idx_persons);
void	Change_User_Data			(UserData* persons, const char* FORMAT_PERSON_PRINTSCREEN);
//===================================================-Car_Data-========================================================================//
FILE*	fp_car_r						(FILE* fp_);
FILE*	fp_car_w						(FILE* fp_);
void	print_Cars_Data_on_screen_		(Vehicle_company* cars, FILE* fp_CARS_from_FILE, const char* FORMAT_CARS_TO, int arrayLength);
void	read_Car_Data_from_file			(Vehicle_company* cars, FILE* fp_CARS, const char* FORMAT_CARS_FROM, int arrayLength);
void	print_Cars_Data_on_screen_by_id_(Vehicle_company* cars, int arrayLength);
void	Fill_Car_Brand_Names			(Vehicle_company* cars, int idx_cars);
void	write_Cars_Data_to_file			(Vehicle_company* cars, FILE* fp_CARS_to_FILE, const char* FORMAT_CARS_TO, int arrayLength);
void	Fill_Car_Model					(Vehicle_company* cars, int idx_cars);
void	Fill_Car_Year					(Vehicle_company* cars, int idx_cars);
void	Fill_Car_DrivingLicence			(Vehicle_company* cars, int idx_cars);
void	Fill_Car_Description			(Vehicle_company* cars, int idx_cars);
void	Fill_Car_Counts_left			(Vehicle_company* cars, int idx_cars);
void	Fill_Car_ID						(Vehicle_company* cars, int idx_cars);
void	Fill_Car_Identificator			(Vehicle_company* cars, int idx_cars);
void	Fill_Car_Price_per_day			(Vehicle_company* cars, int idx_cars);
int		index_Cars_Data					(Vehicle_company* cars, int id, int arrayLength);
void	Change_Cars_Data				(Vehicle_company* cars, const char* FORMAT_CARS_PRINTSCREEN, int arrayLength);
void	(*fun_ptr_arr[10])				(Vehicle_company* cars, int idx_car);
void	add_new_vehicle					(Vehicle_company* cars, const char* FORMAT_CARS_PRINTSCREEN, int arrayLength);
int		unique_id_validator				(Vehicle_company* cars, int idx_cars);
int		id_cars_last_record_next_		(const Vehicle_company* cars, int list_size);
//===================================================-Admin_menu-======================================================================//
void	adminMenu						(Vehicle_company* cars, UserData* person, char* user_selection, FILE* fp_CARS_WRITE, FILE* fp_PERSONS_WRITE);
void	main_menu						(char* user_selection);



#endif // !HW_8_MODULE_1
