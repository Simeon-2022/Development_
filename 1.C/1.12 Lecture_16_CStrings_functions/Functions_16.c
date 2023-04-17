#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_16.h"


void	get_string_EOF(char* arr) {
	char letter = ' ';
	int index = 0;
	while ((letter = getchar()) != EOF)
	{
		arr[index++] = letter;
	}
	arr[index] = '\0';
};

void	get_string(char* arr) {

	char temp = ' ';
	int index = 0;
	while ((temp = getchar()) != '\n')
	{
		arr[index++] = temp;
	}
	arr[index] = '\0';
};

char* my_strchr(const char* arr_1, int letter) {

	char symbol = letter;

	for (const char* ptr_1 = arr_1; *ptr_1 != '\0'; ptr_1++)
	{
		if (*ptr_1 == symbol)
		{
			return (char*)ptr_1;
		}
	}
	return NULL;
}

char* my_strrchr(const char* arr_1, int letter) {

	char symbol = letter;
	const char* temp_ptr = NULL;

	for (const char* ptr_1 = arr_1; *ptr_1 != '\0'; ptr_1++)
	{
		if (*ptr_1 == symbol)
		{
			temp_ptr = ptr_1;
		}
	}
	if (!temp_ptr)
	{
		return NULL;
	}
	return (char*)temp_ptr;
}

char	is_char_unique_in_str(const char* arr_1, int letter) {

	char symbol = letter;
	int counter = 0;

	const char* ptr_begin = my_strchr(arr_1, letter);
	const char* ptr_end = my_strrchr(arr_1, letter);
	if (ptr_end == NULL)
	{
		return 0;
	}
	else if (ptr_end - ptr_begin == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void	shorten_str(char* str, int length) {

	//char* ptr = str;
	*(str + length) = '\0';
}

void	print_char_Array(const char* begin) {

	for (const char* arr_Ptr = begin; *arr_Ptr != '\0'; arr_Ptr++)
	{
		printf("%c", *arr_Ptr);
	}
	putchar('\n');
}

void	print_char_Array_to_index(const char* begin, int index) {
	int i = 0;
	for (const char* arr_Ptr = begin; i < index; i++, arr_Ptr++)
	{
		printf("%c", *arr_Ptr);
	}
	putchar('\n');
}

char* strcpy(char* destination, const char* source) {

	char* ptr_destination = destination;
	for (const char* ptr_source = source; *ptr_source != '\0'; ptr_source++, ptr_destination++)
	{
		*ptr_destination = *ptr_source;
	}
	*ptr_destination = '\0';
	return (char*)ptr_destination;
}

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

char* my_strncpy_with_size(char* destination, const char* source, size_t num) {

	char* ptr_destination = destination;
	int size_source = (int)my_strlen(source);
	int size_destination = sizeof(destination);

	// if source >= num && destination  >= num;
	if (size_destination >= num) {
		int num_count = 0;
		for (const char* ptr_source = source; num_count < num; ptr_destination++, num_count++)
		{
			if (*ptr_source != '\0')
			{
				*ptr_destination = *(ptr_source++);

			}
			else
			{
				*ptr_destination = '\0';
			}
		}

	}	// if source < num && destination  >= num;
	else if ((size_destination < num) && (size_destination < size_source))
	{
		int num_count = 0;
		for (const char* ptr_source = source; num_count < size_destination; ptr_destination++, ptr_source++, num_count++)
		{
			*ptr_destination = *ptr_source;
		}
	} 	// if source < num && destination < num && destination >= source;
	else if ((size_source < num) && (size_destination < num) && (size_destination >= size_source))
	{
		int num_count = 0;
		for (const char* ptr_source = source; num_count < size_destination; ptr_destination++, ptr_source++, num_count++)
		{
			if (num_count < size_source)
			{
				*ptr_destination = *ptr_source;
			}
			else if (num_count < size_destination)
			{
				*ptr_destination = '\0';
			}
			else
			{
				break;
			}
		}
	}
	return (char*)ptr_destination;
}

char* my_strncpy(char* destination, const char* source, size_t num) {

	char* ptr_destination = destination;

	int num_count = 0;
	for (const char* ptr_source = source; num_count < num; ptr_destination++, num_count++)
	{
		if (*ptr_source != '\0')
		{
			*ptr_destination = *(ptr_source++);
		}
		else
		{
			*ptr_destination = '\0';
		}
	}
	ptr_destination = destination;
	return ptr_destination;
}

char* my_strcat(char* destination, const char* source) {

	char* ptr_destination = destination;

	while (*ptr_destination != '\0')
	{
		ptr_destination++;
	}

	for (const char* ptr_source = source; *ptr_source != '\0'; ptr_destination++, ptr_source++)
	{
		*ptr_destination = *ptr_source;
	}

	*ptr_destination = '\0';

	return destination;
}

char* my_strncat(char* destination, const char* source, size_t count) {

	char* ptr_destination = destination;

	while (*ptr_destination != '\0')
	{
		ptr_destination++;
	}
	int counter = 0;
	for (const char* ptr_source = source; counter < count; ptr_destination++, counter++)
	{
		if (*ptr_source != '\0')
		{
			*ptr_destination = *(ptr_source++);
		}
		else
		{
			*ptr_destination = '\0';
			break;
		}
	}

	*ptr_destination = '\0';

	return destination;
}

int		my_strncmp(const char* arr_1, const char* arr_2, size_t count) {

	const char* ptr_1 = arr_1;
	const char* ptr_2 = arr_2;
	int iterator = 0;
	int greaterStr = 0;

	if (count <= 0)
	{
		return -2;
	}
	else if (my_strlen(ptr_1) > my_strlen(ptr_2))
	{
		greaterStr = (int)my_strlen(ptr_1);
	}
	else
	{
		greaterStr = (int)my_strlen(ptr_2);
	}

	if (greaterStr > count)
	{
		iterator = (int)count;
	}
	else
	{
		iterator = greaterStr;
	}
	for (int i = 0; i < iterator; i++)
	{
		if (*(ptr_1 + i) > *(ptr_2 + i))
		{
			return 1;
		}
		else if (*(ptr_1 + i) < *(ptr_2 + i))
		{
			return -1;
		}
	}
	return 0;
}

char* my_strstr(const char* str, const char* substr) {

	// aa in aaba will return index

	int index = 0;
	int counter = 0;
	const char* ptr_str = str;
	const char* ptr_substr = substr;

	int substr_size = 0;

	while (*ptr_substr != '\0')
	{
		substr_size++;
		ptr_substr++;
	}

	for (ptr_substr = substr, ptr_str = str; *ptr_substr != '\0'; )
	{
		bool isFound = false;

		for (; *ptr_str != '\0'; ptr_str++, index++)
		{
			if (*ptr_str == *ptr_substr)
			{
				isFound = true;
				index++;
				ptr_substr++;
				ptr_str++;
				counter++;
				break;
			}
			else if (counter > 0)
			{
				ptr_substr = &substr[0];
				counter = 0;
				ptr_str--;
				index--;
			}
		}
		if (!isFound)
		{
			return NULL;
		}
	}
	return (char*)(ptr_substr - substr_size);
}

int		find_str_pattern_by_row_char(const char* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1) {
	//array size must have terminating zero at the end
	//matrix size must have terminating zero at the end

	int arr_size = 0;
	const char* ptr_substr = arr_1;

	while (*ptr_substr != '\0')
	{
		arr_size++;
		ptr_substr++;
	}

	int iterationRow = (matrix_cols - arr_size) >= 0 ? (matrix_cols - arr_size) : -1;//allowed iterations per col
	int iterationCol = (matrix_rows - arr_size) >= 0 ? (matrix_rows - arr_size) : -1;//allowed iterations per row

	bool check = true;
	int counter_occurrences = 0;
	for (int currentRow = 0; currentRow < matrix_rows; currentRow++)
	{
		for (int shiftIndex = 0; shiftIndex < iterationRow; shiftIndex++)
		{
			check = true;
			for (int columnIndex = shiftIndex, arrayIndex = 0; (columnIndex < matrix_cols) || (arrayIndex < arr_size); columnIndex++, arrayIndex++)
			{

				if ((*(arr_1 + arrayIndex) == '\0')) // in case of missing '\0'
				{
					break;
				}
				else if (*(arr_1 + arrayIndex) != matrix_1[currentRow * matrix_cols + columnIndex])
				{
					check = false; // { "cathhat","xrahatk","hatyhat" }
					break;
				}

			}
			if (check)
			{
				counter_occurrences++;
			}
		}
	}

	for (int currentCol = 0; currentCol < matrix_cols; currentCol++)
	{
		for (int shiftIndexRow = 0; shiftIndexRow <= iterationCol; shiftIndexRow++)
		{
			bool check = true;

			for (int currentRowMain = shiftIndexRow, columnIndex_array = 0; (currentRowMain < matrix_rows) && (columnIndex_array < arr_size); currentRowMain++, columnIndex_array++)
			{
				//commns --->
				if (arr_1[columnIndex_array] != matrix_1[currentRowMain * matrix_cols + currentCol])
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				counter_occurrences++;
			}
		}
	}
	return counter_occurrences;
}

void	print_matrix(const char* matrix, int rows, int cols) {

	printf("===================================\n");
	for (int i = 0; i < rows; i++, putchar('\n'))
	{

		for (int y = 0; y < cols; y++)
		{
			printf(" %c", matrix[i * cols + y]);
		}

	}
}

void	print_matrix_brackets(const char* matrix, int rows, int cols) {

	printf("===================================\n");
	printf("{");
	for (int i = 0; i < rows; i++)
	{
		putchar('\"');
		for (int y = 0; y < cols; y++)
		{
			printf("%c", matrix[i * cols + y]);
		}
		putchar('\"');

		if (i < cols)
		{
			putchar(',');
		}
	}
	printf("}");
}

char* extract_substr(const char* str, size_t idx_from, size_t idx_to, char result[]) {

	int idx_result = 0;

	for (const char* str_Ptr_first = str + idx_from, *str_Ptr_last = str + idx_to; str_Ptr_first <= str_Ptr_last; str_Ptr_first++, idx_result++)
	{
		result[idx_result] = *str_Ptr_first;
	}

	return result;
}

char toLower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
	{
		return	ch += 32;
	}
	return ch;
};

int my_strcmp_to_Lower(const char* arr_1, const char* arr_2) {

	for (const char* ptr_1 = arr_1, *ptr_2 = arr_2; *ptr_1 != '\0' || *ptr_2 != '\0';) //to avoid incrementing post deter zero
	{
		if (toLower(*ptr_1) > toLower(*ptr_2))
		{
			return 1;
		}
		else if (toLower(*ptr_1) < toLower(*ptr_2))
		{
			return -1;
		}

		if (*ptr_1 != '\0')
		{
			ptr_1++;
		}
		if (*ptr_2 != '\0')
		{
			ptr_2++;
		}
	}
	return 0;
};

int is_lexicographical(const char* arr_1[], int size) {

	for (int i = 0; (i + 1) < size; i++)
	{

		if (my_strcmp_to_Lower(arr_1[i], arr_1[i + 1]) > 0)
		{
			return 0;
		}
	}
	return 1;
}

void print_str_tokens(const char* str, const char* delimiters) {

	//print_str_tokens(", ,,,,hello,hi,Simo@gmail.com,bye__,,, _ __ ___ _  --- -- _ byee_12-3", "_@. -,");

	bool is_Printed = false;
	for (const char* str_ptr = str; *str_ptr != '\0'; str_ptr++)
	{
		bool is_Found = false;
		for (const char* str_del = delimiters; *str_del != '\0'; str_del++)
		{
			if (*str_ptr == *str_del)
			{
				is_Found = true;
				break;
			}
		}

		if (!is_Found)
		{
			putchar(*str_ptr);
			is_Printed = true;
		}

		if (is_Found && is_Printed)
		{
			putchar('\n');
			is_Printed = false;
		}
	}
}