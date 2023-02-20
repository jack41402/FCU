#define max 100 // Maximum 100 element. 

// Type definition of queues using an array.
// The queue elements of integers.
typedef struct {
  int elem[max]; // Holding elements of a queue.
  int head; // Index of the queue head.
  int tail; // Index of the queue tail.
  int cnt; // The the of elements in a queue.
} Queue;

// Set a queue to empty, i.e., reset head and tail of a queue.
void initial_queue(Queue *);

// Add an element to the tail of a queue.
void enqueue(Queue *, int);

// Remove an element from the head of a queue.
int dequeue(Queue *);

// Get the element at the head of a queue.
int head(Queue);

// Check if a queue is empty or not.
int is_empty(Queue);

// Print elements of a queue from the head to the tail. 
void print_queue(Queue);
