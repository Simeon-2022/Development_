//#pragma once
#ifndef FUNCTIONS_16_H
#define FUNCTIONS_16_H

size_t	my_strlen(const char arrPtr[]);
void	get_string_EOF(char* arr);
void	get_string(char* arr);
char*	my_strchr(const char* arr_1, int letter);
char*	my_strrchr(const char* arr_1, int letter);
char	is_char_unique_in_str(const char* arr_1, int letter);
void	shorten_str(char* str, int length);
void	print_char_Array(const char* begin);
char*	strcpy(char* destination, const char* source);
void	print_char_Array_to_index(const char* begin, int index);
char*	my_strncpy(char* destination, const char* source, size_t num);
char*	my_strcat(char* destination, const char* source);
char*	my_strncat(char* destination, const char* source, size_t count);
int		my_strncmp(const char* arr_1, const char* arr_2, size_t count);
char*	my_strstr(const char* str, const char* substr);
void	print_matrix(const char* matrix, int rows, int cols);
int		find_str_pattern_by_row_char(const char* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1);
void	print_matrix_brackets(const char* matrix, int rows, int cols);
char*	extract_substr(const char* str, size_t idx_from, size_t idx_to, char result[]);
char	toLower(char ch);
int		my_strcmp_to_Lower(const char* arr_1, const char* arr_2);
int		is_lexicographical(const char* arr_1[], int size);
void	print_str_tokens(const char* str, const char* delimiters);
#endif // !FUNCTIONS_16_H
