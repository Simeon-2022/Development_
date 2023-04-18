#include "../Headers/utility.h"
#include "../Headers/funcErrorHandling.h"
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

//Convert data Format sring from 'DD-MON-YY' to 'YYYYMMDD'
//Function takes pointer to string with original date in format 'DD-MON-YY'
void convertDateFormat(char* date) //'01-FEB-23'
{
    unsigned day = 0;
    unsigned month = 0;
    unsigned year = 0;
    char strMonth[5] = { 0 };
    sscanf(date, "%2d-%[^-]-%2d", &day, strMonth, &year);

    if (!strcmp(strMonth, "JAN")) { month = 1; }
    if (!strcmp(strMonth, "FEB")) { month = 2; }
    if (!strcmp(strMonth, "MAR")) { month = 3; }
    if (!strcmp(strMonth, "APR")) { month = 4; }
    if (!strcmp(strMonth, "MAY")) { month = 5; }
    if (!strcmp(strMonth, "JUN")) { month = 6; }
    if (!strcmp(strMonth, "JUL")) { month = 7; }
    if (!strcmp(strMonth, "AUG")) { month = 8; }
    if (!strcmp(strMonth, "SEP")) { month = 9; }
    if (!strcmp(strMonth, "OCT")) { month = 10; }
    if (!strcmp(strMonth, "NOV")) { month = 11; }
    if (!strcmp(strMonth, "DEC")) { month = 12; }

    year = 2000 + year;

    struct tm myDate = {
    myDate.tm_year = year - 1900,
    myDate.tm_mon = month - 1,
    myDate.tm_mday = day
    };

    strftime(date, 11, "%Y%m%d", &myDate);
}

//Adds addDayd to old Date and return new date
//Function takes pointer to start date, days to be add and pointer to string where result will be stored
void  addDaysToDate(char* oldDate, unsigned addDays, char* newDate)
{
    if (oldDate == NULL)
    {
        ERROR_PRINT(ERR_FORMAT_6);
    }
    unsigned day = 0;
    int month = 0;
    unsigned year = 0;
    sscanf(oldDate, "%4d%2d%2d", &year, &month, &day);

    struct tm myDate = {
    myDate.tm_year = year - 1900,
    myDate.tm_mon = month - 1,
    myDate.tm_mday = day
    };
    myDate.tm_mday += addDays;
    mktime(&myDate);
    strftime(newDate, 11, "%Y%m%d", &myDate);
}

//Function creates new invoice number 
//Function takes customer_id, max invoice seq + 1, string to new Issue day and pointer to string where result will be stored
void newInviceNo(int custID, int newSeq, char* newIssueDate, char* newInvNo)
{
    if (newIssueDate == NULL)
    {
        ERROR_PRINT(ERR_FORMAT_6);
    }
    char strInt[20];
    sprintf(strInt, "%d", custID);
    strcpy(newInvNo, strInt);
    strcat(newInvNo, "_");
    sprintf(strInt, "%d", newSeq);
    strcat(newInvNo, strInt);
    strcat(newInvNo, "_");
    strcat(newInvNo, newIssueDate);
}

void convertDateFormatToYYYYMMDD(char* date) //'01022023'
{
    if (date == NULL)
    {
        ERROR_PRINT(ERR_FORMAT_6);
    }
    unsigned day = 0;
    unsigned month = 0;
    unsigned year = 0;

    sscanf(date, "%2d%2d%4d", &day, &month, &year);

    struct tm myDate = {
    myDate.tm_year = year - 1900,
    myDate.tm_mon = month - 1,
    myDate.tm_mday = day
    };

    strftime(date, 9, "%Y%m%d", &myDate);
}

//Terminate string after data
//Function takes pointer to string that must be terminated
void nullTerminateString(char* string)
{
    if (string == NULL)
    {
        ERROR_PRINT(ERR_FORMAT_6);
    }
    char* iter = string;
    for (; *iter != '\0'; iter++)
    {
        if (*iter == ' ')
        {
            *iter = '\0';
            break;
        }
    }
}

void stringTrim(char* str) {
    int sizeStr = (int)strlen(str);
    int i = 0;
    for (; i < sizeStr; i++) {
        if (isblank(str[i]) || (str[i] == '\n')) {
            str[i] = '\0';
            break;
        }
    }
}


