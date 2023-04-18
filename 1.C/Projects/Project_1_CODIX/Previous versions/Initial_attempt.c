#define _CRT_SECURE_NO_WARNINGS
#define DATE_ARR_LENGTH 9
#define TIME_ARR_LENGTH 7
#define W_FILE_NAME "\\IMPORT_INVOICES_????????_??????.txt"
#define ROW_LENGTH 53
//#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <wchar.h>
#include <wctype.h>
#include <tchar.h>
#include <time.h>
#include "Project_functions.h"
#include <stdbool.h>

char* find_idx_ptr(const char* src, size_t length) {

	for (const char* srcPtr = src; srcPtr < src + length; srcPtr++)
	{
		if (isdigit(*srcPtr))
		{
			return (char*)srcPtr;
		}
	}
	return NULL;
}

int _date_stamp_validator(const char* idxPtr_to_fileName) {

	int year = 0, month = 0, day = 0;
	char file_name_date[DATE_ARR_LENGTH] = { '\0' };

	memcpy(file_name_date, idxPtr_to_fileName, DATE_ARR_LENGTH - 1);

	for (int i = 0; file_name_date[i] != '\0'; i++)
	{
		if (!isdigit(file_name_date[i]))
		{
			return -1;
		}
	}

	sscanf(file_name_date, "%4d%2d%2d", &year, &month, &day);

	if (month == 2 && day == 29)
	{
		if (year % 4 != 0)
		{
			return -1;
		}
		if (year % 100 == 0 && year % 400 != 0)
		{
			return -1;
		}

	}

	struct tm name_date = { 0 };
	name_date.tm_year = year - 1900;
	name_date.tm_mon = month - 1;
	name_date.tm_mday = day;

	return (int)mktime(&name_date);
}

int _time_stamp_validator(const char* idxPtr_to_fileName) {

	char file_name_time[TIME_ARR_LENGTH] = { '\0' };
	int hour = 0, min = 0, sec = 0;

	memcpy(file_name_time, idxPtr_to_fileName + DATE_ARR_LENGTH, TIME_ARR_LENGTH - 1);

	for (int i = 0; file_name_time[i] != '\0'; i++)
	{
		if (!isdigit(file_name_time[i]))
		{
			return -1;
		}
	}

	sscanf(file_name_time, "%2d%2d%2d", &hour, &min, &sec);

	if (hour > 23 || min > 59 || sec > 59) { return -1; }

	return 1;
}

int date_time_stamp_validator(const char* idxPtr_to_fileName) {

	if ((_date_stamp_validator(idxPtr_to_fileName) == -1) || (_time_stamp_validator(idxPtr_to_fileName) == -1))
	{
		return -1;
	}
	return 1;
}

FILE* fp_file_open(FILE* fp_, char* directory_path) {

	fp_ = fopen(directory_path, "r");

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

int main() //int main(int argc, TCHAR* argv[])
{
	// Declare variables
	WIN32_FIND_DATA file_data;
	HANDLE h_find;
	FILE* fp_FROM = NULL;
	TCHAR buffer[MAX_PATH] = L"D:\\Documents\\GitHub\\C03-team-2-ivelina-mileva\\Project_1\\Project_1_CODIX";
	char* idxPtr_to_fileName = NULL;
	char directory_path[MAX_PATH];
	char file_data_file_Name_toChar[sizeof(W_FILE_NAME) - 1];

	// Get current working directory
	char cwd[1024];
	if (_getcwd(cwd, sizeof(cwd)) != NULL)
	{
		fprintf(stdout, "Current working directory >> %s\n", cwd);
	}
	else
	{
		perror("getcwd() error");
		return 1;
	}

	//printf("Enter file directory >> "); -- DO NOT delete!!!
	//_tscanf_s(_T("%s"), buffer, MAX_PATH); -- DO NOT delete!!!
	_tcscat_s(buffer, MAX_PATH, _T(W_FILE_NAME));

	//======================================================-FILE NAME VALIDATION-==============================================================================

	h_find = FindFirstFile(buffer, &file_data);
	if (h_find != INVALID_HANDLE_VALUE) {

		wcstombs(file_data_file_Name_toChar, file_data.cFileName, sizeof(W_FILE_NAME) - 1); // convert TCHAR[] to char[]

		idxPtr_to_fileName = find_idx_ptr(file_data_file_Name_toChar, strlen(file_data_file_Name_toChar)); // Find index of the first number in string

		if (date_time_stamp_validator(idxPtr_to_fileName) == -1)
		{
			puts("Date and time stamp validation failure!");
			return -1;
		}

		printf("%ls\n", file_data.cFileName); // Print the name of the first file

		while (FindNextFile(h_find, &file_data)) // Search for additional files
		{
			if (date_time_stamp_validator(idxPtr_to_fileName) == -1)
			{
				puts("Date and time stamp validation failure!");
			}
			else
			{
				printf("%ls\n", file_data.cFileName);// Print the name of each subsequent file
			}
		}
	}
	else
	{
		puts("Name validation failed or no file found");
		return -1;
	}

	FindClose(h_find); // Close the handle to the search results

	//======================================================-FILE CONTENT VALIDATION-==============================================================================

	wcstombs(directory_path, buffer, wcslen(buffer) - wcslen(file_data.cFileName)); // convert TCHAR to char

	int dirPathSize = (int)(wcslen(buffer) - wcslen(file_data.cFileName)); // get lenght of the dir path

	directory_path[dirPathSize] = '\0';

	strcat(directory_path, file_data_file_Name_toChar);

	fp_FROM = fp_file_open(fp_FROM, directory_path);

	//1.-----------------------------------------------------Check for correct row count number:--------------------------------------------------------------------------

	char* current_row_ptr = (char*)malloc(sizeof(char)); // initialize array (char*) malloc(size * sizeof(char));
	if (current_row_ptr == NULL)
	{
		//printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	char c[2] = { '\0' };
	int curr_ptr_idx = 0;
	int doc_rows = 0;
	bool isValid = true;

	while ((c[0] = fgetc(fp_FROM)) != '\n')
	{
		if (!isdigit(c[0]))
		{
			//puts("Content validation: Wrong row count number"); // TODO::The program must move to the next file!!
			isValid = false;
			break;
		}
		current_row_ptr[curr_ptr_idx++] = c[0];
		current_row_ptr = (char*)realloc(current_row_ptr, sizeof(char) * (curr_ptr_idx + 1));
		if (current_row_ptr == NULL)
		{
			//printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}
	}
	if (isValid)
	{
		current_row_ptr[curr_ptr_idx] = ('\0');
		doc_rows = atoi(current_row_ptr);
		free(current_row_ptr);
		//printf("doc_rows: %d\n", doc_rows);
	}
	int row_count_extractor_(char* dynamicArrPtr, ) {}
	//char words[ROW_LENGTH + NEW_LINE + NULL_CHAR];

	//-------------------------------------------------------------Count number of lines---------------------------------------------------------------------------------

	char temp = 0;
	int new_ln_count = 0;
	rewind(fp_FROM);
	while ((temp = fgetc(fp_FROM)) != EOF) {

		if (temp == '\n')
		{
			new_ln_count++;
		}
	}

	if (new_ln_count != doc_rows)
	{
		printf("Content validation: Target rows (%d). Actual %d\n", doc_rows, new_ln_count);
		//TODO:: row validation function 


	}
	else if (new_ln_count < doc_rows)
	{
		printf("Content validation: Target rows (%d). Actual %d\n", doc_rows, new_ln_count);
		//TODO:: row validation function 


	}


	//-------------------------------------------------------------Check number of lines - 1 (total sum) and row lengh--------------------------------------------------------------------

	temp = 0;
	new_ln_count = 1;
	int rowCharcount = 0;

	fseek(fp_FROM, (long)(curr_ptr_idx + 2), SEEK_SET); // go back to the beginning of second row in file
	current_row_ptr = (char*)malloc(sizeof(char)); // initialize array (char*) malloc(size * sizeof(char));
	if (current_row_ptr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	while ((temp = fgetc(fp_FROM)) != EOF) {
		rowCharcount++;

		current_row_ptr = (char*)realloc(current_row_ptr, sizeof(char) * (rowCharcount + 1)); // allocate memory to store char value

		if (current_row_ptr == NULL)
		{
			printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}

		current_row_ptr[rowCharcount - 1] = temp;

		if (temp == '\n')
		{
			current_row_ptr[rowCharcount] = '\0';

			new_ln_count++;

			if (rowCharcount > ROW_LENGTH + NEW_LINE)
			{
				printf("Content validation: Row length (%d) mismatch on line %d\n", ROW_LENGTH, new_ln_count);
			}
			rowCharcount = 0;
			//printf("%s", current_row_ptr);

			// ----------Extract Name section-----------

			for (int i = 0; i < INV_NAME; i++)
			{
				if ((current_row_ptr[i] != ' ') && (!isalpha(current_row_ptr[i])))
				{
					printf("Content validation: Invalid name on line %d\n", new_ln_count);
				}
			}
		}
	}



	//rewind(fp_FROM);


	//todo STRUCT


	return 0;
}

/*The lpFileName parameter of the FindFirstFile() function is indeed a pointer to a null-terminated string that specifies the file name or pattern to search for. However, you can also use it to specify the path to a directory, by using a pattern like "C:\\my_directory\\*", as I mentioned in my previous response.

In this case, the * character is a wildcard that matches any file name. Therefore, the FindFirstFile() function will search for all files in the "C:\my_directory" directory.

You can use other wildcard characters in the file name or pattern, such as ? (which matches any single character) or [...] (which matches any character within the specified range). For example, you could use a pattern like "C:\\my_directory\\file[0-9]*.txt" to search for files in the "C:\my_directory" directory that have a name that starts with "file", followed by a digit ([0-9]), and ends with ".txt".*/
//Test address strings:
//TCHAR buffer[MAX_PATH] = L"C:\\Users\\Simeon\\source\\repos\\ConsoleApplication1\\x64\\Debug\\IMPORT_INVOICES_????????_??????.txt";
//TCHAR buffer[MAX_PATH] = L"D:\\Documents\\GitHub\\C03-team-2-ivelina-mileva\\Project_1\\Project_1_CODIX\\IMPORT_INVOICES_20230401_152022.txt";
//TCHAR buffer[MAX_PATH] = L"IMPORT_INVOICES_20230401_152022.txt";  
//TCHAR buffer[MAX_PATH] = L"IMPORT_INVOICES_[0-9]{8}_[0-9]{6}.txt"; 
// _fullpath(buffer, cwd, _MAX_PATH);
//TCHAR buffer[MAX_PATH] = L"IMPORT_INVOICES_????????_??????.txt"; 
/*
The use of TCHAR and wide characters (_T()) instead of char in the code you provided is because it allows the code to be more platform-independent.

TCHAR is a macro that maps to either char or wchar_t depending on whether the code is being compiled with the _UNICODE preprocessor define. This means that when the code is compiled for a system that uses multi-byte characters, TCHAR maps to char, and when the code is compiled for a system that uses wide characters, TCHAR maps to wchar_t.

Using TCHAR allows the code to be built for either multi-byte or wide characters, which enables the code to run on different platforms and support different languages without modification.

This is important because in windows the default characters encoding is Unicode and many of the windows API functions use wide characters (wchar_t*), and in order for this code to work on other platforms it is best to use TCHAR instead of wchar_t* or char*.
The functions _tprintf, _tcscpy_s, _tcscat_s are used to handle string in a more generic way and support both MBCS and Unicode.
_T("") macro is used to automatically switch between narrow and wide string literals based on the value of _UNICODE.

In summary this code uses TCHAR and wide characters (_T()) to be platform independent and handle different languages and character encoding.
*/