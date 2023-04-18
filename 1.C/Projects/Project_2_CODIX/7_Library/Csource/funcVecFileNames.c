#include "../Headers/funcVecFileNames.h"
#include "../Headers/funcErrorHandling.h"
#include "../Headers/funcDataValidation.h"
#include "../Headers/funcDirFileEdit.h"
#include "../Headers/configMacro.h"
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//Rumi

//Initialize the vector vecFileNames. 
//Function takes a pointer to the vector vecFileNames.
void vecFileNames_init(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	vec->paFileName = NULL;
	vec->size = 0;
	vec->capacity = VEC_CAPACITY;
	vec->paFileName = (vectData*)malloc(sizeof(vectData) * vec->capacity);
	if (vec->paFileName == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_7);
		exit(EXIT_FAILURE);
	}
} 

//Free dynamic memory for the vector vecFileNames.
//Function takes a pointer to the vector vecFileNames.
void vecFileNames_free(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	vec->size = 0;
	vec->capacity = 0;
	free(vec->paFileName);
	vec->paFileName = NULL;
}

//Double the capacity of vector vecFileNames.
//Function takes pointer to vector vecFileNames.
static void vecFileNames_doubleCapacity(vecFileNames* vec)
{
	if (vec == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	if (vec->capacity <= 0)
	{
		vec->capacity = VEC_CAPACITY;
	}
	size_t newCapacity = vec->capacity * 2;
	vectData* newData = (vectData*)malloc(sizeof(vectData) * newCapacity);
	if (newData == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_7);
		return;
	}
	size_t i = 0;
	for (; i < vec->size; i++)
	{
		strcpy(newData[i], vec->paFileName[i]);
	}

	free(vec->paFileName);
	vec->paFileName = newData;
	vec->capacity = newCapacity;
}

//Push back filename in vector.
//Function takes pointer to vector vecFileNames and pointer to char string filename.
static void vecFileNames_pushBack(vecFileNames* vec, char* strFileName)
{
	if (vec == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return;
	}
	if (vec->size + 1 > vec->capacity)
	{
		vecFileNames_doubleCapacity(vec);
	}
	strcpy(vec->paFileName[vec->size++], strFileName);
}

//The function is used for predicate in qsort-function for compare filenames by date
//Function takes two void pointers to elements in the vector vecFileNames
//The function returns: - Negative value if array a appears before array b lexicographically.
//						- Zero if array a and array b compare equal.
//						- Positive value if array a appears after array b lexicographically.
static int compareStringsLexically(const void* a, const void* b)
{
	return strcmp(*(const vectData*)a, *(const vectData*)b);
}

//Search in the directory for files with the specified template, validate filename and push back in vector vecFileNames.
//Function takes pointer to the directory name and pointer to vector vecFileNames.
//Function returns TRUE if the directory consist valid files and FALSE otherwise.
int isFillsNamesOfValidFiles(const char* strDirectory, vecFileNames* vec)
{
	if ((strDirectory == NULL)||(vec == NULL))
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}

	DIR* pDir = opendir(strDirectory);
	struct dirent* struct_inputDir;
	struct stat struct_fileStatus;
	
	if (pDir)//todo
	{
		//Read directory entries
		while ((struct_inputDir = readdir(pDir)))
		{
			char buffer[MAX_SIZE_FILEPATH];
			concatFullPathToFile(strDirectory, struct_inputDir->d_name, buffer);
	
			stat(buffer, &struct_fileStatus);
			if (!S_ISDIR(struct_fileStatus.st_mode))
			{
				//Checks if the name of file is valid
				if (fileNameValidate(struct_inputDir->d_name))
				{
					//Pushes back the filename in the vector
					vecFileNames_pushBack(vec, struct_inputDir->d_name);
				}
			}
		}
		closedir(pDir);
	}
	else if (ENOENT == errno)
	{
		//The directory doesn't exist.
		ERROR_PRINT(ERR_FORMAT_1);
		return 0;
	}
	else
	{
		return 0;
	}
	if (vec->size == 0)
	{
		printf("vecFilenames is empty. There is no files with correct name in the directory!\n");
		OUTPUT_LOG_MSG(program.programName, "vecFilenames is empty. There is no files with correct name in the directory!");
		ERROR_LOG_MSG(program.programName, "vecFilenames is empty. There is no files with correct name in the directory!");
		return 0;
	}

	//Sorts vecFileNames ascending by date
	qsort(vec->paFileName, vec->size, sizeof(vectData), compareStringsLexically);
	return 1;
}
