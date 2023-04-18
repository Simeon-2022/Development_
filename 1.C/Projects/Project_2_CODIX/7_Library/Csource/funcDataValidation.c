#include "../Headers/funcDataValidation.h"
#include "../Headers/funcErrorHandling.h"
#include "../Headers/configMacro.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

//Pancho, Simo, Rumi

static const char* apGender[2] = { "f", "m" };
static const char* apCurrency[1] = { "BGN" };
static const char* apLineType[3] = { "01","02","03" };


static double dateDifference(int day, int month, int year)
{
	struct tm file_time_entry = {
	.tm_mday = day,
	.tm_mon = month - 1,
	.tm_year = year - 1900,
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 0,
	.tm_isdst = 0,
	.tm_yday = 0,
	.tm_wday = 0 };

	time_t t = time(NULL);
	struct tm time_entry_current = *localtime(&t);
	time_entry_current.tm_sec = 0;
	time_entry_current.tm_min = 0;
	time_entry_current.tm_hour = 0;
	time_entry_current.tm_isdst = 0;
	time_entry_current.tm_yday = 0;
	time_entry_current.tm_wday = 0;

	time_t time_to_seconds_Begin = mktime(&file_time_entry);
	time_t time_to_seconds_End = mktime(&time_entry_current);

	if (time_to_seconds_Begin < 0)
	{
		return -1;
	}

	return difftime(time_to_seconds_End, time_to_seconds_Begin);
}

int isDateValid(const char* idxPtr_to_fileName)
{

	int year = 0, month = 0, day = 0;
	char file_name_date[FILE_DATE_ + NULL_CHAR] = { '\0' };

	memcpy(file_name_date, idxPtr_to_fileName, FILE_DATE_);

	if (strlen(file_name_date) != 8)
	{
		return 0;
	}
	int i = 0;
	for (; file_name_date[i] != '\0'; i++)
	{
		if (!isdigit(file_name_date[i]))
		{
			return 0;
		}
	}

	int result = sscanf(file_name_date, "%2d%2d%4d", &day, &month, &year);

	if (result == EOF) {
		ERROR_PRINT("sscanf failed");
		return 0;
	}

	if (year < 1900 || (month < 1 || month > 12) || (day < 1 || day > 31))
	{
		return 0;
	}

	if (day == 29 && month == 2)
	{
		if (year % 4 != 0)
		{
			return 0;
		}
		if (year % 100 == 0 && year % 400 != 0)
		{
			return 0;
		}
	}
	else if (day > 29 && month == 2)
	{
		return 0;
	}
	else if ((day == 31) && (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12))
	{
		return 0;
	}

	if (dateDifference(day, month, year) < 0)// check if future date
	{
		return 0;
	}
	return 1;
}

static int isValidName(const char* strName)
{
	if (strName == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strName); // - \0
	if (szLen <= 0 && szLen > MAX_NAME_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if (!isalpha(*strName) || !isalpha(*(strName + szLen - 1)))
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in name!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in name!");
		return 0;
	}
	for (; *strName; strName++)
	{
		if (!isalpha(*strName) && *strName != '-')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in name!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in name!");
			return 0;
		}
	}
	return 1;
}

static int isValidGender(const char* strGender)
{
	if (strGender == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strGender);
	if (szLen <= 0 && szLen > MAX_LINE_GENDER_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if ((strcmp(strGender, apGender[0]) != 0) && (strcmp(strGender, apGender[1]) != 0))
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Not matched gender!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Not matched gender!");
		return 0;
	}
	return 1;
}

static int isValidCity(const char* strCity)
{
	if (strCity == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strCity); // - \0

	if (szLen == 0)
	{
		return 1;
	}

	if (szLen > MAX_CITY_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if (!isalpha(*strCity) || !isalpha(*(strCity + szLen - 1)))
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in city!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in city!");
		return 0;
	}
	for (; *strCity; strCity++)
	{
		if (!isalpha(*strCity) && *strCity != ' ')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in city!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in city!");
			return 0;
		}
	}

	return 1;
}

static int isValidCountry(const char* strCountry)
{
	if (strCountry == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strCountry); // - \0
	if (szLen <= 0 && szLen > MAX_COUNTRY_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if (!isalpha(*strCountry) || !isalpha(*(strCountry + szLen - 1)))
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in country!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in country!");
		return 0;
	}
	for (; *strCountry; strCountry++)
	{
		if (!isalpha(*strCountry) && *strCountry != ' ')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in country!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in country!");
			return 0;
		}
	}
	return 1;
}

static int isValidCreditLimit(const char* strCreditLimit)
{
	if (strCreditLimit == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strCreditLimit); // - \0
	if (szLen <= 0 && szLen > MAX_CREDIT_LIMIT_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	for (; *strCreditLimit; strCreditLimit++)
	{
		if (!isdigit(*strCreditLimit))
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in credit limit!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in credit limit!");
			return 0;
		}
	}
	return 1;
}

static int isValidExtRef(const char* strExtRef)
{
	if (strExtRef == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strExtRef);

	if (szLen <= 0 && szLen > MAX_EXTERNAL_REF_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}

	const char* pcExtRefBegin = "EXT";

	if (strncmp(strExtRef, pcExtRefBegin, 3) != 0)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid string prefix (EXT)!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid string prefix (EXT)!");
		return 0;
	}
	int i = 3;
	for (; i < szLen; i++)
	{
		if (!isdigit(strExtRef[i]))
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid string format after EXT!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid string format after EXT!");
			return 0;
		}
	}
	return 1;
}

static int isValidIntRef(const char* strIntRef)
{
	if (strIntRef == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}

	size_t szLen = strlen(strIntRef);

	if (szLen == 0)
	{
		return 1;
	}

	if (szLen > MAX_INTERNAL_REF_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}

	for (; *strIntRef; strIntRef++)
	{
		if (!isdigit(*strIntRef))
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in IntRef!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character in IntRef!");
			return 0;
		}
	}
	return 1;
}

static int isValidCurrency(const char* strCurrency)
{
	if (strCurrency == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strCurrency);
	if (szLen <= 0 && szLen > MAX_LINE_CURRENCY_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if (strcmp(strCurrency, apCurrency[0]) != 0)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Isn't valid currency!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Isn't valid currency!");
		return 0;
	}
	return 1;
}

static int isValidSum(const char* strSum)
{
	if (strSum == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strSum);

	if (szLen <= 0 && szLen > MAX_AMOUNT_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	int iDotsCounter = 0;
	int i = 0;
	for (; i < szLen; i++)
	{
		if (!isdigit(strSum[i]))
		{
			if (strSum[i] == '.' && iDotsCounter < 1)
			{
				iDotsCounter++;

				if (i > 10 || szLen - i > 3) //max digits before "." are 10 and max digits after "." are 2
				{
					OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid decimal part!");
					ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid decimal part!");
					return 0;
				}
			}
			else
			{
				OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid decimal part!");
				ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid decimal part!");
				return 0;
			}
		}
	}

	if (iDotsCounter == 0 && szLen > 10)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character!");
		return 0;
	}
	return 1;
}

static int isValidPaymentMethod(const char* strPaymentMethod)
{
	if (strPaymentMethod == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	size_t szLen = strlen(strPaymentMethod);

	if (szLen <= 0 && szLen > MAX_PEYMENT_METOD_LENGHT)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	for (; *strPaymentMethod; strPaymentMethod++)
	{
		if (*strPaymentMethod == ';')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Contains wrong character!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Contains wrong character!");
			return 0;
		}
	}
	return 1;
}

//static int isValidEmail(const char* strEmail)
//{
//	size_t szLen = strlen(strEmail);
//	int iPosOfAt = 0;
//	int iAtCounter = 0;
//	int iDotCounter = 0;
//
//	if (strEmail == NULL)
//	{
//		ERROR_PRINT(ERR_FORMAT_6);
//		return 0;
//	}
//	if (szLen < 5 && szLen > MAX_EMAIL_LENGHT) // email need to be at least 5 characters
//	{
//		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
//		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
//		return 0;
//	}
//	if (strEmail[0] == '.' || strEmail[szLen - 1] == '.' || strEmail[0] == '@' || strEmail[szLen - 1] == '@')
//	{
//		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		return 0;
//	}
//	if (isdigit(strEmail[0]) != 0)
//	{
//		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		return 0;
//	}
//	int i = 0;
//	for (; i < szLen; i++)
//	{
//		if (strEmail[i] == ';')
//		{
//			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			return 0;
//		}
//		if (strEmail[i] == '@')
//		{
//			iAtCounter++;
//		}
//		if (iAtCounter > 1)
//		{
//			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			return 0;
//		}
//		iPosOfAt = i;
//	}
//	if (iAtCounter <= 0)
//	{
//		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//		return 0;
//	}
//	i = 0;
//	for (; i < szLen; i++)
//	{
//		if (strEmail[i] == '.' && strEmail[i + 1] == '.')
//		{
//			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			return 0;
//		}
//	}
//	i = iPosOfAt;
//	for (; i < szLen; i++)
//	{
//		if (strEmail[iPosOfAt + 1] == '.')
//		{
//			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//			return 0;
//		}
//		if (strEmail[i] == '.')
//		{
//			iDotCounter++;
//			if (iDotCounter > 1)
//			{
//				OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//				ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
//				return 0;
//			}
//		}
//	}
//	return 1;
//}

static int isValidEmail(const char* strEmail)
{
	size_t szLen = strlen(strEmail);
	int iPosOfAt = 0;
	int iAtCounter = 0;
	int iDotCounter = 0;

	if (strEmail == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	if (szLen < 5 && szLen > MAX_EMAIL_LENGHT) // email need to be at least 5 characters
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		ERROR_LOG_MSG(MSG_FORMAT_4, ERR_FORMAT_18);
		return 0;
	}
	if (strEmail[0] == '.' || strEmail[szLen - 1] == '.' || strEmail[0] == '@' || strEmail[szLen - 1] == '@')
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		return 0;
	}
	if (isdigit(strEmail[0]) != 0)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		return 0;
	}
	int i = 0;
	for (; i < szLen; i++)
	{
		if (strEmail[i] == ';')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			return 0;
		}
		if (strEmail[i] == '@')
		{
			iAtCounter++;
			iPosOfAt = i;
		}
		if (iAtCounter > 1)
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			return 0;
		}

	}
	if (iAtCounter <= 0)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		return 0;
	}
	i = 0;
	for (; i < szLen; i++)
	{
		if (strEmail[i] == '.' && strEmail[i + 1] == '.')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			return 0;
		}
	}
	i = iPosOfAt;
	for (; i < szLen; i++)
	{
		if (strEmail[iPosOfAt + 1] == '.')
		{
			OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
			return 0;
		}
		if (strEmail[i] == '.')
		{
			iDotCounter++;
			if (iDotCounter > 1)
			{
				OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
				ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
				return 0;
			}
		}
	}
	if (iDotCounter == 0)
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Incorrect email syntax!");
		return 0;
	}
	return 1;
}

static int isValidTypeCustomerLine(const char* strTypeCustomerLine)
{
	if (strTypeCustomerLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	if (strcmp(strTypeCustomerLine, apLineType[0]) == 0)
	{
		return 1;
	}
	else
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		return 0;
	}
}

static int isValidTypeInvoiceLine(const char* strTypeInvoiceLine)
{
	if (strTypeInvoiceLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	if (strcmp(strTypeInvoiceLine, apLineType[1]) == 0)
	{
		return 1;
	}
	else
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		return 0;
	}
}

static int isValidTypePaymentLine(const char* strTypePaymentLine)
{
	if (strTypePaymentLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}
	if (strcmp(strTypePaymentLine, apLineType[2]) == 0)
	{
		return 1;
	}
	else
	{
		OUTPUT_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		ERROR_LOG_MSG(MSG_FORMAT_4, "Invalid Line Type!");
		return 0;
	}
}

static char* findNumberIdx(const char* file_Name_, int length)
{
	const char* file_Name_Ptr = file_Name_;
	for (; file_Name_Ptr < file_Name_ + length; file_Name_Ptr++)
	{
		if (isdigit(*file_Name_Ptr))
		{
			return (char*)file_Name_Ptr;
		}
	}
	return NULL;
}

static int dateStampValidator(const char* idxPtr_to_fileName) {

	int year = 0, month = 0, day = 0;
	char file_name_date[FILE_DATE_ + NULL_CHAR] = { '\0' };

	memcpy(file_name_date, idxPtr_to_fileName, FILE_DATE_);

	if (strlen(file_name_date) != 8)
	{
		return 0;
	}
	int i = 0;
	for (; file_name_date[i] != '\0'; i++)
	{
		if (!isdigit(file_name_date[i]))
		{
			return 0;
		}
	}

	int result = sscanf(file_name_date, "%4d%2d%2d", &year, &month, &day);

	if (result == EOF) {
		//printf("sscanf failed\n");
		return 0;
	}

	if (year < 1900 || (month < 1 || month > 12) || (day < 1 || day > 31))
	{
		return 0;
	}

	if (day == 29 && month == 2)
	{
		if (year % 4 != 0)
		{
			return 0;
		}
		if (year % 100 == 0 && year % 400 != 0)
		{
			return 0;
		}
	}
	else if (day > 29 && month == 2)
	{
		return 0;
	}
	else if (day == 31 && (month != 1 || month != 3 || month != 5 || month != 7 || month != 8 || month != 10 || month != 12))
	{
		return 0;
	}

	if (dateDifference(day, month, year) < 0)// check if future date
	{
		return 0;
	}

	return 1;
}

static int timeStampValidate(const char* idxPtr_to_fileName) {

	char file_name_time[FILE_TIME + NULL_CHAR] = { '\0' };
	int hour = 0, min = 0, sec = 0;

	memcpy(file_name_time, idxPtr_to_fileName + FILE_DATE_, FILE_TIME);
	int i = 0;
	for (; file_name_time[i] != '\0'; i++)
	{
		if (!isdigit(file_name_time[i]))
		{
			return 0;
		}
	}

	int result = sscanf(file_name_time, "%2d%2d%2d", &hour, &min, &sec);

	if (result == EOF) {
		return 0;
	}

	if (hour > 23 || min > 59 || sec > 59)
	{
		return 0;
	}
	return 1;
}

static int dateTimeStampValidate(const char* idxPtr_to_fileName) {

	return (dateStampValidator(idxPtr_to_fileName) && timeStampValidate(idxPtr_to_fileName)) ? 1 : 0;
}

static int fileNameTextValidate(const char* filename) {

	return strncmp(filename, FILENAME_TEXT, FILENAME_TEXT_LEN) ? 0 : 1;
}

int fileNameValidate(const char* filename) 
{

	if (strlen(filename) > MAX_FILENAME_LENGTH)
	{
		return 0;
	}

	if (!fileNameTextValidate(filename))
	{
		return 0;
	}
	char* idxPtr_to_fileDate = NULL;
	idxPtr_to_fileDate = findNumberIdx(filename, strlen(filename)); // Find index of the first number in string

	return dateTimeStampValidate(idxPtr_to_fileDate)? 1:0;

}

int lineType_extractor_(char* current_row_arrPtr) 
{
	char lineType[4] = { '\0' };

	int lineTypeToNum = 0;

	if (sscanf(current_row_arrPtr, "%3s", lineType) == 0)
	{
		return -1;
	}
	if (lineType[2] != ';')
	{
		return -1;
	}

	return lineTypeToNum = atoi(current_row_arrPtr);
}

int validateCustomerLine(const char* strCustomerLine)
{
	if (strCustomerLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}

	int iFieldCounter = 0;

	//Copy line 
	char* newMemory = (char*)malloc((strlen(strCustomerLine) + 1) * sizeof(char));
	char* cpFieldStart = newMemory;
	if (cpFieldStart == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_7);
		return 0;
	}
	strcpy(cpFieldStart, strCustomerLine);

	char* cpFieldEnd = strchr(cpFieldStart, ';');
	char* cur_word = NULL;

	while (cpFieldStart != NULL)
	{
		if (cpFieldEnd > cpFieldStart)
		{
			*cpFieldEnd = '\0';
			cur_word = cpFieldStart;
		}
		else
		{
			cur_word = "";
			if (cpFieldEnd == NULL)
			{
				cur_word = cpFieldStart;
			}
		}
		if (cpFieldEnd != NULL)
		{
			cpFieldStart = cpFieldEnd + 1;
		}

		iFieldCounter++;

		switch (iFieldCounter)
		{
		case 1: if (!isValidTypeCustomerLine(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 2:	if (!isValidIntRef(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';');	break;
		case 3:	if (!isValidExtRef(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 4:	if (!isValidName(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 5: if (!isValidName(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 6:	if (!isValidGender(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 7:	if (!isValidCity(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 8:	if (!isValidCountry(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 9:	if (!isValidCreditLimit(cur_word)) { free(newMemory); return 0; } cpFieldEnd = strchr(cpFieldStart, ';'); break;
		case 10:if (!isValidEmail(cur_word)) { free(newMemory); return 0; }
			   if (cpFieldEnd == NULL) { free(newMemory); return 1; }
			   else if (*(cpFieldStart) == '\0') { free(newMemory); return 1; }
			   else { free(newMemory); return 0; } break;
		default: break;
		}
	}
	free(newMemory);
	return 1;
}

int validateInvoiceLine(const char* strInvoiceLine)
{
	if (strInvoiceLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}

	int iFieldCounter = 0;

	//Copy line 
	char* newMemory = (char*)malloc((strlen(strInvoiceLine) + 1) * sizeof(char));
	char* cpFieldStart = newMemory;
	if (cpFieldStart == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_7);
		return 0;
	}
	strcpy(cpFieldStart, strInvoiceLine);

	char* cpToken = strtok(cpFieldStart, ";");

	while (cpToken != NULL)
	{
		iFieldCounter++;

		switch (iFieldCounter)
		{
		case 1: if (!isValidTypeInvoiceLine(cpToken)) { free(newMemory);   return 0; }; cpToken = strtok(NULL, ";"); break;
		case 2: if (!isValidExtRef(cpToken)) { free(newMemory);   return 0; }; cpToken = strtok(NULL, ";");  break;
		case 3: if (!isDateValid(cpToken)) { free(newMemory);   return 0; }; cpToken = strtok(NULL, ";");  break;
		case 4: if (!isValidSum(cpToken)) { free(newMemory);  return 0; }; cpToken = strtok(NULL, ";");  break;
		case 5: if (!isValidCurrency(cpToken)) { free(newMemory); return 0; }; cpToken = strtok(NULL, ";");  break;
		default:break;
		}
	}
	if (iFieldCounter != 5) { free(newMemory); return 0; }
	free(newMemory);
	return 1;
}

int validatePaymentLine(const char* strPaymentLine)
{
	if (strPaymentLine == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_6);
		return 0;
	}

	//Copy line 
	char* newMemory = (char*)malloc((strlen(strPaymentLine) + 1) * sizeof(char));
	char* cpFieldStart = newMemory;
	if (cpFieldStart == NULL)
	{
		ERROR_PRINT(ERR_FORMAT_7);
		return 0;
	}
	strcpy(cpFieldStart, strPaymentLine);

	int iFieldCounter = 0;
	char* cpToken = strtok(cpFieldStart, ";");

	while (cpToken != NULL)
	{
		iFieldCounter++;

		switch (iFieldCounter)
		{
		case 1: if (!isValidTypePaymentLine(cpToken)) { free(newMemory);  return 0; }; cpToken = strtok(NULL, ";"); break;
		case 2: if (!isValidExtRef(cpToken)) { free(newMemory);  return 0; }; cpToken = strtok(NULL, ";");  break;
		case 3: if (!isDateValid(cpToken)) { free(newMemory);  return 0; }; cpToken = strtok(NULL, ";");  break;
		case 4: if (!isValidSum(cpToken)) { free(newMemory);  return 0; }; cpToken = strtok(NULL, ";");  break;
		case 5: if (!isValidPaymentMethod(cpToken)) { free(newMemory); return 0; }; cpToken = strtok(NULL, ";");  break;
		case 6: if (!isValidCurrency(cpToken)) { free(newMemory); return 0; }; cpToken = strtok(NULL, ";");  break;
		default:break;
		}
	}
	if (iFieldCounter != 6) { free(newMemory); return 0; }
	free(newMemory);
	return 1;
}

//The function does validation on customer external refference
//The function takes pointer to string to user input
int isValidExtReff(char* strReff)
{
	int i = 0;
	int icountNumbers = 0;
	for (; i != 3; i++)
	{
		strReff[i] = toupper(strReff[i]);
	}
	if (strncmp(strReff, "EXT", 3))
	{
		return 0;
	}
	for (; strReff[i] != '\0'; i++)
	{
		if (isdigit(strReff[i]))
		{
			icountNumbers++;
		}
		else
		{
			return 0;
		}
	}
	if (icountNumbers < 1)
	{
		return 0;
	}
	return 1;
}
