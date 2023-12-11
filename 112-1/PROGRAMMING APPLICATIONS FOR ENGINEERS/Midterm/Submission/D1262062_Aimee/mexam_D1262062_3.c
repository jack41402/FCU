#include <stdio.h>
unsigned int printBinary()
		{
			int i, num,num2;
			for(i=1; i<=32; ++i)
			{
				printf("%d", num>>(32-i)&0X00000001);
				if(i%8==0)printf(" ");
			} 
			return num2;
		};
int main(void) {
	unsigned num, rev, num2; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		num2=0;
		printf("Binary representation of num:\n\t");
		printBinary(num);
		printf("\nHexadecimal representation of num:\n\t");
		printf("%.8X", num);
		printf("\nDecimal representation of rev: %d\n\t", ~num);
		printf("\nBinary representation of rev:\n\t");
		printBinary(~num);
		printf("\nHexadecimal representation of rev:\n\t");
		printf("%.8X", ~num);
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
