#include <stdio.h>

int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		printf("Binary representation of num:\n    ");
		for (i=0; i<32; i++) { // Print 32 bits.
			printf("%d", (num >> (31-i)) & 0X01);
			if ((i+1)%8==0) printf(" ");
		}
		printf("\n\n");
		
		printf("Hexadecimal representation of num:\n    ");
		for (i=0; i<4; i++) { // Print 8 nibbles, 2 in a pair.
			printf("%02X ", (num >> (3-i)*8) & 0XFF);
		}
		printf("\n\n");
		
		// Set rev to be the bit reversal of num.
		rev = 0; // Clear rev.
		for (i=0; i<32; i++) { // Process all bits of Num from left to right.
			rev = rev | ((num >> (31-i) & 0X01) << i);
		}
		
		printf("Decimal representation of rev: %u\n\n", rev);
		
		printf("Binary representation of rev:\n    ");
		for (i=0; i<32; i++) { // Print 32 bits.
			printf("%d", (rev >> (31-i)) & 0X01);
			if ((i+1)%8==0) printf(" ");
		}
		printf("\n\n");
		
		printf("Hexadecimal representation of rev:\n    ");
		for (i=0; i<4; i++) { // Print 8 nibbles£¬ 2 in a pair.
			printf("%02X ", (rev >> (3-i)*8) & 0XFF);
		}
		printf("\n\n");

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
