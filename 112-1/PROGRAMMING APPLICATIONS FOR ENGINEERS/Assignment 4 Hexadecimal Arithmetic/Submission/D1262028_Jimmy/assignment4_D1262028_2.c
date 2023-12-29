#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char n1[9], n2[9]; // Inupt hexadecimal numerals, maximum 8 bits.
int p[17]; // product = n1 * n2, maximum number of bits of sum is 16.
char s[17]; // product = n1 * n2, maximum number of bits of sum is 16.
int l1, l2, lp, ls; // Length of string n1, n2, p and s.
int i, j; // Loop variable.
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
    
    for(i = 0; i < strlen(Hex); i++) 
    {
        decimal = decimal * 16;
        if (Hex[i] >= '0' && Hex[i] <= '9')
        {
            decimal += Hex[i] - '0';
        }
        else if (Hex[i] >= 'A' && Hex[i] <= 'F')
        {
            decimal += Hex[i] - 'A' + 10;
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
		
		for(i=0; i<17; i++) 
		{
			p[i]=0;// Reset each number in p ary.
		}
		
		l1 = strlen(n1); // Length of n1.
		l2 = strlen(n2); // Length of n2.
		lp = l1 + l2 - 1;
		ls = lp; // Length of s.
		// Function to add two hexadecimal numbers

		c = 0; // Reset the carry to 0.
		
		//multiply n1 and n2 and store the number into p.
		for(i=0; i<=l1; ++i)
		{
			for(j=0; j<=l2; ++j)
			{
				if(((n1[l1-i-1] >= '0') && (n1[l1-i-1] <= '9')) && ((n2[l2-j-1] >= '0') && (n2[l2-j-1] <= '9')))
				{
					p[l1-i+l2-j-2] += (n1[l1-i-1] - '0') * (n2[l2-j-1] - '0');
				}
				else if(((n1[l1-i-1] >= 'A') && (n1[l1-i-1] <= 'F')) && ((n2[l2-j-1] >= '0') && (n2[l2-j-1] <= '9')))
				{
					p[l1-i+l2-j-2] += (n1[l1-i-1] - 'A' + 10) * (n2[l2-j-1] - '0');
				}
				else if(((n1[l1-i-1] >= '0') && (n1[l1-i-1] <= '9')) && ((n2[l2-j-1] >= 'A') && (n2[l2-j-1] <= 'F')))
				{
					p[l1-i+l2-j-2] += (n1[l1-i-1] - '0') * (n2[l2-j-1] - 'A' + 10);
				}
				else if(((n1[l1-i-1] >= 'A') && (n1[l1-i-1] <= 'F')) && ((n2[l2-j-1] >= 'A') && (n2[l2-j-1] <= 'F')))
				{
					p[l1-i+l2-j-2] += (n1[l1-i-1] - 'A' + 10) * (n2[l2-j-1] - 'A' + 10);
				}
			}
		}
		
		//calculate each number in p and store the char into s.
		for(i = lp; i > 0; --i)
		{
			p[i-1] += c;
			c = p[i-1] / 16;
			
			if((p[i-1] % 16 >= 0) && (p[i-1] % 16 <= 9))
			{
				s[i-1] = p[i-1] % 16 + '0';
			}
			else if((p[i-1]%16 >= 10) && (p[i-1]%16 <= 15))
			{
				s[i-1] = p[i-1] % 16 + 'A' - 10;
			}
		}
		
		//Check if carry in >= 1 in the first bit
		if(c >= 1)
		{
			s[ls+1] = '\0';
			for (i=ls; i>0; i--)
			{
				s[i] = s[i-1];// Move the bits of sum one position to the right.
			}
			if((c >= 1) && (c <= 9))
			{
				s[0] = c + '0'; // Put the carry bit to sum.
			} 
			else if((c >= 10) && (c <= 15))
			{
				s[0] = c + 'A' - 10;
			}
			ls+=1; //add string length of s.
		}
		else
		{
			s[ls] = '\0'; // Insert end-of-string.
		}
	
		printChar(ls-l1, ' '); // If n2 is longer than n1, print blanks.
		printChar(2, ' '); // Print 2 or 3 blanks depending on carry.
	    printf("%s\n", n1); // Print n1.
	    printf("*"); // Print "*" sign.
	    printChar(ls-l2, ' '); // If n1 is longer than n2, print blanks.
	    printChar(1, ' '); // Print 1 or 2 blanks depending on carry.
	    printf("%s\n", n2); // Print n2.
	    printChar(ls+2, '-'); // Print separate line.
	    printf("\n  %s\n", s); // Print two blanks and the product.
	    printf("%llu * %llu = %llu", Hex2decimal(n1), Hex2decimal(n2), Hex2decimal(s)); // Print n1*n2=product in decimal.
	    printf("\n\n");
	}
	return 0;
}
