//#pragma once
#ifndef FUNCTIONS_15_H
#define FUNCTIONS_15_H


size_t	my_strlen									(const char arrPtr[]);
int		is_digit									(const char* arr);
int		is_alpha									(const char symbol);
int		is_capital									(const char letter);
int		is_Lower_alpha								(const char symbol);
int		is_numeric									(const char symbol);
int		is_punctuation								(const char symbol);
int		is_special_character						(const char symbol);
int		h_lookup_string_occurrences					(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2);
int		my_pow										(int base, int power);
int		h_lookup_string_index						(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2);
int		my_atoi										(const char* arr);
double	my_atof										(const char* arr);
double	conversion_type								(int check, const char* input); 
void	operation									(char operand, double d_result, double d_input_1, double d_input_2);
void	print_menu									(void);
void	print_reversed_char_array					(const char* arr);
void	print_string_no_blanks_						(char* begin);
void	print_matrix_char							(const char* matrix, int rows, int cols);
void	validate_input								(char* operand);
void	get_string_EOF								(char* arr);
char*	select_capital_lower_numeric				(char* matrix, const int cols, const char* arr_1);
void	fill_char_matrix_from_array_split_by_line	(char* matrix, int* current_row, const int rows, const int cols, const char* arr);
void	print_char_matrix_in_reverse_given_row_		(const char* matrix, int current_row, int col_size);
void	print_char_matrix_in_reverse_given_row_v2	(const char* matrix, int current_row, int col_size);

#endif // !FUNCTIONS_15_H
