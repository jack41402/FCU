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
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    	
    	power = 1;
    	unsigned n = 0;
    	for(i=strlen(num)-1;i>=0;i--){
    		if(num[i]-'0'<10){
    			n = n+(num[i]-'0')*power;
			}
			else{
				n = n+(num[i]-'A'+10)*power;
			}
			power = power *base; 
		}
		printf("The input hexadecimal numeral %s is of the decimal value: %u\n",num,n);
		printf("Binary numeral:      ");
		residual = n;
    	count = 0;
    	power = pow(2,31);
    	while(count<32){
    		printf("%u",residual/power);
    		residual = residual%power;
    		power = power/2;
    		count++;
    		if(count%8==0){
    			printf(" ");
			}
		}
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
