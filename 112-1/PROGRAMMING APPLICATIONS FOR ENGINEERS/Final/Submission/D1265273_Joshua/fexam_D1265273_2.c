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
	unsigned long long n;
	int i; // Loop variable.

	do {
		// a.Enter a string of digits and English letters str.
		for (i=0; i<65; i++)
		{
			str[i]= '0';
		}
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
//		for (i=0; i<65; i++)
//		{
//			if (('0'<=str[i] && str[i]<='9' || 'A'<=str[i] && str[i]<='Z' || 'a'<=str[i] && str[i]<='z'))
//			{
//				continue;
//			}
//			else 
//			{
//				 printf("The input string is an invalid numeral");
//			}
		
		base= 8;
		power= 1, residual=0;
		for (i=strlen(str); i>=0; i--)
		{
			if ('0'<=str[i] && str[i]<='9')
			{
				residual= residual+ (str[i]-'0')*power;
			}
			else if ('A'<=str[i] && str[i]<='Z')
			{
				residual= residual+(str[i]-'A'+10)*power;
			}
			else 
			{
				residual=residual+ (str[i]-'a'+36)*power;
			}
			power= power* base;
		}
		// c. Output the values of base and num.
		printf("Base: %d,", base);
		printf("  Decimal value: %llu\n", residual);
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		count= 0;
		//residual= n;
		printf("Binary numeral: ");
		while (count<65)
		{
			power = pow(2, 63);
			printf("%llu", residual/ power);
			if(count%8==0)
			{
				printf(" ");
			}
			residual= residual% power;
			power= power/ 2;
			count++;
		}
		printf("\n");
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		count=0;
		residual= residual;
		printf("Hexadecimal numeral: ");
		while (count<16)
		{
			power= pow(16, 15);
			printf("%llu", residual/ power);
			if (count%4==0)
			{
				printf(" ");
			}
			residual= residual% power;
			power= power/ 16;
			count++;
		}
		printf("\n");
	
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
