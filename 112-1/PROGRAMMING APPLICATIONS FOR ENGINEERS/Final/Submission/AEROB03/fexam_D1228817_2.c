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
	int i; // Loop variable.
	int temp;

	do {
		// a.Enter a string of digits and English letters str.
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", str); // Input the numeral base and the numeral as a string.
		base = 0; // Initial base to 0.
		
		// ***** Complete the program of the following steps.
/*for(i=0; i<strlen(str); i++){
	if(str[i]>='A'&&str[i]<='Z') printf("");
	else if(str[i]>='a'&&str[i]<='z') printf("");
	else if (str[i]>='0'&&str[i]<='9') printf("");
	else{
		do{
			 printf("The input string is an invalid numeral.\n");
			 printf("Enter a numeral (a string of digits and English letters): ");
			scanf("%s", str); // Input the numeral base and the numeral as a string.
		}while()
	}
}*/
		num=0;
	
for(i=0; i<strlen(str); i++){
	if(str[i]>='0'&&str[i]<='9') temp=str[i]-'0'+1;
	else if(str[i]>='A'&&str[i]<='Z') temp=str[i]-'A'+11;
	else if(str[i]>='a'&&str[i]<='z') temp=str[i]-'a'+37;
	
	if(temp>base) base =temp;
	power=pow(62, strlen(str)-(i+1));
	num+=(temp-1)*power;
	
} 

printf("Base: %d, Decimal value:%llu\n", base, num);
printf("Binary numeral: ");
		
power=pow(2, 63);
residual=num;
for(i=0; i<64; i++){
	printf("%d", residual/power);
	residual%=power;
	power/=2;
	if((i+1)%8==0) printf(" ");
}
printf("\nHexadecimal numeral: ");
power=pow(16, 15);
residual=num;
for(i=0; i<16; i++){
	if(residual/power>=0&&residual/power<=9) 	printf("%d", residual/power);
	else printf("%c", residual/power-10+'A');
	
	residual%=power;
	power/=16;
	if((i+1)%4==0) printf(" ");
}
printf("\n\n");	
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
