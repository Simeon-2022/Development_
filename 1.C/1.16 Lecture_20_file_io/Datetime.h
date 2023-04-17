#pragma once
#ifndef DATETIME_H
#define DATETIME_H

typedef enum E_Weekday
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday

}E_Weekday;

typedef enum E_Month
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	Setember,
	October,
	November,
	December,

}E_Month;

typedef struct datetime
{
	unsigned year;
	E_Month month;
	unsigned day_of_month;
}datetime;

typedef enum
{
	_separator_comma,
	_separator_slash,
	_separator_hyphen
	
}DateFormatting;



struct datetime date_variance		(datetime userInput, int days);
struct datetime date_variance_v2	(datetime userInput, int days);
char*			my_strftime			(const datetime* date, char* buffer);
void			print_time			(datetime* final_date);
double			date_difference		(datetime time_begin, datetime time_end);

#endif // !DATETIME_H