#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int main(void){
	char *buffer, *temp;
	FILE *datain, *dataout;
	int capacity = 512; 
	int fleng,length; 
	int i,j;  
	int count = 0,count1 = 0,count2 = 0, count3 = 0, count4up = 0;
	int A = 0, E = 0, I = 0, O = 0, U = 0,total_vowels = 0; 
	char vowels[ ] ="AEIOU";
	
	datain = fopen("Gift_of_Magi.txt","r");
	if(datain == NULL){
		printf("\nText file \"Gift_of_Magi.txt\" does not exist.\n\n");
		system("pause");
		return -1; 
	} 
	
	fseek(datain, 0 ,SEEK_END);
	fleng =  ftell(datain);
	fseek(datain, 0 ,SEEK_SET);
	buffer = (char *) malloc(capacity * sizeof(char));
	while(capacity <= fleng){
		capacity += 512; 
		temp = (char *)realloc(buffer, capacity * sizeof(char)); 
		buffer = temp; 
	}
	length = 0;
    while (!feof(datain) && length < capacity - 1) { 
		buffer[length] = fgetc(datain);
        buffer[length] = toupper(buffer[length]); 
        if(isalpha(buffer[length])) length++; 
    }
    buffer[length] = '\0'; 
    printf(">>>> Total input English Characters: %d.",length);
	dataout = fopen("result.txt", "w");
	printf("\n\nBUFFER: %s\n\n", buffer);
    fwrite(buffer, sizeof(char), length, dataout);
	fclose(datain); 
	fclose(dataout); 
	printf("\n****************************************************************************\n\n");
	printf(">>>> The first 800 characters are: ");
	for(i=0;i<800;i++){
		if(i%80==0) printf("\n  "); 
		printf("%c",buffer[i]);
	}
	printf("\n\n******************************************************************************\n\n");
	printf(">>>> The number of contiguous letter(s) are: \n");
	for(j=0;j<length;j++){
			count++;
			if(buffer[j]!=buffer[j+1]){
				if(count == 1) count1++;
				else if(count == 2) count2++;
				else if(count == 3) count3++;
				else count4up++; 
				count = 0; 
			}
	}
	printf("  One characater: %d",count1);
	printf("\n  Two contiguous characaters: %d",count2);
	printf("\n  Three contiguous characters: %d",count3);
	printf("\n  Four or more contiguous characaters: %d",count4up);
	printf("\n  ****Total characater counts: %d",length);
	printf("\n\n******************************************************************************\n");
	for(j=0;vowels[j]!='\0';j++){
		char *ptr;
		ptr = buffer;
		if(j==0) ptr = strpbrk(ptr, "A");
		else if(j==1)  ptr = strpbrk(ptr, "E");
		else if(j==2)  ptr = strpbrk(ptr, "I");
		else if(j==3)  ptr = strpbrk(ptr, "O");
		else ptr = strpbrk(ptr, "U");
		while(ptr!=NULL){
			total_vowels++;
			if(j==0) {
				A++;
				ptr = strpbrk(ptr+1, "A"); 
			}else if(j==1) {
				E++;
				ptr = strpbrk(ptr+1, "E"); 
			}else if(j==2) {
				I++;
				ptr = strpbrk(ptr+1, "I"); 
			}else if(j==3) {
				O++;
				ptr = strpbrk(ptr+1, "O"); 
			}else{
				U++;
				ptr = strpbrk(ptr+1, "U"); 
			}     
		}
	}
	printf("\n>>>> The numbers of occurences of vowel: \n");
	printf("  Vowels 'A': %d",A);
	printf("\n  Vowels 'E': %d",E);
	printf("\n  Vowels 'I': %d",I);
	printf("\n  Vowels 'O': %d",O);
	printf("\n  Vowels 'U': %d",U);
	printf("\n  **** Total vowel count: %d",total_vowels);
	printf("\n******************************************************************************");
	free(buffer);
	return 0; 
	
} 
