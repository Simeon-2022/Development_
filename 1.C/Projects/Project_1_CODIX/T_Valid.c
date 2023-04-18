#define _CRT_SECURE_NO_WARNINGS
#define W_FILE_NAME "\\IMPORT_INVOICES_????????_??????.txt"
#define ROW_LENGTH 53
#define DATE_ARR_LENGTH 9
#define TIME_ARR_LENGTH 7
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include "Struct_Init.h"
#include "Date_Time.h"
#include "T_Valid.h"

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

char* read_Invoice_Line(FILE* fp_FROM) {

	char tempChar = 0;
	int rowCharCount = 0;
	int rowlength = ROW_LENGTH + NULL_CHAR;
	char* temp_ptr = (char*)malloc(sizeof(char) * (size_t)(rowlength));

	while ((tempChar = fgetc(fp_FROM)) != '\n' && tempChar != EOF)
	{
		rowCharCount++;

		//current_row_ptr = (char*)realloc(current_row_ptr, (sizeof(char) * (rowCharCount + 1)));
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

int header_Validator(FILE* fp_ERROR, char* current_row_ptr, int actual_rows_count, int rowCounter, bool* docErrorFlag) {

	int doc_rows_integer = row_count_extractor_(current_row_ptr); // if integer invalid returns '-1'
	bool docRowsCheck = false;

	if (doc_rows_integer < 0)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Invalid row count integer: \t\t'%s'\n", rowCounter, current_row_ptr);
		*docErrorFlag = true;
		docRowsCheck = true;
	}

	if (doc_rows_integer != actual_rows_count)
	{
		char str[ULLONG_MAX_LENGTH + NULL_CHAR];
		_itoa(doc_rows_integer, str, ULLONG_MAX_LENGTH + NULL_CHAR);
		fprintf(fp_ERROR, "Content validation: Target rows = '%s' Actual = \t\t'%d'\n", ((doc_rows_integer == -1) ? "invalid" : str), actual_rows_count);
		*docErrorFlag = true;
		docRowsCheck = true;
	}

	if (docRowsCheck)
	{
		return 1;
	}

	return 0;
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

int invoice_num_validator(char* current_row_ptr) {
	int i = 0;
	bool isSpace = false;
	char rowInvoiceNum[sizeof(char) * INV_NUM + NULL_CHAR] = { '\0' };

	strncpy_s(rowInvoiceNum, sizeof(char) * INV_NUM + NULL_CHAR, &current_row_ptr[INV_NAME], sizeof(char) * INV_NUM);

	while (isspace(rowInvoiceNum[i])) { // Ignore leading whitespaces
		if (i >= INV_NUM)
		{
			return 0;
		}
		i++;
	}

	for (; i < INV_NUM; ) {
		if (!isalnum(rowInvoiceNum[i]) && !isspace(rowInvoiceNum[i])) { // "FN1234   "
			return 0;
		}
		else if(isalnum(rowInvoiceNum[i]) && isSpace)
		{
			return 0;
		}
	
		if (isspace(rowInvoiceNum[i]))
		{
			isSpace = true;
		}
		i++;
	}

	return 1;
}

int currency_Validator(char* current_row_ptr) {

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

	if (day == 29 && month == 2)
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
	else if (day > 29 && month == 2)
	{
		return 0;
	}
	else if (day == 31 && (month != 1 || month != 3 || month != 5 || month != 7 || month != 8 || month != 10 || month != 12))
	{
		return 0;
	}

	struct tm file_time_entry = {
	.tm_mday = day,
	.tm_mon = month - 1,
	.tm_year = year - 1900,
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 0,
	.tm_isdst = 0,
	.tm_yday = 0,
	.tm_wday = 0 };

	double ddd = date_difference(file_time_entry); // check if future date

	if (date_difference(file_time_entry) < 0)
	{
		return 0;
	}

	return 1;
}

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

int footer_Validator(FILE* fp_ERROR, char* current_row_ptr, bool* docErrorFlag, double d_RowAmount, int rowCounter) {

	int f_result = row_amount_Validator(current_row_ptr);

	if (f_result == -1)
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Endline figure invalid: \t\t'%s'\n", rowCounter, current_row_ptr);
		return (*docErrorFlag = true);
	}
	else //if (f_result == 0)
	{
		double d_lastRowFigure = atof(current_row_ptr);
		double d_lastRowFigureRounded = round(d_lastRowFigure * 10000000000) / 10000000000;
		double d_RowAmountRounded = round(d_RowAmount * 10000000000) / 10000000000;

		if (d_lastRowFigureRounded - d_RowAmountRounded != 0.0000000000) // to use less eps!! < 0.0000000001
		{
			fprintf(fp_ERROR, "Content validation: Line %d: Total sum incorrect: \t\t'%lf' </> '%lf'\n", rowCounter, d_lastRowFigureRounded, d_RowAmountRounded);
			return (*docErrorFlag = true);
		}
	}

	return 0;
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

	//----------Validate invoice number-----------

	if (!invoice_num_validator(current_row_ptr))
	{
		fprintf(fp_ERROR, "Content validation: Line %d: Invalid invoice number: \t\t'%.*s'\n", rowCounter, INV_NUM, current_row_ptr + INV_NAME);
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
		*firstInvoiceIndex = currency_Validator(current_row_ptr);
	}

	int currentRowCurrencyIndex = currency_Validator(current_row_ptr);

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
		fprintf(fp_ERROR, "Content validation: Line %d: Invoice figure invalid: \t\t'%s'\n", rowCounter, current_row_ptr + (INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY));
		*docErrorFlag = true;
	}
	else
	{
		*d_RowAmount += atof(&current_row_ptr[INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY]);
	}

	return *docErrorFlag;
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


