#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int max(int x, int y) {
	if (x>y) return x;
	else return y;
}

int main(void) {
	int base; // Numeral base.
	char str[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long num,binary,hexa; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i; // Loop variable.

	do {
		// a.Enter a string of digits and English letters str.
		printf("\nEnter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		for(i=0;i<strlen(str);i++){
			base=max(0,str[i]-'0'+1);
		}
		printf("\nBase :%d ",base);
		
		for(i=0;i<strlen(str);i++){
			num=num*base+(str[i]-'0');
		} 
		printf(" decimal value :%lld",num);
		for(i=0;i<strlen(str);i++){
			
		}
		printf("\nbinary numeral :");
		
		printf("\nhexadecimal numeral : %llX",num);
		
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
