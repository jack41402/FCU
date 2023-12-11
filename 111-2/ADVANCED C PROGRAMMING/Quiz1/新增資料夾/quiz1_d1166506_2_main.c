#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quiz1_d1166506_2.h" 

int main(void) {
	List L; // Linear list L. 
	int n; // The number of elements.
	ElemType e1, e2; // List elements for swaping operation.
	int i, j; // Loop index.
	int temp ;
	
	// (1) Declare a variable L of a linear list and initialize L.
	initial(&L);

	// ***** Complete the rest of the program.

	// (2) Enter a positive integer n such that 20¡Ün¡Ü100, and insert n elements of random number
	//     between 0 and 999 to linear list L. No duplicated elements are allowed. 
	do {
		printf(">>>> Enter the size of linear list L: ");
		scanf("%d", &n);
	} while (n<20 || n>100);
	
	srand(time(NULL));
	for (i=0 ; i<n ; ++i)
	{
		insertElem(&L , rand()%1000) ;
	}
	// (3) Print the elements of linear list L.
	printList(L) ;
	 
	// (4) Sort the elements of linear list L. You may only use the functions in the header file.
	for (i=0 ; i<L.size ; ++i)
	{
		for (j=i ; j<L.size ; ++j)
		{
			if (L.elem[i]>L.elem[j])
			{
				temp = L.elem[i] ;
				L.elem[i] = L.elem[j] ;
				L.elem[j] = temp ;
			}
		}
	}
	
	// (5) Print the elements of linear list L after sorting.
	printf ("The elements of linear list after sorting:\n") ;
	printList(L) ;
	return 0;
} 
