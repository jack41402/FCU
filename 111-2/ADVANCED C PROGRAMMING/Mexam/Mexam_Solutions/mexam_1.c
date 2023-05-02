#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Dictionaries for reversed letters and digits.
//             Characters: 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'L', 'M',
char reverse_letter[26] = {'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J', 'M',
//             Characters: 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                           ' ', 'O', ' ', ' ', ' ', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
 //                Digits: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
char reverse_digit[10]  = {'0', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' '};

/* 
  RECURSIVE function check_palindrome_mirrored() checks palindrome and mirrored string 
  at the same time. The function has four parameters as below:
  int check_palindrome_mirrored(char *low, char *high, 
                                int is_palindrome, int is_mirrored)
    low: a pointer to the chraracters on the left-half of the input string, initailly,
         low points to the first character of the input string.
    high: a pointer to the characters on the right-half of the input string, initially,
          high points to the last character of the input string.
    is_palindrome: a flag indicates if the string is a palindrome, initially,
	               is_palindrome is of value 1, means true; is_palindrome is turned to 0,
				   flase, when the input string is determined not a palindrome.
    is_mirrored: a flag indicates if the string is a mirrored string, initially,
	             is_mirrored is of value 1, denoting true; is_mirrored is turned to 0, 
				 false, when the input string is determined not a mirrored string.
               
    The function terminates when high<=low OR both is_palindrome AND is_mirrored are both
    false and value 2*is_palindrome+is_mirrored is returned. That is, the return value is 
	one of the following cases:
	    0: neither palindrome nor mirrored string,
        1: mirrored string,
        2: palindrome,
        3: both palindrome and mirrored string.
*/
int check_palindrome_mirrored(char *low, char *high, int is_palindrome, int is_mirrored) {
  // The function terminates when high<=low OR both is_palindrome AND is_mirrored.	
  if (high<=low || (!is_palindrome && !is_mirrored))
    return is_palindrome * 2 + is_mirrored; // 0: neither palindrome nor mirrored string,
                                            // 1: mirrored string,
											// 2: palindrome,
										    // 3: both palindrome and mirrored string.
  // The string may be a palindrome,  but, the paired characters do not match.
  else if (is_palindrome && *low!=*high)
    // Set is_palindrome to false.
    return check_palindrome_mirrored(low, high, 0, is_mirrored); 
  // The string may be a mirrored one and the low points to a character;
  // but the paired characters are not reverse of each other.
  else if (is_mirrored && isalpha(*low) && *high!=reverse_letter[*low-0X41])
    // Set is_mirrored to false; move low to the character on theright and 
	// high to the character on the left.
    return check_palindrome_mirrored(low+1, high-1, is_palindrome, 0);
  // The string may be a mirrored one and the low points to a digit;
  // but the paired characters are not reverse of each other.
  else if (is_mirrored && isdigit(*low) && *high!=reverse_digit[*low-0X30])
    // Set is_mirrored to false; move low to the character on theright and 
	// high to the character on the left.
    return check_palindrome_mirrored(low+1, high-1, is_palindrome, 0);
  
  // Otherwise, do not update the values of is_palindrome and is_mirrored.
  // Move low to the character on theright and high to the character on the left.  
  else return check_palindrome_mirrored(low+1, high-1, is_palindrome, is_mirrored);
}

int main(void) {
  char string[100]; // Maximum string length is 99.
  char *first; // Pointer to the first character of the input string.
  char *last; // Pointer to the last character of the input string. 
  
  do { // Continue to enter a string and palindrome and mirrored string.
    // Input message.
    printf(">>>> Enter a string (uppercase characters and digits, maximum 99 characters): ");
    scanf("%s", &string); // Read a string.
    
    first = &string[0]; // Pointer to the first character of the input string.
    last  = &string[strlen(string) - 1]; // Pointer to the last character of the input string.
    
    // Call check_palindrome_mirrored(); it returns value 0, 1, 2, or 3.
    switch (check_palindrome_mirrored(first, last, 1, 1)) {
      case 0: { // neither a palindrome nor a mirrored string.
        printf("  \"%s\" is neither a palindrome nor a mirrored string.\n", string); 
	    break;
	  }
	  case 1: { // mirrored string.
	    printf("  \"%s\" is a mirrored string.\n", string);
	    break;
	  }
	  case 2:{ // a palindrome string.
	    printf("  \"%s\" is a palindrome string.\n", string);
	    break;
	  }
	  case 3:{ // a mirrored palindrome string
	    printf("  \"%s\" is a mirrored palindrome string.\n", string);
	    break;
	  }
    }
    printf("\n************************************************\n");
  } while (strcmp(string, "000"));  // The loop terminates if the input string is "000".
  
  return 0;
} 
