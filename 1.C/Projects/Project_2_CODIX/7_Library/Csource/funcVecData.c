#include "../Headers/funcVecData.h"
#include "../Headers/funcErrorHandling.h"
#include "../Headers/funcDataValidation.h"
#include "../Headers/funcDirFileEdit.h"
#include "../Headers/insertCustomer.h"
#include "../Headers/insertPayment.h"
#include "../Headers/insertInvoice.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

//Simo

static void sCustomerAttributes_init(sCustomer* customerRow) 
{
	customerRow->cpCustomerLineType[0] = '\0';
	customerRow->iInternCustRef = 0;
	customerRow->strExternCustRef[0] = '\0';
	customerRow->strFirstName[0] = '\0';
	customerRow->strLastName[0] = '\0';
	customerRow->cpGender[0] = '\0';
	customerRow->strCity[0] = '\0';
	customerRow->strCountry[0] = '\0';
	customerRow->iCreditLimit = 0;
	customerRow->strEmail[0] = '\0';
}
static void sInvoiceAttributes_init(sInvoice* invoiceRow) 
{
	invoiceRow->cpCurrency[0] = '\0';
	invoiceRow->cpInvoiceLineType[0] = '\0';
	invoiceRow->strExternInvoiceRef[0] = '\0';
	invoiceRow->dInvoiceAmt = 0.0;
	invoiceRow->strInvoiceDate[0] = '\0';
}
static void sPaymentAttributes_init(sPayment* paymentRow) 
{
	paymentRow->cpCurrency[0] = '\0';
	paymentRow->cpPaymentLineType[0] = '\0';
	paymentRow->strExternaymentRef[0] = '\0';
	paymentRow->dInvoiceAmt = 0.0;
	paymentRow->strPaymentDate[0] = '\0';
	paymentRow->strPaymentMethod[0] = '\0';
}

void fillCustomerData(sCustomer* customerRow, char* current_row_ptr)
{
	char* linePtr = current_row_ptr;
	int delimiterLen = (int)strlen(";");

	sCustomerAttributes_init(customerRow);

	if ((sscanf(linePtr, "%[^;\n];", customerRow->cpCustomerLineType) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(customerRow->cpCustomerLineType) + delimiterLen;
	char customerRowInternCustRef[MAX_INTERNAL_REF_LENGHT] = {'\0'};
	(sscanf(linePtr, "%[^;\n];", customerRowInternCustRef));
	
	customerRow->iInternCustRef = atoi(customerRowInternCustRef);

	linePtr += strlen(customerRowInternCustRef) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strExternCustRef) != 1)) 
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += strlen(customerRow->strExternCustRef) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strFirstName) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += strlen(customerRow->strFirstName) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strLastName) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += strlen(customerRow->strLastName) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->cpGender) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += strlen(customerRow->cpGender) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strCity) != 1))
	{
		if (customerRow->strCity[0] != '\0')
		{
			ERROR_PRINT(ERR_FORMAT_17);
			return;
		}
	}

	linePtr += strlen(customerRow->strCity) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strCountry) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += strlen(customerRow->strCountry) + delimiterLen;
	char customerCreditLimit[MAX_CREDIT_LIMIT_LENGHT];
	if ((sscanf(linePtr, "%[^;\n];", customerCreditLimit) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}
	customerRow->iCreditLimit = atoi(customerCreditLimit);
	linePtr += strlen(customerCreditLimit) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", customerRow->strEmail) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}
}
void fillInvoiceData(sInvoice* invoiceRow, char* current_row_ptr) 
{

	sInvoiceAttributes_init(invoiceRow);

	char* linePtr = current_row_ptr;
	int delimiterLen = (int)strlen(";");


	if ((sscanf(linePtr, "%[^;\n];", invoiceRow->cpInvoiceLineType) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(invoiceRow->cpInvoiceLineType) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", invoiceRow->strExternInvoiceRef) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(invoiceRow->strExternInvoiceRef) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", invoiceRow->strInvoiceDate) != 1)) 
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(invoiceRow->strInvoiceDate) + delimiterLen;
	char invoiceRowInvAmount[MAX_AMOUNT_LENGHT];
	if (sscanf(linePtr, "%[^;\n];", invoiceRowInvAmount) != 1)
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}
	invoiceRow->dInvoiceAmt = atof(invoiceRowInvAmount);

	linePtr += (int)strlen(invoiceRowInvAmount) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", invoiceRow->cpCurrency) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}
}
void fillPaymentData(sPayment* paymentRow, char* current_row_ptr) 
{
	sPaymentAttributes_init(paymentRow);
	char* linePtr = current_row_ptr;
	int delimiterLen = (int)strlen(";");

	if ((sscanf(linePtr, "%[^;\n];", paymentRow->cpPaymentLineType) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(paymentRow->cpPaymentLineType) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", paymentRow->strExternaymentRef) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(paymentRow->strExternaymentRef) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", paymentRow->strPaymentDate) != 1)) 
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(paymentRow->strPaymentDate) + delimiterLen;
	char paymentRowInvAmount[MAX_AMOUNT_LENGHT];
	if ((sscanf(linePtr, "%[^;\n];", paymentRowInvAmount) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	paymentRow->dInvoiceAmt = atof(paymentRowInvAmount);
	linePtr += (int)strlen(paymentRowInvAmount) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", paymentRow->strPaymentMethod) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}

	linePtr += (int)strlen(paymentRow->strPaymentMethod) + delimiterLen;
	if ((sscanf(linePtr, "%[^;\n];", paymentRow->cpCurrency) != 1))
	{
		ERROR_PRINT(ERR_FORMAT_17);
		return;
	}
}

void processFiles(const char* strFilename, const char* strDirectory)
{
	FILE* fp_READ = NULL;
	FILE* fp_WRITE_OK = NULL;
	FILE* fp_WRITE_KO = NULL;
	unsigned countRowsWRITE_OK = 0;
	unsigned countRowsWRITE_KO = 0;
	unsigned currentRowNumber = 0;

	sCustomer customer;
	sInvoice invoice;
	sPayment payment;

	char message[MAX_SIZE_LINE] = { '\0' };
	char strDirectory_OK_KO[MAX_SIZE_FILEPATH];
	createDirectory(strDirectory, "/.OK_KO", strDirectory_OK_KO);
	fp_READ = fp_fileRead_(fp_READ, strDirectory, strFilename, "r");
	OUTPUT_LOG_MSG(strFilename, MSG_FORMAT_1);
	while (!feof(fp_READ))
	{
		int isValid = 0;
		char* current_row_ptr = readFileLine(fp_READ);
		if (!isLineEmpty(current_row_ptr))
		{
			currentRowNumber++;
		}
		int typeOfLine = lineType_extractor_(current_row_ptr);
		if ((typeOfLine == LINE_CUSTOMER) && (validateCustomerLine(current_row_ptr))) 
		{
			fillCustomerData(&customer, current_row_ptr);
			isValid = 1;
			sprintf(message, "Extract line %d type 01 - Customer", currentRowNumber);
			OUTPUT_LOG_MSG(strFilename, message);
		}
		else if ((typeOfLine == LINE_INVOICE) && (validateInvoiceLine(current_row_ptr))) 
		{
			fillInvoiceData(&invoice, current_row_ptr);
			isValid = 1;
			sprintf(message, "Extract line %d type 02 - Invoice", currentRowNumber);
			OUTPUT_LOG_MSG(strFilename, message);
		}
		else if ((typeOfLine == LINE_PAYMENT) && (validatePaymentLine(current_row_ptr)))
		{
			fillPaymentData(&payment, current_row_ptr);
			isValid = 1;
			sprintf(message, "Extract line %d type 03 - Payment", currentRowNumber);
			OUTPUT_LOG_MSG(strFilename, message);
		}
		/*Import data to base*/
		int isInserted = 0;
		if (isValid)
		{
			switch (typeOfLine)
			{
			case LINE_CUSTOMER: isInserted = insertCustomer(&customer); break;
			case LINE_INVOICE:	isInserted = insertInvoice(&invoice); break;
			case LINE_PAYMENT:	isInserted = insertPayment(&payment); break;
			default: break;
			}
		}

		if (isInserted)
		{
			if (fp_WRITE_OK == NULL)
			{
				fp_WRITE_OK = fp_fileWrite_OK_KO(fp_WRITE_OK, strDirectory_OK_KO, strFilename, "ОК", "w");
			}
			countRowsWRITE_OK++;
			fprintf(fp_WRITE_OK, "line %hu: %s\n", currentRowNumber, current_row_ptr);
			OUTPUT_LOG_MSG(current_row_ptr, MSG_FORMAT_3); 
			OUTPUT_LOG_MSG(program.programName, "Print line in file .OK\n");
		}
		else if (!isLineEmpty(current_row_ptr))
		{
			if (fp_WRITE_KO == NULL)
			{
				fp_WRITE_KO = fp_fileWrite_OK_KO(fp_WRITE_KO, strDirectory_OK_KO, strFilename, "КО", "w");
			}
			countRowsWRITE_KO++;
			fprintf(fp_WRITE_KO, "line %hu: %s\n", currentRowNumber, current_row_ptr);
			ERROR_LOG_MSG(strFilename, MSG_FORMAT_4);
			sprintf(message, "line %hu: %s\n", currentRowNumber, current_row_ptr);
			ERROR_LOG_MSG("", message);
			OUTPUT_LOG_MSG(current_row_ptr, MSG_FORMAT_4);
			OUTPUT_LOG_MSG(program.programName, "Print line in file .KO\n");
		}
		free(current_row_ptr);
	}

	fclose(fp_READ);
	OUTPUT_LOG_MSG(strFilename, MSG_FORMAT_2);

	if (fp_WRITE_KO != NULL)
	{
		OUTPUT_LOG_MSG(program.programName, "Close file .OK");
		fclose(fp_WRITE_KO);
	}

	if (fp_WRITE_OK != NULL)
	{
		OUTPUT_LOG_MSG(program.programName, "Close file .KO");
		fclose(fp_WRITE_OK);
	}

	//Move file to .back
	moveReadFileToBackFolder(strDirectory, strFilename);
	OUTPUT_LOG_MSG(strFilename, "Move file to .back\n");


	sprintf(message, "%s have %hu row(s).", strFilename, currentRowNumber);
	OUTPUT_LOG_MSG(program.programName, message);
	sprintf(message, "%hu row(s) are processed and copied in file .OK.", countRowsWRITE_OK);
	OUTPUT_LOG_MSG(program.programName, message);
	if (countRowsWRITE_KO != 0)
	{
		sprintf(message, "%hu row(s) have mistakes and they are not inserted in the database. They are copied in file .KO", countRowsWRITE_KO);
		OUTPUT_LOG_MSG(program.programName, message);
	}
	fprintf(program.pOutputFile, "\n");
}
