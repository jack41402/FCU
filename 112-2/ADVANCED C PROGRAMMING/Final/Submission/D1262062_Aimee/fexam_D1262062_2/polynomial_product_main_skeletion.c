#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_skeletion.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {
	int i;
	Term current = *P;
	srand(time(NULL));
	for(i=deg; i>=0; i--) {
		current->degree = i;
		current->coeff = rand() % 10;
		current = current->next;
	}
	//***** Complete this function. 
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	double sum = 0;
	Term current = P;
	while(current != NULL){
		sum += current->coeff * pow(a, current->degree);
		current = current->next;
	}
	//***** Complete this function. 
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
	eval_P = evalevalPolynomial(P, a);
	printf(">>>> Evaluation of polynomial P(a): %lf", eval_P);
	eval_Q = evalevalPolynomial(Q, a);
	printf("\n>>>> Evaluation of polynomial P(a): %lf\n", eval_Q);
	
	prod = productPolynomial(P, Q);
	printf("\n>>>> Polynomial product P*Q(X) has %d non-zero coefficient terms.\n    ", getTerm(prod));
	printPoly(prod);
	eval_PQ = evalevalPolynomial(prod, a);
	printf(">>>> Evaluation of polynomial P(a): %lf\n", eval_PQ);
	printf(">>>>  eval_P*eval_Q-eval_PQ == %lf\n", eval_P*eval_Q-eval_PQ);
	if(abs(eval_P*eval_Q-eval_PQ)<0.000001) printf(">>>> Verified. P(a)*Q(a) equals to P*Q(a).");
	else printf(">>>> Failed. P(a)*Q(a) not equals to P*Q(a).");
	// Print the vlaue of P(a).
	
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	
	// Print polynomial product P*Q(X).
	
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.

	return 0; 
} 
