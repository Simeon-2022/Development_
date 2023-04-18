#ifndef FUNC_VFILENAMES_H
#define FUNC_VFILENAMES_H
#include <stdio.h>

//Rumi

typedef struct vecFileNames vecFileNames;

//Initialize the vector
void vecFileNames_init(vecFileNames* vec);

//Free dynamic memory for the vector
void vecFileNames_free(vecFileNames* vec);

//Search in the directory for files with the specified template and push back in vector valid files, sort the vector lexically
int isFillsNamesOfValidFiles(const char* strDirectory, vecFileNames* vec);

#endif // For FUNC_VFILENAMES_H
