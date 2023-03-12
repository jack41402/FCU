// Basic operation interface of single linked ordered linear list.
typedef int ElemType; // Define the linear list element type as an integer.

typedef struct node { // Define linked list node 
  ElemType elem; // Node data, integer 
  struct node* next; // Node link, defined recursively
} Node; // Node type 

typedef Node* Link; // Node link, pointer to a node.

// The ordered linear list is a node pointer, pointing to the 
// head node of the linked list.
typedef Link List; 

 // Initialize linear list.
void initial(List *);

// Get size of the linear list.
int getSize(List); 

// Get the i-th element of the linear list and return the value of the element.
// If i is greater than the number of elements in the linear list, return -1.
ElemType getElem(List, int);

// Search the element of the linear list and return the position of the element. 
// If successful, return the position of the element; otherwise, return -1.
int search(List, ElemType);  

// Insert an element into the appropriate position of the linear list. 
// If successful, return the position of the element; otherwise, return -1
int insertElem(List *, ElemType);

// Delete an element from the list. 
// If successful, return the original position of the element; otherwise, return -1.
int removeElem(List *, ElemType); 

// Clear the linear list.
void clear(List *);

// Checks whether the linear list is empty. Return 1, if empty; otherwise, return 0.
int is_empty(List); 

// Print the linear list elements. We add this function because of its necessity.
void printlst(List);
 

