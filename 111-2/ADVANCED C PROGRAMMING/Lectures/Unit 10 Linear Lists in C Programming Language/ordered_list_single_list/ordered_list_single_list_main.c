#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordered_list_single_list.h"

// Merge two linear lists L1 and L2.
// Return the merged linear list. 
List merge_list(List L1, List L2) {
  List L; // The merged linear list.   
  int size1=getSize(L1), size2=getSize(L2); // The size of linear lists L1, and L2.  
  ElemType e1, e2; // Elements of linear lists L1 and L2. 
  int i1=0, i2=0; // Indexes to linear lists L1 and L2.
	
  initial(&L); // Initialize L. 
	
  // If i1<L1.size, l1 still has elements to merge.
  // If i2<L2.size, l2 still has elements to merge. 
  while (i1<size1 && i2<size2) {
    e1 = getElem(L1, i1); // Get an element of L1.
    e2 = getElem(L2, i2); // Get an element of L2.
    // Insert the smaller element of L1 and L2 into L and move to 
	// the position of the next element¡£ 
    if (e1<=e2) {insertElem(&L, e1); i1++;}
    else {insertElem(&L, e2); i2++;}
	}
	
  // L1 still has elements, continue to copy the elements of L1.
  while (i1<size1) insertElem(&L, getElem(L1, i1++));
	
  // L2 still has elements, continue to copy the elements of L2. 
  while (i2<size2) insertElem(&L, getElem(L2, i2++));
	
  return L; // Return the merged linear list.  
} 

// Collectively remove all elements of L2 from L1.
// Return the removed linear table.
List remove_list(List L1, List L2) {
  List L; // Removed linear list.   
  int size1=getSize(L1), size2=getSize(L2); // Removed linear list.  
  ElemType e1, e2; // Elements of the linear lists L1 and L2. 
  int i1=0, i2=0; // Indexes to the linear lists L1 and L2.
	
  initial(&L); // Initialize L.
	
  // If i1<size1, l1 still has elements to remove.
  // If i2<size2, l2 still has elements to remove.
  while (i1<size1 && i2<size2) {
    e1 = getElem(L1, i1); // Get an element of L1.
    e2 = getElem(L2, i2); // Get an element of L2. 
    // If the elements of L1 and L2 are the same, remove the elements 
	// of L1 and not store them. 
    if (e1==e2) i1++;
    // If the element of L1 is smaller than the element of L2, 
	// put the elements of L1 into L.  
    else if (e1<e2) {insertElem(&L, e1); i1++;}
    // If the element of L1 is greater than the element of L2, 
	// check the next element of L2. 
    else i2++;
  } 
	
  // L2 has no elements; however, L1 still has elements, 
  // continue to put the elements of L1 into L.  
  while (i1<size1) insertElem(&L, getElem(L1, i1++));
	
  return L; // Return the removed linear list.   
} 

int main(void) {
  List L, L1, L2; // Declare the linear lists. 
  int leng1, leng2; // The length of the two linear lists. 
  int i; // Loop ariables 
	
  initial(&L1); // Initialize L1.
  initial(&L2); // Initialize L2.
	
  srand(time(NULL)); // Seed for the random number generator.
	
  // Input the number of elements of the linear list L1. 
  do {
    printf("Enter the size (between 1 and 100 (inclusive)) of the linear list L1: ");
    scanf("%d", &leng1);
  } while (leng1<0 || leng1>100);

  // Input the number of elements of the linear list L2. 
  do {
    printf("Enter the size (between 1 and 100 (inclusive)) of the linear list L2: ");
    scanf("%d", &leng2);
  } while (leng2<0 || leng2>100);
  printf("-------------------------------------------\n");

  // Randomly generate elements of L1. 
  for (i=0; i<leng1; i++) insertElem(&L1, rand() % 100); // Insert elements of L1.
  printf("Linear list L1£º\n");
  printlst(L1); // Print the linear list L1. 
  
  // Randomly generate elements of L2. 
  for (i=0; i<leng2; i++) insertElem(&L2, rand() % 100); // Insert elements of L2.
  printf("Linear list L2£º\n");
  printlst(L2); // Print the linear list L2. 

  L = merge_list(L1, L2); // Merge L1 and L2. 
  printf("Merged linear lists of L1 and L2:\n"); 
  printlst(L); // Print the merged linear list.
	
  L = remove_list(L1, L2); // Remove L2 from L1. 
  printf("Removed linear list of L2 from L1:\n"); 
  printlst(L); // Print the removed line list.

  return 0; 
} 
