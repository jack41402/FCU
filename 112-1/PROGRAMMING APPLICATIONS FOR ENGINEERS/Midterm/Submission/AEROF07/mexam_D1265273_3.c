#include <stdio.h>
#include<math.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	char printbinary[32];
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.	
		printbinary[32]=num;
		//for (i=0;i<31;++i)
		//{
		//	num>>(32-i)&1;
		//	printf("%d",printbinary[i]);
		//	if (i%8==0) printf(" ");
		//}	
		printf("\n");
		for (i=7;i>=0;--i)
		{
			printf("%8x",num);
			if (num/)
			if (i%2==0)
			{
				printf(" ");
			}
		}printf("\n");
		printf("%X",num);
		if (num==0) return;
		
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
