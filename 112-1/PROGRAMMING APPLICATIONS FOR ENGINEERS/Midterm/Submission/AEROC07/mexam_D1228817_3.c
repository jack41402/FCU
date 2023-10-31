#include <stdio.h>

int main(void) {
	unsigned num, rev=0; // Two 32-bit integers.. 
	int i, j; // Loop variable.
	int a=1;
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return;
		
		printf("Binary representation of num:\n    ");
		for(i=1; i<=32; i++){
			printf("%d", (num>>32-i)&1);
			if(i%8==0) printf(" ");
		}
		printf("\n");
		printf("Hexadecimal representation of num:\n    ");
		printf("%X\n", num);
		printf("Decimal representation of num:    %d\n", num);
		
		
		for(i=1; i<=32; i++){
			a=1;
			for(j=1; j<=32-i; j++){
				a=a*2;
				
			}
			rev=rev+(a*((num>>i-1)&1));
			
			
		}
	
			printf("Binary representation of rev:\n    ");
		for(i=1; i<=32; i++){
			printf("%d", (rev>>32-i)&1);
			if(i%8==0) printf(" ");
		}
		printf("\n");
			printf("Hexadecimal representation of rev:\n    %X\n", rev);
	

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
