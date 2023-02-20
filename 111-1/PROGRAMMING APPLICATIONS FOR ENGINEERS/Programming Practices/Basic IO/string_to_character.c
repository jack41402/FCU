/*
  Input a string and output the characters of the string one after one separated by a white space.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  // A string is represented as a character array.
  // String str to hold maximum 100 characters.
  char str[101];   
  int i; // Loop variable.

  printf("Input a string: "); // Request to input a string.
  scanf("%s", str);
  for (i=0; i<strlen(str); i++) // strlen(s) gives the length of the string.
    printf("%c ", str[i]); // Print a character (an array element) at a time.
  printf("\n"); // Print a newline.
  
  return 0;
}
