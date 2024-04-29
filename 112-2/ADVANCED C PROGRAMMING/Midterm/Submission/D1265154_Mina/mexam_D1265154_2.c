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
	int i,j;
	char elem;
	for(i=0;i<L->List;i++)
		if(elem[i]>=e)break;
	for(j=L->List-1;j>=i;j--)
		if(elem[j]==e)L->List
		elem[j+1]=elem[j];
		L->data = L->next;
	return e;
	
	
	
		
		
		

		
	
	
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
Term current = ptr;
int count;
	while(current != NULL){
		current = current -> next;
		count++
	}
	return count;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	int i,j;
	for (i=n-2; i>=0; i--)
	for (j=0; j<=i; j++)
	if (ptr1[i]>ptr2[i+1]) swap(&ptr1[i], &ptr2[i+1]);
	

}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	Term curret = P;
	if(current->next && coeff == deg)return current=current->next;
	
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
	printf(">>>>> Unordered singly-linked linear list: ");
	printf("\n");
	printf(">>>>> Sorted singly-linked linear list: ");
	printf("\n");
	
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	if(rand()%20==0)  printf(" ");
	
	return 0;
}
