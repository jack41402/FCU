#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

int main(void) {
  Stack s, t; // Declare two stacck variables.
  int i;

  // Initialize the two stacks.
  initialStack(&s);
  initialStack(&t); 
 
  for (i = 0; i < 50; i++) push(&s, i); // Insert integers 0 to 49 to stack s.
  printf("\nPrint stack s (from top to bottom):\n");
  printStack(s); // Print stack s.
  printf("\n");

  while (!isEmpty(s)) push(&t, pop(&s)); // Reverse elements of s to put in t. Stack s is destroyed.
  printf("\nPrint stack t (from top to bottom):\n");
  printStack(t); // Print stack t.
  printf("\n\n");
  
  return 0;
}
