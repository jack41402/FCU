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
		int origin_num=num;
		// ***** Complete program of the following steps.
		// b. Print num in its binary representation, a space after every 8 bits.
		int binary[32];
		for(i=0;i<32;i++){
			binary[i]=0;
		}
		for(i=31;i>=0;i--){
			binary[i]=num%2;
			num/=2;
		}
		printf("Binary representation of num:\n");
		for(i=0;i<32;i++){
			if((i%8)==0)printf(" %d",binary[i]);
			else printf("%d",binary[i]);
		}
		printf("\n\n");
		// c. Print num in its hexadecimal representation, print a space after every 2 digits.
		printf("hexadecimal representation of num:\n");
		char hexi[8];
		int a;
		for(i=0;i<8;i++){
			hexi[i]='0';
		}		
		for(i=7;i>=0;i--){
			if(num%16<10)hexi[i]=num%16;
			else if(num%16==10)hexi[i]='A';
			else if(num%16==11)hexi[i]='B';
			else if(num%16==12)hexi[i]='C';
			else if(num%16==13)hexi[i]='D';
			else if(num%16==14)hexi[i]='E';
			else if(num%16==15)hexi[i]='F';
			num/=16;
		}
		for(i=0;i<8;i++){
			if((i%2)==0)printf(" %c",hexi[i]);
			else printf("%c",hexi[i]);
		}
		printf("\n\n");
		// d. Assign rev to be the bit reversal of num.
		for(i=0;i<32;i++){
			rev+=binary[31-i]*pow(2,31-i);
		}
		// e. Print rev in its decimal representation.
		printf("Decimal representation of rev: %d\n",rev);
		printf("\n\n");
		// f. Print rev in its binary representation, a space after every 8 bits.
		printf("Binary representation of rev:\n");
		for(i=0;i<32;i++){
			if((i%8)==0)printf(" %d",binary[31-i]);
			else printf("%d",binary[31-i]);
		}
		printf("\n\n");
		// g. Print rev in its hexadecimal representation, print a space after every 2 digits.
		printf("hexadecimal representation of rev:\n");
		for(i=0;i<8;i++){
			if((i%8)==0)printf(" %c",hexi[8-i]);
			else printf("%c",hexi[8-i]);
		}
		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}
