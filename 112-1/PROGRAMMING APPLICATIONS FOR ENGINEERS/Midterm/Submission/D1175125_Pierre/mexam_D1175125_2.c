#include <stdio.h>

int main(void) {
  // Name of 12 months.
  const char *name_of_month[12] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
  // Name of seven weekdays.
  const char *days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};                            
  // Number of days of 12 months, non-leap year.
  const int days_of_month[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int weekday=1, day=6, month=9; // September 6, Labor day of the given year.
  int count; // Number of days from the Labor day to the specified day.
  int i; // Loop variable
  
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[weekday], name_of_month[month-1], day);
  
  // ***** Complete program of the following steps:
  int first_day;
  for(i=0;i<month-1;i++){
  		first_day+=days_of_month[i];
  }
  first_day+=6;
  first_day%=7;
  weekday=first_day-1;
  if(weekday<0)weekday=7+weekday; // 1/1 weekday==4
  // Compute and print Independence day, July 4.
  month=7;
  day=4;
  first_day=0; 
    for(i=0;i<month-1;i++){
  		first_day+=days_of_month[i];
  }
	first_day%=7;
	weekday=(4+first_day+(4-1))%7; //weekday of July 4, 4-1 means gap from 7/1 to 7/4
	printf("Independence day: %s, %s %d\n\n", days_of_week[weekday], name_of_month[month-1], day);
  // Compute and print Thanksgiving day, the forth Thursday in November.
  month=11;
  day=0; //uncertain
  first_day=0; 
    for(i=0;i<month-1;i++){
  		first_day+=days_of_month[i];
  }
	first_day%=7;
	weekday=(4+first_day)%7; //weekday of 11/1
	if((4-weekday)>=0)day=((4-weekday)+22);
	else day=(7+(4-weekday)+22);
	weekday=4;
	printf("Independence day: %s, %s %d\n\n", days_of_week[weekday], name_of_month[month-1], day);
  return 0; 
}



