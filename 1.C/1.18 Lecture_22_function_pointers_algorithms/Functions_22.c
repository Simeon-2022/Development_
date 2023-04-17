#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Functions_22.h"

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

int compare_int_(const void* a, const void* b) {
	int arg_1 = *(const int*)a;
	int arg_2 = *(const int*)b;

	if (arg_1 > arg_2) { return 1; }
	if (arg_1 < arg_2) { return -1; }
	return 0;
}

int compare_char_(const void* a, const void* b) {
	int arg_1 = *(const char*)a;
	int arg_2 = *(const char*)b;

	if (arg_1 > arg_2) { return 1; }
	if (arg_1 < arg_2) { return -1; }
	return 0;
}

int compare_ltr_(const void* a, const void* b) {

	//const char** ptr_1 = (const char**)a;
	//const char** ptr_2 = (const char**)b;

	//return strcmp(*ptr_1, *ptr_2); or:
	//return my_strcmp_to_Lower(*ptr_1, *ptr_2);

	for (const char** ptr_1 = (const char**)a, **ptr_2 = (const char**)b; **ptr_1 != '\0' || **ptr_2 != '\0';) //to avoid incrementing post deter zero
	{
		if (**ptr_1 > **ptr_2)
		{
			return 1;
		}
		else if (**ptr_1 < **ptr_2)
		{
			return -1;
		}

		if (**ptr_1 != '\0')
		{
			*ptr_1++;
		}
		if (**ptr_2 != '\0')
		{
			*ptr_2++;
		}
	}
	return 0;
}

int compare_int_long(const void* a, const void* b) {
	unsigned long arg_1 = *(const unsigned long*)a;
	unsigned long arg_2 = *(const unsigned long*)b;

	if ((arg_1 % 2 == 0 && arg_2 % 2 != 0))//|| (arg_1 % 2 != 0 && arg_2 % 2 == 0))
	{
		return -1;
	}
	else if (arg_1 % 2 != 0 && arg_2 % 2 == 0)
	{
		return 1;
	}
	if (arg_1 % 2 == 0 && arg_2 % 2 == 0)
	{
		//return (arg_1 < arg_2) - (arg_1 > arg_2);

		if (arg_1 > arg_2) { return -1; }
		if (arg_1 < arg_2) { return 1; }
	}
	if (arg_1 % 2 != 0 && arg_2 % 2 != 0) // else { return (arg1 < arg2) - (arg1 > arg2);}
	{
		if (arg_1 > arg_2) { return -1; }
		if (arg_1 < arg_2) { return 1; }
	}

	return 0;
}

int my_strcmp(const char* arr_1, const char* arr_2) {

	for (const char* ptr_1 = arr_1, *ptr_2 = arr_2; *ptr_1 != '\0' || *ptr_2 != '\0';) //to avoid incrementing post deter zero
	{
		if ((*ptr_1) > (*ptr_2))
		{
			return 1;
		}
		else if ((*ptr_1) < (*ptr_2))
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

int compare_ltr_my_strcmp_(const void* a, const void* b) {

	const char** ptr_1 = (const char**)a;
	const char** ptr_2 = (const char**)b;

	return my_strcmp(*ptr_1, *ptr_2);
}

int count_punct(const char* arg_1) {

	int count = 0;
	for (const char* ptr_1 = arg_1; *ptr_1 != '\0'; ptr_1++)
	{
		if (!isalnum(*ptr_1))
		{
			count++;
		}
	}

	return count;
};

int compare_ltr_rvsl(const void* a, const void* b) {

	const char** ptr_1 = (const char**)a;
	const char** ptr_2 = (const char**)b;
	if (my_strcmp(*ptr_1, *ptr_2) == 1)
	{
		return -1;
	}
	else if (my_strcmp(*ptr_1, *ptr_2) == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int compare_char_count_(const void* a, const void* b) {

	const char** ptr_1 = (const char**)a;
	const char** ptr_2 = (const char**)b;

	if (strlen(*ptr_1) > strlen(*ptr_2))
	{
		return -1;
	}
	else if (strlen(*ptr_1) < strlen(*ptr_2))
	{
		return 1;
	}
	return 0;
}

int compare_char_punct_(const void* a, const void* b) {

	const char** ptr_1 = (const char**)a;
	const char** ptr_2 = (const char**)b;

	if (count_punct(*ptr_1) > count_punct(*ptr_2))
	{
		return -1;
	}
	else if (count_punct(*ptr_1) < count_punct(*ptr_2))
	{
		return 1;
	}
	return 0;
}

void my_qsort(void* arr_ptr, size_t arr_size, size_t element_size, int (*compare_ltr_)(const void* a, const void* b)) {

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{
			void* addr_arg_1 = (char*)arr_ptr + j * element_size;
			void* addr_arg_2 = (char*)arr_ptr + ((j + 1) * element_size);

			if ((*compare_ltr_)(addr_arg_1, addr_arg_2) > 0)
			{
				char temp[sizeof(char*)];

				memcpy(temp, addr_arg_1, sizeof(char*));
				memcpy(addr_arg_1, addr_arg_2, sizeof(char*));
				memcpy(addr_arg_2, temp, sizeof(char*));
				//free(temp);
			}
		}
	}
}

int bin_search_int_(int arr[], int n, int val)
{
	int lo = 0, hi = n - 1;
	while (hi - lo > 1)
	{
		int mid = (hi + lo) / 2;
		if (arr[mid] < val)
			lo = mid + 1;
		else
			hi = mid;
	}
	if (arr[lo] == val)
		return lo;
	else if (arr[hi] == val)
		return hi;

	return -1;
}

int compare_ltr_strcmp(const void* a, const void* b) {

	const char** ptr_1 = (const char**)a;
	const char** ptr_2 = (const char**)b;
	if (strcmp(*ptr_1, *ptr_2) == 1)
	{
		return 1;
	}
	else if (strcmp(*ptr_1, *ptr_2) == -1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

char** bin_search_char_unsorted(const char* arr[], size_t arr_size, const char* key) {

	const char* key_ptr = key;
	const char** lo_ptr = arr;
	const char** hi_ptr = arr + (arr_size - 1);

	int lo = 0;
	int hi = (int)arr_size - 1;

	while (hi_ptr - lo_ptr > 1) // elements available between the pointers
	{
		int mid = (hi + lo) / 2;
		const char** mid_ptr = arr + mid;
		if (*mid_ptr < key)
		{
			lo = mid + 1;
			lo_ptr = arr + lo;
		}
		else
		{
			hi = mid;
			hi_ptr = arr + mid;
		}
	}

	if (*lo_ptr == key)
	{
		return (char**)lo_ptr;
	}
	else if (*hi_ptr == key)
	{
		return (char**)hi_ptr;
	}
	return NULL;
}

char** bin_search_char_sorted(const char* key[], const char* arr[], size_t arr_size, int (*compare_ltr_)(const void* a, const void* b)) {

	const char** key_ptr = key;
	const char** lo_ptr = arr;
	const char** hi_ptr = arr + (arr_size - 1);

	int lo = 0;
	int hi = (int)arr_size - 1;

	while (hi - lo > 1)
	{
		int mid = (hi + lo) / 2;
		const char** mid_ptr = arr + mid;

		if ((*compare_ltr_strcmp) (mid_ptr, key_ptr) < 0)
		{
			lo = mid + 1;
			lo_ptr = arr + lo;
		}
		else
		{
			hi = mid;
			hi_ptr = arr + mid;
		}
	}

	if (!(*compare_ltr_strcmp) (lo_ptr, key_ptr))
	{
		return (char**)lo_ptr;
	}
	else if (!(*compare_ltr_strcmp) (hi_ptr, key_ptr))
	{
		return (char**)hi_ptr;
	}
	return NULL;
}