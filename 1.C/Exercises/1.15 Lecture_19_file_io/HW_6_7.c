#define _CRT_SECURE_NO_WARNINGS
#define LINE_LENGTH 50
#define USER_ARRAY_LENGTH 5
#define DRIVING_LICENCE_CATEGORIES 4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>


const char* licence_to_char[] = { "A","B","C","D","AA","AB","BC","DD"};

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

struct UserData
{
	char names[LINE_LENGTH];
	int PIN;
	E_DrivingLicenseCategory driving_licence;
};
typedef struct UserData UserData;

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

E_DrivingLicenseCategory driving_licence_category_from_char(char *ch) {


	for (int i = 0; i < driving_licence_count; i++)
	{
		if (!my_strcmp_v2(ch, licence_to_char[i]))
		{
			return i;
		}
	}
	return driving_licence_count;
}

void read_User_Data(UserData* persons, FILE* fp_FROM, const char* FORMAT_FROM) {

	char categorySymbol[3] = {'\0'};

	for (; fscanf(fp_FROM, FORMAT_FROM, persons->names, &persons->PIN, &categorySymbol) == 3; )
	{
		persons->driving_licence = driving_licence_category_from_char(categorySymbol);
		persons++;
	}
}

void print_User_Data(UserData* persons, FILE* fp_TO, const char* FORMAT_TO, int userArrayLength) {

	UserData* end_ptr_persons = persons + userArrayLength;

	for (; persons < end_ptr_persons; persons++)
	{
		fprintf(fp_TO, FORMAT_TO, persons->names, persons->PIN, licence_to_char[persons->driving_licence]);
	}
}

int main(void)
{
	FILE* fp_TO = NULL;
	FILE* fp_FROM = NULL;

	static const char* FORMAT_PERSON_FROM = "(%[^,], %d, %[^)])\n";
	static const char* FORMAT_PERSON_TO = "(Name: %s, PIN: %d, Licence category %s)\n";

	//E_DrivingLicenseCategory l[4];
	//l[0] = A;
	//l[1] = B;
	//l[2] = C;
	//l[3] = D;

	UserData person[USER_ARRAY_LENGTH]; 

	fp_FROM = fopen("HW_6_from.txt", "r");
	read_User_Data(person, fp_FROM, FORMAT_PERSON_FROM);

	fp_TO = fopen("HW_6_to.txt", "w");
	print_User_Data(person, fp_TO, FORMAT_PERSON_TO, USER_ARRAY_LENGTH);

	fclose(fp_TO);
	fclose(fp_FROM);

	return 0;
}


