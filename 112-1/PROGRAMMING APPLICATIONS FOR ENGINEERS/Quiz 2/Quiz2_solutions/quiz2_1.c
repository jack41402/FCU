#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	int count; // digit count.
	int i; // Loop variable.

	while (1) {
		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
		scanf("%s", num); // Input the hexadecimal numeral as a string.
		if (strcmp(num, "00000000")==0) break; // Stop the loop and terminate the program when the numeral is "000000000".
    
		value = 0; // Initial the numeral value of 0.
		power = 1; // Initial power to 1.
		for (i=strlen(num)-1; i>=0; i--) { // Start the converion from the left-most digit.
			if (isdigit(num[i])) value = value + (num[i] - '0') * power; // The digit is 0 to 9.
			else value = value + (num[i] - 'A' + 10) * power; // The digit is A to F.
			power = power * base; // Increment the degree of power by 1, that is, multiplied by base x.
		}
		printf("The input hexadecimal numeral %s is of the decimal value: %u\n", num, value);
    
    	// Print the correspinding binary numeral.
    	residual = value; // Initial residual is value.
    	power = pow(2, 31); // Initial power of binary numeral.
    	count = 0; // Initial digit count is 0.
    	printf("Binary numeral:      "); // Print the prelude message.
    	while (count<32) { // Total 32 bits.
  	    	printf("%u", residual/power); // Print the left-most bit of the residual.
  	    	residual = residual % power; // Update the rest of bits.
  	    	power = power / 2; // Decrement the degree of power by 1.
  	    	count++; // Increment count.
  	    	if (count%8==0) printf(" "); // Print a space if eight bits are printed.
		}
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
