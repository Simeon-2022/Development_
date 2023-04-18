#ifndef FUNCVECDATA_H
#define FUNCVECDATA_H

//Simo

#include "configMacro.h"
#include <stdio.h>

void fillCustomerData(sCustomer* customerRow, char* current_row_ptr);
void fillInvoiceData(sInvoice* invoiceRow, char* current_row_ptr);
void fillPaymentData(sPayment* vec, char* current_row_ptr);

void processFiles(const char* strFilename, const char* strDirectory);

#endif // FUNCVECDATA_H
