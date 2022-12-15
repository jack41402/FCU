#define SEGMENT 50 // Segment size.
// Type definition of queues using a dynamic array.
// The queue elements of integers.

typedef struct
{
    int *elem ; // Pointer to queue container.
    int head ; // Index of the queue head.
    int tail ; // Index of the queue tail.
    int capacity ; // Capacity of a queue.
} Queue ;

// Set a queue to empty, i.e., reset head and tail of a queue.
void initial_queue(Queue *);

// Insert an element to the tail of a queue.
void enqueue(Queue * , int);

// Remove an element from the head of a queue.
int dequeue(Queue *);

// Get the element at the head of a queue.
int head(Queue);

// Check if a queue is empty or not.
int is_empty(Queue);

// Get size of queue.
int get_size(Queue);

// Clear queue and set capacity to one segment.
void clear(Queue *);

// Print elements of a queue from the head to the tail.
void print_queue(Queue);
