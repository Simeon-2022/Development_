#pragma once
#ifndef DATE_TIME_H
#define DATE_TIME_H


double	date_difference			(struct tm time_entry_begin);
void	get_time					(char* current_date);
void	replace_dateAndTimeStamp	(char** dirPath);

#endif // !DATE_TIME_H
