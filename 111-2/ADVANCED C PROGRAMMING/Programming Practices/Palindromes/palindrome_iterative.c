/*
  This program repeatedly reads a string and checks whether it is a palindrome or not.
  The program stops when the input string is "000".
*/
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

int main(void) {
  char str[101]; // Input string, maximum 100 characters.
  
  while (1) { // Continue until "000" is read.
    printf("Enter a string: "); // Enter a string without spaces and punctuations.
    scanf("%s", str);
    
    if (strcmp(str, "000")) { // If the string is not "000".
      if (is_palindrome(str)) printf("**** %s is a palindrome.\n", str); // Palindrome check succeeds.
      else  printf("**** %s is not a palindrome.\n", str); // Palindrome check fails.
      printf("------------------------------------------------\n");
    }  
    else {
      printf("\n"); // String entered is "000". 
      return 0; // Retrun from the main program (program terminates).
    }
  }
}
