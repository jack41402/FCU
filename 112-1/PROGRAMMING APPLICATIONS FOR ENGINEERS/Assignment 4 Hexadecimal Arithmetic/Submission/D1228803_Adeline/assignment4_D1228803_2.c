#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Print each character c for n times
void printChar(int n, char c) //void as doesn't return any value when print each character was called
{
 	int i; //Declare i in the use of for loop variable
 
 	for (i=0; i<n; i++) printf("%c", c); //Each iteration print one character c.
}

//Function to convert a hexadecimal string to its decimal value
unsigned long long hexadecimal2decimal(char *hexadecimal) 
{
  	unsigned long long decimal = 0; //The initial decimal value is 0
  	int i; //Declare i in the use of for loop variable
  
  	for (i=0; i<strlen(hexadecimal); i++) 
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

// Function to perform hexadecimal addition of two numbers
void hexadecimal_addition(char *n1, char *n2, char *sum) 
{
  
	int length1, length2;
	int lengthmin, lengthmax; 
	int carry;
	int digitsum;
	int i;
	  
	length1 = strlen(n1);
	length2 = strlen(n2);
	strcpy(sum, "0"); //Initialize sum to "0"
	//Determine the minimum and maximum lengths of the two numbers
	if (length1 >= length2) 
	{
		lengthmin = length2; lengthmax = length1;
	}
	else 
	{
		lengthmin = length1; lengthmax = length2;
	}
	carry = 0; //Reset carry to 0
	
	//Loop through digits of the numbers and calculate the sum
	for (i = 0; i < lengthmax; i++)
		{
		    if (i < lengthmin) //Add digits if both numbers have digits remaining
		    {
		        int digit_n1 = (n1[length1 - (i + 1)] >= 'A' ? n1[length1 - (i + 1)] - 'A' + 10 : n1[length1 - (i + 1)] - '0');
		        int digit_n2 = (n2[length2 - (i + 1)] >= 'A' ? n2[length2 - (i + 1)] - 'A' + 10 : n2[length2 - (i + 1)] - '0');
		        sum[lengthmax - (i + 1)] = digit_n1 + digit_n2 + carry;
		    }
		    else if (i < length1) //If n1 is larger, process remaining digits in n1
		    {
		        int digit_n1 = (n1[length1 - (i + 1)] >= 'A' ? n1[length1 - (i + 1)] - 'A' + 10 : n1[length1 - (i + 1)] - '0');
		        sum[lengthmax - (i + 1)] = digit_n1 + carry;
		    }
		    else if (i < length2) //If n2 is larger, process remaining digits in n2
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

			// The i-th digit of the sum.
		    
		}
		if (carry>=1) //If there's a carry after processing all digits, adjust the sum
		{ 
		 	sum[lengthmax + 1] = '\0'; //End-of-string occupies one bit more.
		  	for (i = lengthmax; i > 0; i--) sum[i] = sum[i - 1]; //Move the bits of sum one position to the right
		  	sum[0] = carry; //Put the carry bit to the most significant bit
	    }
	    else sum[lengthmax] = '\0'; //Insert end-of-string

}

//Function to perform product of a hexadecimal number and a hexadecimal digit
void hexadecimal_digit_product(char *n, char d, char *product, int p) 
{

	int leng;
	int carry;
	int digitproduct;
	int i;
  
  	leng = strlen(n);
  	if (d != '0') 
	{
    carry = 0;
    for (i = 0; i < leng; i++) //Loop through digits and calculate product
	{ 	
		 //Calculate the product of the current digits and add the carry
    	digitproduct = (n[leng - i - 1] >= 'A' ? n[leng - i - 1] - 'A' + 10 : n[leng - i - 1] - '0') * (d >= 'A' ? d - 'A' + 10 : d - '0') + carry;
      	// Update the carry for the next iteration
      	carry = digitproduct / 16;
      	//Store the result digit in the product array
      	product[leng - i - 1] = (digitproduct % 16 >= 10) ? (digitproduct % 16 - 10 + 'A') : (digitproduct % 16 + '0');
	}
	
	if (carry >= 1) //Check if there is a carry after the loop
	{
		//Adjust the product array to accommodate the carry
	  	for (i = 0; i <= leng; i++) product[leng - i] = product[leng - i - 1];
		//Update the most significant digit with the carry
	  	product[0] = (carry >= 10) ? (carry - 10 + 'A') : (carry + '0');
	  	leng++; //Increment the length of the product.
	}
	//Add trailing zeros for positioning in multiplication
	for (i = 0; i < p; i++) product[leng + i] = '0';

	product[leng + p] = '\0';
    }
  	else strcpy(product, "0");
}

//Main function
int main (void) 
{
  	char n1[17], n2[17];
  	char product[18];
  	char partial_product[18];
  	char digit_product[18];
  	int length1, length2, leng;
  	int swap;
  	int i;
  	
  	//Read hexadecimal numbers as strings until both are 0
  	while (scanf("%s %s", n1, n2)==2) 
	{ 
	  	if(strcmp(n1, "0")==0 && strcmp(n2, "0")==0) 
		break; //Terminate the program if both numbers are 0
	  	
	  	length1 = strlen(n1);
	  	length2 = strlen(n2);
	  	swap = 0;
	  	
	  	//Swap numbers if the second one is longer
	  	if(length2 > length1) 
		{ 
	  	  	swap = 1;
	  	  	strcpy(product, n2); 
	  	  	strcpy(n2, n1);
	  	  	strcpy(n1, product);
	  	  	i = length2;
	  	  	length2 = length1;
	  	  	length1 = i;
	    }
	  	strcpy(product, "0");
	  	
	  	//Loop through digits of the second number and calculate the product.
	  	for(i=0; i < length2; i++) 
		{
	  	  	strcpy(partial_product, "0");
	  	  	hexadecimal_digit_product(n1, n2[length2 - i - 1], digit_product, i); 
	  	  	hexadecimal_addition(product, digit_product, partial_product); 
	  	  	strcpy(product, partial_product); 
		}
	    leng = strlen(product);
	    //Print the numbers and the product
	    if(swap) 
		{
	    	printChar(leng-length2 + 2, ' '); //Print spaces to align the second number with the first
	      	printf("%s\n", n2); //Print the second number (multiplier)
	      	printf("*"); //Print the multiplication symbol
	      	printChar(leng-length1+1, ' '); //Print spaces to align the first number (multiplicand) with the second
	      	printf("%s\n", n1); //Print the first number (multiplicand)
		}
		else 
		{ 
	      	printChar(leng - length1 + 2, ' '); //Print spaces to align the first number with the second
	      	printf("%s\n", n1); //Print the first number (multiplicand)
	      	printf("*"); //Print the multiplication symbol
	      	printChar(leng - length2 + 1, ' '); //Print spaces to align the second number with the first
	      	printf("%s\n", n2); //Print the second number (multiplier)
		}
	    printChar(leng + 2, '-'); //Print a line to separate the numbers from the product
	    printf("\n  %s\n", product);
	    //Print the decimal values of the numbers and the product
	    if(swap)
	    {
	    	//Print the multiplication expression in decimal form when the second number is the multiplier
	    	printf("%llu * %llu = %llu\n\n", hexadecimal2decimal(n2), hexadecimal2decimal(n1), hexadecimal2decimal(product));
		}
	    else
	    { 
	    	//Print the multiplication expression in decimal form when the first number is the multiplier
		  	printf("%llu * %llu = %llu\n\n", hexadecimal2decimal(n1), hexadecimal2decimal(n2), hexadecimal2decimal(product));
	  	}
	}	
  return 0;
}
 

