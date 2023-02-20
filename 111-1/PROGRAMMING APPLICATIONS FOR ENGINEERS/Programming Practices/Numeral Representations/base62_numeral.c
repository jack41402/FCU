/*
  This program reads an integer x and a numeral string s.
  If x is 10, the numeral string s is a decimal numeral and 
  convert it to the equivalent base62 numeral;
  if x is 62, the numeral string is base62 and 
  convert it to the equivalent decimal numeral.
  Repeat the conversion step until x is 0. 
  Declare the numeral vaule of type unsigned long long.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
  int x; // Numeral base.
  char s[21]; // Numeral as string, maximum length 20 digits.
  unsigned long long n; // Integer value of the numeral (64-bit integer).
  unsigned long long power; // Power of 10 or 62.
  unsigned long long residual; // Remainding numbers.
  int leading_0; // 1: check leading zeros, 0: not check leading zeros.
  int count; // digit count.
  int i; // Loop variable.

  while (1) {
  	printf("Input the numeral base and the numeral as a string: ");
    scanf("%d %s", &x, s); // Input the numeral base and the numeral as a string.
    if (x==0) break; // Stop the loop and terminate the program when the numeral base is 0.
    
    n = 0; // Initial the numeral value of 0.
    power = 1; // Initial power to 1.
    for (i=strlen(s)-1; i>=0; i--) { // Start the converion from the left-most digit.
      if (isdigit(s[i])) n = n + (s[i] - '0') * power; // The digit is 0 to 9.
      else if (isupper(s[i])) n = n + (s[i] - 'A' + 10) * power;  // Upper case letter, A to Z.
      else n = n + (s[i] - 'a' + 36) * power;  // Lower case letter, a to z.
      power = power * x; // Increment by 1, that is, multiplied by base x.
    }
    
    // Convert decimal number to base62 numeral.
    if (x==10) {
      residual = n; // Initial residual is n.
      power = pow(62, 10); // Initial power of base62 numeral.
      leading_0 = 1; // Check leading_0; 
      count = 0; // Initial digit count is 1.
      printf("Decimal number %llu is equivalent to base62 numeral: ", n); // Print the prelude message.
      while (count<11) { // Print base62 digits, maximum 11 digits.
        // Print the left-most hexadecimal digit of the residual, for 0 to 9.
        if (!leading_0 || residual/power!=0) {
          if (residual/power<10) printf("%c", residual/power + '0');
          // Print the left-most hexadecimal digit of the residual, for A to Z.
  	      else if (residual/power<36) printf("%c", residual/power - 10 + 'A');
          // Print the left-most hexadecimal digit of the resuidual, for a to z.
  	      else printf("%c", residual/power - 36 + 'a');
  	      leading_0 = 0;
	    }
  	    residual = residual % power; // Update the rest of digits.
  	    power = power / 62; // Decrement the power by 1.
  	    count++; // Increment count.
      }      
      printf("\n");
    }
	
	// Output to decimal numeral.
	if (x==62) printf("Base62 numeral %s is equivalent to decimal numeral: %llu\n", s, n);
	
    printf("\n"); // Print an empty line.
  }
  return 0;
}
