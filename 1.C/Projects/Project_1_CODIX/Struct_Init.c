#define _CRT_SECURE_NO_WARNINGS
#define ULLONG_MAX_LENGTH 20
#include <stdio.h>
#include <Windows.h>
#include "Struct_Init.h"


Invoice* Invoice_Data_init(void) {

	Invoice* invoice = (Invoice*)malloc(sizeof(Invoice));
	if (invoice == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	invoice->rows = (Row_Sec*)malloc(sizeof(Row_Sec));
	if (invoice->rows == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}

	invoice->vec_size = 0;

	return invoice;
};

void vector_memFree(Invoice* invoice) {

	free(invoice->rows);
	free(invoice);
	invoice->rows = NULL;
	invoice = NULL;
}

void struct_Row_Sec_Pushback(Invoice* invoice, char* current_row_ptr) {

	invoice->rows = (Row_Sec*)realloc(invoice->rows, sizeof(Row_Sec) * (size_t)(invoice->vec_size + 1));
	if (invoice->rows == NULL)
	{
		printf("Error allocating memory. File validation process failure\n");
		exit(1);
	}
	strncpy_s(invoice->rows[invoice->vec_size].name_Section, sizeof(invoice->rows[invoice->vec_size].name_Section), current_row_ptr, INV_NAME);
	strncpy_s(invoice->rows[invoice->vec_size].invoice_Num_Section, sizeof(invoice->rows[invoice->vec_size].invoice_Num_Section), current_row_ptr + INV_NAME, INV_NUM);
	strncpy_s(invoice->rows[invoice->vec_size].date_Section, sizeof(invoice->rows[invoice->vec_size].date_Section), current_row_ptr + INV_NAME + INV_NUM, INV_DATE);
	strncpy_s(invoice->rows[invoice->vec_size].currency_Section, sizeof(invoice->rows[invoice->vec_size].currency_Section), current_row_ptr + INV_NAME + INV_NUM + INV_DATE, INV_CURRENCY);
	strncpy_s(invoice->rows[invoice->vec_size].end_Amount_Section, sizeof(invoice->rows[invoice->vec_size].end_Amount_Section), current_row_ptr + INV_NAME + INV_NUM + INV_DATE + INV_CURRENCY, (size_t)INV_AMOUNT + NEW_LINE);

	invoice->vec_size++;
}

void struct_Header_Pushback(Invoice* invoice, char* current_row_ptr) {

	strncpy_s(invoice->rowCount, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR, current_row_ptr, ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR);
}

void struct_Footer_Pushback(Invoice* invoice, char* current_row_ptr) {

	strncpy_s(invoice->invoiceSum, ULLONG_MAX_LENGTH + NULL_CHAR, current_row_ptr, ULLONG_MAX_LENGTH);
}