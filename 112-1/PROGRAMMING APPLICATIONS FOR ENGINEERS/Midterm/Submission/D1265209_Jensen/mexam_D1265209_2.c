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
  
  // Compute and print Independence day, July 4.
  int ddi=4, mmi=7,wwi;
  count = days_of_month[6]-4+days_of_month[7]+days_of_month[8]+6;
  wwi=((count-mm-1)%7+7)%7;
  printf("Independence day: %s, %s %d\n", days_of_week[wwi],name_of_month[mmi-1],ddi);
  // Compute and print Thanksgiving day, the forth Thursday in November.
  int ddt,mmt=10,wwt=4;
  int count1 = days_of_month[9]-6+1;
  int count2 = count1%7+ww;
  ddi=7*3+(7-count2)+3;
  printf("Thanksgiving day: %s, %s %d\n", days_of_week[wwt],name_of_month[mmt],ddi);
  return 0; 
}
