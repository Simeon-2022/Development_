#ifndef OVERPAYMENTS_H
#define OVERPAYMENTS_H

void update_payments_with_invoices(const char *custExtRef);
int isExternalRefValid(const char* custExtRef);
void stringTrim(char* str);
#endif

