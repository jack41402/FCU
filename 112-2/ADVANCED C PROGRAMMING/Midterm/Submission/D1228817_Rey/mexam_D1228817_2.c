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
	List curr=*L;
	List prev=NULL;
	NodePtr New_node;
	New_node=malloc(sizeof(Node));
	
	if(curr==NULL){
		 *L=New_node;
	 New_node->next=NULL;
	 New_node->data=e;
	}
	
	
else{
	while(curr!=NULL){
		prev=curr;
		curr=curr->next;
	}
	
    curr=New_node;
	New_node->next=NULL;
	New_node->data=e;
	prev->next=New_node;
}	
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	return ptr->data;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	int x=ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=x;
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	int i=0;
	while(L!=NULL){
		printf("%3d ", L->data);
		i++;
		if(i%20==0) printf("\n");
		L=L->next;
	}
}


NodePtr search(int x, List L){
	int i;
	for(i=0; i<x; i++){
		L=L->next;
	}
	return L;
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
	
	printf(">>>>> Unordered singly-linked linear list:\n");
	
	// ***** Complete program of the following steps.
  
		print_list(lst)	;
		
		for (i=n-2; i>=0; i--){
			for (j=0; j<=i; j++){
				if (search(i, lst)->data>search(i+1, lst)->data) swap_node(search(i, lst), search(i+1, lst));
			}

		}
		
	/*	i=i-2;
		while(i>=0){
			while(j<=i){
				if (search(i, lst)->data>search(i+1, lst)->data) swap(search(i, lst), search(i+1, lst));
			}
		}*/

	printf("\n\n");
	print_list(lst)	;
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	
	return 0;
}
