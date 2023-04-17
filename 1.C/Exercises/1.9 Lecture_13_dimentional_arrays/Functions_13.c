#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Functions_13.h"


void fill_matrix_rand(float* matrix, int rows, int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			//scanf(" %f", &matrix[i * cols + y]);

			matrix[i * cols + y] = (float)(rand() % 2);
		}
	}
}

void fill_matrix_rand_int(int* matrix, int rows, int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			//scanf(" %f", &matrix[i * cols + y]);

			matrix[i * cols + y] = (rand() % (2));
		}
	}
}

void sum_matrix(const float* matrix_1, const float* matrix_2, float* matrix_3, int rows, int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			int index = i * cols + y;
			matrix_3[index] = matrix_1[index] + matrix_2[index];
		}
	}
}

void print_matrix(const float* matrix, int rows, int cols) {

	printf("===================================\n");
	for (int i = 0; i < rows; i++, putchar('\n'))
	{
		for (int y = 0; y < cols; y++)
		{
			printf(" %.2f\t", matrix[i * cols + y]);
		}
	}
}

void print_matrix_no_decimal_int(const int* matrix, int rows, int cols) {

	printf("===================================\n");
	for (int i = 0; i < rows; i++, putchar('\n'))
	{
		for (int y = 0; y < cols; y++)
		{
			printf("%d", matrix[i * cols + y]);
		}
	}
}

void fill_matrix_manual(float* matrix, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			printf("[%d][%d] -> ", i, y);
			scanf("%f", &matrix[i * cols + y]);
		}
	}
}

void compare_elements(const float* matrix_1, const float* matrix_2, const int rows, const int cols) {
	bool test = true;
	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			if (matrix_1[i * cols + y] != matrix_2[i * cols + y])
			{
				test = false;
				break;
			}
		}
		if (!test)	break;
	}

	if (test)
	{
		printf("\nMatrices are exactly equal!\n");
	}
	else
	{
		printf("\nMatrices are NOT equal!\n");
	}
}

void matrix_multiplier(const float* matrix_1, const float* matrix_2, float* matrix_3, const int rows, const int cols) {

	for (int i = 0; i < rows; i++)
	{
		int z = 0;
		for (int y = 0; y < cols; y++, z++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix_3[i * cols + z] += matrix_1[i * cols + j] * matrix_2[j * cols + y];
			}
		}
	}
}

void print_matrix_w_characters(const int* matrix, int currentRows, int totalRows, int cols, int sumRows) {

	for (int i = currentRows, y = 0; y < cols; y++)
	{
		printf("%d", matrix[i * cols + y]);
		if (y < cols - 1)
		{
			printf(" + ");
		}
		else
		{
			printf(" = %d", sumRows);
		}
	}

	putchar('\n');

	for (int z = 0; z < cols; z++)
	{
		if (currentRows < totalRows - 1)
		{
			printf("+   ");
		}
		else
		{
			printf("=   ");
		}
	}
	putchar('\n');
	//}
};

void print_char_Array(const char* begin, int array_size) {

	for (const char* arr_Ptr = begin; arr_Ptr < (begin + array_size); arr_Ptr++)
	{
		printf("%c", *arr_Ptr);
	}
	putchar('\n');
};

int pattern_by_row_col(const int* matrix_1, int matrix_rows, int matrix_cols, const int* sub_matrix, int sub_matrix_rows, int sub_matrix_cols) {

	int iterationRow = (matrix_rows - sub_matrix_rows) >= 0 ? (matrix_rows - sub_matrix_rows) : -1;//allowed iterations per row
	int iterationCol = (matrix_cols - sub_matrix_cols) >= 0 ? (matrix_cols - sub_matrix_cols) : -1;//allowed iterations per col

	//int counter_occurrences = 0;
	for (int shiftIndexCol = 0; shiftIndexCol <= iterationCol; shiftIndexCol++)
	{
		for (int shiftIndexRow = 0; shiftIndexRow <= iterationRow; shiftIndexRow++)
		{
			bool check = true;
			int counter_subMatrix_row_iterations = 0;

			for (int currentRowIndex = shiftIndexRow, sub_matrix_row = 0; currentRowIndex < matrix_rows; currentRowIndex++, sub_matrix_row++)
			{
				if (++counter_subMatrix_row_iterations > sub_matrix_cols)
				{
					break;
				}
				for (int currentColMain = shiftIndexCol, columnIndexSub = 0; currentColMain < matrix_cols; currentColMain++, columnIndexSub++)//commns --->
				{
					if (sub_matrix[sub_matrix_row * sub_matrix_cols + columnIndexSub] != matrix_1[currentRowIndex * matrix_cols + currentColMain])
					{
						check = false;
						currentRowIndex = matrix_rows;
						break;
					}
					else if (columnIndexSub == sub_matrix_cols - 1)
					{
						break;
					}
				}
			}
			if (check)
			{
				return 1;
				//counter_occurrences++;
			}
		}
	}
	return 0;
}

int check_diagonals(const float* matrix, int matrix_rows, int matrix_cols) {

	bool diagonal_1 = true;
	bool diagonal_2 = true;

	for (int i = 0; i < matrix_rows; i++)
	{
		if (matrix[i * matrix_cols + i] != 1)
		{
			diagonal_1 = false;
			break;
		}
	}

	for (int i = 0; i < matrix_rows; i++)
	{
		if (matrix[i * matrix_cols + ((matrix_cols - 1) - i)] != 1)// matrix_1[i][(ARR_COLS - y)-1])
		{
			diagonal_2 = false;
			break;
		}
	}
	return (diagonal_1 == diagonal_2) ? 1 : 0;
}

int check_non_diagonals(const float* matrix, int matrix_rows, int matrix_cols) {

	//bool non_diagonals = true;
	int zeroes_count = 0;
	int matrix_size = matrix_rows * matrix_cols;

	for (int i = 0; i < matrix_rows; i++)
	{
		for (int y = 0; y < matrix_cols; y++)
		{
			if (matrix[i * matrix_cols + y] == 0)
			{
				//non_diagonals = false;
				zeroes_count++;
			}
		}
	}
	if (matrix_size % 2 != 0) // if odd diagonals cross each other => +1 element;
	{
		matrix_size++;
	}
	if (matrix_size - matrix_rows * 2 == zeroes_count)
	{
		return 1;
	}

	return 0;
}

void swap_rows(float* matrix, int cols, int* row_swap_1, int* row_swap_2) {
	for (int i = 0; i < cols; i++)
	{
		float temp = matrix[*row_swap_1 * cols + i];
		matrix[*row_swap_1 * cols + i] = matrix[*row_swap_2 * cols + i];
		matrix[*row_swap_2 * cols + i] = temp;
	}
}

void swap_cols(float* matrix, int rows, int cols, int* col_swap_1, int* col_swap_2) {
	for (int i = 0; i < rows; i++)
	{
		float temp = matrix[i * cols + *col_swap_1];
		matrix[i * cols + *col_swap_1] = matrix[i * cols + *col_swap_2];
		matrix[i * cols + *col_swap_2] = temp;
	}
}

void matrix_multiplier_2(float* matrix, int rows, int cols, float number) {
	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			matrix[i * cols + y] *= number;
		}
	}
}

void print_Array_Brackets(const float* begin, const int array_size) {

	for (const float* arr_Ptr = begin; arr_Ptr < (begin + array_size); arr_Ptr++)
	{
		printf("[");
		printf("%.2f", *arr_Ptr);
		printf("]");
		printf("\t");
	}
	putchar('\n');
}

void array_matrix_multiplier(float* matrix, int rows, int cols, float* array) {
	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			matrix[i * cols + y] *= array[y];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		array[i] = 0.0;
		for (int y = 0; y < cols; y++)
		{
			array[i] += matrix[i * cols + y];
		}
	}
}

int unique_columns(const int* matrix, int rows, int cols) {

	int count_Unique = 0;
	//for (int cycles = 0; cycles < cols; cycles++)
	//{
		for (int col_Iterations = 0; col_Iterations < cols; col_Iterations++)
		{
			bool is_Match = false;
			for (int col = 0; col < cols; col++)
			{
				int count_Row_Occurrences = 0;

				if (col_Iterations == col)
				{
					continue;
				}

				for (int row = 0; row < rows; row++)
				{
					if (matrix[row * cols + col_Iterations] == matrix[row * cols + col])
					{
						count_Row_Occurrences++;
					}
				}

				if (count_Row_Occurrences == rows)
				{
					is_Match = true;
					break;
				}
			}
			if (!is_Match)
			{
				count_Unique++;
			}
		}
	//}
	return count_Unique;
};

void sum_of_rows_and_columns(const int* matrix, int rows, int cols) {

	int sumRows = 0;
	int sumColumns = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int y = 0; y < cols; y++)
		{
			sumRows += matrix[i * cols + y];
		}

		print_matrix_w_characters(matrix, i, rows, cols, sumRows);
		sumRows = 0;
	}

	for (int i = 0; i < cols; i++)
	{
		for (int y = 0; y < rows; y++)
		{
			sumColumns += matrix[y * rows + i];
		}
		printf("%d   ", sumColumns);
		sumColumns = 0;
	}
}

void getCharArray(char* arr, int rows, int cols) {
	char temp = ' ';
	int maxLength = 0;
	if (cols >= rows)
	{
		maxLength = cols;
	}
	else
	{
		maxLength = rows;
	}

	printf("Enter an array sequence of maximum %d integers or less: \n", maxLength);

	for (int i = 0; i < maxLength; i++)
	{
		temp = getchar();

		if (temp == '\n')
		{
			break;
		};
		arr[i] = temp;
	};
	//arr[i] = '\0';
}

int pattern_by_row(const int* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1, int arr_size) {

	int iterationRow = (matrix_cols - arr_size) >= 0 ? (matrix_cols - arr_size) : -1;//allowed iterations per col

	bool check = true;
	//int counter_row_occurrences = 0;
	for (int currentRow = 0; currentRow < matrix_rows; currentRow++)
	{
		for (int shiftIndex = 0; shiftIndex <= iterationRow; shiftIndex++)
		{
			check = true;
			for (int columnIndex = shiftIndex, arrayIndex = 0; columnIndex < matrix_cols; columnIndex++, arrayIndex++)
			{
				if (*(arr_1 + arrayIndex) - '0' != matrix_1[currentRow * matrix_cols + columnIndex])
				{
					check = false;
					break;
				}
				else if (arrayIndex == arr_size - 1)
				{
					break;
				}
			}
			if (check)
			{
				//counter_row_occurrences++;
				return 1;
			}
		}
	}
	return 0; // counter_row_occurrences;
};

int pattern_by_column(const int* matrix_1, int matrix_rows, int matrix_cols, const char* arr_1, int arr_size) {

	int iterationCol = (matrix_rows - arr_size) >= 0 ? (matrix_rows - arr_size) : -1;//allowed iterations per col

	bool check = true;
	//int counter_col_occurrences = 0;

	for (int currentCol = 0; currentCol < matrix_cols; currentCol++)//commns --->
	{
		for (int shiftIndex = 0; shiftIndex <= iterationCol; shiftIndex++)
		{
			check = true;
			for (int rowIndex = shiftIndex, arrayIndex = 0; rowIndex < matrix_rows; rowIndex++, arrayIndex++)
			{
				if (*(arr_1 + arrayIndex) - '0' != matrix_1[rowIndex * matrix_cols + currentCol])
				{
					check = false;
					break;
				}
				else if (arrayIndex == arr_size - 1)
				{
					break;
				}
			}
			if (check)
			{
				return 1; //counter_col_occurrences++;
			}
		}
	}
	return 0; //counter_col_occurrences;
};



/*
int unique_columns(const int* matrix, int rows, int cols) {
	int countOnes = 0;
	int countZeroes = 0;
	int countOccurrences = 0;

	for (int i = 0; i < cols; i++)
	{
		for (int y = 0; y < rows; y++)
		{
			if (matrix[y * rows + i])
			{
				countOnes++;
			}
			else
			{
				countZeroes++;
			}
		}
		if (countOnes == rows || countZeroes == rows)
		{
			countOccurrences++;
		}
		countOnes = 0;
		countZeroes = 0;
	}
	return countOccurrences;
};
*/