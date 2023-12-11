#include <stdio.h>

int main(void) {
  // Name of 12 months.
  char name_of_month[12][10] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
  // Name of seven weekdays.
  char days_of_week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};                            
  // Number of days of 12 months, non-leap year.
  const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int ww=1, dd=6, mm=9; // September 6, Labor day of the given year.
  int month, day, weekday; // A day to be computed.
  int count; // Number of days from the Labor day to the specified day.
  int id,a,td,b; // Loop variable
 
  id=25+days_of_month[9]+25;
  a=id%7;
  
  td=5+days_of_month[7]+28;
  printf("%d\n",td%7);
  b=td%7-1;
  
 
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.

  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  printf("Independence day: %s , July 4\n",days_of_week[b] );
  printf("Thanksgiving day: %s , November 25", days_of_week[a]);
  
  return 0; 
}
