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
	NodePtr nptr;
	
	nptr = (NodePtr) malloc(sizeof(Node));
	nptr->data = e;
	nptr->next = NULL;
	
	if (*L == NULL){
		*L = nptr;
	}
	else{
		*L = nptr;
	}
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	return ptr->data;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	NodePtr temp;
	
	temp = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = temp;
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	return get_data(L);
}

int main(void) {
	List lst; // An unordered singly-linked linear list.
	NodePtr end_Ptr; // Pointer to the end node.
	NodePtr curr_Ptr; // Pointer to the current node.
	NodePtr prev_Ptr; // Pointer to the previous node.
	int n; // Number of nodes in lst.
	int i, j; // Loop variable.
  
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
  	printf(">>>>> Unordered singly-linked linear list:\n");
  	for (i = 1; i <= n; i++){
  		if (i%21==0){
  			printf("\n");
		  }
  		printf("%d", print_list(lst));
	}
	printf("\n\n");
	
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	do{
		for (i=0; i<n; i++){
			for (j=0; j<n-i; j++){
				if (get_data(&lst) > get_data(&lst->next)){
					swap_node(&lst, &lst->next);
			}
		}
		break;
	}
	}while(1);
	
	printf(">>>>> Sorted singly-linked linear list:\n");
	// Print the sorted list lst with 20 elements in a line.
	for (i = 1; i <= n; i++){
		if (i%21==0){
  			printf("\n");
		}
  		print_list(&lst);
	}
	printf("\n\n");
	return 0;
}
