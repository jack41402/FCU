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
		NodePtr curr_Ptr;
		NodePtr prev_Ptr;
		NodePtr end_Ptr;
		NodePtr new_Ptr;
		new_Ptr->data == e; 
		int position = 0;
	
		do{
			if(curr_Ptr->data==e){
				L = (List) malloc(sizeof (Node));
				prev_Ptr->next = new_Ptr;
				new_Ptr->next = curr_Ptr;
			}
			else{
				curr_Ptr = curr_Ptr->next;
			}
		}while(curr_Ptr->next!=end_Ptr);			
}
			

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	NodePtr curr_Ptr;
	NodePtr prev_Ptr;
	if(curr_Ptr->next<=ptr){
		if(curr_Ptr->data==ptr) return curr_Ptr;
		else{
			prev_Ptr->data = curr_Ptr->data;
			curr_Ptr->data = curr_Ptr->next->data;
		}
	}
	else return -1;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	NodePtr curr_Ptr = L;
	int i=0;
	do{
		printf("%d", curr_Ptr->data);
		if(i%20==0) printf("\n");
		i++;
	}while(curr_Ptr->next!="\0");
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
	
	// ***** Complete program of the following steps.
  
  	// Print the unordered singly-linked linear list.
  	printf(">>>>> Unordered singly-linked linear list: \n");
  	print_list(lst); 
  	
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	printf(">>>>> Sorted singly-linked linear list: \n");
	print_list(lst);
	
	return 0;
}
