#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_skeletion.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {	
	//***** Complete this function. 
	int i;
	Coeff n;
	for (i=0; i<deg; i++){
		if(rand()%2){
			n = (rand()%10000);
			n = n/1000;
			if (rand()%2){
				n = n * -1.0;
			}
			replaceTerm(P, i, n);
		}
	}
	n = rand()%10000;
	n = n/1000;
	if (rand()%2){
		n = n * -1;
	}
	replaceTerm(P, deg, n);
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
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
	// Print the vlaue of P(a).
	printf("\n>>>> Evaluation of Polynomial P(a): %f", eval_P);
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	printf("\n>>>> Evaluation of Polynomial Q(a): %f\n", eval_Q);
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	
	// Print polynomial product P*Q(X).
	printf("\n>>>> Polynomial product P*Q(a): %f", eval_PQ);
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	printf("\n>>>>  eval_P*eval_Q-eval_PQ == %f", 0.0000001);
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.
	//if (abs(P*Q-eval_PQ) < 0.000001){
	//	printf("\n>>>> Verified, P(a)*Q(a) equals to P*Q(a).", abs(P*Q-eval_PQ));
	//}
	return 0; 
} 
