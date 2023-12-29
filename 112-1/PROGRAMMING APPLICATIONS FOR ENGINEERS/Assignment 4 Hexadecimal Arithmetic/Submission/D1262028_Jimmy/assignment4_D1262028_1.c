#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char n1[17], n2[17]; // Inupt hexadecimal numerals, maximum 16 bits.
char s[18]; // sum = n1 + n2, maximum number of bits of sum is 17.
int l1, l2; // Length of string n1 and n2.
int lmax, lmin; // lmin=min(l1, l2), lmax=max(l1, l2).
int i; // Loop variable.
int c; // Carry bit.

void printChar(int n, char c)
{
	for (i=0; i<n; ++i) // Print n times of character c.
	{
		printf("%c", c); // Each iteration print one character c.
	}
}

// Convert a hexadecimal string to its decimal value.
unsigned long long Hex2decimal(char *Hex) 
{
  	unsigned long long decimal = 0; // Decimal value initial to 0.

  	for(i=0; i<strlen(Hex); i++) 
	{
		if((Hex[i] >= '0') && (Hex[i] <= '9'))
		{
			decimal = decimal *16 + Hex[i] - '0';
		}
		else if((Hex[i] >= 'A') && (Hex[i] <= 'F'))
		{
			decimal = decimal *16 + Hex[i] - '7';
		}
	}
  	return decimal;
}

int main(void)
{
	while(scanf("%s %s", &n1, &n2)==2) // Read two binary numbers as 0-1 strings.
	{
		if(strcmp(n1,"0") == 0 && strcmp(n2,"0") == 0)
		{
			break; // If the two numbers are both 0, terminate the program.
		}

		l1 = strlen(n1); // Length of n1.
		l2 = strlen(n2); // Length of n2.
		// Function to add two hexadecimal numbers
		lmax = (l1 > l2) ? l1 : l2; // Find the maximum length to determine the size of the result
		lmin = (l1 > l2) ? l2 : l1; // Find the minimum length to determine the size of the result
		c = 0; // Reset the carry to 0.
		
		for(i=0; i<lmax; i++)
		{
			if(i<lmin) // Add the i-th bit for both n1 and n2, counting from the least significant bit.
			{
				if(((n1[l1-(i+1)] >= '0') && (n1[l1-(i+1)] <= '9')) && ((n2[l2-(i+1)] >= '0') && (n2[l2-(i+1)] <= '9')))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - '0') + (n2[l2-(i+1)] - '0') + c;
				}
				else if(((n1[l1-(i+1)] >= 'A') && (n1[l1-(i+1)] <= 'F')) && ((n2[l2-(i+1)] >= '0') && (n2[l2-(i+1)] <= '9')))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - 'A' + 10) + (n2[l2-(i+1)] - '0') + c;
				}
				else if(((n1[l1-(i+1)] >= '0') && (n1[l1-(i+1)] <= '9')) && ((n2[l2-(i+1)] >= 'A') && (n2[l2-(i+1)] <= 'F')))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - '0') + (n2[l2-(i+1)] - 'A' + 10) + c;
				}
				else if(((n1[l1-(i+1)] >= 'A') && (n1[l1-(i+1)] <= 'F')) && ((n2[l2-(i+1)] >= 'A') && (n2[l2-(i+1)] <= 'F')))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - 'A' + 10) + (n2[l2-(i+1)] - 'A' + 10) + c;
				}
			}
			else if(i<l1) // n1 is larger than n2, process reset of bits in n1.
			{
				if((n1[l1-(i+1)] >= '0') && (n1[l1-(i+1)] <= '9'))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - '0') + c;
				}
				else if((n1[l1-(i+1)] >= 'A') && (n1[l1-(i+1)] <= 'F'))
				{
					s[lmax-(i+1)] = (n1[l1-(i+1)] - 'A' + 10) + c;
				}
			}
			else if(i<l2) // n2 is larger than n1, process reset of bits in n2.
			{
				if((n2[l2-(i+1)] >= '0') && (n2[l2-(i+1)] <= '9'))
				{
					s[lmax-(i+1)] = (n2[l2-(i+1)] - '0') + c;
				}
				else if((n2[l2-(i+1)] >= 'A') && (n2[l2-(i+1)] <= 'F'))
				{
					s[lmax-(i+1)] = (n2[l2-(i+1)] - 'A' + 10) + c;
				}
			}
			c = s[lmax-(i+1)] / 16; // Next carry.
			if((s[lmax-(i+1)] % 16) <= 9)
			{
				s[lmax-(i+1)] = s[lmax-(i+1)] % 16 + '0'; // The i-th bit of the sum if sum is smaller than or equal to 9.
			}
			else if((s[lmax-(i+1)] % 16) >= 10)
			{
				s[lmax-(i+1)] = s[lmax-(i+1)] % 16 + 'A' - 10; // The i-th bit of the sum if sum is greater than or equal to 10.
			}
		} 
		if(c==1)
		{
			s[lmax+1] = '\0';
			for (i=lmax; i>0; i--)
			{
				s[i] = s[i-1];// Move the bits of sum one position to the right.
			}
			s[0] = '1'; // Put the carry bit to sum.
		}
		else
		{
			s[lmax] = '\0'; // Insert end-of-string.
		}
		
		printChar(l2-l1, ' '); // If n2 is longer than n1, print blanks.
		printChar(c+2, ' '); // Print 2 or 3 blanks depending on carry.
	    printf("%s\n", n1); // Print n1.
	    printf("+"); // Print "+" sign.
	    printChar(l1-l2, ' '); // If n1 is longer than n2, print blanks.
	    printChar(c+1, ' '); // Print 1 or 2 blanks depending on carry.
	    printf("%s\n", n2); // Print n2.
	    printChar(lmax+c+2, '-'); // Print separate line.
	    printf("\n  %s\n", s); // Print two blanks and the sum.
	    printf("%llu + %llu = %llu", Hex2decimal(n1), Hex2decimal(n2), Hex2decimal(s)); // Print n1+n2=sum in decimal.
	    if (strlen(s)>16)
	    {
	    	printf("    **** Overflow!!!\n\n"); // Check and print overflow message.
		}
		else
		{
			printf("\n\n"); // Print newline.
		}
	}
	return 0;
}
