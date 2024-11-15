#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	int X, Y, *c,S;
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0��num��4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		// ***** Complete program of the following steps.
		printf("Binary representation of num: ");
		printf("\n");
		printf("    %h",X);
		S=(X^Y)^*c;
		*c=X&Y|(X^Y)&*c;
		for(i=0;i<31;++i){
			if(i%8==0){
				printf(" ");
			}
		}
		printf("\n");
		printf("Hexedecimal representation of num:");
		printf("\n");
		printf("    %",num);
		for(i=0;i<8;++i){
			if(i%2==0){
				printf(" ");
			}
		}
		printf("\n");
		printf("Decimal representation of rev:");
		printf("\n");
		printf("    %h",~X);
		printf("\n");
		printf("Binary representation of rev:");
		printf("\n");
		printf("    %h",num);
		for(i=0;i<32;++i){
			if(i%8==0){
				printf(" ");
			}
		}
		printf("\n");
		printf("Hexedecimal representation of rev:");
		printf("\n");
		printf("    %h",num);
		for(i=0;i<8;++i){
			if(i%2==0){
				printf(" ");
			}
		}
		// b. Print num in its binary representation, a space after every 8 bits.
		
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		
		// d. Assign rev to be the bit reversal of num.
		
		// e. Print rev in its decimal representation.
		
		// f. Print rev in its binary representation, a space after every 8 bits.
		
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
