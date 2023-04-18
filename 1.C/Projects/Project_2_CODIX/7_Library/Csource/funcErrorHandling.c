#include "../Headers/funcErrorHandling.h"
#include "../Headers/funcDirFileEdit.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

//Rumi

//Returns char* formatted string to current time
//Function takes pointer to string where the current time will be stored and date format
char* stringDateAndTime(char* strTime, const char* format)
{
	if (format == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
	}
	time_t t = time(NULL);
    struct tm* buf = gmtime(&t);
	buf->tm_hour = buf->tm_hour + 1;
	mktime(buf);
	strftime(strTime, MAX_SIZE_DATETIME, format, buf);
	return strTime;
}
	 
//Creates and opens output log file
void outputLogFileInit(void)
{
	char filePath[MAX_SIZE_FILEPATH];
	char strTime[MAX_SIZE_DATETIME] = { 0 };
	stringDateAndTime(strTime, STR_DATA_FORMAT_1);
	strcpy(filePath, program.prDirectory);
	strcat(filePath, "/");
	strcat(filePath, program.programName);
	strcat(filePath, "_OUTPUT_LOG_");
	strcat(filePath, strTime);
	strcat(filePath, ".txt");
	program.pOutputFile = fileOpen(filePath, "w");

}

//Creates and opens error log file
void errorLogFileInit(void)
{
	char filePath[MAX_SIZE_FILEPATH];
	char strTime[MAX_SIZE_DATETIME] = { 0 };
	stringDateAndTime(strTime, STR_DATA_FORMAT_1);
	strcpy(filePath, program.prDirectory);
	strcat(filePath, "/");
	strcat(filePath, program.programName);
	strcat(filePath, "_ERROR_LOG_");
	strcat(filePath, strTime);
	strcat(filePath, ".txt");
	program.pErrFile = fileOpen(filePath, "w");
}

