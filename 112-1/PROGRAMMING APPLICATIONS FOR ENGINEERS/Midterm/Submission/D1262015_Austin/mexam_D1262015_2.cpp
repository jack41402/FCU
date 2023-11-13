#include <stdio.h>


int countshit (int n){
	int i ;
	int sum;
	const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (i = 0;i < n;i++){
		sum+=days_of_month[i];
	}
	return sum;
  
}//this is use to count day of former months

int main() {
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
  int newyear ;
  printf("Labor day of a given leap year: %s, %s %d\n\n", days_of_week[ww], name_of_month[mm-1], dd);
  //  find new year
  newyear = dd + countshit( mm-1 );
  ww =((ww - countshit( mm-1 ))%7 +7)%7 ; 

  int IdayWW,TdayDD;
  int IdayMM = 7 ;
  int IdayDD = 4 ;
  int TdayWW = 4 ;
  int TdayMM = 11 ;
  
  IdayWW =((ww + countshit( mm-1 ) + IdayDD)%7+7)%7 ;
  printf ("Independence day : %s, %s %d\n", days_of_week[IdayWW], name_of_month[IdayMM-1], IdayDD );
  
  int nov1stWW;
  nov1stWW = ((ww + countshit( TdayMM-1 ))%7+7)%7;
  printf ("%d\n",nov1stWW );
  TdayDD = -(TdayWW-nov1stWW)+28;
  //the last thursday of last month and +28 to get the forth thursday of nov
  printf ("Thanksgiving day : %s, %s %d\n", days_of_week[TdayWW], name_of_month[TdayMM-1], TdayDD );
  // ***** Complete program of the following steps:
  
  // Compute and print Independence day, July 4.
  
  // Compute and print Thanksgiving day, the forth Thursday in November.
  
  return 0; 
}
