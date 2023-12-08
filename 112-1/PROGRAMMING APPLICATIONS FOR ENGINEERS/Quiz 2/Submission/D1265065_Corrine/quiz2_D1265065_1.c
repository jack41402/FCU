#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	char bin[33];
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	unsigned decimal;
	int count; // digit count.
	unsigned num1;
	int i, j; // Loop variable.
	int tmp;

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
		
		printf("The input hexadecimal numeral %s is of the decimal value: ", num);
		decimal = 0;
		for(i = 0; i < strlen(num); i++){
			decimal *= 16;
			decimal += num[i] > '9' ? num[i] - 'A' + 10 : num[i] - '0';
		}
		printf("%u", decimal);
		printf("\n");
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
	/*	residual = num;
		power = pow(2, 32);
		printf("Binary numeral: ");
		for(i = 0; i < strlen(num); i++){
			value = residual / power + residual;
			residual = residual % power;
			power = power/2;
		}
		printf("%u", value);*/
		count = 0;
		printf("Binary numeral:    ");
		for(i = 0; i<strlen(bin); i++){
			if(!num1) strcpy(bin, "0");
			bin[i] = decimal % 2 ;
			decimal /= 2;
			count++;
		}
		bin[strlen(bin)] = '\0';
	
		for(i = 0, j = strlen(bin)-1; i<j; i++, i--){
			tmp = bin[i];
			bin[i] = bin[j];
			bin[j] = tmp;
		}
		for(i = 0; i < strlen(bin); i++){
		if(count%8 == 0) printf(" ");
		printf("%c", bin[i]);
		}
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
