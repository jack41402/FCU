#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int dectobin(unsigned long long dec, char bin[]){
	int i = 0;
	int binl, rsd;
	while(1){
		rsd= dec % 2;
		dec = dec / 2;
	    bin[i] = rsd;
	    printf("%d ", bin[i]);
	    i++;
	    if (dec == 0){
	    	break;
		}
	}
	binl = strlen(bin);
	return binl;
}
int main(void) {
	const int base=16; // Numeral base.
	char num[9], oldnum[9]; // Hexadecimal numeral as string of length 8.
	char binry[32] = {"0"};
	unsigned long long value, binlen; // Integer value of the numeral.
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
    	for(i=0; i<9; i++){
    		oldnum[i] = num[i];
		}
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros.
		value = 0;
		for(i=0; i<8; i++){
			if (num[i]>='A'){
				num[i] = num[i] - 'A' + 10; 
			}
			else {
				num[i] = num[i] - '0'; 
			}
			value = value + num[i] * pow(16,(7-i));
		} 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space.
		binlen = dectobin(value, binry);
		
		printf("The input hexadecimal numeral %s is of the decimal value %llu\n", oldnum, value); 
		printf("Binary value: ");
		for (i=31; i>=0; i--){
			printf("%c",binry[i] + '0');
			if (i%8 == 0){
				printf(" ");
			}
		}
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
