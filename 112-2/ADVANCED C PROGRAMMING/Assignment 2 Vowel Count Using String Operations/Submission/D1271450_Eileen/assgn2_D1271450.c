#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut; //input and output file pointer
	char *buffer; //data buffer pointer
	int capacity = 512;
	int inx = 0; //index of the input text
	char *char_ptr; //character pointers
	char vowels[] = "AEIOU"; //vowels
	char one_char[2]; //one-character string
	unsigned int length; //letter sequence's length
	unsigned int total_count; //total count of characcters
	unsigned int word_count[7] = {0, 0, 0, 0, 0, 0, 0}; //number of words with length 1 to 6 and over 6
	unsigned int vowel_count[5] = {0, 0, 0, 0, 0}; //number of vowels 'A', 'E', 'I', 'O','U'
	unsigned int char_count[4] = {0, 0, 0, 0}; //number 1, 2, 3, and over 3 contiguous characters
	unsigned int i; //loop variable
	
	buffer = (char *) malloc(capacity); //initial memory allocation for text buffer
	

	// open input text file "Gift_of_Magi.txt"and read the file using fgetc() to input the file character by character until reaching the end of file.
	fptrIn = fopen("Gift_of_Magi.txt", "r"); 
	
	//if the input character is an English letter, convert it to uppercase letter and store in buffer[], starting from index 0, and when the memory space of buffer[] becomes full, extend the size of buffer 512 bytes more and if the input character is not an English letter, ignore it.
	while (!feof(fptrIn)) {
		buffer[inx] = fgetc(fptrIn);
		if (isalpha(buffer[inx])) {
			buffer[inx] = toupper(buffer[inx]);
			inx++;
			if (inx==capacity) {
				capacity += 512;
				buffer = (char *) realloc(buffer, capacity); 
			}
		}
	}
	
	buffer[inx] = '\0';//insert end-of-string ¡®\0¡¯ following the last input character
	printf(">>>> Total input English characters: %d.\n", inx);//print the number of input English letters, i.e., the length of string
	printf("");
	fclose(fptrIn); //close the input file
	printf("***********************************************************************\n\n");
	
	fptrOut = fopen("result.txt", "w");  //open output file "result.txt" and write the file using fwrite()
	fwrite(buffer, 1, inx, fptrOut); //write data from the data buffer to the output file
	fclose(fptrOut); //close the output file
  

	printf(">>>> The first 800 characters are:\n  "); //print the first 500 characters
	for (i=0; i<800; i++) { // 800 characters in a line.
		if ((i+1)%80==0)  printf("%c\n  ", buffer[i]); //if it is not a full line, print the character only
		else printf("%c", buffer[i]); //if it is a full line, print the character and a new line
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	
	char_ptr = buffer; //start from the beginning of the text
	//construct a single-character string of the current character
	one_char[1] = '\0'; //since the string is of length 1, insert end-of-string in the second array element
	total_count = 0; //reset total character count to 0
	while (char_ptr[0]!='\0') { //continue, When there are more letters
		one_char[0] = char_ptr[0]; //insert the letter
		length = strspn(char_ptr, one_char); //find the length of the contiguous letter
		total_count += length; //sum up the total character count
		char_ptr = char_ptr + length; //move to the address of the next distinguished letter
		length = length < 4 ? length : 4; //if the length is over four, set it to 4
		++char_count[length-1]; //increment the contiguous letter count
	}

	printf(">>>> The number of contiguous letter(s) are:\n"); //print contiguous letter count
	printf("  One character: %u\n", char_count[0]); //one-letter count
	printf("  Two contiguous characters: %u\n", char_count[1]); //two-letter count
	printf("  Three contiguous characters: %u\n", char_count[2]); //three-letter count
	printf("  Four or more contiguous characters: %u\n", char_count[3]); //four-letter or more count
	printf("  **** Total characater counts: %u\n", total_count); //total letter count
	printf("***********************************************************************\n\n");
 
	char_ptr = (char *) strpbrk(buffer, vowels); //find the first vowel
	total_count = 0; //reset total vowel count to 0
	while (char_ptr!=NULL) { //continue, when there are more vowels
		switch (*char_ptr) { //check the case of the vowel
			case 'A': {++vowel_count[0]; break;} //increment vowel'A''s count
			case 'E': {++vowel_count[1]; break;} //increment vowel 'E''s count
			case 'I': {++vowel_count[2]; break;} //increment vowel 'I' count
			case 'O': {++vowel_count[3]; break;} //increment vowel 'O' count
			case 'U': {++vowel_count[4]; break;} //increment vowel 'U' count
		}
		char_ptr = (char *) strpbrk(char_ptr+1, vowels); //find the next vowel
		total_count++; //increment total vowel count
	}
	printf(">>>> The number of occurences of vowels:\n"); //report vowel counts
	for (i=0; i<5; i++) //print vowel count
		printf("  Vowel \'%c\': %u\n", vowels[i], vowel_count[i]);
	printf("  **** Total vowel count: %u\n", total_count);
	printf("***********************************************************************\n\n");
	
	free(buffer);//release memory space of buffer[]
  
	return 0;
}  
