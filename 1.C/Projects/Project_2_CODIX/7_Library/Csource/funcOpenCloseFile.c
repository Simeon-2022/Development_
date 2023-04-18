#include "../Headers/funcOpenCloseFile.h"
#include "../Headers/funcErrorHandling.h"

//Rumi

//Opens file or prints error otherwise.
//Function takes pointer to file name and pointer to the file access mode.
//Function returns pointer to the openned file at success, and NULL at failure.
FILE* fileOpen(const char* strFileName, char* mode)
{
	if (strFileName == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
	}
	FILE* pFile = NULL;
	if ((pFile = fopen(strFileName, mode)) == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_10);
	}
	return pFile;
}

//Close file or prints error otherwise.
//Function takes pointer to file.
void fileClose(FILE* pFile)
{
	if (pFile == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
	}
	if (fclose(pFile) != 0)
	{
		ERROR_PRINT(ERR_FORMAT_11);
	}
}
