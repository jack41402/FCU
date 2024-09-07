// Basic operation interface of single linked ordered linear list.
#include <stdio.h>
#include <stdlib.h>
#include "polynomial_product_list_D1228792.h"

 // Initialize polynomial.
void initial(Polynomial *P) {	
	*P = NULL;  	
}

// Get number of terms of the polynomial. 
int getTerm(Polynomial P) {
	Term term = P; // node pointer. 
	int count = 0; // The number of terms of the the polynomial is set to 0.
	
	while (term!=NULL) {
		term = term->next; // Next term.
		count++; // Increment term counter.
	}
	return count; // The number of terms of the the polynomial.	 
}

// Get a polynomial term with given degree.
// If no term with the specified degree, return -99.0.
Coeff getCoeff(Polynomial P, Degree deg){
	Term current = P; // Term pointer.
	
	while (current!=NULL) { // Continue until no more term.
		if (current->degree==deg) return current->coeff; // The specified is found.
		else if (current->degree>deg) current = current->next; // Check next term.
		else return 0.0; // The spcified degree is greater than the current term, no such term.
	};
	return 0.0; // No more term, fails.
} 

// Search a polynomial term with a specified degree. 
// If successful, return the degree of the term; otherwise, return -1.
int searchTerm(Polynomial P, Degree deg) {
	Term current = P; // Term pointer.
	
	while (current!=NULL) { // Continue until no more term.
		if (current->degree==deg) return deg; // Return degree.
		else if (current->degree>deg) current = current->next; // Check next term.
		else return -1; // The spcified degree is greater than the current term, no such term.
	};
	return -1; // No more term, fails.
} 

// Clear the polynomial.
void clear(Polynomial *P){
	Term current; // Pointer to the current node.
	
	while (*P!=NULL) { // There are more terms to clear.
    	current = *P; // The current term.
		*P = current->next; // The rest of the polynomial.
		free(current); // Release the current term. 
  }
}

// Checks whether the polynomial is empty. Return 1, if empty; otherwise, return 0.
int is_empty(Polynomial P){
  return P==NULL; // If polynomial is NULL, return 1; otherwise, return 0. 
} 

// Print the polynomial.
void printPoly(Polynomial P){
	Term current = P; // Pointer to the current term.

	while (current!=NULL) { // There are more terms to print.
		if (current!=P && current->coeff>0) printf("+");
		if (current->degree>1) {
			printf("%5.3f X^%d", current->coeff, current->degree); // Print degree i term, i>1.
		}
		else if (current->degree==1) {
			printf("%5.3f X", current->coeff); // Print degree 1 term.
		}
		else {
			printf("%5.3f", current->coeff); // Print degree 0 term.
		}
		current = current->next; // Move to the next node. 
	}
	printf("\n"); // Print a newline. 
} 

// Replace a polynomial term of a specified degree with given coefficient.
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.
Degree replaceTerm(Polynomial *P, Degree deg, Coeff coeff){
	//***** Complete this function.
	int i=0;
	Term temp;
	temp = *P;
	if(*P==NULL){
		Term e;
		e = (Term) malloc(sizeof(Node)); 
		e->degree = deg;
		e->coeff = coeff;
		e->next = NULL;
		*P=e;
	}
	else{
		while(temp->degree!=deg&&temp->next!=NULL){
			temp=temp->next;
			if(temp->degree==deg){
				temp->coeff=coeff;
				i=1;
			}
		}
		if(i==0){
			Term temp2=*P;
			while(temp2->next!=NULL&&temp2->next->degree>deg){
				temp2=temp2->next;
			}
			Term e;
			Term p = temp2->next;
			e = (Term) malloc(sizeof(Node)); 
			e->degree = deg;
			e->coeff = coeff;
			temp2->next = e;
			e->next = p;
		}
	}
	
}

// Polynomial product.
Polynomial productPolynomial(Polynomial P, Polynomial Q) {
	//***** Complete this function. 
	
}
