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
	unsigned long long int ans = 0;
	char s;
	char ansb[33] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','\0'};

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
		ans = 0;
		int k;
		for (i=0; i < strlen(num); i++){
			s = (num[i] > '9')?'7':'0';
			k = num[i] - s;
			ans = (ans * 16) + k;
		}
		
		printf("The input hexadecimal numeral %s is of the decimal value: %d\n", num, ans);
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
		for (i=0; ans; i++){
			ansb[i] = ans % 2 + '0';
			ans = ans / 2;
		}

		printf("Binary numeral:      ");
		for (i=1;i<33;i++){
			printf("%c", ansb[32-i]);
			if (i%8==0){
				printf(" ");
			}
		}
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
