#ifndef UTILITY_H
#define UTILITY_H



//Convert data Format sring from 'DD-MON-YY' to 'YYYYMMDD'
//Function takes pointer to string with original date in format 'DD-MON-YY'
void convertDateFormat(char* date);

void convertDateFormatToYYYYMMDD(char* date);

//Adds addDayd to old Date and return new date
//Function takes pointer to start date, days to be add and pointer to string where result will be stored
void  addDaysToDate(char* oldDate, unsigned addDays, char* newDate);

//Function creates new invoice number 
//Function takes customer_id, max invoice seq + 1, string to new Issue day and pointer to string where result will be stored
void newInviceNo(int custID, int newSeq, char* newIssueDate, char* newInvNo);

//Terminate string after data
//Function takes pointer to string that must be terminated
void nullTerminateString(char* string);

void stringTrim(char* str);





#endif
