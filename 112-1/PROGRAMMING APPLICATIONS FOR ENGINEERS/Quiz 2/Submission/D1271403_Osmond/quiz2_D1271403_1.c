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
	int i; // Loop variable.
 
	 
	while (1) {
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
    	if (strcmp(num, "00000000")==0) break; 

  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	residual = value;
    	power = pow (2,31);
    	count = 0;
    	while (count<32) printf("%c", residual/power);
		}
    	residual = residual%power;
    	power = power / 2;
    	count++;
		
    	if(count%4==0) printf(" ");
    	printf("\n");
	 
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	/*if (strcmp(num, "00000000")==0) break;*/  
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
    	printf("The input Hexadecimal numeral %u is of the decimal value: ", value);
    	printf("Binary numeral:    ");
		printf("\n\n---------------------\n"); // Print a separate line.
	return 0;
}