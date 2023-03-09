// Use a ordered linear list with no duplicate elements to implement set operations.
#include <stdio.h>
#include <stdlib.h>
#include "linear_list_dynamic_set.h"

// Initialize the linear list L, set size to 0.
void initial(List *L) {
  // Allocate memory space for a segement of elements.
  L->elem = (ElemType *) calloc(SEGMENT, sizeof(ElemType));  
  L->size = 0; // Set the linear list to empty.
  L->capacity = SEGMENT; // Initial capacity of the linear list.  
}

// The length of the linear list L, returns the number of elements, namely size. 
int getSize(List L) {
  return L.size; // Size of the linear list. 
}  

// Get the capacity of the linear list L.  
int getCapacity(List L) {
  return L.capacity; // The capacity of the linear list L 
}  

// Get element e at position i from L, if 0<=i<size, returns e, otherwise; returns -1.
ElemType getElem(List L, int i) {
  if (i>=0 && i<L.size) return L.elem[i]; // If 0<=i<size, return e;
  else return -1; // otherwise, return -1.
}  

// Finds the position of element e in L. If successful, return the position of e; 
// otherwise, return -1.
int search(List L, ElemType e) {
  int i; // Loop variable.
	
  for (i=0; i<L.size; i++)
    if (L.elem[i]==e) return i; // Search succeeds. 
  return -1; // Search fails.
} 

// Insert the element e at the appropriate position in L. 
// When insertion is completed, return the position of e.
// Make sure that the memory of the linear list has at least one empty element position, 
int insertElem(List *L, ElemType e) {
  int i, j; // Loop variables.
	
  for (i=0; i<L->size; i++)
    if (L->elem[i]>e) break; // Find the position to insert the element.
    else if (L->elem[i]==e) return -1; // Element e is in L, insertion fails, returning -1. 
	
  // Move element i and the following elements to the right one position. 	
  for (j=L->size-1; j>=i; j--) L->elem[j+1] = L->elem[j]; 
  L->elem[i] = e; // Inserts element e at the position of i.
  
  L->size++; // Update the number of elements in the linear list.
  // If the linear list is full, increase the memory capacity by one segement. 
  if (L->size==L->capacity) {
    L->elem = (ElemType *) realloc(L->elem, (L->capacity+SEGMENT)*sizeof(ElemType));
    L->capacity += SEGMENT; 
  }  
  return i; // Returns the position at which element e is inserted.  
} 

// Removes element e from L. If successful, returns the original position of e; 
// otherwise, returns -1.
int removeElem(List *L, ElemType e) {
  int i, j; // Loop variable.
	 
  for (i=0; i<L->size; i++)
    if (L->elem[i]==e) break;  // Find the position of the deleted element.
    else if (L->elem[i]>e) return -1; // Element e is not an element of list L, remove fails.
		 
  // If i==size, element e is not an element of the linear list L, remove fails. 
  if (i==L->size) return -1;
	
  // Moves the element after element i forward one position.  
  for (j=i; j<L->size; j++) L->elem[j] = L->elem[j+1]; 
  
  L->size--;  // Update the number of elements in the linear list.
  // If the capacity of the linear list is two segments more than the number of elements, 
  // reduce the capacity by one segment. 
  if ((L->capacity-L->size)>=SEGMENT*2) {
    L->elem = (ElemType *) realloc(L->elem, (L->capacity-SEGMENT)*sizeof(ElemType));
    L->capacity -= SEGMENT; 
  } 
  return i; // Returns the position at which element e was removed.
}

// Destroy the linear list L and release its memory space.
void destroy(List *L) {
	free(L->elem); // Release the memory space of the linear list.
	L->capacity = 0; // Reset the memory space of the linear list to 0. 
	L->size = 0; // The number of elements in the linear list is 0. 
} 

// Clear the linear list L.
void clear(List *L) {
  L->elem = (ElemType *) realloc(L->elem, SEGMENT*sizeof(ElemType)); // Reallocate memory space. 
  L->size = 0; // Reset the number of elements to 0.
  L->capacity = SEGMENT; // Reset the capacity. 
}

// Check if the linear list L is empty. 
// Returns 1 if empty; otherwise, returns 0.
int is_empty(List L) {
  return L.size==0; // If the size is 0, it is empty; otherwise, it is not empty. 
} 

// Print elements of the linear list.
// We add this function because of its necessity.
void printlst(List L) {
  int i; // Loop variable 
	
	printf("Linear list capacity: %3d\n", L.capacity); 
	printf("Number of linear list elements: %3d\n", L.size);
	
  for (i=0; i<L.size; i++) {
    printf("%3d ", L.elem[i]);   
    if ((i+1)%20==0) printf("\n"); // 20 elements in a line. 
  }
  if ((i%20)!=0) printf("\n"); // If there are less than 20 elements, print a newline.
  printf("\n"); // Print a newline. 
} 

