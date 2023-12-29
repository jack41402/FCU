#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Print each character c for n times
void printChar(int n, char c) //void as doesn't return any value when print each character was called
{
 	int i; //Declare i in the use of for loop variable
 
 	for(i = 0; i < n; i++) printf("%c", c); //Each iteration print one character c
}

//Function to convert a hexadecimal string to its decimal value
unsigned long long hexadecimal2decimal(char *hexadecimal) 
{
  	unsigned long long decimal = 0; //The initial decimal value is 0
  	int i; //Declare i in the use of for loop variable
  
  	for(i = 0; i<strlen(hexadecimal); i++) 
	{
		if(hexadecimal[i] >= 'A' && hexadecimal[i <= 'F'])
        {
        	decimal = decimal * 16 + (hexadecimal[i] - 'A' + 10); //Update decimal value for hexadecimal characters A-F
		}
		else
		{
			decimal = decimal * 16 + (hexadecimal[i] - '0'); //Update decimal value for hexadecimal characters 0-9
		}
	}
  	return decimal; //Return the decimal value
}

int main (void) 
{
  	char n1[18], n2[18]; //Declare arrays to store binary numerals, maximum 17 characters
  	char sum[19]; //Declare array to store the sum, maximum 18 characters
  	int length1, length2; //Declare variables to store the length of strings n1 and n2
  	int lengthmin, lengthmax; //Declare variables for minimum and maximum lengths
 	int carry; //Declare variable for carry bit.
  	int digitsum; // Sum of single digit.
  	int i; //Declare i in the use of for loop variable
  
  	while (scanf("%s %s", n1, n2) == 2)//Read numbers as strings until both are 0
	{
	  	if(strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0) break; //If both numbers are 0, terminate the program
	  	
	  	length1 = strlen(n1); //Length of n1
	  	length2 = strlen(n2); //Length of n2
	  	if(length1 >= length2) {lengthmin = length2; lengthmax = length1;} //Set minimum and maximum lengths
	  	else{lengthmin = length1; lengthmax = length2;}
	  	carry = 0; //Reset the carry to 0.
	  	
		for(i = 0; i < lengthmax; i++) //Loop through digits of the numbers and calculate the sum
		{
		    if(i < lengthmin) //Add digits if both numbers have digits remaining
		    {
		        int digit_n1 = (n1[length1 - (i + 1)] >= 'A' ? n1[length1 - (i + 1)] - 'A' + 10 : n1[length1 - (i + 1)] - '0');
		        int digit_n2 = (n2[length2 - (i + 1)] >= 'A' ? n2[length2 - (i + 1)] - 'A' + 10 : n2[length2 - (i + 1)] - '0');
		        sum[lengthmax - (i + 1)] = digit_n1 + digit_n2 + carry;
		    }
		    else if(i < length1) //If n1 is larger, process remaining digits in n1
		    {
		        int digit_n1 = (n1[length1 - (i + 1)] >= 'A' ? n1[length1 - (i + 1)] - 'A' + 10 : n1[length1 - (i + 1)] - '0');
		        sum[lengthmax - (i + 1)] = digit_n1 + carry;
		    }
		    else if(i < length2) //If n2 is larger, process remaining digits in n2
		    {
		        int digit_n2 = (n2[length2 - (i + 1)] >= 'A' ? n2[length2 - (i + 1)] - 'A' + 10 : n2[length2 - (i + 1)] - '0');
		        sum[lengthmax - (i + 1)] = digit_n2 + carry;
		    }
		    else //If both numbers processed and there's still a carry, add it
		    {
		        sum[lengthmax - (i + 1)] = carry;
		    }
		
		    carry = sum[lengthmax - (i + 1)] / 16; //Calculate the next carry
			//Convert sum to hexadecimal representation
			sum[lengthmax - (i + 1)] = (sum[lengthmax - (i + 1)] % 16 >= 10) ? (sum[lengthmax - (i + 1)] % 16 - 10 + 'A') : (sum[lengthmax - (i + 1)] % 16 + '0');
		    
		}
		if (carry == 1) //If there's a carry after processing all digits, adjust the sum
		{
		 	sum[lengthmax+1] = '\0'; //End-of-string occupies one bit more
		  	for (i = lengthmax; i > 0; i--) sum[i] = sum[i - 1]; //Move the bits of sum one position to the right
		  	sum[0] = '1'; //Put the carry bit to the most significant bit
	    }
	    else sum[lengthmax] = '\0'; //Insert end-of-string
	    
	    //Print the formatted output
	    printChar(length2 - length1, ' '); //If n2 is longer than n1, print blanks to ensure a pretty format
	    printChar(carry + 2, ' '); //Print 2 or 3 blanks depending on carry
	    printf("%s\n", n1); //Print n1
	    printf("+"); //Print "+" sign as addition calculation
	    printChar(length1 - length2, ' '); //If n1 is longer than n2, print blanks to ensure a pretty format
	    printChar(carry + 1, ' '); //Print 1 or 2 blanks depending on carry
	    printf("%s\n", n2); //Print n2
	    printChar(lengthmax + carry + 2, '-'); //Print separate line to separate the sum and the num
	    printf("\n  %s\n", sum); //Print two blanks and the sum.
	    printf("%llu + %llu = %llu", //Print the addition of n1, n2 in decimal
		       hexadecimal2decimal(n1), hexadecimal2decimal(n2), hexadecimal2decimal(sum));
	
		if(strlen(sum) >= 17) printf("    ****Overflow!!!\n\n"); //Indicate that an overflow occurred
	    else printf("\n\n"); // Print newline
  	}
  return 0;//To indicate successful execution
}
