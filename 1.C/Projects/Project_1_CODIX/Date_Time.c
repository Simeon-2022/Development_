#define _CRT_SECURE_NO_WARNINGS
#define DATE_ARR_LENGTH 9
#define TIME_ARR_LENGTH 7
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "Date_Time.h"

double date_difference(struct tm time_entry_begin)
{
	time_t t = time(NULL);
	struct tm time_entry_current = *localtime(&t);
	time_entry_current.tm_sec = 0;
	time_entry_current.tm_min = 0;
	time_entry_current.tm_hour = 0;
	time_entry_current.tm_isdst = 0;
	time_entry_current.tm_yday = 0;
	time_entry_current.tm_wday = 0;

	//time_t time_to_seconds_Begin = mktime(&time_entry_begin);
	//time_t time_to_seconds_End = mktime(&time_entry_end);
	//printf("%ld\n", (long int)(time_to_seconds_End - time_to_seconds_Begin));
	//int secondsPerDay = 60 * 60 * 24;

	return (difftime(mktime(&time_entry_current), mktime(&time_entry_begin)));
}

void get_time(char* current_date) {

	time_t t = time(NULL);
	struct tm time_entry = *localtime(&t);

	mktime(&time_entry);

	strftime(current_date, sizeof(char) * 20, "%Y%m%d_%H%M%S.txt", &time_entry);
};

void replace_dateAndTimeStamp(char** dirPath) {

	char currentDate[20] = { '\0' };
	get_time(currentDate);

	int i = 0;
	//for (; dirPath[i] != '\0'; i++);

	//dirPath[i - strlen("????????_??????.txt")] = '\0';

	//strcat(&dirPath[i - strlen("????????_??????.txt")], currentDate);
	strcat(*dirPath, currentDate);
}