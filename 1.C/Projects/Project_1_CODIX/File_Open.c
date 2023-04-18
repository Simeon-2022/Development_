#define _CRT_SECURE_NO_WARNINGS
#define W_FILE_NAME "\\IMPORT_INVOICES_????????_??????.txt"
#include <stdio.h>
#include <Windows.h>
#include "Struct_Init.h"
#include "Date_Time.h"
#include "File_Open.h"


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

FILE* fp_fileWrite_Error_(FILE* fp_, char* file_data_file_Name_toChar, char* current_dir_path, char* mode) {

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("_Error_Log.txt") + strlen("KO\\")));

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	int nameLength = (int)strlen(file_data_file_Name_toChar);
	strncpy(directory_cpy, current_dir_path, strlen(current_dir_path) - nameLength + NULL_CHAR);

	directory_cpy[strlen(current_dir_path) - nameLength] = '\0';
	strcat(directory_cpy, "KO\\");
	strncat(directory_cpy, file_data_file_Name_toChar, nameLength - (int)strlen(".txt"));
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

	char* directory_cpy = (char*)malloc(sizeof(char) * (strlen(current_dir_path) + strlen("INVOICES_ORDERED\\") + strlen("D_"))); // 2 chars to compensate

	if (directory_cpy == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	size_t current_dir_idx = (strlen(current_dir_path) - strlen("IMPORT_INVOICES_????????_??????.txt"));
	strncpy(directory_cpy, current_dir_path, current_dir_idx); // copy current working path w/o filename

	//char fileName[sizeof(W_FILE_NAME)];
	//strcpy(fileName, directory_cpy + current_dir_idx); // get filename
	//strcat(directory_cpy, fileName + strlen("INVOICES_ORDERED_") - 1); // append new date

	directory_cpy[current_dir_idx] = '\0';

	strcat(directory_cpy, "INVOICES_ORDERED\\INVOICES_ORDERED_");	// append DIRECTORY and new filename
	
	replace_dateAndTimeStamp(&directory_cpy);


	fp_ = fopen(directory_cpy, mode);

	if (fp_ == NULL)
	{
		puts("Error reading file");
		exit(EXIT_FAILURE);
	}
	free(directory_cpy);
	return fp_;
}



void write_Invoice_Content_To_File(Invoice* invoice, char* current_dir_path) {

	FILE* fp_TO = NULL;

	fp_TO = fp_fileWrite_Validated_(fp_TO, current_dir_path, "w");

	fprintf(fp_TO, "%s\n", invoice->rowCount);
	for (int i = 0; i < invoice->vec_size; i++)
	{
		fprintf(fp_TO, "%s%s%s%s%s\n", invoice->rows[i].name_Section, invoice->rows[i].invoice_Num_Section, invoice->rows[i].date_Section, invoice->rows[i].currency_Section, invoice->rows[i].end_Amount_Section);
	}
	fprintf(fp_TO, "%s", invoice->invoiceSum);

	fclose(fp_TO);
}