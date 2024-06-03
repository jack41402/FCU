#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {	
	Coeff coeff; // Coefficient of the polynomial.
	int i; // Loop variable. 
	
	coeff =  (rand() % 2001 - 1000) / 100.0; // Generate coefficient of the first term.
	replaceTerm(P, deg, coeff); // Insert the first term.
	for (i=deg-1; i>=0; i--) { // Generate the remainding term. 
		if (rand()%2==0) { // Only 50% of terms have non-zero coefficient.
			coeff =  (rand() % 2001 - 1000) / 100.0;
			replaceTerm(P, i, coeff);
		}
	}
}

double evalPolynomial(Polynomial P, float a) {
	Term term = P;
	float value = 0.0;
	
	while (term!=NULL) { // Evaluate polynomial while there is a term.
		value = value + term->coeff * pow(a, term->degree);
		term = term->next; // Continue to the next term.
	} 
	
	return value; // Return the evaluation result.
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
	
	eval_P = evalPolynomial(P, a); // Evaluate polynomial P(a).
	printf(">>>> Evaluation of Polynomial P(a): %6.4E\n", eval_P); // Print the vlaue of P(a).
	
	eval_Q = evalPolynomial(Q, a); // Evaluate polynomial Q(a).
	printf(">>>> Evaluation of Polynomial Q(a): %6.4E\n", eval_Q); // Print the vlaue of Q(a).
	
	initial(&prod); // Initialize prod.
	prod = productPolynomial(P, Q); // Compute product of polynominals P and Q.
	
	printf("\n>>>> Polynomial product P*Q(X) has %d non-zero coefficient terms.\n    ", getTerm(prod));
	printPoly(prod); // Print polynomial product P*Q(X).
	
	eval_PQ = evalPolynomial(prod, a); // Evaluate polynomial P*Q(a).
	printf(">>>> Evaluation of Polynomial P*Q(a): %6.4E\n", eval_PQ); // Print the vlaue of P*Q(a).
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	printf(">>>> |eval_P*eval_Q-eval_PQ| == %8.6E\n", fabs(eval_P*eval_Q-eval_PQ)); 
	
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.
	if (fabs(eval_P*eval_Q-eval_PQ)<0.000001) printf(">>>> Verified, P(a)*Q(a) equals to P*Q(a).\n");
	else printf(">>>> Not verified, P(a)*Q(a) does not equal to P*Q(a).\n");

	return 0; 
} 
