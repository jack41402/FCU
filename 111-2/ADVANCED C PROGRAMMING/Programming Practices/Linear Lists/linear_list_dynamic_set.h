// Use a ordered linear list with no duplicate elements to implement set operations.
#define SEGMENT 50 // The length of each segment of ordered linear list.
typedef int ElemType; // Integer linear list.

typedef struct {
  ElemType *elem; // dynamic array pointer of element type.
  int size; // The number of elements in the ordered linear list, the initial value is 0.
  int capacity; // The capacity of the ordered linear list.
} List;

// Initialize the linear list L, set size to 0.
void initial(List *L);

// The length of the linear list L, returns the number of elements, namely size.
int getSize(List L); 

// Get the capacity of the linear list L. 
int getCapacity(List L);

// Get element e at position i from L, if 0<=i<size, returns e, otherwise; returns -1.
ElemType getElem(List L, int i);

// Finds the position of element e in L. If successful, returns the position of e; 
// otherwise, returns -1.
int search(List L, ElemType e);  

// Insert the element e into L at the appropriate position. 
// If successful, returns the position of e; otherwise, returns -1.
int insertElem(List *L, ElemType e); 

// Removes element e from L. If successful, returns the original position of e; 
// otherwise, returns -1.
int removeElem(List *L, ElemType e); 

// Destroy the linear list L and release its memory space.
void destroy(List *L);
 
// Clear the linear list L.
void clear(List *L);

// Check whether the linear list L is empty. 
// Returns 1 if empty; otherwise, returns 0.
int is_empty(List L); 

// Print elements of the linear list.
// We add this function because of its necessity.
void printlst(List L);

