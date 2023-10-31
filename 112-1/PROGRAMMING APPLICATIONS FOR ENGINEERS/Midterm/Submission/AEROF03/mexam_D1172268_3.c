#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	int Bnum = 0;
	int Bin = 0;
	int j = 0;
	int Hnum = 0;
	int Hin = 0;
	int dec = 0;
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		printf("Binary representation of num: \n");
		
		
		for(i = 1; i <= 32; i++){
			Bnum = num;
			for(j = 0; j < 32 - i; j++){
				Bnum = Bnum/2;
				}
			Bin = Bnum %2 ;
			printf("%d", Bin);
			if(i%8 == 0) printf(" ");
			}
			printf("\n\n");
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		printf("Hexadecimal representation of num: \n");
		for(i = 1; i <= 8; i++){
			Hnum = num;
			for(j = 0; j < 8 - i; j++){
				Hnum = Hnum/16;
				}
			Hin = Hnum %16 ;
			printf("%X", Hin);
			if(i%2 == 0) printf(" ");
			
			}
			printf("\n");
		// d. Assign rev to be the bit reversal of num.
			
				
		
		// e. Print rev in its decimal representation.
		printf("Decimal representation of rev: \n");
		Bnum = num;
			for(i = 1; i <= 32; i++){
				Bin = Bnum %2 ;
				
				for(j = 0; j<=32; j++){
					Bin = Bin * 10;
					
				}
				printf("%d a", Bin);
				rev = rev + Bin;
				Bnum = Bnum/2;
				}
				printf("%d", rev);
				printf("\n\n");
		// f. Print rev in its binary representation, a space after every 8 bits.
		printf("Binary representation of rev: \n");
		Bnum = num;
		for(i = 1; i <= 32; i++){
			Bin = Bnum %2 ;
			printf("%d", Bin);
			if(i%8 == 0) printf(" ");
			Bnum = Bnum/2;
			}
			printf("\n\n");
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.
		printf("Hexadecimal representation of rev: \n");
		for(i = 1; i <= 8; i++){
			Hin = Hnum %16 ;
			printf("%X", Hin);
			if(i%2 == 0) printf(" ");
			Hnum = Hnum/16;
			}
			printf("\n\n");
		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
