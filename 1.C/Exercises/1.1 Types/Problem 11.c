#include <stdio.h>
int main (){
        int iYear = 1;
	const int iDays_In_One_Year = 365;
	const int iHours_In_One_Day = 24;
	const int iMinutes_In_One_Hour = 60;
	const int iSeconds_In_One_Minute = 60;

	printf("%d",iYear * iDays_In_One_Year * iHours_In_One_Day * iMinutes_In_One_Hour * iSeconds_In_One_Minute);

	return 0;
}
