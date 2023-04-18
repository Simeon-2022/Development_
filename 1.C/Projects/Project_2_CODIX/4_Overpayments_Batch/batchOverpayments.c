#include "../7_Library/Headers/funcOpenCloseFile.h"
#include "../7_Library/Headers/funcErrorHandling.h"
#include "../7_Library/Headers/funcDataValidation.h"
#include "../7_Library/Headers/funcDirFileEdit.h"
#include "../7_Library/Headers/Overpayments.h"
#include "../7_Library/Headers/funcSql.h"


#include <stdio.h>

int main(int argc, char *argv[])
{
    const char* strDirectory = MAIN_DIRECTORY; //update Linux directory

    program.programName = "BATCH_OVERPAYMENT";
    createDirectory(strDirectory, "/.LogAndErr", program.prDirectory);
    OUTPUT_LOG_MSG(program.programName, "Create directory .LogErr");

    connect_oracle(USER_CONNECTION);
	
    if (argc == 2)
    {
        update_payments_with_invoices(argv[1]);
    }
    else if (argc == 1)
    {
        char emptyArgInput[1] = { '\0' };
        update_payments_with_invoices(emptyArgInput);
    }

    exec_commit_all();

    OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_2);
    printf("%s - %s\n", program.programName, ORA_MSG_FORMAT_2);

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
