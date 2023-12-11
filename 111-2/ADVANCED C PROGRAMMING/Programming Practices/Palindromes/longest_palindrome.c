#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
  unsigned int inx = 0; // Index of the modified text.
  unsigned int i; // Loop variable.
  
  // Read data from file "longest_palindrome_in.txt" and store in the da
  data_ptr = read_text_file("longest_palindrome_in.txt");
  
  for (i=0; i<strlen(data_ptr); i++) // Scan the entire data buffer.
    // If the character is an English letter, convert to the uppercase letter and
    // store it in the modified text;
    // otherwise, ignore the character, i.e., remove non-English letters.
    if (isalpha(data_ptr[i])) data_ptr[inx++] = toupper(data_ptr[i]);
  data_ptr[inx] = '\0'; // Insert the end-of-string after the end of the modified text.
  
  printf("The longest palindrome has %d characters.\n\n", inx);
  
  printf("The first 500 characters are:\n  "); // Print the first 500 characters.
  for (i=0; i<500; i++) { // 800 characters in a line.
  	if ((i+1)%80==0)  printf("%c\n  ", data_ptr[i]); // If it is not a full line, print the character only.
  	else printf("%c", data_ptr[i]); // If it is a full line, print the character and a new line.
  }
  printf("\n\n");
  
  if (is_palindrome(data_ptr)) printf("Yes, it is a palindrome.\n"); // Yes, a palindrome.    
  else printf("No, it is not a palindrome.\n"); // No, not a palindrome.
  
  write_text_file("longest_palindrome_out.txt", data_ptr); // Write the data in buffer to the output file.
  return 0;
}  
