/* This program reads a month, a day, and a weekday, and then,
   outputs a monthly calendar of that month.
   Weekdays are denoted as:
     0: Sunday    1: Monday  2: Tuesday   3: Wednesday
     4: Thursday  5: Friday  6: Saturday
   The program will check validity of day of the month being input.
   Assume non-leap years, i.e., February is of 28 days. 
   Repeat the process until the input month is zero.
*/

#include <stdio.h>

int main(void) {
  int mm, dd, ww; // Input month, day, and weekday
  int count; // Day count to the first day of the specified.
  // Name of 12 months.
  char name_of_month[12][10] = {"January", "February", "March",     "April",   "May",      "June",
                                "July",    "August",   "September", "October", "November", "December"};
  // Number of days of 12 months.
  int days_of_month[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i; // Loop variable.
  
  // Enter a month 1 to 12; 0 to stop the program.
  do {
    printf(">>>> Enter a month (0 to quit): ");
    scanf("%d", &mm);
    if (mm==0) break; // If the month is zero stop the loop and termniate the program.
    else if (mm>=1 && mm<=12) { // If a vaild month,
      // Enter a day 1 to the number of days of the input month..
      printf("\n>>>> Enter a day (between 1 and %d): ", days_of_month[mm-1]);
      scanf("%d", &dd);
      if (dd>=1 && dd<=days_of_month[mm-1]) { // If a valid day,
        // Enter a weekday 0 to 6.
        printf("\n0: Sunday    1: Monday  2: Tuesday  3: Wednesday\n");
        printf("4: Thursday  5: Friday  6: Saturday\n");
        printf(">>>> Enter a weekday (between 0 and 6): ");
        scanf("%d", &ww);
        if (ww>=0 && ww<=6) { // A vaild weekday, begin to print monthly calendar.
          // Note that when n<0 and n%7!=0, n%7 is between -1 and -6.
          // Hence, (n%7)+7 will turn it to the postivie congruent value.
          // Howerver, if n%7>0, we pefrorm modulo operation one more time,
          // ((n%7)+7)%7, to make (n%7)+7 between 1 and 6.
          ww = ((ww - dd + 1) % 7 + 7) % 7; // Compute the weekday of the first day of the month.
          dd = 1; // Start from the first day of the month.
          printf("\n    %s\n", name_of_month[mm-1]); // Print month name.
          printf("    Sun Mon Tue Wed Thu Fri Sat\n"); // Print weekday name of seven days.
          printf("    "); // Four blanks on the left-hand-side.
          count = days_of_month[mm-1]; // Get number of days in the month.
          
          for (i=0; i<ww; i++) printf("    "); // Move the cursor to the weekday of day one.
          while (count>0) {
            printf(" %2d ", dd); // Print the day. Each day taks four characters (including two spaces).
            dd++; // Continue to the next day.
            ww= (ww + 1) % 7; // Next weekday.
            if (ww==0) printf("\n    "); // Starting from Sunday, again, output a newline.
            count--; // Decrement the rest of days in that month. 
          }
          if (ww!=0) printf("\n"); // If the next day is not Sunday, output a newline.
        }
        else printf("****Error: %d is not a valid weekday.\n", ww); // Incorrect weekday.
      }
      // Incorrect day of the input month.
      else printf("****Error: %d is not a valid day for the month of %s.\n", dd, name_of_month[mm-1]);
    }
    else printf("****Error: %d is not a valid month.\n", mm); // Incorrect month.
    
    // Printed a separated line.
    printf("\n---------------------------------------------------------------\n\n");
  } while (1); // Continue the next case until the input month is 0.
  
  return 0;
}
