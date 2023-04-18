#define _CRT_SECURE_NO_WARNINGS
#define W_FILE_NAME "\\IMPORT_INVOICES_????????_??????.txt"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <Windows.h>
#include <wchar.h> // input and output operations on wide streams
#include <tchar.h>
#include <time.h>
#include <stdbool.h>
#include "Struct_Init.h"
#include "File_Open.h"
#include "Date_Time.h"
#include "T_Valid.h"
#include "T_Process.h"

/*To start the program open command prompt and access the file directory
Example: D:\Documents\GitHub\C03-team-2-ivelina-mileva\Project_1\Project_1_CODIX
Next type in the arguments: Project_1_CODIX.exe D:\Documents\GitHub\C03-team-2-ivelina-mileva\Project_1\Project_1_CODIX\_Input split by a white space*/


int _tmain(int argc, TCHAR* argv[]) 
{
	//=====================================================================-Declare variables-=====================================================================//

	WIN32_FIND_DATA file_data;
	HANDLE h_find;
	TCHAR buffer[MAX_PATH];
	char current_dir_path[MAX_PATH];
	char file_data_file_Name_toChar[sizeof(W_FILE_NAME) - NULL_CHAR];

	if (argc != 2)
	{
		printf("Usage: %ls filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	_tcsncpy_s(buffer, MAX_PATH, argv[1], _tcslen(argv[1]));
	_tcscat_s(buffer, MAX_PATH, _T(W_FILE_NAME));

	//=====================================================================-FILE VALIDATION PROCESS START-=========================================================//

	h_find = FindFirstFile(buffer, &file_data);
	if (h_find != INVALID_HANDLE_VALUE)
	{
		file_process_(file_data_file_Name_toChar, &file_data, current_dir_path, buffer);

		while (FindNextFile(h_find, &file_data))
		{
			file_process_(file_data_file_Name_toChar, &file_data, current_dir_path, buffer);
		}
	}
	else
	{
		puts("No files found");
	}

	FindClose(h_find);

	return 0;
	//=====================================================================-FILE VALIDATION PROCESS END-==========================================================//
}

