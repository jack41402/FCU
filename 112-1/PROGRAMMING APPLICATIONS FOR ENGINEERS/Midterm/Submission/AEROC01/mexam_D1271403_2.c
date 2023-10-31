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
  scanf("%s, %s %d", &days_of_week[ww], &name_of_month[mm-1], &dd);
  printf("Independence day: %s, %s %d\n", days_of_week[ww], name_of_month[mm-1], dd);
  scanf("%s, %s %d", &days_of_week[ww], &name_of_month[mm-1], &dd);
	ww= ((ww-dd+1)%7+7)%7;
  count=1;
  
  else if (mm>0 && mm<12){
  	count=1;
  	ww= ((ww-dd+1)%7+7)%7;
  	
  }
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
