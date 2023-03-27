#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_single_link_list.h"

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
	Polynomial P; // Declare a polynomial. 
	Degree deg; // Degree of the polynomial.
	Coeff coeff; // Coefficient of the polynomial.
	float a; // Value of X to evaluate the polynomial. 
	int i; // Loop ariables 
	
	initial(&P); // Initialize P.
  
	do {
		printf("Enter degree of the polynomial (between 0 and 100): ");
		scanf("%d", &deg); // Enter a degree.
	} while (deg<0 || deg>100);
  
	do {
		printf("Enter value of a (between -1.0 and 1.0): ");
		scanf("%f", &a); // Enter a degree.
	} while (a<-1.0 || a>1.0);
	
	srand(time(NULL)); // Seed for the random number generator.
	
	coeff =  (rand() % 2001 - 1000) / 100.0; // Generate coefficient of the first term.
	replaceTerm(&P, deg, coeff); // Insert the first term.
	for (i=deg-1; i>=0; i--) { // Generate the remainding term. 
		if (rand()%3==0) { // Only 0.33% of terms have non-zero coefficient.
			coeff =  (rand() % 2001 - 1000) / 100.0;
			replaceTerm(&P, i, coeff);
		}
	}
	
	printf("\n>>>> Polynomial P(X) has %d non-zero coefficient terms.\n", getTerm(P)); // Print number of terms.
	printPoly(P); // Print polynomial.
	
	// Evaluate the polynomial and print the vlaue of the polynomial.
	printf("\n>>>> a=%5.3f\n", a);
	printf(">>>> Evaluation of Polynomial P(a): %6.4E\n", evalPolynomial(P, a));

	return 0; 
} 
