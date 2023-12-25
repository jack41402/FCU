#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int main(void) {
	int base; // Numeral base.
	char str[65], ostr[65], string[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	int binary[64], hex[16];
	unsigned long long num; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i, a = 0; // Loop variable.
	int max = 0;
	int decb, rsdb, rsdh;

	do {
		for(i=0; i<64; i++) binary[i] = 0;
		for(i=0; i<16; i++) hex[i] = 0;
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		count = strlen(str);
		for(i=0; i<count; i++){
			if(isalpha(str[i]) || isdigit(str[i])) string[a] = str[i];
			a++;
		}
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		for(i=0; i<a; i++){
			ostr[i] = string[i];
			if(string[i]>='A' && string[i]<='Z') string[i] = string[i] - 'A' + 10;
			else if(string[i]<=a &&string[i]<='z') string[i] = string[i] - 'a' + 36;
			else string[i] = string[i] - '0';
			if (string[i] > max) max = string[i];
		}
		base = max + 1;
		int obase = base;
		base = 1;
		for(i=a-1; i>=0; i--){
			num += string[i] * base;
			base = base * obase;
		}
		// c. Output the values of base and num.
		printf("Base %d, Decimal value, %d", obase, num);
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		int x = 0;
		int onum = num;
		while(num>0){
			rsdb = num % 2;
			num = num / 2;
			binary[x] = rsdb;
			x++;
		}
		printf("\nBinary value: ");
		for(i=63; i>=0; i--){
			printf("%d", binary[i]);
			if(i%8 == 0) printf(" ");
		}
		printf("\n");
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space
		//    after every four digits.
		x = 0;
		while(onum>0){
			rsdh = onum % 16;
			onum = onum / 16;
			hex[x] = rsdh;
			x++;
		}
		printf("Hexadecimal value: ");
		for(i=15; i>=0; i--){
			if(hex[i]>=10 && hex[i]<=15) hex[i] = hex[i] - 10 +'A';
			else hex[i] = hex[i] + '0';
			printf("%c", hex[i]);
			if(i%4 == 0) printf(" ");
		}
		printf("\n\n\n");
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
