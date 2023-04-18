#pragma once
#ifndef FILE_OPEN_H
#define FILE_OPEN_H

FILE* fp_fileRead_					(FILE* fp_, char* file_data_file_Name_toChar, char* current_dir_path, TCHAR* buffer, WIN32_FIND_DATA* file_data, char* mode);
FILE* fp_fileWrite_Error_			(FILE* fp_, char* file_data_file_Name_toChar, char* current_dir_path, char* mode);
FILE* fp_fileWrite_Validated_		(FILE* fp_, char* current_dir_path, char* mode);
void write_Invoice_Content_To_File	(Invoice* invoice, char* current_dir_path);
#endif // !FILE_OPEN_H
