// Basic operation interface of single linked ordered linear list.
#include <stdio.h>
#include <stdlib.h>
#include "ordered_list_single_list.h"

 // Initialize linear list.
void initial(List *L) {
  *L = NULL; // Sets the pointer to the linear list to NULL. 
}

// Get size of the linear list. 
int getSize(List L) {
	Link link = L; // node pointer. 
	int size = 0; // The initial value of the linear list size is set to 0.
	
	while (link!=NULL) {
    link = link->next; // Next node.
    size++; 
  }
  return size; // The size of the linear list L.	 
}

// Get the i-th element of the linear list and return the value of the element.
// If i is greater than the number of elements in the linear list, return -1.
ElemType getElem(List L, int inx) {
  Link current = L; // Node pointer.
  int i; // Loop variable. 
	
  for (i=0; i<inx; i++) 
    if (current==NULL) return -1; // The ith element does not exist. 
    else current = current->next; // Move to the next node. 
  return current->elem; // Return the element value of the node.
} 

// Search the element of the linear list and return the position of the element. 
// If successful, return the position of the element; otherwise, return -1.
int search(List L, ElemType e) {
  Link link = L; // Node pointer.
  int position=0; // Element position, set the initial value to 0. 
	
  while (link!=NULL) {
    if (link->elem==e) return position; // The search succeeds. The position is returned. 
    else if (link->elem<e) { // There are other nodes, continue to search. 
      link = link->next; // Move to the next node. 
      position++; // Increment the position by 1. 
    }
    else return -1; // Node's value exceeded, search failed. 
  }
  return -1; // Pass the last node of the linear list, search failed. 
} 

// Insert an element into the appropriate position of the linear list. 
// If successful, return the position of the element; otherwise, return -1
int insertElem(List *L, ElemType e) {
  Link current = *L; // Pointer to the current node.
  Link previous = NULL; // Pointer to the previous node, initially NULL. 
  Link newNode; // Pointer to the new node.
  int position = 0; // Current node position.
	
	if (*L==NULL) { // Case 1: The linear list is empty.
    newNode = (Link) malloc(sizeof(Node)); // Allocate memory for a new node.
    newNode->elem = e; // Set the data of the head node. 
    newNode->next = NULL; // Set the head node.
    *L = newNode; // The linear list points to the first node.
	return 0; // Return the position of the head node. 
	}
	
  do { // Check the current node.
  // Cases 2 & 3: Find the insertion position and insert a new node before this node.
  if (current->elem>=e) {  
    newNode = (Link) malloc(sizeof(Node)); // Allocate memory for a new node.
    newNode->elem = e; // Set the data for the new node. 
    newNode->next = current; // Set up the new node's link.
    if (previous==NULL) *L = newNode; // Case 2: Insert the head node of the linear list.
	else previous->next = newNode; // Case3: Modify the chain of the previous node. 
    return position; // Return the position. 
    }
  else {
    previous =  current;// The current node becomes the previous node. 
    current = current->next; // Set the next node as the current node for the next step. 
    position++; // Increment the position by 1.
  }
  } while (current!=NULL); // If there are more nodes in the linear list, continue. 

  // Case 4: The while loop ends, no execution returns, 
  //         and moves to the last node of the linked list. 
  newNode = (Link) malloc(sizeof(Node)); // Allocate memory for a new node.
  newNode->elem = e; // Set the data for the new node.
  newNode->next = NULL; // The last node, set its next node to NULL.
	previous->next = newNode; // Put the newly added node at the end of the linear list.
  return position; // Return the position.
}

// Remove an element from the list. 
// If successful, return the original position of the element; otherwise, return -1.
int removeElem(List *L, ElemType e) {
  Link current = *L; // Pointer to the current node.
  Link previous; // Pointer to the previous node. 
  int position = 0; // Current node position.
	
  while (current!=NULL) { // When the linear list still has nodes,
    if (current->elem==e) { // Find the node to remove.
      if (position==0) { // The removed node is the head node. 
        *L = current->next; // Set the next node as the head node.
        free(current); // Release the removed node.
        return position; // Return the original position of the removed node. 
      }
      else {
        previous->next = current->next; // Update the previous node. 
        free(current); // Release the removed node.
        return position; // Return the original position of the removed node. 
      } 
    }
    else if (current->elem<e) {
      previous = current; // Set the current node to be the previous node. 
      current = current->next; // Set the next node as the current node for the next step. 
      position++; // Increment the position by 1.
    }
    else return -1; // The current node data has exceeded the specified value; remove failed.
  }
  return -1; // There are no more nodes, and remove failed. 
}

// Clear linear list.
void clear(List *L) {
  Link current; // Pointer to the current node.
	
  while (*L!=NULL) { // There are still nodes to clear.
    current = *L; // The current node.
    *L = current->next; // The rest of the link list.
    free(current); // Release the current node. 
  }
}

// Checks whether the linear list is empty. Return 1, if empty; otherwise, return 0.
int is_empty(List L) {
  return L==NULL; // If L is NULL, return 1; otherwise, return 0. 
} 

// Print the linear list elements. 
// We add this function because of its necessity.
void printlst(List L) {
  List current = L; // Pointer to the current node.
  int position = 0; // The current position of the node. 
	
  printf("Number of linear list elements:%3d\n", getSize(L));

  while (current!=NULL) { // There are still nodes to print.
    printf("%3d ", current->elem); // Print node data.
    if ((++position)%20==0) printf("\n"); // When 20 elementsl, print a newline.
    current = current->next; // Move to the next node. 
  }
  if ((position%20)!=0) printf("\n"); // If there are less than 20 elements, print a newline.
  printf("\n"); // Print a newline. 
} 
