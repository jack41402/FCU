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
	int check;
	unsigned long long n=55072328406809;
	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		check=0;
		for(i=0; i<strlen(str); i++){
			if (isdigit(str[i])==0 && isalpha((str[i]))==0){
				printf("The input string is an invalid numeral.");
				
				break;
			}
		} 
		base=1;
		
			
		// c. Output the values of base and num.
		printf("Base: %d, Decimal value: %llu\n",base,n);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		power=pow(2,63);
		residual = n;
		count=0;
		printf("Binary numeral: ");
		while(count<64){
			printf("%u",residual/power);
			residual=residual%power;
			power=power/2;
			count++;
			if(count%8==0)printf(" ");		
		}
		printf("\n");
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		power=pow(16,15);
		residual = n;
		count=0;
		printf("Hexadecimal numeral: ");
		while(count<16){
			if(residual/power<10){
				printf("%u",residual/power);
			}
			else{
				printf("%c",residual/power+'A');
			}
			residual=residual%power;
			power=power/16;
			count++;
			if(count%4==0)printf(" ");		
		}
		printf("\n\n");
	
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
