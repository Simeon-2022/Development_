//#pragma once
#ifndef FUNCTIONC_14_H
#define FUNCTIONS_14_H

//void	get_string_no_white_space		(char* begin);
size_t	my_strlen						(const char arrPtr[]);
void	print_reversed_const_string		(const char* str[]);
void	print_reversed_char_array		(const char* arr);
void	print_char_Array				(const char* begin);
void	get_string						(char* begin);
void	get_string_no_blanks_lowercase	(char* begin);
int		compare							(const char* arr, char* arr_2);
void	copy_array_in_reverse			(const char* arr, char* arr_2);
char	toLower							(char ch);
void	calmify_str						(char* begin);
int		lookup_char_value				(const char* begin, char ch);
int		h_lookup_string_index			(const char* arr_1, int arr_size_1,const char* arr_2, int arr_size_2);
int		h_lookup_string_occurrences		(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2);
int		find_At_char					(const char* arr, int* index);
int		is_alpha						(const char symbol);
int		is_numeric						(const char symbol);
int		is_printable					(const char arr);
char	is_special_character			(const char ptr);
int		is_period						(const char* arr_1, const char* ptr, int begin_index, int end_index, int* index_local);
int		is_hyphen						(const char* arr_1, const char* ptr, int ånd_index, int arr_size, int* index_local, int arr_size_2);
int		validation_email_local			(const char* arr, int begin_index, int end_index, int* index_local, int at_valuation);
int		validation_email_domein			(const char* arr, int end_index, int arr_size, const char* arr_2, int arr_size_2, int* index_local);
void	print_warning					(int part_, int index_local, int at_valuation);
void	print_array_index				(const char* arr_1, int arr_size);
void	get_string_EOF					(char* arr);
int		my_strcmp						(const char* arr_1, const char* arr_2);
int		my_strcmp_modified				(const char* arr_1, const char* arr_2, int rows, int cols);
int		is_capital						(const char letter);
void	first_letter_to_capital			(char arr_1[]);
void	fill_char_matrix_from_array		(char* matrix, int* current_row, int col, const int rows, const int cols, const char arr[]);
void	print_result					(const char* matrix, int rows, int cols, int arr[], int uncounted);
void	word_count_occurrences			(const char arr_1[], char arr_2[], char* matrix, const int row_size, const int col_size, int arr_occurrences[]);
void	shorten_string					(char * arr);
int		cmpr_rows_length				(const char* matrix, int rows, int cols);
char*	h_lookup_string_pointer			(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2);
int		longest_word_matrix_position	(const char arr_1[], char arr_2[], char* matrix, const int row_size, const int col_size, int arr_occurrences[], int arr_1_size);


#endif // !FUNCTIONC_14_H
