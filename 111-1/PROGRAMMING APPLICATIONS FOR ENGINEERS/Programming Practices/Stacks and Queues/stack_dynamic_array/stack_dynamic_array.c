#include <stdio.h>
#include <stdlib.h>
#include "stack_dynamic_array.h"

int temp = 0;

// Initialize a stack.
void initial(Stack *S) {
  // Allocate a segment of elements to the stack.
  S->elem = (ElemType *) malloc(SEGMENT*sizeof(ElemType));  
  S->top = -1; // Set top pointer to -1.
  S->capacity = SEGMENT; // Set initial capacity.
}

// Check if a stack is empty or not.
int is_empty(Stack S) {
  return S.top==-1; 
}

// Check the element at the top.
ElemType top(Stack S) {
  if (S.top<0) return -1; // The stack is empty, return -1.
  else return S.top; // Return the top element. 
}

// Insert an element to a stack.
void push(Stack *S, ElemType e) {
	S->elem[++S->top] = e; // Insert an element and increment the top index.
	if (get_size(*S)==S->capacity) {// If the stack is full, expand the stack capacity.
    // Reallocate memory space, add one more segement. 
	  S->elem = (ElemType *) realloc(S->elem, 
                                   (S->capacity+SEGMENT)*sizeof(ElemType));
	  S->capacity += SEGMENT; // Update stack capacity. 
	}
}

// Remove an element from a stack.
ElemType pop(Stack *S) {
	ElemType e; // The element to be returned.
	
	if (S->top<0) return -1; // The stack is empty; cannot pop an element.
	e = S->elem[S->top--]; // Get the current top element and decrement the top index.
	if (get_size(*S)==S->capacity-SEGMENT*2) { // Too many vacant capacity?
    // Reallocate memory space, reduce one segement. 
    S->elem = (ElemType *) realloc(S->elem,
                                   (S->capacity-SEGMENT)*sizeof(ElemType));
	S->capacity -= SEGMENT; // Update stack capacity.   
	                     
	}
	return e; // Return the original top element.
} 

// Check the size of the stack. (not a basic operation)
int get_size(Stack S) {
	return S.top + 1; // Return the size of the stack. 
}

// Clear the stack, set the capacity to one segment. (not a basic operation)
void clear(Stack *S) {
  // Reallocate memory space, set the capacity to one segement.
  S->elem = (ElemType *) realloc(S->elem, SEGMENT * sizeof(ElemType)); 
  S->top = -1; // Set the stack to be empty.
  S->capacity = SEGMENT; // Update stack capacity. 
}

// Print the stack from bottom to top (not a basic operation)
void print_stack(Stack S) {
  int i; // Loop variable.
	
  printf("Stack capacity: %d elements\n", S.capacity); 
  printf("Stack size:     %d elements\n", S.top+1);
  printf("****From bottom to top\n");
	
  for (i=0; i<S.top+1; i++) {
    printf("%3d ", S.elem[i]); // Print the i-th element from top 
    if ((i+1)%20==0) printf("\n"); // 20 elements each line. 
  }
  if ((i%20)!=0) printf("\n"); // Print a new line if the last line is less 20 elements.
  printf("\n"); // Print a new line.
}
