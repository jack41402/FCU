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
  
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);//9/6 monday
  
  int i_day = 4;
  int i_month = 7;
  count = days_of_month[6]-4+days_of_month[7]+6;//days from iday to 9/6 (64)
  int i_weekday = ww-(count%7);
  printf("Independence day: %s, %s %d\n", days_of_week[i_weekday], name_of_month[7-1], i_day);
  
  int t_weekday = 4;
  int t_month = days_of_month[10];
  count = days_of_month[8]-6+days_of_month[9]+1;//days from 9/6 to nov first (56)
  int i_nov_first = (ww+count)%7;//monday
  int t_day = 1+4-i_nov_first+7*3;//days from first day to first Thursday and add 3 weeks
  printf("Thanksgiving day: %s, %s %d\n", days_of_week[t_weekday], name_of_month[11-1], t_day);
  
  
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
