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
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
    
		for (i=0; i<strlen(str); i++) { // Search for the digit in s with the largest value.
			if (isdigit(str[i]) && (str[i]-'0')>=base) base = str[i] - '0' + 1; // A digitt.
			else if (isupper(str[i]) && (str[i]-'A'+10)>=base) base = str[i] - 'A' + 10 + 1; // An upper case letter.
			else if (islower(str[i]) && (str[i]-'a'+36)>=base) base = str[i] - 'a' + 10 + 26 + 1; // A lower case letter.
			else if (!isalnum(str[i])) { // Neither a digit nor an English letter.
				printf("The input string is an invalid numeral.\n\n"); // Output the error message.
				base = 0; // Set base to -0.
				break; // Stop checking the input data.
			}
		}

		// When base is between 2 and 62, convert the numeral to a decimal number.
		// When base is 1, terminate the program.
		// When base is 0, invalid input; try again.
		if (base>1) { //Base is between 2 and 62. 
			num = 0; // Initial the numeral value of 0.
			power = 1; // Initial power to 1.
			for (i=strlen(str)-1; i>=0; i--) { // Start the converion from the left-most digit.
				if (isdigit(str[i])) num = num + (str[i] - '0') * power; // The digit is 0 to 9.
				else if (isupper(str[i])) num = num + (str[i] - 'A' + 10) * power;  // Upper case letter, A to Z.
				else num = num + (str[i] - 'a' + 36) * power;  // Lower case letter, a to z.
				power = power * base; // Increment by 1, that is, multiplied by base.
			}
			printf("Base: %d, Decimal value: %llu\n", base, num); // Output the base and decimal value.
		}
		
		if (base>1) {
  			// Print binary numeral.
			residual = num; // Initial residual is n.
			power = pow(2, 63); // Initial power of binary numeral.
			count = 0; // Initial digit count is 0.
			printf("Binary numeral: "); // Print the prelude message.
			while (count<64) { // Print 32 bits.
				printf("%u", residual/power); // Print the left-most bit of the resudual.
				residual = residual % power; // Update the rest of bits.
				power = power / 2; // Decrement the degree of power by 1.
				count++; // Increment count.
				if (count%8==0) printf(" "); // Print a space if eight bits are printed.
			}
			printf("\n");
		
  			// Print hexadecimal numeral.
			residual = num; // Initial residual is n.
			power = pow(16, 15); // Initial power of hexadecimal numeral.
			count = 0; // Initial digit count is 0.
			printf("Hexadecimal numeral: "); // Print the prelude message.
			while (count<16) { // Print 16 digits.
				// Print the left-most hexadecimal digit of the resudual, for 0 to 9.
				if (residual/power<10) printf("%c", residual/power + '0');
				// Print the left-most hexadecimal digit of the residual, for A to F.
				else printf("%c", residual/power - 10 + 'A');
				residual = residual % power; // Update the rest of digits.
				power = power / 16; // Decrement the degree of power by 1.
				count++; // Increment count.
				if (count%4==0) printf(" "); // Print a space if four digits are printed.
			}
			printf("\n\n");
		}
	} while (base!=1); // Program terminates if the input numeral str is a string of 0's.
  
	return 0;
}
