//#pragma once
#ifndef FUNCTIONS_12_H
#define FUNCTIONS_12_H
#define _CRT_SECURE_NO_WARNINGS


int					abs								(int number);
void				arr_Manual_filler				(const int* begin, int array_size);
void				print_Array_Brackets			(const int* begin, int array_size);
double				arithmetic_Average				(const int* begin, int array_size);
unsigned long long	range_factoriel_recursion		(int min, int max);
unsigned long long	multiplication_Array_Range		(const int* begin, int array_size);
int					isFound							(const int* begin, int count, int dummyVar);
void				arr_range_filler_w_min_max		(const int* begin, int minValue, int maxValue, int array_size);
void				null_Negative_Values			(const int* begin, int array_size);
int					range_check_w_min_max			(int minValue, int maxValue, int array_element);
void				arr_manual_range_filler			(const int* begin, int array_size, int minValue, int maxValue);
void				arr_copy						(const int* begin_arr_1, const int* begin_arr_2, int array_size);
void				arr_rand_filler_preset_values	(const int* begin, int array_size);
void				array_exchange					(const int* begin_arr_1, const int* begin_arr_2, int array_size);
void				printstr						(const char* arr);
void				getstr							(char* arr);
void				copystr							(char* to, char* from);
void				change_variables				(int* a, int* b);
void				change_pointer_variables		(int** a, int** b);


#endif