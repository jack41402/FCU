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
  int i,j=-1; // Loop variable
  
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  
  count=days_of_month[7]+days_of_month[6]+2;
  if (count%7==0) printf("Independence day: Monday, July 4");
  else if (count%7==1) printf("Independence day: Sunday, July 4");
  else if (count%7==2) printf("Independence day: Saturday, July 4");
  else if (count%7==3) printf("Independence day: Friday, July 4");
  else if (count%7==4) printf("Independence day: Thursday, July 4");
  else if (count%7==5) printf("Independence day: Wednesday, July 4");
  else if (count%7==6) printf("Independence day: Tuesday, July 4");
  printf("\n");
  count=days_of_month[8]+days_of_month[9];
  j=3;
	
	for (i=0;i<7;++i)
	{
		if (count%7==i)
		{
			printf("Thanksgiving day: Thursday,November %d",6+j+21);
		}
		j=j-1;
	}
	
  //if (count%7==0) printf("Independence day: Monday, July 4");
  //else if (count%7==1) printf("Independence day: Tuesday, July 4");
  //else if (count%7==2) printf("Independence day: Wednesday, July 4");
  //else if (count%7==3) printf("Independence day: Thursday, July 4");
  //else if (count%7==4) printf("Independence day: Friday, July 4");
  //else if (count%7==5) printf("Independence day: Saturday, July 4");
  //else if (count%7==6) printf("Independence day: Sunday, July 4");
  //printf("\n");
  
  
  
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
