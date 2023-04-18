#ifndef FUNC_DATAVALIDATION_H
#define FUNC_DATAVALIDATION_H

//Pancho, Simo, Rumi
int isDateValid(const char* idxPtr_to_fileName);

int fileNameValidate(const char* filename);

int lineType_extractor_(char* current_row_arrPtr);

int validateCustomerLine(const char* strCustomerLine);

int validateInvoiceLine(const char* strInvoiceLine);

int validatePaymentLine(const char* strPaymentLine);

//The function does validation on customer external refference
//The function takes pointer to string to user input
int isValidExtReff(char* strReff);

#endif //For FUNC_DATAANDFILENAMEVALIDATION_H
