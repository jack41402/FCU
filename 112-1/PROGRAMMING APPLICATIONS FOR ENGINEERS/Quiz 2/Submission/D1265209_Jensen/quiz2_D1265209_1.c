#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	int count; // digit count.
	int i,j; // Loop variable.

	while (1) {
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    
    	// ***** Complete the rest of the program.
		int result;
		for(i=0; i<strlen(num); i++){
			if(num[i]>='0' && num[i]<='9')
			result = result * 16 + (num[i] - '0');
			else if(num[i]>='A' && num[i]<='F')
			result = result * 16 + (num[i] - 'A' + 10);	
		}
		printf("The input hexadecimal numeral %s is of the decimal value: %u\n", num, result);
		char tmp;
		char bin[33];
		for(i=0; i<32; i++){
			bin[i] = (result % 2) + '0';
			result = result / 2;
		}
		for(i=0, j=32; i<j; i++, j--){
			tmp = bin[i];
			bin[i] = bin[j];
			bin[j] = tmp;
		}
		printf("Binary number:      %s", bin);
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
