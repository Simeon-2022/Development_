//#pragma once
#ifndef FUNCTIONS_13_H
#define FUNCTIONS_13_H

int	pattern_by_row_col			(const int* matrix_1, int matrix_rows, int matrix_cols, const int* sub_matrix, int sub_matrix_rows, int sub_matrix_cols);
int check_diagonals				(const float* matrix, int matrix_rows, int matrix_cols);
int check_non_diagonals			(const float* matrix, int matrix_rows, int matrix_cols);
int unique_columns				(const int* matrix, int rows, int cols);
void fill_matrix_rand			(float* matrix, int rows, int cols);
void fill_matrix_manual			(float* matrix, const int rows, const int cols);
void sum_matrix					(const float* matrix_1, const float* matrix_2, float* matrix_3, int rows, int cols);
void print_matrix				(const float* matrix, int rows, int cols);
void compare_elements			(const float* matrix_1, const float* matrix_2, const int rows, const int cols);
void matrix_multiplier			(const float* matrix_1, const float* matrix_2, float* matrix_3, const int rows, const int cols);
void print_matrix_no_decimal_int(const int* matrix, int rows, int cols);
void fill_matrix_rand_int		(int* matrix, int rows, int cols);
void print_matrix_w_characters	(const int* matrix, int currentRows, int totalRows, int cols, int sumRows);
void print_char_Array			(const char* begin, int array_size);
void swap_rows					(float* matrix, int cols, int* row_swap_1, int* row_swap_2);
void swap_cols					(float* matrix, int rows, int cols, int* col_swap_1, int* col_swap_2);
void matrix_multiplier_2		(float* matrix, int rows, int cols, float number);
void print_Array_Brackets		(const float* begin, const int array_size);
void array_matrix_multiplier	(float* matrix, int rows, int cols, float* array);
void sum_of_rows_and_columns	(const int* matrix, int rows, int cols);
void getCharArray				(char* arr, int rows, int cols);
int pattern_by_row				(const int* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1, int arr_size);
int pattern_by_column			(const int* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1, int arr_size);


#endif // !FUNCTIONS_13_H
