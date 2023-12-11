#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned int hex2dec(char* num)
{
	unsigned int result = 0;
	int len = strlen(num);
	int i;
	
	for(i = 0; i < len; ++i)
	{
		result *= result *16;

		if(num[i] >= '0' && num[i] <= '9')
		{
			result += num[i] - '0';
		}
		else if(num[i] >= 'A' && num[i] <= 'F')
		{
			result += num[i] - 'A' + 10; 
		}
		else if(num[i] >= 'a' && num[i] <= 'f')
		{
			result += num[i] - 'a' + 10; 
		}
	}
	return result;
}

char* num(unsigned int num, char* value)
{
	int index = 0;
	int i, j;
	int residual = residual % 2;
			
	value *= value *2;
		
	for(i = 0, j = index; i < j; i++, j--)
	{
		value += index[++] + '0';
	}
	return value;
}

int main(void) 
{
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	int count; // digit count.
	int i; // Loop variable.
		
	while (1) 
	{
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", &num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000") == 0) 
		{
			break;
		}
		else
		{
			printf("The input hexadecimal nummeral %s is of the decimal value: %u\n", num, hex2dec(num));
		}
		
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
		
	/*char* num(unsigned int num, char* result)
	{
		int index = 0;
		int i, j;
		int residual = residual % 2;
			
		value *= value *2;
		
		for(i = 0, j = index; i < j; i++, j--)
		{
			result += index[++] + '0';
		}
		return value;
	}
	*/
	int temp;
		
	temp = value[i];
	value[i] = value[j];
	value[j] = temp;
	

	else
	{
		printf("Binary numeral:%c\t\t\n", dec2hex(num, temp));
	}
	    
		printf("\n\n---------------------\n"); // Print a separate line.
		
	}
	
	return 0;
}
/*

//The input hexadecimal nummeral %s is of the decimal value: %u\n
//Binary numeral:\t\t\n


//
unsigned int hex2dec(char* num)
{
	unsigned int result = 0;
	int len = strlen(num);
	int i;
	
	for(i = 0; i < len; ++i)
	{
		result *= result *16

		if(num[i] >= '0' && num[i] <= '9')
		{
			result += num[i] - '0';
		}
		else if(num[i] >= 'A' && num[i] <= 'F')
		{
			result += num[i] - 'A' + 10; 
		}
		else if(num[i] >= 'a' && num[i] <= 'f')
		{
			result += num[i] - 'a' + 10; 
		}
		return result;
	}
}
//

//
int main(void)//
{
	char num_string[40];//
	
	while(1)//
	{
		printf("Enter the hexadecimal number(0 tp exist): ")//
		scanf("%s", &num_string);//
		
		if(strcmp(num_string, "0") == 0)//
		{
			break;
		}
		else
		{
			printf("Hex to Dex is: %u\n", hex2dec(num_string));
		}
	}
	return 0;
}
//

//index num result remainder residual
char* num(unsigned int num, char* result)
{
	int index = 0;
	int i, j;
	int residual = residual % 2;
		
	value *= value *2;
	
	for(i = 0, j = index; i < j; i++, j--)
	{
		result += index[++] + '0';
	}
	return value;
}

int main(void)
{
	
	int temp;
	
	temp = result[i];
	result[i] = result[j];
	result[j] = temp;
	
	else
	{
		printf("Binary numeral:%c\t\t\n", dec2hex(num, temp));
	}
	return 0;
}
*/
