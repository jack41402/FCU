#include <stdio.h>
#include <math.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		printf("Binary representation of num:\n");
		printf("    ");
		for(i=1 ;i<=32 ;i++)
		{
			int n =0;
			n=num>>(32-i)&1 ;
			printf("%d",n);
			if(i%8 == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		printf("Hexadecimal representation of num:\n");
		printf("    ");
		for(i=1 ;i<=8 ;i++)
		{
			unsigned int n =0;
			n=num/pow(16,8-i) ;
			printf("%X",n);
			if(i%2 == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
		// d. Assign rev to be the bit reversal of num.
		for(i=1 ;i<=32 ;i++)
		{
			int n =0;
			n=num>>(32-i)&1 ;
			rev+=n*pow(2,i-1);
		}
		// e. Print rev in its decimal representation.
		printf("Decimal representation of rev: ");
		printf("%u\n", rev);
		// f. Print rev in its binary representation, a space after every 8 bits.
		printf("Binary representation of rev:\n");
		printf("    ");
		for(i=1 ;i<=32 ;i++)
		{
			int n =0;
			n=rev>>(32-i)&1 ;
			printf("%d",n);
			if(i%8 == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.
	printf("Hexadecimal representation of rev:\n");
		printf("    ");
		for(i=1 ;i<=8 ;i++)
		{
			unsigned int n =0;
			n=rev/pow(16,8-i) ;
			printf("%X",n);
			if(i%2 == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
