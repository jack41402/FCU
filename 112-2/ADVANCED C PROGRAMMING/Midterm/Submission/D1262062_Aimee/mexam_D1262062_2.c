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
	if(*L==NULL){
		newNode = (List) malloc(sizeof(Node));
		newNode->data = e; 
		*L = newNode;
	}
	else{
		newNode = (List) malloc(sizeof(Node));
		newNode->data = e;
		current->next = newNode;
	}
	newNode->next = NULL;
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	return ptr->data;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	NodePtr temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	List current = L;
	int position = 0;
	do{
		printf("%d ", current->data);
		if((position+1)%20==0) printf("\n");
		current = current->next;
		position++;
		
	}while(current!=NULL);
	printf("\n\n");
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
	printf(">>>>> Unordered singly-linked linear list:\n");
	print_list(lst);
  
  	// Print the unordered singly-linked linear list.
	for (i=n-2; i>=0; i--){
		for (j=0; j<=i; j++){
			if (get_data(prev_Ptr)>get_data(curr_Ptr)) swap_node(prev_Ptr, curr_Ptr);
		}
	}

	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	printf(">>>>> Sorted singly-linked linear list:\n");
	print_list(lst);
	return 0;
}
