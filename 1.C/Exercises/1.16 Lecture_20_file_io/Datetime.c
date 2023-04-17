#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "Datetime.h"

int days_per_Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char* formatting[3] = { "%d,%b,%Y", "%d/%m/%y", "%a-%d-%b-%Y" };

char* formatNaming[3] = { "22,Dec,2022", "22/12/2022", "Mon-25-Dec-2022" };

struct datetime date_variance(datetime userInput, int days) {

	datetime custom_date = {

	.day_of_month = userInput.day_of_month,
	.month = userInput.month,
	.year = userInput.year
	};

	// 31.12.2022 -> - 100days
	if (days < 0)
	{
		for (int i = 0; i < abs(days); i++)
		{
			if (custom_date.day_of_month > 0)//< (unsigned)days_per_Month[custom_date.month])
			{
				custom_date.day_of_month--;
			}
			else if (custom_date.day_of_month == 0)//(unsigned)days_per_Month[custom_date.month])
			{

				if (custom_date.month == January)
				{
					custom_date.month = December;
					custom_date.year--;
				}
				else
				{
					custom_date.month--;
				}
				custom_date.day_of_month = (unsigned)days_per_Month[custom_date.month];
				custom_date.day_of_month--;
			}
		}
	}
	else // 31.12.2022 -> + 100days
	{
		for (int i = 0; i < days; i++)
		{
			if (custom_date.day_of_month < (unsigned)days_per_Month[custom_date.month])
			{
				custom_date.day_of_month++;
			}
			else if (custom_date.day_of_month == (unsigned)days_per_Month[custom_date.month])
			{
				custom_date.day_of_month = 0; custom_date.day_of_month++;

				if (custom_date.month == December)
				{
					custom_date.month = January;
					custom_date.year++;
				}
				else
				{
					custom_date.month++;
				}
			}
		}
	}

	return custom_date;
}

datetime date_variance_v2(datetime userInput, int days) {

	struct tm time_entry;// = *localtime(&(time_t) { time(NULL) });

	time_entry.tm_sec = 0;
	time_entry.tm_min = 0;
	time_entry.tm_hour = 0;
	time_entry.tm_mday = userInput.day_of_month + days;
	time_entry.tm_mon = userInput.month;
	time_entry.tm_year = userInput.year - 1900;


	char buffer[50];

	mktime(&time_entry);
	strftime(buffer, sizeof(buffer), ".%Y.%m.%d", &time_entry);

	int dateToInt[4];

	int j = 0;
	for (const char* buffer_ptr = buffer; *buffer_ptr != '\0'; buffer_ptr++)
	{
		if (*buffer_ptr == '.')
		{
			buffer_ptr++;
			dateToInt[j] = atoi(buffer_ptr);
			j++;
		}
	}

	datetime custom_date = {

	.year = dateToInt[0],
	.month = (dateToInt[1] - 1),
	.day_of_month = dateToInt[2]
	};

	return custom_date;
}

void print_time(datetime* final_date) {

	struct tm time_entry;
	time_entry.tm_sec = 0;
	time_entry.tm_min = 0;
	time_entry.tm_hour = 0;
	time_entry.tm_year = final_date->year - 1900;
	time_entry.tm_mon = final_date->month;
	time_entry.tm_mday = final_date->day_of_month;
	
	mktime(&time_entry);
	char buffer[45];

	strftime(buffer, sizeof(buffer), "%A.%d.%B.%Y", &time_entry);
	printf("Return date is: %s\n", buffer);

};

double date_difference(datetime time_begin, datetime time_end)
{
	struct tm time_entry_begin = {
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 0,
	.tm_mday = time_begin.day_of_month,
	.tm_mon = time_begin.month,
	.tm_year = time_begin.year - 1900 };

	struct tm time_entry_end = {
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 0,
	.tm_mday = time_end.day_of_month,
	.tm_mon = time_end.month,
	.tm_year = time_end.year - 1900 };

	//time_t time_to_seconds_Begin = mktime(&time_entry_begin);
	//time_t time_to_seconds_End = mktime(&time_entry_end);
	//printf("%ld\n", (long int)(time_to_seconds_End - time_to_seconds_Begin));

	int secondsPerDay = 60 * 60 * 24;

	return (difftime(mktime(&time_entry_end), mktime(&time_entry_begin)) / secondsPerDay);
}

char* my_strftime(const datetime* date, char* buffer) {

	struct tm time_entry;
	time_entry.tm_sec = 0;
	time_entry.tm_min = 0;
	time_entry.tm_hour = 0;
	time_entry.tm_year = date->year - 1900;
	time_entry.tm_mon = date->month;
	time_entry.tm_mday = date->day_of_month;

	mktime(&time_entry);
	printf("Choose date formatting:\n 0->%s\n 1->%s\n 2->%s \n -> ", formatNaming[_separator_comma], formatNaming[_separator_slash], formatNaming[_separator_hyphen]);

	int formatIdx = 0;
	scanf("%d", &formatIdx);
	strftime(buffer, 50, formatting[formatIdx], &time_entry);

	return buffer;
};