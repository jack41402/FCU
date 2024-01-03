#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().


char *dec2binary(int num, char *binary){
	int i;
	for(i=0; i<strlen(num); ++i){
		binary[i] = num
	}
}

char *dec2hex(int num, char *binary){
	int i;
	
}

int main(void) {
	int base, base2; // Numeral base.
	char str[65], binary[65];//string, maximum length 64 digits for binary numerals.
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
		
		
		for(i=0; i<strlen(str); ++i){
			if(isupper(str[i])) base2 = str[i] - 'A' + 10;
			else if(islower(str[i])) base2 = str[i] - 'a' + 36; 
			else base2 = str[i];
			if(base2 > base) base = base2; 
		}
		printf("\nBase: %d,", base+1);
		printf("Decimal value: ");
		
		printf("Binary nummeral: ");
		count = 0;
		for(i=0; i<strlen(binary); ++i){
			printf("%c", binary[i]);
			count ++;
			if(count%8==0) printf(" ");
		}
		
		printf("\nHexadecimal numeral: ");
		count = 0;
		for(i=0; i<strlen(hex); ++i){
			printf("%c", binary[i]);
			count ++;
			if(count%4==0) printf(" ");
		}
			
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}

		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		
		// c. Output the values of base and num.
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
