#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int main(void) {
	int base; // Numeral base.
	char str[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long num; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i; // Loop variable.

	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		printf("Base:  ");
		printf("The input string is an invalid numeral.");
		printf("Decimal value: ");
		
		
			residual=1;
			power=pow(2,31);
			count=0;
			printf("\nBinary numeral:%u\n",num);
			for(i=0;i<32;i++){
				if(power<32) 
				printf("%u",residual/power);
			
				residual=residual%power;
				power=power/2;
				count++;
			}
			
			if(count%8==0)printf(" ");
		
	
			residual=1;
			power=pow(16,7);
			count=0;
			printf("\nHexadecimal numeral:%c\n",num);
			for(i=0;i<8;i++){
			if(power<8) 
			printf("%c",residual/power-'0');
			else printf("%c",residual/power-10+'A');
			
			residual=residual%power;
			power=power/16;
			count++;
	
			}
			
			
			
			if(count%4==0)printf(" ");
		
			
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		
		// c. Output the values of base and num.
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.

	return 0;
}

