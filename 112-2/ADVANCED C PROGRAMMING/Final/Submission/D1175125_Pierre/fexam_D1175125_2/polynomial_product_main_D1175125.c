#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_D1175125.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {	
	//***** Complete this function.
	for(int i = deg; i>= 0; i--){
		replaceTerm(P, i, ((float)rand()/(float)(RAND_MAX))*20.0-10.0);
	} 
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	//***** Complete this function. 
	float result = 0.0;
	while(P!= NULL){
		result += p->coeff*pow(a, P->degree);
		P = P->next;
	}
	return result;
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
	eval_P = evalPolynomial(P,a);
	printf("Evaluation of P(%f): %f\n",a,eval_P);
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	eval_Q = evalPolynomial(P,a);
	printf("Evaluation of P(%f): %f\n",a,eval_Q);
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	prod = productPolynomial(P,Q);
	// Print polynomial product P*Q(X).
	printf("\n>>> Polynomial product P(x)Q(x): \n");
	printPoly(prod);
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	eval_PQ = evalPolynomialprodP,a);
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	printf("Evaluation of P(x)Q(x) at %f: %f\n",a,eval_PQ);
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.
	printf("Check whether |P(a)Q(a)-P(a)Q(a)|<0.000001: %s\n",(fabs(eval_p*eval_Q-eval_PQ)<0.000001)?"true":"false");
	clear(&P);
	clear(&Q);
	clear(&prod);
	return 0; 
} 
