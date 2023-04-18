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
#include "Project_functions.h"

Invoice* Invoice_Data_init(void) {

	Invoice* invoice = (Invoice*)malloc(sizeof(Invoice));
	if (invoice == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	invoice->sentences = (SentComp*)malloc(sizeof(SentComp));
	if (invoice->sentences == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	invoice->vec_size = 0;

	return invoice;
};

void vector_memFree(Invoice* invoice) {

	free(invoice->sentences);
	free(invoice);
	invoice->sentences = NULL;
	invoice = NULL;
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

void my_bbsort(SentComp* arr_ptr, size_t arr_size, int (*compare_ltr_)(const void* a, const void* b)) {

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{

			if ((*compare_ltr_)(arr_ptr[j].date_Section, arr_ptr[j + 1].date_Section) > 0)
			{
				SentComp* temp = (SentComp*)malloc(sizeof(SentComp));
				if (temp == NULL)
				{
					printf("Error allocating memory. File validation process failure\n");
					exit(1);
				}

				memcpy(temp, arr_ptr + j, sizeof(SentComp));
				memcpy(arr_ptr + j, arr_ptr + (j + 1), sizeof(SentComp));
				memcpy(arr_ptr + (j + 1), temp, sizeof(SentComp));
				free(temp);
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

int find_readPtr_pos(FILE* fp_) {

	char currentChar = 0;
	int charCounter = 0;
	while (((currentChar = fgetc(fp_)) != '\n') && (currentChar != EOF))
	{
		charCounter++;
	}
	return charCounter;

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
		return -1;
	}

	for (int i = 0; file_date[i] != '\0'; i++)
	{
		if (!isdigit(file_date[i]))
		{
			return -1;
		}
	}

	sscanf(file_date, "%4d%2d%2d", &year, &month, &day);

	if (year < 1900 || (month < 1 || month > 12) || (day < 1 || day > 31))
	{
		return -1;
	}

	if (day > 28 && month == 2)
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
	else if (day == 31 && (month != 1 || month != 3 || month != 5 || month != 7 || month != 8 || month != 10 || month != 12))
	{
		return -1;
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
		return -1;
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
		return 0;
	}
	return 1;
}

int row_count_extractor_(FILE* fp_) {

	int arrIdx = 0;
	char* current_row_ArrPtr = (char*)malloc(sizeof(char)); // initialize array (char*) malloc(size * sizeof(char));
	if (current_row_ArrPtr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	char c[2] = { '\0' };

	int doc_rows = 0;

	while (((c[0] = fgetc(fp_)) != '\n') && (c[0] != EOF))
	{
		if (!isdigit(c[0]))
		{
			return -1;
		}
		current_row_ArrPtr[arrIdx++] = c[0];
		current_row_ArrPtr = (char*)realloc(current_row_ArrPtr, sizeof(char) * (arrIdx + 1));
		if (current_row_ArrPtr == NULL)
		{
			printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}
	}

	current_row_ArrPtr[arrIdx] = ('\0');
	doc_rows = atoi(current_row_ArrPtr);
	free(current_row_ArrPtr);

	return doc_rows;
}

int actual_row_counter_(FILE* fp_) {

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
	return new_ln_count;
}

int row_length_validator_(FILE* fp_) {

	char tempChar = 0;
	int rowCharcount = 0;

	while (tempChar != '\n' && tempChar != EOF) {

		tempChar = fgetc(fp_);
		rowCharcount++;

		if (tempChar == '\n')
		{
			if ((rowCharcount != (ROW_LENGTH + NEW_LINE)))
			{
				return rowCharcount; //-1?
			}
			rowCharcount = 0;
		}
	}
	return 0; // 0
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
		return -1;
	}
}

FILE* fp_fileRead_open(FILE* fp_, char* file_data_file_Name_toChar, char* current_dir_path, TCHAR* buffer, WIN32_FIND_DATA* file_data, char* mode) {

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

FILE* fp_fileWrite_open(FILE* fp_, char* current_dir_path,char* mode) {

	fp_ = fopen(current_dir_path, mode);

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	return fp_;

}

int main(void) //TODO::int main(int argc, TCHAR* argv[]) - substitute with arg[] in code where path is used
{
	// Declare variables
	WIN32_FIND_DATA file_data;
	HANDLE h_find;
	FILE* fp_FROM = NULL;
	FILE* fp_TO = NULL;
	TCHAR buffer[MAX_PATH] = L"D:\\Documents\\GitHub\\C03-team-2-ivelina-mileva\\Project_1\\Project_1_CODIX";
	//char* idxPtr_to_fileName = NULL;
	char current_dir_path[MAX_PATH];
	char file_data_file_Name_toChar[sizeof(W_FILE_NAME) - NULL_CHAR];


	//printf("Enter file directory >> "); -- !!! DO NOT delete!!!
	//_tscanf_s(_T("%s"), buffer, MAX_PATH); -- !!! DO NOT delete!!!
	_tcscat_s(buffer, MAX_PATH, _T(W_FILE_NAME));

	//======================================================-FILE NAME VALIDATION-==============================================================================

	h_find = FindFirstFile(buffer, &file_data);
	if (h_find != INVALID_HANDLE_VALUE) {


		if (fileNameValidator(file_data_file_Name_toChar, &file_data))
		{
			printf("\nValidating file: %ls\n", file_data.cFileName);// Print the name of file

			//======================================================-FILE CONTENT VALIDATION-==============================================================================

			fp_FROM = fp_fileRead_open(fp_FROM, file_data_file_Name_toChar, current_dir_path, buffer, &file_data, "r"); // open read file



		}








		while (FindNextFile(h_find, &file_data)) // Search for additional files
		{
			//wcstombs(file_data_file_Name_toChar, file_data.cFileName, sizeof(W_FILE_NAME) - 1); // convert TCHAR[] file name to char[]

			//idxPtr_to_fileName = find_number_idx_(file_data_file_Name_toChar, strlen(file_data_file_Name_toChar)); // Find index of the first number in string

			//if (!date_time_stamp_validator(idxPtr_to_fileName))
			//{
			//	printf("\n%ls\n", file_data.cFileName);// Print the name of each subsequent file
			//}
		}
	}
	else
	{
		puts("Validation process failed or no file found");

		FindClose(h_find); // Close the handle to the search results
		return -1;
	}


	//-------------------------------------------------------------Extract row count number:--------------------------------------------------------------------------
	bool errorFlag = false;
	fseek(fp_FROM, 0L, SEEK_SET);// go to the beginning of the file

	int doc_rows = row_count_extractor_(fp_FROM);

	if (doc_rows < 0)
	{
		// TODO::Print error to file -> 
		printf("Content validation: Invalid row count integer\n");
		errorFlag = true;

	}

	//-------------------------------------------------------------Count number of lines------------------------------------------------------------------------------

	int actual_row_count = actual_row_counter_(fp_FROM);
	if (actual_row_count != doc_rows)
	{
		// TODO::Print error to file -> 
		printf("Content validation: Target rows = %d Actual = %d\n", ((doc_rows == -1) ? 0 : doc_rows), actual_row_count);
		errorFlag = true;
		// -> move to next file
	}

	//-------------------------------------------------------------Inspect row lengh except first and last------------------------------------------------------------

	int fileReadPtrPosition = find_readPtr_pos(fp_FROM);
	fseek(fp_FROM, (long)(fileReadPtrPosition + NEW_LINE + 1), SEEK_SET); // go back to the beginning of second row in file; 1 = next row;

	for (int i = 2; i < actual_row_count; i++)
	{
		int result = row_length_validator_(fp_FROM); 
		if (result != 0)
		{
			// TODO::Print error to file -> 
			printf("Content validation: Text line %d: required row char count = %d Actual = %d \n", i, ROW_LENGTH, result - NEW_LINE);
			errorFlag = true;
			// -> move to next file
		}
	}
	//-------------------------------------------------------------Inspect row content except first and last------------------------------------------------------------
	// TODO:: wrap cycle in a function
	char tempChar = 0;
	int new_ln_count = 2;
	int rowCharcount = 0;

	char* current_row_ptr = (char*)malloc(sizeof(char)); // initialize array (char*) malloc(size * sizeof(char));
	if (current_row_ptr == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	fseek(fp_FROM, (long)(fileReadPtrPosition + NEW_LINE + 1), SEEK_SET); // go back to the beginning of second row in file

	while ((new_ln_count < actual_row_count) && ((tempChar = fgetc(fp_FROM)) != EOF)) {

		rowCharcount++;

		current_row_ptr = (char*)realloc(current_row_ptr, sizeof(char) * (rowCharcount + 1)); // allocate memory to store char value
		if (current_row_ptr == NULL)
		{
			printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}

		current_row_ptr[rowCharcount - 1] = tempChar;

		if (tempChar == '\n')
		{
			current_row_ptr[rowCharcount - 1] = '\0';

			// ----------Validate Name section-----------

			for (int i = 0; i < INV_NAME; i++)
			{
				if (((current_row_ptr[i] != ' ') && (!isalpha(current_row_ptr[i]))) || (current_row_ptr[INV_NAME - 1] == ' '))
				{
					printf("Content validation: Text line %d: Invalid name\n", new_ln_count);
					errorFlag = true;
					break;
				}
			}
			//TODO:: EMA: Validate invoice number

			// ----------Validate Name section-----------		

			if (_date_stamp_validator(&current_row_ptr[INV_NAME + INV_NUM]) == -1)
			{
				printf("Content validation: Text line %d: Date stamp invalid: %s\n", new_ln_count);
				errorFlag = true;
			}

			//TODO:: Rahim: Validate currency
			//TODO:: Diman: Validate end number
			//TODO:: Diman: Validate total figure

			new_ln_count++;
			rowCharcount = 0;
		}
	}

	free(current_row_ptr);
	rewind(fp_FROM);
	tempChar = 0;
	int rowCount = 0;
	char textLines[ROW_LENGTH + NEW_LINE + NULL_CHAR];

	// TODO:: wrap read cycle in a function
	if (errorFlag) {
		Invoice* invoice = Invoice_Data_init();

		while (fgets(textLines, ROW_LENGTH + NEW_LINE + NULL_CHAR, fp_FROM) != NULL)
		{
			rowCount++;

			if (rowCount <= 1)
			{
				strncpy_s(invoice->rowCount, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR, textLines, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR);
			}
			else if (rowCount <= doc_rows - LAST_ROW)
			{
				invoice->sentences = (SentComp*)realloc(invoice->sentences, sizeof(SentComp) * (invoice->vec_size + 1));
				if (invoice->sentences == NULL)
				{
					printf("Error allocating memory. File validation process failure\n");
					exit(1);
				}

				strncpy_s(invoice->sentences[invoice->vec_size].name_Section, sizeof(invoice->sentences[invoice->vec_size].name_Section), textLines, INV_NAME);
				strncpy_s(invoice->sentences[invoice->vec_size].invoice_Num_Section, sizeof(invoice->sentences[invoice->vec_size].invoice_Num_Section), textLines + INV_NAME, INV_NUM);
				strncpy_s(invoice->sentences[invoice->vec_size].date_Section, sizeof(invoice->sentences[invoice->vec_size].date_Section), textLines + INV_NAME + INV_NUM, INV_DATE);
				strncpy_s(invoice->sentences[invoice->vec_size].currency_Section, sizeof(invoice->sentences[invoice->vec_size].currency_Section), textLines + INV_NAME + INV_NUM + INV_DATE, INV_CURRENCY);
				strncpy_s(invoice->sentences[invoice->vec_size].end_Amount_Section, sizeof(invoice->sentences[invoice->vec_size].end_Amount_Section), textLines + INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY, INV_AMOUNT + NEW_LINE);

				invoice->vec_size++;
			}
			else
			{
				strncpy_s(invoice->invoiceSum, ULLONG_MAX_LENGTH + NULL_CHAR, textLines, ULLONG_MAX_LENGTH);
			}

			if (feof(fp_FROM)) {
				break;
			}
		}
		fclose(fp_FROM);

		//TODO::Use rename() to rename approved file - add function void rename_OK_(){};

		char* updated_dir_path = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + 1));
		if (updated_dir_path == NULL)
		{
			printf("Error allocating memory. File validation process failure\n");
			exit(1);
		}

		strcpy(updated_dir_path, current_dir_path);

		updated_dir_path[strlen(updated_dir_path) - strlen(file_data_file_Name_toChar)] = '\0';

		file_data_file_Name_toChar[strlen(file_data_file_Name_toChar) - strlen("txt")] = '\0';


		strcat(file_data_file_Name_toChar, "OK");

		strcat(updated_dir_path, file_data_file_Name_toChar);


		if (!rename(current_dir_path, updated_dir_path))
		{
			printf("File renamed to: %s\n", file_data_file_Name_toChar); // 3 symbols less than original file name (\,\,t)
		}
		else
		{
			printf("Error renaming file\n");
		}


		my_bbsort(invoice->sentences, invoice->vec_size, compare_ltr_);

		replace_dateAndTimeStamp(current_dir_path);


		fp_TO = fp_fileWrite_open(fp_TO, current_dir_path, "w");

		// TODO:: write cycle in a function
		fprintf(fp_TO, "%s", invoice->rowCount);
		for (int i = 0; i < invoice->vec_size; i++)
		{
			fprintf(fp_TO, "%s%s%s%s%s", invoice->sentences[i].name_Section, invoice->sentences[i].invoice_Num_Section, invoice->sentences[i].date_Section, invoice->sentences[i].currency_Section, invoice->sentences[i].end_Amount_Section);
		}
		fprintf(fp_TO, "%s", invoice->invoiceSum);

		vector_memFree(invoice);

	}


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
	}*/