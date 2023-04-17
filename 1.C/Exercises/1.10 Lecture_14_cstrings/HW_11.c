#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 256
#define ROW_SIZE 100
#define COL_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int main(void)
{
	const int arr_size = ARR_SIZE;
	const int row_size = ROW_SIZE;
	const int col_size = COL_SIZE;

	char arr_1[ARR_SIZE] = { '\0' }; //"How are you today, how were you yesterday?";
	char arr_2[ARR_SIZE] = { '\0' };
	int arr_occurrences[ARR_SIZE] = { 0 };

	char matrix[256][20] = { '\0' };
	
	int uncounted = 1;
	printf("\nEnter string to evaluate [255] characters max:")';
	get_string(arr_1);

	first_letter_to_capital(arr_1);

	word_count_occurrences(arr_1, arr_2, *matrix, row_size, col_size, arr_occurrences);

	print_result(*matrix, ROW_SIZE, COL_SIZE, arr_occurrences,uncounted);

	return 0;
}
/*How Simo are you you you today today,.... how were were we Simo yesterday????>><*/