//#pragma once
#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
//#define _CRT_SECURE_NO_WARNINGS


void	arr_filler						(int* begin, int array_size);
void	arr_Manual_filler				(int* begin, int array_size);
void	print_Array						(int* begin, int array_size);
void	compare							(int* begin, int number, int array_size);
int		isFound							(int* begin, int count, int dummyVar);
void	biggest_Number					(int* begin,int array_size);
void	smallest_Number					(int* begin, int array_size);
void	print_Array_In_Reverse			(int* begin, int array_size);
void	print_Array_To_Index			(int* begin, int index);
void	find_odd_even_numbers			(int* begin_arr_1, int* begin_arr_2, int* begin_arr_3, int* index_2_Count, int* index_3_Count, int array_size);
void	find_Unique_Numbers				(int* begin_arr_1, int* begin_arr_2, int* index,int array_size);
int		count_Unique_Numbers			(int* begin_arr_1, int array_size, int number);
void	print_Unique_Numbers			(int number, int timesFound);
void	shift_array_elements			(int* begin, int shift, int array_size);
void	arr_copy						(int* begin_arr_1, int* begin_arr_2, int array_size);
int		is_Duplicate					(int* begin, int array_size, int current);
#endif // !MY_FUNCTIONS_H
