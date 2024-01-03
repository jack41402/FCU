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
    unsigned long long number;
    unsigned long long decimal=0;
    unsigned long long a;
    char hexadecimal[16];
	do {
		decimal=0;
		a=0;
		base=0;
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		for(i=0;i<strlen(str);i++){
			if(str[i]=='0') break;
		}
		for(i=0;i<strlen(str);i++){
		if(!isalnum(str[i])){
			printf("The input string is an invalid numeral.\n\n");
			break;
	       	}
	    }   
		for(i=1;i<strlen(str);i++){
			if(str[i]>='0'&&str[i]<='9') number=str[i]-48;
			else if(str[i]>='A'&&str[i]<='Z') number=str[i]-55;
			else if(str[i]>='a'&&str[i]<='z') number=str[i]-61;
			if(str[i]>str[i-1]) base=number+1;
		}
		for(i=0;i<strlen(str)-1;i++){
			if(str[i]>='0'&&str[i]<='9') a=str[i]-48;
			else if(str[i]>='A'&&str[i]<='Z') a=str[i]-55;
			else if(str[i]>='a'&&str[i]<='z') a=str[i]-61;
			decimal=(decimal+a)*base;
		}
		if(str[i]>='0'&&str[i]<='9') a=str[i]-48;
		else if(str[i]>='A'&&str[i]<='Z') a=str[i]-55;
		else if(str[i]>='a'&&str[i]<='z') a=str[i]-61;
		decimal=decimal+a;
		printf("Base: %d, Decimal value: %llu\n", base, decimal);
		printf("Binary numeral: ");
		for(i=1;i<=64;i++){
			printf("%d", decimal>>(64-i)&1);
			if(i%8==0) printf(" ");
		}
		printf("\nHexadecimal numeral: ");
		for(i=15;i>=0;i--){
			a=decimal%16;
			hexadecimal[i]=(a>=10)?a+55:a+48;
			decimal=decimal/16;
		}
		for(i=0;i<=15;i++){
		    printf("%c",hexadecimal[i]);
		    if(i%0==4) printf(" ");
		}
		printf("\n");
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
