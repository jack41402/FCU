#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
  int x; // Numeral base.
  char s[33]; // Numeral as string, maximum length 32 bits.
  unsigned n; // Integer value of the numeral.
  unsigned power; // Power of 2, 8, or 16.
  unsigned residual; // Remainding numbers.
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
      else n = n + (s[i] - 'A' + 10) * power; // The digit is A to F.
      power = power * x; // Increment the degree of power by 1, that is, multiplied by base x.
    }
    printf("The input numeral %s of base %d has the decimal value: %u\n", s, x, n);
    
    // Convert to binary numeral.
    if (x!=2) {
      residual = n; // Initial residual is n.
      power = pow(2, 31); // Initial power of binary numeral.
      leading_0 = 1; // Check leading_0; 
      count = 0; // Initial digit count is 0.
      printf("Binary numeral:      "); // Print the prelude message.
      while (count<32) { // At most 32 bits.
        if (!leading_0 || residual/power!=0) {
  	      printf("%u", residual/power); // Print the left-most bit of the residual.
  	      leading_0 = 0; // Not to check leading 0's.
        } // If the condition is false, do not print anything.
  	    residual = residual % power; // Update the rest of bits.
  	    power = power / 2; // Decrement the degree of power by 1.
  	    count++; // Increment count.
  	    if (count%4==0 && !leading_0) printf(" "); // Print a space if four bits are printed.
      }
      if (n==0) printf("0"); // If n is 0, print a single digit 0.
      printf("\n");
	}

    // Convert to octal numeral.	
	if (x!=8) {
      residual = n; // Initial residual is n.
      power = pow(8, 10); // Initial power of octal numeral.
      leading_0 = 1; // Check leading_0; 
      count = 0; // Initial digit count is 1.
      printf("Octal numeral:       "); // Print the prelude message.
      while (count<11) { // At most 11 digtis.
        if (!leading_0 || residual/power!=0) {
  	      printf("%u", residual/power); // Print the left-most octal of the residual.
  	      leading_0 = 0; // Not to check leading 0's.
        } // If the condition is false, do not print anything.
  	    residual = residual % power; // Update the rest of digits.
  	    power = power / 8; // Decrement the degree of power by 1.
  	    count++; // Increment count.
  	    if ((count+1)%3==0 && !leading_0) printf(" "); // Print a space if three digits are printed.
      }
      if (n==0) printf("0"); // If n is 0, print a single digit 0.
      printf("\n");
	}
	
	// Output to decimal numeral.
	if (x!=10) printf("Decimal numeral:     %u\n", n);
	
    // Convert to hexadecimal numeral.	
	if (x!=16) {
      residual = n; // Initial residual is n.
      power = pow(16, 7); // Initial power of hexadecimal numeral.
      leading_0 = 1; // Check leading_0; 
      count = 0; // Initial digit count is 1.
      printf("Hexadecimal numeral: "); // Print the prelude message.
      while (count<8) { // At most 8 digits.
        // Print the left-most hexadecimal digit of the residual, for 0 to 9.
        if (!leading_0 || residual/power!=0) {
          if (residual/power<10) printf("%c", residual/power + '0');
          // Print the left-most hexadecimal digit of the residual, for A to F.
  	      else printf("%c", residual/power - 10 + 'A');
  	      leading_0 = 0;
	    }
  	    residual = residual % power; // Update the rest of digits.
  	    power = power / 16; // Decrement the degree of power by 1.
  	    count++; // Increment count.
  	    if (count%4==0 && !leading_0) printf(" "); // Print a space if four digits are printed.
      }
      if (n==0) printf("0"); // If n is 0, print a single digit 0.
      printf("\n");
    }
    printf("\n"); // Print an empty line.
  }
  return 0;
}
