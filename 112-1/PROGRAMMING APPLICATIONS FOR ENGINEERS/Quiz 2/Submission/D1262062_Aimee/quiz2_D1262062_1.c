#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned int hex2dec(char*num)
{
	unsigned int decimal = 0;
	int i;
	for(i=0; i<strlen(num); ++i)
	{
		if(num[i]<= '9') decimal = decimal*16 + num[i] - '0';
		else decimal = decimal*16 + num[i] - 'A' + 10;
		
	}
	return decimal;
}

char* dec2binary(unsigned int num, char*result)
{
	int i, j, tmp;
	if(!num) strcpy(result, "0");
	for(i=0; num; ++i)
	{
		result[i] = num % 2 + '0';
		num /= 2;
	}
	result[i] = '\0';
	for(i = 0, j = strlen(result) - 1; i<j; ++i, --j)
	{
		tmp = result[j];
		result[j] = result[i];
		result[i] = tmp;
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
	int i, j; // Loop variable.
	char result[40];
	while (1) {
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    	value = hex2dec(num);
    	printf("The input hexadecimal numeral %s is of the decimal value %u", num, value);// ***** Complete the rest of the program.
	 	printf("\n");
		printf("Binary numeral:      ");
		count = 0;
		j = 0;
		for(i=0; i<32; ++i)
		{
			if(i<32-strlen(dec2binary(value, result))) printf("0");
			else 
			{
				printf("%c", dec2binary(value, result)[j]);
				j++;
			}
			count++;
			if(count%8 == 0)printf(" ");
		}
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
