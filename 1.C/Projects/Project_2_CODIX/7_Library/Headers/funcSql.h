#ifndef FUNC_SQL_H
#define FUNC_SQL_H

//handle errors
void sql_error(const char* message);

//connect to Oracle
void connect_oracle(const char* strUserID);

//commit transaction
void exec_commit(void);

//commit all
void exec_commit_all(void);

//Convert data Format sring from "DD-MON-YY" to "YYYYMMDD"
void convertDateFormat(char* date);

//Add addDayd to old Date and return new date
void  addDaysToDate(char* oldDate, unsigned addDays, char* newDate);

//Puts determineted NULL in the end of data
void nullTermonateString(char* string);

//Create new invoice number 
void newInviceNo(int custID, int newSeq, char* newIssueDate, char* newInvNo);

#endif



