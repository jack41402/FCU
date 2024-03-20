#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut; // Input and output file pointer.
	char *buffer; // Data buffer pointer.
	int capacity = 512;
	int inx = 0; // Index of the input text.
	char *char_ptr; // Character pointers for scanning characters.
	char vowels[] = "AEIOU"; // Vowels.
	char one_char[2]; // To construct one-character string.
	unsigned int length; // Length of letter sequence.
	unsigned int total_count; // Total count of characcters.
	unsigned int word_count[7] = {0, 0, 0, 0, 0, 0, 0}; // Number of words with length 1 to 6 and over 6. 
	unsigned int vowel_count[5] = {0, 0, 0, 0, 0}; // Number of vowels 'A', 'E', 'I', 'O', and 'U'.
	unsigned int char_count[4] = {0, 0, 0, 0}; // Number 1, 2, 3, and over 3 contiguous characters.
	unsigned int i; // Loop variable.
	
    // Step a: Dynamically allocate 512 characters as the initial memory space of buffer[]. 
	buffer = (char *) malloc(capacity); // Initial memory allocation for text buffer.
	
	// Step b. Open the input text file "Gift_of_Magi.txt" and read the file using fgetc() 
	//         to input the file character by character until reaching the end of file.
	//    1) If the input character is an English letter, convert it to uppercase letter 
	//       and store in buffer[], starting from index 0. When the memory space of buffer[] 
	//       becomes full, extend the size of buffer 512 bytes more.
	//    2) If the input character is not an English letter, ignore it.
	fptrIn = fopen("Gift_of_Magi.txt", "r"); // Open input text file.
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
	
	// Step c: Insert end-of-string ¡®\0¡¯ following the last input character. 
	//         Print the number of input English letters, i.e., the length of string.
	buffer[inx] = '\0';
	printf(">>>> Total input English characters: %d.\n", inx);
	printf("");
	fclose(fptrIn); // Close the input file. 
	printf("***********************************************************************\n\n");
	
	// Step d: Open an output text file "result.txt" and write the file using fwrite(). 
	fptrOut = fopen("result.txt", "w");  // Open output file.
	fwrite(buffer, 1, inx, fptrOut); // Write data from the data buffer to the output file.
	fclose(fptrOut); // Close the output file.
  
	// Step e: Print the first 800 characters of the modified text on the monitor,
	//         80 characters in a line.
	printf(">>>> The first 800 characters are:\n  "); // Print the first 500 characters.
	for (i=0; i<800; i++) { // 800 characters in a line.
		if ((i+1)%80==0)  printf("%c\n  ", buffer[i]); // If it is not a full line, print the character only.
		else printf("%c", buffer[i]); // If it is a full line, print the character and a new line.
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	
	// Step f: Count and report the number of one character letter, two contiguous
	//         character letters, three contiguous character letters, and four or
	//         more contiguous character letters.
	char_ptr = buffer; // Start from the beginning of the text.
	// Construct a single-character string of the current character.
	one_char[1] = '\0'; // Since the string is of length 1, insert end-of-string in the second array element.
	total_count = 0; // Reset total character count to 0.
	while (char_ptr[0]!='\0') { // Continue, When there are more letters.
		one_char[0] = char_ptr[0]; // Insert the letter.
		length = strspn(char_ptr, one_char); //Find the length of the contiguous letter.
		total_count += length; // Sum up the total character count.
		char_ptr = char_ptr + length; // Move to the address of the next distinguished letter.
		length = length < 4 ? length : 4; // If the length is over four, set it to 4.
		++char_count[length-1]; // Increment the contiguous letter count.
	}
	// Report contiguous letter count.
	printf(">>>> The number of contiguous letter(s) are:\n"); // Print contiguous letter count.
	printf("  One character: %u\n", char_count[0]); // One-letter count.
	printf("  Two contiguous characters: %u\n", char_count[1]); // Two-letter count.
	printf("  Three contiguous characters: %u\n", char_count[2]); // Three-letter count.
	printf("  Four or more contiguous characters: %u\n", char_count[3]); // Four-letter or more count.
	printf("  **** Total characater counts: %u\n", total_count); // Total letter count.
	printf("***********************************************************************\n\n");
 
	// Step g: Count and report the number of each occurence of vowels,
	//         'A', 'E', 'I', 'O', and 'U'.
	char_ptr = (char *) strpbrk(buffer, vowels); // Find the first vowel.
	total_count = 0; // Reset total vowel count to 0.
	while (char_ptr!=NULL) { // Continue, when there are more vowels.
		switch (*char_ptr) { // Check the case of the vowel.
			case 'A': {++vowel_count[0]; break;} // Vowel 'A', increment its count.
			case 'E': {++vowel_count[1]; break;} // Vowel 'E', increment its count.
			case 'I': {++vowel_count[2]; break;} // Vowel 'I', increment its count.
			case 'O': {++vowel_count[3]; break;} // Vowel 'O', increment its count.
			case 'U': {++vowel_count[4]; break;} // Vowel 'U', increment its count.
		}
		char_ptr = (char *) strpbrk(char_ptr+1, vowels); // Find the next vowel.
		total_count++; // Increment total vowel count.
	}
	printf(">>>> The number of occurences of vowels:\n"); // Report vowel counts.
	for (i=0; i<5; i++) // Print vowel count.
		printf("  Vowel \'%c\': %u\n", vowels[i], vowel_count[i]);
	printf("  **** Total vowel count: %u\n", total_count);
	printf("***********************************************************************\n\n");
	
	// Step h: Release memory space of buffer[].
	free(buffer);
  
	return 0;
}  
