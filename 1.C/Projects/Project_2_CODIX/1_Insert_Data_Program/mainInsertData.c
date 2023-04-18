#include "../7_Library/Headers/funcvecFileNames.h"
#include "../7_Library/Headers/funcErrorHandling.h"
#include "../7_Library/Headers/funcDirFileEdit.h"
#include "../7_Library/Headers/funcVecData.h"
#include "../7_Library/Headers/configMacro.h"
#include "../7_Library/Headers/funcSql.h"
#include <stdlib.h>
#include <stdio.h>

//Rumi

int main(int argc, char **argv)
{
	const char* strDirectory = MAIN_DIRECTORY;//Update for your Linux directory
	//Open Log and Error file
	program.programName = "PROG_INSERT_FILE";
	createDirectory(strDirectory, "/.LogAndErr", program.prDirectory);
	OUTPUT_LOG_MSG(program.programName, "Create directory .LogErr");

	//Initializes a vector that will hold the names of all files, matching the pattern.
	vecFileNames vectFNames;
	vecFileNames_init(&vectFNames);
	OUTPUT_LOG_MSG(program.programName, "Initialize a vector vecFilenames to hold the correct filenames");
	
	//Searches the directory for files with the specified pattern and pushes back valid files in vector
	if (!isFillsNamesOfValidFiles(strDirectory, &vectFNames))
	{
		ERROR_PRINT(ERR_FORMAT_4);
		exit(EXIT_FAILURE);
	}
	OUTPUT_LOG_MSG(program.programName, "Fill the vector vecFilenames");

	//connect to DB
	connect_oracle(USER_CONNECTION);

	//Loop that iterates through each file found.
	int index = 0;
	for (; index < vectFNames.size; index++)
	{
		//work with files
		processFiles(vectFNames.paFileName[index], strDirectory);
	}

	//Commit all transactions and release memory
	exec_commit_all();

	//Frees vector vecFileNames.
	vecFileNames_free(&vectFNames);
	OUTPUT_LOG_MSG(program.programName, "Free the vector vecFilenames");

	//Close Output and error logs
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