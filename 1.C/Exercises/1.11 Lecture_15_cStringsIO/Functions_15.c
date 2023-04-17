#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_15.h"

void	get_string_EOF(char* arr) {
	char letter = ' ';
	int index = 0;
	while ((letter = getchar()) != EOF)
	{
		arr[index++] = letter;
	}
	arr[index] = '\0';
};

int		is_alpha(const char symbol) {

	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return 1;
	}
	return 0;
}

int		is_Lower_alpha(const char symbol) {

	if (symbol >= 'a' && symbol <= 'z')
	{
		return 1;
	}
	return 0;
}

int		is_capital(const char letter) {

	if (letter >= 'A' && letter <= 'Z')
	{
		return 1;
	}
	return 0;
}

int		is_punctuation(const char symbol) {

	char arr_special_char[20] = { '!', ';', '.', ':', '-', '\'', '"', ',',  '?', '_', '`', '\0' };

	for (int i = 0; i < 20; i++)
	{
		if (arr_special_char[i] == symbol)
		{
			return 1;
		}
	}
	return 0;
}

int		is_special_character(const char symbol) {

	char arr_special_char[22] = { '<' , '>' ,'@','[','\\', '*', '(', ')', '[', ']', '/','{', '|', '}', '$','#','%', '+', '-', '=','^', '\0' };

	for (int i = 0; i < 22; i++)
	{
		if (symbol == arr_special_char[i])
		{
			return 1;
		}
	}

	return 0;
}

int		is_numeric(const char symbol) {

	const char* ptr = &symbol;

	if ((*ptr >= '0' && *ptr <= '9'))
	{
		return 1;
	}
	return 0;
};

int		is_digit(const char* arr) {

	int dot_count = 0;
	int hyphen_count = 0;
	int size = (int)my_strlen(arr) - 1;
	int is_zero = 0;

	for (const char* ptr = arr; *ptr != '\0'; ptr++)
	{
		if (!is_numeric(*ptr))
		{
			if (*ptr == '.') // look up the index, must be other than 0
			{
				dot_count++;
			}
			else if (*ptr == '-')// look up the index, must be  0
			{
				hyphen_count++;
			}
			else
			{
				return 0; // Warning: Input is not a proper number.
			}
		}
		else
		{
			is_zero += (*ptr - '0');
		}
	}

	if (dot_count > 1 || hyphen_count > 1)
	{
		return 0; // Warning: Input is not a proper number.
	}
	else if (h_lookup_string_index(arr, (int)my_strlen(arr), ".", 1) == 0 || h_lookup_string_index(arr, (int)my_strlen(arr), "-", 1) > 0)
	{
		return 0; // Warning: Input is not a proper number.
	}
	else if (!is_zero)
	{
		return 3; // Warning: Division by zero.
	}
	else if (dot_count)
	{
		return 2; // Has decimal -> float
	}
	else
	{
		return 1; // No decimal -> int
	}
}

int		h_lookup_string_occurrences(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2) {

	int counter_char_occurrences = 0;
	int counter_phrase_occurrences = 0;

	const char* ptr_1_end = (arr_1 + arr_size_1);
	const char* ptr_2_end = (arr_2 + arr_size_2);

	for (int i = 0; i < (int)my_strlen(arr_1); i++)
	{
		const char* ptr_1 = (arr_1 + i);
		counter_char_occurrences = 0;

		for (const char* ptr_2 = (arr_2); ptr_2 < ptr_2_end; ptr_2++, ptr_1++)
		{
			if (ptr_1 >= ptr_1_end)
			{
				break;
			}
			else if (*ptr_1 == *ptr_2)
			{
				counter_char_occurrences++;
			}
		}

		if (counter_char_occurrences == (int)my_strlen(arr_2))
		{
			counter_phrase_occurrences++;
		}
	}
	return counter_phrase_occurrences;
};

size_t	my_strlen(const char arrPtr[]) {

	//char* ptr = arr;

	size_t lengthArray = 0;
	while (*arrPtr != '\0')
	{
		lengthArray++;

		arrPtr++;
	}

	return (int)lengthArray;
};

int		my_pow(int base, int power) {

	int sum = 1;

	if (power == 0)
	{
		sum = 1;
	}
	else
	{
		for (int i = 0; i < power; i++) // 10^3 = 10 * 10 * 10;
		{
			sum = sum * base;
		}
	}
	return sum;
}

int		h_lookup_string_index(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2) {

	int index = 0;
	int counter = 0;
	// aa in aaba should not return index

	for (const char* ptr_2 = arr_2, *ptr_1 = arr_1; *ptr_2 != '\0'; )
	{
		bool isFound = false;

		for (; *ptr_1 != '\0'; ptr_1++, index++)
		{
			if (*ptr_2 == *ptr_1)
			{
				isFound = true;
				index++;
				ptr_2++;
				ptr_1++;
				counter++;
				break;
			}
			else if (counter > 0)
			{
				ptr_2 = &arr_2[0];
				counter = 0;
				ptr_1--;
				index--;
			}
		}
		if (!isFound)
		{
			return -1;
		}
	}
	return index - arr_size_2;
};

int		my_atoi(const char* arr) {

	int compensator = 0;
	int count_digits = (int)my_strlen(arr);
	int sum = 0;

	if (arr[0] == '-')
	{
		compensator = 1;
	}

	for (const char* ptr = arr + compensator; *ptr != '\0'; ptr++)
	{
		sum += (*ptr - '0') * my_pow(10, (--count_digits - compensator));
	}

	if (compensator && (sum != 0))
	{
		return -sum;
	}
	else
	{
		return sum;
	}
}

double	my_atof(const char* arr) { // if left 'float' -> rounding occures;

	int compensator = 0;

	int index_floating_point = h_lookup_string_index(arr, (int)my_strlen(arr), ".", 1);

	if (index_floating_point < 0)
	{
		return 0;
	}

	int count_float_digits = (int)my_strlen(arr) - index_floating_point - 1;

	if (arr[0] == '-')
	{
		compensator = 1;
	}

	const char* ptr_end_begin = arr + index_floating_point;

	double sum_total = 0;
	int sum_int = 0;
	double sum_float = 0.0;

	for (const char* ptr = arr + compensator; ptr < ptr_end_begin; ptr++)
	{
		sum_int += (*ptr - '0') * my_pow(10, (--(index_floating_point)-compensator));
	}

	ptr_end_begin++;
	int power = count_float_digits;

	for (; *ptr_end_begin != '\0'; ptr_end_begin++)
	{
		sum_float += (*ptr_end_begin - '0') * my_pow(10, --power);
	}
	power = count_float_digits;

	sum_total = sum_int + (sum_float / my_pow(10, power));

	if (compensator && (sum_total != 0.0))
	{
		return -sum_total;
	}
	else
	{
		return sum_total;
	}
}

double	conversion_type(int check, const char* input) {

	double input_convertion = 0.0;

	if (check == 1)
	{
		input_convertion = my_atoi(input); // function convert to int
	}
	else if (check == 2)
	{
		input_convertion = my_atof(input); // function convert to double
	}

	return input_convertion;
}

void	operation(char operand, double d_result, double d_input_1, double d_input_2) {

	char c_sign = '\0';

	switch (operand)
	{
	case 'a':

		d_result = d_input_1 + d_input_2;
		c_sign = '+';
		//printf("%.2lf %c %.2lf = %.2lf \n", d_input_1, c_sign, d_input_2, d_result);
		break;
	case 's':
		d_result = d_input_1 - d_input_2;
		c_sign = '-';
		//printf(" %.2lf %c %.2lf = %.2lf \n", d_input_1, c_sign, d_input_2, d_result);
		break;
	case 'm':
		d_result = d_input_1 * d_input_2;
		c_sign = '*';
		//printf(" %.2lf %c %.2lf = %.2lf \n", d_input_1, c_sign, d_input_2, d_result);
		break;
	case 'd':
		d_result = d_input_1 / d_input_2;
		c_sign = '/';
		//printf(" %.2lf %c %.2lf = %.2lf \n", d_input_1, c_sign, d_input_2, d_result);
		break;

	default:
			break;
	}

	printf("%.2lf %c %.2lf = %.2lf \n", d_input_1, c_sign, d_input_2, d_result);

}

void	print_menu(void) {

	putchar('\n');
	printf(
		"Enter the operation of your choice:\n"
		"-----------------------------------"
		"\n a. add           s. subtract"
		"\n m. multiply      d. divide"
		"\n q. quit"
		"\n-----------------------------------"
	);
	putchar('\n');
}

void	print_matrix_char(const char* matrix, int rows, int cols) {

	printf("===================================\n");

	for (int i = 0; i < matrix[i * cols] != '\0'; i++, putchar('\n'))
	{
		for (int y = 0; matrix[i * cols + y] != '\0'; y++)
		{
			printf("%c", matrix[i * cols + y]);
		}
	}
}

void	print_string_no_blanks_(char* begin) {

	int count_blanks = 0;

	for (const char* arr_Ptr = begin; *arr_Ptr != '\0'; arr_Ptr++)
	{
		if (*arr_Ptr == ' ')
		{
			count_blanks++;
		}
		else
		{
			count_blanks = 0;
		}

		if (count_blanks > 1) //   a   s
		{
			continue;
		}
		else
		{
			putchar(*arr_Ptr);
		}
	}
};

void	print_reversed_char_array(const char* arr) {

	int lastIndex = (int)my_strlen(arr);

	for (const char* end = &arr[lastIndex - 1]; end >= &arr[0]; end--)
	{
		printf("%c", *end);

	}
	putchar('\n');
};

void	validate_input(char* operand) {

	while (*operand == 'q' || (*operand != 'a' && *operand != 's' && *operand != 'm' && *operand != 'd'))
	{

		if (*operand != 'q')
		{
			printf("\n Not a valid operation!\n");
			print_menu();
		}
		else if (*operand == 'q')
		{
			printf(" Bye.\n");
			break;
		}
		putchar(' ');
		scanf(" %c", operand);
		//getchar();
	}
}

char*	select_capital_lower_numeric(char* matrix, const int cols, const char* arr_1) {

	int current_col_0 = 0;
	int current_col_1 = 0;
	int current_col_2 = 0;

	for (const char* arr_Ptr = arr_1; *arr_Ptr != '\0'; arr_Ptr++)
	{
		if (is_capital(*arr_Ptr))
		{
			matrix[current_col_0++] = *arr_Ptr;
		}
		else if (is_Lower_alpha(*arr_Ptr))
		{
			matrix[1 * cols + current_col_1++] = *arr_Ptr;
		}
		else if (is_numeric(*arr_Ptr))
		{
			matrix[2 * cols + current_col_2++] = *arr_Ptr;
		}
	}
	return matrix;
}

void	fill_char_matrix_from_array_split_by_line(char* matrix, int* current_row, const int rows, const int cols, const char* arr) {

	int arr_size = (int)my_strlen(arr);
	int col = 0;

	for (int i = 0; i < arr_size; i++)
	{
		if (*current_row == rows - 1)
		{
			break;
		}
		if (*(arr + i) == '\n')
		{
			(*current_row)++;
			col = 0;
		}
		else
		{
			matrix[(*current_row) * cols + col] = arr[i];
			col++;
		}
	}
	//(*current_row)--;
}

void	print_char_matrix_in_reverse_given_row_(const char* matrix, int current_row, int col_size) {

	for (int i = current_row; i >= 0; i--)
	{
		for (const char* end = &matrix[i * col_size]; *end != '\0'; end++)
		{

			printf("%c", *end);

		}

		putchar('\n');
	}
};

void	print_char_matrix_in_reverse_given_row_v2(const char* matrix, int current_row, int col_size) {

	for (int i = 0; i < current_row; i++)
	{
		const char* ptrBegin = matrix + i * col_size;

		int size_current_row = (int)my_strlen(ptrBegin) - 1;
		
		
		for (const char* end = ptrBegin + size_current_row; end >= ptrBegin; end--)
		{
			putchar(* end);
		}
		putchar('\n');
	}
}