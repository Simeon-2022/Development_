#ifndef FUNC_ERRORHANDLING_H
#define FUNC_ERRORHANDLING_H
#include "../Headers/funcOpenCloseFile.h"
#include "../Headers/configMacro.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

//Rumi

typedef struct LogErr
{
	char* programName;
	char  prDirectory[MAX_SIZE_FILEPATH];
	FILE* pOutputFile;
	FILE* pErrFile;
} LogErr;
LogErr program;


//List with system errors:
#define ERR_FORMAT_1 "The directory does not exist!"
#define ERR_FORMAT_2 "Error in creating directory!"
#define ERR_FORMAT_3 "Error with seeking in directory!"
#define ERR_FORMAT_4 "There is no file with this pattern in the directory!"
#define ERR_FORMAT_5 "Pointer to structs is lost!"
#define ERR_FORMAT_6 "NULL pointer!"
#define ERR_FORMAT_7 "Cannot alocate memory!"
#define ERR_FORMAT_8 "Error in openning output log file!"
#define ERR_FORMAT_9 "Error in openning error log file!"
#define ERR_FORMAT_10 "Error in openning file!"
#define ERR_FORMAT_11 "Error in clossing file!"
#define ERR_FORMAT_12 "Error in renaming file!"
#define ERR_FORMAT_13 "Invalid reposition of file pointer!"
#define ERR_FORMAT_14 "File path array size overflow!"
#define ERR_FORMAT_15 "Error in writing file!"
#define ERR_FORMAT_16 "Error in moving file!"
#define ERR_FORMAT_17 "Error in saving data!"
#define ERR_FORMAT_18 "String size overflow!"
#define ERR_FORMAT_19 ""
#define ERR_FORMAT_20 ""

//List with massages:
#define MSG_FORMAT_1 "Open file"
#define MSG_FORMAT_2 "Close file"
#define MSG_FORMAT_3 "Line is IMPORTED!"
#define MSG_FORMAT_4 "Line is NOT IMPORTED!"
#define MSG_FORMAT_6 "..."

//List with errors for oracle programs:
#define ORA_ERR_FORMAT_1 "Error during connection!"
#define ORA_ERR_FORMAT_2 "Error during creation of table!"
#define ORA_ERR_FORMAT_3 "Error during dropping table!"
#define ORA_ERR_FORMAT_4 "Error during commiting!"
#define ORA_ERR_FORMAT_5 "Error during inserting!"
#define ORA_ERR_FORMAT_6 "Error during deleteng record!"
#define ORA_ERR_FORMAT_7 "Error during selection!"
#define ORA_ERR_FORMAT_8 "Error during oppening cursor!"
#define ORA_ERR_FORMAT_9 "Error during closing cursor!"
#define ORA_ERR_FORMAT_10 "Error during fetching cursor!"
#define ORA_ERR_FORMAT_11 "Error during updating!"
#define ORA_ERR_FORMAT_12 "Incorrect invoice. Customer does not exist!"

//List with massages for oracle programs:
#define ORA_MSG_FORMAT_1 "Program started!"
#define ORA_MSG_FORMAT_2 "Program executed successfully!"
#define ORA_MSG_FORMAT_3 "Connected to DB\n"
#define ORA_MSG_FORMAT_4 "Table created"
#define ORA_MSG_FORMAT_5 "Table dropped"
#define ORA_MSG_FORMAT_6 "Commit transaction"
#define ORA_MSG_FORMAT_7 "Commit work release"
#define ORA_MSG_FORMAT_8 "Record inserted"
#define ORA_MSG_FORMAT_9 "Record deleted"
#define ORA_MSG_FORMAT_10 "Successfull selection"
#define ORA_MSG_FORMAT_11 "Open cursor"
#define ORA_MSG_FORMAT_12 "Close cursor"
#define ORA_MSG_FORMAT_13 "Program did not execute successfully!"

//Returns char* formatted string to current time
//Function takes pointer to string where the current time will be stored
char* stringDateAndTime(char* strTime, const char* format);

//Creates and opens output log file
void outputLogFileInit(void);

//Creates and opens error log file
void errorLogFileInit(void);

//Prints system errors in error log file in hidden directory .LogAndErr in main directory
//Takes X - errno from last error and ERR_FORMAT - string from list with system errors
#define ERROR_PRINT(ERR_FORMAT)	{\
										if (program.pErrFile == NULL)\
										{\
											errorLogFileInit();\
										}\
										char strTime[MAX_SIZE_DATETIME] = { 0 };\
										stringDateAndTime(strTime, STR_DATA_FORMAT_2);\
										fprintf(program.pErrFile, "[ERROR][%s] %s ", strTime, ERR_FORMAT);\
										fprintf(program.pErrFile, "\t(Error code %d - %s)\n", errno, strerror(errno));\
										fprintf(program.pErrFile, "\tError in line %d in file %s\n", __LINE__, __FILE__);\
				  					}


//Prints massage in the error log file
//Function takes pointers to two strings
#define ERROR_LOG_MSG(FILENAME, MSG_FORMAT) {\
												if (program.pErrFile == NULL)\
												{\
													errorLogFileInit();\
												}\
												char strTime[MAX_SIZE_DATETIME] = { 0 };\
												stringDateAndTime(strTime, STR_DATA_FORMAT_2);\
												fprintf(program.pErrFile, "[ERROR][%s] %s: %s\n", strTime, FILENAME, MSG_FORMAT);\
											}


//Prints massage in the output log file
//Function takes pointers to two strings
#define OUTPUT_LOG_MSG(FILENAME, MSG_FORMAT) {\
												if (program.pOutputFile == NULL)\
												{\
													outputLogFileInit();\
												}\
												char strTime[MAX_SIZE_DATETIME] = { 0 };\
												stringDateAndTime(strTime, STR_DATA_FORMAT_2);\
												fprintf(program.pOutputFile, "[%s] %s: %s\n", strTime, FILENAME, MSG_FORMAT);\
											 }

#endif /*For FUNC_ERRORHANDLING_H*/
