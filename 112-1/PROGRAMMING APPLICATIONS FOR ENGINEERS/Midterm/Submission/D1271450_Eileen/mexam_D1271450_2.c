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
  int Tdate, Tday, Tweek;
  char iweek;
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  count=-(days_of_month[7]+27+6);
  iweek=((dd-count)%7+7)%7;
  count=days_of_month[9]+30-6+1;
Tday=count%7;
Tweek=Tday+1;
if(Tweek==4){
	Tdate=21+1;
	
}
else if(Tweek==0){
	Tdate=21+(5-Tweek)+7;
}
else{
	Tdate=21+(5-Tweek);
}
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  printf("Independence Day: %s, July 4 ", days_of_week[iweek]);
  printf("\n");
  printf("Thanksgiving Day: Thursday, November %d", Tdate);
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
