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
	
/***** Complete this RECURSIVE function. Do NOT change the function parameters. *****/
	int ans=0 ;
	if (low>high)
	{
		if (is_palindrome==1 && is_mirrored==1) return 3;
		if (is_palindrome==1) return 2;
		if (is_mirrored==1) return 1;
		else return 0;
	}
	if (*low==*high && is_palindrome==1)
	{
		if (isalpha(*low) && reverse_letter[*low-'A']==*high && is_mirrored==1)
		{
			ans = check_palindrome_mirrored(low+1 , high-1 , 1 , 1) ;
		}
		else if (isdigit(*low) && reverse_digit[*low-'0']==*high && is_mirrored==1)
		{
			ans = check_palindrome_mirrored(low+1 , high-1 , 1 , 1) ;
		}
		else
		{
			ans = check_palindrome_mirrored(low+1 , high-1 , 1 , 0) ;
		}
	}
	else
	{
		if (isalpha(*low) && (reverse_letter[*low-'A']==*high || reverse_letter[*high-'A']==*low))
		{
			ans = check_palindrome_mirrored(low+1 , high-1 , 0 , 1) ;
		}
		else if (isdigit(*low) && (reverse_digit[*low-'0']==*high || reverse_digit[*high-'0']==*low))
		{
			ans = check_palindrome_mirrored(low+1 , high-1 , 0 , 1) ;
		}
	}
	return ans;
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
