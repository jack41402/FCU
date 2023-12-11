/* The program performs the following operations:
    a. Enter a year between 1901 and 2050.
    b. Print calendar of that year.
   The reference date is Saturday, January 1, 2022.
*/

#include <stdio.h>

int main(void) {
  const int yy = 2022, mm = 1, dd = 1, ww = 6; // Reference day
  // Name of 12 months.
  const char *name_of_month[12] = {"January", "February", "March",     "April",   "May",      "June",
                                   "July",    "August",   "September", "October", "November", "December"};
  // Number of days of 12 months.
  const int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int year, month, day, weekday; // Variables for a given date.
  int count; // Number of days from the reference day to the given days.
  int i; // Loop variable
  
  // Enter a year between 1901 and 2050.
  do {
    printf(">>>>Enter the year of calendar: ");
    scanf("%d", &year);
  } while (year<1901 || year>2060);
  
  // Calculate the number of days from January 1 of 2020 to January 1 of the selected year.
  count = 0; // Inital day count to 0.
  // If the year is 2021, count is 0.
  if (year<yy) { // The year before 2021.
    for (i = year; i < yy; i++) // The count is negative.
      if (i%4!=0) count = count - 365; // Non-leap year.
      else count = count - 366; // Leap year.
  }
  else { // The year after 2021.
    for (i = year; i > yy; i--) // The count is positive.
      if ((i-1)%4!=0) count = count + 365; // Non-leap year.
      else count = count + 366; // Leap year.
  }  
  
  month = 1; // Start from January.
  // Compute the day of week of January 1 of the entered year.
  // Note that when n<0, n%7 is between -6 and 0.
  // Hence, (n%7)+7 will turn it to the postivie congruent value.
  // Howerver, if n%7>=0, we pefrorm modulo operation one more time,
  // ((n%7)+7)%7, to make (n%7)+7 between 0 and 6.
  weekday = ((ww + count) % 7 + 7) % 7; 
    
  printf("\nCalendar of the Year of %d\n\n", year); // Print calendar header.
  while (month<=12) { // Process all 12 months. 
    printf("    %s\n", name_of_month[month-1]); // Print month name.
    printf("    Sun Mon Tue Wed Thu Fri Sat\n"); // Print weekday names.
    printf("    "); // Print four blanks before days.
    count = days_of_month[month-1]; // Get number of days in the month. Variable count is used here.
    if (month==2 && year%4==0) count = 29; // If it is February of a leap year, the month has 29 days.
    day = 1; // Start from the first day of the month.
    for (i=0; i<weekday; i++) printf("    "); // Move the cursor to the weekday of day one.
    while (count>0) { // Print all days.
      printf(" %2d ", day); // Print the day. Each day takes four characters (including two spaces).
      day++; // Change to next day. 
      weekday = (weekday + 1) % 7; // Weekday is between 0 and 6.
      if (weekday==0) printf("\n    "); // Starts from Sunday. Output a output a newline.
      count--; // Decrement the number of remaining days in the month.
    }
    if (weekday!=0) printf("\n"); // If the last day is not saturday, Output a newline.
    printf("\n");
    month++; // Continue to process next month.
  }
  
  return 0; 
}
