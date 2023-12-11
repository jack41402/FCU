#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Palindrome check function, iterative version.
int is_palindrome(char *s) {
  unsigned int h = 0; // Head pointer of string s.
  unsigned int t = strlen(s) - 1; // Tail pointer of string s.
  
  // Scan the string from head and tail toward the center, if a pair corresponding
  // characters are not identical, return flase (0).
  // The loop continues when head pointer is on the left-hand-side of the tail pointer.
  while (h<t) if (s[h++]!=s[t--]) return 0;
  return 1; // If the entire string passes the check, s is a palindrome.
}

// (1) Read data from a text file named <file_name>.
// (2) Store the data in a buffer pointed by <buffer_ptr>.
// (3) Return the memory address of the data buffer.
char *read_text_file(char *file_name) {
  FILE *fPtr; // File pointer.
  char * buffer_ptr; // Pointer to the data buffer.
  unsigned int size; // Size of the text file.
  
  fPtr = fopen(file_name, "r"); // Open file <file_name> with read mode.
  fseek(fPtr, 0, SEEK_END); // Move the file pointer to the end of the file.
  size = ftell(fPtr); // Get the position of the file, i.e., the size of the file.
  fseek(fPtr, 0, SEEK_SET); // Move the file pointer to the beginning of the file.
  buffer_ptr = (char *) malloc((size + 1) * sizeof(char)); // Allocate buffer memory.
  fread(buffer_ptr, 1, size, fPtr); // Read data from the input file and store in the data buffer.
  fclose(fPtr); // Close the input file.
  buffer_ptr[size] = '\0'; // Insert the end-of-string after the end of the text data.
  return buffer_ptr; // Return the memory address of the data buffer.
}

// Write text data pointed by <buffer_ptr> to a file named <file_name>.
// Free memory space of the data buffer.
void write_text_file(char *file_name, char *buffer_ptr) {
  FILE *fPtr; // File pointer.
  
  fPtr = fopen(file_name, "w");  // Open file <file_name> with write mode.
  fwrite(buffer_ptr, 1, strlen(buffer_ptr), fPtr); // Write data from the data buffer to the output file.
  fclose(fPtr); // Close the output file.
  free(buffer_ptr); // Release the memory space of the data buffer.	
}

int main(void) {
  char *data_ptr; // Data buffer pointer.
  char *char_ptr0, *char_ptr1; // Character pointers for scanning characters.
  char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Upper cases English letters.
  char lowercase[] = "abcdefghijklmnopqrstuvwxyz"; // lower cases English letters.
  char vowels[] = "AEIOU"; // Vowels.
  char one_char[2]; // To construct one-character string.
  unsigned int length; // Length of letter sequence.
  unsigned int total_count; // Total count of characcters.
  unsigned int word_count[7] = {0, 0, 0, 0, 0, 0, 0}; // Number of words with length 1 to 6 and over 6. 
  unsigned int vowel_count[5] = {0, 0, 0, 0, 0}; // Number of vowels 'A', 'E', 'I', 'O', and 'U'.
  unsigned int char_count[4] = {0, 0, 0, 0}; // Number 1, 2, 3, and over 3 contiguous characters.
  unsigned int inx = 0; // Index of the modified text.
  unsigned int i; // Loop variable.
  
  // Step 1: Read data from file "longest_palindrome_in.txt" and store in the data buffer.
  data_ptr = read_text_file("longest_palindrome_in.txt");
  printf(">>>> The testing text is read from file longest_palindrome_in.txt.\n"); // Print reading writing message.
  printf("***********************************************************************\n\n"); // Print a separte line.
  
  // Step 2: Convert all lowercase characters to uppercase.
  // Find the first lowercase letter in the text.
  char_ptr0 = (char *) strpbrk(data_ptr, lowercase);
  while (char_ptr0!=NULL) { // If there is lowercase letter, convert it to uppercase.
    *char_ptr0 = *char_ptr0 - 32; // Case conversion, because in ASCII code, we have 'a'-'A' is 32.
    char_ptr0 = (char *) strpbrk(char_ptr0, lowercase); // Find the next lowercase letter in the text.
  }
    
  // Step 3: Count the number of words with length 1 to 6 and over.
  // Find the first uppercase letter in the text.
  char_ptr0 = (char *) strpbrk(data_ptr, uppercase);
  total_count = 0; // Reset total character count to 0.
  while (char_ptr0!=NULL) { // If there is uppercase letter, there is a word.
    length = strspn(char_ptr0, uppercase); // Get the length of contiguous uppercase letters.
    total_count += length; // Accumulate total charcater count.
	if (length<7) ++word_count[length-1]; // Increment the word count of the word length.
    else ++word_count[6]; // Increment the word count of the word over length 6.
    char_ptr0 = (char *) strpbrk(char_ptr0+length, uppercase); // Find the next uppercase letter in the text.
  }
  printf(">>>> Word counts with length 1 to 6 and over:\n");
  for (i=0; i<6; i++) printf("  Length %u: %u\n", i+1, word_count[i]); // Word count of length 1 to 6.
  printf("  Length greater than 6: %u\n", word_count[6]); // Word count of length over 6.
  printf("  **** Total character count: %u\n", total_count); // Total character count.
  printf("***********************************************************************\n\n"); // Print a separte line.
  
  // Step 4: Remove space and non-English characters.
  char_ptr1 = data_ptr; // Pointer to record English letters only.. 
  char_ptr0 = (char *) strpbrk(data_ptr, uppercase); // Find pointer to the first English letter.
  while (char_ptr0!=NULL) { // Continue, when there are more English letters.
    *char_ptr1 = *char_ptr0; // Copy the English letter.
    char_ptr1++; // Move the pointer of the modified text one character forward.
    char_ptr0 = (char *) strpbrk(char_ptr0+1, uppercase); // Find pointer to the next English letter. 
  }
  *char_ptr1 = '\0'; // Insert end-of-string at the end of modified text.
  
  // Step 5: Print the first 500 characters of the modified text on the monitor,
  //         80 characters in a line.
  printf(">>>> The first 500 characters are:\n  "); // Print the first 500 characters.
  for (i=0; i<500; i++) { // 800 characters in a line.
  	if ((i+1)%80==0)  printf("%c\n  ", data_ptr[i]); // If it is not a full line, print the character only.
  	else printf("%c", data_ptr[i]); // If it is a full line, print the character and a new line.
  }
  printf("\n***********************************************************************\n\n"); // Print a separte line.

  // Step 6: Count and report the number of one character letter, two contiguous 
  //         character letters, three contiguous character letters, and four or
  //         more contiguous character letters.
  char_ptr0 = data_ptr; // Start from the beginning of the text.
  // Construct a single-character string of the current character.
  one_char[1] = '\0'; // Since the string is of length 1, insert end-of-string in the second array element.
  total_count = 0; // Reset total character count to 0.
  while (char_ptr0[0]!='\0') { // Continue, When there are more letters.
    one_char[0] = char_ptr0[0]; // Insert the letter.
    length = strspn(char_ptr0, one_char); //Find the length of the contiguous letter.
    total_count += length; // Sum up the total character count.
	char_ptr0 = char_ptr0 + length; // Move to the address of the next distinguished letter.
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
  printf("***********************************************************************\n\n"); // Print a separte line.
 
  // Step 7: Count and report the number of each occurence of vowels,
  //         'A', 'E', 'I', 'O', and 'U'.
  char_ptr0 = (char *) strpbrk(data_ptr, vowels); // Find the first vowel.
  total_count = 0; // Reset total vowel count to 0.
  while (char_ptr0!=NULL) { // Continue, when there are more vowels.
    switch (*char_ptr0) { // Check the case of the vowel.
      case 'A': {++vowel_count[0]; break;} // Vowel 'A', increment its count.
      case 'E': {++vowel_count[1]; break;} // Vowel 'E', increment its count.
      case 'I': {++vowel_count[2]; break;} // Vowel 'I', increment its count.
      case 'O': {++vowel_count[3]; break;} // Vowel 'O', increment its count.
      case 'U': {++vowel_count[4]; break;} // Vowel 'U', increment its count.
    }
    char_ptr0 = (char *) strpbrk(char_ptr0+1, vowels); // Find the next vowel.
    total_count++; // Increment total vowel count.
  }
  printf(">>>> The number of occurences of vowels:\n"); // Report vowel counts.
  for (i=0; i<5; i++) // Print vowel count.
    printf("  Vowel \'%c\': %u\n", vowels[i], vowel_count[i]);
  printf("  **** Total vowel count: %u\n", total_count);
  printf("***********************************************************************\n\n");
  
  if (is_palindrome(data_ptr)) printf(">>>> Yes, the testing data is a palindrome.\n"); // Yes, a palindrome.    
  else printf(">>>> No, the testing data is not a palindrome.\n"); // No, not a palindrome. 
  printf("***********************************************************************\n\n");
  
  // Step 8: Write the modified text to a file named longest_palindrome_out.txt.
  write_text_file("longest_palindrome_out.txt", data_ptr); // Write the modified text.
  printf(">>>> The modified text is written to file longest_palindrome_out.txt.\n"); // Print file writing message.
  printf("***********************************************************************\n"); // Print a separte line.

  return 0;
}  
