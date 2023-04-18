#pragma once
#ifndef T_PROCESS_H
#define T_PROCESS_H

int		compare_ltr_				(const void* a, const void* b);
void	sort_invoices_by_date		(Row_Sec* arr_ptr, size_t arr_size, int (*compare_ltr_)(const void* a, const void* b));
void	remove_Temp_Error_Log_		(char* current_dir_path, char* file_data_file_Name_toChar);
void	analyze_text_by_line		(FILE* fp_FROM, FILE* fp_ERROR, Invoice* invoice, char* current_row_ptr, int actual_rows_count, int rowCounter, int** firstInvoiceIndex, double** d_RowAmount, bool** docErrorFlag);
void	rename_source_file_KO_OK_	(char* current_dir_path, char* file_data_file_Name_toChar, bool* docErrorFlag);
void	file_process_				(char* file_data_file_Name_toChar, WIN32_FIND_DATA* file_data, char* current_dir_path, TCHAR* buffer);

#endif // !T_PROCESS_H
