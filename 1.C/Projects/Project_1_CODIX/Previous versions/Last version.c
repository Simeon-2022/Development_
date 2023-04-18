#define _CRT_SECURE_NO_WARNINGS
#define DATE_ARR_LENGTH 9
#define TIME_ARR_LENGTH 7
#define W_FILE_NAME "\\IMPORT_INVOICES_????????_??????.txt"
#define ROW_LENGTH 53
#define ULLONG_MAX_LENGTH 20	
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <wchar.h>
#include <wctype.h>
#include <tchar.h>
#include <time.h>
#include <stdbool.h>

typedef enum FileNameAttributes
{
	LAST_ROW = 1,
	NULL_CHAR = 1,
	NEW_LINE = 1,
	IMPORT_INVOICES_ = 16,
	FILE_DATE_ = 8,
	FILE_TIME = 6,
	INV_NAME = 20,
	INV_NUM = 10,
	INV_DATE = 8,
	INV_CURRENCY = 3,
	INV_AMOUNT = 12
}FileNameAttributes;

typedef struct RowSections //Inv_file_data row info
{
	char name_Section[INV_NAME + NULL_CHAR + 10];
	char invoice_Num_Section[INV_NUM + NULL_CHAR + 10];
	char date_Section[INV_DATE + NULL_CHAR + 10];
	char currency_Section[INV_CURRENCY + NULL_CHAR + 10];
	char end_Amount_Section[INV_AMOUNT + NEW_LINE + NULL_CHAR + 10];

}Row_Sec;

typedef struct Inv_file_data
{
	char rowCount[ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR];
	Row_Sec** rows;
	int	vec_size;
	char invoiceSum[ULLONG_MAX_LENGTH + NULL_CHAR];
}Inv_file_data;

static const char* currencies[] = { "BGN", "USD", "EUR", "RSD", "TND" };


Inv_file_data* Invoice_Data_init(void) {

	Inv_file_data* inv_file_data = (Inv_file_data*)malloc(sizeof(Inv_file_data));
	if (inv_file_data == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	inv_file_data->rows = (Row_Sec**)malloc(sizeof(Row_Sec*)); //NULL
	if (inv_file_data->rows == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	inv_file_data->vec_size = 0;

	return inv_file_data;
};

void vector_memFree(Inv_file_data* Inv_file_data) {
	
	free(Inv_file_data->rows);
	Inv_file_data->rows = NULL;
	
	free(Inv_file_data);
	Inv_file_data = NULL;

}

int compare_ltr_(const void* a, const void* b) {

	//const char** ptr_1 = (const char**)a;
	//const char** ptr_2 = (const char**)b;

	//return strcmp(*ptr_1, *ptr_2); or:
	//return my_strcmp_to_Lower(*ptr_1, *ptr_2);

	for (const char* ptr_1 = (const char*)a, *ptr_2 = (const char*)b; *ptr_1 != '\0' || *ptr_2 != '\0';) //to avoid incrementing post deter zero
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
}

void sort_invoices_by_date(Row_Sec** arr_ptr, size_t arr_size, int (*compare_ltr_)(const void* a, const void* b)) {

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{

			if ((*compare_ltr_)(arr_ptr[j]->date_Section, arr_ptr[j + 1]->date_Section) > 0)
			{
				Row_Sec* temp = arr_ptr[j];
				arr_ptr[j] = arr_ptr[j + 1];//(*arr_ptr + (j + 1));
				arr_ptr [j + 1] = temp;
			}
		}
	}
}

char* find_number_idx_(const char* src, size_t length) {

	for (const char* srcPtr = src; srcPtr < src + length; srcPtr++)
	{
		if (isdigit(*srcPtr))
		{
			return (char*)srcPtr;
		}
	}
	return NULL;
}

long int find_readPtr_pos(FILE* fp_) {

	char currentChar = 0;
	int charCounter = 0;
	while (((currentChar = fgetc(fp_)) != '\n') && (currentChar != EOF))
	{
		charCounter++;
	}

	return ++charCounter;

}

double date_difference(struct tm time_entry_begin)
{
	time_t t = time(NULL);
	struct tm time_entry_current = *localtime(&t);
	time_entry_current.tm_sec = 0;
	time_entry_current.tm_min = 0;
	time_entry_current.tm_hour = 0;
	time_entry_current.tm_isdst = 0;
	time_entry_current.tm_yday = 0;
	time_entry_current.tm_wday = 0;

	//time_t time_to_seconds_Begin = mktime(&time_entry_begin);
	//time_t time_to_seconds_End = mktime(&time_entry_end);
	//printf("%ld\n", (long int)(time_to_seconds_End - time_to_seconds_Begin));
	//int secondsPerDay = 60 * 60 * 24;

	return (difftime(mktime(&time_entry_current), mktime(&time_entry_begin)));
}

int _date_stamp_validator(const char* idxPtr) {

	int year = 0, month = 0, day = 0;
	char file_date[DATE_ARR_LENGTH] = { '\0' };

	memcpy(file_date, idxPtr, DATE_ARR_LENGTH - 1);

	if (strlen(file_date) != 8)
	{
		return 0;
	}

	for (int i = 0; file_date[i] != '\0'; i++)
	{
		if (!isdigit(file_date[i]))
		{
			return 0;
		}
	}

	sscanf(file_date, "%4d%2d%2d", &year, &month, &day);

	if (year < 1900 || (month < 1 || month > 12) || (day < 1 || day > 31))
	{
		return 0;
	}

	if (day > 28 && month == 2)
	{
		if (year % 4 != 0)
		{
			return 0;
		}
		if (year % 100 == 0 && year % 400 != 0)
		{
			return 0;
		}

	}
	else if (day == 31 && (month != 1 || month != 3 || month != 5 || month != 7 || month != 8 || month != 10 || month != 12))
	{
		return 0;
	}

	struct tm file_time_entry = {// = *localtime(&(time_t) { time(NULL) });
	.tm_mday = day,
	.tm_mon = month - 1,
	.tm_year = year - 1900,
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 0,
	.tm_isdst = 0,
	.tm_yday = 0,
	.tm_wday = 0 };

	double ddd = date_difference(file_time_entry);

	if (date_difference(file_time_entry) < 0)
	{
		return 0;
	}

	return 1;
}

void get_time(char* current_date) {

	time_t t = time(NULL);
	struct tm time_entry = *localtime(&t);

	mktime(&time_entry);

	strftime(current_date, sizeof(char) * 20, "%Y%m%d_%H%M%S.txt", &time_entry);
};

int _time_stamp_validator(const char* idxPtr_to_fileName) {

	char file_name_time[TIME_ARR_LENGTH] = { '\0' };
	int hour = 0, min = 0, sec = 0;

	memcpy(file_name_time, idxPtr_to_fileName + DATE_ARR_LENGTH, TIME_ARR_LENGTH - 1);

	for (int i = 0; file_name_time[i] != '\0'; i++)
	{
		if (!isdigit(file_name_time[i]))
		{
			return 0;
		}
	}

	sscanf(file_name_time, "%2d%2d%2d", &hour, &min, &sec);

	if (hour > 23 || min > 59 || sec > 59)
	{
		return 0;
	}

	return 1;
}

int date_time_stamp_validator(const char* idxPtr_to_fileName) {

	if (!_date_stamp_validator(idxPtr_to_fileName) || !_time_stamp_validator(idxPtr_to_fileName))
	{
		return 0;
	}
	return 1;
}

int row_count_extractor_(char* current_row_ArrPtr) {

	bool errorFlag = false;
	int arrIdx = 0;
	//char c[2] = { '\0' };

	int doc_rows_integer = 0;


	for (int i = 0; current_row_ArrPtr[i] != '\0'; i++)
	{
		errorFlag = true;
		if (!isdigit(current_row_ArrPtr[i]))
		{
			return -1;
		}
	}

	if (!errorFlag)
	{
		return -1;
	}

	doc_rows_integer = atoi(current_row_ArrPtr);

	return doc_rows_integer;
}

int actual_row_counter_(FILE* fp_) { //!!!!

	char tempChar = 0;
	int new_ln_count = 0;
	rewind(fp_);

	while ((tempChar = fgetc(fp_)) != EOF) {

		if (tempChar == '\n')
		{
			new_ln_count++;
		}
	}

	fseek(fp_, (long)(-1), SEEK_CUR);

	if ((tempChar = fgetc(fp_)) != EOF)
	{
		new_ln_count++;
	}

	rewind(fp_);

	return new_ln_count;
}

int row_length_validator_(char* current_row_ArrPtr) {

	int rowCharCount = (int)strlen(current_row_ArrPtr);

	if (rowCharCount != ROW_LENGTH)
	{
		return rowCharCount;
	}

	// in case rowCharCount == 1 or 0
	return -1;
}

void replace_dateAndTimeStamp(char* dirPath) {

	char currentDate[20] = { '\0' };
	get_time(currentDate);

	int i = 0;
	for (; dirPath[i] != '\0'; i++);

	dirPath[i - strlen("????????_??????.txt")] = '\0';

	strcat(&dirPath[i - strlen("????????_??????.txt")], currentDate);
}

int fileNameValidator(char* file_data_file_Name_toChar, WIN32_FIND_DATA* file_data) {

	char* idxPtr_to_fileName = NULL;

	wcstombs(file_data_file_Name_toChar, file_data->cFileName, sizeof(W_FILE_NAME) - NULL_CHAR); // convert TCHAR[] filename to char[]

	idxPtr_to_fileName = find_number_idx_(file_data_file_Name_toChar, strlen(file_data_file_Name_toChar)); // Find index of the first number in string

	if (date_time_stamp_validator(idxPtr_to_fileName))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

FILE* fp_fileRead_(FILE* fp_, char* file_data_file_Name_toChar, char* current_dir_path, TCHAR* buffer, WIN32_FIND_DATA* file_data, char* mode) {

	wcstombs(current_dir_path, buffer, wcslen(buffer) - wcslen(file_data->cFileName)); // convert TCHAR directory to char

	int dirPathSize = (int)(wcslen(buffer) - wcslen(file_data->cFileName)); // get lenght of the dir path

	current_dir_path[dirPathSize] = '\0';

	strcat(current_dir_path, file_data_file_Name_toChar);

	fp_ = fopen(current_dir_path, mode);

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;
}

FILE* fp_fileWrite_Error_(FILE* fp_, char* current_dir_path, char* mode) {

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("_Error_Log.txt")));

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) + NULL_CHAR);

	directory_cpy[strlen(current_dir_path) - strlen(".txt")] = '\0';
	strcat(directory_cpy, "_Error_Log.txt");

	fp_ = fopen(directory_cpy, mode);

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	free(directory_cpy);
	return fp_;
}

FILE* fp_fileWrite_Validated_(FILE* fp_, char* current_dir_path, char* mode) {

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("_Validated\\")));

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) + NULL_CHAR); // copy current working path + new filename

	int current_dir_idx = (int)(strlen(current_dir_path) - strlen("IMPORT_INVOICES_????????_??????.txt"));
	char fileName[sizeof(W_FILE_NAME)];
	strcpy(fileName, directory_cpy + current_dir_idx); // get filename



	directory_cpy[current_dir_idx] = '\0';// 1 adjust for correct index number
	//strcat(directory_cpy, "_Validated\\"); // append new filename
	strcat(directory_cpy, "INVOICES_ORDERED_");	// append filename   INVOICES_ORDERED_

	strcat(directory_cpy, fileName + strlen("INVOICES_ORDERED_") - 1); // append new date

	fp_ = fopen(directory_cpy, mode);

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	free(directory_cpy);
	return fp_;
}

void remove_Temp_Error_Log_(char* current_dir_path) {

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("_Error_Log.txt")));

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) + NULL_CHAR);

	directory_cpy[strlen(current_dir_path) - strlen(".txt")] = '\0';
	strcat(directory_cpy, "_Error_Log.txt");

	remove(directory_cpy);
	free(directory_cpy);
}

int name_validator(char* current_row_ptr) {

	bool isSpace = false;
	bool isAlpha = false;

	for (int i = 0; i < INV_NAME; i++)
	{
		if (current_row_ptr[i] == ' ')
		{
			isSpace = true;
		}
		else if (isalpha(current_row_ptr[i]))
		{
			isAlpha = true;
		}
		else
		{
			return 0;
		}
	}

	if (isSpace && !isAlpha)
	{
		return 0;
	}
	return 1;
}

int row_amount_Validator(char* current_row_ptr) {

	int strLength = (int)strlen(current_row_ptr);
	bool digidFlag = false;
	bool spaceFlag = false;
	bool dotFlag = false;
	//	bool minusFlag = false;
	for (int i = 0; current_row_ptr[i] != '\0'; i++)
	{
		if (isdigit(current_row_ptr[i]))
		{

			digidFlag = true;
		}
		else if (isspace(current_row_ptr[i]))
		{
			if (digidFlag && spaceFlag && isdigit(current_row_ptr[i + 1]))
			{
				return -1;
				break;
			}
			spaceFlag = true;
		}
		else if (current_row_ptr[i] == '.')
		{
			if (dotFlag || !digidFlag || !isdigit(current_row_ptr[i - 1]) || !isdigit(current_row_ptr[i + 1]))
			{
				return -1;
				break;
			}
			dotFlag = true;
		}
		else if (current_row_ptr[i] == '-')
		{
			if (digidFlag || !isdigit(current_row_ptr[i + 1]))
			{
				return -1;
			}
			//minusFlag = true;
		}
		else
		{
			return -1;
		}
	}
	if (!digidFlag)
	{
		return -1;
	}
	if (dotFlag)
	{
		return 0;
	}

	return 1;
}

int header_Validator(FILE* fp_ERROR, char* current_row_ptr, int actual_rows_count, int rowCounter, bool* docErrorFlag) {

	int doc_rows_integer = row_count_extractor_(current_row_ptr);
	bool docRowsCheck = false;

	if (doc_rows_integer != actual_rows_count)
	{
		char str[ULLONG_MAX_LENGTH + NULL_CHAR];
		_itoa(doc_rows_integer, str, ULLONG_MAX_LENGTH + NULL_CHAR);
		fprintf(fp_ERROR, "Content validation: Target rows = '%s' Actual = \t\t'%d'\n", ((doc_rows_integer == -1) ? "invalid" : str), actual_rows_count);
		*docErrorFlag = true;
		docRowsCheck = true;
	}

	if (doc_rows_integer < 0)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Invalid row count integer: \t\t'%s'\n", rowCounter, current_row_ptr);
		*docErrorFlag = true;
		docRowsCheck = true;
	}

	if (docRowsCheck)
	{
		return 1;
	}

	return 0;
}

char* read_Invoice_Line(FILE* fp_FROM) {

	char tempChar = 0;
	int rowCharCount = 0;
	int rowlength = 54;
	char* temp_ptr = (char*)malloc(sizeof(char) * (size_t)(rowlength));

	while ((tempChar = fgetc(fp_FROM)) != '\n' && tempChar != EOF)
	{
		rowCharCount++;

		//current_row_ptr = (char*)realloc(current_row_ptr, (sizeof(char) * (rowCharCount + 1))); // allocate memory to store char value
		if (rowCharCount > rowlength)
		{
			temp_ptr = (char*)realloc(temp_ptr, (sizeof(char) * (size_t)(rowCharCount + 1))); // allocate memory to store char value
			if (temp_ptr == NULL)
			{
				printf("Error allocating memory. File validation process failure\n");
				free(temp_ptr);
				exit(1);
			}
			rowlength += rowlength;
		}

		//current_row_ptr = temp_ptr;

		temp_ptr[rowCharCount - 1] = tempChar;
	}

	temp_ptr[rowCharCount] = '\0';

	return temp_ptr;
}

int footer_Validator(FILE* fp_ERROR, char* current_row_ptr, bool* docErrorFlag, double d_RowAmount, int rowCounter) {

	int f_result = row_amount_Validator(current_row_ptr);

	if (f_result == -1)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Endline figure invalid: \t\t'%s'\n", rowCounter, current_row_ptr);
		return (*docErrorFlag = true);
	}
	else if (f_result == 0)
	{
		double d_lastRowFigure = atof(current_row_ptr);
		if (d_lastRowFigure != d_RowAmount)// + i_RowFigure)
		{
			fprintf(fp_ERROR, "Content validation: Line %d: Total sum incorrect: \t\t'%lf' </> '%lf'\n", rowCounter, d_lastRowFigure, d_RowAmount);
			return (*docErrorFlag = true);
		}
	}
	else
	{
		int i_lastRowFigure = atoi(current_row_ptr);
		if (i_lastRowFigure != (int)d_RowAmount)
		{
			fprintf(fp_ERROR, "Content validation: Line %d: Endline total sum incorrect: \t\t'%d' </> '%d'\n", rowCounter, i_lastRowFigure, (int)d_RowAmount);
			return (*docErrorFlag = true);
		}
	}

	return 0;
}

int is_doc_empty(FILE* fp_FROM, FILE* fp_ERROR, bool* docErrorFlag) {

	if (fgetc(fp_FROM) == EOF) // check for empty file
	{
		*docErrorFlag = true;

		fprintf(fp_ERROR, "Content validation: Input file contains no data\n");

		return 1;
	}
	rewind(fp_FROM);
	return 0;
}

int is_doc_content_sufficient(FILE* fp_FROM, FILE* fp_ERROR, bool* docErrorFlag) {
	int actual_rows_count = 0;
	if ((actual_rows_count = actual_row_counter_(fp_FROM)) < 3)
	{
		fprintf(fp_ERROR, "Content validation: Docrows too few, min '3' Actual '%d'\n", actual_rows_count);
		*docErrorFlag = true;
		return 0;
	}
	return actual_rows_count;
}

int currencyValidator(char* current_row_ptr) {

	char rowCurrency[sizeof(char) * INV_CURRENCY + NULL_CHAR] = { '\0' };

	strncpy_s(rowCurrency, sizeof(char) * INV_CURRENCY + NULL_CHAR, &current_row_ptr[INV_NAME + INV_NUM + INV_DATE], sizeof(char) * 3);

	int currencyIndex = -1;
	size_t num_elements = sizeof(currencies) / sizeof(currencies[0]);

	for (int i = 0; i < (int)num_elements; i++)
	{
		if (!strcmp(rowCurrency, currencies[i]))
		{
			currencyIndex = i;
			break;
		}
	}

	return currencyIndex;
}

int invoice_num_validator(char* current_row_ptr) {
	int i = 0;

	char rowInvoiceNum[sizeof(char) * INV_NUM + NULL_CHAR] = { '\0' };

	strncpy_s(rowInvoiceNum, sizeof(char) * INV_NUM + NULL_CHAR, &current_row_ptr[INV_NAME], sizeof(char) * INV_NUM);

	while (isspace(rowInvoiceNum[i++])) { // Ignore leading whitespaces
		if (i >= INV_NUM)
		{
			return 0;
		}
	}

	for (; i < INV_NUM; i++) {
		if (!isalnum(rowInvoiceNum[i])) {
			return 0;
		}
	}

	return 1;
}

int bodytext_Validator(FILE* fp_ERROR, char* current_row_ptr, int rowCounter, int* firstInvoiceIndex, double* d_RowAmount, bool* docErrorFlag)
{
	if (row_length_validator_(current_row_ptr) != -1)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: required char count = '%d' Actual = '%d'\n", rowCounter, ROW_LENGTH, (int)strlen(current_row_ptr));
		return (*docErrorFlag = true);
	}

	// ----------Validate Name section-----------

	if (!name_validator(current_row_ptr))
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Invalid name: \t\t\t'%.*s'\n", rowCounter, INV_NAME, current_row_ptr);
		*docErrorFlag = true;
		//	lineErrorFlag = true;
	}

	//----------Validate Inv_file_data number-----------

	if (!invoice_num_validator(current_row_ptr))
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Invalid Inv_file_data number: \t\t'%.*s'\n", rowCounter, INV_NUM, current_row_ptr + INV_NAME);
		*docErrorFlag = true;
	}

	// ----------Validate date section-----------
	if (!_date_stamp_validator(&current_row_ptr[INV_NAME + INV_NUM]))
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Date stamp invalid: \t\t'%.*s'\n", rowCounter, INV_DATE, current_row_ptr + (INV_NAME + INV_NUM));
		*docErrorFlag = true;
	}

	// ----------Validate currency section-----------

	if (rowCounter == 2)
	{
		*firstInvoiceIndex = currencyValidator(current_row_ptr);
	}

	int currentRowCurrencyIndex = currencyValidator(current_row_ptr);

	if (*firstInvoiceIndex == -1 || currentRowCurrencyIndex == -1)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Currency out of scope: \t\t'%.*s' \n", rowCounter, INV_CURRENCY, current_row_ptr + (INV_NAME + INV_NUM + INV_DATE));
		*docErrorFlag = true;
	}
	else if (*firstInvoiceIndex != currentRowCurrencyIndex)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Currency inconsistent with prime: \t'%.*s' \n", rowCounter, INV_CURRENCY, current_row_ptr + (INV_NAME + INV_NUM + INV_DATE));
		*docErrorFlag = true;
	}

	// ----------Validate number section-----------

	if (row_amount_Validator(&current_row_ptr[INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY]) == -1)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Inv_file_data figure invalid: \t\t'%s'\n", rowCounter, current_row_ptr + (INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY));
		*docErrorFlag = true;
	}
	else
	{
		*d_RowAmount += atof(&current_row_ptr[INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY]);
	}

	return *docErrorFlag;
}

void struct_Row_Sec_Pushback(Inv_file_data* inv_file_data, char* current_row_ptr) {

	inv_file_data->rows = (Row_Sec**)realloc(inv_file_data->rows, sizeof(Row_Sec*) * (size_t)(inv_file_data->vec_size + 1));
	if (inv_file_data->rows == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	strncpy_s(inv_file_data->rows[inv_file_data->vec_size]->name_Section, sizeof(inv_file_data->rows[inv_file_data->vec_size]->name_Section), current_row_ptr, INV_NAME);
	strncpy_s(inv_file_data->rows[inv_file_data->vec_size]->invoice_Num_Section, sizeof(inv_file_data->rows[inv_file_data->vec_size]->invoice_Num_Section), current_row_ptr + INV_NAME, INV_NUM);
	strncpy_s(inv_file_data->rows[inv_file_data->vec_size]->date_Section, sizeof(inv_file_data->rows[inv_file_data->vec_size]->date_Section), current_row_ptr + INV_NAME + INV_NUM, INV_DATE);
	strncpy_s(inv_file_data->rows[inv_file_data->vec_size]->currency_Section, sizeof(inv_file_data->rows[inv_file_data->vec_size]->currency_Section), current_row_ptr + INV_NAME + INV_NUM + INV_DATE, INV_CURRENCY);
	strncpy_s(inv_file_data->rows[inv_file_data->vec_size]->end_Amount_Section, sizeof(inv_file_data->rows[inv_file_data->vec_size]->end_Amount_Section), current_row_ptr + INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY, (size_t)INV_AMOUNT + NEW_LINE);

	inv_file_data->vec_size++;
}

void struct_Header_Pushback(Inv_file_data* Inv_file_data, char* current_row_ptr) {

	strncpy_s(Inv_file_data->rowCount, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR, current_row_ptr, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR);
}

void struct_Footer_Pushback(Inv_file_data* Inv_file_data, char* current_row_ptr) {

	strncpy_s(Inv_file_data->invoiceSum, ULLONG_MAX_LENGTH + NULL_CHAR, current_row_ptr, ULLONG_MAX_LENGTH);
}

void analyze_text_by_line(FILE* fp_FROM, FILE* fp_ERROR, Inv_file_data* Inv_file_data, char* current_row_ptr, int actual_rows_count, int rowCounter, int** firstInvoiceIndex, double** d_RowAmount, bool** docErrorFlag) {


	current_row_ptr = read_Invoice_Line(fp_FROM);

	if (rowCounter == 1)
	{
		if (!header_Validator(fp_ERROR, current_row_ptr, actual_rows_count, rowCounter, *docErrorFlag)) // &docErrorFlag)
		{
			struct_Header_Pushback(Inv_file_data, current_row_ptr);
		}
	}
	else if (rowCounter < actual_rows_count)
	{

		if (!bodytext_Validator(fp_ERROR, current_row_ptr, rowCounter, *firstInvoiceIndex, *d_RowAmount, *docErrorFlag)) //&firstInvoiceIndex, &d_RowAmount, &docErrorFlag)
		{
			struct_Row_Sec_Pushback(Inv_file_data, current_row_ptr);
		}
	}
	else
	{
		if (!footer_Validator(fp_ERROR, current_row_ptr, *docErrorFlag, **d_RowAmount, rowCounter)) // &docErrorFlag,
		{
			struct_Footer_Pushback(Inv_file_data, current_row_ptr);
		}
	}

}

void rename_source_file_KO_OK_(char* current_dir_path, char* file_data_file_Name_toChar, bool* docErrorFlag) {

	char* updated_dir_path = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + 1));
	if (updated_dir_path == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	strcpy(updated_dir_path, current_dir_path);

	updated_dir_path[strlen(updated_dir_path) - strlen(file_data_file_Name_toChar)] = '\0';

	file_data_file_Name_toChar[strlen(file_data_file_Name_toChar) - strlen("txt")] = '\0';

	if (!(*docErrorFlag))
	{
		strcat(file_data_file_Name_toChar, "OK");
	}
	else
	{
		strcat(file_data_file_Name_toChar, "KO");
	}

	strcat(updated_dir_path, file_data_file_Name_toChar);

	if (!rename(current_dir_path, updated_dir_path))
	{
		printf("File renamed to: %s\n", file_data_file_Name_toChar);
	}
	else
	{
		printf("Error renaming file\n");
	}
}

void write_Invoice_Content_To_File(Inv_file_data* Inv_file_data, char* current_dir_path) {

	FILE* fp_TO = NULL;

	fp_TO = fp_fileWrite_Validated_(fp_TO, current_dir_path, "w");

	fprintf(fp_TO, "%s\n", Inv_file_data->rowCount);
	for (int i = 0; i < Inv_file_data->vec_size; i++)
	{
		fprintf(fp_TO, "%s%s%s%s%s\n", Inv_file_data->rows[i]->name_Section, Inv_file_data->rows[i]->invoice_Num_Section, Inv_file_data->rows[i]->date_Section, Inv_file_data->rows[i]->currency_Section, Inv_file_data->rows[i]->end_Amount_Section);
	}
	fprintf(fp_TO, "%s", Inv_file_data->invoiceSum);

	fclose(fp_TO);
}

void file_finder(char* file_data_file_Name_toChar, WIN32_FIND_DATA* file_data, char* current_dir_path, TCHAR* buffer) {

	if (fileNameValidator(file_data_file_Name_toChar, file_data))
	{
		printf("\nValidating file: %ls\n", file_data->cFileName);// Print the name of inspected file

		FILE* fp_FROM = NULL;
		FILE* fp_ERROR = NULL;
		int rowCounter = 0;
		int actual_rows_count = 0;
		int firstInvoiceIndex = -1;
		int* firstInvoiceIndex_Ptr = &firstInvoiceIndex;
		int new_ln_count = 0;
		double d_RowAmount = 0;
		double* d_RowAmount_Ptr = &d_RowAmount;
		int i_RowFigure = 0;
		char* current_row_ptr = NULL;
		bool docErrorFlag = false;
		bool* docErrorFlag_Ptr = &docErrorFlag;

		fp_FROM = fp_fileRead_(fp_FROM, file_data_file_Name_toChar, current_dir_path, buffer, file_data, "r"); // open read file
		fp_ERROR = fp_fileWrite_Error_(fp_ERROR, current_dir_path, "w+");

		Inv_file_data* Inv_file_data = Invoice_Data_init();

		if (!is_doc_empty(fp_FROM, fp_ERROR, &docErrorFlag) && (actual_rows_count = is_doc_content_sufficient(fp_FROM, fp_ERROR, &docErrorFlag)))
		{
			for (int rowCounter = 1; rowCounter <= actual_rows_count; rowCounter++)
			{
				analyze_text_by_line(fp_FROM, fp_ERROR, Inv_file_data, current_row_ptr, actual_rows_count, rowCounter, &firstInvoiceIndex_Ptr, &d_RowAmount_Ptr, &docErrorFlag_Ptr);
			}
		}

		free(current_row_ptr);
		fclose(fp_FROM);
		fclose(fp_ERROR);

		if (!docErrorFlag)
		{
			remove_Temp_Error_Log_(current_dir_path);
			printf("File content validated.\n");
		}
		else
		{
			printf("File content incorrect.\n");
		}

		rename_source_file_KO_OK_(current_dir_path, file_data_file_Name_toChar, &docErrorFlag);

		if (!docErrorFlag)
		{
			sort_invoices_by_date(Inv_file_data->rows, Inv_file_data->vec_size, compare_ltr_);

			replace_dateAndTimeStamp(current_dir_path);

			write_Invoice_Content_To_File(Inv_file_data, current_dir_path);
		}
		vector_memFree(Inv_file_data);
	}
}

int main(void) //TODO::int main(int argc, TCHAR* argv[]) - substitute with arg[] in code where path is used
{
	// Declare variables
	WIN32_FIND_DATA file_data;
	HANDLE h_find;
	TCHAR buffer[MAX_PATH] = L"D:\\Documents\\GitHub\\C03-team-2-ivelina-mileva\\Project_1\\Project_1_CODIX\\_Input";
	char current_dir_path[MAX_PATH];
	char file_data_file_Name_toChar[sizeof(W_FILE_NAME) - NULL_CHAR];

	//printf("Enter file directory >> ");	 // -- !!! DO NOT delete!!!
	//_tscanf_s(_T("%s"), buffer, MAX_PATH); // -- !!! DO NOT delete!!!
	_tcscat_s(buffer, MAX_PATH, _T(W_FILE_NAME));

	//======================================================-FILE NAME VALIDATION Process-==============================================================================

	h_find = FindFirstFile(buffer, &file_data);
	if (h_find != INVALID_HANDLE_VALUE)
	{
		file_finder(file_data_file_Name_toChar, &file_data, current_dir_path, buffer);

		while (FindNextFile(h_find, &file_data)) // Search for additional files
		{
			file_finder(file_data_file_Name_toChar, &file_data, current_dir_path, buffer);
		}
	}
	else
	{
		puts("No files found");
		return 0;
	}

	FindClose(h_find); // Close the handle to the search results
	return 0;
}

/*
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


					//while ((tempChar = fgetc(fp_FROM)) != EOF)
					//{
					//	rowCharCount++;
					//	current_row_ptr = (char*)realloc(current_row_ptr, sizeof(char) * (rowCharCount)); // allocate memory to store char value
					//	if (current_row_ptr == NULL)
					//	{
					//		printf("Error allocating memory. File validation process failure\n");
					//		exit(1);
					//	}
					//	current_row_ptr[rowCharCount - 1] = tempChar;
						//if (fgetc(fp_FROM) == EOF) // check in case of single row with no '\n';
						//{
						//	if (tempChar != '\n')
						//	{
						//		docErrorFlag = true;
						//		current_row_ptr = (char*)realloc(current_row_ptr, sizeof(char) * (rowCharCount + 1));
						//		current_row_ptr[rowCharCount] = '\n';
						//		tempChar = '\n';
						//		rowCharCount++;
						//	}
						//}
						//else
						//{
						//	fseek(fp_FROM, -1L, SEEK_CUR);
						//}
					//	if (tempChar == '\n')
					//	{
							//bool lineErrorFlag = false;
							//rowCounter++;
							//current_row_ptr[rowCharCount - 1] = '\0';
							//rowCharCount = 0;



	*/

	//else
	//{
	//	puts("No file found");
	//	FindClose(h_find); // Close the handle to the search results
	//	return 0;
	//}