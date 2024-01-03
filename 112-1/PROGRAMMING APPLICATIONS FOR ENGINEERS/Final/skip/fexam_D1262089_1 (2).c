#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().


int max(int x, int y) {
	if (x>y) return x;
	else return y;
}


int main(void) {
	int base; // Numeral base.
	char str[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long num; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i; // Loop variable.

	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		
		for(i=0;i<strlen(str);i++){
			if((str[i]-'0'<=61)&&(str[i]-'0'>=0)){
				
				
						
		int max1=0;
		int max2=0;
		for(i=0;i<strlen(str);i++){
			if(isdigit(str[i])){
			max1=str[i]-'0';
			}else if(isupper(str[i])){
			max1=str[i]-'A'+10;
			}else if(islower(str[i])){
			max1=str[i]-'a'+36;
			}
			max2=max(max1,max2);
		}
		base=max2+1;
		
		// c. Output the values of base and num.
		num=0;
		for(i=0;i<strlen(str);i++){
			if(isdigit(str[i])){
			num=num*base+(str[i]-'0');
			}else if(isupper(str[i])){
			num=num*base+(str[i]-'A')+10;
			}else if(islower(str[i])){
			num=num*base+(str[i]-'a')+36;
			}
		}
		
		
		printf("Base: %d, Decimal value:%u\n",base,num);
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		printf("Binary numeral:");
		power=pow(2,63);
		residual=num;
		for(i=0;i<64;i++){
			count=residual/power;
			printf("%d",count);
			residual=residual%power;
			if(i%8==7){
			printf(" ");
			}
			power/=2;
		}
		printf("\n");
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		printf("hexadecimal numeral:");
		power=pow(16,15);
		residual=num;
		for(i=0;i<16;i++){
			count=residual/power;
			printf("%d",count);
			residual=residual%power;
			if(i%4==3){
			printf(" ");
			}
			power/=16;
		}
		printf("\n");
		
				
			}else{
				printf("The input string is an invalid numeral.\n");
				break;
			}
		}		
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
