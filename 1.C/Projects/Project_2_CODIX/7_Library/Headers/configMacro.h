#ifndef CONFIGMACRO_H
#define CONFIGMACRO_H

//Rumi, Simo, Pancho

#define MAX_SIZE_FILENAME 45U
#define MAX_SIZE_FILEPATH 260U
#define MAX_SIZE_DATETIME 25
#define VEC_CAPACITY 10U
#define MAX_INTERNAL_REF_LENGHT 21
#define MAX_EXTERNAL_REF_LENGHT 61
#define MAX_NAME_LENGHT 61
#define MAX_CITY_LENGHT 51
#define MAX_COUNTRY_LENGHT 31
#define MAX_EMAIL_LENGHT 51
#define MAX_CREDIT_LIMIT_LENGHT 11
#define MAX_DATE_LENGHT 9
#define MAX_DATE_2_LENGHT 11
#define MAX_AMOUNT_LENGHT 14
#define MAX_PEYMENT_METOD_LENGHT 11
#define MAX_PEYMENT_ID_LENGHT 61
#define MAX_PEYMENT_IBAN_LENGHT 61
#define MAX_PEYMENT_CREATED_BY_LENGHT 51
#define MAX_PEYMENT_BANK_NAME_LENGHT 101
#define MAX_INVOICE_NUMBER_LENGHT 51
#define MAX_LINE_CUSTOMER_LENGHT 355
#define MAX_LINE_INVOICE_LENGHT 91
#define MAX_LINE_PAYMENT_LENGHT 104
#define MAX_LINE_LINETYPE_LENGHT 3
#define MAX_LINE_GENDER_LENGHT 2
#define MAX_LINE_CURRENCY_LENGHT 4
#define MAX_SIZE_LINE 1024
#define MAX_SIZE_NUMBER 10
#define MAX_DATE_LENGHT_REPORT 11
#define MAX_FILENAME_LENGTH 36

#define FILENAME_TEXT "IMP_CUSTOMER_DATA_"
#define STR_DATA_FORMAT_1 "%Y%m%d%H%M%S"
#define STR_DATA_FORMAT_2 "%d-%m-%Y %H:%M:%S"

#define MAIN_DIRECTORY "/media/sf_Shared/test_dir"

#define USER_CONNECTION "TEAM2/dbpass@83.228.124.173:6223/TEAM2"

typedef char vectData[MAX_SIZE_FILENAME];
typedef struct vecFileNames
{
	vectData* paFileName;
	unsigned size;
	unsigned capacity;
}vecFileNames;

typedef enum FileNameAttributes
{
	NULL_CHAR = 1,
	FILENAME_TEXT_LEN = 18,
	FILE_DATE_ = 8,
	FILE_TIME = 6,

}FileNameAttributes;

typedef enum LineType
{
	LINE_CUSTOMER = 1,
	LINE_INVOICE = 2,
	LINE_PAYMENT = 3
}LineType;

typedef struct sCustomer
{
	char cpCustomerLineType[MAX_LINE_LINETYPE_LENGHT];
	int iInternCustRef;
	char strExternCustRef[MAX_EXTERNAL_REF_LENGHT];
	char strFirstName[MAX_NAME_LENGHT];
	char strLastName[MAX_NAME_LENGHT];
	char cpGender[MAX_LINE_GENDER_LENGHT];
	char strCity[MAX_CITY_LENGHT];
	char strCountry[MAX_COUNTRY_LENGHT];
	int iCreditLimit;
	char strEmail[MAX_EMAIL_LENGHT];
}sCustomer;

typedef struct sInvoice
{
	char cpInvoiceLineType[MAX_LINE_LINETYPE_LENGHT];
	char strExternInvoiceRef[MAX_EXTERNAL_REF_LENGHT];
	char strInvoiceDate[MAX_DATE_LENGHT];
	double dInvoiceAmt;
	char cpCurrency[MAX_LINE_CURRENCY_LENGHT];
}sInvoice;

typedef struct sPayment
{
	char cpPaymentLineType[MAX_LINE_LINETYPE_LENGHT];
	char strExternaymentRef[MAX_EXTERNAL_REF_LENGHT];
	char strPaymentDate[MAX_DATE_LENGHT];
	double dInvoiceAmt;
	char strPaymentMethod[MAX_PEYMENT_METOD_LENGHT];
	char cpCurrency[MAX_LINE_CURRENCY_LENGHT];
}sPayment;

#endif
