#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int main(void) {
	int base; // Numeral base.
	char str[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long num; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int count; // digit count. 
	int i,j; // Loop variable.
	int temp;
	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		temp = 0;
		for(i=0;i<strlen(str);i++){
			
			if(str[i]>str[i-1]){
			temp = str[i];
	}
		
		
		}
		
		if(isdigit(temp)){
			base = (temp-'0')+1;
		}
		else if(isupper(temp)){
			base = (temp-'A')+10+1;
		}	
		else if(islower(temp)){
			base = (temp-'a')+36+1;
		}
		
		printf("Base: %d,",base);	
		// ***** Complete the program of the following steps.
	
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		
		num = 0;
  	for(i=0;i<strlen(str);i++){
			
			if(isdigit(str[i])){
			str[i]=str[i]-'0';
		}
		else if(isupper(str[i])){
			str[i]=str[i]-'A'+10;
		}	
		else if(islower(str[i])){
			str[i]=str[i]-'a'+36;
		}
			
			j = strlen(str)-1;
			num += str[i]*pow(base,j);
			j--;
		}
		printf(" Decimal value: %d\n",num);
		printf("Binary numeral: ");
		residual = num;
		count = 0;
		power = pow(2,63);
		while(count<64){
			printf("%u",residual/power); 
			residual = residual%power;
			
			power = power/2;
			count++;
		if(count%8 == 0){
			printf(" ");
		}
	}
	
	printf("\nHexadecimal numeral: ");
		residual = num;
		count = 0;
		power = pow(16,15);
		while(count<16){
			if(residual/power==10){
				printf("A");
			}
			if(residual/power==11){
				printf("B");
			}
			if(residual/power==12){
				printf("C");
			}
			if(residual/power==13){
				printf("D");
			}
			if(residual/power==14){
				printf("E");
			}
			if(residual/power==15){
				printf("F");
			}
			printf("%u",residual/power); 
			residual = residual%power;
			
			power = power/16;
			count++;
		if(count%4 == 0){
			printf(" ");
		}
	}
		
		// c. Output the values of base and num.
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
	
	return 0;

}
