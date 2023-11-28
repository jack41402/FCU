#include <stdlib.h>
#include <stdio.h>
#include <string.h>
unsigned int hextodecimal(const char *num){
	 unsigned int decimal = strtoul(num, NULL, 16);
	 return decimal;
}
void printbinary(unsigned int decimal){
	int i;
	for(i=31 ; i>=0 ; --i){
		printf("%c", (decimal & (1u << i)) ? '1' : '0');
		if(i % 8 ==0) printf(" ");
	}
}
int main(void) {
	char num[9];
	while(1){
		printf("Input a hexadecimal numeral string of length 8, including leading zeros: ");
		scanf("%8s", num);
		if(strcmp(num, "00000000") == 0){
			break;
		}
	unsigned int decimal = hextodecimal(num);
	printf("The input hexadecimal numeral %8s is of the decimal value: %u\n", num, decimal);
	printf("Binary numeral: ");
	printf("     ");
	printbinary(decimal);
	printf("\n\n");
	printf("---------------------\n");
    }
    return 0;
}


