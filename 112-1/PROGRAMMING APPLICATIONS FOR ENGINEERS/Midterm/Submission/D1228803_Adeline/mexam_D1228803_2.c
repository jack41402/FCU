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
  int thanksgivingday;
  
  
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  
  count=days_of_month[8];
  weekday=((count+27+6)%7);
  
  printf("Independence day: %s, July 4\n", days_of_week[weekday]);
  
  count=days_of_month[10];
 
  day=(24+count+1+21);
  
  if((day-3)%7+7==0)
  {
  	thanksgivingday=21-(day%7);
  }
  else
  {
  	thanksgivingday=(day-3)%7+21+1;
  }
  
  
  printf("Thanksgiving day: Thursday, November %d \n", thanksgivingday);
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
