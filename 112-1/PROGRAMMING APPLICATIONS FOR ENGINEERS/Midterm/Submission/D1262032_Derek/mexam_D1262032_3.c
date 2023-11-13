#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		printf("Binary representation of num:\n");
		printf("    ");
		for(i=1;i<=32;i++)
		{
			printf("%u", num>>(32-i)&1);
			if(i%8==0) printf(" ");
		}
		printf("\n\nHexadecimal representation of num:\n ");
		printf("   ");
		for(i=1;i<=4;i++)
		{
			printf("%X", num>>(32-8*i));
			if(i%4!=0) printf(" ");
		}
		printf("\n\nDecimal representation of rev: ");
		for(i=1;i<=32;i++)
		{
			printf("%u", num&1^1);
		}
		printf("\n\nBinary representation of rev:\n");
		printf("    ");
		for(i=1;i<=32;i++)
		{
			printf("%u", num>>(32-i)&1^1);
			if(i%8==0) printf(" ");
		}
		printf("\n\nHexadecimal representation of rev:\n");
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		
		// d. Assign rev to be the bit reversal of num.
		
		// e. Print rev in its decimal representation.
		
		// f. Print rev in its binary representation, a space after every 8 bits.
		
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
