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
  
  // Compute and print Independence day, July 4.
  month = 7; // July.
  day = 4; // Day 4.
  count = -dd + 1; // The number of days in September before Labor day.
  for (i=mm-1; i>=month+1; i--) count -= days_of_month[i-1]; // Number of days for August. 
  count -= 31 - day + 1; // Number of days in July after the day and before Independence day.
  weekday = (((ww + count) % 7) + 7) % 7;
  printf("Independence day: %s, %s %d\n", days_of_week[weekday], name_of_month[month-1], day);
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  month = 11; // November.
  day = 1; // Day 1.
  count = days_of_month[mm-1] - dd; // The number of days in September after Labor day.
  for (i=mm+1; i<month; i++) count += days_of_month[i-1]; // Add number of days in October.
  count += day; // 1st day of November..
  weekday = (((ww + count) % 7) + 7) % 7; // Weekday of November 1.
  if (weekday<=4) day = 21 + (4 - weekday + 1); // If the weekday of November 1 is Thursday or before.
  else  day = 28 - (4 - weekday); // If the weekday of November 1 is Friday or after.
  weekday = 4;
  printf("Thanksgiving day: %s, %s %d\n", days_of_week[weekday], name_of_month[month-1], day);
  
  return 0; 
}
