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
  month=7;
  day=4;
  count = -dd + 1;
  for(i=mm-1;i>=month+1;i--) count-=days_of_month[i-1];
  count-=31-day +1;
  weekday=(((ww+count)%7)+7)%7;
  printf("Independence day: %s, %s %d\n",days_of_week[weekday],name_of_month[month-1],day);
  
  month=11;
  day=1;
  count=days_of_month[mm-1]-dd;
  for(i=mm+1;i<month;i++) count+=days_of_month[i-1];
  count+=day;
  weekday=(((ww+count)%7)+7)%7;
  if(weekday<=4) day=21+(4-weekday+1);
  else day=28-(4-weekday);
  weekday=4;
  printf("Thanksgiving day: %s, %s %d\n",days_of_week[weekday],name_of_month[month-1],day);
  
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
