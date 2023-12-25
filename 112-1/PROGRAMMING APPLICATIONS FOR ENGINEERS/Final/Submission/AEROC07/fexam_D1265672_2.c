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
	int flag;
	
	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		flag = 0;
		for (i=0; i<strlen(str); i++){
			if (!isdigit(str[i])  && !isalpha(str[i])){
			printf("The input string is an invalid numeral.\n\n");
			flag = 1;
			break;
			}
			if (isdigit(str[i])){
				if (base < str[i]-'0'){
					base = str[i]-'0';
				}
			}
			else if (str[i] > 'a'){
				if (base < str[i]-'a'){
					base = str[i]-'a'+36;
				}
			}
			else if (str[i] > 'A'){
				if (base < str[i]-'A'){
					base = str[i]-'A'+10;
				}
			}
		}
		base+=1;
		if (flag){
			continue;
		}
		// c. Output the values of base and num.
		
		print("Base: %d, Decimal value: %d",base,decimal);
		print("\n");
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		print("Binary numeral: ");
		for(i=0;i<65;i++){
			if (i%8==0){
				printf(" ");
			}
			print(x[i]);
		}
		print("\n");
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		print("Hexadecimal numeral: ");
		for(i=0;i<17;i++){
			if (i%4==0){
				printf(" ");
			}
			print(x[i]);
		}
		print("\n");
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
