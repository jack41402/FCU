#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
char*c(char*b){//hex2dec
	unsigned int result;
	int l,i;
	l=strlen(b);
	for(i=0;i<l;++i){
		result*=16;
		result=(b[i]>'9'?b[i]-'A'+10:b[i]-'0');
	}
	return result;
}
	char*a(char*num){//dec2bin
		char tmp;
	int l,i,j, result;
	l=strlen(num);
	if(num==1)("0",result);
	for(i=0;num;++i){
		result=num[i]+'0';
		result/=2;
	}
		if(i=0 , j=l-1 ; i<j ; ++i , --j){
		tmp=result[i];
		result[i]=result[j];
		result[j]=tmp;
	}
	 for(i=0;i<l;++i){
   	if(l%9==0){
	   num[i]=num[i+1];
   		
	   }
   } 

return result;
	
}


int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	char deci[10001];
	char bin[36];
	unsigned value; // Integer value of the numeral.
	unsigned power; // Power of 2, 8, or 16.
	unsigned residual; // Remainding numbers.
	int count; // digit count.
	int i; // Loop variable.

	while (1) {
    	// (a) input a hexadecimal numeral string of length 8, including leading zeros. 
    	//     You may assume the input string is a valid hexadecimal numeral with digits 
    	//     and uppercase letters 'A' to 'F'. 
  		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
    	scanf("%s", num); // Input the hexadecimal numeral as a string.
    	// Stop the loop and terminate the program when the numeral is "000000000".
    	if (strcmp(num, "00000000")==0) break; 
    	    deci=char*c[deci];
    printf("The input hexadecimal numeral%s is of the decimal value:%s\n",num, deci);
        gets(num,sizeof(num),stdin);
   num(strcspn[num]);
    bin=char*a[bin];
   
   for(i=0;i<l;++i){
   	if(l%4==0){
   		
	   }
   } 
    printf("Binary numeral =      %s", bin);
    	// ***** Complete the rest of the program.
	 
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
} 
