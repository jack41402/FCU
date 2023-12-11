/* 
  Write a C program to implement the following functions of doubly-linked list:
  1. void insert(List *L, int e): Insert a node of data element e to the last node of list L.
  2. void swap(NodePtr ptr1, NodePtr ptr2): swap two internal nodes pointed by ptr1 and ptr2. 
     Do not simply exchange the data element. The code must "physically" swap the two nodes by 
     modifying corresponding node pointers. (Hint: Need to modify eight node pointes.)
*/
#include <stdio.h>
#include <stdlib.h>

// Type delcaration of a doubly-linked list node.
typedef struct node {
	int data; // data element of a node
	struct node* left; // pointer to the node on the left-hand-side
	struct node* right; // pointer to the node on the right-hand-side
} Node; // type of a doubly-linked list node


// Type definition of node pointer.
typedef Node* NodePtr;

// Type definition of doubly-linked list.
typedef struct {
  NodePtr first; // Pointer to the first node.
  NodePtr last; // Pointer to the last node.
} List;

// Initialize list L to the empty list.
void initial_list(List *L) {
  L->first = NULL; // Set the pointer to the frist node to NULL.
  L->last  = NULL; // Set the pointer to the last node to null.
}

// Insert a node of data element e to the last node of list L.
void insert(List *L, int e) {
  NodePtr new_ptr; // Pointer to a new node.
  
  new_ptr = (NodePtr) malloc(sizeof(Node)); // Create a new node.
  new_ptr->data = e; // Store the data element.
  new_ptr->right = NULL; // The new node is the last node. Hence, set its right pointer to NULL.
  if (L->first == NULL) { // If the current list is empty.
    new_ptr->left = NULL; // The new node is also the first node. Hence, set its left pointer to NULL.
    L->first = new_ptr; // Update the first pointer.
    L->last  = new_ptr; // Update the last pointer.
  }
  else { // The current list is not empty.
    L->last->right = new_ptr; // Update the right pointer of the current last node.
    new_ptr->left = L->last; // Update the left pointer of the new node.
    L->last = new_ptr; // Set the new node as the last node.
  }
}

// Suppose prt1 and ptr2 are node pointers pointing to two internal nodes.
// Swap the nodes pointed by ptr1 and ptr2.
// Do not simply exchange the data elements.
// The code must "physically" swap the two nodes by modifying corresponding node pointers.
// Hint: Need to modify eight node pointers.
void swap(NodePtr ptr1, NodePtr ptr2) {
  NodePtr temp; // Temporary node pointer.
  
  ptr1->left->right = ptr2; // Modify the right pointer of the node on the left-hand-side of node pointed by ptr1.
  ptr1->right->left = ptr2; // Modify the left pointer of the node on the right-hand-side of node pointed by ptr1.
  ptr2->left->right = ptr1; // Modify the right pointer of the node on the left-hand-side of node pointed by ptr2.
  ptr2->right->left = ptr1; // Modify the left pointer of the node on the right-hand-side of node pointed by ptr2.
  // Swap the left pointers of the nodes pointed by ptr1 and ptr2.
  temp = ptr2->left; // Copy the left pointer of the node pointed by ptr2 to the temporary pointer.
  ptr2->left = ptr1->left; // Copy the left pointer of the node pointed by ptr1 to that by ptr2.
  ptr1->left = temp; // Copy the original left pointer of the node pointed by ptr2 to that by ptr1.
  // Swap the right pointers of the nodes pointed by ptr1 and ptr2.
  temp = ptr2->right; // Copy the right pointer of the node pointed by ptr2 to the temporary pointer.
  ptr2->right = ptr1->right; // Copy the right pointer of the node pointed by ptr1 to that by ptr2.
  ptr1->right = temp; // Copy the original right pointer of the node pointed by ptr2 to that by ptr1.
}

// Print the content of a node.
void print_node(NodePtr this_node) {
  // Print a node in a list: address of the node, left pointer, right pointer, and data element.
  printf("node address: 0X%06X, left pointer: 0X%06X, right pointer: 0X%06X, data element: %d\n", 
         this_node, this_node->left, this_node->right, this_node->data);
}

// Print all elements of a list from the head to the tail.
void print_list(List L) {
  NodePtr current=L.first; // Get the first node.
  
  while (current!=NULL) { // If there is a node,
    printf("%d ", current->data); // Print the data element.
    current = current->right; // Get the next node on the right.
  }
  printf("\n");
}

// Do not change the main program.
int main(void) {
  List lst; // A doubly-linked list.
  NodePtr node_12, node_20; // Pointers to node 12 and node 20.
  int i; // Loop variable.
  
  initial_list(&lst); // Initial the list.
  
  for (i=0; i<25; i++) insert(&lst, 50+i); // Insert 25 nodes to list lst with values from 50 to 74.
  
  printf(">>>> The list before swap operation:\n");
  printf("node index: ");
  for (i=0; i<25; i++) printf("%2d ", i); // Print node index.
  printf("\n");
  printf("data value: "); // Print data value.
  print_list(lst); // Print list of the nodes.
  printf("\n");  
  printf(">>>> The first node is on the left-most end, i.e., its left pointer is NULL:\n  ");  
  print_node(lst.first); // Print the first node.
  printf(">>>> The last node is on the right-most end, i.e., its right pointer is NULL:\n  ");  
  print_node(lst.last); // Print the last node.
  printf("\n");
  
  printf(">>>> Node 12 before swap operation:\n  ");  
  node_12 = lst.first; // Initial the pointer.
  for (i=0; i<12; i++) node_12 = node_12->right; // Get node 12.
  print_node(node_12); // Print node 12.
  
  printf(">>>> Node 20 before swap operation:\n  ");  
  node_20 = lst.first; // Initial the pointer.
  for (i=0; i<20; i++) node_20 = node_20->right; // Get node 20.
  print_node(node_20); // Print node 20.
  
  printf("\n***********************************************************************************************\n\n");
  
  swap(node_12, node_20); // Swap node 12 and node 20.
  
  printf(">>>> The list after swap operation:\n");
  printf("node index: ");
  for (i=0; i<25; i++) printf("%2d ", i); // Print node index.
  printf("\n");
  printf("data value: "); // Print data value.
  print_list(lst); // Print list of the nodes.
  printf("\n");
  
  printf(">>>> Node 12 after swap operation:\n  ");  
  node_12 = lst.first; // Initial the pointer.
  for (i=0; i<12; i++) node_12 = node_12->right; // Get node 12.
  print_node(node_12); // Print node 12.
  
  printf(">>>> Node 20 after swap operation:\n  ");  
  node_20 = lst.first; // Initial the pointer.
  for (i=0; i<20; i++) node_20 = node_20->right; // Get node 20.
  print_node(node_20); // Print node 20.
  
  return 0;
}
