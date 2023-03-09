// Use a ordered linear list with no duplicate elements to implement set operations.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_list_dynamic_set.h"

// Union operation: all elements of two sets R and S.
// Return the linear list of the union of R and S.
List Union(List R, List S) {
  List T; // Union of sets R and S.   
  int size1=getSize(R), size2=getSize(S); // Sizes of set R and S.  
  ElemType e1, e2; // Elements of set R and S. 
  int i1=0, i2=0; // Indexes of set R and S
	
  initial(&T); // Initialize set T.
	
  // If i1<size1, R has more elements to check.
  // If i2<size2: S has more elements to check. 
  while (i1<size1 && i2<size2) {
    e1 = getElem(R, i1); // Get an element of set R.
    e2 = getElem(S, i2); // Get an element of set S.
    // Put the smaller element of R and S into set T and move the next element.
    if (e1==e2) {insertElem(&T, e1); i1++; i2++;} // Join common elements of sets R and S. 
    else if (e1<e2) {insertElem(&T, e1); i1++;} // Add an element of R. 
    else {insertElem(&T, e2); i2++;} // Add an element of S. 
	}
	
  // Set A still has elements, continue to copy the elements of R.
  // insertElem() will not insert if the element is duplicated. 
  while (i1<size1) insertElem(&T, getElem(R, i1++));
	
  // Set B still has elements, continue to copy the elements of S.
  // insertElem() will not insert if the element is duplicated. 
  while (i2<size2) insertElem(&T, getElem(S, i2++));
	
  return T; // Return the linear list of union.  
} 

// Intersection operation: Common elements of two sets R and S.
// Return the linear list of the intersection of R and S.
List Intersection(List R, List S) {
  List T; // Intersection of sets R and S.   
  int size1=getSize(R), size2=getSize(S); // Sizes of set R and S.  
  ElemType e1, e2; // Elements of set R and S. 
  int i1=0, i2=0; // Indexes of set R and S
	
  initial(&T); // Initialize set T.
	
  // If i1<size1, R has more elements to check.
  // If i2<size2: S has more elements to check.
  while (i1<size1 && i2<size2) {
    e1 = getElem(R, i1); // Get an element of set R.
    e2 = getElem(S, i2); // Get an element of set S.
    
	// If the elements are the same, add the result of the intersection, 
	// and both sets proceed to the next element. 
    if (e1==e2) {insertElem(&T, e1); i1++; i2++;} 
    else if (e1<e2) i1++; // The element of R is smaller, move to the next element of R. 
    else i2++; // The element of S is smaller, move to the next element of S. 
	}
	
  return T; // Return the linear list of intersection.  
}

// Difference operation: elements in set R, but not in set S.
// Return the linear list of the differencde of R and S.
List Difference(List R, List S) {
  List T; // Difference of R and S.
  int size=getSize(R); // Sizes of set R.  
  ElemType e; // Elements of set R.
  int i=0; // Index of set R.
	
  initial(&T); // Initialize set T.
	
    // If i1<size1, R has more elements to check.
  while (i<size) {
    e = getElem(R, i++); // Get ab element of R and proceed to the next element. 
    // If element e is not in S, add the result of difference.
    if (search(S, e)<0) insertElem(&T, e);
  }
	
  return T; // Return the linear list of differenced.   
} 

int main(void) {
  List A, B, C; // Declare three sets. 
  int length1, length2; // Length of set A and B.
  int i; // Loop variable. 
	
  initial(&A); // Initialize set R.
  initial(&B); // Initialize set S.
	
  srand(time(NULL)); // Seed for the random number generator.
	
  // Input the size of set A. 
  do {
    printf("Enter the size (between 1 and 100 (inclusive)) of set A: ");
    scanf("%d", &length1);
  } while (length1<0 || length1>100);
	
  // 输入集合 L2 的元素个数。 
  do {
    printf("Enter the size (between 1 and 100 (inclusive)) of set B: ");
    scanf("%d", &length2);
  } while (length2<0 || length2>100);
  printf("-------------------------------------------\n");
	
  // Generate elements of set A. 
  i = 0; // Set index to 0.
  while (i<length1)
    if (insertElem(&A, rand() % 200)>=0) i++; // Add an element to set A.
  printf("Set A:\n"); 
  printlst(A); // Print set A. 
	
  // Generate elements of set B. 
  i = 0; // Set index to 0.
  while (i<length2)
    if (insertElem(&B, rand() % 200)>=0) i++; // Add an element to set B.
  printf("Set B:\n"); 
  printlst(B); // Print set B. 
	
  C = Union(A, B); // Compute union of sets A and B. 
  printf("Union of sets A and B:\n"); 
  printlst(C); // Print union of sets A and B.
	
  clear(&C); // Clear set C. 
  C = Intersection(A, B); // Compute intersection of sets A and B. 
  printf("Intersection of sets A and B:\n"); 
  printlst(C); // Print intersection of sets A and B.
	
  clear(&C); // Clear set C. 
  C = Difference(A, B); // Compute difference of sets A and B. 
  printf("Difference of sets A and B:\n"); 
  printlst(C); // Print difference of sets A and B.
	
  return 0; 
} 
