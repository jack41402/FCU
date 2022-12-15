#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_array_parenthesis.h"

// Check whether string str contains all parenthesis symbols,
// '(', ')', '[', ']', '{', or '}'. 
int allParenthesis(char *str) {
  int i; // Loop variable
	
  for (i=0; i<strlen(str); i++) 
    if (!(str[i]=='(' || str[i]==')' ||  // Find a non-parenthesis character, return 0.
          str[i]=='[' || str[i]==']' ||
          str[i]=='{' || str[i]=='}')) return 0; 

  return 1; // Non non-parenthesis character, return 1. 
}

// Check if two characters are matching parentheses. 
int isMatching(char e, char c) {
	// Return 1, if a pair matching parentheses.
  return (e=='(' && c==')') || (e=='[' && c==']') || (e=='{' && c=='}'); 
} 

// Check if a string contains matching parentheses.
int parenthesisMatching(char *str) {  
  Stack S; // Stack to hold left-hand-side parenthesis symbols.
  char e; // To store symbol which is poped out from the stack. 
  int matching = 1; // Matcing flag, initial value is true.
  int i; // Loop variable.
	
  initialStack(&S); // Initialize the stack
	
  for (i=0; i<strlen(str) && matching; i++) {	// Scan the string when matching is true.
    if (str[i]=='(' || str[i]=='[' || str[i]=='{') // A left-hand-side parenthesis is found. 
      push(&S, str[i]); // Push the left-hand-side parenthesis to the stack. 
    else { // A right-hand-side parenthesis is found.
      e = pop(&S); // Pop an element from the stack.
      // If the element popped from the stack does not match the current character,
      // set matching to false.
      if (!isMatching(e, str[i])) matching = 0;  
    } 
  }
  // If all characters of the string has been scanned and the stack is empty,  
  if (matching==1 && isEmpty(S)) matching = 1; // the string contains matching parentheses.
  else matching = 0; // otherwise, matching is false.
  
  initialStack(&S); // Reset the stack.
	return matching; // Return the matching flag.
} 

int main(void) {
  char str[100]; // String of parentheses.
	
  do { // Repeat until the input string is "stop".
    do { // Input a string of parenthese.
		  printf("Input a string of parentheses ('(', ')', '[', ']', '{', '}')£º");
			scanf("%s", &str);
			if (!strcmp(str, "stop")) return 0; // If the string is "stop", program terminates. 
		} while (!allParenthesis(str));
		
	if (parenthesisMatching(str)) printf("**** String %s is all matching parentheses.\n", str);
	else printf("**** String %s is not all matching parentheses.\n", str); 
	
	printf("\n----------------------------------------\n\n"); // Print a separate line. 		
	} while (1);
}
