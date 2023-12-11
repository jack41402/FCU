#define max 100

// Type definition of named stack.
typedef struct {
  char name[10]; // Stack name.
  int elem[max]; // Stack elements.
  int ptr; // Stack top pointer.
} Stack;

// Initial stack as a peg; Stack *: pointer to the stack, char *: stack name.
// The stack name is given when calling function initial_stack().
void initial_stack(Stack *, char *);

// Return the name of the stack.
char *get_name(Stack *);

// Check if the stack is empty or not.
int is_empty(Stack);

// Get the top element of the stack.
int top(Stack);

// Pust an element to the stack.
void push(Stack *, int);

// Pop an element from the stack.
int pop(Stack *);

// Print the elements of stack s from bottom to top.
// The parameter is call-by-address because the content of s is manipulated in 
// the print_stack function.
void print_stack(Stack);
