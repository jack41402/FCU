#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  // A string is represented as a character array.
  //  word of string is of maximum 30 characters.
  char word[31];
  int count = 0; // Word count; initial value is 0.
  
  while (scanf("%s", word)==1) { // Input a string until no more data in the standard input stream.
  	printf("%s\n", word); // Output the word in a single line.
  	count = count + 1; // Increment the word count.
  }
  
  // Print a newline before the line contents. That is, print an empty line. 
  printf("\nTotal %d words.\n", count); // Output the total number of words. 
  
  return 0;
}
