/*
  This program prints the following sequence of characters of in four lines. 
  Some of characters must be printed using escape sequences.
  '"/ \"'
   ??_??
     |
  ^^"@"^^
*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  // Escape sequence characters: ' " \ ? 
  printf("\'\"/ \\\"\'\n \?\?_\?\?\n   |\n^^\"@\"^^\n");
  
  return 0; 
}
