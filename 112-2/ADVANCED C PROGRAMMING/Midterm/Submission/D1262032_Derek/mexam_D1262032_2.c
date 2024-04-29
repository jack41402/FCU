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
	List current=*L;
	List Newnode, previous=NULL; 
	if(current==NULL){
	Newnode=(List)malloc(sizeof(Node));
	Newnode->data=e;
	Newnode->next=NULL;
	*L=Newnode;
	} 
	else{
		do{
			previous=current;
			current=current->next;
		}while(current!=NULL);
		Newnode=(List)malloc(sizeof(Node));
		Newnode->data=e;
		Newnode->next=NULL;
		previous->next=Newnode;
	}
	
}

// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	List a=ptr;
	if(a==NULL) return -1;
	else{return a->data; }
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
     NodePtr temp_next;
     int temp;
     temp=ptr1->data;
     ptr1->data=ptr2->data;
     ptr2->data=temp;
     temp_next=ptr1->next;
     ptr1->next=ptr2->next;
     ptr2->next=temp_next;
}

// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	int i;
	List current=L;
	while(current!=NULL){
		printf("%3d ", current->data);
		if((i+1)%20==0) {printf("\n");}
		i++;
		current=current->next;
	}
	if(i%20!=0) printf("\n");
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
	printf(">>>>> Unordered singly-linked linear list:\n");
	print_list(lst);
	printf(">>>>> Sorted singly-linked linear list:\n");
	curr_Ptr=lst;
	end_Ptr=curr_Ptr->next;
	prev_Ptr=NULL;
    do{
	for (i=n-2; i>=0; i--){
		for (j=0; j<=i; j++){
			if (a[i]>a[i+1]) swap(&a[i], &a[i+1]);
		}
	}
    }while(curr_Ptr!=NULL);
    print_list(lst);

	// ***** Complete program of the following steps.
  
  	// Print the unordered singly-linked linear list.
	
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	
	return 0;
}
