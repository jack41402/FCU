#define max 100

// Type definition of Stack.
typedef struct {
  int elem[max];
  int ptr;
} Stack;

// Initialize a stack. 
void initialStack(Stack *);

// Check if a stack is empty or not. 
int isEmpty(Stack);

// Check the top element of a stack.
int top(Stack);

// Insert an integer to the top of a stack.
void push(Stack *, int);

// Remove the top element from a stack.
int pop(Stack *);

// Print elements of a stack from the top to the bottom.
void printStack(Stack);

// Print elements of a stack from the bottom to the top.
void printStackBottomToTop(Stack);
