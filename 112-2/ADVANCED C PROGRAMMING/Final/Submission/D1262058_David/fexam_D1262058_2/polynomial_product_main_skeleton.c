#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_skeletion.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {	
	//***** Complete this function.
	Term head = *P;
	Term newterm;
	Term previous;
	int a, i;
	float b, c;
	do{
		b = rand();
	}while(b > 10.0 || b < 10.0 || b == 0);
	head = (Node *)malloc(sizeof(Node));
	head->degree = deg;
	do{
		head->coeff = b;
	}while(b == 0.0);
	head->next = NULL;
	for(i=deg-1; i>=0; i--){
		a = rand()%2;
		if(a == 1){
			do{
				c = rand();
			}while(c > 10.0 || c < 10.0 || c == 0.0);
			newterm = (Node *)malloc(sizeof(Node));
			newterm->degree = i;
			newterm -> coeff = c;
			newterm-> next = NULL;
			if(i == deg-1){
				head -> next = newterm; 
			}
			else{
				previous -> next = newterm; 
			}
			previous = newterm;
		}
	}
  	
  	
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	//***** Complete this function.
	Term current = P;
	double sum = 0.0;
	while(current != NULL){
		sum += current->degree * pow(current->coeff, a);
		current = current->next;
	}
	return sum; 
}

int main(void) {
	Polynomial P, Q; // Declare two polynomials. 
	Polynomial prod; // Product of polynomial P and Q. 
	Degree deg; // Degree of the polynomial.
	Coeff coeff; // Coefficient of the polynomial.
	float a; // Value of X to evaluate the polynomial. 
	float eval_P, eval_Q, eval_PQ; // Values of P(a), Q(a), and PQ(a)
	
	srand(time(NULL)); // Seed for the random number generator.
	
	initial(&P); // Initialize P.
	initial(&Q); // Initialize Q.	
	initial(&prod); // Initialize prod.

	do {
		printf("Enter degree of polynomial P (between 0 and 20): ");
		scanf("%d", &deg); // Enter a degree.
	} while (deg<0 || deg>20);	
	genePolynomial(&P, deg); // Generate polynomial P.
	
	do {
		printf("Enter degree of polynomial Q (between 0 and 20): ");
		scanf("%d", &deg); // Enter a degree.
	} while (deg<0 || deg>20);	
	genePolynomial(&Q, deg); // Generate polynomial Q.
  
	do {
		printf("Enter value of a (between -1.0 and 1.0): ");
		scanf("%f", &a); // Enter a degree.
	} while (a<-1.0 || a>1.0);
	
	printf("\n>>>> Polynomial P(X) has %d non-zero coefficient terms.\n    ", getTerm(P));
	printPoly(P); // Print polynomial P.
	
	printf("\n>>>> Polynomial Q(X) has %d non-zero coefficient terms.\n    ", getTerm(Q));
	printPoly(Q); // Print polynomial Q.
	printf("\n");
	
	// ***** Complete the following steps. 
	
	// Evaluate polynomial P(a).
	// Print the vlaue of P(a).
	eval_P = evalPolynomial(P, a);
	printf("Evaluation of Polynomial P(a): %lf\n", eval_P);
	
	
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	eval_Q = evalPolynomial(Q, a);
	printf("Evaluation of Polynomial Q(a): %lf\n", eval_Q);
	
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	// Print polynomial product P*Q(X).
	prod = productPolynomial(P, Q);
	printPoly(prod);
	
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	eval_PQ = evalPolynomial(prod, a);
	printf("Evaluation of Polynomial P*Q(a): %lf\n", eval_PQ);
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	printf("|P(a)*Q(a)-P*Q(a)|, %lf\n", abs(eval_P * eval_P - eval_PQ));
	
	
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.
	if(abs(eval_P * eval_P - eval_PQ)<0.000001){
		printf("Verified, P(a)*Q(a) eauals to P*Q(a)");
	}
	else{
		printf("Verify failed");
	}

	return 0; 
} 
