#include "../Headers/funcDirFileEdit.h"
#include "../Headers/funcErrorHandling.h"
#include "../Headers/funcDataValidation.h"
#include "../Headers/configMacro.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

//Rumi, Simo

//Rumi
//Creates a full path to the file - concat the directory name to the file name in char type.
//The function takes as arguments a const char pointer to a directory path, a const char pointer to a original filename,
//and a char pointer to the result of the concatenation
void concatFullPathToFile(const char* strDirectory, const char* strFileName, char* strResult)
{
	if ((strDirectory == NULL) || (strFileName == NULL))
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	strcpy(strResult, strDirectory);
	strcat(strResult, "/");
	strcat(strResult, strFileName);
}

//Creates directory in the given directory
//Function takes pointer to string with name of the existing directory, 
//pointer to string woth name of new directory and pointer to string where the new directory name will be stored
void createDirectory(const char* strMainDirectory, const char* newDirectoryName, char* newDirectory)
{
	if (strMainDirectory == NULL)
	{
		printf(ERR_FORMAT_6);
		return;
	}
	strcpy(newDirectory, strMainDirectory);
	strcat(newDirectory, newDirectoryName);
	if (access(newDirectory, F_OK) != 0)
	{
		if (mkdir(newDirectory, 0777) == -1)
		{
			printf(ERR_FORMAT_2);
		}
	}
}

//Creates file name
//Function takes pointer to main directory, type of the file and pointer to result string
//Function returns pointer to string with file name full path
void fileInit(const char* directory, char* filePath, const char* fileType)
{
	if ((directory == NULL) || (filePath == NULL) || (fileType == NULL))
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	char strTime[MAX_SIZE_DATETIME] = { 0 };
	stringDateAndTime(strTime, STR_DATA_FORMAT_1);
	strcpy(filePath, directory);
	strcat(filePath, "/");
	strcat(filePath, program.programName);
	strcat(filePath, fileType);
	strcat(filePath, strTime);
	strcat(filePath, ".txt");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//Simo
//Create files .OK and .KO
static void append_extension_KO_OK_(char* current_dir_path, const char* docType) {

	current_dir_path[strlen(current_dir_path) - strlen("txt")] = '\0';

	strcat(current_dir_path, docType);
}

FILE* fp_fileRead_(FILE* fp_, const char* strDirectory, const char* strFilename, const char* mode) {

	char current_dir_path[MAX_SIZE_FILEPATH] = { '\0' };
	concatFullPathToFile(strDirectory, strFilename, current_dir_path);

	fp_ = fopen(current_dir_path, mode);

	if (fp_ == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_10);
		exit(EXIT_FAILURE);
	}
	return fp_;
}

FILE* fp_fileWrite_OK_KO(FILE* fp_, char* strDirectory, const char* strFilename, const char* fileType, const char* mode) {

	char current_dir_path[MAX_SIZE_FILEPATH] = { '\0' };

	concatFullPathToFile(strDirectory, strFilename, current_dir_path);

	append_extension_KO_OK_(current_dir_path, fileType);

		fp_ = fopen(current_dir_path, mode);
		if (fp_ == NULL)
		{
			ERROR_PRINT(ERR_FORMAT_15);
			exit(EXIT_FAILURE);
		}

	return fp_;
}

int isLineEmpty(char* current_row_ptr) {

	if (current_row_ptr == NULL || current_row_ptr[0] == '\0')
	{
		return 1;
	}
	return 0;
}

char* readFileLine(FILE* fp_FROM) {

	char tempChar = 0;
	int rowCharCount = 0;
	int rowlength = MAX_LINE_CUSTOMER_LENGHT;
	char* temp_ptr = (char*)malloc(sizeof(char) * (size_t)(rowlength));

	temp_ptr[0] = '\0';

	while ((tempChar = fgetc(fp_FROM)) != '\n' && tempChar != EOF)
	{
		rowCharCount++;

		if (rowCharCount == rowlength)
		{
			temp_ptr = (char*)realloc(temp_ptr, (sizeof(char) * (size_t)(rowCharCount + 1))); // allocate memory to store char value
			if (temp_ptr == NULL)
			{
				ERROR_PRINT(ERR_FORMAT_7);
				free(temp_ptr);
			}
			rowlength += MAX_LINE_CUSTOMER_LENGHT;
		}

		temp_ptr[rowCharCount - 1] = tempChar;
	}
	if (temp_ptr[0] != '\0')
	{
		temp_ptr[rowCharCount - 1] = '\0';
	}

	return temp_ptr;
}

void moveReadFileToBackFolder(const char* strDirectory, const char* strFilename)
{

	struct stat filestat;
	char oldFileName[MAX_SIZE_FILEPATH] = { '\0' };
	char newFileName[MAX_SIZE_FILEPATH] = { '\0' };
	char newFileName2[MAX_SIZE_FILEPATH] = { '\0' };

	concatFullPathToFile(strDirectory, strFilename, oldFileName);
	snprintf(newFileName, MAX_SIZE_FILEPATH, "%s/%s", strDirectory, ".back");

	stat(newFileName, &filestat);
	if (!S_ISDIR(filestat.st_mode))
	{
		if (mkdir(newFileName, 0777) == -1)
		{
			ERROR_PRINT(ERR_FORMAT_2);
			return;
		}
	}

	snprintf(newFileName2, MAX_SIZE_FILEPATH, "%s/%s", newFileName, strFilename);
	if (rename(oldFileName, newFileName2) != 0)
	{
		ERROR_PRINT(ERR_FORMAT_16);
	};
}
