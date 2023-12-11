/*
  This program repeatedly reads a string and checks whether it is a palindrome or not.
  The program stops when the input string is "000".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Palindrome check function, recursive version.
// s: string to be checked, h: head pointer, t: tail pointer.
int is_palindrome(char *s, unsigned int h, unsigned int t) { 
  
  if (s[h]!=s[t]) return 0; // If the two characters are not identical, return flase (0).
  else if (h>=t) return 1; // If head is not on the left-hand-side of tail, return true (1).
  else return is_palindrome(s, ++h, --t); // Recursive call, move h to the right and t to the left.
}

int main(void) {
  char str[101]; // Input string, maximum 100 characters.
  
  while (1) { // Continue until "000" is read.
    printf("Enter a string: "); // Enter a string without spaces and punctuations.
    scanf("%s", str);
    
    if (strcmp(str, "000")) { // If the string is not "000".
      if (is_palindrome(str, 0, strlen(str)-1)) printf("**** %s is a palindrome.\n", str); // Palindrome check succeeds.
      else  printf("**** %s is not a palindrome.\n", str); // Palindrome check fails.
      printf("------------------------------------------------\n");
    }  
    else {
      printf("\n"); // String entered is "000". 
      return 0; // Retrun from the main program (program terminates).
    }
  }
}
