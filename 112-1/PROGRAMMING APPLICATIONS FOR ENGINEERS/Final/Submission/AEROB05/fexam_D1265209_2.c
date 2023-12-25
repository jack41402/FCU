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
		int decimal;
		for(i=0; i<strlen(str); i++){
			if(str[i]<='9'){
				 = str[i] - '0';
			}
			else{
				 = str[i] - 'A' + 10;
			}
		}
		
		int a=0;
		for(i=0; i<strlen(str); i++){
			if(str[i]>a)
				a = str[i];
			else if(i == srlen(str))
				return a;	
		}
		
		if(a>'0' || a<'9'){
			base = a - '0';
		}
		else if(a>'A' || a<'Z') {
			base = a - 'A' + 10;
		}
		else(a>'a' || a<'z'){
			base = a - 'a' + 36;
		}
		
		// c. Output the values of base and num.
		printf("Base: %d", base);
		printf("Decimal value: %d", decimal);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		printf("Binary number: \n");
		residual = decimal;
		power = pow(2, 32);
		count = 0;
		while(n<31){
			residual = residual % power;
			num = residual / power;
			power = power / 2;
			count++;
			printf("%d", num);
			if(count%8==0){
				printf(" ");
			}
		}
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		printf("Hexadecimal numeral: \n");
		residual = decimal;
		power = pow(16, 8);
		count = 0;
		while(n<7){
			residual = residual % power;
			num = residual / power;
			power = power / 16;
			if(num>=10){
				printf("%s", num - 10 + 'A');
			}
			else{
				printf("%s", num + '0');	
			}
			if(count%4==0){
				printf(" ");
			}
		}
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
