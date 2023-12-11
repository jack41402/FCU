#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


unsigned int hex2dec(char* num, unsigned int result)
{
	int i;
	unsigned int decimal;
	decimal = 0;
	for(i = 0; i < 8; ++i)
	{
		decimal = decimal * 16;
		decimal += (((num[i] >= '0') && (num[i] <= '9')) ? num[i] - '0' : num[i] - 'A' + 10);
	}
	return decimal;
}

char *dec2bin(unsigned int num, char* result)
{
	int i, j;
	char tmp;
	if(!num)
	{
		strcpy(result, "0");
	}
	for(i = 0; num; ++i)
	{
		result[i] = num % 2 + '0';
		num /= 2;
	}
	result[i] = '\0';
	
	for(i = 0, j = sizeof(num); i < j; ++i, --j)
	{
		tmp = result[i];
		result[i] = result[j];
		result[j] = tmp;
	}
	return result;
} 

int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	int count; // digit count.
	int i; // Loop variable.
	char bin[33];
	
	
	while (1) {
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
		printf("The input hexadecimal numeral %s is of the decimal value : ", num);
		hex2dec(num, value);
		printf("%u\n", value);
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
		printf("Binary numeral :      ");
		dec2bin(value, bin);
		printf("%s", bin);
    	
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}

