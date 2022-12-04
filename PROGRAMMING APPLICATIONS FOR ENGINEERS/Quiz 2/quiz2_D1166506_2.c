#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum(). 

char dict[62]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"} ;
int digit[200]={0} ;

unsigned long long int power (int base , int pow)
{
	if (pow==0) return 1;
	unsigned long long int ans=1 ;
	while (pow!=0)
	{
		if (pow&1) ans *= base ;
		pow >>= 1 ;
		base *= base ;
	}
	return ans;
}

int main(void) {
	char s[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long n; // Integer value of the numeral (64-bit integer).
	int i; // Loop variable.
	
	for (i=0 ; i<62 ; ++i)
	{
		digit[(int)dict[i]] = i ;
	}
	
	while (1)
	{
		int base=-5; // Numeral base.
		unsigned long long int ans = 0 ;
		int flag=1 ;
		printf ("Enter a numeral (a string of digits and English letters): ") ;
		scanf ("%s" , s) ;
		for (i=0 ; i<strlen(s) ; ++i)
		{
			if (digit[s[i]]>base) base = digit[s[i]] ;
			if (!isalnum (s[i]))
			{
				printf ("The input data is an invalid numeral.\n\n") ;
				flag = 0 ;
				break ;
			}
		}
		if (!flag) continue ;
		if (base==0) break ;
		base++ ;
		for (i=0 ; i<strlen(s) ; ++i)
		{
			ans += digit[s[i]] * power (base , strlen(s)-i-1) ;
		}
		printf ("Base: %d, Decimal value: %lld\n\n" , base , ans) ;
	}
	return 0;
}
