#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut;
	char *buffer;
	int box = 512;
	int inx = 0;
	char *char_ptr;
	char vowels[] = "AEIOU";
	char one_char[2];
	unsigned int l;
	unsigned int total;
	unsigned int count[7] = {0, 0, 0, 0, 0, 0, 0};
	unsigned int vowel[5] = {0, 0, 0, 0, 0};
	unsigned int char_count[4] = {0, 0, 0, 0};
	unsigned int i;
	
    // Allocate memory for buffer
	buffer = (char *) malloc(box); 
	
    // Open input file by file operation and read characters from file into buffer
	fptrIn = fopen("Gift_of_Magi.txt", "r");
	while (!feof(fptrIn)) {
		buffer[inx] = fgetc(fptrIn);
        // Convert characters to uppercase if they are alphabetic
		if (isalpha(buffer[inx])) {
			buffer[inx] = toupper(buffer[inx]);
			inx++;
            // Check if buffer is full and resize if necessary
			if (inx==box) { 
				box += 512; 
				buffer = (char *) realloc(buffer, box); 
			}
		}
	}
	
    // Terminate buffer
	buffer[inx] = '\0';
	printf(">>>> Total input English characters: %d.\n", inx);
	fclose(fptrIn);
	printf("");
	printf("***********************************************************************\n\n");
	
    // Open output file write buffer contents to output file
	fptrOut = fopen("result.txt", "w");
	fwrite(buffer, 1, inx, fptrOut);
	fclose(fptrOut);
	
	// Print the words
	printf(">>>> The first 800 characters are:\n  ");
	for (i=0; i<800; i++) {
		if ((i+1)%80==0)  printf("%c\n  ", buffer[i]);
		else printf("%c", buffer[i]);
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	
    // Count contiguous characters
	char_ptr = buffer;
	one_char[1] = '\0';
	total = 0;
	while (char_ptr[0]!='\0') {
		one_char[0] = char_ptr[0];
		l = strspn(char_ptr, one_char);
		total += l;
		char_ptr = char_ptr + l;
		l = l < 4 ? l : 4;
		++char_count[l-1];
	}
	
	printf(">>>> The number of contiguous letter(s) are:\n");
	printf("  One character: %u\n", char_count[0]);
	printf("  Two contiguous characters: %u\n", char_count[1]);
	printf("  Three contiguous characters: %u\n", char_count[2]);
	printf("  Four or more contiguous characters: %u\n", char_count[3]);
	printf("  **** Total characater counts: %u\n", total);
	printf("***********************************************************************\n\n");
 
    // Count vowels
	char_ptr = (char *) strpbrk(buffer, vowels);
	total = 0;
	while (char_ptr!=NULL) {
		switch (*char_ptr) {
			case 'A': {++vowel[0]; break;}
			case 'E': {++vowel[1]; break;}
			case 'I': {++vowel[2]; break;}
			case 'O': {++vowel[3]; break;}
			case 'U': {++vowel[4]; break;}
		}
		char_ptr = (char *) strpbrk(char_ptr+1, vowels);
		total++;
	}

	printf(">>>> The number of occurences of vowels:\n");
	for (i=0; i<5; i++)
		printf("  Vowel \'%c\': %u\n", vowels[i], vowel[i]);
	printf("  **** Total vowel count: %u\n", total);
	printf("***********************************************************************\n\n");
	
    // Free allocated memory
	free(buffer);
  
	return 0;
}
