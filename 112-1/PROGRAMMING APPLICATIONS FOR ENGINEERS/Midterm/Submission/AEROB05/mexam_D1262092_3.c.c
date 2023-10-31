#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	int S;
	int c;
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		
		printf("Binary representation of num:\n");
		printf("    ");
		for(i=31; i<=1; i--){
			
			if(i==8||i==16||i==24) printf(" ");
		}
	    printf("\n");
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		printf("Hexadecimal representation of num:\n");
		printf("    ");
		printf("%0.8X\n",num);
		// d. Assign rev to be the bit reversal of num.
		
		// e. Print rev in its decimal representation.
		printf("Decimal representation of rev:");
		// f. Print rev in its binary representation, a space after every 8 bits.
		
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
