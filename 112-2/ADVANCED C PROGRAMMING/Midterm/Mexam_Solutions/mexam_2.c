#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node type Node and its pointer type NodePtr of an unordered singly-linked linear
// list as below:
typedef struct node {
	int data; // data element of a node
	struct node* next; // pointer to the next node on the right hand side
} Node; // type of a singly-linked node

typedef Node* NodePtr; // type of a node pointer

typedef NodePtr List; // type of a singly-linked linear list

// Initialize list L to the empty list.
void initial_list(List *L) {
	*L = NULL; // Set the pointer of L to NULL.
}

// Insert a node of data element e to the end of list L.
void insert(List *L, int e) {
	NodePtr new_ptr; // Pointer to a new node.
	NodePtr curr_ptr=*L; // Pointer to the current node.
  
	new_ptr = (NodePtr) malloc(sizeof(Node)); // Create a new node.
	new_ptr->data = e; // Store the data element.
	new_ptr->next = NULL; // Set the next link of the new node to NULL.
	if (curr_ptr == NULL) { // If the current list is empty.
		*L = new_ptr; // The inserted node is the first node of L.
	}
	else { // The current list is not empty.
  		while (curr_ptr->next!=NULL) curr_ptr = curr_ptr->next; // Search the last node of the list.
		curr_ptr->next = new_ptr; // Insert the node node as the end of the list.
  }
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	return ptr->data; // Return the data value.
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	int temp;
	
	// Swap the data elements of ptr1 and ptr2.
	temp = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = temp;
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	  NodePtr current=L; // Get the first node.
	int cnt=0; // Node counter.

	while (current!=NULL) { // If there is a node,
		printf("%3d ", current->data); // Print the data element.
		if (++cnt%20==0) printf("\n"); // Print a newline for every 20 data elements.
		current = current->next; // Get the next node on the right.
	}
	if (++cnt%20!=0) printf("\n"); // If not a full line print a newline.
	printf("\n");
}

int main(void) {
	List lst; // An unordered singly-linked linear list.
	NodePtr end_Ptr; // Pointer to the end node.
	NodePtr curr_Ptr; // Pointer to the current node.
	NodePtr prev_Ptr; // Pointer to the previous node.
	int n; // Number of nodes in lst.
	int i; // Loop variable.
  
	initial_list(&lst); // Initial the list.
	srand(time(NULL)); // Seed of the random number generator.

	// The number of nodes is between 20 and 500.
	do {
		printf("***** Enter the number of nodes: ");
		scanf("%d", &n);
	} while (n<=20 || n>500);

	// Randomly generate the unordered singly-linked linear list.
	for (i=0; i<n; i++) insert(&lst, rand() % 1000);
  
  	// Print the unordered singly-linked linear list.
	printf(">>>>> Unordered singly-linked linear list:\n");
	print_list(lst);
	
	// Sort the unordered singly-linked linear list.
	
	// Simulate insertion sort algorithm.
	// Search the end node of the linear list.
	end_Ptr = lst;
	while (end_Ptr->next!=NULL) end_Ptr =  end_Ptr->next;
	
	// Insertion sort algorithm.
	curr_Ptr = lst; // Starting node of the data segment. 
	// Peform compare-and-swap of two adjacent nodes, until reaching the end of data segment.
	while (curr_Ptr!=end_Ptr) { // Repeat if end node is not the starting node of the segment.
		do { // Compare-and-swap operation of two adjacent nodes.
			if (get_data(curr_Ptr)>get_data(curr_Ptr->next)) swap_node(curr_Ptr, curr_Ptr->next);
			prev_Ptr = curr_Ptr; // Recording the previous node.
			curr_Ptr = curr_Ptr->next; // Move to the next current node. 
		} while (curr_Ptr!=end_Ptr); // Repeat if not end node of the data segment. 
		
		end_Ptr = prev_Ptr; // Move the end node of position to the left.
		curr_Ptr = lst; // Reset the starting node.
	}
  
	printf(">>>>> Sorted singly-linked linear list:\n");
	print_list(lst);
	
	return 0;
}
