#include <stdio.h>
#include "stack_array_parenthesis.h"

// Initialize a stack. 
void initialStack(Stack *s) {
  s->ptr = -1; // Set the index of top pointer to -1.
}

// Check if a stack is empty or not. 
int isEmpty(Stack s) {
  return (s.ptr < 0); // Stack s is empty, if the index of top pointer.
}

// Check the top element of a stack.
char top(Stack s) {
  if (s.ptr >= 0) return s.elem[s.ptr]; // The stack is not empty.
  else { // The stack is empty.
    printf("Stack empty.\n");
    return -1;
  }
}

// Insert an integer to the top of a stack.
void push(Stack *s, char e) {
  // When stack is not full, increment top pointer befor inseting the element.
  if (s->ptr < max-1) s->elem[++s->ptr] = e; 
  else printf("Stack overflow.\n"); // Stack is full. Cannot insert any element.
}

// Remove the top element from a stack.
char pop(Stack *s) {
  // When stack is not empty, decrement top pointer after removing the top element.
  if (s->ptr > -1) return s->elem[s->ptr--]; 
  else return -1; // Stack is empty. Cannot remove any element. 
}

// Print elements of a stack from the top to the bottom.
void printStack(Stack s) {
  int i;

  for (i = s.ptr; i>-1; i--)
    printf("%3c", s.elem[i]);
}

// Print elements of a stack from the bottom to the top.
void printStackBottomToTop(Stack s) {
  int i;

  for (i = 0; i<=s.ptr; i++)
    printf("%3c", s.elem[i]);
}

