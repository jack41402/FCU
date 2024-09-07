#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_skeletion.h"

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

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	double eval = a;
	int i;
	Term current = P;
	while(current != NULL){
		while(current->degree != 0){
			for(i = 0; i < current->degree; i++){
				eval = eval * a;
			}
			eval = eval * current->coeff;
		}
	} 
	if(searchTerm(P, 0) != -1) eval = eval + searchTerm(P, 0);
	return eval;
	//***** Complete this function. 
}

int main(void) {
	Polynomial P, Q; // Declare two polynomials. 
	Polynomial prod; // Product of polynomial P and Q. 
	Degree deg; // Degree of the polynomial.
	Coeff coeff; // Coefficient of the polynomial.
	float a; // Value of X to evaluate the polynomial. 
	float eval_P, eval_Q, eval_PQ; // Values of P(a), Q(a), and PQ(a)
	float fa;
	
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
	eval_P = evalPolynomial(P, a);
	// Print the vlaue of P(a).
	printf("\n>>>> Evaluate polynomial P(a): %f\n", eval_P);
	
	// Evaluate polynomial Q(a).
	eval_Q = evalPolynomial(Q, a);
	// Print the vlaue of Q(a).
	printf("\n>>>> Evaluate polynomial Q(a): %f\n", eval_Q);
	
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	prod = productPolynomial(P, Q);
	// Print polynomial product P*Q(X).
	printf("\n>>>> Polynomial Product P*Q(X) has %d non-zero coefficient terms.\n    ", getTerm(prod));
	// Evaluate polynomial P*Q(a).
	eval_PQ = evalPolynomial(prod, a);
	// Print the vlaue of P*Q(a).
	printf("\n>>>> Evaluation of Polynomial P*Q(x): %f", eval_PQ);
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	fa = eval_P * eval_Q - eval_PQ;
	fa = fabs(fa);
	printf("\n>>>> |eval_P*eval_Q-eval_PQ| == %f", fa);
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.
	if(fa < 0.000001) printf("\n>>>> Verified, P(a)*Q(a) is equal to P*Q(a).");
	return 0; 
} 
