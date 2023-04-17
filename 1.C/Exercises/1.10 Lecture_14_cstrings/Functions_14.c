#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


size_t my_strlen(const char arrPtr[]) {

	//char* ptr = arr;

	size_t lengthArray = 0;
	while (*arrPtr != '\0')
	{
		lengthArray++;

		arrPtr++;
	}

	return (int)lengthArray;
};

void print_reversed_const_string(const char* str[]) {

	int lastIndex = (int)my_strlen(str[0]);
	for (const char* end = &str[0][lastIndex - 1]; end >= &str[0][0]; end--)
	{
		printf("%c", *end);

	}
	putchar('\n');
};

void print_reversed_char_array(const char* arr) {

	int lastIndex = (int)my_strlen(arr);

	for (const char* end = &arr[lastIndex - 1]; end >= &arr[0]; end--)
	{
		printf("%c", *end);

	}
	putchar('\n');
};

void print_char_Array(const char* begin) {

	for (const char* arr_Ptr = begin; *arr_Ptr != '\0'; arr_Ptr++)
	{
		printf("%c", *arr_Ptr);
	}
	putchar('\n');
};

void get_string(char* arr) {

	char temp = ' ';
	int index = 0;
	while ((temp = getchar()) != '\n')
	{
		arr[index++] = temp;
	}
	arr[index] = '\0';
};

void get_string_EOF(char* arr) {
	char letter = ' ';
	int index = 0;
	while ((letter = getchar()) != EOF)
	{
		arr[index++] = letter;
	}
	arr[index] = '\0';
};

void get_string_no_blanks_lowercase(char* begin) {

	char temp = ' ';
	int index = 0;
	while ((temp = getchar()) != '\n')
	{
		if (temp != ' ')
		{
			begin[index++] = toLower(temp);
		}
	}
};

int compare(const char* arr, char* arr_2) {

	int i = 0;
	for (const char* ptr = arr; *ptr != '\0'; ptr++)
	{
		if (*ptr != arr_2[i++])
		{
			return 0;
		}
	}
	return 1;
};

char toLower(char ch) {
	if (ch >= 'A' && ch <= 'Z')
	{
		return	ch += 32;
	}
	return ch;
};

void copy_array_in_reverse(const char* arr, char* arr_2) {

	int lastIndex = (int)my_strlen(arr) - 1;
	int i = 0;
	for (const char* end = &arr[lastIndex]; end >= &arr[0]; end--)
	{
		arr_2[i++] = *end;
	}
};

void calmify_str(char* begin) {

	for (char* arr_Ptr = begin; *arr_Ptr != '\0'; arr_Ptr++)
	{
		if (*arr_Ptr >= 'a' && *arr_Ptr <= 'z')
		{
			*arr_Ptr -= 32; // ACSII letter difference
		}
		else if (*arr_Ptr == '.')
		{
			*arr_Ptr = '!';
		}
	}
};

void shorten_string(char* arr) {

	for (char* ptr = arr; *ptr != '\0'; ptr++)
	{
		if (*ptr == ' ')
		{
			*ptr = '\0';
			break;
		}
	}
};

int lookup_char_value(const char* begin, char ch) {
	int occurrences = 0;
	for (const char* arr_Ptr = begin; *arr_Ptr; arr_Ptr++) // *arr_Ptr != '\0'
	{
		if (*arr_Ptr == ch)
		{
			occurrences++;
		}
	}
	return occurrences;
};

int h_lookup_string_index(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2) {

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

int h_lookup_string_occurrences(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2) {

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

int find_At_char(const char* arr, int* index) {
	int count = 0;
	int isFound = 0;
	for (const char* ptr = arr; *ptr != '\0'; ptr++, (*index)++)
	{
		if (*ptr == '@')
		{
			count++;
			isFound = 1;
		}
		else if (isFound)
		{
			(*index)--;
		}
	}
	if (count > 1)
	{
		return count;
	}
	else if (count == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
};

int is_alpha(const char symbol) {

	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'))
	{
		return 1;
	}
	return 0;
};

int is_numeric(const char symbol) {

	const char* ptr = &symbol;

	if ((*ptr >= '0' && *ptr <= '9'))
	{
		return 1;
	}
	return 0;
};

int is_printable(const char word) {

	char arr_special_char[] = { '!', '#', '$', '%', '&', '\'', '*', ',', '+', '-', '/', '=', '?', '^', '_', '`', '{', '|', '}', '~', '\0' };

	for (int i = 0; i < 21; i++)
	{
		if (arr_special_char[i] == word)
		{
			return 1;
		}
	}
	return 0;
};

char is_special_character(const char word) {

	char arr_special_char[14] = { ' ', '"', '(',')' , ',' , ':' ,';' ,'<' , '>' ,'@','[','\\', ']', '\0' };

	for (int i = 0; i < 14; i++)
	{
		if (word == arr_special_char[i])
		{
			char element = arr_special_char[i];
			return 1;
		}
	}

	return 0;
};

int is_period(const char* arr_1, const char* ptr, int begin_index, int end_index, int* index_local) {

	int validation = 1;

	const char* test_ptr = ptr;

	if (h_lookup_string_occurrences(arr_1, end_index, "..", 3))
	{
		validation = 4;//	printf("\nDot at index [%d] should not appear consecutively!", *index_local);
		return validation;
	}
	else if (ptr[end_index - 2] == '.')// || ptr[end_index - 1] == '.')
	{
		validation = 3;// printf("\nIndex [%d] character must be an alphabetical letter!", *index_local);
		return validation;
	}

	return validation;
};

int is_hyphen(const char* arr_1, const char* ptr, int ånd_index, int arr_size, int* index_local, int arr_size_2) {
	int validation = 0;
	int index = 0;
	const char* test_ptr = NULL;

	if (*ptr == '-')
	{
		if (*(ptr - 1) == '@')
		{
			validation = 6; //printf("\nHyphen at index [%d] not allowed!", *index_local);
			return validation;
		}

		else if (*ptr == *(ptr + 1))
		{
			validation = 8;// printf("\nHyphen at index [%d] should not appear consecutively!", *index_local);
			return validation;
		}
		else if (*ptr == *(arr_1 + arr_size - arr_size_2 - 1))
		{
			validation = 7;// printf("\nLast character must be an alphabetical letter!");
			return validation;
		}
	}
	return validation;
};

int validation_email_local(const char* arr, int begin_index, int end_index, int* index_local, int at_valuation) {

	int validation = 1;

	*index_local = begin_index;

	if (at_valuation > 1)
	{
		validation = 14;//	printf("\nOnly a single [@] character allowed!\n");
		return validation;
	}
	else if (!at_valuation)
	{
		validation = 15;//printf("\nInvalid email. No '@' separator found!\n");
		return validation;
	}
	else if (end_index == 1)
	{
		validation = 16;	//printf("\nInvalid email. No local part!\n");
		return validation;
	}

	for (const char* ptr = arr; ptr < arr + end_index - 1; ptr++, (*index_local)++)
	{
		if (!is_alpha(ptr[0]) && !is_numeric(ptr[0]) && (*index_local) == 0)
		{
			validation = 13;// printf("\nFirst local character must be alpha-numeric!");
			return validation;
		}
		else if (*ptr == '.')
		{
			validation = is_period(arr, ptr, begin_index, end_index, index_local);
			return validation;
		}
		else if (is_special_character(*ptr) != 0)
		{
			validation = 5;//	printf("\nIndex[%d] special character [%c] is not allowed!", *index_local, is_special_character(*ptr));
			return validation;
			//break;
		}

	}

	return validation;

};

int validation_email_domein(const char* arr, int end_index, int arr_size, const char* arr_2, int arr_size_2, int* index_local) { // end index  = size - ".com"

	char special_char = ' ';
	int validation = 1;

	//*index_domain = end_index;

	int h_lookup = h_lookup_string_occurrences(arr, arr_size, arr_2, arr_size_2);

	if ((arr_size - arr_size_2) <= end_index)
	{
		validation = 12; //printf("\nDomain incomplete!\n");
		return validation;
	}
	else if (h_lookup > 1)
	{
		validation = 10;// printf("\nDomain must have only one '.com' occurrence\n");
		return validation;
	}
	else if (h_lookup)
	{
		if ((h_lookup_string_index(arr, arr_size, arr_2, arr_size_2) != (arr_size - arr_size_2)))
		{
			validation = 9;// printf("\nDomain must end in '.com'\n");
			return validation;
		}
		else
		{
			for (const char* ptr = arr + end_index; ptr < arr + arr_size; ptr++)
			{
				(*index_local)++;
				if (is_hyphen(arr, ptr, end_index, arr_size, index_local, arr_size_2)) {

					validation = is_hyphen(arr, ptr, end_index, arr_size, index_local, arr_size_2);
					return validation;
				}
				else if (is_special_character(*ptr) != 0)
				{
					special_char = is_special_character(*ptr);
					validation = 11; //printf("\nIndex[%d] special character [%c] is not allowed!\n", *index_local, is_special_character(*ptr));
					return validation;
				}
				if (!is_alpha(*(arr + end_index)) && !is_numeric(*(arr + end_index)))// && (*index_local) == 0)
				{
					validation = 17;// printf("\nFirst domain character must be alpha-numeric!");
					return validation;
				}
			}
		}
	}
	return validation;

};

void print_warning(int part_, int index_local, int at_valuation) {
	int check = 0;

	switch (part_)
	{
	case 2:
		printf("\nWarning: Dot at index [%d] not allowed!", index_local);
		break;
	case 3:
		printf("\nWarning: Index [%d] character must be an alphabetical letter!", index_local);
		break;
	case 4:
		printf("\nWarning: Dots should not appear consecutively!");
		break;
	case 5:
		printf("\nWarning: Index[%d] special character not allowed!", index_local);
		break;
	case 6:
		printf("\nWarning: Hyphen at index [%d] not allowed!", at_valuation);
		break;
	case 7:
		printf("\nWarning: Last domain character prior to '.com' must be an alphabetical letter!");
		break;
	case 8:
		printf("\nWarning: Hyphen in domain should not appear consecutively!");
		break;
	case 9:
		printf("\nWarning: Domain must end in '.com'");
		break;
	case 10:
		printf("\nWarning: Domain must have only one '.com' occurrence");
		break;
	case 11:
		printf("\nWarning: Index[%d] special character is not allowed!", index_local);
		break;
	case 12:
		printf("\nWarning: Domain incomplete!");
		break;
	case 13:
		printf("\nWarning: First local character must be alpha-numeric!");
		break;
	case 14:
		printf("\nWarning: Only a single [@] character allowed!");
		break;
	case 15:
		printf("\nWarning: Invalid email. No '@' separator found!");
		break;
	case 16:
		printf("\nWarning: Invalid email. No local part!");
		break;
	case 17:
		printf("\nWarning: First domain character must be alpha-numeric!");
		break;

	default:
		break;
	}
}

void print_array_index(const char* arr_1, int arr_size) {

	printf("\nEmail address: << ");

	for (const char* arr_ptr = arr_1; arr_ptr < arr_1 + arr_size; arr_ptr++)
	{
		printf("%c", *arr_ptr);
	}
	printf(" >> is valid\n");
}

int my_strcmp(const char* arr_1, const char* arr_2) {

	const char* ptr_1 = arr_1;
	const char* ptr_2 = arr_2;
	int iterator = 0;

	if (my_strlen(ptr_1) > my_strlen(ptr_2))
	{
		iterator = (int)my_strlen(ptr_1);
	}
	else
	{
		iterator = (int)my_strlen(ptr_2);
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
};

int my_strcmp_modified(const char* arr_1, const char* arr_2, int rows, int cols) {

	const char* ptr_1 = arr_1;
	const char* ptr_2 = arr_2;
	int iterator = 0;

	for (int row = 0; ptr_2[row * cols] != '\0'; row++)
	{
		bool is_different = false;

		if (my_strlen(ptr_1) > my_strlen(&ptr_2[row * cols]))
		{
			iterator = (int)my_strlen(ptr_1);
		}
		else
		{
			iterator = (int)my_strlen(&ptr_2[row * cols]);
		}

		for (int i = 0; i < iterator; i++)
		{
			if (*(ptr_1 + i) != ptr_2[row * cols + i])
			{
				is_different = true;
				break;
			}
		}

		if (!is_different)
		{
			return row;
		}

	}
	return -1;

};

int is_capital(const char letter) {

	if (letter >= 'A' && letter <= 'Z')
	{
		return 1;
	}
	return 0;
};

void first_letter_to_capital(char arr_1[]) {

	int count_chars = 0;
	bool is_special_char = false;
	char* ptr_arr_1 = arr_1;
	int iterations = (int)my_strlen(ptr_arr_1);

	for (int i = 0; i < iterations; i++)
	{
		if (is_alpha(ptr_arr_1[i]) || is_numeric(ptr_arr_1[i]))
		{
			count_chars++;
			is_special_char = false;
		}
		else if (!is_special_char)
		{
			if (is_capital(ptr_arr_1[i - count_chars]))
			{
				ptr_arr_1[i - count_chars] -= 32;
			}
			count_chars = 0;
			is_special_char = true;
		}
	}
};

void fill_char_matrix_from_array(char* matrix, int* current_row, int col, const int rows, const int cols, const char arr[]) {

	for (int i = 0; *(arr + i) != '\0'; col++, i++)
	{
		if (col == cols - 2)
		{
			matrix[(*current_row) * cols + col] = '\0';
			break;
		}
		else
		{
			matrix[(*current_row) * cols + col] = arr[i];
		}
	}
	(*current_row)++;
};

void print_result(const char* matrix, int rows, int cols, int arr[], int uncounted) {

	printf("===================================");
	for (int i = 0; matrix[i * cols] != '\0'; i++)
	{
		//for (int y = 0; matrix[i * cols + y] != '\0'; y++)
	//	{
		printf("\n%s: %d", &matrix[i * cols], arr[i] + uncounted);
		//	}
	}
}

void word_count_occurrences(const char arr_1[], char arr_2[], char* matrix, const int row_size, const int col_size, int arr_occurrences[]) {


	int arr_2_index = 0;
	bool is_special_char = false;
	int current_row = 0;
	int col = 0;

	for (int i = 0; arr_1[i] != '\0'; i++)
	{
		if (is_alpha(arr_1[i]) || is_numeric(arr_1[i]))
		{
			arr_2[arr_2_index++] = arr_1[i];

			is_special_char = false;
		}
		else if (!is_special_char)
		{
			is_special_char = true;

			arr_2[arr_2_index] = '\0';
			arr_2_index = 0;
			int occurrences = my_strcmp_modified(arr_2, matrix, row_size, col_size);

			if (occurrences == -1)
			{
				fill_char_matrix_from_array(matrix, &current_row, col, row_size, col_size, arr_2);
			}
			else
			{
				arr_occurrences[occurrences] += 1;
			}
		}
	}
};

int cmpr_rows_length(const char* matrix, int rows, int cols) {

	int count_Unique_row = 0;

	for (int row_Iterations = 0; *(matrix + row_Iterations * cols) != '\0'; row_Iterations++)
	{
		bool is_bigger = false;

		for (int row = 0; *(matrix + row * cols) != '\0'; row++)
		{
			if (row_Iterations == row)
			{
				continue;
			}

			if ((int)my_strlen(&*(matrix + row_Iterations * cols)) > (int)my_strlen(&*(matrix + row * cols)))
			{
				is_bigger = true;
			}
			else if ((int)my_strlen(&*(matrix + row_Iterations * cols)) == (int)my_strlen(&*(matrix + row * cols)))
			{
				continue;
			}
			else
			{
				is_bigger = false;
				//count_Unique_row = -1;
				break;
			}
		}
		if (is_bigger) 
		{
			count_Unique_row = row_Iterations;
		}
	}
	return count_Unique_row;
};

char* h_lookup_string_pointer(const char* arr_1, int arr_size_1, const char* arr_2, int arr_size_2) {

	int index = 0;
	int counter = 0;
	// aa in aaba should not return index
	const char* ptr_2 = arr_2, * ptr_1 = arr_1;
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
			return NULL;
		}
	}
	return (char*)(arr_1 + index - arr_size_2);
};

int longest_word_matrix_position(const char arr_1[], char arr_2[], char* matrix, const int row_size, const int col_size, int arr_occurrences[], int arr_1_size) {

	bool is_special_char = false;
	int arr_2_index = 0;
	int current_row = 0;
	int col = 0;

	for (int i = 0; &arr_1[i] <= (arr_1 + arr_1_size); i++)
	{
		if (is_alpha(arr_1[i]) || is_numeric(arr_1[i]))
		{
			arr_2[arr_2_index++] = arr_1[i];

			is_special_char = false;
		}
		else if (!is_special_char)
		{
			is_special_char = true;

			arr_2[arr_2_index] = '\0';
			arr_2_index = 0;
			int occurrences = my_strcmp_modified(arr_2, matrix, row_size, col_size);

			if (occurrences == -1)
			{
				fill_char_matrix_from_array(matrix, &current_row, col, row_size, col_size, arr_2);
			}
		}
	}

	int row_longest_string = cmpr_rows_length(matrix, row_size, col_size);

	return row_longest_string;

};


