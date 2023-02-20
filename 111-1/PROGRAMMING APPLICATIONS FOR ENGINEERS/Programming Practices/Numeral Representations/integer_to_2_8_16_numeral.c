/*
  This program receives a positive  decimal integer and output its binary numeral, octal numeral,
  and hexdecimal numeral representations.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
  unsigned n; // Input an unsigned integer.
  unsigned power; // Power of 2, 8, or 16.
  unsigned residual; // Remainding numbers.
  int count; // digit count. 

  printf("Input a positive integer: "); // Request to input a positive integer:.
  scanf("%u", &n); // Input positive integer n.
  
  // Print binary numeral.
  residual = n; // Initial residual is n.
  power = pow(2, 31); // Initial power of binary numeral.
  count = 0; // Initial digit count is 0.
  printf("Binary numeral:      "); // Print the prelude message.
  while (count<32) { // Print 32 bits.
  	printf("%u", residual/power); // Print the left-most bit of the resudual.
  	residual = residual % power; // Update the rest of bits.
  	power = power / 2; // Decrement the degree of power by 1.
  	count++; // Increment count.
  	if (count%4==0) printf(" "); // Print a space if four bits are printed.
  }
  printf("\n");
  
  // Print octal numeral.
  residual = n; // Initial residual is n.
  power = pow(8, 10); // Initial power of octal numeral.
  count = 0; // Initial digit count is 1.
  printf("Octal numeral:       "); // Print the prelude message.
  while (count<11) { // At most 11 digits, the left-most end has two digits only.
  	printf("%u", residual/power); // Print the left-most octal digit of the residual.
  	residual = residual % power; // Update the rest of digits.
  	power = power / 8; // Decrement the degree of power by 1.
  	count++; // Increment count.
  	if ((count+1)%3==0) printf(" "); // Print a space if three digits are printed.
  }
  printf("\n");
  
  // Print hexadecimal numeral.
  residual = n; // Initial residual is n.
  power = pow(16, 7); // Initial power of hexadecimal numeral.
  count = 0; // Initial digit count is 1.
  printf("Hexadecimal numeral: "); // Print the prelude message.
  while (count<8) { // Print at most 8 digits, the left-most end has four digits.
    // Print the left-most hexadecimal digit of the resudual, for 0 to 9.
    if (residual/power<10) printf("%c", residual/power + '0');
    // Print the left-most hexadecimal digit of the residual, for A to F.
  	else printf("%c", residual/power - 10 + 'A');
  	residual = residual % power; // Update the rest of digits.
  	power = power / 16; // Decrement the degree of power by 1.
  	count++; // Increment count.
  	if (count%4==0) printf(" "); // Print a space if four digits are printed.
  }
  printf("\n");
  return 0;
}
