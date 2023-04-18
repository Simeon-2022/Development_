#pragma once
#ifndef T_VALID_H
#define T_VALID_H

char*	find_number_idx_			(const char* src, size_t length);
int		row_count_extractor_		(char* current_row_ArrPtr);
int		actual_row_counter_			(FILE* fp_);
int		row_length_validator_		(char* current_row_ArrPtr);
int		is_doc_empty				(FILE* fp_FROM, FILE* fp_ERROR, bool* docErrorFlag);
int		is_doc_content_sufficient	(FILE* fp_FROM, FILE* fp_ERROR, bool* docErrorFlag);
char*	read_Invoice_Line			(FILE* fp_FROM);
int		header_Validator			(FILE* fp_ERROR, char* current_row_ptr, int actual_rows_count, int rowCounter, bool* docErrorFlag);
int		name_validator				(char* current_row_ptr);
int		invoice_num_validator		(char* current_row_ptr);
int		currency_Validator			(char* current_row_ptr);
int		_date_stamp_validator		(const char* idxPtr);
int		_time_stamp_validator		(const char* idxPtr_to_fileName);
int		date_time_stamp_validator	(const char* idxPtr_to_fileName);
int		row_amount_Validator		(char* current_row_ptr);
int		footer_Validator			(FILE* fp_ERROR, char* current_row_ptr, bool* docErrorFlag, double d_RowAmount, int rowCounter);
int		bodytext_Validator			(FILE* fp_ERROR, char* current_row_ptr, int rowCounter, int* firstInvoiceIndex, double* d_RowAmount, bool* docErrorFlag);
int		fileNameValidator			(char* file_data_file_Name_toChar, WIN32_FIND_DATA* file_data);



#endif // !T_VALID_H
