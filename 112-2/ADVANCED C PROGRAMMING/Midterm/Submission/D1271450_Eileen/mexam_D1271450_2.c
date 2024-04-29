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
void insert(NodePtr *L, int e) {
	NodePtr current=*L;
	NodePtr previous=NULL;
	NodePtr newNode;
	int i=0;
	if(*L==NULL){
		newNode=(NodePtr)malloc(sizeof(newNode));
		newNode->data=e;
		newNode->next=NULL;
		*L=newNode;
		return i;
	}
	while(current!=NULL){
		if(current->data>=e){
			newNode=(NodePtr)malloc(sizeof(newNode));
			newNode->data=e;
			newNode->next=current;
			if(previous==NULL){
				*L=newNode;
			}
			else{
			 current=previous; 
		}
	}
	else{
		current=current->next;
		i++;
	}
	
}
    newNode=(NodePtr)malloc(sizeof(newNode));
    newNode->data=e;
    newNode->next=NULL;
    *L=current;
    return i;
}  


// Get the data value of the node pointed by ptr.
int get_data(NodePtr ptr) {
	NodePtr current;
	int i=0;
	while(ptr!=NULL){
		for(i=0;i<ptr;++i){
			current=current->next;
		}
		return current->data;
	}
	return -1;
}

// Swap two nodes pointed by ptr1 and ptr2.
void swap_node(NodePtr ptr1, NodePtr ptr2) {
	NodePtr current;
	NodePtr previous=NULL;
	NodePtr temp;
	int i=0;
	
	if(current==NULL){
		return -1;
	}else{
	if(ptr1==current){
	ptr1->data=temp;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
	ptr1->next=temp;
	ptr1->next=ptr2->next;
	ptr2->next=temp;
	current=ptr2;
	}
	else if(ptr2==current){
	 ptr1->data=temp;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
	ptr1->next=temp;
	ptr1->next=ptr2->next;
	ptr2->next=temp;
	current=ptr1;
}
else if(ptr1==NULL){
	ptr1->data=temp;
	ptr1->data=ptr2->data;
	ptr1->data=temp;
	ptr2->next=NULL;
	ptr1->next=temp;
}
else if(ptr2==NULL){
	ptr1->data=temp;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
	ptr1->next=temp;
	ptr1->next=NULL;
	ptr2->next=temp;	
}
else{
	ptr1->data=temp;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
	ptr1->next=temp;
	ptr1->next=ptr2->next;
	ptr2->next=temp;
	return i;
}
return i;
}
// Print list L from starting from the first node with 20 elements in a line.
void print_list(List L) {
	NodePtr current=L;
	int i=0;
	while(L!=NULL){
		if(L%20==0){
			for(i=0;i<20;++i){
				printf("%d",current->data);
			}
			printf("\n");
		}
		else{
			printf("%d\n",current->data);
		}
	}
	return i;
}

int main(void) {
	List lst; // An unordered singly-linked linear list.
	NodePtr end_Ptr; // Pointer to the end node.
	NodePtr curr_Ptr; // Pointer to the current node.
	NodePtr prev_Ptr; // Pointer to the previous node.
	int n; // Number of nodes in lst.
	int i,j; // Loop variable.
  
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
	print_list(lst);
	// Sort list lst into the ascending order by simulating the given sorting algorithm.
	do{
         for (i=n-2; i>=0; i--)
         for (j=0; j<=i; j++)
         if (a[i]>a[i+1]) swap(&a[i], &a[i+1]);
		 }while(i!=0);
	// Use do-while and/or while-do loop.
	
	// Print the sorted list lst with 20 elements in a line.
	printlst(lst);
	return 0;
}
