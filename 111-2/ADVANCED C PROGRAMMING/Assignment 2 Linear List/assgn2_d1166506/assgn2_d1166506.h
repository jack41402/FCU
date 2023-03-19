typedef int ElemType ; // Define the linear list element type as an integer.

// Define linked list node
typedef struct node
{
    ElemType elem ;
    struct node* next ;
} Node ;

// Node link, pointer to a node.
typedef Node* Link ;

// The ordered linear list is a node pointer
// pointing to the head node of the linked list.
typedef Link List ;

// Initialize a linear list, set its size to 0.
void initial (List *);

// The length of a linear list, returns the number of elements, namely size.
int getSize (List);

// Get the element at a position from a linear list, return the designated element.
ElemType getElem (List , int);

// Set the element at a position in a linear list to a specific element.
ElemType setElem (List , ElemType , int);

// Find the position of an element in L. If successful, return the position of the
// element; otherwise, returns -1.
int search (List , ElemType);

// Insert an element after the end of a linear list, return the position of the inserted element.
// If the inserted element exists in the linear list or the linear list is overflow, insertElem() fails, and returns -1.
int insertElem (List * , ElemType);

// Delete an element from a list. If the element is in the linear list, delete it and
// return its position; otherwise, return -1.
int deleteElem (List * , ElemType);

// Print all elements of the linear list starting from the head.
void printList (List);

// Append list L2 at the end of L1.
// If an element of L2 exists in L1, discard that element.
// Return the result of append() operation.
List append (List , List);

// Join two lists L1 and L2.
// Return a list containing all common elements in L1 and L2.
// The elements of the resulting list are stored in the order of list L1.
List join (List , List);

// Sort list L. The elements of L are rearranged into the ascending order.
void sort (List *);