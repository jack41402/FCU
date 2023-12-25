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
	int i, j; // Loop variable.

	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
	/*	if(!isdigit(str)||!isalpha(str)||!isalnum(str))
		{
			printf("The input string is am invalid numeral.\n");
			break;
		}
		else
		{
		 
		}*/
		for(i = 0; i < strlen(str); i++)
		{
			if(isdigit(str))
			{
				for(j = 0; j < i; j++)
				{
				if(str[i]>str[j]) base = str[i]+1;
				printf("%d\n", base);
				}
			}
		}
		
		// c. Output the values of base and num.
		printf("Base: %d\n, Decimal value:\n", base);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		printf("Binary numeral:\n");
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		printf("Hexadecimal numeral:\n");
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
