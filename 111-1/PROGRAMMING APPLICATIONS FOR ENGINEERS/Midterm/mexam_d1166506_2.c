#include <stdio.h>

int main(void) {
	// Name of 12 months.
	const char *name_of_month[12] = {"January", "February", "March", "April", "May", "June",
	                        "July", "August", "September", "October", "November", "December"};
	// Name of seven weekdays.
	const char *days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
	                             "Thursday", "Friday", "Saturday"};                            
	// Number of days of 12 months, non-leap year.
	const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int ww=1, dd=6, mm=9; // September 6, Labor day of the given year.
	int month, day, weekday; // A day to be computed.
	int count; // Number of days from the Labor day to the specified day.
	int i; // Loop variable
	
	printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
	
	// ***** Complete program of the following steps:
	// Compute and print Valentine's day, February 14.
	count = 0 , month = 2 , day = 14 ;
	count += 29 - day ;
	for (i=2 ; i<8 ; ++i)
	{
	count += days_of_month[i] ;
	}
	count += dd ;
	weekday = ((ww-count%7)+7)%7 ;
	printf ("Valentine's day: %s, %s %d\n" , days_of_week[weekday] , name_of_month[month-1] , day) ;
	
	// Compute and print Thanksgiving day, the forth Thursday in November.
	count = 0 , month = 11 , weekday = 4 ;
	count += 30 - dd ;
	count += days_of_month[9] ;
	day = (4-(ww+count)%7+7)%7 ;
	if (day==0) day += 7 ;
	for (i=1 ; i<=3 ; ++i)
	{
		day += 7 ;
	}
	printf ("Thanksgiving day: %s, %s %d\n" , days_of_week[weekday] , name_of_month[month-1] , day) ;
	return 0; 
}