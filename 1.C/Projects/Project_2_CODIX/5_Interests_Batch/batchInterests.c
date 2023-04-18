#include "../7_Library/Headers/funcOpenCloseFile.h"
#include "../7_Library/Headers/funcErrorHandling.h"
#include "../7_Library/Headers/funcDataValidation.h"
#include "../7_Library/Headers/funcDirFileEdit.h"
#include "../7_Library/Headers/funcSql.h"
#include "../7_Library/Headers/interests.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char strExtRef[MAX_EXTERNAL_REF_LENGHT] = { 0 };
    if (argc == 1)
    {
        strcpy(strExtRef, "");
    }
    if (argc == 2)  
    {
        if (isValidExtReff(argv[1]))
        {
            strcpy(strExtRef, argv[1]);
        }
        else
        {
            printf("Invalid external refference.The refference must begin with \"EXT\" and followed by numbers.\n");
            exit(EXIT_FAILURE);
        }
    }
    const char* strDirectory = MAIN_DIRECTORY; //Update for your Linux directory

    //Open Log and Error file
    program.programName = "PROG_INTERESTS";
    createDirectory(strDirectory, "/.LogAndErr", program.prDirectory);
    OUTPUT_LOG_MSG(program.programName, "Create directory .LogErr");

    connect_oracle(USER_CONNECTION);

    int isInserted = insertInterests(strExtRef);

    exec_commit_all();

    if (isInserted)
    {
        OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_2);
    }
    else
    {
        OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_13);
        ERROR_LOG_MSG(program.programName, ORA_MSG_FORMAT_13);
    }

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
