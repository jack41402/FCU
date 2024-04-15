#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut;
	char *buffer;
	int capacity = 512;
	int index = 0;
	char vowel[] = "AEIOU";
	int vowel_count[5] = {0, 0, 0, 0, 0};
	int letter_count[4] = {0, 0, 0, 0};
	char *cptr;
	char one_char[2];
	int length;
	int total;
	int i;
	
	buffer = (char *) malloc(capacity); // initial memory allocation for text buffer.
	
	fptrIn = fopen("Gift_of_Magi.txt", "r");// open the input text file "Gift_of_Magi.txt"
	while(!feof(fptrIn)){// until reaching the end of file
		buffer[index] = fgetc(fptrIn);// read the file
		if(isalpha(buffer[index])){// if the input character is not an English letter, ignore it
			buffer[index] = toupper(buffer[index]);// convert all English letters to uppercase letters 
			index++;
			if(index==capacity){ 
				capacity += 512;// extend the size of buffer 512 bytes more if the space is full
				buffer = (char *) realloc(buffer, capacity);
			}
		}
	}
	buffer[index] = '\0';
	fclose(fptrIn);
	printf(">>>> Total input English characters: %d.\n", index);
	printf("");
	printf("***********************************************************************\n\n");
	
	fptrOut = fopen("result.txt", "w");// open an output text file "result.txt"
	fwrite(buffer, 1, index, fptrOut);// write the file
	fclose(fptrOut);
	printf(">>>> The first 800 characters are:\n  ");
	for(i=0; i<800; ++i){// print the first 800 characters of the modified text
		if((i+1)%80==0) printf("%c\n  ", buffer[i]);// 80 characters in a line
		else printf("%c", buffer[i]);
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	
	// count the number of contiguous characters
	cptr = buffer;
	one_char[1] = '\0';
	total = 0;
	while(cptr[0]!='\0'){
		one_char[0] = cptr[0];
		length = strspn(cptr, one_char);
		total += length;
		cptr = cptr + length;
		length = length < 4 ? length : 4;
		++letter_count[length-1];
	}
	printf(">>>> The number of contiguous letter(s) are:\n");
	printf("  One character: %u\n", letter_count[0]);
	printf("  Two contiguous characters: %u\n", letter_count[1]);
	printf("  Three contiguous characters: %u\n", letter_count[2]);
	printf("  Four or more contiguous characters: %u\n", letter_count[3]);
	printf("  **** Total characater counts: %u\n", total);
	printf("***********************************************************************\n\n");
	
	// count the number of each occurrence of vowels
	cptr = (char *) strpbrk(buffer, vowel);
	total = 0;
	while(cptr != NULL){
		switch(*cptr){
			case 'A': {++vowel_count[0];break;}
			case 'E': {++vowel_count[1];break;}
			case 'I': {++vowel_count[2];break;}
			case 'O': {++vowel_count[3];break;}
			case 'U': {++vowel_count[4];break;}
		}
		cptr = (char *) strpbrk(cptr+1, vowel);
		total ++;
	}
	printf(">>>> The number of occurences of vowels:\n");
	for(i=0; i<5; ++i) printf("  Vowel \'%c\': %u\n", vowel[i], vowel_count[i]);
	printf("  **** Total vowel count: %u\n", total);
	printf("***********************************************************************\n\n");
	free(buffer);// release memory space of buffer
	return 0;
}
