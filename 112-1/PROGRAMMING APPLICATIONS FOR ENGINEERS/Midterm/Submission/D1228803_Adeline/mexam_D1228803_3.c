#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	int operand;
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return 1;
		num=0x0000000001;
		rev= ~num;
		
		//Binary
		for(i=0; i<32; ++i)
		{
			num=0x0000000001;
		
			if(i%8==0)
			{
				printf(" ");
			}
			
			
		}
		printf("Binary represntation of num: %d\n", num);
		
	
		
		//Hexadecimal
		for(i=0; i<32; ++i)
		{
			num=0x0000000001;
			if(i%2==0)
			{
				printf(" ");
			}
			
		}
		printf("Hexadecimal representstion of num: %x \n", num);
		
		//Decimal
		rev= ~num;
		printf("Decimal representation of rev:%u ", rev);
		printf("\n");
		
		//Binary
		for(i=0; i<32; ++i)
		{
			rev= ~num;
			if(i%8==0)
			{
				printf(" ");
			}
			
		}
		printf("Binary represntation of rev:%d \n", rev);
		
		//Hexadecimal
		for(i=0; i<32; ++i)
		{
			rev= ~num;
			if(i%2==0)
			{
				printf(" ");
			}
			
			
		}
		
		printf("Hexadecimal representstion of rev:%x \n");
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
