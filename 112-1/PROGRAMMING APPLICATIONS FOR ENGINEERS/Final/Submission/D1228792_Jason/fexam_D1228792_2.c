#include <stdio.h>
#include <string.h> // Refer to function strlen().
#include <ctype.h> // Refer to functions isdigit(), isupper(), islower(), isalnum().
#include <math.h> // Refer to function pow().

int main(void) {
	int base; // Numeral base.
	char str[65]; // Numeral as string, maximum length 64 digits for binary numerals.
	unsigned long long num,b,h; // Integer value of the numeral (64-bit integer).
	unsigned long long power; // Power of base.
	unsigned long long residual; // Remainding numbers for printing binary and hexadecimal numberal.
	int bin[70]={0},hex[20]={0};
	int count; // digit count. 
	int i; // Loop variable.
	int text,t;
	char max;
	do {
		// a.Enter a string of digits and English letters str.
		text=0;
		count=0;
		max='0';
		num=0;
		power=1;
		
		do{
			printf("Enter a numeral (a string of digits and English letters): ");
			scanf("%s", str); // Input the numeral base and the numeral as a string.
			for(i=0;i<strlen(str);i++){
				if(str[i]>='0'&&str[i]<='9') text+=0;
				else if(str[i]>='A'&&str[i]<='Z') text+=0;
				else if(str[i]>='a'&&str[i]<='z') text+=0;
				else text+=1;
			}
			if(text>0) printf("The input string is an invalid numeral.\n\n");
		}while(text!=0);
		
		base = 0; // Initial base to 0.
		t=0;
		// ***** Complete the program of the following steps.
		for(i=0;i<strlen(str);i++){
			if(str[i]=='0') t+=1;
		}
		if(t==strlen(str)) base=1;
		else{
			for(i=0;i<strlen(str);i++){
				if(str[i]>max) max=str[i];
			}
		}
		if(max>='0'&&max<='9') count=max-'0';
		else if(max>='A'&&max<='Z') count=max-'A'+10;
		else if(max>='a'&&max<='z') count=max-'a'+36;
		count+=1;
		for(i=strlen(str)-1;i>=0;i--){
			if(str[i]>='0'&&str[i]<='9') num+=(str[i]-'0')*power;
			else if(str[i]>='A'&&str[i]<='Z') num+=(str[i]-'A'+10)*power;
			else if(str[i]>='a'&&str[i]<='z') num+=(str[i]-'a'+36)*power;
			power*=count;
		}
		printf("Base: %d, Decimal value: %llu\n",count,num);
		b=num;
		h=num;
		i=0;
		power=1;
		while(b>0){
			bin[i]=b%2;
			i++;
			b/=2;
		}
		printf("Binary numeral:");
		for(i=63;i>=0;i--){
			if((i+1)%8==0) printf(" ");
			printf("%d",bin[i]);
		}
		printf("\n");
		i=0;
		while(h>0){
			hex[i]=h%16;
			i++;
			h/=16;
		}
		printf("Hexadecimal numeral:");
		for(i=15;i>=0;i--){
			if((i+1)%4==0) printf(" ");
			if(hex[i]>=10) printf("%c",hex[i]-10+'A');
			else printf("%d",hex[i]);
		}
		printf("\n");
		// b. Find the smallest possible base base and convert str to its equivalent decimal 
		//    numeral num. Report an error message, if str contains a non-alphanumerical character.
		
		// c. Output the values of base and num.
		
		// d. Output num as a 64-bit binary numeral with leading zeros and print a space after 
		//    every eight bits.
		
		// e. Output num as a 16-digit hexadecimal numeral with leading zeros and print a space 
		//    after every four digits.
		
	} while (base!=1); // Repeat the above steps until the input numeral str is a string of 0's.
	                   // That is, base==1.
  
	return 0;
}
