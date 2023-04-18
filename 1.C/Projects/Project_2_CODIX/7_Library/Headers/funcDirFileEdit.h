#ifndef FUNC_DIRFILEEDIT_H
#define FUNC_DIRFILEEDIT_H
#include <stdio.h>

//Rumi, Simo

//Rumi
//Creates a full path to the file - concat the directory name to the file name in char type.
//The function takes as arguments a const char pointer to a directory path, a const char pointer to a original filename,
//and a char pointer to the result of the concatenation
void concatFullPathToFile(const char* strDirectory, const char* strFileName, char* strResult);

//Creates directory in the given directory
//Function takes pointer to string with name of the existing directory, 
//pointer to string woth name of new directory and pointer to string where the new directory name will be stored
void createDirectory(const char* strMainDirectory, const char* newDirectoryName, char* newDirectory);

//Creates file name
//Function takes pointer to main directory, type of the file and pointer to result string
//Function returns pointer to string with file name full path
void fileInit(const char* directory, char* filePath, const char* fileType);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Simo

FILE* fp_fileRead_(FILE* fp_, const char* strDirectory, const char* strFilename, const char* mode);

FILE* fp_fileWrite_OK_KO(FILE* fp_, char* strDirectory, const char* strFilename, const char* fileType, const char* mode);

char* readFileLine(FILE* fp_FROM);

int isLineEmpty(char* current_row_ptr);

void moveReadFileToBackFolder(const char* strDirectory, const char* strFilename);


#endif //For FUNC_DIRFILEEDIT_H

