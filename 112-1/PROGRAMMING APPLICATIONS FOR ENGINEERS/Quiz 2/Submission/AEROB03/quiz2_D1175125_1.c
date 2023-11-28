#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int replace(char c){
	int a=0;
	if(c=='A'){
		a=10;
		return a;
	}else if(c=='B'){
		a=11;
		return a;
	} else if(c=='C'){
		a=12;
		return a;
	}else if(c=='D'){
		a=13;
		return a;
	}else if(c=='E'){
		a=14;
		return a;
	}else if(c=='F'){
		a=15;
		return a;
	}else{
		a=c-'0';
		return a;
	}
}

int hex2dec(char num[]){
	int i;
	int counter=0;
	int hexnum;
	long long int decnum;
	for(i=7;i>=0;i--){
		hexnum=replace(num[i]);
		decnum+=hexnum*pow(16,counter);
		counter+=1;
	} 
	return decnum;
}
int dec2bin(int num){
	int i;
	int binnum[33];
	for(i=0;i<32;i++){
		binnum[i]=0;
	}
	for(i=32;i>=0;i--){
		binnum[i]=num%2;
		num/=2;
	}
	for(i=1;i<33;i++){
   		if(i%8==0){
 			printf("%d ",binnum[i]);
		}else{
			printf("%d",binnum[i]);
		}
	}
}

int main(void) {
	const int base=16; // Numeral base.
	char num[9]; // Hexadecimal numeral as string of length 8.
	long value; // Integer value of the numeral.
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

    	// ***** Complete the rest of the program.
	 	value=hex2dec(num);
    	printf("The input hexidecimal numeral %s is of the decimal value: %d\n",num,value);
    	printf("Binary numeral: ");
 		dec2bin(value);
		// (b) Convert this string to a 32-bit non-negative integer with the value less 
		//     than or equal to 4,294,967,295. Print the decimal value of n without leading zeros. 
	
		// (c) Print the value as the 32-bit binary numeral representation, including zeros, such that 
		//     every eight bits are separated by a space. 
    
		printf("\n\n---------------------\n"); // Print a separate line.
	}
	return 0;
}
