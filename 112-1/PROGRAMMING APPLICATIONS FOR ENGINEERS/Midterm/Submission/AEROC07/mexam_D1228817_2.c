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
  
  int ww=1, dd=6, mm=9; // September 6, Labor day of the given year.
  int month, day, weekday; // A day to be computed.
  int count; // Number of days from the Labor day to the specified day.
  int i; // Loop variable
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  
  month=7;
  day=4;
  for(i=month-1; i<mm-1; i++){
  	count+=days_of_month[i];
  }

 
  weekday=(count%7)-1;

  if(ww-weekday>=0){
  	weekday=ww-weekday;
  }
  else{
  		weekday=ww+7-weekday;
  }
  printf("Independece day: %s, %s, %d\n", days_of_week[weekday], name_of_month[month-1], day);
  
  month=11;
  day=0;
  count=0;
  for(i=mm-1; i<month-ww-1; i++){
  	count+=days_of_month[i];
  }
  weekday=((count-6)%7)-1;
  
  if(ww-weekday>=0){
  	weekday=ww-weekday;
  }
  else{
  		weekday=ww+7-weekday;
  }
  
  if(weekday>4-1){
  	day+=(7-1)-weekday+4;
  }
  else{
  	day+=4-weekday;
  }
  day+=7*(4-1);
  
  printf("Thanksgiving day: Thursday, November, %d", day);
  
  return 0; 
}
