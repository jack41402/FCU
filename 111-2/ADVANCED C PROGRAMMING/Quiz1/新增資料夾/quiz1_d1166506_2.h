typedef int ElemType; // Integer element type.

typedef struct {
  ElemType elem[100]; // fixed-size array of 100 elements.
  int size; // number of elements in the linear list, 
} List;

// Initialize a linear list, set its size to 0.
void initial(List *);

// The length of a linear list, returns the number of elements, namely size.
int getSize(List); 

// Get the element at a position from a linear list, return the designated element.
ElemType getElem(List , int);

// Set the element at a position in a linear list to a specific element.
ElemType setElem(List *, ElemType, int);

// Find the position of an element in L. If successful, return the position of the 
// element; otherwise, returns -1.
int search(List, ElemType);

// Insert an element after the end of a linear list, return the position of the
// inserted element. If the inserted element exists in the linear list or the linear list
// is overflow, insertElem() fails, and returns -1.
int insertElem(List *, ElemType); 

// Delete an element from a list. If the element is in the linear list, delete it and
// return its position; otherwise, return -1.
int deleteElem(List *, ElemType);

// Print all elements of the linear list starting from the head.
void printList(List);

