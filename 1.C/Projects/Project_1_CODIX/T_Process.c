#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <windows.h>
#include "Struct_init.h"
#include "File_Open.h"
#include "Date_Time.h"
#include "T_Valid.h"
#include "T_Process.h"



int compare_ltr_(const void* a, const void* b) {

	//const char** ptr_1 = (const char**)a;
	//const char** ptr_2 = (const char**)b;
	//return strcmp(*ptr_1, *ptr_2); or:
	//return my_strcmp_to_Lower(*ptr_1, *ptr_2);

	for (const char* ptr_1 = (const char*)a, *ptr_2 = (const char*)b; *ptr_1 != '\0' || *ptr_2 != '\0';)
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

void sort_invoices_by_date(Row_Sec* arr_ptr, size_t arr_size, int (*compare_ltr_)(const void* a, const void* b)) {

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{
			if ((*compare_ltr_)(arr_ptr[j].date_Section, arr_ptr[j + 1].date_Section) > 0)
			{
				Row_Sec* temp = (Row_Sec*)malloc(sizeof(Row_Sec));
				if (temp == NULL)
				{
					printf("Error allocating memory. File validation process failure\n");
					exit(1);
				}

				memcpy(temp, arr_ptr + j, sizeof(Row_Sec));
				memcpy(arr_ptr + j, arr_ptr + (j + 1), sizeof(Row_Sec));
				memcpy(arr_ptr + (j + 1), temp, sizeof(Row_Sec));
				free(temp);
			}
		}
	}
}

void remove_Temp_Error_Log_(char* current_dir_path, char* file_data_file_Name_toChar) {

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("_Error_Log.txt") + strlen("KO\\")));

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	/*strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) + NULL_CHAR);

	directory_cpy[strlen(current_dir_path) - strlen(".txt")] = '\0';
	strcat(directory_cpy, "_Error_Log.txt");*/

	int nameLength = (int)strlen(file_data_file_Name_toChar);
	strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) - nameLength + NULL_CHAR);

	directory_cpy[strlen(current_dir_path) - nameLength] = '\0';
	strcat(directory_cpy, "KO\\");
	strncat(directory_cpy, file_data_file_Name_toChar, nameLength - (int)strlen(".txt"));
	strcat(directory_cpy, "_Error_Log.txt");

	remove(directory_cpy);
	free(directory_cpy);
}

void analyze_text_by_line(FILE* fp_FROM, FILE* fp_ERROR, Invoice* invoice, char* current_row_ptr, int actual_rows_count, int rowCounter, int** firstInvoiceIndex, double** d_RowAmount, bool** docErrorFlag) {
	
	current_row_ptr = read_Invoice_Line(fp_FROM); // initialize dynamic array 

	if (rowCounter == 1)
	{
		if (!header_Validator(fp_ERROR, current_row_ptr, actual_rows_count, rowCounter, *docErrorFlag)) 
		{
			struct_Header_Pushback(invoice, current_row_ptr);
		}
	}
	else if (rowCounter < actual_rows_count)
	{

		if (!bodytext_Validator(fp_ERROR, current_row_ptr, rowCounter, *firstInvoiceIndex, *d_RowAmount, *docErrorFlag)) 
		{
			struct_Row_Sec_Pushback(invoice, current_row_ptr);
		}
	}
	else
	{
		if (!footer_Validator(fp_ERROR, current_row_ptr, *docErrorFlag, **d_RowAmount, rowCounter)) 
		{
			struct_Footer_Pushback(invoice, current_row_ptr);
		}
	}
	
}

void rename_source_file_KO_OK_(char* current_dir_path, char* file_data_file_Name_toChar, bool* docErrorFlag) {

	char* updated_dir_path = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("OK\\") + NULL_CHAR));
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
		strcat(updated_dir_path, "OK\\");
		strcat(file_data_file_Name_toChar, "OK");
	}
	else
	{
		strcat(updated_dir_path, "KO\\");
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

void file_process_(char* file_data_file_Name_toChar, WIN32_FIND_DATA* file_data, char* current_dir_path, TCHAR* buffer) {

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
		fp_ERROR = fp_fileWrite_Error_(fp_ERROR, file_data_file_Name_toChar, current_dir_path, "w+");

		Invoice* invoice = Invoice_Data_init();

		if (!is_doc_empty(fp_FROM, fp_ERROR, &docErrorFlag) && (actual_rows_count = is_doc_content_sufficient(fp_FROM, fp_ERROR, &docErrorFlag)))
		{
			for (int rowCounter = 1; rowCounter <= actual_rows_count; rowCounter++)
			{
				analyze_text_by_line(fp_FROM, fp_ERROR, invoice, current_row_ptr, actual_rows_count, rowCounter, &firstInvoiceIndex_Ptr, &d_RowAmount_Ptr, &docErrorFlag_Ptr);
				Sleep(100);
			}
		}
		free(current_row_ptr);
		fclose(fp_FROM);
		fclose(fp_ERROR);

		if (!docErrorFlag)
		{
			remove_Temp_Error_Log_(current_dir_path, file_data_file_Name_toChar);
			printf("File content validated.\n");
		}
		else
		{
			printf("File content incorrect.\n");
		}

		rename_source_file_KO_OK_(current_dir_path, file_data_file_Name_toChar, &docErrorFlag);

		if (!docErrorFlag)
		{
			sort_invoices_by_date(invoice->rows, invoice->vec_size, compare_ltr_);

			//replace_dateAndTimeStamp(current_dir_path);

			write_Invoice_Content_To_File(invoice, current_dir_path);
		}
		vector_memFree(invoice);
	}
}



