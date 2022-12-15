#define SEGMENT 50 // Segment size.

typedef int ElemType; // Integer element type.

typedef struct {
  ElemType *elem; // Starting address of the stack continer.
  int top; // Index of the top element, initial value -1.
  int capacity; // Stack capacity, initial a segment.
} Stack;

// Initialize a stack.
void initial(Stack *);

// Check if a stack is empty or not.
int is_empty(Stack);

// Check the element at the top.
ElemType top(Stack);

// Insert an element to a stack.
void push(Stack *, ElemType);

// Remove an element from a stack.
ElemType pop(Stack *);

// Check the size of the stack. (not a basic operation)
int get_size(Stack);

// Clear the stack, set the capacity to one segment. (not a basic operation)
void clear(Stack *);

// Print the stack from bottom to top (not a basic operation)
void print_stack(Stack);

