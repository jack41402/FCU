#define MAXIMUM 20 // Maximum elements of queue. 

typedef int ElemType; // Integer Element.

typedef struct {
  ElemType elem[MAXIMUM]; // Fixed array with at most MAXIMUM elements.
  int head; // The head pointer (index) of the queue, the initial value is -1.
  int tail; // The tail pointer (index) of the queue, the initial value is -1.
} Queue;

// Initialize Q. 
void initial(Queue *);

// Enqueue operation. 
void enqueue(Queue *, ElemType );

// Dequeue operation. 
ElemType dequeue(Queue *);

//reset (Queue *)

// Clear queue operation.
void clear(Queue *);

