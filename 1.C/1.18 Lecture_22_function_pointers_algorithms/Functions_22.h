//#pragma once
#ifndef FUNCTIONS_22_H
#define FUNCTIONS_22_H

char toLower(char ch);

int my_strcmp(const char* arr_1, const char* arr_2);

int my_strcmp_to_Lower(const char* arr_1, const char* arr_2) ;

int count_punct(const char* arg_1);

int compare_int_(const void* a, const void* b);

int compare_int_long(const void* a, const void* b);

int compare_ltr_(const void* a, const void* b);

int compare_ltr_rvsl(const void* a, const void* b);

int compare_ltr_strcmp(const void* a, const void* b);

int compare_ltr_my_strcmp_(const void* a, const void* b);

int compare_char_(const void* a, const void* b);

int compare_char_count_(const void* a, const void* b);

int compare_char_punct_(const void* a, const void* b);

void my_qsort(void* arr_ptr, size_t arr_size, size_t element_size, int (*compare_ltr_)(const void* a, const void* b));

int bin_search_int_(int arr[], int n, int val);

char** bin_search_char_unsorted(const char* arr[], size_t arr_size, const char* key);

char** bin_search_char_sorted(const char* key[], const char* arr[], size_t arr_size, int (*compare_ltr_)(const void* a, const void* b));

#endif // !FUNCTIONS_22_H
