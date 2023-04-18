#pragma once
#ifndef STRUCT_INIT_H
#define STRUCT_INIT_H
#define ULLONG_MAX_LENGTH 20

typedef enum FileNameAttributes
{
	LAST_ROW = 1,
	NULL_CHAR = 1,
	NEW_LINE = 1,
	IMPORT_INVOICES_ = 16,
	FILE_DATE_ = 8,
	FILE_TIME = 6,
	INV_NAME = 20,
	INV_NUM = 10,
	INV_DATE = 8,
	INV_CURRENCY = 3,
	INV_AMOUNT = 12
}FileNameAttributes;

typedef struct RowSections //invoice row info
{
	char name_Section			[INV_NAME		+ NULL_CHAR				];
	char invoice_Num_Section	[INV_NUM		+ NULL_CHAR				];
	char date_Section			[INV_DATE		+ NULL_CHAR				];
	char currency_Section		[INV_CURRENCY	+ NULL_CHAR				];
	char end_Amount_Section		[INV_AMOUNT		+ NEW_LINE	+ NULL_CHAR	];
	
}Row_Sec;

typedef struct Invoice
{
	char			rowCount	[ULLONG_MAX_LENGTH + NEW_LINE + NULL_CHAR];
	Row_Sec*		rows;
	int				vec_size;
	char			invoiceSum	[ULLONG_MAX_LENGTH + NULL_CHAR];
}Invoice;

static const char* currencies[] = { "BGN", "USD", "EUR", "RSD", "TND" };

Invoice*	Invoice_Data_init		(void);
void		vector_memFree			(Invoice* invoice);
void		struct_Row_Sec_Pushback	(Invoice* invoice, char* current_row_ptr);
void		struct_Header_Pushback	(Invoice* invoice, char* current_row_ptr);
void		struct_Footer_Pushback	(Invoice* invoice, char* current_row_ptr);

#endif // !STRUCT_INIT_H
