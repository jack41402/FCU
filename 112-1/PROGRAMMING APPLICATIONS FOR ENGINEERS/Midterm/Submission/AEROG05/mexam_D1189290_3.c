#include <stdio.h>
unsigned int reverseb(unsigned int num){
	unsigned int nob = sizeof(num) * 8;
	unsigned int reversen=0;
	int i;
	for(i=0;i<nob;i++){
		if((num & (1 << i))){
			reversen != (1<<(nob-1)-i);
		}
	}
	return reversen;
}
int main(){
	unsigned int num; // Two 32-bit integers..
	while(1){
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u",&num);
		if(num==0){
			break;
		}
	printf("Binary representation of num: \n");
	printf("    ");
	int i;
	for(i=31;i>=0;i--){
		printf("%u",(num >> i) & 1);
		if(i % 8==0){
			printf(" ");
		}
	}
	printf("\n\n");
	printf("Hexadecimal representation of num: \n    %08X\n\n",num);
	unsigned int rev = reversen(num);
	printf("Decimal representation of rev: %u\n\n",rev);
	printf("Binary representation of rev: \n    ");
	for(i=31;i>=0;i--){
		printf("%u",(rev >> i) & 1);
		if(i % 8==0){
			printf(" ");
		}
	}
	printf("\n\n");
	printf("Hexadecimal representation of rev: \n    %08X\n\n",rev);
 	printf("\n----------------------------------\n"); // Print a separating line.
	}
	return 0;
}
