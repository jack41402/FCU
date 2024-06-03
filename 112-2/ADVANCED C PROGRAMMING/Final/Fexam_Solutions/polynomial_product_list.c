// Basic operation interface of single linked ordered linear list.
#include <stdio.h>
#include <stdlib.h>
#include "polynomial_product_list.h"

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

// Replace a polynomial term of a specified degree with given coefficient.
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.
Degree replaceTerm(Polynomial *P, Degree deg, Coeff coeff){
	Term current = *P; // Pointer to the current term.
	Term previous = NULL; // Pointer to the previous term, initially NULL. 
	Term newNode; // Pointer to the new term.
	
	if (*P==NULL) { // The polynomial is empty.
		if (coeff!=0.0) { // Insert a new term.
			newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new node.
			newNode->degree = deg; // Copy degree.
			newNode->coeff = coeff; // Copy coefficient.
			newNode->next = NULL; // Set next term to NULL.
			*P = newNode; // The polynomial points to the first term.
		}
		return deg; // Return the degree. 
	}
	
	do { // Check the current term.
		// Find the insertion position and insert a new node before this node.
		if (current->degree==deg) { // The specified degree exists.
			if (coeff!=0.0) { // Coefficient is not 0.0, replace it.
				current->coeff = coeff; // Replace the coefficient.
				return deg; // Return the degree.
			}
			else { // If coefficient is zeor, remove the current term.
				if (previous!=NULL) {
					previous->next = current->next; // Skip the current term.
					free(current); // Release the current term.
					return deg; // Return the degree.
				}
				else { // The first term is removed.
					*P = current->next; // The second term becomes the first term.
					free(current); // Release the current term.
					return deg; // Return the degree.
				}
			}
		}
		else if (current->degree<deg) { // Insert befor the current term.
			if (coeff!=0.0) { // Insert a new term.
				newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new term.
				newNode->degree = deg; // Copy degree.
				newNode->coeff = coeff; // Copy coefficient.
				newNode->next = current; // Set up the new node's link.
				if (previous==NULL) *P = newNode; // Insert the first term of the polynomial.
				else previous->next = newNode; // Modify the link of the previous term. 
			}
			return deg; /// Return the degree. 
		}
		else {
			previous = current;// The current term becomes the previous term. 
			current = current->next; // Set the next as the current term for the next step. 
		}
	} while (current!=NULL); // If there are more terms in the polynomial, continue. 

	// The while loop ends, no degree returned, and add to the last term of the polynomial. 
	if (coeff!=0.0) {
		newNode = (Polynomial) malloc(sizeof(Node)); // Allocate memory for a new term.
		newNode->degree = deg; // Copy degree.
		newNode->coeff = coeff; // Copy coefficient.
		newNode->next = NULL; // The last term, set its next term to NULL.
		previous->next = newNode; // Put the new term at the end of the polynomial.
	}
	return deg; /// Return the degree. 
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

// Polynomial product.
Polynomial productPolynomial(Polynomial P, Polynomial Q) {
	Polynomial prod;
	Term curr_P = P, curr_Q;
	int deg; 
	
	initial(&prod);
	while (curr_P!=NULL) {
		curr_Q = Q;
		while (curr_Q!=NULL) {
			deg = curr_P->degree+curr_Q->degree;
			replaceTerm(&prod, deg, getCoeff(prod, deg)+curr_P->coeff*curr_Q->coeff);
			curr_Q = curr_Q->next;
		}
		curr_P = curr_P->next;
	} 
	return prod;
}
