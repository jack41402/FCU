#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hanoi_stack_array.h"

// Type definition of named stack.
// The bottom pointer is used for printing stack elements from the bottom. It is
// recorded only when the first element is pushed into the stack.
void initial_stack(Stack *s, char *name) {
  strcpy(s->name, name); // Store name of the stack.
  s->ptr = -1; // Reset the top pointer to -1.
}

// Return the name of the stack.
char *get_name(Stack *s) {
  return s->name;
}

// Check if the stack is empty or not.
int is_empty(Stack s) {
  return (s.ptr<0); // The stack is empty, if ptr is less than 0.
}

// Get the top element of the stack.
int top (Stack s) {
  return s.elem[s.ptr]; // Return the top element.
}

// Pust an element to the stack.
void push(Stack *s, int e) {
  s->elem[++s->ptr] = e; // Add an element to the top of the stack.
}

// Pop an element from the stack.
int pop(Stack *s) {
  return s->elem[s->ptr--]; // Remove an the top element from the stack.
}

// Print the elements of stack s from bottom to top.
// The parameter is call-by-address because the content of s is manipulated in 
// the print_stack function.
void print_stack(Stack s) {
  int i;

  for (i=0; i<=s.ptr; i++)
    printf("%3d", s.elem[i]);
}

