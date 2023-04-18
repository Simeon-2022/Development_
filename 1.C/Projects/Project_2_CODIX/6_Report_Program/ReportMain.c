#include "../7_Library/Headers/funcOpenCloseFile.h"
#include "../7_Library/Headers/funcErrorHandling.h"
#include "../7_Library/Headers/funcDataValidation.h"
#include "../7_Library/Headers/funcDirFileEdit.h"
#include "../7_Library/Headers/funcSql.h"
#include "../7_Library/Headers/funcReport.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int cUserChoice = 0;
    int  custID = 0;
    char strStartDate[MAX_DATE_LENGHT] = { 0 };
    char strEndDate[MAX_DATE_LENGHT] = { 0 };

    if (argc < 3)
    {
        printf("\nHELP: Not enough arguments.\nEnter \"client <customer_id>\" or \"period <start_date> <end_date>\"\nThe dates must have format \"DDMMYYYY\"\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 3)
    {
        if (!strcmp(argv[1], "client"))
        {
            custID = atoi(argv[2]);
            cUserChoice = 1;
        }
        else
        {
            printf("HELP: Enter \"client <customer_id>\" or \"period <start date> <end date>\"\nThe dates must have format \"DDMMYYYY\"\n");
            exit(EXIT_FAILURE);
        }
    }
    if (argc == 4)
    {
        if (!strcmp(argv[1], "period"))
        {
            if (!isDateValid(argv[2]) || !isDateValid(argv[3]))
            {
                printf("\nHELP: Enter \"client <customer_id>\" or \"period <start date> <end date>\"\nThe dates must have format \"DDMMYYYY\"\n");
                exit(EXIT_FAILURE);
            }
            strcpy(strStartDate, argv[2]);
            strcpy(strEndDate, argv[3]); 
            cUserChoice = 2;
        }
        else
        {
            printf("HELP: Enter \"client <customer_id>\" or \"period <start date> <end date>\"\nThe dates must have format \"DDMMYYYY\"\n");
            exit(EXIT_FAILURE);
        }
    }
    const char* strDirectory = "/media/sf_Shared/test_dir"; //Update for your Linux directory

    //Open Log and Error file
    program.programName = "PROG_REPORT";
    createDirectory(strDirectory, "/.LogAndErr", program.prDirectory);
    OUTPUT_LOG_MSG(program.programName, "Create directory /.LogErr");

    int isReported = 0;

    //Report in file
    if (cUserChoice == 1)
    {
         isReported = report_client(custID, strDirectory);
    }
    else if (cUserChoice == 2)
    {
        isReported = report_period(strStartDate, strEndDate, strDirectory);
    }

    if (isReported)
    {
        OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_2);
    }
    else
    {
        OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_13);
        ERROR_LOG_MSG(program.programName, ORA_MSG_FORMAT_13);
    }

    //Close files
    if (program.pOutputFile != NULL)
    {
	    fileClose(program.pOutputFile);
    }
    if (program.pErrFile != NULL)
    {
        fileClose(program.pErrFile);
    }

	printf("Done!\n");
    return 0;
}
