#include <stdio.h>

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
		printf("Binary representation of num:\n    ");
		for(i=0; i<64; i++){
			printf("%d",num%2);
			if(num%2==0){
				printf
			}
			if(i%8==0 && i/8!=0) printf(" ");
		}
		printf("\n");
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		printf("Hexadecimal representation of num:\n");
	    printf("    %08X",num);
		printf("\n");
		// d. Assign rev to be the bit reversal of num.
		rev =;
		printf("Decimal representation of rev: %d\n",~num);
		
		// e. Print rev in its decimal representation.
		
		// f. Print rev in its binary representation, a space after every 8 bits.
		
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
