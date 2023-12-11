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
  
  int ww=1, dd=6, mm=9, ww_id, dd_th; // September 6, Labor day of the given year.
  int month, day, weekday; // A day to be computed.
  int count; // Number of days from the Labor day to the specified day.
  int i; // Loop variable
  
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  count = -(days_of_month[7]+28+5);
  ww_id = ((count+ww)%7+7)%7;
  count = days_of_month[9]+days_of_month[10]+12;
  if((count+ww)%7==0) dd_th = 1 + 21;
  else dd_th = 7-(count+ww)%7+1+21;
  printf("Independence day: %s, July 4", days_of_week[ww_id]);
  printf("\nThanksgiving day: Thursday, November %d", dd_th);
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
