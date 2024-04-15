#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
	FILE *fptrIn, *fptrOut;
	char *buffer; 
	int capacity = 512;
	int inx = 0;
	int i; 
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int total = 0;
	int A = 0, E = 0, I = 0, O = 0, U = 0;
	int totalv = 0;
	
	//1) Let capacity be the size of a data buffer with initial value 512. Declare a pointer to character ¡§char *buffer;¡¨ and dynamically allocate 512 characters as the initial memory space of buffer[].
	buffer = (char *) malloc(capacity); 
	
	//2) Open the input text file Gift_of_Magi.txt and read the file using fgetc() to input the file character by character until reaching the end of file. If the input character is an English letter, convert it to uppercase letter and store in buffer[], starting from index 0. When the memory space of buffer[] becomes full, extend the size of buffer 512 bytes more. b. If the input character is not an English letter, ignore it.
	fptrIn = fopen("Gift_of_Magi.txt", "r"); 
	while (!feof(fptrIn)) {
		buffer[inx] = fgetc(fptrIn);
		if (isalpha(buffer[inx])) {
			buffer[inx] = toupper(buffer[inx]);
			inx++;
			if (inx==capacity) {
				capacity += 512;
				buffer = (char *) realloc(buffer, capacity); // add more place if the space isn't enough
			}
		}
	}
	//3) Insert end-of-string ¡¥\0¡¦ following the last input character. Print the number of input English letters, i.e., the length of string.
	buffer[inx] = '\0';
	printf(">>>> Total input English characters: %d.\n", inx);
	fclose(fptrIn); //close the file
	printf("***********************************************************************\n\n");
	 
	//4) Open an output text file ¡§result.txt¡¨ and write the file using fwrite().
	fptrOut = fopen("result.txt", "w"); 
	fwrite(buffer, 1, inx, fptrOut); 
	fclose(fptrOut); //close the file
  	
  	//5) Print the first 800 characters of the input text on the console, 80 characters in a line.
	printf(">>>> The first 800 characters are:\n  "); 
	for (i=0; i<800; i++) { 
		if ((i+1)%80==0)  printf("%c\n  ", buffer[i]); 
		else printf("%c", buffer[i]); 
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	
	//6) Count and report the number of one character letter, two contiguous character letters. three contiguous character letters, and four or more contiguous character letters.
	i = 0;
	while(buffer[i] != '\0'){
		if(buffer[i] == buffer[i + 1]){
			if(buffer[i + 1] == buffer[i + 2]){
				if(buffer[i + 2] == buffer[i + 3]){
					c4 = c4 + 1;
					i = i + 4;
				}
				else{
					c3 = c3 + 1;
					i = i + 3;
				} 
			}
			else{
				c2 = c2 + 1;
				i = i + 2;
			} 	
		}
		else{
			c1 = c1 + 1;
			i++;
		} 
	}
	total = c1 + c2 * 2 + c3 * 3 + c4 * 4;
	
	printf(">>>> The number of contiguous letter(s) are:\n");
	printf("  One character: %d\n", c1);
	printf("  Two contiguous characters: %d\n", c2);
	printf("  Three contiguous characters: %d\n", c3);
	printf("  Four or more contiguous characters: %d\n", c4);
	printf("  **** Total character counts: %d\n", total);
	
	//7) Count and report the number of each occurrence of vowels, 'A', 'E', 'I', 'O', and 'U'. Print the total vowel count.
	i = 0;
	while(buffer[i] != '\0'){
		if(buffer[i] == 'A') A = A + 1;
		if(buffer[i] == 'E') E = E + 1;
		if(buffer[i] == 'I') I = I + 1;
		if(buffer[i] == 'O') O = O + 1;
		if(buffer[i] == 'U') U = U + 1;
		i++;
	}
	totalv = A + E + I + O + U;
	
	printf("***********************************************************************\n\n");
	printf(">>>> The number of occurences of vowels:\n");
	printf("  Vowel 'A': %d\n", A);
	printf("  Vowel 'E': %d\n", E);
	printf("  Vowel 'I': %d\n", I);
	printf("  Vowel 'O': %d\n", O);
	printf("  Vowel 'U': %d\n", U);
	printf("  **** Total vowel count: %d\n", totalv);
	printf("***********************************************************************");
	
	//8) Release memory space of buffer[].
	free(buffer);
}

