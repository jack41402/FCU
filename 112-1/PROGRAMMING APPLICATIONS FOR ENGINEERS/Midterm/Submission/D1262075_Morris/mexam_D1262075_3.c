#include <stdio.h>

int main(void) {
	unsigned num, rev,j,k; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.	
		printf("\n");	
		if (num==0) return;
		
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		
		// d. Assign rev to be the bit reversal of num.
		
		// e. Print rev in its decimal representation.
		
		// f. Print rev in its binary representation, a space after every 8 bits.
		
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.
		printf("Binary represenration of num : ");
		printf("\n    ");
		for(i=1;i<=32;i++){
			j=(num>>32-i)&1;
			printf("%u",j);
			if(i%8==0) printf(" ");
		}
		printf("\nHexadecimal representation of num : ");
		printf("\n    ");
		printf("%8X",num);
		
		
		
		
		printf("\n\nDecimal representation of rev : ");
		rev=(~num);
		printf("%u",rev);
		
		printf("\n\nBinary representation of rev : ");
		printf("\n    ");
		for(i=32;i>=1;i--){
			j=((num>>32-i)&1);
			printf("%u",j);
			if(i%8==1) printf(" ");
		}
		printf("\nHexadecimal representation of rev : ");
		printf("\n    ");
		for(i=8;i>=1;i--){
			printf("%X",num)^0;
			if(num=0) printf(" ");
		}
	
		
		

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
