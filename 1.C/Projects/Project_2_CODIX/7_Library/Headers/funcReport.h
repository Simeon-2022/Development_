#ifndef FUNC_REPORT_H
#define FUNC_REPORT_H
#include <stdio.h>

int report_client(int custID, const char* strDirectory);
int report_period(const char* strStartDate, const char* strEndDate, const char* strDirectory);

#endif
