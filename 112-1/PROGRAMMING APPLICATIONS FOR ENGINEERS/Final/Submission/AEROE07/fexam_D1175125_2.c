#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int main(void) {
	int base; // Numeral base.
	char s[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long n; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i,j; // Loop variable.
	char c[65];
	int b[64];
	char h[16];
	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", s); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		n=0;
		power=0;
		for(i=strlen(s)-1;i>=0;i--){
			if(!isalnum(s[i])){printf("The input string is an invalid numeral.\n\n");break;
			}
			if(isdigit(s[i])){c[i]=s[i]-'0';
			}
			else if(isupper(s[i])){c[i]=s[i]-'A'+10;
			}
			else{c[i]=s[i]-'a'+36;
			}
			if (c[i]+1>base){base=c[i]+1;
			}
		}
		for(i=strlen(s)-1;i>=0;i--){
			n+=c[i]*pow(base,power);
			power+=1;
		}

		if(base==1)break;
		// c. Output the values of base and num.
		printf("Base: %d, Decimal value: %u\n",base,n);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		for(i=0;i<64;i++)b[i]=0;
		i=63;
		while(n!=0){
			b[i]=n%2;
			n/=2;
			i--;
		}
		printf("Binary numeral: ");
		for(i=0;i<64;i++){
		if((i+1)%8==0){
			printf("%d ",b[i]);
		}
		else{
			printf("%d",b[i]);
		}
		n/=2;
		}
		printf("\n");
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		i=0;
		int hs;
		while(i<16){
			hs=0;
			for(j=0;j<4;j++){
				hs+=b[j+i*4]*pow(2,3-j);
			}
			if(hs>10)h[i]=hs-10+'A';
			else h[i]=hs;
			i++;
		}
		printf("Hexidecimal numeral: ");
		for(i=0;i<16;i++){
		if((i+1)%4==0){
			printf("%d ",h[i]);
		}
		else{
			printf("%d",h[i]);
		}
		}
		printf("\n");
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
