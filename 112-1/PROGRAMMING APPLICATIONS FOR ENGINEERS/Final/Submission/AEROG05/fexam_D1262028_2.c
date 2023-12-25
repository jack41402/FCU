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
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		for(i=0; i < strlen(str)-1; ++i){
			if(!isalnum){
				printf("\nThe input string is an invalid numeral.\n\n");
				break;
			}
		}
		
		
		// c. Output the values of base and num.
		printf("Base: %d, Decimal value: %u\n", base, num);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		for(i=63; i>=0; --i){
			str[i] = (num >> (64-i)) + '0';
		}
		printf("Binary numeral: ");
		for(i=0; i<64; ++i){
			if(((i + 1) % 8) == 0) printf(" ");
			else printf("%c", str[i]);
		}
		printf("\n");
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		
		for(i=15; i>=0; --i){
			if((num % 16) > 9) str[i] = num % 16 - 10 + 'A';
			else str[i] = num % 16 + '0';
			num /= 16;
		}
		printf("Hexadecimal numeral: ");
		for(i=0; i<16; ++i){
			if(((i + 1) % 4) == 0) printf(" ");
			else printf("%c", str[i]);
		}
		printf("\n");
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
