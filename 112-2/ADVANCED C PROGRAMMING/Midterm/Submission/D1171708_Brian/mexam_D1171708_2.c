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

// ***** Complete the following functions. 

// Insert a node of data element e to the end of list L.
void insert(List *L, int e) {
	List current = *L;
	List newNode;
	if(current==NULL){
		newNode = (List)malloc(sizeof(List));
		newNode->data = e;
		newNode->next = NULL;
		newNode = *L;
	}
	else{
		newNode = (List)malloc(sizeof(List));
		newNode->data = e;
		current->next = newNode;
		newNode->next = NULL;
		current = current->next;
	}
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	NodePtr current;
	return current->data; 
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	List current = L;
	int position = 0;
	while(current->data!=NULL){
		printf("%d ",current->data);
		current = current->next;
		position++;
		if(position%19==0){
			printf("\n");
		} 
	}
	
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
	printf(">>>> Unordered singly-linked linear list:");
	print_list(lst);
	printf(">>>> Sorted singly-linked linear list:");
	print_list(lst);
	// ***** Complete program of the following steps.
  
  	// Print the unordered singly-linked linear list.
	
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	
	return 0;
}
